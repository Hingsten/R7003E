/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: group_10_Simulink.c
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
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "group_10_Simulink_types.h"
#include "group_10_Simulink_private.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_group_10_Simulink group_10_Simulink_B;

/* Block states (default storage) */
D_Work_group_10_Simulink group_10_Simulink_DWork;

/* Real-time model */
static RT_MODEL_group_10_Simulink group_10_Simulink_M_;
RT_MODEL_group_10_Simulink *const group_10_Simulink_M = &group_10_Simulink_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void group_10_Simulink_step(void)
{
  /* local block i/o variables */
  real32_T rtb_TSamp;
  real32_T rtb_TSamp_n;
  real32_T rtb_converttoradianssec;
  real32_T rtb_Internal_4_4;
  real32_T rtb_Internal_3_3;
  real32_T rtb_Internal_3_2;
  real32_T rtb_DataTypeConversion1;
  codertarget_arduinobase_inter_a *obj;
  real32_T Sum2_tmp_tmp;
  real32_T rtb_Add1_idx_1;
  real32_T rtb_Gain8_idx_0;
  real32_T tmp;
  real32_T tmp_0;
  int16_T i;
  uint16_T rtb_DataTypeConversion4;
  uint16_T rtb_DataTypeConversion6;

  /* FromWorkspace: '<S1>/FromWs' */
  {
    real_T *pDataValues = (real_T *)
      group_10_Simulink_DWork.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      group_10_Simulink_DWork.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = group_10_Simulink_DWork.FromWs_IWORK.PrevIndex;
    real_T t = group_10_Simulink_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[189]) {
      currTimeIndex = 188;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    group_10_Simulink_DWork.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 4; ++elIdx) {
              (&group_10_Simulink_B.FromWs[0])[elIdx] =
                pDataValues[currTimeIndex];
              pDataValues += 190;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 4; ++elIdx) {
              (&group_10_Simulink_B.FromWs[0])[elIdx] =
                pDataValues[currTimeIndex + 1];
              pDataValues += 190;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex = currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 4; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&group_10_Simulink_B.FromWs[0])[elIdx] = (real_T) rtInterpolate(d1,
              d2, f1, f2);
            pDataValues += 190;
          }
        }
      }
    }
  }

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Active signal'
   *  Gain: '<Root>/Gain'
   */
  switch ((int16_T)group_10_Simulink_P.Activesignal_Value) {
   case 1:
    group_10_Simulink_B.Signalgain = group_10_Simulink_B.FromWs[0];
    break;

   case 2:
    group_10_Simulink_B.Signalgain = group_10_Simulink_B.FromWs[1];
    break;

   case 3:
    group_10_Simulink_B.Signalgain = group_10_Simulink_B.FromWs[2];
    break;

   default:
    group_10_Simulink_B.Signalgain = group_10_Simulink_P.Gain_Gain *
      group_10_Simulink_B.FromWs[3];
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* Gain: '<Root>/Signal gain' */
  group_10_Simulink_B.Signalgain *= group_10_Simulink_P.Signalgain_Gain;

  /* Gain: '<S2>/Gain3' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  group_10_Simulink_B.Gain3 = group_10_Simulink_P.Nxd * (real32_T)
    group_10_Simulink_B.Signalgain;

  /* MATLABSystem: '<S4>/Encoder' */
  /*         %% Define output properties */
  /* 'Encoder_arduino:136' num = 0; */
  /* 'Encoder_arduino:140' num = 1; */
  /* 'Encoder_arduino:121' y = int32(0); */
  /* 'Encoder_arduino:122' if coder.target('Rtw') */
  /*  Call: int enc_output(int enc) */
  /* 'Encoder_arduino:124' y = coder.ceval('enc_output', obj.Encoder); */
  group_10_Simulink_B.rtb_Encoder_m = enc_output(1.0);

  /* Gain: '<S3>/convert to meters' incorporates:
   *  DataTypeConversion: '<S4>/Data Type  Conversion2'
   *  Gain: '<S3>/convert to  radians'
   *  MATLABSystem: '<S4>/Encoder'
   */
  group_10_Simulink_B.converttometers =
    group_10_Simulink_P.converttoradians_Gain * (real32_T)
    group_10_Simulink_B.rtb_Encoder_m * group_10_Simulink_P.fWheelRadius;

  /* SampleTimeMath: '<S6>/TSamp'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = group_10_Simulink_B.converttometers *
    group_10_Simulink_P.TSamp_WtEt;

  /* SampleTimeMath: '<S7>/TSamp' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *
   * About '<S7>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_n = group_10_Simulink_DWork.DiscreteTimeIntegratorconvertfr *
    group_10_Simulink_P.TSamp_WtEt_j;

  /* DiscreteStateSpace: '<S8>/Internal_1_1' */
  {
    rtb_Internal_4_4 = group_10_Simulink_P.Internal_1_1_C*
      group_10_Simulink_DWork.Internal_1_1_DSTATE;
  }

  /* DiscreteStateSpace: '<S8>/Internal_1_2' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_1_3' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_1_4' */
  {
    rtb_DataTypeConversion1 = 0.0;
  }

  /* Sum: '<S8>/Sum1' */
  group_10_Simulink_B.Sum1 = ((rtb_Internal_4_4 + rtb_Internal_3_3) +
    rtb_Internal_3_2) + rtb_DataTypeConversion1;

  /* DiscreteStateSpace: '<S8>/Internal_2_1' */
  {
    rtb_DataTypeConversion1 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_2_2' */
  {
    rtb_Internal_3_2 = group_10_Simulink_P.Internal_2_2_C*
      group_10_Simulink_DWork.Internal_2_2_DSTATE;
  }

  /* DiscreteStateSpace: '<S8>/Internal_2_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_2_4' */
  {
    rtb_Internal_4_4 = 0.0;
  }

  /* Sum: '<S8>/Sum2' */
  Sum2_tmp_tmp = ((rtb_DataTypeConversion1 + rtb_Internal_3_2) +
                  rtb_Internal_3_3) + rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S8>/Internal_3_1' */
  {
    rtb_DataTypeConversion1 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_3_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_3_3' */
  {
    rtb_Internal_3_3 = group_10_Simulink_P.Internal_3_3_C*
      group_10_Simulink_DWork.Internal_3_3_DSTATE;
  }

  /* DiscreteStateSpace: '<S8>/Internal_3_4' */
  {
    rtb_Internal_4_4 = 0.0;
  }

  /* Sum: '<S8>/Sum3' */
  tmp = ((rtb_DataTypeConversion1 + rtb_Internal_3_2) + rtb_Internal_3_3) +
    rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S8>/Internal_4_1' */
  {
    rtb_DataTypeConversion1 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_4_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_4_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* DiscreteStateSpace: '<S8>/Internal_4_4' */
  {
    rtb_Internal_4_4 = group_10_Simulink_P.Internal_4_4_C*
      group_10_Simulink_DWork.Internal_4_4_DSTATE;
  }

  /* Sum: '<S8>/Sum4' */
  tmp_0 = ((rtb_DataTypeConversion1 + rtb_Internal_3_2) + rtb_Internal_3_3) +
    rtb_Internal_4_4;

  /* DiscreteStateSpace: '<S9>/Internal_1_1' */
  {
    rtb_DataTypeConversion1 = group_10_Simulink_P.Internal_1_1_C_i*
      group_10_Simulink_DWork.Internal_1_1_DSTATE_n;
  }

  /* DiscreteStateSpace: '<S9>/Internal_1_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_1_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* Sum: '<S9>/Sum1' */
  rtb_Gain8_idx_0 = (rtb_DataTypeConversion1 + rtb_Internal_3_2) +
    rtb_Internal_3_3;

  /* DiscreteStateSpace: '<S9>/Internal_2_1' */
  {
    rtb_DataTypeConversion1 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_2_2' */
  {
    rtb_Internal_3_2 = group_10_Simulink_P.Internal_2_2_C_n*
      group_10_Simulink_DWork.Internal_2_2_DSTATE_o;
  }

  /* DiscreteStateSpace: '<S9>/Internal_2_3' */
  {
    rtb_Internal_3_3 = 0.0;
  }

  /* Sum: '<S9>/Sum2' */
  rtb_Add1_idx_1 = (rtb_DataTypeConversion1 + rtb_Internal_3_2) +
    rtb_Internal_3_3;

  /* DiscreteStateSpace: '<S9>/Internal_3_1' */
  {
    rtb_DataTypeConversion1 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_3_2' */
  {
    rtb_Internal_3_2 = 0.0;
  }

  /* DiscreteStateSpace: '<S9>/Internal_3_3' */
  {
    rtb_Internal_3_3 = group_10_Simulink_P.Internal_3_3_C_i*
      group_10_Simulink_DWork.Internal_3_3_DSTATE_o;
  }

  /* Sum: '<S5>/Add1' incorporates:
   *  Gain: '<S5>/Gain4'
   *  Sum: '<S9>/Sum1'
   *  Sum: '<S9>/Sum2'
   *  Sum: '<S9>/Sum3'
   */
  group_10_Simulink_B.rtb_Add1_idx_0 = group_10_Simulink_P.Md5[0] *
    group_10_Simulink_B.converttometers + rtb_Gain8_idx_0;
  rtb_Add1_idx_1 += group_10_Simulink_P.Md5[1] *
    group_10_Simulink_B.converttometers;
  group_10_Simulink_B.rtb_Add1_idx_2 = ((rtb_DataTypeConversion1 +
    rtb_Internal_3_2) + rtb_Internal_3_3) + group_10_Simulink_P.Md5[2] *
    group_10_Simulink_B.converttometers;

  /* Sum: '<S5>/Add2' incorporates:
   *  Gain: '<S5>/Gain5'
   *  Gain: '<S5>/Gain6'
   *  Sum: '<S5>/Add1'
   */
  for (i = 0; i < 4; i++) {
    group_10_Simulink_B.Add2[i] = ((group_10_Simulink_P.Md7[i + 4] *
      rtb_Add1_idx_1 + group_10_Simulink_P.Md7[i] *
      group_10_Simulink_B.rtb_Add1_idx_0) + group_10_Simulink_P.Md7[i + 8] *
      group_10_Simulink_B.rtb_Add1_idx_2) + group_10_Simulink_P.Md6[i] *
      group_10_Simulink_B.converttometers;
  }

  /* End of Sum: '<S5>/Add2' */

  /* ManualSwitch: '<S5>/Manual Switch1' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Gain: '<S5>/Gain8'
   *  ManualSwitch: '<S5>/Manual Switch'
   *  Sum: '<S5>/Add2'
   *  Sum: '<S6>/Diff'
   *  Sum: '<S7>/Diff'
   *  UnitDelay: '<S6>/UD'
   *  UnitDelay: '<S7>/UD'
   *
   * Block description for '<S6>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S7>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S6>/UD':
   *
   *  Store in Global RAM
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  if (group_10_Simulink_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_Gain8_idx_0 = group_10_Simulink_B.converttometers;
    group_10_Simulink_B.rtb_Gain8_idx_1 = rtb_TSamp -
      group_10_Simulink_DWork.UD_DSTATE;
    group_10_Simulink_B.rtb_Gain8_idx_2 =
      group_10_Simulink_DWork.DiscreteTimeIntegratorconvertfr;
    group_10_Simulink_B.rtb_Gain8_idx_3 = rtb_TSamp_n -
      group_10_Simulink_DWork.UD_DSTATE_o;
  } else if (group_10_Simulink_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<S5>/Manual Switch' incorporates:
     *  Gain: '<S5>/Gain8'
     *  Sum: '<S8>/Sum2'
     *  Sum: '<S8>/Sum3'
     *  Sum: '<S8>/Sum4'
     */
    rtb_Gain8_idx_0 = group_10_Simulink_B.Sum1;
    group_10_Simulink_B.rtb_Gain8_idx_1 = Sum2_tmp_tmp;
    group_10_Simulink_B.rtb_Gain8_idx_2 = tmp;
    group_10_Simulink_B.rtb_Gain8_idx_3 = tmp_0;
  } else {
    rtb_Gain8_idx_0 = group_10_Simulink_B.Add2[0];
    group_10_Simulink_B.rtb_Gain8_idx_1 = group_10_Simulink_B.Add2[1];
    group_10_Simulink_B.rtb_Gain8_idx_2 = group_10_Simulink_B.Add2[2];
    group_10_Simulink_B.rtb_Gain8_idx_3 = group_10_Simulink_B.Add2[3];
  }

  /* End of ManualSwitch: '<S5>/Manual Switch1' */

  /* Product: '<S2>/Product1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  DiscreteIntegrator: '<S3>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Fcn: '<S2>/turn off the motor if the measured angle is greater than X degrees'
   *  Gain: '<S2>/Gain4'
   *  Gain: '<S2>/controller'
   *  Gain: '<S5>/Gain8'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum1'
   */
  group_10_Simulink_B.Gain3 = (((((group_10_Simulink_B.Gain3 + rtb_Gain8_idx_0) *
    group_10_Simulink_P.Kd[0] + (group_10_Simulink_B.Gain3 +
    group_10_Simulink_B.rtb_Gain8_idx_1) * group_10_Simulink_P.Kd[1]) +
    (group_10_Simulink_B.Gain3 + group_10_Simulink_B.rtb_Gain8_idx_2) *
    group_10_Simulink_P.Kd[2]) + (group_10_Simulink_B.Gain3 +
    group_10_Simulink_B.rtb_Gain8_idx_3) * group_10_Simulink_P.Kd[3]) +
    group_10_Simulink_P.Gain4_Gain * (real32_T)group_10_Simulink_B.Signalgain) *
    (real32_T)((real32_T)fabs
               (group_10_Simulink_DWork.DiscreteTimeIntegratorconvertfr) < 0.75F);

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Fcn: '<S10>/Fcn'
   */
  rtb_Gain8_idx_0 = (real32_T)floor((group_10_Simulink_B.Gain3 + 10.0F) *
    3276.8F);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0);
  }

  rtb_DataTypeConversion6 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S10>/Data Type Conversion' */

  /* MATLABSystem: '<S10>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S40>/Extract Desired Bits'
   *  DataTypeConversion: '<S41>/Extract Desired Bits'
   */
  group_10_Simulink_B.dataIn[1] = (uint8_T)(rtb_DataTypeConversion6 >> 8);
  group_10_Simulink_B.dataIn[2] = (uint8_T)rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
   *  Fcn: '<S10>/Fcn1'
   */
  rtb_Gain8_idx_0 = (real32_T)floor((group_10_Simulink_B.converttometers + 10.0F)
    * 3276.8F);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0);
  }

  rtb_DataTypeConversion6 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S10>/Data Type Conversion1' */

  /* MATLABSystem: '<S10>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S46>/Extract Desired Bits'
   *  DataTypeConversion: '<S47>/Extract Desired Bits'
   */
  group_10_Simulink_B.dataIn[3] = (uint8_T)(rtb_DataTypeConversion6 >> 8);
  group_10_Simulink_B.dataIn[4] = (uint8_T)rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S4>/Data Type  Conversion1' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   *  Fcn: '<S10>/Fcn2'
   */
  rtb_DataTypeConversion1 =
    (group_10_Simulink_DWork.DiscreteTimeIntegratorconvertfr + 10.0F) * 3276.8F;

  /* DataTypeConversion: '<S10>/Data Type Conversion2' */
  rtb_Gain8_idx_0 = (real32_T)floor(rtb_DataTypeConversion1);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0);
  }

  rtb_DataTypeConversion4 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S10>/Data Type Conversion2' */

  /* MATLABSystem: '<S10>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S48>/Extract Desired Bits'
   *  DataTypeConversion: '<S49>/Extract Desired Bits'
   */
  group_10_Simulink_B.dataIn[5] = (uint8_T)(rtb_DataTypeConversion4 >> 8);
  group_10_Simulink_B.dataIn[6] = (uint8_T)rtb_DataTypeConversion4;

  /* DataTypeConversion: '<S4>/Data Type  Conversion1' incorporates:
   *  Fcn: '<S10>/Fcn3'
   */
  rtb_DataTypeConversion1 = (group_10_Simulink_B.Sum1 + 10.0F) * 3276.8F;

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  rtb_Gain8_idx_0 = (real32_T)floor(rtb_DataTypeConversion1);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0);
  }

  rtb_DataTypeConversion4 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S10>/Data Type Conversion3' */

  /* MATLABSystem: '<S10>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S50>/Extract Desired Bits'
   *  DataTypeConversion: '<S51>/Extract Desired Bits'
   */
  group_10_Simulink_B.dataIn[7] = (uint8_T)(rtb_DataTypeConversion4 >> 8);
  group_10_Simulink_B.dataIn[8] = (uint8_T)rtb_DataTypeConversion4;

  /* DataTypeConversion: '<S4>/Data Type  Conversion1' incorporates:
   *  Fcn: '<S10>/Fcn4'
   *  Sum: '<S8>/Sum3'
   */
  rtb_DataTypeConversion1 = (tmp + 10.0F) * 3276.8F;

  /* DataTypeConversion: '<S10>/Data Type Conversion4' */
  rtb_Gain8_idx_0 = (real32_T)floor(rtb_DataTypeConversion1);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0);
  }

  rtb_DataTypeConversion4 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S10>/Data Type Conversion4' */

  /* DataTypeConversion: '<S10>/Data Type Conversion5' incorporates:
   *  Fcn: '<S10>/Fcn5'
   */
  rtb_Gain8_idx_0 = (real32_T)floor((group_10_Simulink_B.Add2[0] + 10.0F) *
    3276.8F);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0);
  }

  rtb_DataTypeConversion6 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S10>/Data Type Conversion5' */

  /* MATLABSystem: '<S10>/Serial Transmit' incorporates:
   *  DataTypeConversion: '<S42>/Extract Desired Bits'
   *  DataTypeConversion: '<S43>/Extract Desired Bits'
   */
  group_10_Simulink_B.dataIn[11] = (uint8_T)(rtb_DataTypeConversion6 >> 8);
  group_10_Simulink_B.dataIn[12] = (uint8_T)rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S10>/Data Type Conversion6' incorporates:
   *  Fcn: '<S10>/Fcn6'
   */
  rtb_Gain8_idx_0 = (real32_T)floor((group_10_Simulink_B.Add2[2] + 10.0F) *
    3276.8F);
  if (rtIsNaNF(rtb_Gain8_idx_0) || rtIsInfF(rtb_Gain8_idx_0)) {
    rtb_Gain8_idx_0 = 0.0F;
  } else {
    rtb_Gain8_idx_0 = (real32_T)fmod(rtb_Gain8_idx_0, 65536.0);
  }

  rtb_DataTypeConversion6 = rtb_Gain8_idx_0 < 0.0F ? (uint16_T)-(int16_T)
    (uint16_T)-rtb_Gain8_idx_0 : (uint16_T)rtb_Gain8_idx_0;

  /* End of DataTypeConversion: '<S10>/Data Type Conversion6' */

  /* MATLABSystem: '<S10>/Serial Transmit' incorporates:
   *  Constant: '<S10>/Constant'
   *  DataTypeConversion: '<S44>/Extract Desired Bits'
   *  DataTypeConversion: '<S45>/Extract Desired Bits'
   *  DataTypeConversion: '<S52>/Extract Desired Bits'
   *  DataTypeConversion: '<S53>/Extract Desired Bits'
   */
  if (group_10_Simulink_DWork.obj.Protocol !=
      group_10_Simulink_P.SerialTransmit_Protocol) {
    group_10_Simulink_DWork.obj.Protocol =
      group_10_Simulink_P.SerialTransmit_Protocol;
  }

  group_10_Simulink_B.dataIn[0] = group_10_Simulink_P.Constant_Value_i;
  group_10_Simulink_B.dataIn[9] = (uint8_T)(rtb_DataTypeConversion4 >> 8);
  group_10_Simulink_B.dataIn[10] = (uint8_T)rtb_DataTypeConversion4;
  group_10_Simulink_B.dataIn[13] = (uint8_T)(rtb_DataTypeConversion6 >> 8);
  group_10_Simulink_B.dataIn[14] = (uint8_T)rtb_DataTypeConversion6;
  MW_Serial_write(group_10_Simulink_DWork.obj.port, &group_10_Simulink_B.dataIn
                  [0], 15.0, group_10_Simulink_DWork.obj.dataSizeInBytes,
                  group_10_Simulink_DWork.obj.sendModeEnum,
                  group_10_Simulink_DWork.obj.dataType,
                  group_10_Simulink_DWork.obj.sendFormatEnum, 2.0, '\x00');
  for (i = 0; i < 3; i++) {
    /* Sum: '<S5>/Add' incorporates:
     *  DiscreteIntegrator: '<S3>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain1'
     *  Gain: '<S5>/Gain2'
     *  Gain: '<S5>/Gain3'
     *  Sum: '<S5>/Add1'
     */
    group_10_Simulink_B.Add[i] = ((group_10_Simulink_P.Md1[i + 3] *
      rtb_Add1_idx_1 + group_10_Simulink_P.Md1[i] *
      group_10_Simulink_B.rtb_Add1_idx_0) + group_10_Simulink_P.Md1[i + 6] *
      group_10_Simulink_B.rtb_Add1_idx_2) + ((group_10_Simulink_P.Md4[i] *
      group_10_Simulink_DWork.DiscreteTimeIntegratorconvertfr +
      group_10_Simulink_P.Md3[i] * group_10_Simulink_B.converttometers) +
      group_10_Simulink_P.Md2[i] * group_10_Simulink_B.Gain3);
  }

  for (i = 0; i < 2; i++) {
    /* Gain: '<S5>/Gain10' incorporates:
     *  SignalConversion generated from: '<S5>/Gain10'
     *  Sum: '<S8>/Sum2'
     *  Sum: '<S8>/Sum3'
     *  Sum: '<S8>/Sum4'
     */
    group_10_Simulink_B.Gain10[i] = ((group_10_Simulink_P.Cd[i + 2] *
      Sum2_tmp_tmp + group_10_Simulink_P.Cd[i] * group_10_Simulink_B.Sum1) +
      group_10_Simulink_P.Cd[i + 4] * tmp) + group_10_Simulink_P.Cd[i + 6] *
      tmp_0;
  }

  /* Sum: '<S5>/Sum' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)'
   */
  group_10_Simulink_B.converttometers -= group_10_Simulink_B.Gain10[0];
  group_10_Simulink_B.rtb_Add1_idx_0 =
    group_10_Simulink_DWork.DiscreteTimeIntegratorconvertfr -
    group_10_Simulink_B.Gain10[1];
  for (i = 0; i < 4; i++) {
    /* Sum: '<S5>/Add3' incorporates:
     *  Gain: '<S5>/Gain7'
     *  Gain: '<S5>/Gain8'
     *  Gain: '<S5>/Gain9'
     *  SignalConversion generated from: '<S5>/Gain10'
     *  Sum: '<S8>/Sum2'
     *  Sum: '<S8>/Sum3'
     *  Sum: '<S8>/Sum4'
     */
    group_10_Simulink_B.Add3[i] = (((group_10_Simulink_P.Ad[i + 4] *
      Sum2_tmp_tmp + group_10_Simulink_P.Ad[i] * group_10_Simulink_B.Sum1) +
      group_10_Simulink_P.Ad[i + 8] * tmp) + group_10_Simulink_P.Ad[i + 12] *
      tmp_0) + ((group_10_Simulink_P.Ld[i + 4] *
                 group_10_Simulink_B.rtb_Add1_idx_0 + group_10_Simulink_P.Ld[i] *
                 group_10_Simulink_B.converttometers) + group_10_Simulink_P.Bd[i]
                * group_10_Simulink_B.Gain3);
  }

  /* MATLABSystem: '<S4>/Gyroscope' */
  /*  initialize output to a single (float) with the value zero */
  /* 'soMPU6050Gyro:59' out = int16(zeros(3,1)); */
  /* 'soMPU6050Gyro:60' if coder.target('Rtw') */
  /*  done only for code gen */
  /* 'soMPU6050Gyro:61' coder.cinclude('MPU6050wrapper.h'); */
  /*  get the current value of the sensor */
  /* 'soMPU6050Gyro:63' coder.ceval('MPU6050Gyro_Read', coder.wref(out)); */
  MPU6050Gyro_Read(&group_10_Simulink_B.out[0]);

  /* DataTypeConversion: '<S4>/Data Type  Conversion1' incorporates:
   *  MATLABSystem: '<S4>/Gyroscope'
   */
  /*  pull the data appart */
  /* 'soMPU6050Gyro:68' xvel = out(1); */
  /* 'soMPU6050Gyro:69' yvel = out(2); */
  /* 'soMPU6050Gyro:70' zvel = out(3); */
  rtb_DataTypeConversion1 = group_10_Simulink_B.out[0];

  /* Gain: '<S3>/convert to radians//sec' incorporates:
   *  Constant: '<S3>/gyro bias'
   *  Sum: '<S3>/Sum'
   */
  rtb_converttoradianssec = (rtb_DataTypeConversion1 -
    group_10_Simulink_P.fGyroBias) *
    group_10_Simulink_P.converttoradianssec_Gain;

  /* MATLABSystem: '<S54>/Digital Output1' incorporates:
   *  Constant: '<S55>/Constant'
   *  RelationalOperator: '<S55>/Compare'
   */
  writeDigitalPin(8, (uint8_T)(group_10_Simulink_B.Gain3 <
    group_10_Simulink_P.Constant_Value));

  /* MATLABSystem: '<S54>/PWM' */
  obj = &group_10_Simulink_DWork.obj_ot;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Saturate: '<S54>/Saturation -Vsupply to Vsupply' */
  if (group_10_Simulink_B.Gain3 >
      group_10_Simulink_P.M1V4LeftMotorDriverPWM6D8FST_Vs) {
    group_10_Simulink_B.Gain3 =
      group_10_Simulink_P.M1V4LeftMotorDriverPWM6D8FST_Vs;
  } else if (group_10_Simulink_B.Gain3 <
             group_10_Simulink_P.SaturationVsupplytoVsupply_Lowe) {
    group_10_Simulink_B.Gain3 =
      group_10_Simulink_P.SaturationVsupplytoVsupply_Lowe;
  }

  /* Gain: '<S54>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)' incorporates:
   *  Saturate: '<S54>/Saturation -Vsupply to Vsupply'
   */
  tmp = (real32_T)floor(group_10_Simulink_P.conversiontodutycycleconverttou *
                        group_10_Simulink_B.Gain3);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 256.0);
  }

  /* MATLABSystem: '<S54>/PWM' incorporates:
   *  Gain: '<S54>/conversion to dutycycle (convert to uint8, overflow will provide reverse polairty magnitued)'
   */
  MW_PWM_SetDutyCycle(group_10_Simulink_DWork.obj_ot.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)(tmp < 0.0F ? (int16_T)(uint8_T)-(int8_T)(uint8_T)
    -tmp : (int16_T)(uint8_T)tmp));

  /* Update for UnitDelay: '<S6>/UD'
   *
   * Block description for '<S6>/UD':
   *
   *  Store in Global RAM
   */
  group_10_Simulink_DWork.UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
  group_10_Simulink_DWork.DiscreteTimeIntegratorconvertfr +=
    group_10_Simulink_P.DiscreteTimeIntegratorconvertfr *
    rtb_converttoradianssec;

  /* Update for UnitDelay: '<S7>/UD'
   *
   * Block description for '<S7>/UD':
   *
   *  Store in Global RAM
   */
  group_10_Simulink_DWork.UD_DSTATE_o = rtb_TSamp_n;

  /* Update for DiscreteStateSpace: '<S8>/Internal_1_1' */
  {
    group_10_Simulink_DWork.Internal_1_1_DSTATE = group_10_Simulink_B.Add3[0] +
      (group_10_Simulink_P.Internal_1_1_A)*
      group_10_Simulink_DWork.Internal_1_1_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S8>/Internal_2_2' */
  {
    group_10_Simulink_DWork.Internal_2_2_DSTATE = group_10_Simulink_B.Add3[1] +
      (group_10_Simulink_P.Internal_2_2_A)*
      group_10_Simulink_DWork.Internal_2_2_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S8>/Internal_3_3' */
  {
    group_10_Simulink_DWork.Internal_3_3_DSTATE = group_10_Simulink_B.Add3[2] +
      (group_10_Simulink_P.Internal_3_3_A)*
      group_10_Simulink_DWork.Internal_3_3_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S8>/Internal_4_4' */
  {
    group_10_Simulink_DWork.Internal_4_4_DSTATE = group_10_Simulink_B.Add3[3] +
      (group_10_Simulink_P.Internal_4_4_A)*
      group_10_Simulink_DWork.Internal_4_4_DSTATE;
  }

  /* Update for DiscreteStateSpace: '<S9>/Internal_1_1' */
  {
    group_10_Simulink_DWork.Internal_1_1_DSTATE_n = group_10_Simulink_B.Add[0] +
      (group_10_Simulink_P.Internal_1_1_A_e)*
      group_10_Simulink_DWork.Internal_1_1_DSTATE_n;
  }

  /* Update for DiscreteStateSpace: '<S9>/Internal_2_2' */
  {
    group_10_Simulink_DWork.Internal_2_2_DSTATE_o = group_10_Simulink_B.Add[1] +
      (group_10_Simulink_P.Internal_2_2_A_k)*
      group_10_Simulink_DWork.Internal_2_2_DSTATE_o;
  }

  /* Update for DiscreteStateSpace: '<S9>/Internal_3_3' */
  {
    group_10_Simulink_DWork.Internal_3_3_DSTATE_o = group_10_Simulink_B.Add[2] +
      (group_10_Simulink_P.Internal_3_3_A_g)*
      group_10_Simulink_DWork.Internal_3_3_DSTATE_o;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  group_10_Simulink_M->Timing.t[0] =
    ((time_T)(++group_10_Simulink_M->Timing.clockTick0)) *
    group_10_Simulink_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    group_10_Simulink_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void group_10_Simulink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)group_10_Simulink_M, 0,
                sizeof(RT_MODEL_group_10_Simulink));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&group_10_Simulink_M->solverInfo,
                          &group_10_Simulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&group_10_Simulink_M->solverInfo, &rtmGetTPtr
                (group_10_Simulink_M));
    rtsiSetStepSizePtr(&group_10_Simulink_M->solverInfo,
                       &group_10_Simulink_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&group_10_Simulink_M->solverInfo, (&rtmGetErrorStatus
      (group_10_Simulink_M)));
    rtsiSetRTModelPtr(&group_10_Simulink_M->solverInfo, group_10_Simulink_M);
  }

  rtsiSetSimTimeStep(&group_10_Simulink_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&group_10_Simulink_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(group_10_Simulink_M, &group_10_Simulink_M->Timing.tArray[0]);
  group_10_Simulink_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &group_10_Simulink_B), 0,
                sizeof(BlockIO_group_10_Simulink));

  /* states (dwork) */
  (void) memset((void *)&group_10_Simulink_DWork, 0,
                sizeof(D_Work_group_10_Simulink));

  {
    codertarget_arduinobase_inter_a *obj;
    real_T tmp;
    uint8_T tmp_0;

    /* Start for FromWorkspace: '<S1>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 0.625, 1.25, 1.875, 1.875, 2.5, 2.5,
        3.125, 3.125, 3.75, 3.75, 4.375, 4.375, 5.0, 5.0, 5.625, 5.625, 6.25,
        6.25, 6.875, 6.875, 7.5, 7.5, 8.125, 8.125, 8.75, 8.75, 9.375, 9.375,
        10.0, 10.0, 10.625, 10.625, 11.25, 11.25, 11.875, 11.875, 12.5, 12.5,
        13.125, 13.125, 13.75, 13.75, 14.375, 14.375, 15.0, 15.0, 15.625, 15.625,
        16.25, 16.25, 16.875, 16.875, 17.5, 17.5, 18.125, 18.125, 18.75, 18.75,
        19.375, 19.375, 20.0, 20.0, 20.625, 20.625, 21.25, 21.25, 21.875, 21.875,
        22.5, 22.5, 23.125, 23.125, 23.75, 23.75, 24.375, 24.375, 25.0, 25.0,
        25.625, 25.625, 26.25, 26.25, 26.875, 26.875, 27.5, 27.5, 28.125, 28.125,
        28.75, 28.75, 29.375, 29.375, 30.0, 30.0, 30.625, 30.625, 31.25, 31.25,
        31.875, 31.875, 32.5, 32.5, 33.125, 33.125, 33.75, 33.75, 34.375, 34.375,
        35.0, 35.0, 35.625, 35.625, 36.25, 36.25, 36.875, 36.875, 37.5, 37.5,
        38.125, 38.125, 38.75, 38.75, 39.375, 39.375, 40.0, 40.0, 40.625, 40.625,
        41.25, 41.25, 41.875, 41.875, 42.5, 42.5, 43.125, 43.125, 43.75, 43.75,
        44.375, 44.375, 45.0, 45.0, 45.625, 45.625, 46.25, 46.25, 46.875, 46.875,
        47.5, 47.5, 48.125, 48.125, 48.75, 48.75, 49.375, 49.375, 50.0, 50.0,
        50.625, 50.625, 51.25, 51.25, 51.875, 51.875, 52.5, 52.5, 53.125, 53.125,
        53.75, 53.75, 54.375, 54.375, 55.0, 55.0, 55.625, 55.625, 56.25, 56.25,
        56.875, 56.875, 57.5, 57.5, 58.125, 58.125, 58.75, 58.75, 59.375, 59.375,
        60.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, -0.0, -0.0, 0.03125, 0.03125, 0.0625, 0.0625, 0.09375, 0.09375,
        0.125, 0.125, 0.15625, 0.15625, 0.1875, 0.1875, 0.21875, 0.21875, 0.25,
        0.25, 0.28125, 0.28125, 0.3125, 0.3125, 0.34375, 0.34375, 0.375, 0.375,
        0.40625, 0.40625, 0.4375, 0.4375, 0.46875, 0.46875, 0.5, 0.5, 0.5, 0.5,
        0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
        0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
        0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
        0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
        0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
        0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
        0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
        0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
        0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.125, 0.125, 0.25, 0.25, 0.375, 0.375, 0.5, 0.5, 0.625, 0.625,
        0.75, 0.75, 0.875, 0.875, 1.0, 1.0, 1.125, 1.125, 1.25, 1.25, 1.375,
        1.375, 1.5, 1.5, 1.625, 1.625, 1.75, 1.75, 1.875, 1.875, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 1.2246467991473533E-17, 1.2246467991473533E-17,
        -0.070710678118654752, -0.070710678118654752, -0.1, -0.1,
        -0.070710678118654766, -0.070710678118654766, 0.0, 0.0,
        0.070710678118654752, 0.070710678118654752, 0.1, 0.1,
        0.070710678118654766, 0.070710678118654766, 1.2246467991473533E-17,
        1.2246467991473533E-17, -0.070710678118654752, -0.070710678118654752,
        -0.1, -0.1, -0.070710678118654766, -0.070710678118654766, 0.0, 0.0,
        0.070710678118654752, 0.070710678118654752, 0.1, 0.1,
        0.070710678118654766, 0.070710678118654766, 1.2246467991473533E-17,
        1.2246467991473533E-17, -0.070710678118654752, -0.070710678118654752,
        -0.1, -0.1, -0.070710678118654766, -0.070710678118654766, 0.0, 0.0,
        0.070710678118654752, 0.070710678118654752, 0.1, 0.1,
        0.070710678118654766, 0.070710678118654766, 1.2246467991473533E-17,
        1.2246467991473533E-17, -0.070710678118654752, -0.070710678118654752,
        -0.1, -0.1, -0.070710678118654766, -0.070710678118654766, 0.0, 0.0,
        0.070710678118654752, 0.070710678118654752, 0.1, 0.1,
        0.070710678118654766, 0.070710678118654766, 1.2246467991473533E-17,
        1.2246467991473533E-17, -0.070710678118654752, -0.070710678118654752,
        -0.1, -0.1, -0.070710678118654766, -0.070710678118654766, 0.0, 0.0,
        0.070710678118654752, 0.070710678118654752, 0.1, 0.1,
        0.070710678118654766, 0.070710678118654766, 1.2246467991473533E-17,
        1.2246467991473533E-17, -0.070710678118654752, -0.070710678118654752,
        -0.1, -0.1, -0.070710678118654766, -0.070710678118654766, 0.0, 0.0,
        0.070710678118654752, 0.070710678118654752, 0.1, 0.1,
        0.070710678118654766, 0.070710678118654766, 1.2246467991473533E-17,
        1.2246467991473533E-17, -0.070710678118654752, -0.070710678118654752,
        -0.1, -0.1, -0.070710678118654766, -0.070710678118654766, 0.0, 0.0,
        0.070710678118654752, 0.070710678118654752, 0.1, 0.1,
        0.070710678118654766, 0.070710678118654766, 1.2246467991473533E-17,
        1.2246467991473533E-17, -0.070710678118654752, -0.070710678118654752,
        -0.1, -0.1, -0.070710678118654766, -0.070710678118654766, 0.0, 0.0,
        0.070710678118654752, 0.070710678118654752, 0.1, 0.1,
        0.070710678118654766, 0.070710678118654766, 1.2246467991473533E-17,
        1.2246467991473533E-17, -0.070710678118654752, -0.070710678118654752,
        -0.1, -0.1, -0.070710678118654766, -0.070710678118654766, 0.0, 0.0,
        0.070710678118654752, 0.070710678118654752, 0.1, 0.1,
        0.070710678118654766, 0.070710678118654766, 1.2246467991473533E-17,
        1.2246467991473533E-17, -0.070710678118654752, -0.070710678118654752,
        -0.1, -0.1, -0.070710678118654766, -0.070710678118654766, 0.0, 0.0,
        0.070710678118654752, 0.070710678118654752, 0.1, 0.1,
        0.070710678118654766, 0.070710678118654766, 1.2246467991473533E-17,
        1.2246467991473533E-17, -0.070710678118654752, -0.070710678118654752,
        -0.1, -0.1, -0.070710678118654766, -0.070710678118654766, 0.0, 0.0,
        0.070710678118654752, 0.070710678118654752, 0.1, 0.1,
        0.070710678118654766, 0.070710678118654766, 1.2246467991473533E-17,
        1.2246467991473533E-17, -0.070710678118654752, -0.070710678118654752,
        -0.1, -0.1, -0.070710678118654766, -0.070710678118654766,
        -0.070710678118654766 } ;

      group_10_Simulink_DWork.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
      group_10_Simulink_DWork.FromWs_PWORK.DataPtr = (void *) pDataValues0;
      group_10_Simulink_DWork.FromWs_IWORK.PrevIndex = 0;
    }

    /* Start for MATLABSystem: '<S4>/Encoder' */
    /*  Constructor */
    /* 'Encoder_arduino:36' coder.allowpcode('plain'); */
    /* 'Encoder_arduino:1' matlab.System */
    /* 'Encoder_arduino:2' coder.ExternalDependency */
    /* 'Encoder_arduino:3' matlab.system.mixin.Propagates */
    /* 'Encoder_arduino:4' matlab.system.mixin.CustomIcon */
    /*  Support name-value pair arguments when constructing the object. */
    /* 'Encoder_arduino:39' setProperties(obj,nargin,varargin{:}); */
    group_10_Simulink_DWork.obj_g.matlabCodegenIsDeleted = false;

    /* 'Encoder_arduino:69' validateattributes(value,... */
    /* 'Encoder_arduino:70'                 {'numeric'},... */
    /* 'Encoder_arduino:71'                 {'real','nonnegative','integer','scalar','>=',0,'<=',obj.MaxNumEncoder},... */
    /* 'Encoder_arduino:72'                 '', ... */
    /* 'Encoder_arduino:73'                 'Encoder'); */
    /* 'Encoder_arduino:74' obj.Encoder = value; */
    /* 'Encoder_arduino:43' coder.extrinsic('sprintf') */
    /*  Do not generate code for sprintf */
    /* 'Encoder_arduino:44' validateattributes(value,... */
    /* 'Encoder_arduino:45'                 {'numeric'},... */
    /* 'Encoder_arduino:46'                 {'real','nonnegative','integer','scalar'},... */
    /* 'Encoder_arduino:47'                 '', ... */
    /* 'Encoder_arduino:48'                 'PinA'); */
    /* 'Encoder_arduino:49' assert(any(value == obj.AvailablePin), ... */
    /* 'Encoder_arduino:50'                 'Invalid value for Pin. Pin must be one of the following: %s', ... */
    /* 'Encoder_arduino:51'                 sprintf('%d ', obj.AvailablePin)); */
    /* 'Encoder_arduino:52' obj.PinA = value; */
    /* 'Encoder_arduino:56' coder.extrinsic('sprintf') */
    /*  Do not generate code for sprintf */
    /* 'Encoder_arduino:57' validateattributes(value,... */
    /* 'Encoder_arduino:58'                 {'numeric'},... */
    /* 'Encoder_arduino:59'                 {'real','nonnegative','integer','scalar'},... */
    /* 'Encoder_arduino:60'                 '', ... */
    /* 'Encoder_arduino:61'                 'PinB'); */
    /* 'Encoder_arduino:62' assert(any(value == obj.AvailablePin), ... */
    /* 'Encoder_arduino:63'                 'Invalid value for Pin. Pin must be one of the following: %s', ... */
    /* 'Encoder_arduino:64'                 sprintf('%d ', obj.AvailablePin)); */
    /* 'Encoder_arduino:65' obj.PinB = value; */
    group_10_Simulink_DWork.obj_g.isInitialized = 1L;

    /*         %% Define output properties */
    /* 'Encoder_arduino:136' num = 0; */
    /*         %% Define output properties */
    /* 'Encoder_arduino:136' num = 0; */
    /* 'Encoder_arduino:108' if coder.target('Rtw') */
    /*    Call: void enc_init(int enc, int pinA, int pinB) */
    /* 'Encoder_arduino:110' coder.cinclude('encoder_arduino.h'); */
    /* 'Encoder_arduino:111' coder.ceval('enc_init', obj.Encoder, obj.PinA, obj.PinB); */
    enc_init(1.0, 19.0, 18.0);

    /*                  if(obj.PWMTimer> 0) */
    /*                      coder.cinclude('PWMFSelect.h'); */
    /*                      coder.ceval('PWM_Select', obj.PWMFSelect, obj.PWMTimer); */
    /*                      disp('skipp!!!') */
    /*                  end */
    group_10_Simulink_DWork.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S10>/Serial Transmit' */
    group_10_Simulink_DWork.obj.matlabCodegenIsDeleted = false;
    group_10_Simulink_DWork.obj.Protocol =
      group_10_Simulink_P.SerialTransmit_Protocol;
    group_10_Simulink_DWork.obj.isInitialized = 1L;
    group_10_Simulink_DWork.obj.port = 0.0;
    group_10_Simulink_DWork.obj.dataSizeInBytes = 1.0;
    group_10_Simulink_DWork.obj.dataType = 0.0;
    group_10_Simulink_DWork.obj.sendModeEnum = 0.0;
    group_10_Simulink_DWork.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(group_10_Simulink_DWork.obj.port);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    group_10_Simulink_DWork.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S10>/Serial Transmit' */

    /* Start for MATLABSystem: '<S4>/Gyroscope' */
    /*  Constructor */
    /* 'soMPU6050Gyro:27' coder.allowpcode('plain'); */
    /* 'soMPU6050Gyro:1' matlab.System */
    /* 'soMPU6050Gyro:1' coder.ExternalDependency */
    /*  Support name-value pair arguments when constructing the object. */
    /* 'soMPU6050Gyro:30' setProperties(obj,nargin,varargin{:}); */
    group_10_Simulink_DWork.obj_gi.matlabCodegenIsDeleted = false;

    /* 'soMPU6050Gyro:34' coder.extrinsic('sprintf') */
    /*  Do not generate code for sprintf */
    /* 'soMPU6050Gyro:35' validateattributes(value,... */
    /* 'soMPU6050Gyro:36'                 {'numeric'},... */
    /* 'soMPU6050Gyro:37'                 {'real','nonnegative','integer','scalar'},... */
    /* 'soMPU6050Gyro:38'                 '', ... */
    /* 'soMPU6050Gyro:39'                 'DLPFmode'); */
    /* 'soMPU6050Gyro:40' obj.DLPFmode = value; */
    group_10_Simulink_DWork.obj_gi.isInitialized = 1L;

    /* 'soMPU6050Gyro:46' if coder.target('Rtw') */
    /*  done only for code gen */
    /* 'soMPU6050Gyro:47' coder.cinclude('MPU6050wrapper.h'); */
    /*  initialize the sensor */
    /*                  coder.ceval('MPU6050Accel_Init'); */
    /* 'soMPU6050Gyro:51' coder.ceval('MPU6050Gyro_Init', obj.DLPFmode); */
    MPU6050Gyro_Init(0.0);
    group_10_Simulink_DWork.obj_gi.isSetupComplete = true;

    /* Start for MATLABSystem: '<S54>/Digital Output1' */
    group_10_Simulink_DWork.obj_o.matlabCodegenIsDeleted = false;
    group_10_Simulink_DWork.obj_o.isInitialized = 1L;
    digitalIOSetup(8, 1);
    group_10_Simulink_DWork.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S54>/PWM' */
    group_10_Simulink_DWork.obj_ot.matlabCodegenIsDeleted = false;
    obj = &group_10_Simulink_DWork.obj_ot;
    group_10_Simulink_DWork.obj_ot.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
    group_10_Simulink_DWork.obj_ot.isSetupComplete = true;

    /* InitializeConditions for UnitDelay: '<S6>/UD'
     *
     * Block description for '<S6>/UD':
     *
     *  Store in Global RAM
     */
    group_10_Simulink_DWork.UD_DSTATE =
      group_10_Simulink_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time  Integrator (convert from theta_b_dot to theta_b)' */
    group_10_Simulink_DWork.DiscreteTimeIntegratorconvertfr =
      group_10_Simulink_P.DiscreteTimeIntegratorconvert_o;

    /* InitializeConditions for UnitDelay: '<S7>/UD'
     *
     * Block description for '<S7>/UD':
     *
     *  Store in Global RAM
     */
    group_10_Simulink_DWork.UD_DSTATE_o =
      group_10_Simulink_P.DiscreteDerivative_ICPrevScal_g;
  }
}

