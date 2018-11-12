/*********************** dSPACE target specific file *************************

   Include file pwm_teste_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1006 7.3 (02-Nov-2014)
   Fri Oct 26 21:59:51 2018

   (c) Copyright 2006, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "pwm_teste.h"
#include "pwm_teste_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             pwm_teste_B
#define RTP_STRUCTURE_NAME             pwm_teste_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <ds2202.h>

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Definition of interface functions for simulation engine =========== */
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        1
#endif

#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

static void rti_mdl_initialize_host_services(void)
{
  ts_timestamp_type ts = { 0, 0 };

  host_service(1, &ts);
  DsDaq_Init(0, 32, 1);
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1006, (void *) 0,
                        VCM_TXT_RTI1006, 7, 3, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 8, 5, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 8, 5, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 8, 8, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }

  /* dSPACE I/O Board DS2202 #1 */
  ds2202_init(DS2202_1_BASE);

  /* dSPACE I/O Board DS2202 #1 Unit:DIO */
  ds2202_timing_out_mode_set(DS2202_1_BASE, DS2202_PWMOUT_CH1,
    DS2202_TIMING_RANGE4, DS2202_D2PWM );
  ds2202_timing_out_mode_set(DS2202_1_BASE, DS2202_PWMOUT_CH2,
    DS2202_TIMING_RANGE4, DS2202_D2PWM );
  ds2202_timing_out_mode_set(DS2202_1_BASE, DS2202_PWMOUT_CH3,
    DS2202_TIMING_RANGE4, DS2202_D2PWM );
  ds2202_timing_out_mode_set(DS2202_1_BASE, DS2202_PWMOUT_CH4,
    DS2202_TIMING_RANGE4, DS2202_D2PWM );

  /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:SETUP */
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN1, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN2, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN3, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN4, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN5, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN6, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN7, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN8, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN9, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN10, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN11, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN12, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN13, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN14, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN15, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN16, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN17, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN18, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN19, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN20, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN21, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN22, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN23, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN24, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN25_32, 1.65);
  ds2202_digin_threshold_set(DS2202_1_BASE, DS2202_THRESH_DIGIN33_38, 1.65);

  /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:SETUP */
  ds2202_digout_ls_write(DS2202_1_BASE, DS2202_OUTSTP_DIGOUT1 |
    DS2202_OUTSTP_DIGOUT2 | DS2202_OUTSTP_DIGOUT3 | DS2202_OUTSTP_DIGOUT4 |
    DS2202_OUTSTP_DIGOUT5 | DS2202_OUTSTP_DIGOUT6 | DS2202_OUTSTP_DIGOUT7 |
    DS2202_OUTSTP_DIGOUT8 | DS2202_OUTSTP_DIGOUT9 | DS2202_OUTSTP_DIGOUT10 |
    DS2202_OUTSTP_DIGOUT11 | DS2202_OUTSTP_DIGOUT12 | DS2202_OUTSTP_DIGOUT13 |
    DS2202_OUTSTP_DIGOUT14 | DS2202_OUTSTP_DIGOUT15 | DS2202_OUTSTP_DIGOUT16 |
    DS2202_OUTSTP_PWMOUT1 | DS2202_OUTSTP_PWMOUT2 | DS2202_OUTSTP_PWMOUT3 |
    DS2202_OUTSTP_PWMOUT4 | DS2202_OUTSTP_PWMOUT5 | DS2202_OUTSTP_PWMOUT6 |
    DS2202_OUTSTP_PWMOUT7 | DS2202_OUTSTP_PWMOUT8 | DS2202_OUTSTP_PWMOUT9);
  ds2202_digout_hs_vbat1_write(DS2202_1_BASE, DS2202_OUTSTP_DIGOUT1 |
    DS2202_OUTSTP_DIGOUT2 | DS2202_OUTSTP_DIGOUT3 | DS2202_OUTSTP_DIGOUT4 |
    DS2202_OUTSTP_DIGOUT5 | DS2202_OUTSTP_DIGOUT6 | DS2202_OUTSTP_DIGOUT7 |
    DS2202_OUTSTP_DIGOUT8 | DS2202_OUTSTP_DIGOUT9 | DS2202_OUTSTP_DIGOUT10 |
    DS2202_OUTSTP_DIGOUT11 | DS2202_OUTSTP_DIGOUT12 | DS2202_OUTSTP_DIGOUT13 |
    DS2202_OUTSTP_DIGOUT14 | DS2202_OUTSTP_DIGOUT15 | DS2202_OUTSTP_DIGOUT16 |
    DS2202_OUTSTP_PWMOUT1 | DS2202_OUTSTP_PWMOUT2 | DS2202_OUTSTP_PWMOUT3 |
    DS2202_OUTSTP_PWMOUT4 | DS2202_OUTSTP_PWMOUT5 | DS2202_OUTSTP_PWMOUT6 |
    DS2202_OUTSTP_PWMOUT7 | DS2202_OUTSTP_PWMOUT8 | DS2202_OUTSTP_PWMOUT9);
  ds2202_digout_hs_vbat2_write(DS2202_1_BASE, 0x00);

  /* dSPACE I/O Board DS2202 #1 Unit:PWM2D */
  ds2202_timing_in_mode_set(DS2202_1_BASE, DS2202_PWMIN_CH1,
    DS2202_TIMING_RANGE7, DS2202_PWM2D);
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* dSPACE I/O Board DS2202 #1 Unit:DIO */
  ds2202_digout_mode_set(DS2202_1_BASE, DS2202_DIGOUT_ENABLE);

  /* dSPACE I/O Board DS2202 #1 Unit:DIO Group:PWM */
  ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH1, 5.0E-5, 0);
  ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH2, 5.0E-5, 0);
  ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH3, 5.0E-5, 0);
  ds2202_pwm_out(DS2202_1_BASE, DS2202_PWMOUT_CH4, 5.0E-5, 0);
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{
  /* DsDaq background call */
  DsDaq_Background(0);
}

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.0001, 0.0] */
  /* dSPACE I/O Board DS2202 #1 Unit:PWM2D */
  ds2202_pwm_in(DS2202_1_BASE, DS2202_PWMIN_CH1, &pwm_teste_B.SFunction1_o2,
                &pwm_teste_B.SFunction1_o1);
}

static void rti_mdl_daq_service()
{
  /* dSPACE Host Service */
  host_service(1, rtk_current_task_absolute_time_ptr_get());
  DsDaq_Service(0, 0, 1, (DsDaqSTimestampStruct *)
                rtk_current_task_absolute_time_ptr_get());
}

#undef __INLINE

/****** [EOF] ****************************************************************/
