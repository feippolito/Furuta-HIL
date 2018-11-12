/*
 * Furuta_Model.c
 *
 * Code generation for model "Furuta_Model".
 *
 * Model version              : 1.59
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Nov 06 13:55:40 2018
 *
 * Target selection: rti1006.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Furuta_Model_trc_ptr.h"
#include "Furuta_Model.h"
#include "Furuta_Model_private.h"

/* Block signals (auto storage) */
B_Furuta_Model_T Furuta_Model_B;

/* Continuous states */
X_Furuta_Model_T Furuta_Model_X;

/* Block states (auto storage) */
DW_Furuta_Model_T Furuta_Model_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Furuta_Model_T Furuta_Model_PrevZCX;

/* Real-time model */
RT_MODEL_Furuta_Model_T Furuta_Model_M_;
RT_MODEL_Furuta_Model_T *const Furuta_Model_M = &Furuta_Model_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Furuta_Model_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Furuta_Model_output();
  Furuta_Model_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Furuta_Model_output();
  Furuta_Model_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

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

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  boolean_T y_0;
  boolean_T y_1;
  if (u1 == 0.0) {
    y = u0;
  } else {
    y_0 = ((!rtIsNaN(u0)) && (!rtIsInf(u0)));
    y_1 = ((!rtIsNaN(u1)) && (!rtIsInf(u1)));
    if (!(y_0 && y_1)) {
      y = (rtNaN);
    } else {
      tmp = u0 / u1;
      if (u1 <= floor(u1)) {
        y = u0 - floor(tmp) * u1;
      } else if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
        y = 0.0;
      } else {
        y = (tmp - floor(tmp)) * u1;
      }
    }
  }

  return y;
}

