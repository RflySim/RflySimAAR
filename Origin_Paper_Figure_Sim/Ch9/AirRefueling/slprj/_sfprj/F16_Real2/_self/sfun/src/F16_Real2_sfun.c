/* Include files */

#include "F16_Real2_sfun.h"
#include "F16_Real2_sfun_debug_macros.h"
#include "c1_F16_Real2.h"
#include "c2_F16_Real2.h"
#include "c3_F16_Real2.h"
#include "c4_F16_Real2.h"
#include "c5_F16_Real2.h"
#include "c6_F16_Real2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _F16_Real2MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void F16_Real2_initializer(void)
{
}

void F16_Real2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_F16_Real2_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_F16_Real2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_F16_Real2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_F16_Real2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_F16_Real2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_F16_Real2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_F16_Real2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_F16_Real2_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(442813686U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3867435700U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2572709415U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2015149190U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1516315195U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2560644654U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(985687857U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2687512857U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_F16_Real2_get_check_sum(mxArray *plhs[]);
          sf_c1_F16_Real2_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_F16_Real2_get_check_sum(mxArray *plhs[]);
          sf_c2_F16_Real2_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_F16_Real2_get_check_sum(mxArray *plhs[]);
          sf_c3_F16_Real2_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_F16_Real2_get_check_sum(mxArray *plhs[]);
          sf_c4_F16_Real2_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_F16_Real2_get_check_sum(mxArray *plhs[]);
          sf_c5_F16_Real2_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_F16_Real2_get_check_sum(mxArray *plhs[]);
          sf_c6_F16_Real2_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2325385138U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1983620818U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3843237520U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1613259640U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_F16_Real2_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "WtIJzyU0dZp9yNOH6UnLz") == 0) {
          extern mxArray *sf_c1_F16_Real2_get_autoinheritance_info(void);
          plhs[0] = sf_c1_F16_Real2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "M6YS3RCZzriDBSwv1kLnND") == 0) {
          extern mxArray *sf_c2_F16_Real2_get_autoinheritance_info(void);
          plhs[0] = sf_c2_F16_Real2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "NufQERQnCpFkpfAzSkB4zG") == 0) {
          extern mxArray *sf_c3_F16_Real2_get_autoinheritance_info(void);
          plhs[0] = sf_c3_F16_Real2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "OtnhBiGkJhLVWPrPsYzBhC") == 0) {
          extern mxArray *sf_c4_F16_Real2_get_autoinheritance_info(void);
          plhs[0] = sf_c4_F16_Real2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "qVOTBQo3DujgD7FGrRt1Z") == 0) {
          extern mxArray *sf_c5_F16_Real2_get_autoinheritance_info(void);
          plhs[0] = sf_c5_F16_Real2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "hvHVHnywvvKfC97swIA1wH") == 0) {
          extern mxArray *sf_c6_F16_Real2_get_autoinheritance_info(void);
          plhs[0] = sf_c6_F16_Real2_get_autoinheritance_info();
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

unsigned int sf_F16_Real2_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        extern const mxArray *sf_c1_F16_Real2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_F16_Real2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_F16_Real2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_F16_Real2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_F16_Real2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_F16_Real2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_F16_Real2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_F16_Real2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_F16_Real2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_F16_Real2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_F16_Real2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_F16_Real2_get_eml_resolved_functions_info();
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

unsigned int sf_F16_Real2_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "uHbPYJBMzAODND9xsTMYlE") == 0) {
          extern mxArray *sf_c1_F16_Real2_third_party_uses_info(void);
          plhs[0] = sf_c1_F16_Real2_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "04hwgis6p9BL8xkjmqpZS") == 0) {
          extern mxArray *sf_c2_F16_Real2_third_party_uses_info(void);
          plhs[0] = sf_c2_F16_Real2_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "jxKHplw87B6UqsfK2VQ1uG") == 0) {
          extern mxArray *sf_c3_F16_Real2_third_party_uses_info(void);
          plhs[0] = sf_c3_F16_Real2_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "dPQ0ld4k9UqP0HnUCE20GE") == 0) {
          extern mxArray *sf_c4_F16_Real2_third_party_uses_info(void);
          plhs[0] = sf_c4_F16_Real2_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "bZYM41XxCtQcAIM9C9ntOG") == 0) {
          extern mxArray *sf_c5_F16_Real2_third_party_uses_info(void);
          plhs[0] = sf_c5_F16_Real2_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "saQB8s79t6nKu0fIxgz1ZH") == 0) {
          extern mxArray *sf_c6_F16_Real2_third_party_uses_info(void);
          plhs[0] = sf_c6_F16_Real2_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void F16_Real2_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _F16_Real2MachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "F16_Real2","sfun",0,6,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_F16_Real2MachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_F16_Real2MachineNumber_,0);
}

void F16_Real2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_F16_Real2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("F16_Real2",
      "F16_Real2");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_F16_Real2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
