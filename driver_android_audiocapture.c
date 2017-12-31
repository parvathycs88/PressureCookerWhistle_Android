/*
 * driver_android_audiocapture.c
 *
 * Driver code
 *
 * Copyright 2013-2017 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>
#include <pthread.h>
#include <android/log.h>

// for native audio
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>

#ifdef AUDIODEBUG
#define AUDIOCAPTURE_LOG(msg)       __android_log_print(ANDROID_LOG_INFO, "AudioCapture", msg);
#define AUDIOCAPTURE_LOG1(msg,p1)   __android_log_print(ANDROID_LOG_INFO, "AudioCapture", msg, p1);
#define AUDIOCAPTURE_LOG2(msg,p1,p2)   __android_log_print(ANDROID_LOG_INFO, "AudioCapture", msg, p1,p2);
#else
#define AUDIOCAPTURE_LOG(msg)       
#define AUDIOCAPTURE_LOG1(msg,p1)    
#define AUDIOCAPTURE_LOG2(msg,p1,p2)   
#endif

#define CHECK_RESULT(res, fcn)      if (res != SL_RESULT_SUCCESS) { __android_log_print(ANDROID_LOG_INFO, "AudioCapture", "Call to %s did ***not*** succeed (%d).\n", fcn, (int)res); return; } 
#define CHECK_RETURN(ret, fcn)      if (ret != 0) { __android_log_print(ANDROID_LOG_INFO, "AudioCapture", "Call to %s did not succeed (%d).\n", fcn, ret); return; } 

#define NUMBUFFERS 5


typedef struct _RecorderContext
{
    SLObjectItf     Object;
    SLEngineItf     Engine;
    SLObjectItf     Recorder;
    SLRecordItf     Record;
    
    SLAndroidSimpleBufferQueueItf BufferQueue;
    
    SLresult        EngineInitialized;
    int             resume;
    int             SampleRate;
    int             SLSampleRate;
    int             FrameSize;
    int             NumPerSample;
    int             NumBytes;
    
    volatile int    CurrentInputBuffer;
    volatile int    CurrentOutputBuffer;
    uint16_t       *Buffer[NUMBUFFERS]; 
} RecorderContext;
static RecorderContext gsRecContext;

void RecorderCallback(SLAndroidSimpleBufferQueueItf bq, void *context)
{ 
   if (gsRecContext.resume == 3) {
  /* Enqueue the next buffer */
      if (gsRecContext.CurrentInputBuffer < (NUMBUFFERS -1))
         gsRecContext.CurrentInputBuffer++;
      else
         gsRecContext.CurrentInputBuffer = 0;
  
      SLresult res = (*(gsRecContext.BufferQueue))->Enqueue(gsRecContext.BufferQueue, 
          gsRecContext.Buffer[gsRecContext.CurrentInputBuffer], 
          gsRecContext.NumBytes);
      CHECK_RESULT(res,"RecorderCallback::Enqueue");
   }
}


