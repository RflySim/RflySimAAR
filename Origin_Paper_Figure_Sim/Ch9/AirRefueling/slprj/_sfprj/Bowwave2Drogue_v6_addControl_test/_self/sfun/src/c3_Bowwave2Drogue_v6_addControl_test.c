/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Bowwave2Drogue_v6_addControl_test_sfun.h"
#include "c3_Bowwave2Drogue_v6_addControl_test.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Bowwave2Drogue_v6_addControl_test_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[17] = { "PosPr", "PosTb", "VrAngle",
  "VrPos", "j", "pX", "pY", "pZ", "vAxis", "vTb", "axis1", "vRot", "nargin",
  "nargout", "PosPr1", "PosTb1", "y" };

/* Function Declarations */
static void initialize_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void initialize_params_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void enable_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void disable_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void set_sim_state_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_st);
static void finalize_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void sf_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void c3_chartstep_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void initSimStructsc3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void registerMessagesc3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_y, const char_T *c3_identifier, real_T c3_b_y[150]);
static void c3_b_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[150]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[9], int32_T c3_inData_sizes[2]);
static void c3_e_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y_data[9],
   int32_T c3_y_sizes[2]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[9],
  int32_T c3_outData_sizes[2]);
static void c3_f_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3]);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_g_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[66]);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_h_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[84]);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_i_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[60]);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[161]);
static void c3_b_info_helper(c3_ResolvedFunctionInfo c3_info[161]);
static void c3_c_info_helper(c3_ResolvedFunctionInfo c3_info[161]);
static real_T c3_eml_div(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x, real_T c3_y);
static void c3_eml_error(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance);
static void c3_eml_xgesvd(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_A[6], real_T c3_U[4], real_T c3_S[2], real_T c3_V[9]);
static void c3_eml_scalar_eg
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static real_T c3_eml_xnrm2(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_x[6]);
static void c3_realmin(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance);
static real_T c3_abs(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                     *chartInstance, real_T c3_x);
static void c3_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_a, real_T c3_x[6], real_T c3_b_x[6]);
static real_T c3_eml_xdotc(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_x[6], real_T c3_y[6], int32_T c3_iy0);
static void c3_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_a, real_T c3_y[6], int32_T c3_iy0, real_T c3_b_y[6]);
static real_T c3_b_eml_xnrm2
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, real_T
   c3_x[3]);
static void c3_b_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[3], real_T c3_b_x[3]);
static void c3_b_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[6], int32_T c3_ix0, real_T c3_y[2],
  real_T c3_b_y[2]);
static void c3_c_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[2], real_T c3_y[6], int32_T c3_iy0,
  real_T c3_b_y[6]);
static real_T c3_b_eml_xdotc
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, real_T
   c3_x[4], real_T c3_y[4]);
static void c3_d_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_y[4], real_T c3_b_y[4]);
static real_T c3_c_eml_xdotc
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, int32_T
   c3_n, real_T c3_x[9], int32_T c3_ix0, real_T c3_y[9], int32_T c3_iy0);
static void c3_e_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, int32_T c3_n, real_T c3_a, int32_T c3_ix0, real_T c3_y[9],
  int32_T c3_iy0, real_T c3_b_y[9]);
static void c3_b_eml_scalar_eg
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void c3_c_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[4], int32_T c3_ix0, real_T c3_b_x[4]);
static void c3_d_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[9], int32_T c3_ix0, real_T c3_b_x[9]);
static void c3_eps(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                   *chartInstance);
static void c3_c_eml_scalar_eg
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static void c3_b_eml_error(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance);
static real_T c3_sqrt(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                      *chartInstance, real_T c3_x);
static void c3_c_eml_error(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance);
static void c3_eml_xrotg(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_a, real_T c3_b, real_T *c3_b_a, real_T *c3_b_b,
  real_T *c3_c, real_T *c3_s);
static void c3_eml_xrot(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x[9], int32_T c3_ix0, int32_T c3_iy0, real_T c3_c,
  real_T c3_s, real_T c3_b_x[9]);
static void c3_b_eml_xrot(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x[4], int32_T c3_ix0, int32_T c3_iy0, real_T c3_c,
  real_T c3_s, real_T c3_b_x[4]);
static void c3_eml_xswap(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x[9], int32_T c3_ix0, int32_T c3_iy0, real_T c3_b_x
  [9]);
static void c3_b_eml_xswap(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_x[4], int32_T c3_ix0, int32_T c3_iy0, real_T c3_b_x[4]);
static void c3_d_eml_scalar_eg
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);
static real_T c3_acos(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                      *chartInstance, real_T c3_x);
static void c3_d_eml_error(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_j_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_k_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_b_is_active_c3_Bowwave2Drogue_v6_addControl_test, const char_T
   *c3_identifier);
static uint8_T c3_l_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[6]);
static void c3_f_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_y[6], int32_T c3_iy0);
static void c3_f_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[3]);
static void c3_g_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[6], int32_T c3_ix0, real_T c3_y[2]);
static void c3_h_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[2], real_T c3_y[6], int32_T c3_iy0);
static void c3_i_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_y[4]);
static void c3_j_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, int32_T c3_n, real_T c3_a, int32_T c3_ix0, real_T c3_y[9],
  int32_T c3_iy0);
static void c3_g_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[4], int32_T c3_ix0);
static void c3_h_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[9], int32_T c3_ix0);
static void c3_b_sqrt(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                      *chartInstance, real_T *c3_x);
static void c3_b_eml_xrotg(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T *c3_a, real_T *c3_b, real_T *c3_c, real_T *c3_s);
static void c3_c_eml_xrot(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x[9], int32_T c3_ix0, int32_T c3_iy0, real_T c3_c,
  real_T c3_s);
static void c3_d_eml_xrot(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x[4], int32_T c3_ix0, int32_T c3_iy0, real_T c3_c,
  real_T c3_s);
static void c3_c_eml_xswap(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_x[9], int32_T c3_ix0, int32_T c3_iy0);
static void c3_d_eml_xswap(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_x[4], int32_T c3_ix0, int32_T c3_iy0);
static void c3_b_acos(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                      *chartInstance, real_T *c3_x);
static void init_dsm_address_info
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_Bowwave2Drogue_v6_addControl_test = 0U;
}

static void initialize_params_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
}

static void enable_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[150];
  const mxArray *c3_b_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T (*c3_d_y)[150];
  c3_d_y = (real_T (*)[150])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  for (c3_i0 = 0; c3_i0 < 150; c3_i0++) {
    c3_u[c3_i0] = (*c3_d_y)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 150), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal =
    chartInstance->c3_is_active_c3_Bowwave2Drogue_v6_addControl_test;
  c3_b_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[150];
  int32_T c3_i1;
  real_T (*c3_y)[150];
  c3_y = (real_T (*)[150])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)), "y",
                      c3_dv0);
  for (c3_i1 = 0; c3_i1 < 150; c3_i1++) {
    (*c3_y)[c3_i1] = c3_dv0[c3_i1];
  }

  chartInstance->c3_is_active_c3_Bowwave2Drogue_v6_addControl_test =
    c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "is_active_c3_Bowwave2Drogue_v6_addControl_test");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_Bowwave2Drogue_v6_addControl_test(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
}

