/*
 * Furuta_Model_data.c
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

#include "Furuta_Model.h"
#include "Furuta_Model_private.h"

/* Block parameters (auto storage) */
P_Furuta_Model_T Furuta_Model_P = {
  3.6,                                 /* Variable: Re
                                        * Referenced by:
                                        *   '<S10>/Gain1'
                                        *   '<S10>/ke//Re '
                                        */
  3.1415926535897931,                  /* Variable: initial_state
                                        * Referenced by: '<S10>/Theta'
                                        */
  0.0006,                              /* Variable: kb
                                        * Referenced by:
                                        *   '<S10>/Gain2'
                                        *   '<S10>/Gain3'
                                        */
  0.182,                               /* Variable: ke
                                        * Referenced by:
                                        *   '<S10>/Gain1'
                                        *   '<S10>/ke//Re '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  26.0,                                /* Expression: 26
                                        * Referenced by: '<Root>/Gain3'
                                        */
  13.0,                                /* Expression: 13
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Control'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Phi'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<Root>/Constant3'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain4'
                                        */
  0.01,                                /* Expression: 10e-3
                                        * Referenced by: '<Root>/Constant10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/dPhi'
                                        */
  25.0,                                /* Expression: 25
                                        * Referenced by: '<Root>/Constant7'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain5'
                                        */
  6.0,                                 /* Expression: 6
                                        * Referenced by: '<Root>/Constant8'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/dTheta'
                                        */
  25.0,                                /* Expression: 25
                                        * Referenced by: '<Root>/Constant9'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain7'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<Root>/Delay Lenght'
                                        */
  10000.0,                             /* Expression: 1/0.0001
                                        * Referenced by: '<Root>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  0.01,                                /* Expression: 1/100
                                        * Referenced by: '<Root>/Gain9'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S18>/2pi'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/Phi'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S19>/2pi'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S19>/Constant'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/Theta'
                                        */
  6.0,                                 /* Expression: 6
                                        * Referenced by: '<Root>/Constant11'
                                        */
  12.0,                                /* Expression: 12
                                        * Referenced by: '<Root>/Gain8'
                                        */
  0,                                   /* Computed Parameter: Q_Y0
                                        * Referenced by: '<S14>/Q'
                                        */
  1,                                   /* Computed Parameter: Q_Y0_j
                                        * Referenced by: '<S14>/!Q'
                                        */
  1,                                   /* Computed Parameter: Delay2_InitialCondition
                                        * Referenced by: '<Root>/Delay2'
                                        */
  1,                                   /* Computed Parameter: Constant12_Value
                                        * Referenced by: '<Root>/Constant12'
                                        */
  0                                    /* Computed Parameter: TmpLatchAtDFlipFlopInport1_X0
                                        * Referenced by: synthesized block
                                        */
};
