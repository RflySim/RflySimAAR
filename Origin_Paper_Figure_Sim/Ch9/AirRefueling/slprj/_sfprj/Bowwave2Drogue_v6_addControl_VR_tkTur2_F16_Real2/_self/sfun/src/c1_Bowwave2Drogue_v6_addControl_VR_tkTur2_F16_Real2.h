#ifndef __c1_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_Real2_h__
#define __c1_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_Real2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc1_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_Real2InstanceStruct
#define typedef_SFc1_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_Real2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_Real2;
} SFc1_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_Real2InstanceStruct;

#endif                                 /*typedef_SFc1_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_Real2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_Real2_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_Real2_get_check_sum
  (mxArray *plhs[]);
extern void
  c1_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_Real2_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