static void sf_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  real_T (*c3_PosTb1)[100];
  real_T (*c3_PosPr1)[3];
  real_T (*c3_y)[150];
  c3_PosTb1 = (real_T (*)[100])ssGetInputPortSignal(chartInstance->S, 1);
  c3_PosPr1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c3_y = (real_T (*)[150])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  for (c3_i2 = 0; c3_i2 < 150; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_y)[c3_i2], 0U);
  }

  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    _SFD_DATA_RANGE_CHECK((*c3_PosPr1)[c3_i3], 1U);
  }

  for (c3_i4 = 0; c3_i4 < 100; c3_i4++) {
    _SFD_DATA_RANGE_CHECK((*c3_PosTb1)[c3_i4], 2U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_Bowwave2Drogue_v6_addControl_test(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_Bowwave2Drogue_v6_addControl_testMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
  int32_T c3_i5;
  real_T c3_PosPr1[3];
  int32_T c3_i6;
  real_T c3_PosTb1[100];
  uint32_T c3_debug_family_var_map[17];
  real_T c3_PosPr[3];
  real_T c3_PosTb[60];
  real_T c3_VrAngle[84];
  real_T c3_VrPos[66];
  real_T c3_j;
  real_T c3_pX[3];
  real_T c3_pY[3];
  real_T c3_pZ[3];
  real_T c3_vAxis[3];
  real_T c3_vTb[3];
  int32_T c3_axis1_sizes[2];
  real_T c3_axis1_data[9];
  real_T c3_vRot[3];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  real_T c3_y[150];
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_b_j;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  real_T c3_b_PosTb[3];
  int32_T c3_i14;
  real_T c3_b;
  real_T c3_d0;
  real_T c3_b_b;
  real_T c3_d1;
  int32_T c3_i15;
  real_T c3_c_b;
  real_T c3_d2;
  real_T c3_d_b;
  real_T c3_d3;
  int32_T c3_i16;
  int32_T c3_i17;
  real_T c3_a[3];
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  static real_T c3_e_b[3] = { 0.0, 0.0, -1.0 };

  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  real_T c3_S[6];
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_x;
  real_T c3_b_x;
  boolean_T c3_f_b;
  boolean_T c3_b0;
  real_T c3_c_x;
  boolean_T c3_g_b;
  boolean_T c3_b1;
  boolean_T c3_h_b;
  int32_T c3_i28;
  real_T c3_b_S[6];
  real_T c3_V[9];
  real_T c3_s[2];
  real_T c3_U[4];
  int32_T c3_i29;
  int32_T c3_c_k;
  real_T c3_d_k;
  int32_T c3_r;
  real_T c3_i_b;
  real_T c3_b_y;
  real_T c3_b_a;
  real_T c3_tol;
  int32_T c3_e_k;
  real_T c3_f_k;
  int32_T c3_c_a;
  int32_T c3_j_b;
  const mxArray *c3_c_y = NULL;
  int32_T c3_i30;
  int32_T c3_loop_ub;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  real_T c3_k_b;
  real_T c3_d4;
  real_T c3_l_b;
  real_T c3_d5;
  real_T c3_b_vRot[3];
  int32_T c3_i35;
  real_T c3_m_b;
  real_T c3_d_y;
  int32_T c3_i36;
  real_T c3_e_y;
  int32_T c3_g_k;
  int32_T c3_h_k;
  real_T c3_f_y;
  int32_T c3_i_k;
  int32_T c3_j_k;
  real_T c3_d_a;
  int32_T c3_i37;
  real_T c3_n_b[3];
  int32_T c3_i38;
  int32_T c3_i39;
  real_T c3_g_y;
  int32_T c3_k_k;
  int32_T c3_l_k;
  real_T c3_A;
  real_T c3_B;
  real_T c3_d_x;
  real_T c3_h_y;
  real_T c3_e_x;
  real_T c3_i_y;
  real_T c3_j_y;
  real_T c3_o_b;
  real_T c3_d6;
  real_T c3_p_b;
  real_T c3_d7;
  real_T c3_b_pZ[3];
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  real_T c3_c_pZ[3];
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  real_T (*c3_k_y)[150];
  real_T (*c3_b_PosTb1)[100];
  real_T (*c3_b_PosPr1)[3];
  c3_b_PosTb1 = (real_T (*)[100])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_PosPr1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c3_k_y = (real_T (*)[150])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  for (c3_i5 = 0; c3_i5 < 3; c3_i5++) {
    c3_PosPr1[c3_i5] = (*c3_b_PosPr1)[c3_i5];
  }

  for (c3_i6 = 0; c3_i6 < 100; c3_i6++) {
    c3_PosTb1[c3_i6] = (*c3_b_PosTb1)[c3_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_PosPr, 0U, c3_c_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_PosTb, 1U, c3_i_sf_marshallOut,
    c3_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_VrAngle, 2U, c3_h_sf_marshallOut,
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_VrPos, 3U, c3_g_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j, 4U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_pX, 5U, c3_c_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_pY, 6U, c3_c_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_pZ, 7U, c3_c_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_vAxis, 8U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_vTb, 9U, c3_c_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_axis1_data, (const int32_T *)
    &c3_axis1_sizes, NULL, 0, 10, (void *)c3_f_sf_marshallOut, (void *)
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_vRot, 11U, c3_e_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 12U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 13U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_PosPr1, 14U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_PosTb1, 15U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_y, 16U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i7 = 0; c3_i7 < 3; c3_i7++) {
    c3_PosPr[c3_i7] = c3_PosPr1[c3_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  for (c3_i8 = 0; c3_i8 < 60; c3_i8++) {
    c3_PosTb[c3_i8] = c3_PosTb1[c3_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
  for (c3_i9 = 0; c3_i9 < 84; c3_i9++) {
    c3_VrAngle[c3_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  for (c3_i10 = 0; c3_i10 < 66; c3_i10++) {
    c3_VrPos[c3_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_j = 1.0;
  c3_b_j = 0;
  while (c3_b_j < 21) {
    c3_j = 1.0 + (real_T)c3_b_j;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
    if (CV_EML_IF(0, 1, 0, c3_j == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
      for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
        c3_pX[c3_i11] = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
      for (c3_i12 = 0; c3_i12 < 3; c3_i12++) {
        c3_pY[c3_i12] = c3_PosTb[c3_i12];
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
      if (CV_EML_IF(0, 1, 1, c3_j == 21.0)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
        for (c3_i13 = 0; c3_i13 < 3; c3_i13++) {
          c3_pX[c3_i13] = c3_PosTb[c3_i13 + 57];
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
        c3_b_PosTb[0] = c3_PosTb[57] - 0.70932901763958689;
        c3_b_PosTb[1] = c3_PosTb[58];
        c3_b_PosTb[2] = c3_PosTb[59] + 0.099689692217694886;
        for (c3_i14 = 0; c3_i14 < 3; c3_i14++) {
          c3_pY[c3_i14] = c3_b_PosTb[c3_i14];
        }
      } else {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
        c3_b = c3_j;
        c3_d0 = 3.0 * c3_b;
        c3_b_b = c3_j;
        c3_d1 = 3.0 * c3_b_b;
        if (c3_d0 == c3_d1) {
        } else {
          _SFD_RUNTIME_ERROR_MSGID(
            "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing");
        }

        for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
          c3_pX[c3_i15] = c3_PosTb[(int32_T)(c3_d0 + (-5.0 + (real_T)c3_i15)) -
            1];
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
        c3_c_b = c3_j;
        c3_d2 = 3.0 * c3_c_b;
        c3_d_b = c3_j;
        c3_d3 = 3.0 * c3_d_b;
        if (c3_d2 == c3_d3) {
        } else {
          _SFD_RUNTIME_ERROR_MSGID(
            "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing");
        }

        for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
          c3_pY[c3_i16] = c3_PosTb[(int32_T)(c3_d2 + (-2.0 + (real_T)c3_i16)) -
            1];
        }
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
    for (c3_i17 = 0; c3_i17 < 3; c3_i17++) {
      c3_a[c3_i17] = c3_pX[c3_i17] + c3_pY[c3_i17];
    }

    for (c3_i18 = 0; c3_i18 < 3; c3_i18++) {
      c3_pZ[c3_i18] = c3_a[c3_i18] / 2.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
    for (c3_i19 = 0; c3_i19 < 3; c3_i19++) {
      c3_a[c3_i19] = c3_pZ[c3_i19];
    }

    for (c3_i20 = 0; c3_i20 < 3; c3_i20++) {
      c3_a[c3_i20] *= 8.0;
    }

    for (c3_i21 = 0; c3_i21 < 3; c3_i21++) {
      c3_pZ[c3_i21] = c3_a[c3_i21] / 3.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
    for (c3_i22 = 0; c3_i22 < 3; c3_i22++) {
      c3_vAxis[c3_i22] = c3_e_b[c3_i22];
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
    for (c3_i23 = 0; c3_i23 < 3; c3_i23++) {
      c3_vTb[c3_i23] = c3_pY[c3_i23] - c3_pX[c3_i23];
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
    c3_i24 = 0;
    for (c3_i25 = 0; c3_i25 < 3; c3_i25++) {
      c3_S[c3_i24] = c3_vAxis[c3_i25];
      c3_i24 += 2;
    }

    c3_i26 = 0;
    for (c3_i27 = 0; c3_i27 < 3; c3_i27++) {
      c3_S[c3_i26 + 1] = c3_vTb[c3_i27];
      c3_i26 += 2;
    }

    for (c3_k = 1; c3_k < 7; c3_k++) {
      c3_b_k = c3_k - 1;
      c3_x = c3_S[c3_b_k];
      c3_b_x = c3_x;
      c3_f_b = muDoubleScalarIsInf(c3_b_x);
      c3_b0 = !c3_f_b;
      c3_c_x = c3_x;
      c3_g_b = muDoubleScalarIsNaN(c3_c_x);
      c3_b1 = !c3_g_b;
      c3_h_b = (c3_b0 && c3_b1);
      if (!c3_h_b) {
        c3_eml_error(chartInstance);
      }
    }

    for (c3_i28 = 0; c3_i28 < 6; c3_i28++) {
      c3_b_S[c3_i28] = c3_S[c3_i28];
    }

    c3_eml_xgesvd(chartInstance, c3_b_S, c3_U, c3_s, c3_V);
    for (c3_i29 = 0; c3_i29 < 6; c3_i29++) {
      c3_S[c3_i29] = 0.0;
    }

    for (c3_c_k = 0; c3_c_k < 2; c3_c_k++) {
      c3_d_k = 1.0 + (real_T)c3_c_k;
      c3_S[((int32_T)c3_d_k + (((int32_T)c3_d_k - 1) << 1)) - 1] = c3_s[(int32_T)
        c3_d_k - 1];
    }

    c3_r = 1;
    c3_eps(chartInstance);
    c3_i_b = c3_S[0];
    c3_b_y = 3.0 * c3_i_b;
    c3_b_a = c3_b_y;
    c3_tol = c3_b_a * 2.2204460492503131E-16;
    for (c3_e_k = 0; c3_e_k < 2; c3_e_k++) {
      c3_f_k = 1.0 + (real_T)c3_e_k;
      c3_c_a = c3_r;
      c3_j_b = (c3_S[((int32_T)c3_f_k + (((int32_T)c3_f_k - 1) << 1)) - 1] >
                c3_tol);
      c3_r = c3_c_a + c3_j_b;
    }

    if (c3_r <= 3) {
    } else {
      c3_c_y = NULL;
      sf_mex_assign(&c3_c_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U,
        0U, 2, 1, strlen("Assertion failed.")), FALSE);
      sf_mex_call_debug("error", 0U, 1U, 14, c3_c_y);
    }

    c3_i30 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c3_r, 1, 3, 0, 0);
    c3_axis1_sizes[0] = 3;
    c3_axis1_sizes[1] = 4 - c3_i30;
    c3_loop_ub = 3 - c3_i30;
    for (c3_i31 = 0; c3_i31 <= c3_loop_ub; c3_i31++) {
      for (c3_i32 = 0; c3_i32 < 3; c3_i32++) {
        c3_axis1_data[c3_i32 + c3_axis1_sizes[0] * c3_i31] = c3_V[c3_i32 + 3 *
          ((c3_i30 + c3_i31) - 1)];
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
    for (c3_i33 = 0; c3_i33 < 3; c3_i33++) {
      c3_vRot[c3_i33] = c3_axis1_data[c3_i33];
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 39);
    if (CV_EML_IF(0, 1, 2, c3_vRot[1] < 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
      for (c3_i34 = 0; c3_i34 < 3; c3_i34++) {
        c3_vRot[c3_i34] = -c3_vRot[c3_i34];
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 43);
    c3_k_b = c3_j;
    c3_d4 = 4.0 * c3_k_b;
    c3_l_b = c3_j;
    c3_d5 = 4.0 * c3_l_b;
    if (c3_d4 == c3_d5) {
    } else {
      _SFD_RUNTIME_ERROR_MSGID(
        "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing");
    }

    c3_b_vRot[0] = c3_vRot[0];
    c3_b_vRot[1] = c3_vRot[2];
    c3_b_vRot[2] = c3_vRot[1];
    for (c3_i35 = 0; c3_i35 < 3; c3_i35++) {
      c3_VrAngle[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("VrAngle",
        (int32_T)_SFD_INTEGER_CHECK("4*j-3:4*j-1", c3_d4 + (-3.0 + (real_T)
        c3_i35)), 1, 84, 1, 0) - 1] = c3_b_vRot[c3_i35];
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
    c3_m_b = c3_j;
    c3_d_y = 4.0 * c3_m_b;
    for (c3_i36 = 0; c3_i36 < 3; c3_i36++) {
      c3_a[c3_i36] = c3_vTb[c3_i36];
    }

    c3_d_eml_scalar_eg(chartInstance);
    c3_d_eml_scalar_eg(chartInstance);
    c3_e_y = 0.0;
    for (c3_g_k = 1; c3_g_k < 4; c3_g_k++) {
      c3_h_k = c3_g_k - 1;
      c3_e_y += c3_e_b[c3_h_k] * c3_a[c3_h_k];
    }

    c3_d_eml_scalar_eg(chartInstance);
    c3_d_eml_scalar_eg(chartInstance);
    c3_f_y = 0.0;
    for (c3_i_k = 1; c3_i_k < 4; c3_i_k++) {
      c3_j_k = c3_i_k - 1;
      c3_f_y += c3_e_b[c3_j_k] * c3_e_b[c3_j_k];
    }

    c3_d_a = c3_f_y;
    for (c3_i37 = 0; c3_i37 < 3; c3_i37++) {
      c3_n_b[c3_i37] = c3_vTb[c3_i37];
    }

    for (c3_i38 = 0; c3_i38 < 3; c3_i38++) {
      c3_n_b[c3_i38] *= c3_d_a;
    }

    for (c3_i39 = 0; c3_i39 < 3; c3_i39++) {
      c3_a[c3_i39] = c3_vTb[c3_i39];
    }

    c3_d_eml_scalar_eg(chartInstance);
    c3_d_eml_scalar_eg(chartInstance);
    c3_g_y = 0.0;
    for (c3_k_k = 1; c3_k_k < 4; c3_k_k++) {
      c3_l_k = c3_k_k - 1;
      c3_g_y += c3_n_b[c3_l_k] * c3_a[c3_l_k];
    }

    c3_A = c3_e_y;
    c3_B = c3_g_y;
    c3_b_sqrt(chartInstance, &c3_B);
    c3_d_x = c3_A;
    c3_h_y = c3_B;
    c3_e_x = c3_d_x;
    c3_i_y = c3_h_y;
    c3_j_y = c3_e_x / c3_i_y;
    c3_VrAngle[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("VrAngle", (int32_T)
      _SFD_INTEGER_CHECK("4*j", c3_d_y), 1, 84, 1, 0) - 1] = c3_j_y;
    c3_b_acos(chartInstance, &c3_VrAngle[(int32_T)(real_T)
              _SFD_EML_ARRAY_BOUNDS_CHECK("VrAngle", (int32_T)_SFD_INTEGER_CHECK
               ("4*j", c3_d_y), 1, 84, 1, 0) - 1]);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 46);
    c3_o_b = c3_j;
    c3_d6 = 3.0 * c3_o_b;
    c3_p_b = c3_j;
    c3_d7 = 3.0 * c3_p_b;
    if (c3_d6 == c3_d7) {
    } else {
      _SFD_RUNTIME_ERROR_MSGID(
        "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing");
    }

    c3_b_pZ[0] = c3_pZ[0];
    c3_b_pZ[1] = -c3_pZ[2];
    c3_b_pZ[2] = c3_pZ[1];
    for (c3_i40 = 0; c3_i40 < 3; c3_i40++) {
      c3_VrPos[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("VrPos", (int32_T)
        _SFD_INTEGER_CHECK("3*j-2:3*j", c3_d6 + (-2.0 + (real_T)c3_i40)), 1, 66,
        1, 0) - 1] = c3_b_pZ[c3_i40];
    }

    c3_b_j++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
  for (c3_i41 = 0; c3_i41 < 3; c3_i41++) {
    c3_pZ[c3_i41] = c3_PosPr[c3_i41];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 51);
  for (c3_i42 = 0; c3_i42 < 3; c3_i42++) {
    c3_a[c3_i42] = c3_pZ[c3_i42];
  }

  for (c3_i43 = 0; c3_i43 < 3; c3_i43++) {
    c3_a[c3_i43] *= 8.0;
  }

  for (c3_i44 = 0; c3_i44 < 3; c3_i44++) {
    c3_pZ[c3_i44] = c3_a[c3_i44] / 3.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 52);
  c3_c_pZ[0] = c3_pZ[0];
  c3_c_pZ[1] = -c3_pZ[2];
  c3_c_pZ[2] = c3_pZ[1];
  for (c3_i45 = 0; c3_i45 < 3; c3_i45++) {
    c3_VrPos[c3_i45 + 63] = c3_c_pZ[c3_i45];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 54);
  for (c3_i46 = 0; c3_i46 < 84; c3_i46++) {
    c3_y[c3_i46] = c3_VrAngle[c3_i46];
  }

  for (c3_i47 = 0; c3_i47 < 66; c3_i47++) {
    c3_y[c3_i47 + 84] = c3_VrPos[c3_i47];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -54);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i48 = 0; c3_i48 < 150; c3_i48++) {
    (*c3_k_y)[c3_i48] = c3_y[c3_i48];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
}

static void registerMessagesc3_Bowwave2Drogue_v6_addControl_test
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i49;
  real_T c3_b_inData[150];
  int32_T c3_i50;
  real_T c3_u[150];
  const mxArray *c3_y = NULL;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i49 = 0; c3_i49 < 150; c3_i49++) {
    c3_b_inData[c3_i49] = (*(real_T (*)[150])c3_inData)[c3_i49];
  }

  for (c3_i50 = 0; c3_i50 < 150; c3_i50++) {
    c3_u[c3_i50] = c3_b_inData[c3_i50];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 150), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_y, const char_T *c3_identifier, real_T c3_b_y[150])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_y), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_y);
}

static void c3_b_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[150])
{
  real_T c3_dv1[150];
  int32_T c3_i51;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 150);
  for (c3_i51 = 0; c3_i51 < 150; c3_i51++) {
    c3_y[c3_i51] = c3_dv1[c3_i51];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_y;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y[150];
  int32_T c3_i52;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_y = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_y), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_y);
  for (c3_i52 = 0; c3_i52 < 150; c3_i52++) {
    (*(real_T (*)[150])c3_outData)[c3_i52] = c3_b_y[c3_i52];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i53;
  real_T c3_b_inData[100];
  int32_T c3_i54;
  real_T c3_u[100];
  const mxArray *c3_y = NULL;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i53 = 0; c3_i53 < 100; c3_i53++) {
    c3_b_inData[c3_i53] = (*(real_T (*)[100])c3_inData)[c3_i53];
  }

  for (c3_i54 = 0; c3_i54 < 100; c3_i54++) {
    c3_u[c3_i54] = c3_b_inData[c3_i54];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 100), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i55;
  real_T c3_b_inData[3];
  int32_T c3_i56;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i55 = 0; c3_i55 < 3; c3_i55++) {
    c3_b_inData[c3_i55] = (*(real_T (*)[3])c3_inData)[c3_i55];
  }

  for (c3_i56 = 0; c3_i56 < 3; c3_i56++) {
    c3_u[c3_i56] = c3_b_inData[c3_i56];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d8;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d8, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d8;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i57;
  real_T c3_b_inData[3];
  int32_T c3_i58;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i57 = 0; c3_i57 < 3; c3_i57++) {
    c3_b_inData[c3_i57] = (*(real_T (*)[3])c3_inData)[c3_i57];
  }

  for (c3_i58 = 0; c3_i58 < 3; c3_i58++) {
    c3_u[c3_i58] = c3_b_inData[c3_i58];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3])
{
  real_T c3_dv2[3];
  int32_T c3_i59;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c3_i59 = 0; c3_i59 < 3; c3_i59++) {
    c3_y[c3_i59] = c3_dv2[c3_i59];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_vRot;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i60;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_vRot = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_vRot), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_vRot);
  for (c3_i60 = 0; c3_i60 < 3; c3_i60++) {
    (*(real_T (*)[3])c3_outData)[c3_i60] = c3_y[c3_i60];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[9], int32_T c3_inData_sizes[2])
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_b_inData_sizes[2];
  int32_T c3_loop_ub;
  int32_T c3_i61;
  int32_T c3_i62;
  real_T c3_b_inData_data[9];
  int32_T c3_u_sizes[2];
  int32_T c3_b_loop_ub;
  int32_T c3_i63;
  int32_T c3_i64;
  real_T c3_u_data[9];
  const mxArray *c3_y = NULL;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_inData_sizes[0] = 3;
  c3_b_inData_sizes[1] = c3_inData_sizes[1];
  c3_loop_ub = c3_inData_sizes[1] - 1;
  for (c3_i61 = 0; c3_i61 <= c3_loop_ub; c3_i61++) {
    for (c3_i62 = 0; c3_i62 < 3; c3_i62++) {
      c3_b_inData_data[c3_i62 + c3_b_inData_sizes[0] * c3_i61] =
        c3_inData_data[c3_i62 + c3_inData_sizes[0] * c3_i61];
    }
  }

  c3_u_sizes[0] = 3;
  c3_u_sizes[1] = c3_b_inData_sizes[1];
  c3_b_loop_ub = c3_b_inData_sizes[1] - 1;
  for (c3_i63 = 0; c3_i63 <= c3_b_loop_ub; c3_i63++) {
    for (c3_i64 = 0; c3_i64 < 3; c3_i64++) {
      c3_u_data[c3_i64 + c3_u_sizes[0] * c3_i63] = c3_b_inData_data[c3_i64 +
        c3_b_inData_sizes[0] * c3_i63];
    }
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 0, 0U, 1U, 0U, 2,
    c3_u_sizes[0], c3_u_sizes[1]), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_e_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y_data[9],
   int32_T c3_y_sizes[2])
{
  int32_T c3_i65;
  uint32_T c3_uv0[2];
  int32_T c3_i66;
  static boolean_T c3_bv0[2] = { FALSE, TRUE };

  boolean_T c3_bv1[2];
  int32_T c3_tmp_sizes[2];
  real_T c3_tmp_data[9];
  int32_T c3_y;
  int32_T c3_b_y;
  int32_T c3_loop_ub;
  int32_T c3_i67;
  for (c3_i65 = 0; c3_i65 < 2; c3_i65++) {
    c3_uv0[c3_i65] = 3U;
  }

  for (c3_i66 = 0; c3_i66 < 2; c3_i66++) {
    c3_bv1[c3_i66] = c3_bv0[c3_i66];
  }

  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 1, 0, 0U, 1, 0U,
                   2, c3_bv1, c3_uv0, c3_tmp_sizes);
  c3_y_sizes[0] = 3;
  c3_y_sizes[1] = c3_tmp_sizes[1];
  c3_y = c3_y_sizes[0];
  c3_b_y = c3_y_sizes[1];
  c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i67 = 0; c3_i67 <= c3_loop_ub; c3_i67++) {
    c3_y_data[c3_i67] = c3_tmp_data[c3_i67];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[9],
  int32_T c3_outData_sizes[2])
{
  const mxArray *c3_axis1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y_sizes[2];
  real_T c3_y_data[9];
  int32_T c3_loop_ub;
  int32_T c3_i68;
  int32_T c3_i69;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_axis1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_axis1), &c3_thisId,
                        c3_y_data, c3_y_sizes);
  sf_mex_destroy(&c3_axis1);
  c3_outData_sizes[0] = 3;
  c3_outData_sizes[1] = c3_y_sizes[1];
  c3_loop_ub = c3_y_sizes[1] - 1;
  for (c3_i68 = 0; c3_i68 <= c3_loop_ub; c3_i68++) {
    for (c3_i69 = 0; c3_i69 < 3; c3_i69++) {
      c3_outData_data[c3_i69 + c3_outData_sizes[0] * c3_i68] = c3_y_data[c3_i69
        + c3_y_sizes[0] * c3_i68];
    }
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_f_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3])
{
  real_T c3_dv3[3];
  int32_T c3_i70;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i70 = 0; c3_i70 < 3; c3_i70++) {
    c3_y[c3_i70] = c3_dv3[c3_i70];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_vTb;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i71;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_vTb = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_vTb), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_vTb);
  for (c3_i71 = 0; c3_i71 < 3; c3_i71++) {
    (*(real_T (*)[3])c3_outData)[c3_i71] = c3_y[c3_i71];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i72;
  real_T c3_b_inData[66];
  int32_T c3_i73;
  real_T c3_u[66];
  const mxArray *c3_y = NULL;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i72 = 0; c3_i72 < 66; c3_i72++) {
    c3_b_inData[c3_i72] = (*(real_T (*)[66])c3_inData)[c3_i72];
  }

  for (c3_i73 = 0; c3_i73 < 66; c3_i73++) {
    c3_u[c3_i73] = c3_b_inData[c3_i73];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 66), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_g_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[66])
{
  real_T c3_dv4[66];
  int32_T c3_i74;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv4, 1, 0, 0U, 1, 0U, 1, 66);
  for (c3_i74 = 0; c3_i74 < 66; c3_i74++) {
    c3_y[c3_i74] = c3_dv4[c3_i74];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_VrPos;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[66];
  int32_T c3_i75;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_VrPos = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_VrPos), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_VrPos);
  for (c3_i75 = 0; c3_i75 < 66; c3_i75++) {
    (*(real_T (*)[66])c3_outData)[c3_i75] = c3_y[c3_i75];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i76;
  real_T c3_b_inData[84];
  int32_T c3_i77;
  real_T c3_u[84];
  const mxArray *c3_y = NULL;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i76 = 0; c3_i76 < 84; c3_i76++) {
    c3_b_inData[c3_i76] = (*(real_T (*)[84])c3_inData)[c3_i76];
  }

  for (c3_i77 = 0; c3_i77 < 84; c3_i77++) {
    c3_u[c3_i77] = c3_b_inData[c3_i77];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 84), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_h_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[84])
{
  real_T c3_dv5[84];
  int32_T c3_i78;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv5, 1, 0, 0U, 1, 0U, 1, 84);
  for (c3_i78 = 0; c3_i78 < 84; c3_i78++) {
    c3_y[c3_i78] = c3_dv5[c3_i78];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_VrAngle;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[84];
  int32_T c3_i79;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_VrAngle = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_VrAngle), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_VrAngle);
  for (c3_i79 = 0; c3_i79 < 84; c3_i79++) {
    (*(real_T (*)[84])c3_outData)[c3_i79] = c3_y[c3_i79];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i80;
  real_T c3_b_inData[60];
  int32_T c3_i81;
  real_T c3_u[60];
  const mxArray *c3_y = NULL;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i80 = 0; c3_i80 < 60; c3_i80++) {
    c3_b_inData[c3_i80] = (*(real_T (*)[60])c3_inData)[c3_i80];
  }

  for (c3_i81 = 0; c3_i81 < 60; c3_i81++) {
    c3_u[c3_i81] = c3_b_inData[c3_i81];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 60), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_i_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[60])
{
  real_T c3_dv6[60];
  int32_T c3_i82;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv6, 1, 0, 0U, 1, 0U, 1, 60);
  for (c3_i82 = 0; c3_i82 < 60; c3_i82++) {
    c3_y[c3_i82] = c3_dv6[c3_i82];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_PosTb;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[60];
  int32_T c3_i83;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_PosTb = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_PosTb), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_PosTb);
  for (c3_i83 = 0; c3_i83 < 60; c3_i83++) {
    (*(real_T (*)[60])c3_outData)[c3_i83] = c3_y[c3_i83];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray
  *sf_c3_Bowwave2Drogue_v6_addControl_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[161];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i84;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  c3_b_info_helper(c3_info);
  c3_c_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 161), FALSE);
  for (c3_i84 = 0; c3_i84 < 161; c3_i84++) {
    c3_r0 = &c3_info[c3_i84];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i84);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i84);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i84);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i84);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i84);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i84);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i84);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i84);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[161])
{
  c3_info[0].context = "";
  c3_info[0].name = "mtimes";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[0].fileTimeLo = 1289494492U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "";
  c3_info[1].name = "mrdivide";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[1].fileTimeLo = 1357926348U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 1319708366U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[2].name = "rdivide";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[2].fileTimeLo = 1346488788U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[3].name = "eml_scalexp_compatible";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c3_info[3].fileTimeLo = 1286797196U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[4].name = "eml_div";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[4].fileTimeLo = 1313326210U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context = "";
  c3_info[5].name = "cos";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[5].fileTimeLo = 1343808772U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[6].name = "eml_scalar_cos";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[6].fileTimeLo = 1286797122U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "";
  c3_info[7].name = "sin";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[7].fileTimeLo = 1343808786U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[8].name = "eml_scalar_sin";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c3_info[8].fileTimeLo = 1286797136U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context = "";
  c3_info[9].name = "null";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/null.m";
  c3_info[9].fileTimeLo = 1286797226U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/null.m";
  c3_info[10].name = "svd";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c3_info[10].fileTimeLo = 1286797232U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c3_info[11].name = "eml_index_class";
  c3_info[11].dominantType = "";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[11].fileTimeLo = 1323145378U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c3_info[12].name = "eml_int_forloop_overflow_check";
  c3_info[12].dominantType = "";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[12].fileTimeLo = 1346488740U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c3_info[13].name = "intmax";
  c3_info[13].dominantType = "char";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[13].fileTimeLo = 1311233716U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c3_info[14].name = "isfinite";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c3_info[14].fileTimeLo = 1286797158U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c3_info[15].name = "isinf";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c3_info[15].fileTimeLo = 1286797160U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c3_info[16].name = "isnan";
  c3_info[16].dominantType = "double";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[16].fileTimeLo = 1286797160U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c3_info[17].name = "eml_error";
  c3_info[17].dominantType = "char";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[17].fileTimeLo = 1343808758U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c3_info[18].name = "eml_xgesvd";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c3_info[18].fileTimeLo = 1286797206U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c3_info[19].name = "eml_lapack_xgesvd";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c3_info[19].fileTimeLo = 1286797210U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c3_info[20].name = "eml_matlab_zsvdc";
  c3_info[20].dominantType = "double";
  c3_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[20].fileTimeLo = 1295259666U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[21].name = "eml_index_class";
  c3_info[21].dominantType = "";
  c3_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[21].fileTimeLo = 1323145378U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[22].name = "eml_scalar_eg";
  c3_info[22].dominantType = "double";
  c3_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[22].fileTimeLo = 1286797196U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[23].name = "eml_index_plus";
  c3_info[23].dominantType = "double";
  c3_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[23].fileTimeLo = 1286797178U;
  c3_info[23].fileTimeHi = 0U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[24].name = "eml_index_class";
  c3_info[24].dominantType = "";
  c3_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[24].fileTimeLo = 1323145378U;
  c3_info[24].fileTimeHi = 0U;
  c3_info[24].mFileTimeLo = 0U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[25].name = "min";
  c3_info[25].dominantType = "coder.internal.indexInt";
  c3_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[25].fileTimeLo = 1311233718U;
  c3_info[25].fileTimeHi = 0U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
  c3_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[26].name = "eml_min_or_max";
  c3_info[26].dominantType = "char";
  c3_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[26].fileTimeLo = 1334049890U;
  c3_info[26].fileTimeHi = 0U;
  c3_info[26].mFileTimeLo = 0U;
  c3_info[26].mFileTimeHi = 0U;
  c3_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[27].name = "eml_scalar_eg";
  c3_info[27].dominantType = "coder.internal.indexInt";
  c3_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[27].fileTimeLo = 1286797196U;
  c3_info[27].fileTimeHi = 0U;
  c3_info[27].mFileTimeLo = 0U;
  c3_info[27].mFileTimeHi = 0U;
  c3_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[28].name = "eml_scalexp_alloc";
  c3_info[28].dominantType = "coder.internal.indexInt";
  c3_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[28].fileTimeLo = 1352399660U;
  c3_info[28].fileTimeHi = 0U;
  c3_info[28].mFileTimeLo = 0U;
  c3_info[28].mFileTimeHi = 0U;
  c3_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[29].name = "eml_index_class";
  c3_info[29].dominantType = "";
  c3_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[29].fileTimeLo = 1323145378U;
  c3_info[29].fileTimeHi = 0U;
  c3_info[29].mFileTimeLo = 0U;
  c3_info[29].mFileTimeHi = 0U;
  c3_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c3_info[30].name = "eml_scalar_eg";
  c3_info[30].dominantType = "coder.internal.indexInt";
  c3_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[30].fileTimeLo = 1286797196U;
  c3_info[30].fileTimeHi = 0U;
  c3_info[30].mFileTimeLo = 0U;
  c3_info[30].mFileTimeHi = 0U;
  c3_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[31].name = "max";
  c3_info[31].dominantType = "double";
  c3_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[31].fileTimeLo = 1311233716U;
  c3_info[31].fileTimeHi = 0U;
  c3_info[31].mFileTimeLo = 0U;
  c3_info[31].mFileTimeHi = 0U;
  c3_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[32].name = "eml_min_or_max";
  c3_info[32].dominantType = "char";
  c3_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[32].fileTimeLo = 1334049890U;
  c3_info[32].fileTimeHi = 0U;
  c3_info[32].mFileTimeLo = 0U;
  c3_info[32].mFileTimeHi = 0U;
  c3_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[33].name = "eml_scalar_eg";
  c3_info[33].dominantType = "double";
  c3_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[33].fileTimeLo = 1286797196U;
  c3_info[33].fileTimeHi = 0U;
  c3_info[33].mFileTimeLo = 0U;
  c3_info[33].mFileTimeHi = 0U;
  c3_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[34].name = "eml_scalexp_alloc";
  c3_info[34].dominantType = "double";
  c3_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[34].fileTimeLo = 1352399660U;
  c3_info[34].fileTimeHi = 0U;
  c3_info[34].mFileTimeLo = 0U;
  c3_info[34].mFileTimeHi = 0U;
  c3_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c3_info[35].name = "eml_scalar_eg";
  c3_info[35].dominantType = "double";
  c3_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[35].fileTimeLo = 1286797196U;
  c3_info[35].fileTimeHi = 0U;
  c3_info[35].mFileTimeLo = 0U;
  c3_info[35].mFileTimeHi = 0U;
  c3_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c3_info[36].name = "eml_relop";
  c3_info[36].dominantType = "function_handle";
  c3_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c3_info[36].fileTimeLo = 1342429582U;
  c3_info[36].fileTimeHi = 0U;
  c3_info[36].mFileTimeLo = 0U;
  c3_info[36].mFileTimeHi = 0U;
  c3_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c3_info[37].name = "coder.internal.indexIntRelop";
  c3_info[37].dominantType = "";
  c3_info[37].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c3_info[37].fileTimeLo = 1326703122U;
  c3_info[37].fileTimeHi = 0U;
  c3_info[37].mFileTimeLo = 0U;
  c3_info[37].mFileTimeHi = 0U;
  c3_info[38].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c3_info[38].name = "eml_float_model";
  c3_info[38].dominantType = "char";
  c3_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c3_info[38].fileTimeLo = 1326702796U;
  c3_info[38].fileTimeHi = 0U;
  c3_info[38].mFileTimeLo = 0U;
  c3_info[38].mFileTimeHi = 0U;
  c3_info[39].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c3_info[39].name = "intmin";
  c3_info[39].dominantType = "char";
  c3_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c3_info[39].fileTimeLo = 1311233718U;
  c3_info[39].fileTimeHi = 0U;
  c3_info[39].mFileTimeLo = 0U;
  c3_info[39].mFileTimeHi = 0U;
  c3_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c3_info[40].name = "isnan";
  c3_info[40].dominantType = "coder.internal.indexInt";
  c3_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[40].fileTimeLo = 1286797160U;
  c3_info[40].fileTimeHi = 0U;
  c3_info[40].mFileTimeLo = 0U;
  c3_info[40].mFileTimeHi = 0U;
  c3_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[41].name = "eml_index_minus";
  c3_info[41].dominantType = "double";
  c3_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[41].fileTimeLo = 1286797178U;
  c3_info[41].fileTimeHi = 0U;
  c3_info[41].mFileTimeLo = 0U;
  c3_info[41].mFileTimeHi = 0U;
  c3_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[42].name = "eml_index_class";
  c3_info[42].dominantType = "";
  c3_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[42].fileTimeLo = 1323145378U;
  c3_info[42].fileTimeHi = 0U;
  c3_info[42].mFileTimeLo = 0U;
  c3_info[42].mFileTimeHi = 0U;
  c3_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[43].name = "max";
  c3_info[43].dominantType = "coder.internal.indexInt";
  c3_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[43].fileTimeLo = 1311233716U;
  c3_info[43].fileTimeHi = 0U;
  c3_info[43].mFileTimeLo = 0U;
  c3_info[43].mFileTimeHi = 0U;
  c3_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[44].name = "eml_index_times";
  c3_info[44].dominantType = "coder.internal.indexInt";
  c3_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[44].fileTimeLo = 1286797180U;
  c3_info[44].fileTimeHi = 0U;
  c3_info[44].mFileTimeLo = 0U;
  c3_info[44].mFileTimeHi = 0U;
  c3_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[45].name = "eml_index_class";
  c3_info[45].dominantType = "";
  c3_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[45].fileTimeLo = 1323145378U;
  c3_info[45].fileTimeHi = 0U;
  c3_info[45].mFileTimeLo = 0U;
  c3_info[45].mFileTimeHi = 0U;
  c3_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[46].name = "eml_index_plus";
  c3_info[46].dominantType = "coder.internal.indexInt";
  c3_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[46].fileTimeLo = 1286797178U;
  c3_info[46].fileTimeHi = 0U;
  c3_info[46].mFileTimeLo = 0U;
  c3_info[46].mFileTimeHi = 0U;
  c3_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[47].name = "eml_index_minus";
  c3_info[47].dominantType = "coder.internal.indexInt";
  c3_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[47].fileTimeLo = 1286797178U;
  c3_info[47].fileTimeHi = 0U;
  c3_info[47].mFileTimeLo = 0U;
  c3_info[47].mFileTimeHi = 0U;
  c3_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[48].name = "eml_xnrm2";
  c3_info[48].dominantType = "double";
  c3_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c3_info[48].fileTimeLo = 1299051576U;
  c3_info[48].fileTimeHi = 0U;
  c3_info[48].mFileTimeLo = 0U;
  c3_info[48].mFileTimeHi = 0U;
  c3_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c3_info[49].name = "eml_blas_inline";
  c3_info[49].dominantType = "";
  c3_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[49].fileTimeLo = 1299051568U;
  c3_info[49].fileTimeHi = 0U;
  c3_info[49].mFileTimeLo = 0U;
  c3_info[49].mFileTimeHi = 0U;
  c3_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c3_info[50].name = "eml_index_class";
  c3_info[50].dominantType = "";
  c3_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[50].fileTimeLo = 1323145378U;
  c3_info[50].fileTimeHi = 0U;
  c3_info[50].mFileTimeLo = 0U;
  c3_info[50].mFileTimeHi = 0U;
  c3_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c3_info[51].name = "eml_refblas_xnrm2";
  c3_info[51].dominantType = "double";
  c3_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[51].fileTimeLo = 1299051584U;
  c3_info[51].fileTimeHi = 0U;
  c3_info[51].mFileTimeLo = 0U;
  c3_info[51].mFileTimeHi = 0U;
  c3_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[52].name = "realmin";
  c3_info[52].dominantType = "char";
  c3_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c3_info[52].fileTimeLo = 1307629642U;
  c3_info[52].fileTimeHi = 0U;
  c3_info[52].mFileTimeLo = 0U;
  c3_info[52].mFileTimeHi = 0U;
  c3_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c3_info[53].name = "eml_realmin";
  c3_info[53].dominantType = "char";
  c3_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c3_info[53].fileTimeLo = 1307629644U;
  c3_info[53].fileTimeHi = 0U;
  c3_info[53].mFileTimeLo = 0U;
  c3_info[53].mFileTimeHi = 0U;
  c3_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c3_info[54].name = "eml_float_model";
  c3_info[54].dominantType = "char";
  c3_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c3_info[54].fileTimeLo = 1326702796U;
  c3_info[54].fileTimeHi = 0U;
  c3_info[54].mFileTimeLo = 0U;
  c3_info[54].mFileTimeHi = 0U;
  c3_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[55].name = "eml_index_class";
  c3_info[55].dominantType = "";
  c3_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[55].fileTimeLo = 1323145378U;
  c3_info[55].fileTimeHi = 0U;
  c3_info[55].mFileTimeLo = 0U;
  c3_info[55].mFileTimeHi = 0U;
  c3_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[56].name = "eml_index_minus";
  c3_info[56].dominantType = "double";
  c3_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[56].fileTimeLo = 1286797178U;
  c3_info[56].fileTimeHi = 0U;
  c3_info[56].mFileTimeLo = 0U;
  c3_info[56].mFileTimeHi = 0U;
  c3_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[57].name = "eml_index_times";
  c3_info[57].dominantType = "coder.internal.indexInt";
  c3_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[57].fileTimeLo = 1286797180U;
  c3_info[57].fileTimeHi = 0U;
  c3_info[57].mFileTimeLo = 0U;
  c3_info[57].mFileTimeHi = 0U;
  c3_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[58].name = "eml_index_plus";
  c3_info[58].dominantType = "coder.internal.indexInt";
  c3_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[58].fileTimeLo = 1286797178U;
  c3_info[58].fileTimeHi = 0U;
  c3_info[58].mFileTimeLo = 0U;
  c3_info[58].mFileTimeHi = 0U;
  c3_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[59].name = "eml_int_forloop_overflow_check";
  c3_info[59].dominantType = "";
  c3_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[59].fileTimeLo = 1346488740U;
  c3_info[59].fileTimeHi = 0U;
  c3_info[59].mFileTimeLo = 0U;
  c3_info[59].mFileTimeHi = 0U;
  c3_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[60].name = "abs";
  c3_info[60].dominantType = "double";
  c3_info[60].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[60].fileTimeLo = 1343808766U;
  c3_info[60].fileTimeHi = 0U;
  c3_info[60].mFileTimeLo = 0U;
  c3_info[60].mFileTimeHi = 0U;
  c3_info[61].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[61].name = "eml_scalar_abs";
  c3_info[61].dominantType = "double";
  c3_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[61].fileTimeLo = 1286797112U;
  c3_info[61].fileTimeHi = 0U;
  c3_info[61].mFileTimeLo = 0U;
  c3_info[61].mFileTimeHi = 0U;
  c3_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[62].name = "eml_div";
  c3_info[62].dominantType = "double";
  c3_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[62].fileTimeLo = 1313326210U;
  c3_info[62].fileTimeHi = 0U;
  c3_info[62].mFileTimeLo = 0U;
  c3_info[62].mFileTimeHi = 0U;
  c3_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[63].name = "eml_xscal";
  c3_info[63].dominantType = "double";
  c3_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c3_info[63].fileTimeLo = 1299051576U;
  c3_info[63].fileTimeHi = 0U;
  c3_info[63].mFileTimeLo = 0U;
  c3_info[63].mFileTimeHi = 0U;
}

