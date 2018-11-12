  /*********************** dSPACE target specific file *************************

   Header file Furuta_Model_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1006 7.3 (02-Nov-2014)
   Tue Nov 06 13:55:40 2018

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_Furuta_Model_trc_ptr_h_
  #define RTI_HEADER_Furuta_Model_trc_ptr_h_
  /* Include the model header file. */
  #include "Furuta_Model.h"
  #include "Furuta_Model_private.h"

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
              EXTERN_C volatile  real_T *p_0_Furuta_Model_real_T_0;
              EXTERN_C volatile  boolean_T *p_0_Furuta_Model_boolean_T_1;
              EXTERN_C volatile  real_T *p_1_Furuta_Model_real_T_0;
              EXTERN_C volatile  boolean_T *p_1_Furuta_Model_boolean_T_1;
              EXTERN_C volatile  boolean_T *p_2_Furuta_Model_boolean_T_1;
              EXTERN_C volatile  real_T *p_3_Furuta_Model_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_0_Furuta_Model_real_T_0 = &Furuta_Model_B.Phi;\
              p_0_Furuta_Model_boolean_T_1 = &Furuta_Model_B.SFunction1;\
              p_1_Furuta_Model_real_T_0 = &Furuta_Model_P.Re;\
              p_1_Furuta_Model_boolean_T_1 = &Furuta_Model_P.Q_Y0;\
              p_2_Furuta_Model_boolean_T_1 = &Furuta_Model_DW.Delay2_DSTATE[0];\
              p_3_Furuta_Model_real_T_0 = &Furuta_Model_X.Phi_CSTATE;\

   #endif                       /* RTI_HEADER_Furuta_Model_trc_ptr_h_ */
