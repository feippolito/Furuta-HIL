/*
 * pwm_teste.c
 *
 * Code generation for model "pwm_teste".
 *
 * Model version              : 1.31
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Oct 26 21:59:51 2018
 *
 * Target selection: rti1006.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pwm_teste_trc_ptr.h"
#include "pwm_teste.h"
#include "pwm_teste_private.h"

/* Block signals (auto storage) */
B_pwm_teste_T pwm_teste_B;

/* Real-time model */
RT_MODEL_pwm_teste_T pwm_teste_M_;
RT_MODEL_pwm_teste_T *const pwm_teste_M = &pwm_teste_M_;

/* Model output function */
static void pwm_teste_output(void)
{
  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Phi'
   */
  pwm_teste_B.Sum2 = pwm_teste_P.Phi_Value + pwm_teste_P.Constant3_Value;

  /* Gain: '<Root>/Gain4' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  pwm_teste_B.Gain4 = pwm_teste_P.Gain4_Gain * pwm_teste_P.Constant3_Value;

  /* Product: '<Root>/Divide' */
  pwm_teste_B.Divide = pwm_teste_B.Sum2 / pwm_teste_B.Gain4;

  /* S-Function (rti_commonblock): '<S3>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:PWM */
  ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH1, (Float32)
                 pwm_teste_P.Constant_Value, (Float32) pwm_teste_B.Divide);

  /* Sum: '<Root>/Sum3' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Constant: '<Root>/dPhi'
   */
  pwm_teste_B.Sum3 = pwm_teste_P.dPhi_Value + pwm_teste_P.Constant7_Value;

  /* Gain: '<Root>/Gain5' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  pwm_teste_B.Gain5 = pwm_teste_P.Gain5_Gain * pwm_teste_P.Constant7_Value;

  /* Product: '<Root>/Divide1' */
  pwm_teste_B.Divide1 = pwm_teste_B.Sum3 / pwm_teste_B.Gain5;

  /* S-Function (rti_commonblock): '<S4>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:PWM */
  ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH2, (Float32)
                 pwm_teste_P.Constant_Value, (Float32) pwm_teste_B.Divide1);

  /* Sum: '<Root>/Sum6' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Constant: '<Root>/Theta'
   */
  pwm_teste_B.Sum6 = pwm_teste_P.Theta_Value + pwm_teste_P.Constant8_Value;

  /* Gain: '<Root>/Gain6' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  pwm_teste_B.Gain6 = pwm_teste_P.Gain6_Gain * pwm_teste_P.Constant8_Value;

  /* Product: '<Root>/Divide2' */
  pwm_teste_B.Divide2 = pwm_teste_B.Sum6 / pwm_teste_B.Gain6;

  /* S-Function (rti_commonblock): '<S5>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:PWM */
  ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH3, (Float32)
                 pwm_teste_P.Constant_Value, (Float32) pwm_teste_B.Divide2);

  /* Sum: '<Root>/Sum7' incorporates:
   *  Constant: '<Root>/Constant9'
   *  Constant: '<Root>/dTheta'
   */
  pwm_teste_B.Sum7 = pwm_teste_P.dTheta_Value + pwm_teste_P.Constant9_Value;

  /* Gain: '<Root>/Gain7' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  pwm_teste_B.Gain7 = pwm_teste_P.Gain7_Gain * pwm_teste_P.Constant9_Value;

  /* Product: '<Root>/Divide3' */
  pwm_teste_B.Divide3 = pwm_teste_B.Sum7 / pwm_teste_B.Gain7;

  /* S-Function (rti_commonblock): '<S6>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:PWM */
  ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH4, (Float32)
                 pwm_teste_P.Constant_Value, (Float32) pwm_teste_B.Divide3);

  /* S-Function (rti_commonblock): '<S2>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<Root>/Gain3' */
  pwm_teste_B.Gain3 = pwm_teste_P.Gain3_Gain * pwm_teste_B.SFunction1_o1;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  pwm_teste_B.Sum = pwm_teste_B.Gain3 - pwm_teste_P.Constant1_Value;

  /* S-Function (rti_commonblock): '<S1>/S-Function1' */
  /* This comment workarounds a code generation problem */
}

/* Model update function */
static void pwm_teste_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++pwm_teste_M->Timing.clockTick0)) {
    ++pwm_teste_M->Timing.clockTickH0;
  }

  pwm_teste_M->Timing.t[0] = pwm_teste_M->Timing.clockTick0 *
    pwm_teste_M->Timing.stepSize0 + pwm_teste_M->Timing.clockTickH0 *
    pwm_teste_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void pwm_teste_initialize(void)
{
}

/* Model terminate function */
static void pwm_teste_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S1>/S-Function1' */

  /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:SETUP */
  ds2202_digout_mode_set(DS2202_1_BASE, DS2202_DIGOUT_DISABLE);
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  pwm_teste_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  pwm_teste_update();
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
  pwm_teste_initialize();
}

void MdlTerminate(void)
{
  pwm_teste_terminate();
}

/* Registration function */
RT_MODEL_pwm_teste_T *pwm_teste(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)pwm_teste_M, 0,
                sizeof(RT_MODEL_pwm_teste_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = pwm_teste_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    pwm_teste_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    pwm_teste_M->Timing.sampleTimes = (&pwm_teste_M->Timing.sampleTimesArray[0]);
    pwm_teste_M->Timing.offsetTimes = (&pwm_teste_M->Timing.offsetTimesArray[0]);

    /* task periods */
    pwm_teste_M->Timing.sampleTimes[0] = (0.0001);

    /* task offsets */
    pwm_teste_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(pwm_teste_M, &pwm_teste_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = pwm_teste_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    pwm_teste_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(pwm_teste_M, -1);
  pwm_teste_M->Timing.stepSize0 = 0.0001;
  pwm_teste_M->solverInfoPtr = (&pwm_teste_M->solverInfo);
  pwm_teste_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&pwm_teste_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&pwm_teste_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  pwm_teste_M->ModelData.blockIO = ((void *) &pwm_teste_B);
  (void) memset(((void *) &pwm_teste_B), 0,
                sizeof(B_pwm_teste_T));

  /* parameters */
  pwm_teste_M->ModelData.defaultParam = ((real_T *)&pwm_teste_P);

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  /* Initialize Sizes */
  pwm_teste_M->Sizes.numContStates = (0);/* Number of continuous states */
  pwm_teste_M->Sizes.numY = (0);       /* Number of model outputs */
  pwm_teste_M->Sizes.numU = (0);       /* Number of model inputs */
  pwm_teste_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  pwm_teste_M->Sizes.numSampTimes = (1);/* Number of sample times */
  pwm_teste_M->Sizes.numBlocks = (30); /* Number of blocks */
  pwm_teste_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  pwm_teste_M->Sizes.numBlockPrms = (15);/* Sum of parameter "widths" */
  return pwm_teste_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