static void c3_b_info_helper(c3_ResolvedFunctionInfo c3_info[161])
{
  c3_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c3_info[64].name = "eml_blas_inline";
  c3_info[64].dominantType = "";
  c3_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[64].fileTimeLo = 1299051568U;
  c3_info[64].fileTimeHi = 0U;
  c3_info[64].mFileTimeLo = 0U;
  c3_info[64].mFileTimeHi = 0U;
  c3_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c3_info[65].name = "eml_index_class";
  c3_info[65].dominantType = "";
  c3_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[65].fileTimeLo = 1323145378U;
  c3_info[65].fileTimeHi = 0U;
  c3_info[65].mFileTimeLo = 0U;
  c3_info[65].mFileTimeHi = 0U;
  c3_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c3_info[66].name = "eml_scalar_eg";
  c3_info[66].dominantType = "double";
  c3_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[66].fileTimeLo = 1286797196U;
  c3_info[66].fileTimeHi = 0U;
  c3_info[66].mFileTimeLo = 0U;
  c3_info[66].mFileTimeHi = 0U;
  c3_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c3_info[67].name = "eml_refblas_xscal";
  c3_info[67].dominantType = "double";
  c3_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c3_info[67].fileTimeLo = 1299051584U;
  c3_info[67].fileTimeHi = 0U;
  c3_info[67].mFileTimeLo = 0U;
  c3_info[67].mFileTimeHi = 0U;
  c3_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c3_info[68].name = "eml_index_class";
  c3_info[68].dominantType = "";
  c3_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[68].fileTimeLo = 1323145378U;
  c3_info[68].fileTimeHi = 0U;
  c3_info[68].mFileTimeLo = 0U;
  c3_info[68].mFileTimeHi = 0U;
  c3_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c3_info[69].name = "eml_index_minus";
  c3_info[69].dominantType = "double";
  c3_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[69].fileTimeLo = 1286797178U;
  c3_info[69].fileTimeHi = 0U;
  c3_info[69].mFileTimeLo = 0U;
  c3_info[69].mFileTimeHi = 0U;
  c3_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c3_info[70].name = "eml_index_times";
  c3_info[70].dominantType = "coder.internal.indexInt";
  c3_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[70].fileTimeLo = 1286797180U;
  c3_info[70].fileTimeHi = 0U;
  c3_info[70].mFileTimeLo = 0U;
  c3_info[70].mFileTimeHi = 0U;
  c3_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c3_info[71].name = "eml_index_plus";
  c3_info[71].dominantType = "coder.internal.indexInt";
  c3_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[71].fileTimeLo = 1286797178U;
  c3_info[71].fileTimeHi = 0U;
  c3_info[71].mFileTimeLo = 0U;
  c3_info[71].mFileTimeHi = 0U;
  c3_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c3_info[72].name = "eml_int_forloop_overflow_check";
  c3_info[72].dominantType = "";
  c3_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[72].fileTimeLo = 1346488740U;
  c3_info[72].fileTimeHi = 0U;
  c3_info[72].mFileTimeLo = 0U;
  c3_info[72].mFileTimeHi = 0U;
  c3_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[73].name = "eml_int_forloop_overflow_check";
  c3_info[73].dominantType = "";
  c3_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[73].fileTimeLo = 1346488740U;
  c3_info[73].fileTimeHi = 0U;
  c3_info[73].mFileTimeLo = 0U;
  c3_info[73].mFileTimeHi = 0U;
  c3_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[74].name = "eml_xdotc";
  c3_info[74].dominantType = "double";
  c3_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c3_info[74].fileTimeLo = 1299051572U;
  c3_info[74].fileTimeHi = 0U;
  c3_info[74].mFileTimeLo = 0U;
  c3_info[74].mFileTimeHi = 0U;
  c3_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c3_info[75].name = "eml_blas_inline";
  c3_info[75].dominantType = "";
  c3_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[75].fileTimeLo = 1299051568U;
  c3_info[75].fileTimeHi = 0U;
  c3_info[75].mFileTimeLo = 0U;
  c3_info[75].mFileTimeHi = 0U;
  c3_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c3_info[76].name = "eml_xdot";
  c3_info[76].dominantType = "double";
  c3_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[76].fileTimeLo = 1299051572U;
  c3_info[76].fileTimeHi = 0U;
  c3_info[76].mFileTimeLo = 0U;
  c3_info[76].mFileTimeHi = 0U;
  c3_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[77].name = "eml_blas_inline";
  c3_info[77].dominantType = "";
  c3_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[77].fileTimeLo = 1299051568U;
  c3_info[77].fileTimeHi = 0U;
  c3_info[77].mFileTimeLo = 0U;
  c3_info[77].mFileTimeHi = 0U;
  c3_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c3_info[78].name = "eml_index_class";
  c3_info[78].dominantType = "";
  c3_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[78].fileTimeLo = 1323145378U;
  c3_info[78].fileTimeHi = 0U;
  c3_info[78].mFileTimeLo = 0U;
  c3_info[78].mFileTimeHi = 0U;
  c3_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c3_info[79].name = "eml_refblas_xdot";
  c3_info[79].dominantType = "double";
  c3_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[79].fileTimeLo = 1299051572U;
  c3_info[79].fileTimeHi = 0U;
  c3_info[79].mFileTimeLo = 0U;
  c3_info[79].mFileTimeHi = 0U;
  c3_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[80].name = "eml_refblas_xdotx";
  c3_info[80].dominantType = "char";
  c3_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[80].fileTimeLo = 1299051574U;
  c3_info[80].fileTimeHi = 0U;
  c3_info[80].mFileTimeLo = 0U;
  c3_info[80].mFileTimeHi = 0U;
  c3_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[81].name = "eml_scalar_eg";
  c3_info[81].dominantType = "double";
  c3_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[81].fileTimeLo = 1286797196U;
  c3_info[81].fileTimeHi = 0U;
  c3_info[81].mFileTimeLo = 0U;
  c3_info[81].mFileTimeHi = 0U;
  c3_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[82].name = "eml_index_class";
  c3_info[82].dominantType = "";
  c3_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[82].fileTimeLo = 1323145378U;
  c3_info[82].fileTimeHi = 0U;
  c3_info[82].mFileTimeLo = 0U;
  c3_info[82].mFileTimeHi = 0U;
  c3_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[83].name = "eml_int_forloop_overflow_check";
  c3_info[83].dominantType = "";
  c3_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[83].fileTimeLo = 1346488740U;
  c3_info[83].fileTimeHi = 0U;
  c3_info[83].mFileTimeLo = 0U;
  c3_info[83].mFileTimeHi = 0U;
  c3_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[84].name = "eml_index_plus";
  c3_info[84].dominantType = "coder.internal.indexInt";
  c3_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[84].fileTimeLo = 1286797178U;
  c3_info[84].fileTimeHi = 0U;
  c3_info[84].mFileTimeLo = 0U;
  c3_info[84].mFileTimeHi = 0U;
  c3_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[85].name = "eml_xaxpy";
  c3_info[85].dominantType = "double";
  c3_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c3_info[85].fileTimeLo = 1299051570U;
  c3_info[85].fileTimeHi = 0U;
  c3_info[85].mFileTimeLo = 0U;
  c3_info[85].mFileTimeHi = 0U;
  c3_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c3_info[86].name = "eml_blas_inline";
  c3_info[86].dominantType = "";
  c3_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[86].fileTimeLo = 1299051568U;
  c3_info[86].fileTimeHi = 0U;
  c3_info[86].mFileTimeLo = 0U;
  c3_info[86].mFileTimeHi = 0U;
  c3_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c3_info[87].name = "eml_index_class";
  c3_info[87].dominantType = "";
  c3_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[87].fileTimeLo = 1323145378U;
  c3_info[87].fileTimeHi = 0U;
  c3_info[87].mFileTimeLo = 0U;
  c3_info[87].mFileTimeHi = 0U;
  c3_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c3_info[88].name = "eml_scalar_eg";
  c3_info[88].dominantType = "double";
  c3_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[88].fileTimeLo = 1286797196U;
  c3_info[88].fileTimeHi = 0U;
  c3_info[88].mFileTimeLo = 0U;
  c3_info[88].mFileTimeHi = 0U;
  c3_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c3_info[89].name = "eml_refblas_xaxpy";
  c3_info[89].dominantType = "double";
  c3_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c3_info[89].fileTimeLo = 1299051572U;
  c3_info[89].fileTimeHi = 0U;
  c3_info[89].mFileTimeLo = 0U;
  c3_info[89].mFileTimeHi = 0U;
  c3_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c3_info[90].name = "eml_index_class";
  c3_info[90].dominantType = "";
  c3_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[90].fileTimeLo = 1323145378U;
  c3_info[90].fileTimeHi = 0U;
  c3_info[90].mFileTimeLo = 0U;
  c3_info[90].mFileTimeHi = 0U;
  c3_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c3_info[91].name = "eml_isa_uint";
  c3_info[91].dominantType = "coder.internal.indexInt";
  c3_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c3_info[91].fileTimeLo = 1286797184U;
  c3_info[91].fileTimeHi = 0U;
  c3_info[91].mFileTimeLo = 0U;
  c3_info[91].mFileTimeHi = 0U;
  c3_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c3_info[92].name = "eml_index_minus";
  c3_info[92].dominantType = "double";
  c3_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[92].fileTimeLo = 1286797178U;
  c3_info[92].fileTimeHi = 0U;
  c3_info[92].mFileTimeLo = 0U;
  c3_info[92].mFileTimeHi = 0U;
  c3_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c3_info[93].name = "eml_int_forloop_overflow_check";
  c3_info[93].dominantType = "";
  c3_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[93].fileTimeLo = 1346488740U;
  c3_info[93].fileTimeHi = 0U;
  c3_info[93].mFileTimeLo = 0U;
  c3_info[93].mFileTimeHi = 0U;
  c3_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c3_info[94].name = "eml_index_plus";
  c3_info[94].dominantType = "double";
  c3_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[94].fileTimeLo = 1286797178U;
  c3_info[94].fileTimeHi = 0U;
  c3_info[94].mFileTimeLo = 0U;
  c3_info[94].mFileTimeHi = 0U;
  c3_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c3_info[95].name = "eml_index_plus";
  c3_info[95].dominantType = "coder.internal.indexInt";
  c3_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[95].fileTimeLo = 1286797178U;
  c3_info[95].fileTimeHi = 0U;
  c3_info[95].mFileTimeLo = 0U;
  c3_info[95].mFileTimeHi = 0U;
  c3_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c3_info[96].name = "intmin";
  c3_info[96].dominantType = "char";
  c3_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c3_info[96].fileTimeLo = 1311233718U;
  c3_info[96].fileTimeHi = 0U;
  c3_info[96].mFileTimeLo = 0U;
  c3_info[96].mFileTimeHi = 0U;
  c3_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold";
  c3_info[97].name = "length";
  c3_info[97].dominantType = "double";
  c3_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c3_info[97].fileTimeLo = 1303124606U;
  c3_info[97].fileTimeHi = 0U;
  c3_info[97].mFileTimeLo = 0U;
  c3_info[97].mFileTimeHi = 0U;
  c3_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c3_info[98].name = "eml_index_class";
  c3_info[98].dominantType = "";
  c3_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[98].fileTimeLo = 1323145378U;
  c3_info[98].fileTimeHi = 0U;
  c3_info[98].mFileTimeLo = 0U;
  c3_info[98].mFileTimeHi = 0U;
  c3_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m!below_threshold";
  c3_info[99].name = "length";
  c3_info[99].dominantType = "double";
  c3_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c3_info[99].fileTimeLo = 1303124606U;
  c3_info[99].fileTimeHi = 0U;
  c3_info[99].mFileTimeLo = 0U;
  c3_info[99].mFileTimeHi = 0U;
  c3_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[100].name = "abs";
  c3_info[100].dominantType = "double";
  c3_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[100].fileTimeLo = 1343808766U;
  c3_info[100].fileTimeHi = 0U;
  c3_info[100].mFileTimeLo = 0U;
  c3_info[100].mFileTimeHi = 0U;
  c3_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[101].name = "mtimes";
  c3_info[101].dominantType = "double";
  c3_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[101].fileTimeLo = 1289494492U;
  c3_info[101].fileTimeHi = 0U;
  c3_info[101].mFileTimeLo = 0U;
  c3_info[101].mFileTimeHi = 0U;
  c3_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[102].name = "realmin";
  c3_info[102].dominantType = "char";
  c3_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c3_info[102].fileTimeLo = 1307629642U;
  c3_info[102].fileTimeHi = 0U;
  c3_info[102].mFileTimeLo = 0U;
  c3_info[102].mFileTimeHi = 0U;
  c3_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[103].name = "eps";
  c3_info[103].dominantType = "char";
  c3_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[103].fileTimeLo = 1326702796U;
  c3_info[103].fileTimeHi = 0U;
  c3_info[103].mFileTimeLo = 0U;
  c3_info[103].mFileTimeHi = 0U;
  c3_info[104].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[104].name = "eml_is_float_class";
  c3_info[104].dominantType = "char";
  c3_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[104].fileTimeLo = 1286797182U;
  c3_info[104].fileTimeHi = 0U;
  c3_info[104].mFileTimeLo = 0U;
  c3_info[104].mFileTimeHi = 0U;
  c3_info[105].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[105].name = "eml_eps";
  c3_info[105].dominantType = "char";
  c3_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c3_info[105].fileTimeLo = 1326702796U;
  c3_info[105].fileTimeHi = 0U;
  c3_info[105].mFileTimeLo = 0U;
  c3_info[105].mFileTimeHi = 0U;
  c3_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c3_info[106].name = "eml_float_model";
  c3_info[106].dominantType = "char";
  c3_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c3_info[106].fileTimeLo = 1326702796U;
  c3_info[106].fileTimeHi = 0U;
  c3_info[106].mFileTimeLo = 0U;
  c3_info[106].mFileTimeHi = 0U;
  c3_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[107].name = "eml_error";
  c3_info[107].dominantType = "char";
  c3_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[107].fileTimeLo = 1343808758U;
  c3_info[107].fileTimeHi = 0U;
  c3_info[107].mFileTimeLo = 0U;
  c3_info[107].mFileTimeHi = 0U;
  c3_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c3_info[108].name = "eml_const_nonsingleton_dim";
  c3_info[108].dominantType = "double";
  c3_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c3_info[108].fileTimeLo = 1286797096U;
  c3_info[108].fileTimeHi = 0U;
  c3_info[108].mFileTimeLo = 0U;
  c3_info[108].mFileTimeHi = 0U;
  c3_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c3_info[109].name = "eml_scalar_eg";
  c3_info[109].dominantType = "double";
  c3_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[109].fileTimeLo = 1286797196U;
  c3_info[109].fileTimeHi = 0U;
  c3_info[109].mFileTimeLo = 0U;
  c3_info[109].mFileTimeHi = 0U;
  c3_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c3_info[110].name = "eml_index_class";
  c3_info[110].dominantType = "";
  c3_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[110].fileTimeLo = 1323145378U;
  c3_info[110].fileTimeHi = 0U;
  c3_info[110].mFileTimeLo = 0U;
  c3_info[110].mFileTimeHi = 0U;
  c3_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[111].name = "eml_index_class";
  c3_info[111].dominantType = "";
  c3_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[111].fileTimeLo = 1323145378U;
  c3_info[111].fileTimeHi = 0U;
  c3_info[111].mFileTimeLo = 0U;
  c3_info[111].mFileTimeHi = 0U;
  c3_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[112].name = "isnan";
  c3_info[112].dominantType = "double";
  c3_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[112].fileTimeLo = 1286797160U;
  c3_info[112].fileTimeHi = 0U;
  c3_info[112].mFileTimeLo = 0U;
  c3_info[112].mFileTimeHi = 0U;
  c3_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[113].name = "eml_index_plus";
  c3_info[113].dominantType = "coder.internal.indexInt";
  c3_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[113].fileTimeLo = 1286797178U;
  c3_info[113].fileTimeHi = 0U;
  c3_info[113].mFileTimeLo = 0U;
  c3_info[113].mFileTimeHi = 0U;
  c3_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[114].name = "eml_int_forloop_overflow_check";
  c3_info[114].dominantType = "";
  c3_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[114].fileTimeLo = 1346488740U;
  c3_info[114].fileTimeHi = 0U;
  c3_info[114].mFileTimeLo = 0U;
  c3_info[114].mFileTimeHi = 0U;
  c3_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c3_info[115].name = "eml_relop";
  c3_info[115].dominantType = "function_handle";
  c3_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c3_info[115].fileTimeLo = 1342429582U;
  c3_info[115].fileTimeHi = 0U;
  c3_info[115].mFileTimeLo = 0U;
  c3_info[115].mFileTimeHi = 0U;
  c3_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[116].name = "sqrt";
  c3_info[116].dominantType = "double";
  c3_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[116].fileTimeLo = 1343808786U;
  c3_info[116].fileTimeHi = 0U;
  c3_info[116].mFileTimeLo = 0U;
  c3_info[116].mFileTimeHi = 0U;
  c3_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[117].name = "eml_error";
  c3_info[117].dominantType = "char";
  c3_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[117].fileTimeLo = 1343808758U;
  c3_info[117].fileTimeHi = 0U;
  c3_info[117].mFileTimeLo = 0U;
  c3_info[117].mFileTimeHi = 0U;
  c3_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[118].name = "eml_scalar_sqrt";
  c3_info[118].dominantType = "double";
  c3_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c3_info[118].fileTimeLo = 1286797138U;
  c3_info[118].fileTimeHi = 0U;
  c3_info[118].mFileTimeLo = 0U;
  c3_info[118].mFileTimeHi = 0U;
  c3_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[119].name = "eml_xrotg";
  c3_info[119].dominantType = "double";
  c3_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c3_info[119].fileTimeLo = 1299051576U;
  c3_info[119].fileTimeHi = 0U;
  c3_info[119].mFileTimeLo = 0U;
  c3_info[119].mFileTimeHi = 0U;
  c3_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c3_info[120].name = "eml_blas_inline";
  c3_info[120].dominantType = "";
  c3_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[120].fileTimeLo = 1299051568U;
  c3_info[120].fileTimeHi = 0U;
  c3_info[120].mFileTimeLo = 0U;
  c3_info[120].mFileTimeHi = 0U;
  c3_info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m";
  c3_info[121].name = "eml_refblas_xrotg";
  c3_info[121].dominantType = "double";
  c3_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c3_info[121].fileTimeLo = 1299051584U;
  c3_info[121].fileTimeHi = 0U;
  c3_info[121].mFileTimeLo = 0U;
  c3_info[121].mFileTimeHi = 0U;
  c3_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c3_info[122].name = "abs";
  c3_info[122].dominantType = "double";
  c3_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[122].fileTimeLo = 1343808766U;
  c3_info[122].fileTimeHi = 0U;
  c3_info[122].mFileTimeLo = 0U;
  c3_info[122].mFileTimeHi = 0U;
  c3_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c3_info[123].name = "mrdivide";
  c3_info[123].dominantType = "double";
  c3_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[123].fileTimeLo = 1357926348U;
  c3_info[123].fileTimeHi = 0U;
  c3_info[123].mFileTimeLo = 1319708366U;
  c3_info[123].mFileTimeHi = 0U;
  c3_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c3_info[124].name = "sqrt";
  c3_info[124].dominantType = "double";
  c3_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[124].fileTimeLo = 1343808786U;
  c3_info[124].fileTimeHi = 0U;
  c3_info[124].mFileTimeLo = 0U;
  c3_info[124].mFileTimeHi = 0U;
  c3_info[125].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m!eml_ceval_xrotg";
  c3_info[125].name = "eml_scalar_eg";
  c3_info[125].dominantType = "double";
  c3_info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[125].fileTimeLo = 1286797196U;
  c3_info[125].fileTimeHi = 0U;
  c3_info[125].mFileTimeLo = 0U;
  c3_info[125].mFileTimeHi = 0U;
  c3_info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[126].name = "eml_xrot";
  c3_info[126].dominantType = "double";
  c3_info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  c3_info[126].fileTimeLo = 1299051576U;
  c3_info[126].fileTimeHi = 0U;
  c3_info[126].mFileTimeLo = 0U;
  c3_info[126].mFileTimeHi = 0U;
  c3_info[127].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  c3_info[127].name = "eml_blas_inline";
  c3_info[127].dominantType = "";
  c3_info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[127].fileTimeLo = 1299051568U;
  c3_info[127].fileTimeHi = 0U;
  c3_info[127].mFileTimeLo = 0U;
  c3_info[127].mFileTimeHi = 0U;
}