void audioCaptureInit(int sampleRate, int frameSize)
{
    SLresult res;

    /* Clear out all */
    memset(&(gsRecContext), sizeof(gsRecContext), 0);
    
    gsRecContext.EngineInitialized = SL_BOOLEAN_FALSE;
    
    gsRecContext.SampleRate = sampleRate;
    gsRecContext.FrameSize  = frameSize;
    gsRecContext.NumPerSample = 2;
    gsRecContext.NumBytes   = gsRecContext.FrameSize * gsRecContext.NumPerSample * sizeof(uint16_t);
    gsRecContext.resume = 3;
    /* Allocate the buffers */
    gsRecContext.CurrentInputBuffer = 0;
    gsRecContext.CurrentOutputBuffer = 0;
    int i;
    for (i = 0; i < NUMBUFFERS; ++i)
    {
        gsRecContext.Buffer[i] = (uint16_t*)malloc(gsRecContext.NumBytes);
        if (gsRecContext.Buffer[i] == NULL)
        {
            return;
        }
    }
    
    /* Create Engine object */
    res = slCreateEngine(&(gsRecContext.Object), 0, NULL, 0, NULL, NULL);
    CHECK_RESULT(res,"slCreateEngine");
    
    /* Realize the object */
    res = (*(gsRecContext.Object))->Realize((gsRecContext.Object), SL_BOOLEAN_FALSE);
    CHECK_RESULT(res,"RealizeEngine");
    
    /* Get the engine interface */
    res = (*(gsRecContext.Object))->GetInterface((gsRecContext.Object), SL_IID_ENGINE, &(gsRecContext.Engine));
    CHECK_RESULT(res,"GetInterfaceEngine");
    
    
    switch (sampleRate)
    {
    case 8000:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_8;
      break;
    case 11025:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_11_025;
      break;
    case 16000:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_16;
      break;
    case 22050:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_22_05;
      break;
    case 24000:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_24;
      break;
    case 32000:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_32;
      break;
    case 44100:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_44_1;
      break;
    case 48000:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_48;
      break;
    case 64000:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_64;
      break;
    case 88200:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_88_2;
      break;
    case 96000:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_96;
      break;
    case 192000:
      gsRecContext.SLSampleRate = SL_SAMPLINGRATE_192;
      break;
    default:
      return;
    }
    
    /* Audio source configuration */
    SLDataLocator_IODevice dev = {SL_DATALOCATOR_IODEVICE, SL_IODEVICE_AUDIOINPUT,
				      SL_DEFAULTDEVICEID_AUDIOINPUT, NULL};
    SLDataSource audioSrc = {&dev, NULL};
    int Speakers = SL_SPEAKER_FRONT_LEFT | SL_SPEAKER_FRONT_RIGHT;
    
    SLDataLocator_AndroidSimpleBufferQueue bq = {SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE, NUMBUFFERS};
    SLDataFormat_PCM format_pcm = {SL_DATAFORMAT_PCM, 2, gsRecContext.SLSampleRate,
				   SL_PCMSAMPLEFORMAT_FIXED_16, SL_PCMSAMPLEFORMAT_FIXED_16,
				   Speakers, SL_BYTEORDER_LITTLEENDIAN};
    SLDataSink audioSnk = {&bq, &format_pcm};

    /* Create the Audio Recorder */
    const SLInterfaceID id[1] = {SL_IID_ANDROIDSIMPLEBUFFERQUEUE};
    const SLboolean req[1] = {SL_BOOLEAN_TRUE};
    res = (*(gsRecContext.Engine))->CreateAudioRecorder((gsRecContext.Engine), &(gsRecContext.Recorder), &audioSrc,
						     &audioSnk, 1, id, req);
    CHECK_RESULT(res,"CreateAudioRecorder");

    /* Realize the audio recorder */
    res = (*(gsRecContext.Recorder))->Realize((gsRecContext.Recorder), SL_BOOLEAN_FALSE);
    CHECK_RESULT(res,"RealizeRecorder");

    /* Get the Record interface */
    res = (*(gsRecContext.Recorder))->GetInterface((gsRecContext.Recorder), SL_IID_RECORD, &(gsRecContext.Record));
    CHECK_RESULT(res,"GetInterfaceRecorder");
 
    /* get the buffer queue interface */
    res = (*(gsRecContext.Recorder))->GetInterface((gsRecContext.Recorder), SL_IID_ANDROIDSIMPLEBUFFERQUEUE, &(gsRecContext.BufferQueue));
    CHECK_RESULT(res,"GetInterfaceBufferQueue");

    // register callback on the buffer queue
    res = (*(gsRecContext.BufferQueue))->RegisterCallback((gsRecContext.BufferQueue), RecorderCallback, &gsRecContext);
    CHECK_RESULT(res,"RegisterCallback");
    
    res = (*(gsRecContext.Record))->SetRecordState((gsRecContext.Record), SL_RECORDSTATE_RECORDING);
    CHECK_RESULT(res,"SetRecordState");

    res = (*(gsRecContext.BufferQueue))->Enqueue(gsRecContext.BufferQueue, gsRecContext.Buffer[gsRecContext.CurrentInputBuffer], gsRecContext.NumBytes);
    CHECK_RESULT(res,"Enqueue");
    
    gsRecContext.EngineInitialized = 1;
}