/* Model output function */
void Furuta_Model_output(void)
{
  uint32_T delayLen;
  real_T B;
  boolean_T zcEvent;
  boolean_T zcEvent_0;
  real_T u;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* set solver stop time */
    if (!(Furuta_Model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Furuta_Model_M->solverInfo,
                            ((Furuta_Model_M->Timing.clockTickH0 + 1) *
        Furuta_Model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Furuta_Model_M->solverInfo,
                            ((Furuta_Model_M->Timing.clockTick0 + 1) *
        Furuta_Model_M->Timing.stepSize0 + Furuta_Model_M->Timing.clockTickH0 *
        Furuta_Model_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Furuta_Model_M)) {
    Furuta_Model_M->Timing.t[0] = rtsiGetT(&Furuta_Model_M->solverInfo);
  }

  /* Integrator: '<S10>/Phi' */
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&Furuta_Model_PrevZCX.Phi_Reset_ZCE,
                       Furuta_Model_P.Control_Value);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Furuta_Model_X.Phi_CSTATE = Furuta_Model_P.Phi_IC;
    }
  }

  Furuta_Model_B.Phi = Furuta_Model_X.Phi_CSTATE;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  Furuta_Model_B.Sum2 = Furuta_Model_B.Phi + Furuta_Model_P.Constant3_Value;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* Gain: '<Root>/Gain4' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Furuta_Model_B.Gain4 = Furuta_Model_P.Gain4_Gain *
      Furuta_Model_P.Constant3_Value;
  }

  /* Product: '<Root>/Divide' */
  Furuta_Model_B.Divide = Furuta_Model_B.Sum2 / Furuta_Model_B.Gain4;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* S-Function (rti_commonblock): '<S6>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:PWM */
    ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH1, (Float32)
                   Furuta_Model_P.Constant10_Value, (Float32)
                   Furuta_Model_B.Divide);
  }

  /* Integrator: '<S10>/dPhi' */
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&Furuta_Model_PrevZCX.dPhi_Reset_ZCE,
                       Furuta_Model_P.Control_Value);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Furuta_Model_X.dPhi_CSTATE = Furuta_Model_P.dPhi_IC;
    }
  }

  Furuta_Model_B.dPhi = Furuta_Model_X.dPhi_CSTATE;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  Furuta_Model_B.Sum3 = Furuta_Model_B.dPhi + Furuta_Model_P.Constant7_Value;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* Gain: '<Root>/Gain5' incorporates:
     *  Constant: '<Root>/Constant7'
     */
    Furuta_Model_B.Gain5 = Furuta_Model_P.Gain5_Gain *
      Furuta_Model_P.Constant7_Value;
  }

  /* Product: '<Root>/Divide1' */
  Furuta_Model_B.Divide1 = Furuta_Model_B.Sum3 / Furuta_Model_B.Gain5;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* S-Function (rti_commonblock): '<S7>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:PWM */
    ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH2, (Float32)
                   Furuta_Model_P.Constant10_Value, (Float32)
                   Furuta_Model_B.Divide1);
  }

  /* Integrator: '<S10>/Theta' */
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &Furuta_Model_PrevZCX.Theta_Reset_ZCE,
                       Furuta_Model_P.Control_Value);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Furuta_Model_X.Theta_CSTATE = Furuta_Model_P.initial_state;
    }
  }

  Furuta_Model_B.Theta = Furuta_Model_X.Theta_CSTATE;

  /* Sum: '<Root>/Sum6' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  Furuta_Model_B.Sum6 = Furuta_Model_B.Theta + Furuta_Model_P.Constant8_Value;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* Gain: '<Root>/Gain6' incorporates:
     *  Constant: '<Root>/Constant8'
     */
    Furuta_Model_B.Gain6 = Furuta_Model_P.Gain6_Gain *
      Furuta_Model_P.Constant8_Value;
  }

  /* Product: '<Root>/Divide2' */
  Furuta_Model_B.Divide2 = Furuta_Model_B.Sum6 / Furuta_Model_B.Gain6;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* S-Function (rti_commonblock): '<S8>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:PWM */
    ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH3, (Float32)
                   Furuta_Model_P.Constant10_Value, (Float32)
                   Furuta_Model_B.Divide2);
  }

  /* Integrator: '<S10>/dTheta' */
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &Furuta_Model_PrevZCX.dTheta_Reset_ZCE,
                       Furuta_Model_P.Control_Value);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Furuta_Model_X.dTheta_CSTATE = Furuta_Model_P.dTheta_IC;
    }
  }

  Furuta_Model_B.dTheta = Furuta_Model_X.dTheta_CSTATE;

  /* Sum: '<Root>/Sum7' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  Furuta_Model_B.Sum7 = Furuta_Model_B.dTheta + Furuta_Model_P.Constant9_Value;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* Gain: '<Root>/Gain7' incorporates:
     *  Constant: '<Root>/Constant9'
     */
    Furuta_Model_B.Gain7 = Furuta_Model_P.Gain7_Gain *
      Furuta_Model_P.Constant9_Value;
  }

  /* Product: '<Root>/Divide3' */
  Furuta_Model_B.Divide3 = Furuta_Model_B.Sum7 / Furuta_Model_B.Gain7;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* S-Function (rti_commonblock): '<S9>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:PWM */
    ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH4, (Float32)
                   Furuta_Model_P.Constant10_Value, (Float32)
                   Furuta_Model_B.Divide3);

    /* S-Function (rti_commonblock): '<S2>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Logic: '<Root>/Logical Operator' */
    Furuta_Model_B.LogicalOperator = !Furuta_Model_B.SFunction1;

    /* Gain: '<Root>/Gain1' incorporates:
     *  Constant: '<Root>/Delay Lenght'
     */
    Furuta_Model_B.Gain1 = Furuta_Model_P.Gain1_Gain *
      Furuta_Model_P.DelayLenght_Value;

    /* Delay: '<Root>/Delay2' */
    if ((Furuta_Model_B.Gain1 < 1.0) || rtIsNaN(Furuta_Model_B.Gain1)) {
      Furuta_Model_B.Delay2 = Furuta_Model_B.LogicalOperator;
    } else {
      if (Furuta_Model_B.Gain1 > 100000.0) {
        delayLen = 100000U;
      } else {
        u = Furuta_Model_B.Gain1;
        if (u < 0.0) {
          u = ceil(u);
        } else {
          u = floor(u);
        }

        if (rtIsNaN(u) || rtIsInf(u)) {
          u = 0.0;
        } else {
          u = fmod(u, 4.294967296E+9);
        }

        delayLen = u < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-u : (uint32_T)u;
      }

      delayLen = 100000U - delayLen;
      Furuta_Model_B.Delay2 = Furuta_Model_DW.Delay2_DSTATE[delayLen];
    }

    /* End of Delay: '<Root>/Delay2' */

    /* Memory: '<S1>/TmpLatchAtD Flip-FlopInport1' */
    Furuta_Model_B.TmpLatchAtDFlipFlopInport1 =
      Furuta_Model_DW.TmpLatchAtDFlipFlopInport1_Prev;

    /* Outputs for Enabled and Triggered SubSystem: '<S1>/D Flip-Flop' incorporates:
     *  EnablePort: '<S14>/C'
     *  TriggerPort: '<S14>/Trigger'
     */
    zcEvent = (Furuta_Model_B.SFunction1 &&
               (Furuta_Model_PrevZCX.DFlipFlop_Trig_ZCE != POS_ZCSIG));
    zcEvent_0 = ((int32_T)NO_ZCEVENT != 0);
    if (rtmIsMajorTimeStep(Furuta_Model_M)) {
      zcEvent_0 = zcEvent;
    }

    if (Furuta_Model_B.Delay2) {
      if (!Furuta_Model_DW.DFlipFlop_MODE) {
        Furuta_Model_DW.DFlipFlop_MODE = true;
      }

      if (rtmIsMajorTimeStep(Furuta_Model_M)) {
        if (zcEvent_0) {
          /* Inport: '<S14>/D' */
          Furuta_Model_B.D = Furuta_Model_B.TmpLatchAtDFlipFlopInport1;

          /* Logic: '<S14>/Logic' */
          Furuta_Model_B.Logic = !Furuta_Model_B.D;
        }

        Furuta_Model_PrevZCX.DFlipFlop_Trig_ZCE = Furuta_Model_B.SFunction1;
      }

      Furuta_Model_PrevZCX.DFlipFlop_Trig_ZCE = Furuta_Model_B.SFunction1;
    } else {
      if (Furuta_Model_DW.DFlipFlop_MODE) {
        /* Disable for Outport: '<S14>/Q' */
        Furuta_Model_B.D = Furuta_Model_P.Q_Y0;

        /* Disable for Outport: '<S14>/!Q' */
        Furuta_Model_B.Logic = Furuta_Model_P.Q_Y0_j;
        Furuta_Model_DW.DFlipFlop_MODE = false;
      }

      Furuta_Model_PrevZCX.DFlipFlop_Trig_ZCE = Furuta_Model_B.SFunction1;
    }

    /* End of Outputs for SubSystem: '<S1>/D Flip-Flop' */

    /* S-Function (rti_commonblock): '<S4>/S-Function1' */
    /* This comment workarounds a code generation problem */
  }

  /* Gain: '<S10>/Gain3' */
  Furuta_Model_B.Gain3 = Furuta_Model_P.kb * Furuta_Model_B.dPhi;

  /* Gain: '<S10>/Gain1' */
  u = Furuta_Model_P.ke * Furuta_Model_P.ke;
  B = Furuta_Model_P.Re;
  u /= B;
  Furuta_Model_B.Gain1_n = u * Furuta_Model_B.dPhi;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Constant: '<Root>/Control'
     */
    if (Furuta_Model_P.Control_Value > Furuta_Model_P.Switch_Threshold) {
      /* Gain: '<Root>/Gain3' */
      Furuta_Model_B.Gain3_n = Furuta_Model_P.Gain3_Gain *
        Furuta_Model_B.SFunction1_o1;

      /* Sum: '<Root>/Sum' incorporates:
       *  Constant: '<Root>/Constant1'
       */
      Furuta_Model_B.Sum_d = Furuta_Model_B.Gain3_n -
        Furuta_Model_P.Constant1_Value;
      Furuta_Model_B.Switch = Furuta_Model_B.Sum_d;
    } else {
      Furuta_Model_B.Switch = Furuta_Model_P.Constant5_Value;
    }

    /* End of Switch: '<Root>/Switch' */

    /* Gain: '<S10>/ke//Re ' */
    u = Furuta_Model_P.ke;
    B = Furuta_Model_P.Re;
    u /= B;
    Furuta_Model_B.keRe = u * Furuta_Model_B.Switch;
  }

  /* Sum: '<S10>/Sum' */
  Furuta_Model_B.Sum = (Furuta_Model_B.keRe - Furuta_Model_B.Gain3) -
    Furuta_Model_B.Gain1_n;

  /* Gain: '<S10>/Gain2' */
  u = -Furuta_Model_P.kb;
  Furuta_Model_B.Gain2 = u * Furuta_Model_B.dTheta;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* Gain: '<Root>/Gain2' */
    Furuta_Model_B.Gain2_n = Furuta_Model_P.Gain2_Gain * (real_T)
      Furuta_Model_B.D;

    /* Gain: '<Root>/Gain9' */
    Furuta_Model_B.Gain9 = Furuta_Model_P.Gain9_Gain * Furuta_Model_B.Gain2_n;
  }

  /* Sum: '<S10>/Sum1' */
  Furuta_Model_B.Sum1 = Furuta_Model_B.Gain2 + Furuta_Model_B.Gain9;

  /* Fcn: '<S10>/DenPhi' */
  Furuta_Model_B.DenPhi = 4.5751333497447378E-6 * sin(Furuta_Model_B.Theta) *
    sin(Furuta_Model_B.Theta) + 3.3064861549094487E-6;

  /* Fcn: '<S10>/DenTheta' */
  Furuta_Model_B.DenTheta = 4.5751333497447378E-6 * sin(Furuta_Model_B.Theta) *
    sin(Furuta_Model_B.Theta) + 3.3064861549094487E-6;

  /* Fcn: '<S10>/NumPhi' */
  Furuta_Model_B.NumPhi = (((((sin(Furuta_Model_B.Theta) * sin
    (Furuta_Model_B.Theta) - 1.0) * 1.7859360934711321E-6 * sin
    (Furuta_Model_B.Theta) * Furuta_Model_B.dPhi * Furuta_Model_B.dPhi -
    7.434079702528363E-6 * cos(Furuta_Model_B.Theta) * sin(Furuta_Model_B.Theta)
    * Furuta_Model_B.dPhi * Furuta_Model_B.dTheta) + 1.7859360934711321E-6 * sin
    (Furuta_Model_B.Theta) * Furuta_Model_B.dTheta * Furuta_Model_B.dTheta) -
    8.8099395291410347E-5 * cos(Furuta_Model_B.Theta) * sin(Furuta_Model_B.Theta))
    + 0.001927962616666667 * Furuta_Model_B.Sum) - 0.0009263333625 * cos
    (Furuta_Model_B.Theta) * Furuta_Model_B.Sum1;

  /* Product: '<S10>/Divide' */
  Furuta_Model_B.Divide_e = Furuta_Model_B.NumPhi / Furuta_Model_B.DenPhi;

  /* Fcn: '<S10>/NumTheta' */
  Furuta_Model_B.NumTheta = (((((0.001927962616666667 * sin(Furuta_Model_B.Theta)
    * sin(Furuta_Model_B.Theta) + 0.002160093571) * 0.001927962616666667 * cos
    (Furuta_Model_B.Theta) * sin(Furuta_Model_B.Theta) * Furuta_Model_B.dPhi *
    Furuta_Model_B.dPhi + (1.0 - sin(Furuta_Model_B.Theta) * sin
    (Furuta_Model_B.Theta)) * 3.5718721869422642E-6 * sin(Furuta_Model_B.Theta) *
    Furuta_Model_B.dPhi * Furuta_Model_B.dTheta) - 8.5809349848055632E-7 * cos
    (Furuta_Model_B.Theta) * sin(Furuta_Model_B.Theta) * Furuta_Model_B.dTheta *
    Furuta_Model_B.dTheta) + (0.001927962616666667 * sin(Furuta_Model_B.Theta) *
    sin(Furuta_Model_B.Theta) + 0.002160093571) * 0.095105497500000011 * sin
    (Furuta_Model_B.Theta)) - 0.0009263333625 * cos(Furuta_Model_B.Theta) *
    Furuta_Model_B.Sum) + (0.001927962616666667 * sin(Furuta_Model_B.Theta) *
    sin(Furuta_Model_B.Theta) + 0.002160093571) * Furuta_Model_B.Sum1;

  /* Product: '<S10>/Divide1' */
  Furuta_Model_B.Divide1_a = Furuta_Model_B.NumTheta / Furuta_Model_B.DenTheta;

  /* Math: '<S18>/Math Function' incorporates:
   *  Constant: '<S18>/2pi'
   */
  Furuta_Model_B.MathFunction = rt_modd_snf(Furuta_Model_B.Phi,
    Furuta_Model_P.pi_Value);

  /* Gain: '<Root>/Phi' */
  Furuta_Model_B.Phi_h = Furuta_Model_P.Phi_Gain * Furuta_Model_B.MathFunction;

  /* Sum: '<S19>/Add' incorporates:
   *  Constant: '<S19>/Constant'
   */
  Furuta_Model_B.Add = Furuta_Model_B.Theta + Furuta_Model_P.Constant_Value;

  /* Math: '<S19>/Math Function' incorporates:
   *  Constant: '<S19>/2pi'
   */
  Furuta_Model_B.MathFunction_h = rt_modd_snf(Furuta_Model_B.Add,
    Furuta_Model_P.pi_Value_m);

  /* Gain: '<Root>/Theta' */
  Furuta_Model_B.Theta_h = Furuta_Model_P.Theta_Gain *
    Furuta_Model_B.MathFunction_h;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* S-Function (rti_commonblock): '<S5>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<Root>/Gain8' */
    Furuta_Model_B.Gain8 = Furuta_Model_P.Gain8_Gain *
      Furuta_Model_B.SFunction1_o1_f;

    /* Sum: '<Root>/Sum8' incorporates:
     *  Constant: '<Root>/Constant11'
     */
    Furuta_Model_B.Sum8 = Furuta_Model_B.Gain8 - Furuta_Model_P.Constant11_Value;

    /* S-Function (rti_commonblock): '<S3>/S-Function1' */
    /* This comment workarounds a code generation problem */
  }
}

