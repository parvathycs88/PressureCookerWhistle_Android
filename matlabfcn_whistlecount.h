/*
 * matlabfcn_whistlecount.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "matlabfcn_whistlecount".
 *
 * Model version              : 1.323
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sun Dec 31 13:30:08 2017
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_matlabfcn_whistlecount_h_
#define RTW_HEADER_matlabfcn_whistlecount_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef matlabfcn_whistlecount_COMMON_INCLUDES_
# define matlabfcn_whistlecount_COMMON_INCLUDES_
#include <stdio.h>
#include "driver_android_plot.h"
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "driver_android_audiocapture.h"
#include "driver_android_datadisplay.h"
#endif                                 /* matlabfcn_whistlecount_COMMON_INCLUDES_ */

#include "matlabfcn_whistlecount_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T GeneratedFilterBlock[44100];  /* '<S2>/Generated Filter Block' */
  real_T Gain[44100];                  /* '<Root>/Gain' */
  real_T b_signal[22050];
  real_T dv0[22050];
  int32_T b_i_data[22050];
  int16_T iv0[44100];
  real_T frame[2205];
  real_T dv1[2205];
  real_T window2[2205];
  real_T b[2205];
  real_T b_m[2205];
  real_T dv2[2205];
  real_T y[2205];
  real_T x[2205];
  real_T window2_c[2205];
  real_T b_k[2205];
  real_T b_c[2205];
  real_T dv3[2205];
  real_T y_b[2205];
  real_T x_p[2205];
  c_classreg_learning_coder_cla_T Mdl;
  real_T dv4[856];
  real_T dv5[856];
  real_T absdiff[18];
  real_T Features[18];                 /* '<Root>/MATLAB Function1' */
  real_T xbar[3];
  real_T dv6[2];
  real_T scores[2];
  real_T label;                        /* '<Root>/MATLAB Function4' */
  real_T curPos;
  real_T xbar_c;
  real_T t;
  real_T f;
  real_T absxk;
  real_T d0;
  real_T b_c_f;
  char_T y_g[6];
  int32_T k;
  int32_T memOffset;
  int32_T memIdx;
  int32_T numIdx;
  int32_T denIdx;
  SwitchType Switch;                   /* '<Root>/Debouncer' */
} B_matlabfcn_whistlecount_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidD_T obj; /* '<S9>/DataDisplay' */
  codertarget_internal_androidA_T obj_o;/* '<S1>/MATLAB System' */
  real_T GeneratedFilterBlock_FILT_STATE[40];/* '<S2>/Generated Filter Block' */
  struct {
    void *LoggedData;
  } ClassifierOutput_PWORK;            /* '<Root>/Classifier Output' */

  int32_T chartAbsoluteTimeCounter;    /* '<Root>/Debouncer' */
  int32_T durationLastReferenceTick_1; /* '<Root>/Debouncer' */
  int32_T durationLastReferenceTick_1_p;/* '<Root>/Debouncer' */
  uint32_T Counter_ClkEphState;        /* '<Root>/Counter' */
  uint8_T Counter_Count;               /* '<Root>/Counter' */
  uint8_T is_active_c17_matlabfcn_whistle;/* '<Root>/Debouncer' */
  boolean_T objisempty;                /* '<S9>/DataDisplay' */
  boolean_T condWasTrueLastTime_1;     /* '<Root>/Debouncer' */
  boolean_T condWasTrueLastTime_1_l;   /* '<Root>/Debouncer' */
  boolean_T objisempty_d;              /* '<S1>/MATLAB System' */
} DW_matlabfcn_whistlecount_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: GeneratedFilterBlock_RTP1COEFF
   * Referenced by: '<S2>/Generated Filter Block'
   */
  real_T GeneratedFilterBlock_RTP1COEFF[30];

  /* Computed Parameter: GeneratedFilterBlock_RTP2COEFF
   * Referenced by: '<S2>/Generated Filter Block'
   */
  real_T GeneratedFilterBlock_RTP2COEFF[20];

  /* Expression: a.ScaleValues
   * Referenced by: '<S2>/Generated Filter Block'
   */
  real_T GeneratedFilterBlock_RTP3COEFF[11];
} ConstP_matlabfcn_whistlecount_T;

/* Parameters (auto storage) */
struct P_matlabfcn_whistlecount_T_ {
  real_T hopSize;                      /* Variable: hopSize
                                        * Referenced by:
                                        *   '<Root>/MATLAB Function'
                                        *   '<Root>/MATLAB Function1'
                                        */
  real_T mean_overallX[2];             /* Variable: mean_overallX
                                        * Referenced by: '<Root>/MATLAB Function4'
                                        */
  real_T std_overallX[2];              /* Variable: std_overallX
                                        * Referenced by: '<Root>/MATLAB Function4'
                                        */
  real_T windowLength;                 /* Variable: windowLength
                                        * Referenced by:
                                        *   '<Root>/MATLAB Function'
                                        *   '<Root>/MATLAB Function1'
                                        */
  uint8_T Counter_InitialCount;        /* Mask Parameter: Counter_InitialCount
                                        * Referenced by: '<Root>/Counter'
                                        */
  real_T MATLABSystem_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S1>/MATLAB System'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/32767
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T SecondFeature_Value[3];       /* Expression: double('zcr')
                                        * Referenced by: '<Root>/Second Feature'
                                        */
  real_T FirstFeature_Value[6];        /* Expression: double('energy')
                                        * Referenced by: '<Root>/First Feature'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_matlabfcn_whistlecoun_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_matlabfcn_whistlecount_T matlabfcn_whistlecount_P;

/* Block signals (auto storage) */
extern B_matlabfcn_whistlecount_T matlabfcn_whistlecount_B;

/* Block states (auto storage) */
extern DW_matlabfcn_whistlecount_T matlabfcn_whistlecount_DW;

/* Constant parameters (auto storage) */
extern const ConstP_matlabfcn_whistlecount_T matlabfcn_whistlecount_ConstP;

/* Model entry point functions */
extern void matlabfcn_whistlecount_initialize(void);
extern void matlabfcn_whistlecount_step(void);
extern void matlabfcn_whistlecount_terminate(void);

/* Real-time Model object */
extern RT_MODEL_matlabfcn_whistlecou_T *const matlabfcn_whistlecount_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'matlabfcn_whistlecount'
 * '<S1>'   : 'matlabfcn_whistlecount/Audio Capture'
 * '<S2>'   : 'matlabfcn_whistlecount/Bandpass Filter'
 * '<S3>'   : 'matlabfcn_whistlecount/Debouncer'
 * '<S4>'   : 'matlabfcn_whistlecount/MATLAB Function'
 * '<S5>'   : 'matlabfcn_whistlecount/MATLAB Function1'
 * '<S6>'   : 'matlabfcn_whistlecount/MATLAB Function2'
 * '<S7>'   : 'matlabfcn_whistlecount/MATLAB Function3'
 * '<S8>'   : 'matlabfcn_whistlecount/MATLAB Function4'
 * '<S9>'   : 'matlabfcn_whistlecount/Whistle Count'
 */
#endif                                 /* RTW_HEADER_matlabfcn_whistlecount_h_ */
