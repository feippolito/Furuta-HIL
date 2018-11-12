/*
 * ADCteste.c
 *
 * Code generation for model "ADCteste".
 *
 * Model version              : 1.13
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Oct 30 21:53:03 2018
 *
 * Target selection: rti1006.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADCteste_trc_ptr.h"
#include "ADCteste.h"
#include "ADCteste_private.h"

/* Block signals (auto storage) */
B_ADCteste_T ADCteste_B;

/* Real-time model */
RT_MODEL_ADCteste_T ADCteste_M_;
RT_MODEL_ADCteste_T *const ADCteste_M = &ADCteste_M_;

/* Model output function */
static void ADCteste_output(void)
{
  /* S-Function (rti_commonblock): '<S1>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS2202 #1 Unit:DAC */
  ds2202_dac_out(DS2202_1_BASE, DS2202_DAC_CH1, (Float32)
                 ADCteste_P.Constant_Value);

  /* S-Function (rti_commonblock): '<S2>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS2202 #1 Unit:DAC */
  ds2202_dac_out(DS2202_1_BASE, DS2202_DAC_CH2, (Float32)
                 ADCteste_P.Constant1_Value);

  /* S-Function (rti_commonblock): '<S3>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS2202 #1 Unit:DAC */
  ds2202_dac_out(DS2202_1_BASE, DS2202_DAC_CH3, (Float32)
                 ADCteste_P.Constant2_Value);

  /* S-Function (rti_commonblock): '<S4>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS2202 #1 Unit:DAC */
  ds2202_dac_out(DS2202_1_BASE, DS2202_DAC_CH4, (Float32)
                 ADCteste_P.Constant3_Value);

  /* S-Function (rti_commonblock): '<S6>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S5>/S-Function1' */
  /* This comment workarounds a code generation problem */
}

/* Model update function */
static void ADCteste_update(void)
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
  if (!(++ADCteste_M->Timing.clockTick0)) {
    ++ADCteste_M->Timing.clockTickH0;
  }

  ADCteste_M->Timing.t[0] = ADCteste_M->Timing.clockTick0 *
    ADCteste_M->Timing.stepSize0 + ADCteste_M->Timing.clockTickH0 *
    ADCteste_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void ADCteste_initialize(void)
{
}

/* Model terminate function */
static void ADCteste_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S1>/S-Function1' */

  /* dSPACE I/O Board DS2202 #1 Unit:DAC */
  ds2202_dac_out(DS2202_1_BASE, DS2202_DAC_CH1, (Float32) (0/100.0));

  /* Terminate for S-Function (rti_commonblock): '<S5>/S-Function1' */

  /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:SETUP */
  ds2202_digout_mode_set(DS2202_1_BASE, DS2202_DIGOUT_DISABLE);
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  ADCteste_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ADCteste_update();
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
  ADCteste_initialize();
}

void MdlTerminate(void)
{
  ADCteste_terminate();
}

/* Registration function */
RT_MODEL_ADCteste_T *ADCteste(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ADCteste_M, 0,
                sizeof(RT_MODEL_ADCteste_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ADCteste_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    ADCteste_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ADCteste_M->Timing.sampleTimes = (&ADCteste_M->Timing.sampleTimesArray[0]);
    ADCteste_M->Timing.offsetTimes = (&ADCteste_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ADCteste_M->Timing.sampleTimes[0] = (0.0001);

    /* task offsets */
    ADCteste_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(ADCteste_M, &ADCteste_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ADCteste_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    ADCteste_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ADCteste_M, -1);
  ADCteste_M->Timing.stepSize0 = 0.0001;
  ADCteste_M->solverInfoPtr = (&ADCteste_M->solverInfo);
  ADCteste_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&ADCteste_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&ADCteste_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ADCteste_M->ModelData.blockIO = ((void *) &ADCteste_B);
  (void) memset(((void *) &ADCteste_B), 0,
                sizeof(B_ADCteste_T));

  /* parameters */
  ADCteste_M->ModelData.defaultParam = ((real_T *)&ADCteste_P);

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  /* Initialize Sizes */
  ADCteste_M->Sizes.numContStates = (0);/* Number of continuous states */
  ADCteste_M->Sizes.numY = (0);        /* Number of model outputs */
  ADCteste_M->Sizes.numU = (0);        /* Number of model inputs */
  ADCteste_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ADCteste_M->Sizes.numSampTimes = (1);/* Number of sample times */
  ADCteste_M->Sizes.numBlocks = (10);  /* Number of blocks */
  ADCteste_M->Sizes.numBlockIO = (2);  /* Number of block outputs */
  ADCteste_M->Sizes.numBlockPrms = (4);/* Sum of parameter "widths" */
  return ADCteste_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