/* Model update function */
void Furuta_Model_update(void)
{
  int_T idxDelay;
  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    /* Update for Delay: '<Root>/Delay2' */
    for (idxDelay = 0; idxDelay < 99999; idxDelay++) {
      Furuta_Model_DW.Delay2_DSTATE[idxDelay] =
        Furuta_Model_DW.Delay2_DSTATE[idxDelay + 1];
    }

    Furuta_Model_DW.Delay2_DSTATE[99999] = Furuta_Model_B.LogicalOperator;

    /* End of Update for Delay: '<Root>/Delay2' */

    /* Update for Memory: '<S1>/TmpLatchAtD Flip-FlopInport1' incorporates:
     *  Constant: '<Root>/Constant12'
     */
    Furuta_Model_DW.TmpLatchAtDFlipFlopInport1_Prev =
      Furuta_Model_P.Constant12_Value;
  }

  if (rtmIsMajorTimeStep(Furuta_Model_M)) {
    rt_ertODEUpdateContinuousStates(&Furuta_Model_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Furuta_Model_M->Timing.clockTick0)) {
    ++Furuta_Model_M->Timing.clockTickH0;
  }

  Furuta_Model_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Furuta_Model_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Furuta_Model_M->Timing.clockTick1)) {
      ++Furuta_Model_M->Timing.clockTickH1;
    }

    Furuta_Model_M->Timing.t[1] = Furuta_Model_M->Timing.clockTick1 *
      Furuta_Model_M->Timing.stepSize1 + Furuta_Model_M->Timing.clockTickH1 *
      Furuta_Model_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Furuta_Model_derivatives(void)
{
  /* Derivatives for Integrator: '<S10>/Phi' */
  {
    ((XDot_Furuta_Model_T *) Furuta_Model_M->ModelData.derivs)->Phi_CSTATE =
      Furuta_Model_B.dPhi;
  }

  /* Derivatives for Integrator: '<S10>/dPhi' */
  {
    ((XDot_Furuta_Model_T *) Furuta_Model_M->ModelData.derivs)->dPhi_CSTATE =
      Furuta_Model_B.Divide_e;
  }

  /* Derivatives for Integrator: '<S10>/Theta' */
  {
    ((XDot_Furuta_Model_T *) Furuta_Model_M->ModelData.derivs)->Theta_CSTATE =
      Furuta_Model_B.dTheta;
  }

  /* Derivatives for Integrator: '<S10>/dTheta' */
  {
    ((XDot_Furuta_Model_T *) Furuta_Model_M->ModelData.derivs)->dTheta_CSTATE =
      Furuta_Model_B.Divide1_a;
  }
}

