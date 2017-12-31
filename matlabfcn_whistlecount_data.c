/*
 * matlabfcn_whistlecount_data.c
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

#include "matlabfcn_whistlecount.h"
#include "matlabfcn_whistlecount_private.h"

/* Block parameters (auto storage) */
P_matlabfcn_whistlecount_T matlabfcn_whistlecount_P = {
  /* Variable: hopSize
   * Referenced by:
   *   '<Root>/MATLAB Function'
   *   '<Root>/MATLAB Function1'
   */
  1103.0,

  /* Variable: mean_overallX
   * Referenced by: '<Root>/MATLAB Function4'
   */
  { 0.15314256462304038, 0.0028553123013311237 },

  /* Variable: std_overallX
   * Referenced by: '<Root>/MATLAB Function4'
   */
  { 0.51016818591363922, 0.0084836004039719366 },

  /* Variable: windowLength
   * Referenced by:
   *   '<Root>/MATLAB Function'
   *   '<Root>/MATLAB Function1'
   */
  2205.0,

  /* Mask Parameter: Counter_InitialCount
   * Referenced by: '<Root>/Counter'
   */
  0U,

  /* Expression: SampleTime
   * Referenced by: '<S1>/MATLAB System'
   */
  0.5,

  /* Expression: 1/32767
   * Referenced by: '<Root>/Gain'
   */
  3.0518509475997192E-5,

  /* Expression: double('zcr')
   * Referenced by: '<Root>/Second Feature'
   */
  { 122.0, 99.0, 114.0 },

  /* Expression: double('energy')
   * Referenced by: '<Root>/First Feature'
   */
  { 101.0, 110.0, 101.0, 114.0, 103.0, 121.0 }
};

/* Constant parameters (auto storage) */
const ConstP_matlabfcn_whistlecount_T matlabfcn_whistlecount_ConstP = {
  /* Computed Parameter: GeneratedFilterBlock_RTP1COEFF
   * Referenced by: '<S2>/Generated Filter Block'
   */
  { 0.025599793165462612, 0.0, -0.025599793165462612, 0.13251323591010702, 0.0,
    -0.13251323591010702, 0.0752683347298045, 0.0, -0.0752683347298045,
    0.022526022637930441, 0.0, -0.022526022637930441, 0.26827034137169464, 0.0,
    -0.26827034137169464, 0.13600778978208308, 0.0, -0.13600778978208308,
    0.043162603718400652, 0.0, -0.043162603718400652, 0.029363376671280753, 0.0,
    -0.029363376671280753, 0.2476562942330767, 0.0, -0.2476562942330767,
    1.4264199321628444, 0.0, -1.4264199321628444 },

  /* Computed Parameter: GeneratedFilterBlock_RTP2COEFF
   * Referenced by: '<S2>/Generated Filter Block'
   */
  { -1.839579261352277, 0.982042265563318, -1.8159866465101668,
    0.97590937505080377, -1.7268957203529003, 0.9706316061833562,
    -1.7571059159319473, 0.9693357159092042, -1.8703792699134461,
    0.99629457166700208, -1.6805637273723788, 0.99429793937732558,
    -1.7013476380389894, 0.975562130223233, -1.7878564576760505,
    0.97136119686728739, -1.8577823493293619, 0.98899353792778166,
    -1.6847673926577302, 0.98377438122508509 },

  /* Expression: a.ScaleValues
   * Referenced by: '<S2>/Generated Filter Block'
   */
  { 0.00668361882128672, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }
};