static void c3_c_info_helper(c3_ResolvedFunctionInfo c3_info[161])
{
  c3_info[128].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c3_info[128].name = "eml_index_class";
  c3_info[128].dominantType = "";
  c3_info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[128].fileTimeLo = 1323145378U;
  c3_info[128].fileTimeHi = 0U;
  c3_info[128].mFileTimeLo = 0U;
  c3_info[128].mFileTimeHi = 0U;
  c3_info[129].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c3_info[129].name = "eml_scalar_eg";
  c3_info[129].dominantType = "double";
  c3_info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[129].fileTimeLo = 1286797196U;
  c3_info[129].fileTimeHi = 0U;
  c3_info[129].mFileTimeLo = 0U;
  c3_info[129].mFileTimeHi = 0U;
  c3_info[130].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c3_info[130].name = "eml_refblas_xrot";
  c3_info[130].dominantType = "double";
  c3_info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c3_info[130].fileTimeLo = 1299051584U;
  c3_info[130].fileTimeHi = 0U;
  c3_info[130].mFileTimeLo = 0U;
  c3_info[130].mFileTimeHi = 0U;
  c3_info[131].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c3_info[131].name = "eml_index_class";
  c3_info[131].dominantType = "";
  c3_info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[131].fileTimeLo = 1323145378U;
  c3_info[131].fileTimeHi = 0U;
  c3_info[131].mFileTimeLo = 0U;
  c3_info[131].mFileTimeHi = 0U;
  c3_info[132].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c3_info[132].name = "eml_int_forloop_overflow_check";
  c3_info[132].dominantType = "";
  c3_info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[132].fileTimeLo = 1346488740U;
  c3_info[132].fileTimeHi = 0U;
  c3_info[132].mFileTimeLo = 0U;
  c3_info[132].mFileTimeHi = 0U;
  c3_info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c3_info[133].name = "mtimes";
  c3_info[133].dominantType = "double";
  c3_info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[133].fileTimeLo = 1289494492U;
  c3_info[133].fileTimeHi = 0U;
  c3_info[133].mFileTimeLo = 0U;
  c3_info[133].mFileTimeHi = 0U;
  c3_info[134].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c3_info[134].name = "eml_index_plus";
  c3_info[134].dominantType = "coder.internal.indexInt";
  c3_info[134].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[134].fileTimeLo = 1286797178U;
  c3_info[134].fileTimeHi = 0U;
  c3_info[134].mFileTimeLo = 0U;
  c3_info[134].mFileTimeHi = 0U;
  c3_info[135].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c3_info[135].name = "eml_xswap";
  c3_info[135].dominantType = "double";
  c3_info[135].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c3_info[135].fileTimeLo = 1299051578U;
  c3_info[135].fileTimeHi = 0U;
  c3_info[135].mFileTimeLo = 0U;
  c3_info[135].mFileTimeHi = 0U;
  c3_info[136].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c3_info[136].name = "eml_blas_inline";
  c3_info[136].dominantType = "";
  c3_info[136].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[136].fileTimeLo = 1299051568U;
  c3_info[136].fileTimeHi = 0U;
  c3_info[136].mFileTimeLo = 0U;
  c3_info[136].mFileTimeHi = 0U;
  c3_info[137].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c3_info[137].name = "eml_index_class";
  c3_info[137].dominantType = "";
  c3_info[137].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[137].fileTimeLo = 1323145378U;
  c3_info[137].fileTimeHi = 0U;
  c3_info[137].mFileTimeLo = 0U;
  c3_info[137].mFileTimeHi = 0U;
  c3_info[138].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c3_info[138].name = "eml_refblas_xswap";
  c3_info[138].dominantType = "double";
  c3_info[138].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c3_info[138].fileTimeLo = 1299051586U;
  c3_info[138].fileTimeHi = 0U;
  c3_info[138].mFileTimeLo = 0U;
  c3_info[138].mFileTimeHi = 0U;
  c3_info[139].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c3_info[139].name = "eml_index_class";
  c3_info[139].dominantType = "";
  c3_info[139].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[139].fileTimeLo = 1323145378U;
  c3_info[139].fileTimeHi = 0U;
  c3_info[139].mFileTimeLo = 0U;
  c3_info[139].mFileTimeHi = 0U;
  c3_info[140].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c3_info[140].name = "abs";
  c3_info[140].dominantType = "coder.internal.indexInt";
  c3_info[140].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[140].fileTimeLo = 1343808766U;
  c3_info[140].fileTimeHi = 0U;
  c3_info[140].mFileTimeLo = 0U;
  c3_info[140].mFileTimeHi = 0U;
  c3_info[141].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[141].name = "eml_scalar_abs";
  c3_info[141].dominantType = "coder.internal.indexInt";
  c3_info[141].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[141].fileTimeLo = 1286797112U;
  c3_info[141].fileTimeHi = 0U;
  c3_info[141].mFileTimeLo = 0U;
  c3_info[141].mFileTimeHi = 0U;
  c3_info[142].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c3_info[142].name = "eml_int_forloop_overflow_check";
  c3_info[142].dominantType = "";
  c3_info[142].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[142].fileTimeLo = 1346488740U;
  c3_info[142].fileTimeHi = 0U;
  c3_info[142].mFileTimeLo = 0U;
  c3_info[142].mFileTimeHi = 0U;
  c3_info[143].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c3_info[143].name = "eml_index_plus";
  c3_info[143].dominantType = "coder.internal.indexInt";
  c3_info[143].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[143].fileTimeLo = 1286797178U;
  c3_info[143].fileTimeHi = 0U;
  c3_info[143].mFileTimeLo = 0U;
  c3_info[143].mFileTimeHi = 0U;
  c3_info[144].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/null.m";
  c3_info[144].name = "eml_index_class";
  c3_info[144].dominantType = "";
  c3_info[144].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[144].fileTimeLo = 1323145378U;
  c3_info[144].fileTimeHi = 0U;
  c3_info[144].mFileTimeLo = 0U;
  c3_info[144].mFileTimeHi = 0U;
  c3_info[145].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/null.m";
  c3_info[145].name = "min";
  c3_info[145].dominantType = "double";
  c3_info[145].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[145].fileTimeLo = 1311233718U;
  c3_info[145].fileTimeHi = 0U;
  c3_info[145].mFileTimeLo = 0U;
  c3_info[145].mFileTimeHi = 0U;
  c3_info[146].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/null.m";
  c3_info[146].name = "max";
  c3_info[146].dominantType = "double";
  c3_info[146].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[146].fileTimeLo = 1311233716U;
  c3_info[146].fileTimeHi = 0U;
  c3_info[146].mFileTimeLo = 0U;
  c3_info[146].mFileTimeHi = 0U;
  c3_info[147].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/null.m";
  c3_info[147].name = "mtimes";
  c3_info[147].dominantType = "double";
  c3_info[147].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[147].fileTimeLo = 1289494492U;
  c3_info[147].fileTimeHi = 0U;
  c3_info[147].mFileTimeLo = 0U;
  c3_info[147].mFileTimeHi = 0U;
  c3_info[148].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/null.m";
  c3_info[148].name = "eps";
  c3_info[148].dominantType = "char";
  c3_info[148].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[148].fileTimeLo = 1326702796U;
  c3_info[148].fileTimeHi = 0U;
  c3_info[148].mFileTimeLo = 0U;
  c3_info[148].mFileTimeHi = 0U;
  c3_info[149].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/null.m";
  c3_info[149].name = "eml_index_plus";
  c3_info[149].dominantType = "coder.internal.indexInt";
  c3_info[149].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[149].fileTimeLo = 1286797178U;
  c3_info[149].fileTimeHi = 0U;
  c3_info[149].mFileTimeLo = 0U;
  c3_info[149].mFileTimeHi = 0U;
  c3_info[150].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[150].name = "eml_index_class";
  c3_info[150].dominantType = "";
  c3_info[150].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[150].fileTimeLo = 1323145378U;
  c3_info[150].fileTimeHi = 0U;
  c3_info[150].mFileTimeLo = 0U;
  c3_info[150].mFileTimeHi = 0U;
  c3_info[151].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[151].name = "eml_scalar_eg";
  c3_info[151].dominantType = "double";
  c3_info[151].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[151].fileTimeLo = 1286797196U;
  c3_info[151].fileTimeHi = 0U;
  c3_info[151].mFileTimeLo = 0U;
  c3_info[151].mFileTimeHi = 0U;
  c3_info[152].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[152].name = "eml_xdotu";
  c3_info[152].dominantType = "double";
  c3_info[152].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[152].fileTimeLo = 1299051572U;
  c3_info[152].fileTimeHi = 0U;
  c3_info[152].mFileTimeLo = 0U;
  c3_info[152].mFileTimeHi = 0U;
  c3_info[153].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[153].name = "eml_blas_inline";
  c3_info[153].dominantType = "";
  c3_info[153].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[153].fileTimeLo = 1299051568U;
  c3_info[153].fileTimeHi = 0U;
  c3_info[153].mFileTimeLo = 0U;
  c3_info[153].mFileTimeHi = 0U;
  c3_info[154].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[154].name = "eml_xdot";
  c3_info[154].dominantType = "double";
  c3_info[154].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[154].fileTimeLo = 1299051572U;
  c3_info[154].fileTimeHi = 0U;
  c3_info[154].mFileTimeLo = 0U;
  c3_info[154].mFileTimeHi = 0U;
  c3_info[155].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[155].name = "eml_index_minus";
  c3_info[155].dominantType = "double";
  c3_info[155].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[155].fileTimeLo = 1286797178U;
  c3_info[155].fileTimeHi = 0U;
  c3_info[155].mFileTimeLo = 0U;
  c3_info[155].mFileTimeHi = 0U;
  c3_info[156].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[156].name = "eml_index_times";
  c3_info[156].dominantType = "coder.internal.indexInt";
  c3_info[156].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[156].fileTimeLo = 1286797180U;
  c3_info[156].fileTimeHi = 0U;
  c3_info[156].mFileTimeLo = 0U;
  c3_info[156].mFileTimeHi = 0U;
  c3_info[157].context = "";
  c3_info[157].name = "sqrt";
  c3_info[157].dominantType = "double";
  c3_info[157].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[157].fileTimeLo = 1343808786U;
  c3_info[157].fileTimeHi = 0U;
  c3_info[157].mFileTimeLo = 0U;
  c3_info[157].mFileTimeHi = 0U;
  c3_info[158].context = "";
  c3_info[158].name = "acos";
  c3_info[158].dominantType = "double";
  c3_info[158].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c3_info[158].fileTimeLo = 1343808766U;
  c3_info[158].fileTimeHi = 0U;
  c3_info[158].mFileTimeLo = 0U;
  c3_info[158].mFileTimeHi = 0U;
  c3_info[159].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c3_info[159].name = "eml_error";
  c3_info[159].dominantType = "char";
  c3_info[159].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[159].fileTimeLo = 1343808758U;
  c3_info[159].fileTimeHi = 0U;
  c3_info[159].mFileTimeLo = 0U;
  c3_info[159].mFileTimeHi = 0U;
  c3_info[160].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c3_info[160].name = "eml_scalar_acos";
  c3_info[160].dominantType = "double";
  c3_info[160].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m";
  c3_info[160].fileTimeLo = 1343808776U;
  c3_info[160].fileTimeHi = 0U;
  c3_info[160].mFileTimeLo = 0U;
  c3_info[160].mFileTimeHi = 0U;
}

