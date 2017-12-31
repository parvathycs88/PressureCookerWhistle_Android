/*
 * matlabfcn_whistlecount_types.h
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

#ifndef RTW_HEADER_matlabfcn_whistlecount_types_h_
#define RTW_HEADER_matlabfcn_whistlecount_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_SwitchType_
#define DEFINED_TYPEDEF_FOR_SwitchType_

typedef enum {
  SwitchType_None = 0,                 /* Default value */
  SwitchType_Off,
  SwitchType_On
} SwitchType;

#endif

#ifndef typedef_codertarget_internal_androidA_T
#define typedef_codertarget_internal_androidA_T

typedef struct {
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T SampleTime;
} codertarget_internal_androidA_T;

#endif                                 /*typedef_codertarget_internal_androidA_T*/

/* Custom Type definition for MATLAB Function: '<Root>/MATLAB Function4' */
#ifndef struct_tag_sTV4mD3w33KbfLr2dclOL5C
#define struct_tag_sTV4mD3w33KbfLr2dclOL5C

struct tag_sTV4mD3w33KbfLr2dclOL5C
{
  real_T PredictorNames;
  char_T ResponseName;
  boolean_T TableInput;
  boolean_T ObservationsInRows;
  real_T NumPredictors;
};

#endif                                 /*struct_tag_sTV4mD3w33KbfLr2dclOL5C*/

#ifndef typedef_sTV4mD3w33KbfLr2dclOL5C_matla_T
#define typedef_sTV4mD3w33KbfLr2dclOL5C_matla_T

typedef struct tag_sTV4mD3w33KbfLr2dclOL5C sTV4mD3w33KbfLr2dclOL5C_matla_T;

#endif                                 /*typedef_sTV4mD3w33KbfLr2dclOL5C_matla_T*/

#ifndef struct_tag_sxtYAoUH7HXhtdT4TrqCdPH
#define struct_tag_sxtYAoUH7HXhtdT4TrqCdPH

struct tag_sxtYAoUH7HXhtdT4TrqCdPH
{
  char_T Function[8];
  real_T PolyOrder;
  real_T Sigmoid[2];
  real_T Scale;
  real_T Offset;
};

#endif                                 /*struct_tag_sxtYAoUH7HXhtdT4TrqCdPH*/

#ifndef typedef_sxtYAoUH7HXhtdT4TrqCdPH_matla_T
#define typedef_sxtYAoUH7HXhtdT4TrqCdPH_matla_T

typedef struct tag_sxtYAoUH7HXhtdT4TrqCdPH sxtYAoUH7HXhtdT4TrqCdPH_matla_T;

#endif                                 /*typedef_sxtYAoUH7HXhtdT4TrqCdPH_matla_T*/

#ifndef typedef_cell_wrap_matlabfcn_whistleco_T
#define typedef_cell_wrap_matlabfcn_whistleco_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_matlabfcn_whistleco_T;

#endif                                 /*typedef_cell_wrap_matlabfcn_whistleco_T*/

/* Custom Type definition for MATLAB Function: '<Root>/MATLAB Function4' */
#ifndef typedef_c_classreg_learning_coder_cla_T
#define typedef_c_classreg_learning_coder_cla_T

typedef struct {
  real_T Alpha[856];
  real_T Bias;
  real_T ClassNames[2];
  int32_T ClassNamesLength[2];
  real_T Prior[2];
  real_T NonzeroProbClasses[2];
  real_T Cost[4];
} c_classreg_learning_coder_cla_T;

#endif                                 /*typedef_c_classreg_learning_coder_cla_T*/

#ifndef struct_tag_s3zEQda6w8SHbmunwhAB8XC
#define struct_tag_s3zEQda6w8SHbmunwhAB8XC

struct tag_s3zEQda6w8SHbmunwhAB8XC
{
  real_T ClassNames[2];
  real_T NonzeroProbClasses[2];
  real_T Prior[2];
  int8_T ClassNamesType;
  real_T ClassNamesLength[2];
  real_T NonzeroProbClassesLength[2];
};

#endif                                 /*struct_tag_s3zEQda6w8SHbmunwhAB8XC*/

