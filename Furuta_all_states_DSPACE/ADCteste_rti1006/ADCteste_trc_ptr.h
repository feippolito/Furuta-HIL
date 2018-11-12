  /*********************** dSPACE target specific file *************************

   Header file ADCteste_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1006 7.3 (02-Nov-2014)
   Tue Oct 30 21:53:03 2018

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_ADCteste_trc_ptr_h_
  #define RTI_HEADER_ADCteste_trc_ptr_h_
  /* Include the model header file. */
  #include "ADCteste.h"
  #include "ADCteste_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_0_ADCteste_real_T_0;
              EXTERN_C volatile  real_T *p_1_ADCteste_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_0_ADCteste_real_T_0 = &ADCteste_B.SFunction1_o1;\
              p_1_ADCteste_real_T_0 = &ADCteste_P.Constant_Value;\

   #endif                       /* RTI_HEADER_ADCteste_trc_ptr_h_ */