static real_T c3_eml_div(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x, real_T c3_y)
{
  return c3_x / c3_y;
}

static void c3_eml_error(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance)
{
  int32_T c3_i85;
  static char_T c3_cv0[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i',
    't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c3_u[33];
  const mxArray *c3_y = NULL;
  for (c3_i85 = 0; c3_i85 < 33; c3_i85++) {
    c3_u[c3_i85] = c3_cv0[c3_i85];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c3_y));
}

static void c3_eml_xgesvd(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_A[6], real_T c3_U[4], real_T c3_S[2], real_T c3_V[9])
{
  int32_T c3_i86;
  real_T c3_b_A[6];
  int32_T c3_i87;
  real_T c3_e[3];
  int32_T c3_i88;
  real_T c3_work[2];
  int32_T c3_i89;
  int32_T c3_i90;
  int32_T c3_i91;
  real_T c3_c_A[6];
  real_T c3_nrm;
  real_T c3_absx;
  real_T c3_d;
  real_T c3_y;
  real_T c3_s[3];
  real_T c3_d9;
  int32_T c3_jj;
  int32_T c3_b_jj;
  int32_T c3_a;
  int32_T c3_c;
  int32_T c3_b;
  int32_T c3_b_c;
  int32_T c3_b_b;
  int32_T c3_qjj;
  int32_T c3_i92;
  real_T c3_d_A[6];
  int32_T c3_i93;
  real_T c3_e_A[6];
  real_T c3_t;
  int32_T c3_ii;
  int32_T c3_b_ii;
  int32_T c3_i94;
  real_T c3_b_e[3];
  real_T c3_b_absx;
  real_T c3_b_d;
  real_T c3_b_y;
  real_T c3_d10;
  int32_T c3_c_jj;
  int32_T c3_b_a;
  int32_T c3_c_c;
  int32_T c3_c_b;
  int32_T c3_d_c;
  int32_T c3_d_b;
  int32_T c3_qp1jj;
  int32_T c3_i95;
  real_T c3_f_A[6];
  int32_T c3_d_jj;
  int32_T c3_c_a;
  int32_T c3_e_c;
  int32_T c3_e_b;
  int32_T c3_f_c;
  int32_T c3_f_b;
  int32_T c3_i96;
  real_T c3_b_work[2];
  int32_T c3_c_ii;
  int32_T c3_m;
  int32_T c3_d_ii;
  int32_T c3_i97;
  real_T c3_b_U[4];
  int32_T c3_i98;
  real_T c3_c_U[4];
  int32_T c3_e_ii;
  int32_T c3_f_ii;
  int32_T c3_q;
  int32_T c3_b_q;
  int32_T c3_e_jj;
  int32_T c3_d_a;
  int32_T c3_g_c;
  int32_T c3_g_b;
  int32_T c3_h_c;
  int32_T c3_h_b;
  int32_T c3_i99;
  real_T c3_b_V[9];
  int32_T c3_i100;
  real_T c3_c_V[9];
  int32_T c3_i101;
  int32_T c3_i102;
  int32_T c3_g_ii;
  int32_T c3_c_q;
  real_T c3_rt;
  real_T c3_r;
  int32_T c3_e_a;
  int32_T c3_i_c;
  int32_T c3_i_b;
  int32_T c3_j_c;
  int32_T c3_j_b;
  int32_T c3_colq;
  int32_T c3_f_a;
  int32_T c3_k_c;
  int32_T c3_g_a;
  int32_T c3_l_c;
  real_T c3_h_a;
  real_T c3_k_b;
  real_T c3_c_y;
  int32_T c3_l_b;
  int32_T c3_m_c;
  int32_T c3_m_b;
  int32_T c3_colqp1;
  real_T c3_iter;
  real_T c3_snorm;
  int32_T c3_h_ii;
  real_T c3_varargin_1;
  real_T c3_varargin_2;
  real_T c3_b_varargin_2;
  real_T c3_varargin_3;
  real_T c3_x;
  real_T c3_d_y;
  real_T c3_b_x;
  real_T c3_e_y;
  real_T c3_xk;
  real_T c3_yk;
  real_T c3_c_x;
  real_T c3_f_y;
  real_T c3_maxval;
  real_T c3_b_varargin_1;
  real_T c3_c_varargin_2;
  real_T c3_d_varargin_2;
  real_T c3_b_varargin_3;
  real_T c3_d_x;
  real_T c3_g_y;
  real_T c3_e_x;
  real_T c3_h_y;
  real_T c3_b_xk;
  real_T c3_b_yk;
  real_T c3_f_x;
  real_T c3_i_y;
  int32_T c3_i_a;
  int32_T c3_j_a;
  int32_T c3_i103;
  int32_T c3_i_ii;
  int32_T c3_k_a;
  int32_T c3_n_c;
  real_T c3_test0;
  real_T c3_ztest0;
  real_T c3_n_b;
  real_T c3_j_y;
  real_T c3_o_b;
  real_T c3_k_y;
  int32_T c3_l_a;
  int32_T c3_o_c;
  real_T c3_kase;
  int32_T c3_qs;
  int32_T c3_b_m;
  int32_T c3_d_q;
  int32_T c3_j_ii;
  real_T c3_test;
  int32_T c3_m_a;
  int32_T c3_p_c;
  int32_T c3_n_a;
  int32_T c3_q_c;
  real_T c3_ztest;
  real_T c3_p_b;
  real_T c3_l_y;
  int32_T c3_o_a;
  int32_T c3_p_a;
  int32_T c3_r_c;
  real_T c3_f;
  int32_T c3_q_a;
  int32_T c3_s_c;
  int32_T c3_r_a;
  int32_T c3_i104;
  int32_T c3_e_q;
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_t1;
  real_T c3_b_t1;
  real_T c3_b_f;
  real_T c3_sn;
  real_T c3_cs;
  real_T c3_b_cs;
  real_T c3_b_sn;
  real_T c3_s_a;
  real_T c3_q_b;
  real_T c3_t_a;
  real_T c3_r_b;
  real_T c3_m_y;
  int32_T c3_u_a;
  int32_T c3_t_c;
  int32_T c3_s_b;
  int32_T c3_u_c;
  int32_T c3_t_b;
  int32_T c3_colk;
  int32_T c3_v_a;
  int32_T c3_v_c;
  int32_T c3_u_b;
  int32_T c3_w_c;
  int32_T c3_v_b;
  int32_T c3_colm;
  int32_T c3_w_a;
  int32_T c3_qm1;
  int32_T c3_f_q;
  int32_T c3_c_m;
  int32_T c3_c_k;
  real_T c3_c_t1;
  real_T c3_unusedU0;
  real_T c3_c_sn;
  real_T c3_c_cs;
  real_T c3_x_a;
  real_T c3_w_b;
  real_T c3_y_a;
  real_T c3_x_b;
  real_T c3_n_y;
  int32_T c3_ab_a;
  int32_T c3_x_c;
  int32_T c3_y_b;
  int32_T c3_y_c;
  int32_T c3_ab_b;
  int32_T c3_bb_a;
  int32_T c3_ab_c;
  int32_T c3_bb_b;
  int32_T c3_bb_c;
  int32_T c3_cb_b;
  int32_T c3_colqm1;
  int32_T c3_cb_a;
  int32_T c3_mm1;
  real_T c3_d11;
  real_T c3_d12;
  real_T c3_d13;
  real_T c3_d14;
  real_T c3_d15;
  real_T c3_c_varargin_1[5];
  int32_T c3_ixstart;
  real_T c3_mtmp;
  real_T c3_g_x;
  boolean_T c3_db_b;
  int32_T c3_ix;
  int32_T c3_b_ix;
  real_T c3_h_x;
  boolean_T c3_eb_b;
  int32_T c3_db_a;
  int32_T c3_i105;
  int32_T c3_c_ix;
  real_T c3_eb_a;
  real_T c3_fb_b;
  boolean_T c3_p;
  real_T c3_b_mtmp;
  real_T c3_scale;
  real_T c3_sm;
  real_T c3_smm1;
  real_T c3_emm1;
  real_T c3_sqds;
  real_T c3_eqds;
  real_T c3_fb_a;
  real_T c3_gb_b;
  real_T c3_o_y;
  real_T c3_gb_a;
  real_T c3_hb_b;
  real_T c3_p_y;
  real_T c3_ib_b;
  real_T c3_hb_a;
  real_T c3_jb_b;
  real_T c3_cb_c;
  real_T c3_ib_a;
  real_T c3_kb_b;
  real_T c3_shift;
  real_T c3_jb_a;
  real_T c3_lb_b;
  real_T c3_q_y;
  real_T c3_kb_a;
  real_T c3_mb_b;
  real_T c3_r_y;
  real_T c3_lb_a;
  real_T c3_nb_b;
  real_T c3_g;
  int32_T c3_g_q;
  int32_T c3_b_mm1;
  int32_T c3_d_k;
  int32_T c3_mb_a;
  int32_T c3_km1;
  int32_T c3_nb_a;
  int32_T c3_kp1;
  real_T c3_c_f;
  real_T c3_unusedU1;
  real_T c3_d_sn;
  real_T c3_d_cs;
  real_T c3_ob_a;
  real_T c3_ob_b;
  real_T c3_s_y;
  real_T c3_pb_a;
  real_T c3_pb_b;
  real_T c3_t_y;
  real_T c3_qb_a;
  real_T c3_qb_b;
  real_T c3_u_y;
  real_T c3_rb_a;
  real_T c3_rb_b;
  real_T c3_v_y;
  real_T c3_sb_a;
  real_T c3_sb_b;
  real_T c3_tb_a;
  real_T c3_tb_b;
  real_T c3_w_y;
  int32_T c3_ub_a;
  int32_T c3_db_c;
  int32_T c3_ub_b;
  int32_T c3_eb_c;
  int32_T c3_vb_b;
  int32_T c3_wb_b;
  int32_T c3_fb_c;
  int32_T c3_xb_b;
  int32_T c3_colkp1;
  real_T c3_d_f;
  real_T c3_unusedU2;
  real_T c3_e_sn;
  real_T c3_e_cs;
  real_T c3_vb_a;
  real_T c3_yb_b;
  real_T c3_x_y;
  real_T c3_wb_a;
  real_T c3_ac_b;
  real_T c3_y_y;
  real_T c3_xb_a;
  real_T c3_bc_b;
  real_T c3_ab_y;
  real_T c3_yb_a;
  real_T c3_cc_b;
  real_T c3_bb_y;
  real_T c3_ac_a;
  real_T c3_dc_b;
  real_T c3_bc_a;
  real_T c3_ec_b;
  real_T c3_cb_y;
  int32_T c3_i106;
  int32_T c3_i107;
  int32_T c3_cc_a;
  int32_T c3_gb_c;
  int32_T c3_e_k;
  int32_T c3_qp1;
  int32_T c3_hb_c;
  int32_T c3_dc_a;
  int32_T c3_ib_c;
  int32_T c3_fc_b;
  int32_T c3_gc_b;
  int32_T c3_ec_a;
  int32_T c3_fc_a;
  int32_T c3_jb_c;
  int32_T c3_gc_a;
  int32_T c3_kb_c;
  int32_T c3_hc_b;
  int32_T c3_ic_b;
  int32_T c3_lb_c;
  int32_T c3_jc_b;
  int32_T c3_kc_b;
  int32_T c3_hc_a;
  real_T c3_d16;
  int32_T c3_i108;
  int32_T c3_i109;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T guard11 = FALSE;
  for (c3_i86 = 0; c3_i86 < 6; c3_i86++) {
    c3_b_A[c3_i86] = c3_A[c3_i86];
  }

  c3_eml_scalar_eg(chartInstance);
  for (c3_i87 = 0; c3_i87 < 3; c3_i87++) {
    c3_e[c3_i87] = 0.0;
  }

  for (c3_i88 = 0; c3_i88 < 2; c3_i88++) {
    c3_work[c3_i88] = 0.0;
  }

  for (c3_i89 = 0; c3_i89 < 4; c3_i89++) {
    c3_U[c3_i89] = 0.0;
  }

  for (c3_i90 = 0; c3_i90 < 9; c3_i90++) {
    c3_V[c3_i90] = 0.0;
  }

  for (c3_i91 = 0; c3_i91 < 6; c3_i91++) {
    c3_c_A[c3_i91] = c3_b_A[c3_i91];
  }

  c3_nrm = c3_eml_xnrm2(chartInstance, c3_c_A);
  if (c3_nrm > 0.0) {
    c3_absx = c3_nrm;
    c3_d = c3_b_A[0];
    if (c3_d < 0.0) {
      c3_y = -c3_absx;
    } else {
      c3_y = c3_absx;
    }

    c3_s[0] = c3_y;
    c3_d9 = c3_eml_div(chartInstance, 1.0, c3_s[0]);
    c3_e_eml_xscal(chartInstance, c3_d9, c3_b_A);
    c3_b_A[0]++;
    c3_s[0] = -c3_s[0];
  } else {
    c3_s[0] = 0.0;
  }

  for (c3_jj = 2; c3_jj < 4; c3_jj++) {
    c3_b_jj = c3_jj;
    c3_a = c3_b_jj - 1;
    c3_c = c3_a;
    c3_b = c3_c;
    c3_b_c = c3_b << 1;
    c3_b_b = c3_b_c + 1;
    c3_qjj = c3_b_b;
    if (c3_s[0] != 0.0) {
      for (c3_i92 = 0; c3_i92 < 6; c3_i92++) {
        c3_d_A[c3_i92] = c3_b_A[c3_i92];
      }

      for (c3_i93 = 0; c3_i93 < 6; c3_i93++) {
        c3_e_A[c3_i93] = c3_b_A[c3_i93];
      }

      c3_t = c3_eml_xdotc(chartInstance, c3_d_A, c3_e_A, c3_qjj);
      c3_t = -c3_eml_div(chartInstance, c3_t, c3_b_A[0]);
      c3_f_eml_xaxpy(chartInstance, c3_t, c3_b_A, c3_qjj);
    }

    c3_e[c3_b_jj - 1] = c3_b_A[c3_qjj - 1];
  }

  for (c3_ii = 1; c3_ii < 3; c3_ii++) {
    c3_b_ii = c3_ii - 1;
    c3_U[c3_b_ii] = c3_b_A[c3_b_ii];
  }

  for (c3_i94 = 0; c3_i94 < 3; c3_i94++) {
    c3_b_e[c3_i94] = c3_e[c3_i94];
  }

  c3_nrm = c3_b_eml_xnrm2(chartInstance, c3_b_e);
  if (c3_nrm == 0.0) {
    c3_e[0] = 0.0;
  } else {
    c3_b_absx = c3_nrm;
    c3_b_d = c3_e[1];
    if (c3_b_d < 0.0) {
      c3_b_y = -c3_b_absx;
    } else {
      c3_b_y = c3_b_absx;
    }

    c3_e[0] = c3_b_y;
    c3_d10 = c3_eml_div(chartInstance, 1.0, c3_e[0]);
    c3_f_eml_xscal(chartInstance, c3_d10, c3_e);
    c3_e[1]++;
  }

  c3_e[0] = -c3_e[0];
  if (c3_e[0] != 0.0) {
    c3_work[1] = 0.0;
    for (c3_c_jj = 2; c3_c_jj < 4; c3_c_jj++) {
      c3_b_jj = c3_c_jj;
      c3_b_a = c3_b_jj - 1;
      c3_c_c = c3_b_a;
      c3_c_b = c3_c_c;
      c3_d_c = c3_c_b << 1;
      c3_d_b = c3_d_c + 2;
      c3_qp1jj = c3_d_b;
      for (c3_i95 = 0; c3_i95 < 6; c3_i95++) {
        c3_f_A[c3_i95] = c3_b_A[c3_i95];
      }

      c3_g_eml_xaxpy(chartInstance, c3_e[c3_b_jj - 1], c3_f_A, c3_qp1jj, c3_work);
    }

    for (c3_d_jj = 2; c3_d_jj < 4; c3_d_jj++) {
      c3_b_jj = c3_d_jj;
      c3_t = c3_eml_div(chartInstance, -c3_e[c3_b_jj - 1], c3_e[1]);
      c3_c_a = c3_b_jj - 1;
      c3_e_c = c3_c_a;
      c3_e_b = c3_e_c;
      c3_f_c = c3_e_b << 1;
      c3_f_b = c3_f_c + 2;
      c3_qp1jj = c3_f_b;
      for (c3_i96 = 0; c3_i96 < 2; c3_i96++) {
        c3_b_work[c3_i96] = c3_work[c3_i96];
      }

      c3_h_eml_xaxpy(chartInstance, c3_t, c3_b_work, c3_b_A, c3_qp1jj);
    }
  }

  for (c3_c_ii = 2; c3_c_ii < 4; c3_c_ii++) {
    c3_b_ii = c3_c_ii - 1;
    c3_V[c3_b_ii] = c3_e[c3_b_ii];
  }

  c3_m = 3;
  c3_s[1] = c3_b_A[3];
  c3_s[2] = 0.0;
  c3_e[1] = c3_b_A[5];
  c3_e[2] = 0.0;
  for (c3_d_ii = 1; c3_d_ii < 3; c3_d_ii++) {
    c3_b_ii = c3_d_ii - 1;
    c3_U[2 + c3_b_ii] = 0.0;
  }

  c3_U[3] = 1.0;
  if (c3_s[0] != 0.0) {
    for (c3_i97 = 0; c3_i97 < 4; c3_i97++) {
      c3_b_U[c3_i97] = c3_U[c3_i97];
    }

    for (c3_i98 = 0; c3_i98 < 4; c3_i98++) {
      c3_c_U[c3_i98] = c3_U[c3_i98];
    }

    c3_t = c3_b_eml_xdotc(chartInstance, c3_b_U, c3_c_U);
    c3_t = -c3_eml_div(chartInstance, c3_t, c3_U[0]);
    c3_i_eml_xaxpy(chartInstance, c3_t, c3_U);
    for (c3_e_ii = 1; c3_e_ii < 3; c3_e_ii++) {
      c3_b_ii = c3_e_ii - 1;
      c3_U[c3_b_ii] = -c3_U[c3_b_ii];
    }

    c3_U[0]++;
  } else {
    for (c3_f_ii = 1; c3_f_ii < 3; c3_f_ii++) {
      c3_b_ii = c3_f_ii - 1;
      c3_U[c3_b_ii] = 0.0;
    }

    c3_U[0] = 1.0;
  }

  for (c3_q = 3; c3_q > 0; c3_q--) {
    c3_b_q = c3_q - 1;
    if (c3_b_q + 1 <= 1) {
      if (c3_e[0] != 0.0) {
        for (c3_e_jj = 2; c3_e_jj < 4; c3_e_jj++) {
          c3_b_jj = c3_e_jj;
          c3_d_a = c3_b_jj - 1;
          c3_g_c = c3_d_a;
          c3_g_b = c3_g_c;
          c3_h_c = 3 * c3_g_b;
          c3_h_b = c3_h_c + 2;
          c3_qp1jj = c3_h_b;
          for (c3_i99 = 0; c3_i99 < 9; c3_i99++) {
            c3_b_V[c3_i99] = c3_V[c3_i99];
          }

          for (c3_i100 = 0; c3_i100 < 9; c3_i100++) {
            c3_c_V[c3_i100] = c3_V[c3_i100];
          }

          c3_t = c3_c_eml_xdotc(chartInstance, 2, c3_b_V, 2, c3_c_V, c3_qp1jj);
          c3_t = -c3_eml_div(chartInstance, c3_t, c3_V[1]);
          c3_i101 = 2;
          c3_i102 = 2;
          c3_j_eml_xaxpy(chartInstance, c3_i101, c3_t, c3_i102, c3_V, c3_qp1jj);
        }
      }
    }

    for (c3_g_ii = 1; c3_g_ii < 4; c3_g_ii++) {
      c3_b_ii = c3_g_ii - 1;
      c3_V[c3_b_ii + 3 * c3_b_q] = 0.0;
    }

    c3_V[c3_b_q + 3 * c3_b_q] = 1.0;
  }

  for (c3_c_q = 1; c3_c_q < 4; c3_c_q++) {
    c3_b_q = c3_c_q - 1;
    if (c3_s[c3_b_q] != 0.0) {
      c3_rt = c3_abs(chartInstance, c3_s[c3_b_q]);
      c3_r = c3_eml_div(chartInstance, c3_s[c3_b_q], c3_rt);
      c3_s[c3_b_q] = c3_rt;
      if (c3_b_q + 1 < 3) {
        c3_e[c3_b_q] = c3_eml_div(chartInstance, c3_e[c3_b_q], c3_r);
      }

      if (c3_b_q + 1 <= 2) {
        c3_e_a = c3_b_q;
        c3_i_c = c3_e_a;
        c3_i_b = c3_i_c;
        c3_j_c = c3_i_b << 1;
        c3_j_b = c3_j_c + 1;
        c3_colq = c3_j_b;
        c3_g_eml_xscal(chartInstance, c3_r, c3_U, c3_colq);
      }
    }

    if (c3_b_q + 1 < 3) {
      if (c3_e[c3_b_q] != 0.0) {
        c3_rt = c3_abs(chartInstance, c3_e[c3_b_q]);
        c3_r = c3_eml_div(chartInstance, c3_rt, c3_e[c3_b_q]);
        c3_e[c3_b_q] = c3_rt;
        c3_f_a = c3_b_q + 2;
        c3_k_c = c3_f_a - 1;
        c3_g_a = c3_b_q + 2;
        c3_l_c = c3_g_a - 1;
        c3_h_a = c3_s[c3_l_c];
        c3_k_b = c3_r;
        c3_c_y = c3_h_a * c3_k_b;
        c3_s[c3_k_c] = c3_c_y;
        c3_l_b = c3_b_q + 1;
        c3_m_c = 3 * c3_l_b;
        c3_m_b = c3_m_c + 1;
        c3_colqp1 = c3_m_b;
        c3_h_eml_xscal(chartInstance, c3_r, c3_V, c3_colqp1);
      }
    }
  }

  c3_iter = 0.0;
  c3_realmin(chartInstance);
  c3_eps(chartInstance);
  c3_eml_div(chartInstance, 2.2250738585072014E-308, 2.2204460492503131E-16);
  c3_snorm = 0.0;
  for (c3_h_ii = 1; c3_h_ii < 4; c3_h_ii++) {
    c3_b_ii = c3_h_ii - 1;
    c3_varargin_1 = c3_abs(chartInstance, c3_s[c3_b_ii]);
    c3_varargin_2 = c3_abs(chartInstance, c3_e[c3_b_ii]);
    c3_b_varargin_2 = c3_varargin_1;
    c3_varargin_3 = c3_varargin_2;
    c3_x = c3_b_varargin_2;
    c3_d_y = c3_varargin_3;
    c3_b_x = c3_x;
    c3_e_y = c3_d_y;
    c3_c_eml_scalar_eg(chartInstance);
    c3_xk = c3_b_x;
    c3_yk = c3_e_y;
    c3_c_x = c3_xk;
    c3_f_y = c3_yk;
    c3_c_eml_scalar_eg(chartInstance);
    c3_maxval = muDoubleScalarMax(c3_c_x, c3_f_y);
    c3_b_varargin_1 = c3_snorm;
    c3_c_varargin_2 = c3_maxval;
    c3_d_varargin_2 = c3_b_varargin_1;
    c3_b_varargin_3 = c3_c_varargin_2;
    c3_d_x = c3_d_varargin_2;
    c3_g_y = c3_b_varargin_3;
    c3_e_x = c3_d_x;
    c3_h_y = c3_g_y;
    c3_c_eml_scalar_eg(chartInstance);
    c3_b_xk = c3_e_x;
    c3_b_yk = c3_h_y;
    c3_f_x = c3_b_xk;
    c3_i_y = c3_b_yk;
    c3_c_eml_scalar_eg(chartInstance);
    c3_snorm = muDoubleScalarMax(c3_f_x, c3_i_y);
  }

  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c3_m > 0)) {
    if (c3_iter >= 75.0) {
      c3_b_eml_error(chartInstance);
      exitg1 = TRUE;
    } else {
      c3_i_a = c3_m - 1;
      c3_b_q = c3_i_a;
      c3_j_a = c3_m - 1;
      c3_i103 = c3_j_a;
      c3_i_ii = c3_i103;
      guard3 = FALSE;
      guard4 = FALSE;
      exitg5 = FALSE;
      while ((exitg5 == FALSE) && (c3_i_ii > -1)) {
        c3_b_ii = c3_i_ii;
        c3_b_q = c3_b_ii;
        if (c3_b_ii == 0) {
          exitg5 = TRUE;
        } else {
          c3_k_a = c3_b_ii + 1;
          c3_n_c = c3_k_a - 1;
          c3_test0 = c3_abs(chartInstance, c3_s[c3_b_ii - 1]) + c3_abs
            (chartInstance, c3_s[c3_n_c]);
          c3_ztest0 = c3_abs(chartInstance, c3_e[c3_b_ii - 1]);
          c3_eps(chartInstance);
          c3_n_b = c3_test0;
          c3_j_y = 2.2204460492503131E-16 * c3_n_b;
          if (c3_ztest0 <= c3_j_y) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else if (c3_ztest0 <= 1.0020841800044864E-292) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else {
            guard11 = FALSE;
            if (c3_iter > 20.0) {
              c3_eps(chartInstance);
              c3_o_b = c3_snorm;
              c3_k_y = 2.2204460492503131E-16 * c3_o_b;
              if (c3_ztest0 <= c3_k_y) {
                guard3 = TRUE;
                exitg5 = TRUE;
              } else {
                guard11 = TRUE;
              }
            } else {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              c3_i_ii--;
              guard3 = FALSE;
              guard4 = FALSE;
            }
          }
        }
      }

      if (guard4 == TRUE) {
        guard3 = TRUE;
      }

      if (guard3 == TRUE) {
        c3_e[c3_b_ii - 1] = 0.0;
      }

      c3_l_a = c3_m - 1;
      c3_o_c = c3_l_a;
      if (c3_b_q == c3_o_c) {
        c3_kase = 4.0;
      } else {
        c3_qs = c3_m;
        c3_b_m = c3_m;
        c3_d_q = c3_b_q;
        c3_j_ii = c3_b_m;
        guard2 = FALSE;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (c3_j_ii >= c3_d_q)) {
          c3_b_ii = c3_j_ii;
          c3_qs = c3_b_ii;
          if (c3_b_ii == c3_b_q) {
            exitg4 = TRUE;
          } else {
            c3_test = 0.0;
            if (c3_b_ii < c3_m) {
              c3_test = c3_abs(chartInstance, c3_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", c3_b_ii, 1, 3, 1, 0) - 1]);
            }

            c3_m_a = c3_b_q + 1;
            c3_p_c = c3_m_a;
            if (c3_b_ii > c3_p_c) {
              c3_n_a = c3_b_ii - 1;
              c3_q_c = c3_n_a;
              c3_test += c3_abs(chartInstance, c3_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", c3_q_c, 1, 3, 1, 0) - 1]);
            }

            c3_ztest = c3_abs(chartInstance, c3_s[c3_b_ii - 1]);
            c3_eps(chartInstance);
            c3_p_b = c3_test;
            c3_l_y = 2.2204460492503131E-16 * c3_p_b;
            if (c3_ztest <= c3_l_y) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else if (c3_ztest <= 1.0020841800044864E-292) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else {
              c3_j_ii--;
              guard2 = FALSE;
            }
          }
        }

        if (guard2 == TRUE) {
          c3_s[c3_b_ii - 1] = 0.0;
        }

        if (c3_qs == c3_b_q) {
          c3_kase = 3.0;
        } else if (c3_qs == c3_m) {
          c3_kase = 1.0;
        } else {
          c3_kase = 2.0;
          c3_b_q = c3_qs;
        }
      }

      c3_o_a = c3_b_q + 1;
      c3_b_q = c3_o_a;
      switch ((int32_T)c3_kase) {
       case 1:
        c3_p_a = c3_m - 1;
        c3_r_c = c3_p_a;
        c3_f = c3_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_r_c, 1, 3, 1, 0) - 1];
        c3_q_a = c3_m - 1;
        c3_s_c = c3_q_a;
        c3_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_s_c, 1, 3, 1, 0) - 1] = 0.0;
        c3_r_a = c3_m - 1;
        c3_i104 = c3_r_a;
        c3_e_q = c3_b_q;
        for (c3_k = c3_i104; c3_k >= c3_e_q; c3_k--) {
          c3_b_k = c3_k;
          c3_t1 = c3_s[c3_b_k - 1];
          c3_b_t1 = c3_t1;
          c3_b_f = c3_f;
          c3_b_eml_xrotg(chartInstance, &c3_b_t1, &c3_b_f, &c3_cs, &c3_sn);
          c3_t1 = c3_b_t1;
          c3_f = c3_b_f;
          c3_b_cs = c3_cs;
          c3_b_sn = c3_sn;
          c3_s[c3_b_k - 1] = c3_t1;
          if (c3_b_k > c3_b_q) {
            c3_s_a = -c3_b_sn;
            c3_q_b = c3_e[0];
            c3_f = c3_s_a * c3_q_b;
            c3_t_a = c3_e[0];
            c3_r_b = c3_b_cs;
            c3_m_y = c3_t_a * c3_r_b;
            c3_e[0] = c3_m_y;
          }

          c3_u_a = c3_b_k - 1;
          c3_t_c = c3_u_a;
          c3_s_b = c3_t_c;
          c3_u_c = 3 * c3_s_b;
          c3_t_b = c3_u_c + 1;
          c3_colk = c3_t_b;
          c3_v_a = c3_m - 1;
          c3_v_c = c3_v_a;
          c3_u_b = c3_v_c;
          c3_w_c = 3 * c3_u_b;
          c3_v_b = c3_w_c + 1;
          c3_colm = c3_v_b;
          c3_c_eml_xrot(chartInstance, c3_V, c3_colk, c3_colm, c3_b_cs, c3_b_sn);
        }
        break;

       case 2:
        c3_w_a = c3_b_q - 1;
        c3_qm1 = c3_w_a;
        c3_f = c3_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_qm1, 1, 3, 1, 0) - 1];
        c3_e[c3_qm1 - 1] = 0.0;
        c3_f_q = c3_b_q;
        c3_c_m = c3_m;
        for (c3_c_k = c3_f_q; c3_c_k <= c3_c_m; c3_c_k++) {
          c3_b_k = c3_c_k - 1;
          c3_t1 = c3_s[c3_b_k];
          c3_c_t1 = c3_t1;
          c3_unusedU0 = c3_f;
          c3_b_eml_xrotg(chartInstance, &c3_c_t1, &c3_unusedU0, &c3_c_cs,
                         &c3_c_sn);
          c3_t1 = c3_c_t1;
          c3_b_cs = c3_c_cs;
          c3_b_sn = c3_c_sn;
          c3_s[c3_b_k] = c3_t1;
          c3_x_a = -c3_b_sn;
          c3_w_b = c3_e[c3_b_k];
          c3_f = c3_x_a * c3_w_b;
          c3_y_a = c3_e[c3_b_k];
          c3_x_b = c3_b_cs;
          c3_n_y = c3_y_a * c3_x_b;
          c3_e[c3_b_k] = c3_n_y;
          c3_ab_a = c3_b_k;
          c3_x_c = c3_ab_a;
          c3_y_b = c3_x_c;
          c3_y_c = c3_y_b << 1;
          c3_ab_b = c3_y_c + 1;
          c3_colk = c3_ab_b;
          c3_bb_a = c3_qm1 - 1;
          c3_ab_c = c3_bb_a;
          c3_bb_b = c3_ab_c;
          c3_bb_c = c3_bb_b << 1;
          c3_cb_b = c3_bb_c + 1;
          c3_colqm1 = c3_cb_b;
          c3_d_eml_xrot(chartInstance, c3_U, c3_colk, c3_colqm1, c3_b_cs,
                        c3_b_sn);
        }
        break;

       case 3:
        c3_cb_a = c3_m - 1;
        c3_mm1 = c3_cb_a;
        c3_d11 = c3_abs(chartInstance, c3_s[c3_m - 1]);
        c3_d12 = c3_abs(chartInstance, c3_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          c3_mm1, 1, 3, 1, 0) - 1]);
        c3_d13 = c3_abs(chartInstance, c3_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          c3_mm1, 1, 3, 1, 0) - 1]);
        c3_d14 = c3_abs(chartInstance, c3_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          c3_b_q, 1, 3, 1, 0) - 1]);
        c3_d15 = c3_abs(chartInstance, c3_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          c3_b_q, 1, 3, 1, 0) - 1]);
        c3_c_varargin_1[0] = c3_d11;
        c3_c_varargin_1[1] = c3_d12;
        c3_c_varargin_1[2] = c3_d13;
        c3_c_varargin_1[3] = c3_d14;
        c3_c_varargin_1[4] = c3_d15;
        c3_ixstart = 1;
        c3_mtmp = c3_c_varargin_1[0];
        c3_g_x = c3_mtmp;
        c3_db_b = muDoubleScalarIsNaN(c3_g_x);
        if (c3_db_b) {
          c3_ix = 2;
          exitg2 = FALSE;
          while ((exitg2 == FALSE) && (c3_ix < 6)) {
            c3_b_ix = c3_ix - 1;
            c3_ixstart = c3_b_ix + 1;
            c3_h_x = c3_c_varargin_1[c3_b_ix];
            c3_eb_b = muDoubleScalarIsNaN(c3_h_x);
            if (!c3_eb_b) {
              c3_mtmp = c3_c_varargin_1[c3_b_ix];
              exitg2 = TRUE;
            } else {
              c3_ix++;
            }
          }
        }

        if (c3_ixstart < 5) {
          c3_db_a = c3_ixstart + 1;
          c3_i105 = c3_db_a;
          for (c3_c_ix = c3_i105; c3_c_ix < 6; c3_c_ix++) {
            c3_b_ix = c3_c_ix - 1;
            c3_eb_a = c3_c_varargin_1[c3_b_ix];
            c3_fb_b = c3_mtmp;
            c3_p = (c3_eb_a > c3_fb_b);
            if (c3_p) {
              c3_mtmp = c3_c_varargin_1[c3_b_ix];
            }
          }
        }

        c3_b_mtmp = c3_mtmp;
        c3_scale = c3_b_mtmp;
        c3_sm = c3_eml_div(chartInstance, c3_s[c3_m - 1], c3_scale);
        c3_smm1 = c3_eml_div(chartInstance, c3_s[c3_mm1 - 1], c3_scale);
        c3_emm1 = c3_eml_div(chartInstance, c3_e[c3_mm1 - 1], c3_scale);
        c3_sqds = c3_eml_div(chartInstance, c3_s[c3_b_q - 1], c3_scale);
        c3_eqds = c3_eml_div(chartInstance, c3_e[c3_b_q - 1], c3_scale);
        c3_fb_a = c3_smm1 + c3_sm;
        c3_gb_b = c3_smm1 - c3_sm;
        c3_o_y = c3_fb_a * c3_gb_b;
        c3_gb_a = c3_emm1;
        c3_hb_b = c3_emm1;
        c3_p_y = c3_gb_a * c3_hb_b;
        c3_ib_b = c3_eml_div(chartInstance, c3_o_y + c3_p_y, 2.0);
        c3_hb_a = c3_sm;
        c3_jb_b = c3_emm1;
        c3_cb_c = c3_hb_a * c3_jb_b;
        c3_ib_a = c3_cb_c;
        c3_kb_b = c3_cb_c;
        c3_cb_c = c3_ib_a * c3_kb_b;
        c3_shift = 0.0;
        guard1 = FALSE;
        if (c3_ib_b != 0.0) {
          guard1 = TRUE;
        } else {
          if (c3_cb_c != 0.0) {
            guard1 = TRUE;
          }
        }

        if (guard1 == TRUE) {
          c3_jb_a = c3_ib_b;
          c3_lb_b = c3_ib_b;
          c3_q_y = c3_jb_a * c3_lb_b;
          c3_shift = c3_q_y + c3_cb_c;
          c3_b_sqrt(chartInstance, &c3_shift);
          if (c3_ib_b < 0.0) {
            c3_shift = -c3_shift;
          }

          c3_shift = c3_eml_div(chartInstance, c3_cb_c, c3_ib_b + c3_shift);
        }

        c3_kb_a = c3_sqds + c3_sm;
        c3_mb_b = c3_sqds - c3_sm;
        c3_r_y = c3_kb_a * c3_mb_b;
        c3_f = c3_r_y + c3_shift;
        c3_lb_a = c3_sqds;
        c3_nb_b = c3_eqds;
        c3_g = c3_lb_a * c3_nb_b;
        c3_g_q = c3_b_q;
        c3_b_mm1 = c3_mm1;
        for (c3_d_k = c3_g_q; c3_d_k <= c3_b_mm1; c3_d_k++) {
          c3_b_k = c3_d_k - 1;
          c3_mb_a = c3_b_k;
          c3_km1 = c3_mb_a;
          c3_nb_a = c3_b_k + 2;
          c3_kp1 = c3_nb_a - 1;
          c3_c_f = c3_f;
          c3_unusedU1 = c3_g;
          c3_b_eml_xrotg(chartInstance, &c3_c_f, &c3_unusedU1, &c3_d_cs,
                         &c3_d_sn);
          c3_f = c3_c_f;
          c3_b_cs = c3_d_cs;
          c3_b_sn = c3_d_sn;
          if (c3_b_k + 1 > c3_b_q) {
            _SFD_EML_ARRAY_BOUNDS_CHECK("", c3_km1, 1, 3, 1, 0);
            c3_e[0] = c3_f;
          }

          c3_ob_a = c3_b_cs;
          c3_ob_b = c3_s[c3_b_k];
          c3_s_y = c3_ob_a * c3_ob_b;
          c3_pb_a = c3_b_sn;
          c3_pb_b = c3_e[c3_b_k];
          c3_t_y = c3_pb_a * c3_pb_b;
          c3_f = c3_s_y + c3_t_y;
          c3_qb_a = c3_b_cs;
          c3_qb_b = c3_e[c3_b_k];
          c3_u_y = c3_qb_a * c3_qb_b;
          c3_rb_a = c3_b_sn;
          c3_rb_b = c3_s[c3_b_k];
          c3_v_y = c3_rb_a * c3_rb_b;
          c3_e[c3_b_k] = c3_u_y - c3_v_y;
          c3_sb_a = c3_b_sn;
          c3_sb_b = c3_s[c3_kp1];
          c3_g = c3_sb_a * c3_sb_b;
          c3_tb_a = c3_s[c3_kp1];
          c3_tb_b = c3_b_cs;
          c3_w_y = c3_tb_a * c3_tb_b;
          c3_s[c3_kp1] = c3_w_y;
          c3_ub_a = c3_b_k;
          c3_db_c = c3_ub_a;
          c3_ub_b = c3_db_c;
          c3_eb_c = 3 * c3_ub_b;
          c3_vb_b = c3_eb_c + 1;
          c3_colk = c3_vb_b;
          c3_wb_b = c3_b_k + 1;
          c3_fb_c = 3 * c3_wb_b;
          c3_xb_b = c3_fb_c + 1;
          c3_colkp1 = c3_xb_b;
          c3_c_eml_xrot(chartInstance, c3_V, c3_colk, c3_colkp1, c3_b_cs,
                        c3_b_sn);
          c3_d_f = c3_f;
          c3_unusedU2 = c3_g;
          c3_b_eml_xrotg(chartInstance, &c3_d_f, &c3_unusedU2, &c3_e_cs,
                         &c3_e_sn);
          c3_f = c3_d_f;
          c3_b_cs = c3_e_cs;
          c3_b_sn = c3_e_sn;
          c3_s[c3_b_k] = c3_f;
          c3_vb_a = c3_b_cs;
          c3_yb_b = c3_e[c3_b_k];
          c3_x_y = c3_vb_a * c3_yb_b;
          c3_wb_a = c3_b_sn;
          c3_ac_b = c3_s[c3_kp1];
          c3_y_y = c3_wb_a * c3_ac_b;
          c3_f = c3_x_y + c3_y_y;
          c3_xb_a = -c3_b_sn;
          c3_bc_b = c3_e[c3_b_k];
          c3_ab_y = c3_xb_a * c3_bc_b;
          c3_yb_a = c3_b_cs;
          c3_cc_b = c3_s[c3_kp1];
          c3_bb_y = c3_yb_a * c3_cc_b;
          c3_s[c3_kp1] = c3_ab_y + c3_bb_y;
          c3_ac_a = c3_b_sn;
          c3_dc_b = c3_e[c3_kp1];
          c3_g = c3_ac_a * c3_dc_b;
          c3_bc_a = c3_e[c3_kp1];
          c3_ec_b = c3_b_cs;
          c3_cb_y = c3_bc_a * c3_ec_b;
          c3_e[c3_kp1] = c3_cb_y;
          if (c3_b_k + 1 < 2) {
            c3_i106 = 1;
            c3_i107 = 3;
            c3_d_eml_xrot(chartInstance, c3_U, c3_i106, c3_i107, c3_b_cs,
                          c3_b_sn);
          }
        }

        c3_cc_a = c3_m - 1;
        c3_gb_c = c3_cc_a;
        c3_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_gb_c, 1, 3, 1, 0) - 1] = c3_f;
        c3_iter++;
        break;

       default:
        if (c3_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_b_q, 1, 3, 1, 0) - 1] < 0.0)
        {
          c3_s[c3_b_q - 1] = -c3_s[c3_b_q - 1];
          c3_dc_a = c3_b_q - 1;
          c3_hb_c = c3_dc_a;
          c3_fc_b = c3_hb_c;
          c3_ib_c = 3 * c3_fc_b;
          c3_gc_b = c3_ib_c + 1;
          c3_colq = c3_gc_b;
          c3_b_eml_scalar_eg(chartInstance);
          c3_d16 = -1.0;
          c3_h_eml_xscal(chartInstance, c3_d16, c3_V, c3_colq);
        }

        c3_ec_a = c3_b_q;
        c3_qp1 = c3_ec_a;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (c3_b_q < 3)) {
          if (c3_s[c3_b_q - 1] < c3_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_qp1 + 1,
               1, 3, 1, 0) - 1]) {
            c3_rt = c3_s[c3_b_q - 1];
            c3_s[c3_b_q - 1] = c3_s[c3_qp1];
            c3_s[c3_qp1] = c3_rt;
            c3_gc_a = c3_b_q - 1;
            c3_jb_c = c3_gc_a;
            c3_hc_b = c3_jb_c;
            c3_kb_c = 3 * c3_hc_b;
            c3_ic_b = c3_kb_c + 1;
            c3_colq = c3_ic_b;
            c3_jc_b = c3_b_q;
            c3_lb_c = 3 * c3_jc_b;
            c3_kc_b = c3_lb_c + 1;
            c3_colqp1 = c3_kc_b;
            c3_c_eml_xswap(chartInstance, c3_V, c3_colq, c3_colqp1);
            if (c3_b_q < 2) {
              c3_i108 = 1;
              c3_i109 = 3;
              c3_d_eml_xswap(chartInstance, c3_U, c3_i108, c3_i109);
            }

            c3_b_q = c3_qp1 + 1;
            c3_hc_a = c3_b_q + 1;
            c3_qp1 = c3_hc_a - 1;
          } else {
            exitg3 = TRUE;
          }
        }

        c3_iter = 0.0;
        c3_fc_a = c3_m - 1;
        c3_m = c3_fc_a;
        break;
      }
    }
  }

  for (c3_e_k = 1; c3_e_k < 3; c3_e_k++) {
    c3_b_k = c3_e_k - 1;
    c3_S[c3_b_k] = c3_s[c3_b_k];
  }
}