/* Model terminate function */
void group_10_Simulink_terminate(void)
{
  codertarget_arduinobase_inter_a *obj;

  /* Terminate for MATLABSystem: '<S4>/Encoder' */
  if (!group_10_Simulink_DWork.obj_g.matlabCodegenIsDeleted) {
    group_10_Simulink_DWork.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Encoder' */

  /* Terminate for MATLABSystem: '<S10>/Serial Transmit' */
  if (!group_10_Simulink_DWork.obj.matlabCodegenIsDeleted) {
    group_10_Simulink_DWork.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S10>/Serial Transmit' */

  /* Terminate for MATLABSystem: '<S4>/Gyroscope' */
  if (!group_10_Simulink_DWork.obj_gi.matlabCodegenIsDeleted) {
    group_10_Simulink_DWork.obj_gi.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Gyroscope' */

  /* Terminate for MATLABSystem: '<S54>/Digital Output1' */
  if (!group_10_Simulink_DWork.obj_o.matlabCodegenIsDeleted) {
    group_10_Simulink_DWork.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S54>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S54>/PWM' */
  obj = &group_10_Simulink_DWork.obj_ot;
  if (!group_10_Simulink_DWork.obj_ot.matlabCodegenIsDeleted) {
    group_10_Simulink_DWork.obj_ot.matlabCodegenIsDeleted = true;
    if ((group_10_Simulink_DWork.obj_ot.isInitialized == 1L) &&
        group_10_Simulink_DWork.obj_ot.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle
        (group_10_Simulink_DWork.obj_ot.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(group_10_Simulink_DWork.obj_ot.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S54>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
