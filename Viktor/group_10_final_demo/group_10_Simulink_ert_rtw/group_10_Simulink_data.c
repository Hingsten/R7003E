/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: group_10_Simulink_data.c
 *
 * Code generated for Simulink model 'group_10_Simulink'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Jan  6 11:07:27 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "group_10_Simulink.h"

/* Block parameters (default storage) */
Parameters_group_10_Simulink group_10_Simulink_P = {
  /* Variable: Ad
   * Referenced by: '<S5>/Gain7'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.00216937577F, 0.169257507F, 0.0123862131F,
    3.63566065F, -3.56150304E-5F, -0.00954899471F, 1.0005976F, 0.218485147F,
    5.93717268E-5F, 0.0174099766F, 0.00474093808F, 0.924248695F },

  /* Variable: Bd
   * Referenced by: '<S5>/Gain8'
   */
  { 0.00013388088F, 0.0392918736F, -0.000585834379F, -0.171956927F },

  /* Variable: Cd
   * Referenced by: '<S5>/Gain10'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F },

  /* Variable: Kd
   * Referenced by: '<S2>/controller'
   */
  { -85.5841293F, -66.5997925F, -100.464256F, -15.3948832F },

  /* Variable: Ld
   * Referenced by: '<S5>/Gain9'
   */
  { 0.206922397F, -0.0984032825F, -0.258340448F, -5.31531F, -0.0187617335F,
    0.152836204F, 0.217459738F, 3.15992427F },

  /* Variable: Md1
   * Referenced by: '<S5>/Gain'
   */
  { 0.762849271F, 0.0299416352F, -0.0381715484F, 0.0287549421F, 0.998597F,
    -0.308095217F, 0.00518891914F, 0.0401074365F, 0.816315532F },

  /* Variable: Md2
   * Referenced by: '<S5>/Gain1'
   */
  { 0.00042434546F, 0.0904737413F, -0.415341914F },

  /* Variable: Md3
   * Referenced by: '<S5>/Gain2'
   */
  { 7.54536343F, 382.294067F, -1817.922F },

  /* Variable: Md4
   * Referenced by: '<S5>/Gain3'
   */
  { 0.237479523F, -0.0531060435F, 0.321402043F },

  /* Variable: Md5
   * Referenced by: '<S5>/Gain4'
   */
  { -7.54536343F, -382.294067F, 1817.922F },

  /* Variable: Md6
   * Referenced by: '<S5>/Gain5'
   */
  { 1.0F, 0.0F, 0.0F, -0.0F },

  /* Variable: Md7
   * Referenced by: '<S5>/Gain6'
   */
  { 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -0.0F, 0.0F, 0.0F, 1.0F },

  /* Variable: Nxd
   * Referenced by: '<S2>/Gain3'
   */
  0.0F,

  /* Variable: fGyroBias
   * Referenced by: '<S3>/gyro bias'
   */
  -30.0F,

  /* Variable: fWheelRadius
   * Referenced by: '<S3>/convert to meters'
   */
  0.0216F,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S6>/UD'
   */
  0.0F,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_g
   * Referenced by: '<S7>/UD'
   */
  0.0F,

  /* Mask Parameter: M1V4LeftMotorDriverPWM6D8FST_Vs
   * Referenced by: '<S54>/Saturation -Vsupply to Vsupply'
   */
  9.0F,

  /* Expression: 1
   * Referenced by: '<Root>/Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Serial Transmit'
   */
  0.0,

  /* Expression: 4
   * Referenced by: '<Root>/Active signal'
   */
  4.0,

  /* Expression: 1
   * Referenced by: '<Root>/Signal gain'
   */
  1.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S55>/Constant'
   */
  0.0F,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S2>/Gain4'
   */
  85.5841293F,

  /* Computed Parameter: converttoradians_Gain
   * Referenced by: '<S3>/convert to  radians'
   */
  -0.00872664619F,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S6>/TSamp'
   */
  200.0F,

  /* Computed Parameter: DiscreteTimeIntegratorconvertfr
   * Referenced by: '<S3>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   */
  0.005F,

  /* Computed Parameter: DiscreteTimeIntegratorconvert_o
   * Referenced by: '<S3>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   */
  0.0F,

  /* Computed Parameter: TSamp_WtEt_j
   * Referenced by: '<S7>/TSamp'
   */
  200.0F,

  /* Computed Parameter: Internal_1_1_A
   * Referenced by: '<S8>/Internal_1_1'
   */
  -0.0F,

  /* Computed Parameter: Internal_1_1_C
   * Referenced by: '<S8>/Internal_1_1'
   */
  1.0F,

  /* Computed Parameter: Internal_1_1_InitialCondition
   * Referenced by: '<S8>/Internal_1_1'
   */
  0.0F,

  /* Computed Parameter: Internal_1_2_InitialCondition
   * Referenced by: '<S8>/Internal_1_2'
   */
  0.0F,

  /* Computed Parameter: Internal_1_3_InitialCondition
   * Referenced by: '<S8>/Internal_1_3'
   */
  0.0F,

  /* Computed Parameter: Internal_1_4_InitialCondition
   * Referenced by: '<S8>/Internal_1_4'
   */
  0.0F,

  /* Computed Parameter: Internal_2_1_InitialCondition
   * Referenced by: '<S8>/Internal_2_1'
   */
  0.0F,

  /* Computed Parameter: Internal_2_2_A
   * Referenced by: '<S8>/Internal_2_2'
   */
  -0.0F,

  /* Computed Parameter: Internal_2_2_C
   * Referenced by: '<S8>/Internal_2_2'
   */
  1.0F,

  /* Computed Parameter: Internal_2_2_InitialCondition
   * Referenced by: '<S8>/Internal_2_2'
   */
  0.0F,

  /* Computed Parameter: Internal_2_3_InitialCondition
   * Referenced by: '<S8>/Internal_2_3'
   */
  0.0F,

  /* Computed Parameter: Internal_2_4_InitialCondition
   * Referenced by: '<S8>/Internal_2_4'
   */
  0.0F,

  /* Computed Parameter: Internal_3_1_InitialCondition
   * Referenced by: '<S8>/Internal_3_1'
   */
  0.0F,

  /* Computed Parameter: Internal_3_2_InitialCondition
   * Referenced by: '<S8>/Internal_3_2'
   */
  0.0F,

  /* Computed Parameter: Internal_3_3_A
   * Referenced by: '<S8>/Internal_3_3'
   */
  -0.0F,

  /* Computed Parameter: Internal_3_3_C
   * Referenced by: '<S8>/Internal_3_3'
   */
  1.0F,

  /* Computed Parameter: Internal_3_3_InitialCondition
   * Referenced by: '<S8>/Internal_3_3'
   */
  0.0F,

  /* Computed Parameter: Internal_3_4_InitialCondition
   * Referenced by: '<S8>/Internal_3_4'
   */
  0.0F,

  /* Computed Parameter: Internal_4_1_InitialCondition
   * Referenced by: '<S8>/Internal_4_1'
   */
  0.0F,

  /* Computed Parameter: Internal_4_2_InitialCondition
   * Referenced by: '<S8>/Internal_4_2'
   */
  0.0F,

  /* Computed Parameter: Internal_4_3_InitialCondition
   * Referenced by: '<S8>/Internal_4_3'
   */
  0.0F,

  /* Computed Parameter: Internal_4_4_A
   * Referenced by: '<S8>/Internal_4_4'
   */
  -0.0F,

  /* Computed Parameter: Internal_4_4_C
   * Referenced by: '<S8>/Internal_4_4'
   */
  1.0F,

  /* Computed Parameter: Internal_4_4_InitialCondition
   * Referenced by: '<S8>/Internal_4_4'
   */
  0.0F,

  /* Computed Parameter: Internal_1_1_A_e
   * Referenced by: '<S9>/Internal_1_1'
   */
  -0.0F,

  /* Computed Parameter: Internal_1_1_C_i
   * Referenced by: '<S9>/Internal_1_1'
   */
  1.0F,

  /* Computed Parameter: Internal_1_1_InitialCondition_j
   * Referenced by: '<S9>/Internal_1_1'
   */
  0.0F,

  /* Computed Parameter: Internal_1_2_InitialCondition_o
   * Referenced by: '<S9>/Internal_1_2'
   */
  0.0F,

  /* Computed Parameter: Internal_1_3_InitialCondition_o
   * Referenced by: '<S9>/Internal_1_3'
   */
  0.0F,

  /* Computed Parameter: Internal_2_1_InitialCondition_h
   * Referenced by: '<S9>/Internal_2_1'
   */
  0.0F,

  /* Computed Parameter: Internal_2_2_A_k
   * Referenced by: '<S9>/Internal_2_2'
   */
  -0.0F,

  /* Computed Parameter: Internal_2_2_C_n
   * Referenced by: '<S9>/Internal_2_2'
   */
  1.0F,

  /* Computed Parameter: Internal_2_2_InitialCondition_f
   * Referenced by: '<S9>/Internal_2_2'
   */
  0.0F,

  /* Computed Parameter: Internal_2_3_InitialCondition_d
   * Referenced by: '<S9>/Internal_2_3'
   */
  0.0F,

  /* Computed Parameter: Internal_3_1_InitialCondition_a
   * Referenced by: '<S9>/Internal_3_1'
   */
  0.0F,

  /* Computed Parameter: Internal_3_2_InitialCondition_i
   * Referenced by: '<S9>/Internal_3_2'
   */
  0.0F,

  /* Computed Parameter: Internal_3_3_A_g
   * Referenced by: '<S9>/Internal_3_3'
   */
  -0.0F,

  /* Computed Parameter: Internal_3_3_C_i
   * Referenced by: '<S9>/Internal_3_3'
   */
  1.0F,

  /* Computed Parameter: Internal_3_3_InitialCondition_e
   * Referenced by: '<S9>/Internal_3_3'
   */
  0.0F,

  /* Computed Parameter: converttoradianssec_Gain
   * Referenced by: '<S3>/convert to radians//sec'
   */
  0.000133158057F,

  /* Computed Parameter: SaturationVsupplytoVsupply_Lowe
   * Referenced by: '<S54>/Saturation -Vsupply to Vsupply'
   */
  -9.0F,

  /* Computed Parameter: conversiontodutycycleconverttou
   * Referenced by: '<S54>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)'
   */
  28.333334F,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S5>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S5>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S10>/Constant'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