static void c3_eml_scalar_eg
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
}

static real_T c3_eml_xnrm2(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_x[6])
{
  real_T c3_y;
  real_T c3_scale;
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_absxk;
  real_T c3_t;
  c3_y = 0.0;
  c3_realmin(chartInstance);
  c3_scale = 2.2250738585072014E-308;
  for (c3_k = 1; c3_k < 3; c3_k++) {
    c3_b_k = c3_k - 1;
    c3_b_x = c3_x[c3_b_k];
    c3_c_x = c3_b_x;
    c3_absxk = muDoubleScalarAbs(c3_c_x);
    if (c3_absxk > c3_scale) {
      c3_t = c3_scale / c3_absxk;
      c3_y = 1.0 + c3_y * c3_t * c3_t;
      c3_scale = c3_absxk;
    } else {
      c3_t = c3_absxk / c3_scale;
      c3_y += c3_t * c3_t;
    }
  }

  return c3_scale * muDoubleScalarSqrt(c3_y);
}

static void c3_realmin(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance)
{
}

static real_T c3_abs(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                     *chartInstance, real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  return muDoubleScalarAbs(c3_b_x);
}

static void c3_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_a, real_T c3_x[6], real_T c3_b_x[6])
{
  int32_T c3_i110;
  for (c3_i110 = 0; c3_i110 < 6; c3_i110++) {
    c3_b_x[c3_i110] = c3_x[c3_i110];
  }

  c3_e_eml_xscal(chartInstance, c3_a, c3_b_x);
}