/* Model initialize function */
void Furuta_Model_initialize(void)
{
  /* Start for Enabled and Triggered SubSystem: '<S1>/D Flip-Flop' */
  /* VirtualOutportStart for Outport: '<S14>/Q' */
  Furuta_Model_B.D = Furuta_Model_P.Q_Y0;

  /* VirtualOutportStart for Outport: '<S14>/!Q' */
  Furuta_Model_B.Logic = Furuta_Model_P.Q_Y0_j;

  /* End of Start for SubSystem: '<S1>/D Flip-Flop' */
  Furuta_Model_PrevZCX.Phi_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Furuta_Model_PrevZCX.dPhi_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Furuta_Model_PrevZCX.Theta_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Furuta_Model_PrevZCX.dTheta_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Furuta_Model_PrevZCX.DFlipFlop_Trig_ZCE = POS_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S10>/Phi' */
    Furuta_Model_X.Phi_CSTATE = Furuta_Model_P.Phi_IC;

    /* InitializeConditions for Integrator: '<S10>/dPhi' */
    Furuta_Model_X.dPhi_CSTATE = Furuta_Model_P.dPhi_IC;

    /* InitializeConditions for Integrator: '<S10>/Theta' */
    Furuta_Model_X.Theta_CSTATE = Furuta_Model_P.initial_state;

    /* InitializeConditions for Integrator: '<S10>/dTheta' */
    Furuta_Model_X.dTheta_CSTATE = Furuta_Model_P.dTheta_IC;

    /* InitializeConditions for Delay: '<Root>/Delay2' */
    for (i = 0; i < 100000; i++) {
      Furuta_Model_DW.Delay2_DSTATE[i] = Furuta_Model_P.Delay2_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay2' */

    /* InitializeConditions for Memory: '<S1>/TmpLatchAtD Flip-FlopInport1' */
    Furuta_Model_DW.TmpLatchAtDFlipFlopInport1_Prev =
      Furuta_Model_P.TmpLatchAtDFlipFlopInport1_X0;
  }
}