void onAudioCaptureStateChange (int state){
   if (state == 4) {
        SLresult  res = (*(gsRecContext.Record))->SetRecordState((gsRecContext.Record), SL_RECORDSTATE_STOPPED);
        CHECK_RESULT(res,"SetRecordState");
   }
   else if (state == 3) {
     SLresult  res = (*(gsRecContext.Record))->SetRecordState((gsRecContext.Record), SL_RECORDSTATE_RECORDING);
     CHECK_RESULT(res,"SetRecordState");
     res = (*(gsRecContext.BufferQueue))->Enqueue(gsRecContext.BufferQueue, gsRecContext.Buffer[gsRecContext.CurrentInputBuffer], gsRecContext.NumBytes);
     CHECK_RESULT(res,"Enqueue");
   } else {}
   gsRecContext.resume = state;
}
void audioCapture(uint16_t* outData, int frameSize)
{
    
    if (gsRecContext.EngineInitialized && gsRecContext.resume == 3)
    {
        if (gsRecContext.CurrentInputBuffer == gsRecContext.CurrentOutputBuffer)
        {
            AUDIOCAPTURE_LOG2("audioCapture need to wait: %d, %d", gsRecContext.CurrentInputBuffer, gsRecContext.CurrentOutputBuffer);
            while (gsRecContext.CurrentInputBuffer == gsRecContext.CurrentOutputBuffer); /* Wait until CurrenInputBuffer is not filled */
            AUDIOCAPTURE_LOG2("audioCapture done waiting: %d, %d", gsRecContext.CurrentInputBuffer, gsRecContext.CurrentOutputBuffer);
        }
        CHECK_RETURN((frameSize - gsRecContext.FrameSize),"FrameSize - frameSize");
        AUDIOCAPTURE_LOG2("audioCapture: Before: CurrentBuffer: %d, %d", gsRecContext.CurrentInputBuffer, gsRecContext.CurrentOutputBuffer);
        uint16_t *dataFromDevice = gsRecContext.Buffer[gsRecContext.CurrentOutputBuffer];
        memcpy(outData,dataFromDevice, gsRecContext.NumBytes);
        if (gsRecContext.CurrentOutputBuffer < (NUMBUFFERS -1))
            gsRecContext.CurrentOutputBuffer++;
        else
            gsRecContext.CurrentOutputBuffer = 0;
        AUDIOCAPTURE_LOG2("audioCapture: After: CurrentBuffer: %d, %d", gsRecContext.CurrentInputBuffer, gsRecContext.CurrentOutputBuffer);
    }
    else
    {
        AUDIOCAPTURE_LOG("RecordContextNotInitialized");
    }
}

void audioCaptureTerminate()
{
    /* Destroy Recorder object */
    if (gsRecContext.Recorder != NULL)
    {
        (*(gsRecContext.Recorder))->Destroy(gsRecContext.Recorder);
        gsRecContext.Recorder = NULL;
        gsRecContext.Record = NULL;
        gsRecContext.BufferQueue = NULL;
    }
    
    /* Destroy Engine object */
    if (gsRecContext.Engine != NULL)
    {
        (*(gsRecContext.Object))->Destroy(gsRecContext.Object);
        gsRecContext.Object = NULL;
        gsRecContext.Engine = NULL;
    }
    
    int i;
    for (i = 0; i < NUMBUFFERS; ++i)
    {
        free(gsRecContext.Buffer[i]);
        gsRecContext.Buffer[i] = NULL;
    }
}