static real_T c3_eml_xdotc(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_x[6], real_T c3_y[6], int32_T c3_iy0)
{
  real_T c3_d;
  int32_T c3_b_iy0;
  int32_T c3_c_iy0;
  int32_T c3_d_iy0;
  int32_T c3_e_iy0;
  int32_T c3_ix;
  int32_T c3_iy;
  int32_T c3_k;
  int32_T c3_a;
  int32_T c3_b_a;
  c3_b_iy0 = c3_iy0;
  c3_c_iy0 = c3_b_iy0;
  c3_d_iy0 = c3_c_iy0;
  c3_e_iy0 = c3_d_iy0;
  c3_d = 0.0;
  c3_ix = 1;
  c3_iy = c3_e_iy0;
  for (c3_k = 1; c3_k < 3; c3_k++) {
    c3_d += c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_ix, 1, 6, 1, 0) - 1] *
      c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_iy, 1, 6, 1, 0) - 1];
    c3_a = c3_ix + 1;
    c3_ix = c3_a;
    c3_b_a = c3_iy + 1;
    c3_iy = c3_b_a;
  }

  return c3_d;
}

static void c3_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_a, real_T c3_y[6], int32_T c3_iy0, real_T c3_b_y[6])
{
  int32_T c3_i111;
  for (c3_i111 = 0; c3_i111 < 6; c3_i111++) {
    c3_b_y[c3_i111] = c3_y[c3_i111];
  }

  c3_f_eml_xaxpy(chartInstance, c3_a, c3_b_y, c3_iy0);
}

static real_T c3_b_eml_xnrm2
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, real_T
   c3_x[3])
{
  real_T c3_y;
  real_T c3_scale;
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_absxk;
  real_T c3_t;
  c3_y = 0.0;
  c3_realmin(chartInstance);
  c3_scale = 2.2250738585072014E-308;
  for (c3_k = 2; c3_k < 4; c3_k++) {
    c3_b_k = c3_k - 1;
    c3_b_x = c3_x[c3_b_k];
    c3_c_x = c3_b_x;
    c3_absxk = muDoubleScalarAbs(c3_c_x);
    if (c3_absxk > c3_scale) {
      c3_t = c3_scale / c3_absxk;
      c3_y = 1.0 + c3_y * c3_t * c3_t;
      c3_scale = c3_absxk;
    } else {
      c3_t = c3_absxk / c3_scale;
      c3_y += c3_t * c3_t;
    }
  }

  return c3_scale * muDoubleScalarSqrt(c3_y);
}

static void c3_b_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[3], real_T c3_b_x[3])
{
  int32_T c3_i112;
  for (c3_i112 = 0; c3_i112 < 3; c3_i112++) {
    c3_b_x[c3_i112] = c3_x[c3_i112];
  }

  c3_f_eml_xscal(chartInstance, c3_a, c3_b_x);
}

static void c3_b_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[6], int32_T c3_ix0, real_T c3_y[2],
  real_T c3_b_y[2])
{
  int32_T c3_i113;
  int32_T c3_i114;
  real_T c3_b_x[6];
  for (c3_i113 = 0; c3_i113 < 2; c3_i113++) {
    c3_b_y[c3_i113] = c3_y[c3_i113];
  }

  for (c3_i114 = 0; c3_i114 < 6; c3_i114++) {
    c3_b_x[c3_i114] = c3_x[c3_i114];
  }

  c3_g_eml_xaxpy(chartInstance, c3_a, c3_b_x, c3_ix0, c3_b_y);
}

static void c3_c_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[2], real_T c3_y[6], int32_T c3_iy0,
  real_T c3_b_y[6])
{
  int32_T c3_i115;
  int32_T c3_i116;
  real_T c3_b_x[2];
  for (c3_i115 = 0; c3_i115 < 6; c3_i115++) {
    c3_b_y[c3_i115] = c3_y[c3_i115];
  }

  for (c3_i116 = 0; c3_i116 < 2; c3_i116++) {
    c3_b_x[c3_i116] = c3_x[c3_i116];
  }

  c3_h_eml_xaxpy(chartInstance, c3_a, c3_b_x, c3_b_y, c3_iy0);
}

static real_T c3_b_eml_xdotc
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, real_T
   c3_x[4], real_T c3_y[4])
{
  real_T c3_d;
  int32_T c3_ix;
  int32_T c3_iy;
  int32_T c3_k;
  int32_T c3_a;
  int32_T c3_b_a;
  c3_d = 0.0;
  c3_ix = 1;
  c3_iy = 3;
  for (c3_k = 1; c3_k < 3; c3_k++) {
    c3_d += c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_ix, 1, 4, 1, 0) - 1] *
      c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_iy, 1, 4, 1, 0) - 1];
    c3_a = c3_ix + 1;
    c3_ix = c3_a;
    c3_b_a = c3_iy + 1;
    c3_iy = c3_b_a;
  }

  return c3_d;
}

static void c3_d_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_y[4], real_T c3_b_y[4])
{
  int32_T c3_i117;
  for (c3_i117 = 0; c3_i117 < 4; c3_i117++) {
    c3_b_y[c3_i117] = c3_y[c3_i117];
  }

  c3_i_eml_xaxpy(chartInstance, c3_a, c3_b_y);
}

static real_T c3_c_eml_xdotc
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, int32_T
   c3_n, real_T c3_x[9], int32_T c3_ix0, real_T c3_y[9], int32_T c3_iy0)
{
  real_T c3_d;
  int32_T c3_b_n;
  int32_T c3_b_ix0;
  int32_T c3_b_iy0;
  int32_T c3_c_n;
  int32_T c3_c_ix0;
  int32_T c3_c_iy0;
  int32_T c3_d_n;
  int32_T c3_d_ix0;
  int32_T c3_d_iy0;
  int32_T c3_e_n;
  int32_T c3_e_ix0;
  int32_T c3_e_iy0;
  int32_T c3_ix;
  int32_T c3_iy;
  int32_T c3_f_n;
  int32_T c3_k;
  int32_T c3_a;
  int32_T c3_b_a;
  c3_b_n = c3_n;
  c3_b_ix0 = c3_ix0;
  c3_b_iy0 = c3_iy0;
  c3_c_n = c3_b_n;
  c3_c_ix0 = c3_b_ix0;
  c3_c_iy0 = c3_b_iy0;
  c3_d_n = c3_c_n;
  c3_d_ix0 = c3_c_ix0;
  c3_d_iy0 = c3_c_iy0;
  c3_e_n = c3_d_n;
  c3_e_ix0 = c3_d_ix0;
  c3_e_iy0 = c3_d_iy0;
  c3_d = 0.0;
  if (c3_e_n < 1) {
  } else {
    c3_ix = c3_e_ix0;
    c3_iy = c3_e_iy0;
    c3_f_n = c3_e_n;
    for (c3_k = 1; c3_k <= c3_f_n; c3_k++) {
      c3_d += c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_ix, 1, 9, 1, 0) - 1] *
        c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_iy, 1, 9, 1, 0) - 1];
      c3_a = c3_ix + 1;
      c3_ix = c3_a;
      c3_b_a = c3_iy + 1;
      c3_iy = c3_b_a;
    }
  }

  return c3_d;
}

static void c3_e_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, int32_T c3_n, real_T c3_a, int32_T c3_ix0, real_T c3_y[9],
  int32_T c3_iy0, real_T c3_b_y[9])
{
  int32_T c3_i118;
  for (c3_i118 = 0; c3_i118 < 9; c3_i118++) {
    c3_b_y[c3_i118] = c3_y[c3_i118];
  }

  c3_j_eml_xaxpy(chartInstance, c3_n, c3_a, c3_ix0, c3_b_y, c3_iy0);
}

static void c3_b_eml_scalar_eg
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
}

static void c3_c_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[4], int32_T c3_ix0, real_T c3_b_x[4])
{
  int32_T c3_i119;
  for (c3_i119 = 0; c3_i119 < 4; c3_i119++) {
    c3_b_x[c3_i119] = c3_x[c3_i119];
  }

  c3_g_eml_xscal(chartInstance, c3_a, c3_b_x, c3_ix0);
}

static void c3_d_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[9], int32_T c3_ix0, real_T c3_b_x[9])
{
  int32_T c3_i120;
  for (c3_i120 = 0; c3_i120 < 9; c3_i120++) {
    c3_b_x[c3_i120] = c3_x[c3_i120];
  }

  c3_h_eml_xscal(chartInstance, c3_a, c3_b_x, c3_ix0);
}

static void c3_eps(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                   *chartInstance)
{
}

static void c3_c_eml_scalar_eg
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
}

static void c3_b_eml_error(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance)
{
  int32_T c3_i121;
  static char_T c3_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  for (c3_i121 = 0; c3_i121 < 30; c3_i121++) {
    c3_u[c3_i121] = c3_cv1[c3_i121];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c3_y));
}

static real_T c3_sqrt(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                      *chartInstance, real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_sqrt(chartInstance, &c3_b_x);
  return c3_b_x;
}

static void c3_c_eml_error(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance)
{
  int32_T c3_i122;
  static char_T c3_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  int32_T c3_i123;
  static char_T c3_cv3[4] = { 's', 'q', 'r', 't' };

  char_T c3_b_u[4];
  const mxArray *c3_b_y = NULL;
  for (c3_i122 = 0; c3_i122 < 30; c3_i122++) {
    c3_u[c3_i122] = c3_cv2[c3_i122];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c3_i123 = 0; c3_i123 < 4; c3_i123++) {
    c3_b_u[c3_i123] = c3_cv3[c3_i123];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c3_y, 14, c3_b_y));
}

static void c3_eml_xrotg(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_a, real_T c3_b, real_T *c3_b_a, real_T *c3_b_b,
  real_T *c3_c, real_T *c3_s)
{
  *c3_b_a = c3_a;
  *c3_b_b = c3_b;
  c3_b_eml_xrotg(chartInstance, c3_b_a, c3_b_b, c3_c, c3_s);
}

static void c3_eml_xrot(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x[9], int32_T c3_ix0, int32_T c3_iy0, real_T c3_c,
  real_T c3_s, real_T c3_b_x[9])
{
  int32_T c3_i124;
  for (c3_i124 = 0; c3_i124 < 9; c3_i124++) {
    c3_b_x[c3_i124] = c3_x[c3_i124];
  }

  c3_c_eml_xrot(chartInstance, c3_b_x, c3_ix0, c3_iy0, c3_c, c3_s);
}

static void c3_b_eml_xrot(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x[4], int32_T c3_ix0, int32_T c3_iy0, real_T c3_c,
  real_T c3_s, real_T c3_b_x[4])
{
  int32_T c3_i125;
  for (c3_i125 = 0; c3_i125 < 4; c3_i125++) {
    c3_b_x[c3_i125] = c3_x[c3_i125];
  }

  c3_d_eml_xrot(chartInstance, c3_b_x, c3_ix0, c3_iy0, c3_c, c3_s);
}

static void c3_eml_xswap(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x[9], int32_T c3_ix0, int32_T c3_iy0, real_T c3_b_x
  [9])
{
  int32_T c3_i126;
  for (c3_i126 = 0; c3_i126 < 9; c3_i126++) {
    c3_b_x[c3_i126] = c3_x[c3_i126];
  }

  c3_c_eml_xswap(chartInstance, c3_b_x, c3_ix0, c3_iy0);
}

static void c3_b_eml_xswap(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_x[4], int32_T c3_ix0, int32_T c3_iy0, real_T c3_b_x[4])
{
  int32_T c3_i127;
  for (c3_i127 = 0; c3_i127 < 4; c3_i127++) {
    c3_b_x[c3_i127] = c3_x[c3_i127];
  }

  c3_d_eml_xswap(chartInstance, c3_b_x, c3_ix0, c3_iy0);
}

static void c3_d_eml_scalar_eg
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
}

static real_T c3_acos(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                      *chartInstance, real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_acos(chartInstance, &c3_b_x);
  return c3_b_x;
}

static void c3_d_eml_error(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance)
{
  int32_T c3_i128;
  static char_T c3_cv4[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  int32_T c3_i129;
  static char_T c3_cv5[4] = { 'a', 'c', 'o', 's' };

  char_T c3_b_u[4];
  const mxArray *c3_b_y = NULL;
  for (c3_i128 = 0; c3_i128 < 30; c3_i128++) {
    c3_u[c3_i128] = c3_cv4[c3_i128];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c3_i129 = 0; c3_i129 < 4; c3_i129++) {
    c3_b_u[c3_i129] = c3_cv5[c3_i129];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c3_y, 14, c3_b_y));
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_j_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i130;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i130, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i130;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_k_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_b_is_active_c3_Bowwave2Drogue_v6_addControl_test, const char_T
   *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Bowwave2Drogue_v6_addControl_test), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Bowwave2Drogue_v6_addControl_test);
  return c3_y;
}

static uint8_T c3_l_emlrt_marshallIn
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[6])
{
  real_T c3_b_a;
  real_T c3_c_a;
  int32_T c3_k;
  int32_T c3_b_k;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  for (c3_k = 1; c3_k < 3; c3_k++) {
    c3_b_k = c3_k - 1;
    c3_x[c3_b_k] *= c3_c_a;
  }
}

static void c3_f_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_y[6], int32_T c3_iy0)
{
  real_T c3_b_a;
  int32_T c3_b_iy0;
  real_T c3_c_a;
  int32_T c3_c_iy0;
  int32_T c3_ix;
  int32_T c3_d_a;
  int32_T c3_iy;
  int32_T c3_k;
  int32_T c3_e_a;
  int32_T c3_c;
  int32_T c3_f_a;
  int32_T c3_b_c;
  int32_T c3_g_a;
  int32_T c3_c_c;
  int32_T c3_h_a;
  int32_T c3_i_a;
  c3_b_a = c3_a;
  c3_b_iy0 = c3_iy0;
  c3_c_a = c3_b_a;
  c3_c_iy0 = c3_b_iy0;
  if (c3_c_a == 0.0) {
  } else {
    c3_ix = 0;
    c3_d_a = c3_c_iy0 - 1;
    c3_iy = c3_d_a;
    for (c3_k = 0; c3_k < 2; c3_k++) {
      c3_e_a = c3_iy;
      c3_c = c3_e_a;
      c3_f_a = c3_iy;
      c3_b_c = c3_f_a;
      c3_g_a = c3_ix;
      c3_c_c = c3_g_a;
      c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_c + 1, 1, 6, 1, 0) - 1] =
        c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_b_c + 1, 1, 6, 1, 0) - 1] +
        c3_c_a * c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_c_c + 1, 1, 6, 1, 0) -
        1];
      c3_h_a = c3_ix + 1;
      c3_ix = c3_h_a;
      c3_i_a = c3_iy + 1;
      c3_iy = c3_i_a;
    }
  }
}

static void c3_f_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[3])
{
  real_T c3_b_a;
  real_T c3_c_a;
  int32_T c3_k;
  int32_T c3_b_k;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  for (c3_k = 2; c3_k < 4; c3_k++) {
    c3_b_k = c3_k - 1;
    c3_x[c3_b_k] *= c3_c_a;
  }
}