/* Model terminate function */
void Furuta_Model_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S3>/S-Function1' */

  /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:SETUP */
  ds2202_digout_mode_set(DS2202_1_BASE, DS2202_DIGOUT_DISABLE);
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Furuta_Model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Furuta_Model_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Furuta_Model_initialize();
}

void MdlTerminate(void)
{
  Furuta_Model_terminate();
}

/* Registration function */
RT_MODEL_Furuta_Model_T *Furuta_Model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Furuta_Model_M, 0,
                sizeof(RT_MODEL_Furuta_Model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Furuta_Model_M->solverInfo,
                          &Furuta_Model_M->Timing.simTimeStep);
    rtsiSetTPtr(&Furuta_Model_M->solverInfo, &rtmGetTPtr(Furuta_Model_M));
    rtsiSetStepSizePtr(&Furuta_Model_M->solverInfo,
                       &Furuta_Model_M->Timing.stepSize0);
    rtsiSetdXPtr(&Furuta_Model_M->solverInfo, &Furuta_Model_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Furuta_Model_M->solverInfo, (real_T **)
                         &Furuta_Model_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Furuta_Model_M->solverInfo,
      &Furuta_Model_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Furuta_Model_M->solverInfo, (&rtmGetErrorStatus
      (Furuta_Model_M)));
    rtsiSetRTModelPtr(&Furuta_Model_M->solverInfo, Furuta_Model_M);
  }

  rtsiSetSimTimeStep(&Furuta_Model_M->solverInfo, MAJOR_TIME_STEP);
  Furuta_Model_M->ModelData.intgData.y = Furuta_Model_M->ModelData.odeY;
  Furuta_Model_M->ModelData.intgData.f[0] = Furuta_Model_M->ModelData.odeF[0];
  Furuta_Model_M->ModelData.intgData.f[1] = Furuta_Model_M->ModelData.odeF[1];
  Furuta_Model_M->ModelData.intgData.f[2] = Furuta_Model_M->ModelData.odeF[2];
  Furuta_Model_M->ModelData.contStates = ((real_T *) &Furuta_Model_X);
  rtsiSetSolverData(&Furuta_Model_M->solverInfo, (void *)
                    &Furuta_Model_M->ModelData.intgData);
  rtsiSetSolverName(&Furuta_Model_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Furuta_Model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Furuta_Model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Furuta_Model_M->Timing.sampleTimes =
      (&Furuta_Model_M->Timing.sampleTimesArray[0]);
    Furuta_Model_M->Timing.offsetTimes =
      (&Furuta_Model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Furuta_Model_M->Timing.sampleTimes[0] = (0.0);
    Furuta_Model_M->Timing.sampleTimes[1] = (0.0001);

    /* task offsets */
    Furuta_Model_M->Timing.offsetTimes[0] = (0.0);
    Furuta_Model_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Furuta_Model_M, &Furuta_Model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Furuta_Model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Furuta_Model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Furuta_Model_M, -1);
  Furuta_Model_M->Timing.stepSize0 = 0.0001;
  Furuta_Model_M->Timing.stepSize1 = 0.0001;
  Furuta_Model_M->solverInfoPtr = (&Furuta_Model_M->solverInfo);
  Furuta_Model_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&Furuta_Model_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&Furuta_Model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Furuta_Model_M->ModelData.blockIO = ((void *) &Furuta_Model_B);
  (void) memset(((void *) &Furuta_Model_B), 0,
                sizeof(B_Furuta_Model_T));

  /* parameters */
  Furuta_Model_M->ModelData.defaultParam = ((real_T *)&Furuta_Model_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Furuta_Model_X;
    Furuta_Model_M->ModelData.contStates = (x);
    (void) memset((void *)&Furuta_Model_X, 0,
                  sizeof(X_Furuta_Model_T));
  }

  /* states (dwork) */
  Furuta_Model_M->ModelData.dwork = ((void *) &Furuta_Model_DW);
  (void) memset((void *)&Furuta_Model_DW, 0,
                sizeof(DW_Furuta_Model_T));

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  /* Initialize Sizes */
  Furuta_Model_M->Sizes.numContStates = (4);/* Number of continuous states */
  Furuta_Model_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Furuta_Model_M->Sizes.numY = (0);    /* Number of model outputs */
  Furuta_Model_M->Sizes.numU = (0);    /* Number of model inputs */
  Furuta_Model_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Furuta_Model_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Furuta_Model_M->Sizes.numBlocks = (72);/* Number of blocks */
  Furuta_Model_M->Sizes.numBlockIO = (51);/* Number of block outputs */
  Furuta_Model_M->Sizes.numBlockPrms = (37);/* Sum of parameter "widths" */
  return Furuta_Model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
