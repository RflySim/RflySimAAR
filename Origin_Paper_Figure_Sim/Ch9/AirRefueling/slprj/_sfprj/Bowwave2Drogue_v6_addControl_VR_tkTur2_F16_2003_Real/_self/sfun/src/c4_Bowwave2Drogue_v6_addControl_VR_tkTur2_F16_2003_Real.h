#ifndef __c4_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_2003_Real_h__
#define __c4_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_2003_Real_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c4_ResolvedFunctionInfo
#define typedef_c4_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c4_ResolvedFunctionInfo;

#endif                                 /*typedef_c4_ResolvedFunctionInfo*/

#ifndef typedef_SFc4_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_2003_RealInstanceStruct
#define typedef_SFc4_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_2003_RealInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_2003_;
} SFc4_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_2003_RealInstanceStruct;

#endif                                 /*typedef_SFc4_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_2003_RealInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_2003_Real_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void
  sf_c4_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_2003_Real_get_check_sum
  (mxArray *plhs[]);
extern void
  c4_Bowwave2Drogue_v6_addControl_VR_tkTur2_F16_2003_Real_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
