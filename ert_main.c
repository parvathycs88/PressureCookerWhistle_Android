#include <stdio.h>
#include <stdlib.h>
#include "matlabfcn_whistlecount.h"
#include "matlabfcn_whistlecount_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "androidinitialize.h"
#define UNUSED(x)                      x = x

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(matlabfcn_whistlecount_M) == (NULL));
  while (runModel) {
    MW_sem_wait(&baserateTaskSem);
    matlabfcn_whistlecount_step();

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(matlabfcn_whistlecount_M) == (NULL)));
    runModel = !stopRequested;
  }

  runModel = 0;
  terminateTask(arg);
  MW_pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(matlabfcn_whistlecount_M, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  my_android_terminate();

  /* Disable rt_OneStep() here */

  /* Terminate model */
  matlabfcn_whistlecount_terminate();
  MW_sem_post(&stopSem);
  return NULL;
}

jint JNICALL naMain(JNIEnv *pEnv, jobject pObj, jobjectArray pArgv, jobject
                    pMainActivity)
{
  int argc = 4;
  char *argv[4] = { "matlabfcn_whistlecount", "-w", "-port", "17725" };

  my_android_init(pEnv, pObj, pArgv, pMainActivity);
  rtmSetErrorStatus(matlabfcn_whistlecount_M, 0);

  /* Initialize model */
  matlabfcn_whistlecount_initialize();

  /* Call RTOS Initialization function */
  myRTOSInit(0.001, 0);

  /* Wait for stop semaphore */
  MW_sem_wait(&stopSem);
  return 0;
}