static void c3_g_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[6], int32_T c3_ix0, real_T c3_y[2])
{
  real_T c3_b_a;
  int32_T c3_b_ix0;
  real_T c3_c_a;
  int32_T c3_c_ix0;
  int32_T c3_d_a;
  int32_T c3_ix;
  int32_T c3_e_a;
  int32_T c3_c;
  c3_b_a = c3_a;
  c3_b_ix0 = c3_ix0;
  c3_c_a = c3_b_a;
  c3_c_ix0 = c3_b_ix0;
  if (c3_c_a == 0.0) {
  } else {
    c3_d_a = c3_c_ix0;
    c3_ix = c3_d_a;
    c3_e_a = c3_ix - 1;
    c3_c = c3_e_a;
    c3_y[1] += c3_c_a * c3_x[c3_c];
  }
}

static void c3_h_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[2], real_T c3_y[6], int32_T c3_iy0)
{
  real_T c3_b_a;
  int32_T c3_b_iy0;
  real_T c3_c_a;
  int32_T c3_c_iy0;
  int32_T c3_d_a;
  int32_T c3_iy;
  int32_T c3_e_a;
  int32_T c3_c;
  int32_T c3_f_a;
  int32_T c3_b_c;
  c3_b_a = c3_a;
  c3_b_iy0 = c3_iy0;
  c3_c_a = c3_b_a;
  c3_c_iy0 = c3_b_iy0;
  if (c3_c_a == 0.0) {
  } else {
    c3_d_a = c3_c_iy0 - 1;
    c3_iy = c3_d_a;
    c3_e_a = c3_iy;
    c3_c = c3_e_a;
    c3_f_a = c3_iy;
    c3_b_c = c3_f_a;
    c3_y[c3_c] = c3_y[c3_b_c] + c3_c_a * c3_x[1];
  }
}

static void c3_i_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_y[4])
{
  real_T c3_b_a;
  real_T c3_c_a;
  int32_T c3_ix;
  int32_T c3_iy;
  int32_T c3_k;
  int32_T c3_d_a;
  int32_T c3_c;
  int32_T c3_e_a;
  int32_T c3_b_c;
  int32_T c3_f_a;
  int32_T c3_c_c;
  int32_T c3_g_a;
  int32_T c3_h_a;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  if (c3_c_a == 0.0) {
  } else {
    c3_ix = 0;
    c3_iy = 2;
    for (c3_k = 0; c3_k < 2; c3_k++) {
      c3_d_a = c3_iy;
      c3_c = c3_d_a;
      c3_e_a = c3_iy;
      c3_b_c = c3_e_a;
      c3_f_a = c3_ix;
      c3_c_c = c3_f_a;
      c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_c + 1, 1, 4, 1, 0) - 1] =
        c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_b_c + 1, 1, 4, 1, 0) - 1] +
        c3_c_a * c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_c_c + 1, 1, 4, 1, 0) -
        1];
      c3_g_a = c3_ix + 1;
      c3_ix = c3_g_a;
      c3_h_a = c3_iy + 1;
      c3_iy = c3_h_a;
    }
  }
}

static void c3_j_eml_xaxpy(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, int32_T c3_n, real_T c3_a, int32_T c3_ix0, real_T c3_y[9],
  int32_T c3_iy0)
{
  int32_T c3_b_n;
  real_T c3_b_a;
  int32_T c3_b_ix0;
  int32_T c3_b_iy0;
  int32_T c3_c_n;
  real_T c3_c_a;
  int32_T c3_c_ix0;
  int32_T c3_c_iy0;
  int32_T c3_d_a;
  int32_T c3_ix;
  int32_T c3_e_a;
  int32_T c3_iy;
  int32_T c3_f_a;
  int32_T c3_i131;
  int32_T c3_k;
  int32_T c3_g_a;
  int32_T c3_c;
  int32_T c3_h_a;
  int32_T c3_b_c;
  int32_T c3_i_a;
  int32_T c3_c_c;
  int32_T c3_j_a;
  int32_T c3_k_a;
  c3_b_n = c3_n;
  c3_b_a = c3_a;
  c3_b_ix0 = c3_ix0;
  c3_b_iy0 = c3_iy0;
  c3_c_n = c3_b_n;
  c3_c_a = c3_b_a;
  c3_c_ix0 = c3_b_ix0;
  c3_c_iy0 = c3_b_iy0;
  if (c3_c_n < 1) {
  } else if (c3_c_a == 0.0) {
  } else {
    c3_d_a = c3_c_ix0 - 1;
    c3_ix = c3_d_a;
    c3_e_a = c3_c_iy0 - 1;
    c3_iy = c3_e_a;
    c3_f_a = c3_c_n;
    c3_i131 = c3_f_a;
    for (c3_k = 0; c3_k < c3_i131; c3_k++) {
      c3_g_a = c3_iy;
      c3_c = c3_g_a;
      c3_h_a = c3_iy;
      c3_b_c = c3_h_a;
      c3_i_a = c3_ix;
      c3_c_c = c3_i_a;
      c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_c + 1, 1, 9, 1, 0) - 1] =
        c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_b_c + 1, 1, 9, 1, 0) - 1] +
        c3_c_a * c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_c_c + 1, 1, 9, 1, 0) -
        1];
      c3_j_a = c3_ix + 1;
      c3_ix = c3_j_a;
      c3_k_a = c3_iy + 1;
      c3_iy = c3_k_a;
    }
  }
}

static void c3_g_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[4], int32_T c3_ix0)
{
  real_T c3_b_a;
  int32_T c3_b_ix0;
  real_T c3_c_a;
  int32_T c3_c_ix0;
  int32_T c3_d_ix0;
  int32_T c3_d_a;
  int32_T c3_i132;
  int32_T c3_k;
  int32_T c3_b_k;
  c3_b_a = c3_a;
  c3_b_ix0 = c3_ix0;
  c3_c_a = c3_b_a;
  c3_c_ix0 = c3_b_ix0;
  c3_d_ix0 = c3_c_ix0;
  c3_d_a = c3_c_ix0;
  c3_i132 = c3_d_a;
  for (c3_k = c3_d_ix0; c3_k <= c3_i132 + 1; c3_k++) {
    c3_b_k = c3_k - 1;
    c3_x[c3_b_k] *= c3_c_a;
  }
}

static void c3_h_eml_xscal(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_a, real_T c3_x[9], int32_T c3_ix0)
{
  real_T c3_b_a;
  int32_T c3_b_ix0;
  real_T c3_c_a;
  int32_T c3_c_ix0;
  int32_T c3_d_ix0;
  int32_T c3_d_a;
  int32_T c3_i133;
  int32_T c3_k;
  int32_T c3_b_k;
  c3_b_a = c3_a;
  c3_b_ix0 = c3_ix0;
  c3_c_a = c3_b_a;
  c3_c_ix0 = c3_b_ix0;
  c3_d_ix0 = c3_c_ix0;
  c3_d_a = c3_c_ix0;
  c3_i133 = c3_d_a;
  for (c3_k = c3_d_ix0; c3_k <= c3_i133 + 2; c3_k++) {
    c3_b_k = c3_k - 1;
    c3_x[c3_b_k] *= c3_c_a;
  }
}

static void c3_b_sqrt(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                      *chartInstance, real_T *c3_x)
{
  if (*c3_x < 0.0) {
    c3_c_eml_error(chartInstance);
  }

  *c3_x = muDoubleScalarSqrt(*c3_x);
}

static void c3_b_eml_xrotg(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T *c3_a, real_T *c3_b, real_T *c3_c, real_T *c3_s)
{
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_c_b;
  real_T c3_c_a;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_e_b;
  real_T c3_e_a;
  real_T c3_b_c;
  real_T c3_b_s;
  double * c3_a_t;
  double * c3_b_t;
  double * c3_c_t;
  double * c3_s_t;
  real_T c3_c_c;
  real_T c3_c_s;
  c3_b_a = *c3_a;
  c3_b_b = *c3_b;
  c3_c_b = c3_b_b;
  c3_c_a = c3_b_a;
  c3_d_a = c3_c_a;
  c3_d_b = c3_c_b;
  c3_e_b = c3_d_b;
  c3_e_a = c3_d_a;
  c3_b_c = 0.0;
  c3_b_s = 0.0;
  c3_a_t = (double *)(&c3_e_a);
  c3_b_t = (double *)(&c3_e_b);
  c3_c_t = (double *)(&c3_b_c);
  c3_s_t = (double *)(&c3_b_s);
  drotg(c3_a_t, c3_b_t, c3_c_t, c3_s_t);
  c3_c_a = c3_e_a;
  c3_c_b = c3_e_b;
  c3_c_c = c3_b_c;
  c3_c_s = c3_b_s;
  *c3_a = c3_c_a;
  *c3_b = c3_c_b;
  *c3_c = c3_c_c;
  *c3_s = c3_c_s;
}

static void c3_c_eml_xrot(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x[9], int32_T c3_ix0, int32_T c3_iy0, real_T c3_c,
  real_T c3_s)
{
  int32_T c3_b_ix0;
  int32_T c3_b_iy0;
  real_T c3_b_c;
  real_T c3_b_s;
  int32_T c3_c_ix0;
  int32_T c3_c_iy0;
  real_T c3_c_c;
  real_T c3_c_s;
  int32_T c3_ix;
  int32_T c3_iy;
  int32_T c3_k;
  real_T c3_a;
  real_T c3_b;
  real_T c3_y;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_b_y;
  real_T c3_temp;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_c_y;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_d_y;
  int32_T c3_e_a;
  int32_T c3_f_a;
  c3_b_ix0 = c3_ix0;
  c3_b_iy0 = c3_iy0;
  c3_b_c = c3_c;
  c3_b_s = c3_s;
  c3_c_ix0 = c3_b_ix0;
  c3_c_iy0 = c3_b_iy0;
  c3_c_c = c3_b_c;
  c3_c_s = c3_b_s;
  c3_ix = c3_c_ix0 - 1;
  c3_iy = c3_c_iy0 - 1;
  for (c3_k = 1; c3_k < 4; c3_k++) {
    c3_a = c3_c_c;
    c3_b = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_ix + 1, 1, 9, 1, 0) - 1];
    c3_y = c3_a * c3_b;
    c3_b_a = c3_c_s;
    c3_b_b = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_iy + 1, 1, 9, 1, 0) - 1];
    c3_b_y = c3_b_a * c3_b_b;
    c3_temp = c3_y + c3_b_y;
    c3_c_a = c3_c_c;
    c3_c_b = c3_x[c3_iy];
    c3_c_y = c3_c_a * c3_c_b;
    c3_d_a = c3_c_s;
    c3_d_b = c3_x[c3_ix];
    c3_d_y = c3_d_a * c3_d_b;
    c3_x[c3_iy] = c3_c_y - c3_d_y;
    c3_x[c3_ix] = c3_temp;
    c3_e_a = c3_iy + 1;
    c3_iy = c3_e_a;
    c3_f_a = c3_ix + 1;
    c3_ix = c3_f_a;
  }
}

static void c3_d_eml_xrot(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
  *chartInstance, real_T c3_x[4], int32_T c3_ix0, int32_T c3_iy0, real_T c3_c,
  real_T c3_s)
{
  int32_T c3_b_ix0;
  int32_T c3_b_iy0;
  real_T c3_b_c;
  real_T c3_b_s;
  int32_T c3_c_ix0;
  int32_T c3_c_iy0;
  real_T c3_c_c;
  real_T c3_c_s;
  int32_T c3_ix;
  int32_T c3_iy;
  int32_T c3_k;
  real_T c3_a;
  real_T c3_b;
  real_T c3_y;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_b_y;
  real_T c3_temp;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_c_y;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_d_y;
  int32_T c3_e_a;
  int32_T c3_f_a;
  c3_b_ix0 = c3_ix0;
  c3_b_iy0 = c3_iy0;
  c3_b_c = c3_c;
  c3_b_s = c3_s;
  c3_c_ix0 = c3_b_ix0;
  c3_c_iy0 = c3_b_iy0;
  c3_c_c = c3_b_c;
  c3_c_s = c3_b_s;
  c3_ix = c3_c_ix0 - 1;
  c3_iy = c3_c_iy0 - 1;
  for (c3_k = 1; c3_k < 3; c3_k++) {
    c3_a = c3_c_c;
    c3_b = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_ix + 1, 1, 4, 1, 0) - 1];
    c3_y = c3_a * c3_b;
    c3_b_a = c3_c_s;
    c3_b_b = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_iy + 1, 1, 4, 1, 0) - 1];
    c3_b_y = c3_b_a * c3_b_b;
    c3_temp = c3_y + c3_b_y;
    c3_c_a = c3_c_c;
    c3_c_b = c3_x[c3_iy];
    c3_c_y = c3_c_a * c3_c_b;
    c3_d_a = c3_c_s;
    c3_d_b = c3_x[c3_ix];
    c3_d_y = c3_d_a * c3_d_b;
    c3_x[c3_iy] = c3_c_y - c3_d_y;
    c3_x[c3_ix] = c3_temp;
    c3_e_a = c3_iy + 1;
    c3_iy = c3_e_a;
    c3_f_a = c3_ix + 1;
    c3_ix = c3_f_a;
  }
}

static void c3_c_eml_xswap(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_x[9], int32_T c3_ix0, int32_T c3_iy0)
{
  int32_T c3_b_ix0;
  int32_T c3_b_iy0;
  int32_T c3_c_ix0;
  int32_T c3_c_iy0;
  int32_T c3_ix;
  int32_T c3_iy;
  int32_T c3_k;
  real_T c3_temp;
  int32_T c3_a;
  int32_T c3_b_a;
  c3_b_ix0 = c3_ix0;
  c3_b_iy0 = c3_iy0;
  c3_c_ix0 = c3_b_ix0;
  c3_c_iy0 = c3_b_iy0;
  c3_ix = c3_c_ix0;
  c3_iy = c3_c_iy0;
  for (c3_k = 1; c3_k < 4; c3_k++) {
    c3_temp = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_ix, 1, 9, 1, 0) - 1];
    c3_x[c3_ix - 1] = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_iy, 1, 9, 1, 0) -
      1];
    c3_x[c3_iy - 1] = c3_temp;
    c3_a = c3_ix + 1;
    c3_ix = c3_a;
    c3_b_a = c3_iy + 1;
    c3_iy = c3_b_a;
  }
}

static void c3_d_eml_xswap(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *
  chartInstance, real_T c3_x[4], int32_T c3_ix0, int32_T c3_iy0)
{
  int32_T c3_ix;
  int32_T c3_iy;
  int32_T c3_k;
  real_T c3_temp;
  int32_T c3_a;
  int32_T c3_b_a;
  c3_ix = 0;
  c3_iy = 2;
  for (c3_k = 1; c3_k < 3; c3_k++) {
    c3_temp = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_ix + 1, 1, 4, 1, 0) - 1];
    c3_x[c3_ix] = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_iy + 1, 1, 4, 1, 0) -
      1];
    c3_x[c3_iy] = c3_temp;
    c3_a = c3_ix + 1;
    c3_ix = c3_a;
    c3_b_a = c3_iy + 1;
    c3_iy = c3_b_a;
  }
}

static void c3_b_acos(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct
                      *chartInstance, real_T *c3_x)
{
  boolean_T guard1 = FALSE;
  guard1 = FALSE;
  if (*c3_x < -1.0) {
    guard1 = TRUE;
  } else {
    if (1.0 < *c3_x) {
      guard1 = TRUE;
    }
  }

  if (guard1 == TRUE) {
    c3_d_eml_error(chartInstance);
  }

  *c3_x = muDoubleScalarAcos(*c3_x);
}

static void init_dsm_address_info
  (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_Bowwave2Drogue_v6_addControl_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(301256316U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(434028223U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3438592628U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(540618964U);
}

mxArray *sf_c3_Bowwave2Drogue_v6_addControl_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("jx90Pqr6uolmTQ6b5LQkhH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(150);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Bowwave2Drogue_v6_addControl_test_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_Bowwave2Drogue_v6_addControl_test
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[6],T\"y\",},{M[8],M[0],T\"is_active_c3_Bowwave2Drogue_v6_addControl_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Bowwave2Drogue_v6_addControl_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
    chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Bowwave2Drogue_v6_addControl_testMachineNumber_,
           3,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_Bowwave2Drogue_v6_addControl_testMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _Bowwave2Drogue_v6_addControl_testMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Bowwave2Drogue_v6_addControl_testMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"y");
          _SFD_SET_DATA_PROPS(1,1,1,0,"PosPr1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"PosTb1");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1444);
        _SFD_CV_INIT_EML_IF(0,1,0,438,447,544,808);
        _SFD_CV_INIT_EML_IF(0,1,1,544,558,731,808);
        _SFD_CV_INIT_EML_IF(0,1,2,1114,1128,-1,1158);
        _SFD_CV_INIT_EML_FOR(0,1,0,355,368,1342);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 150;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 100;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c3_y)[150];
          real_T (*c3_PosPr1)[3];
          real_T (*c3_PosTb1)[100];
          c3_PosTb1 = (real_T (*)[100])ssGetInputPortSignal(chartInstance->S, 1);
          c3_PosPr1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          c3_y = (real_T (*)[150])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_y);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_PosPr1);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_PosTb1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Bowwave2Drogue_v6_addControl_testMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "09hoWOYx79E6Xu4RsI55wG";
}

static void sf_opaque_initialize_c3_Bowwave2Drogue_v6_addControl_test(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c3_Bowwave2Drogue_v6_addControl_test
    ((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*) chartInstanceVar);
  initialize_c3_Bowwave2Drogue_v6_addControl_test
    ((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Bowwave2Drogue_v6_addControl_test(void
  *chartInstanceVar)
{
  enable_c3_Bowwave2Drogue_v6_addControl_test
    ((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Bowwave2Drogue_v6_addControl_test(void
  *chartInstanceVar)
{
  disable_c3_Bowwave2Drogue_v6_addControl_test
    ((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Bowwave2Drogue_v6_addControl_test(void
  *chartInstanceVar)
{
  sf_c3_Bowwave2Drogue_v6_addControl_test
    ((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c3_Bowwave2Drogue_v6_addControl_test(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_Bowwave2Drogue_v6_addControl_test
    ((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c3_Bowwave2Drogue_v6_addControl_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c3_Bowwave2Drogue_v6_addControl_test
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c3_Bowwave2Drogue_v6_addControl_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_Bowwave2Drogue_v6_addControl_test
    ((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c3_Bowwave2Drogue_v6_addControl_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_Bowwave2Drogue_v6_addControl_test(S);
}

static void sf_opaque_set_sim_state_c3_Bowwave2Drogue_v6_addControl_test
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_Bowwave2Drogue_v6_addControl_test(S, st);
}

static void sf_opaque_terminate_c3_Bowwave2Drogue_v6_addControl_test(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Bowwave2Drogue_v6_addControl_test_optimization_info();
    }

    finalize_c3_Bowwave2Drogue_v6_addControl_test
      ((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Bowwave2Drogue_v6_addControl_test
    ((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Bowwave2Drogue_v6_addControl_test(SimStruct *
  S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Bowwave2Drogue_v6_addControl_test
      ((SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct*)(((ChartInfoStruct
          *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_Bowwave2Drogue_v6_addControl_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_Bowwave2Drogue_v6_addControl_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(781322664U));
  ssSetChecksum1(S,(4222933292U));
  ssSetChecksum2(S,(1798152209U));
  ssSetChecksum3(S,(555668178U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Bowwave2Drogue_v6_addControl_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Bowwave2Drogue_v6_addControl_test(SimStruct *S)
{
  SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct *)
    utMalloc(sizeof(SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc3_Bowwave2Drogue_v6_addControl_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_Bowwave2Drogue_v6_addControl_test;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_Bowwave2Drogue_v6_addControl_test;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_Bowwave2Drogue_v6_addControl_test;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_Bowwave2Drogue_v6_addControl_test;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_Bowwave2Drogue_v6_addControl_test;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_Bowwave2Drogue_v6_addControl_test;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_Bowwave2Drogue_v6_addControl_test;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_Bowwave2Drogue_v6_addControl_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Bowwave2Drogue_v6_addControl_test;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c3_Bowwave2Drogue_v6_addControl_test;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_Bowwave2Drogue_v6_addControl_test;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_Bowwave2Drogue_v6_addControl_test_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Bowwave2Drogue_v6_addControl_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Bowwave2Drogue_v6_addControl_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Bowwave2Drogue_v6_addControl_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Bowwave2Drogue_v6_addControl_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