#ifndef typedef_s3zEQda6w8SHbmunwhAB8XC_matla_T
#define typedef_s3zEQda6w8SHbmunwhAB8XC_matla_T

typedef struct tag_s3zEQda6w8SHbmunwhAB8XC s3zEQda6w8SHbmunwhAB8XC_matla_T;

#endif                                 /*typedef_s3zEQda6w8SHbmunwhAB8XC_matla_T*/

#ifndef struct_tag_sDpzQBCpufMCJIuCMEkB7H
#define struct_tag_sDpzQBCpufMCJIuCMEkB7H

struct tag_sDpzQBCpufMCJIuCMEkB7H
{
  real_T Alpha[856];
  real_T Bias;
  sxtYAoUH7HXhtdT4TrqCdPH_matla_T KernelParameters;
  real_T NumPredictors;
  real_T SupportVectors[2568];
  real_T SupportVectorLabels[856];
};

#endif                                 /*struct_tag_sDpzQBCpufMCJIuCMEkB7H*/

#ifndef typedef_sDpzQBCpufMCJIuCMEkB7H_matlab_T
#define typedef_sDpzQBCpufMCJIuCMEkB7H_matlab_T

typedef struct tag_sDpzQBCpufMCJIuCMEkB7H sDpzQBCpufMCJIuCMEkB7H_matlab_T;

#endif                                 /*typedef_sDpzQBCpufMCJIuCMEkB7H_matlab_T*/

#ifndef struct_tag_s5Nd0FgPOCY19AusrRFz7lB
#define struct_tag_s5Nd0FgPOCY19AusrRFz7lB

struct tag_s5Nd0FgPOCY19AusrRFz7lB
{
  sTV4mD3w33KbfLr2dclOL5C_matla_T DataSummary;
  s3zEQda6w8SHbmunwhAB8XC_matla_T ClassSummary;
  char_T ScoreTransform[8];
  char_T DefaultLoss[35];
  char_T LabelPredictor[54];
  char_T DefaultScoreType[3];
  boolean_T fitPosterior;
  char_T ScoreTransformFull[36];
  boolean_T CustomScoreTransform;
  char_T FromStructFcn[61];
  sDpzQBCpufMCJIuCMEkB7H_matlab_T Impl;
};

#endif                                 /*struct_tag_s5Nd0FgPOCY19AusrRFz7lB*/

#ifndef typedef_s5Nd0FgPOCY19AusrRFz7lB_matla_T
#define typedef_s5Nd0FgPOCY19AusrRFz7lB_matla_T

typedef struct tag_s5Nd0FgPOCY19AusrRFz7lB s5Nd0FgPOCY19AusrRFz7lB_matla_T;

#endif                                 /*typedef_s5Nd0FgPOCY19AusrRFz7lB_matla_T*/

#ifndef struct_tag_slrxSqmWu57110XdXlkQPVG
#define struct_tag_slrxSqmWu57110XdXlkQPVG

struct tag_slrxSqmWu57110XdXlkQPVG
{
  s5Nd0FgPOCY19AusrRFz7lB_matla_T compactStruct;
};

#endif                                 /*struct_tag_slrxSqmWu57110XdXlkQPVG*/

#ifndef typedef_slrxSqmWu57110XdXlkQPVG_matla_T
#define typedef_slrxSqmWu57110XdXlkQPVG_matla_T

typedef struct tag_slrxSqmWu57110XdXlkQPVG slrxSqmWu57110XdXlkQPVG_matla_T;

#endif                                 /*typedef_slrxSqmWu57110XdXlkQPVG_matla_T*/

#ifndef typedef_codertarget_internal_androidD_T
#define typedef_codertarget_internal_androidD_T

typedef struct {
  int32_T isInitialized;
  cell_wrap_matlabfcn_whistleco_T inputVarSize;
} codertarget_internal_androidD_T;

#endif                                 /*typedef_codertarget_internal_androidD_T*/

/* Parameters (auto storage) */
typedef struct P_matlabfcn_whistlecount_T_ P_matlabfcn_whistlecount_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_matlabfcn_whistlecoun_T RT_MODEL_matlabfcn_whistlecou_T;

#endif                                 /* RTW_HEADER_matlabfcn_whistlecount_types_h_ */
