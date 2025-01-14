/* Include files */

#include "Bowwave2Drogue_v6_addControl_VR_tkTur_sfun.h"
#include "Bowwave2Drogue_v6_addControl_VR_tkTur_sfun_debug_macros.h"
#include "c1_Bowwave2Drogue_v6_addControl_VR_tkTur.h"
#include "c2_Bowwave2Drogue_v6_addControl_VR_tkTur.h"
#include "c3_Bowwave2Drogue_v6_addControl_VR_tkTur.h"
#include "c4_Bowwave2Drogue_v6_addControl_VR_tkTur.h"
#include "c5_Bowwave2Drogue_v6_addControl_VR_tkTur.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Bowwave2Drogue_v6_addControl_VR_tkTurMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Bowwave2Drogue_v6_addControl_VR_tkTur_initializer(void)
{
}

void Bowwave2Drogue_v6_addControl_VR_tkTur_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Bowwave2Drogue_v6_addControl_VR_tkTur_method_dispatcher
  (SimStruct *simstructPtr, unsigned int chartFileNumber, const char* specsCksum,
   int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Bowwave2Drogue_v6_addControl_VR_tkTur_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Bowwave2Drogue_v6_addControl_VR_tkTur_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Bowwave2Drogue_v6_addControl_VR_tkTur_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Bowwave2Drogue_v6_addControl_VR_tkTur_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Bowwave2Drogue_v6_addControl_VR_tkTur_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Bowwave2Drogue_v6_addControl_VR_tkTur_process_check_sum_call
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(661433721U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3319295684U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(654172125U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(376044250U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(238024296U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1836046292U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3562123457U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2904787100U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Bowwave2Drogue_v6_addControl_VR_tkTur_get_check_sum
            (mxArray *plhs[]);
          sf_c1_Bowwave2Drogue_v6_addControl_VR_tkTur_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_get_check_sum
            (mxArray *plhs[]);
          sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Bowwave2Drogue_v6_addControl_VR_tkTur_get_check_sum
            (mxArray *plhs[]);
          sf_c3_Bowwave2Drogue_v6_addControl_VR_tkTur_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Bowwave2Drogue_v6_addControl_VR_tkTur_get_check_sum
            (mxArray *plhs[]);
          sf_c4_Bowwave2Drogue_v6_addControl_VR_tkTur_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Bowwave2Drogue_v6_addControl_VR_tkTur_get_check_sum
            (mxArray *plhs[]);
          sf_c5_Bowwave2Drogue_v6_addControl_VR_tkTur_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4183358359U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(970358701U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3557850601U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2888839263U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Bowwave2Drogue_v6_addControl_VR_tkTur_autoinheritance_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "vi5jM57zT3gnIoLTabKWW") == 0) {
          extern mxArray
            *sf_c1_Bowwave2Drogue_v6_addControl_VR_tkTur_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_Bowwave2Drogue_v6_addControl_VR_tkTur_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "M6YS3RCZzriDBSwv1kLnND") == 0) {
          extern mxArray
            *sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "5zd1WfoLK2qKHOBiLRBH6G") == 0) {
          extern mxArray
            *sf_c3_Bowwave2Drogue_v6_addControl_VR_tkTur_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c3_Bowwave2Drogue_v6_addControl_VR_tkTur_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "gLCjqY62Y0p3xBf5auZUEC") == 0) {
          extern mxArray
            *sf_c4_Bowwave2Drogue_v6_addControl_VR_tkTur_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c4_Bowwave2Drogue_v6_addControl_VR_tkTur_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "Yt9mgxeWIh1bZaia4sqY3C") == 0) {
          extern mxArray
            *sf_c5_Bowwave2Drogue_v6_addControl_VR_tkTur_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c5_Bowwave2Drogue_v6_addControl_VR_tkTur_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int
  sf_Bowwave2Drogue_v6_addControl_VR_tkTur_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_Bowwave2Drogue_v6_addControl_VR_tkTur_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Bowwave2Drogue_v6_addControl_VR_tkTur_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_Bowwave2Drogue_v6_addControl_VR_tkTur_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Bowwave2Drogue_v6_addControl_VR_tkTur_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Bowwave2Drogue_v6_addControl_VR_tkTur_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Bowwave2Drogue_v6_addControl_VR_tkTur_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_Bowwave2Drogue_v6_addControl_VR_tkTur_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Bowwave2Drogue_v6_addControl_VR_tkTur_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Bowwave2Drogue_v6_addControl_VR_tkTur_third_party_uses_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "JNVzz1Buh3NSvClaC9Dq4F") == 0) {
          extern mxArray
            *sf_c1_Bowwave2Drogue_v6_addControl_VR_tkTur_third_party_uses_info
            (void);
          plhs[0] =
            sf_c1_Bowwave2Drogue_v6_addControl_VR_tkTur_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "04hwgis6p9BL8xkjmqpZS") == 0) {
          extern mxArray
            *sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_third_party_uses_info
            (void);
          plhs[0] =
            sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "YEWPqSGY4oZJDcNhk7HipD") == 0) {
          extern mxArray
            *sf_c3_Bowwave2Drogue_v6_addControl_VR_tkTur_third_party_uses_info
            (void);
          plhs[0] =
            sf_c3_Bowwave2Drogue_v6_addControl_VR_tkTur_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "7qvAWdidiA420LOtGxDvnB") == 0) {
          extern mxArray
            *sf_c4_Bowwave2Drogue_v6_addControl_VR_tkTur_third_party_uses_info
            (void);
          plhs[0] =
            sf_c4_Bowwave2Drogue_v6_addControl_VR_tkTur_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "b2YXVX1KY02s3dLUKhAyf") == 0) {
          extern mxArray
            *sf_c5_Bowwave2Drogue_v6_addControl_VR_tkTur_third_party_uses_info
            (void);
          plhs[0] =
            sf_c5_Bowwave2Drogue_v6_addControl_VR_tkTur_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Bowwave2Drogue_v6_addControl_VR_tkTur_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _Bowwave2Drogue_v6_addControl_VR_tkTurMachineNumber_ =
    sf_debug_initialize_machine(debugInstance,
    "Bowwave2Drogue_v6_addControl_VR_tkTur","sfun",0,5,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Bowwave2Drogue_v6_addControl_VR_tkTurMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Bowwave2Drogue_v6_addControl_VR_tkTurMachineNumber_,0);
}

void Bowwave2Drogue_v6_addControl_VR_tkTur_register_exported_symbols(SimStruct*
  S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Bowwave2Drogue_v6_addControl_VR_tkTur_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Bowwave2Drogue_v6_addControl_VR_tkTur",
      "Bowwave2Drogue_v6_addControl_VR_tkTur");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Bowwave2Drogue_v6_addControl_VR_tkTur_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
