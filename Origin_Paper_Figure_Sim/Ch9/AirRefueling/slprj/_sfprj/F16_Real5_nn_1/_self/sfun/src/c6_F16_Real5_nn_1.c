/* Include files */

#include <stddef.h>
#include "blas.h"
#include "F16_Real5_nn_1_sfun.h"
#include "c6_F16_Real5_nn_1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "F16_Real5_nn_1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[4] = { "nargin", "nargout",
  "pos_dr2tk", "TkTur2dr" };

static const char * c6_b_debug_family_names[73] = { "airDensity1", "airSpeed1",
  "wingSpan1", "tankerWeight1", "gravity1", "vortexStrength", "wingTipLeftPos",
  "wingTipRightPos", "tailTipLeftPos", "tailTipRightPos", "tankerMassPos",
  "receiverPos", "rVorL", "tVorL", "TVorL", "vVorL", "rVorCoreL", "WVorL",
  "thetaVorL", "WVorLVector", "rVorR", "tVorR", "TVorR", "vVorR", "rVorCoreR",
  "WVorR", "thetaVorR", "WVorRVector", "rVorW", "tVorW", "LVorLength",
  "RVorLength", "gamaLCos", "gamaRCos", "TVorW", "vVorW", "rVorCoreW", "WVorW",
  "thetaVorW", "WVorWVector", "rVorLT", "tVorLT", "TVorLT", "vVorLT",
  "rVorCoreLT", "WVorLT", "thetaVorLT", "WVorLTVector", "rVorRT", "tVorRT",
  "TVorRT", "vVorRT", "rVorCoreRT", "WVorRT", "thetaVorRT", "WVorRTVector",
  "rVorT", "tVorT", "LVorLengthT", "RVorLengthT", "gamaLCosT", "gamaRCosT",
  "TVorT", "vVorT", "rVorCoreT", "WVorT", "thetaVorT", "WVorTVector",
  "WTotalVector", "nargin", "nargout", "PosReceiver", "y" };

/* Function Declarations */
static void initialize_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void initialize_params_c6_F16_Real5_nn_1
  (SFc6_F16_Real5_nn_1InstanceStruct *chartInstance);
static void enable_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void disable_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_F16_Real5_nn_1
  (SFc6_F16_Real5_nn_1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_F16_Real5_nn_1
  (SFc6_F16_Real5_nn_1InstanceStruct *chartInstance);
static void set_sim_state_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void sf_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void initSimStructsc6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void registerMessagesc6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct *
  chartInstance);
static void c6_TankerVortexWindField(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, real_T c6_PosReceiver[3], real_T c6_y[3]);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance,
  const mxArray *c6_TkTur2dr, const char_T *c6_identifier, real_T c6_y[3]);
static void c6_b_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[27]);
static real_T c6_mpower(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance, real_T
  c6_a);
static void c6_eml_scalar_eg(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance);
static real_T c6_sqrt(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance, real_T
                      c6_x);
static void c6_eml_error(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance);
static real_T c6_abs(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance, real_T
                     c6_x);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_d_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_e_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_F16_Real5_nn_1, const char_T *
  c6_identifier);
static uint8_T c6_f_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sqrt(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance, real_T
                      *c6_x);
static void init_dsm_address_info(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_F16_Real5_nn_1 = 0U;
}

static void initialize_params_c6_F16_Real5_nn_1
  (SFc6_F16_Real5_nn_1InstanceStruct *chartInstance)
{
}

static void enable_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_F16_Real5_nn_1
  (SFc6_F16_Real5_nn_1InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c6_F16_Real5_nn_1
  (SFc6_F16_Real5_nn_1InstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[3];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T (*c6_TkTur2dr)[3];
  c6_TkTur2dr = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2), FALSE);
  for (c6_i0 = 0; c6_i0 < 3; c6_i0++) {
    c6_u[c6_i0] = (*c6_TkTur2dr)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_F16_Real5_nn_1;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[3];
  int32_T c6_i1;
  real_T (*c6_TkTur2dr)[3];
  c6_TkTur2dr = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
                      "TkTur2dr", c6_dv0);
  for (c6_i1 = 0; c6_i1 < 3; c6_i1++) {
    (*c6_TkTur2dr)[c6_i1] = c6_dv0[c6_i1];
  }

  chartInstance->c6_is_active_c6_F16_Real5_nn_1 = c6_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_F16_Real5_nn_1");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_F16_Real5_nn_1(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
}

static void sf_c6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  real_T c6_pos_dr2tk[3];
  uint32_T c6_debug_family_var_map[4];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  real_T c6_TkTur2dr[3];
  int32_T c6_i5;
  real_T c6_b_pos_dr2tk[3];
  real_T c6_dv1[3];
  int32_T c6_i6;
  int32_T c6_i7;
  real_T (*c6_b_TkTur2dr)[3];
  real_T (*c6_c_pos_dr2tk)[3];
  c6_b_TkTur2dr = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_c_pos_dr2tk = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  for (c6_i2 = 0; c6_i2 < 3; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*c6_c_pos_dr2tk)[c6_i2], 0U);
  }

  for (c6_i3 = 0; c6_i3 < 3; c6_i3++) {
    _SFD_DATA_RANGE_CHECK((*c6_b_TkTur2dr)[c6_i3], 1U);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  for (c6_i4 = 0; c6_i4 < 3; c6_i4++) {
    c6_pos_dr2tk[c6_i4] = (*c6_c_pos_dr2tk)[c6_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_pos_dr2tk, 2U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_TkTur2dr, 3U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  for (c6_i5 = 0; c6_i5 < 3; c6_i5++) {
    c6_b_pos_dr2tk[c6_i5] = c6_pos_dr2tk[c6_i5];
  }

  c6_TankerVortexWindField(chartInstance, c6_b_pos_dr2tk, c6_dv1);
  for (c6_i6 = 0; c6_i6 < 3; c6_i6++) {
    c6_TkTur2dr[c6_i6] = c6_dv1[c6_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i7 = 0; c6_i7 < 3; c6_i7++) {
    (*c6_b_TkTur2dr)[c6_i7] = c6_TkTur2dr[c6_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_F16_Real5_nn_1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc6_F16_Real5_nn_1(SFc6_F16_Real5_nn_1InstanceStruct *
  chartInstance)
{
}

static void c6_TankerVortexWindField(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, real_T c6_PosReceiver[3], real_T c6_y[3])
{
  uint32_T c6_debug_family_var_map[73];
  real_T c6_airDensity1;
  real_T c6_airSpeed1;
  real_T c6_wingSpan1;
  real_T c6_tankerWeight1;
  real_T c6_gravity1;
  real_T c6_vortexStrength;
  real_T c6_wingTipLeftPos[3];
  real_T c6_wingTipRightPos[3];
  real_T c6_tailTipLeftPos[3];
  real_T c6_tailTipRightPos[3];
  real_T c6_tankerMassPos[3];
  real_T c6_receiverPos[3];
  real_T c6_rVorL;
  real_T c6_tVorL;
  real_T c6_TVorL;
  real_T c6_vVorL;
  real_T c6_rVorCoreL;
  real_T c6_WVorL;
  real_T c6_thetaVorL;
  real_T c6_WVorLVector[3];
  real_T c6_rVorR;
  real_T c6_tVorR;
  real_T c6_TVorR;
  real_T c6_vVorR;
  real_T c6_rVorCoreR;
  real_T c6_WVorR;
  real_T c6_thetaVorR;
  real_T c6_WVorRVector[3];
  real_T c6_rVorW;
  real_T c6_tVorW;
  real_T c6_LVorLength;
  real_T c6_RVorLength;
  real_T c6_gamaLCos;
  real_T c6_gamaRCos;
  real_T c6_TVorW;
  real_T c6_vVorW;
  real_T c6_rVorCoreW;
  real_T c6_WVorW;
  real_T c6_thetaVorW;
  real_T c6_WVorWVector[3];
  real_T c6_rVorLT;
  real_T c6_tVorLT;
  real_T c6_TVorLT;
  real_T c6_vVorLT;
  real_T c6_rVorCoreLT;
  real_T c6_WVorLT;
  real_T c6_thetaVorLT;
  real_T c6_WVorLTVector[3];
  real_T c6_rVorRT;
  real_T c6_tVorRT;
  real_T c6_TVorRT;
  real_T c6_vVorRT;
  real_T c6_rVorCoreRT;
  real_T c6_WVorRT;
  real_T c6_thetaVorRT;
  real_T c6_WVorRTVector[3];
  real_T c6_rVorT;
  real_T c6_tVorT;
  real_T c6_LVorLengthT;
  real_T c6_RVorLengthT;
  real_T c6_gamaLCosT;
  real_T c6_gamaRCosT;
  real_T c6_TVorT;
  real_T c6_vVorT;
  real_T c6_rVorCoreT;
  real_T c6_WVorT;
  real_T c6_thetaVorT;
  real_T c6_WVorTVector[3];
  real_T c6_WTotalVector[3];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i8;
  static real_T c6_dv2[3] = { 0.0, -20.0, 0.0 };

  int32_T c6_i9;
  static real_T c6_dv3[3] = { 0.0, 20.0, 0.0 };

  int32_T c6_i10;
  static real_T c6_dv4[3] = { -12.44, -6.515, -1.27 };

  int32_T c6_i11;
  static real_T c6_dv5[3] = { -12.44, 6.515, -1.27 };

  int32_T c6_i12;
  int32_T c6_i13;
  real_T c6_A;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_b;
  real_T c6_b_y;
  real_T c6_b_b;
  real_T c6_c_b;
  real_T c6_c_y;
  real_T c6_d_b;
  real_T c6_d_y;
  real_T c6_b_A;
  real_T c6_B;
  real_T c6_c_x;
  real_T c6_e_y;
  real_T c6_d_x;
  real_T c6_f_y;
  real_T c6_g_y;
  real_T c6_e_b;
  real_T c6_h_y;
  real_T c6_c_A;
  real_T c6_b_B;
  real_T c6_e_x;
  real_T c6_i_y;
  real_T c6_f_x;
  real_T c6_j_y;
  real_T c6_k_y;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_a;
  real_T c6_f_b;
  real_T c6_d_A;
  real_T c6_c_B;
  real_T c6_i_x;
  real_T c6_l_y;
  real_T c6_j_x;
  real_T c6_m_y;
  real_T c6_n_y;
  real_T c6_k_x;
  real_T c6_l_x;
  real_T c6_m_x;
  real_T c6_n_x;
  real_T c6_b_a;
  real_T c6_g_b;
  real_T c6_o_y;
  real_T c6_o_x;
  real_T c6_p_x;
  real_T c6_c_a;
  real_T c6_h_b;
  real_T c6_p_y;
  real_T c6_dv6[3];
  int32_T c6_i14;
  real_T c6_e_A;
  real_T c6_q_x;
  real_T c6_r_x;
  real_T c6_i_b;
  real_T c6_q_y;
  real_T c6_j_b;
  real_T c6_k_b;
  real_T c6_r_y;
  real_T c6_l_b;
  real_T c6_s_y;
  real_T c6_f_A;
  real_T c6_d_B;
  real_T c6_s_x;
  real_T c6_t_y;
  real_T c6_t_x;
  real_T c6_u_y;
  real_T c6_v_y;
  real_T c6_m_b;
  real_T c6_w_y;
  real_T c6_g_A;
  real_T c6_e_B;
  real_T c6_u_x;
  real_T c6_x_y;
  real_T c6_v_x;
  real_T c6_y_y;
  real_T c6_ab_y;
  real_T c6_w_x;
  real_T c6_x_x;
  real_T c6_d_a;
  real_T c6_n_b;
  real_T c6_h_A;
  real_T c6_f_B;
  real_T c6_y_x;
  real_T c6_bb_y;
  real_T c6_ab_x;
  real_T c6_cb_y;
  real_T c6_db_y;
  real_T c6_bb_x;
  real_T c6_cb_x;
  real_T c6_db_x;
  real_T c6_eb_x;
  real_T c6_e_a;
  real_T c6_o_b;
  real_T c6_eb_y;
  real_T c6_fb_x;
  real_T c6_gb_x;
  real_T c6_f_a;
  real_T c6_p_b;
  real_T c6_fb_y;
  real_T c6_dv7[3];
  int32_T c6_i15;
  real_T c6_i_A;
  real_T c6_hb_x;
  real_T c6_ib_x;
  real_T c6_j_A;
  real_T c6_g_B;
  real_T c6_jb_x;
  real_T c6_gb_y;
  real_T c6_kb_x;
  real_T c6_hb_y;
  real_T c6_k_A;
  real_T c6_h_B;
  real_T c6_lb_x;
  real_T c6_ib_y;
  real_T c6_mb_x;
  real_T c6_jb_y;
  real_T c6_q_b;
  real_T c6_kb_y;
  real_T c6_l_A;
  real_T c6_nb_x;
  real_T c6_ob_x;
  real_T c6_lb_y;
  real_T c6_g_a;
  real_T c6_mb_y;
  real_T c6_m_A;
  real_T c6_pb_x;
  real_T c6_qb_x;
  real_T c6_r_b;
  real_T c6_h_a;
  real_T c6_s_b;
  real_T c6_nb_y;
  real_T c6_t_b;
  real_T c6_i_a;
  real_T c6_u_b;
  real_T c6_ob_y;
  real_T c6_v_b;
  real_T c6_pb_y;
  real_T c6_n_A;
  real_T c6_i_B;
  real_T c6_rb_x;
  real_T c6_qb_y;
  real_T c6_sb_x;
  real_T c6_rb_y;
  real_T c6_sb_y;
  real_T c6_w_b;
  real_T c6_tb_y;
  real_T c6_j_a;
  real_T c6_x_b;
  real_T c6_ub_y;
  real_T c6_o_A;
  real_T c6_j_B;
  real_T c6_tb_x;
  real_T c6_vb_y;
  real_T c6_ub_x;
  real_T c6_wb_y;
  real_T c6_xb_y;
  real_T c6_vb_x;
  real_T c6_wb_x;
  real_T c6_k_a;
  real_T c6_y_b;
  real_T c6_p_A;
  real_T c6_k_B;
  real_T c6_xb_x;
  real_T c6_yb_y;
  real_T c6_yb_x;
  real_T c6_ac_y;
  real_T c6_bc_y;
  real_T c6_ac_x;
  real_T c6_bc_x;
  real_T c6_cc_x;
  real_T c6_dc_x;
  real_T c6_l_a;
  real_T c6_ab_b;
  real_T c6_cc_y;
  real_T c6_ec_x;
  real_T c6_fc_x;
  real_T c6_m_a;
  real_T c6_bb_b;
  real_T c6_dc_y;
  real_T c6_ec_y[3];
  int32_T c6_i16;
  real_T c6_q_A;
  real_T c6_gc_x;
  real_T c6_hc_x;
  real_T c6_cb_b;
  real_T c6_fc_y;
  real_T c6_db_b;
  real_T c6_eb_b;
  real_T c6_gc_y;
  real_T c6_fb_b;
  real_T c6_hc_y;
  real_T c6_r_A;
  real_T c6_l_B;
  real_T c6_ic_x;
  real_T c6_ic_y;
  real_T c6_jc_x;
  real_T c6_jc_y;
  real_T c6_kc_y;
  real_T c6_gb_b;
  real_T c6_lc_y;
  real_T c6_s_A;
  real_T c6_m_B;
  real_T c6_kc_x;
  real_T c6_mc_y;
  real_T c6_lc_x;
  real_T c6_nc_y;
  real_T c6_oc_y;
  real_T c6_mc_x;
  real_T c6_nc_x;
  real_T c6_n_a;
  real_T c6_hb_b;
  real_T c6_t_A;
  real_T c6_n_B;
  real_T c6_oc_x;
  real_T c6_pc_y;
  real_T c6_pc_x;
  real_T c6_qc_y;
  real_T c6_rc_y;
  real_T c6_qc_x;
  real_T c6_rc_x;
  real_T c6_sc_x;
  real_T c6_tc_x;
  real_T c6_o_a;
  real_T c6_ib_b;
  real_T c6_sc_y;
  real_T c6_uc_x;
  real_T c6_vc_x;
  real_T c6_p_a;
  real_T c6_jb_b;
  real_T c6_tc_y;
  real_T c6_dv8[3];
  int32_T c6_i17;
  real_T c6_u_A;
  real_T c6_wc_x;
  real_T c6_xc_x;
  real_T c6_kb_b;
  real_T c6_uc_y;
  real_T c6_lb_b;
  real_T c6_mb_b;
  real_T c6_vc_y;
  real_T c6_nb_b;
  real_T c6_wc_y;
  real_T c6_v_A;
  real_T c6_o_B;
  real_T c6_yc_x;
  real_T c6_xc_y;
  real_T c6_ad_x;
  real_T c6_yc_y;
  real_T c6_ad_y;
  real_T c6_ob_b;
  real_T c6_bd_y;
  real_T c6_w_A;
  real_T c6_p_B;
  real_T c6_bd_x;
  real_T c6_cd_y;
  real_T c6_cd_x;
  real_T c6_dd_y;
  real_T c6_ed_y;
  real_T c6_dd_x;
  real_T c6_ed_x;
  real_T c6_q_a;
  real_T c6_pb_b;
  real_T c6_x_A;
  real_T c6_q_B;
  real_T c6_fd_x;
  real_T c6_fd_y;
  real_T c6_gd_x;
  real_T c6_gd_y;
  real_T c6_hd_y;
  real_T c6_hd_x;
  real_T c6_id_x;
  real_T c6_jd_x;
  real_T c6_kd_x;
  real_T c6_r_a;
  real_T c6_qb_b;
  real_T c6_id_y;
  real_T c6_ld_x;
  real_T c6_md_x;
  real_T c6_s_a;
  real_T c6_rb_b;
  real_T c6_jd_y;
  real_T c6_dv9[3];
  int32_T c6_i18;
  real_T c6_y_A;
  real_T c6_nd_x;
  real_T c6_od_x;
  real_T c6_ab_A;
  real_T c6_r_B;
  real_T c6_pd_x;
  real_T c6_kd_y;
  real_T c6_qd_x;
  real_T c6_ld_y;
  real_T c6_bb_A;
  real_T c6_s_B;
  real_T c6_rd_x;
  real_T c6_md_y;
  real_T c6_sd_x;
  real_T c6_nd_y;
  real_T c6_sb_b;
  real_T c6_od_y;
  real_T c6_cb_A;
  real_T c6_td_x;
  real_T c6_ud_x;
  real_T c6_pd_y;
  real_T c6_t_a;
  real_T c6_qd_y;
  real_T c6_db_A;
  real_T c6_vd_x;
  real_T c6_wd_x;
  real_T c6_tb_b;
  real_T c6_u_a;
  real_T c6_ub_b;
  real_T c6_rd_y;
  real_T c6_vb_b;
  real_T c6_v_a;
  real_T c6_wb_b;
  real_T c6_sd_y;
  real_T c6_xb_b;
  real_T c6_td_y;
  real_T c6_eb_A;
  real_T c6_t_B;
  real_T c6_xd_x;
  real_T c6_ud_y;
  real_T c6_yd_x;
  real_T c6_vd_y;
  real_T c6_wd_y;
  real_T c6_yb_b;
  real_T c6_xd_y;
  real_T c6_w_a;
  real_T c6_ac_b;
  real_T c6_yd_y;
  real_T c6_fb_A;
  real_T c6_u_B;
  real_T c6_ae_x;
  real_T c6_ae_y;
  real_T c6_be_x;
  real_T c6_be_y;
  real_T c6_ce_y;
  real_T c6_ce_x;
  real_T c6_de_x;
  real_T c6_x_a;
  real_T c6_bc_b;
  real_T c6_gb_A;
  real_T c6_v_B;
  real_T c6_ee_x;
  real_T c6_de_y;
  real_T c6_fe_x;
  real_T c6_ee_y;
  real_T c6_fe_y;
  real_T c6_ge_x;
  real_T c6_he_x;
  real_T c6_ie_x;
  real_T c6_je_x;
  real_T c6_y_a;
  real_T c6_cc_b;
  real_T c6_ge_y;
  real_T c6_ke_x;
  real_T c6_le_x;
  real_T c6_ab_a;
  real_T c6_dc_b;
  real_T c6_he_y;
  real_T c6_ie_y[3];
  int32_T c6_i19;
  int32_T c6_i20;
  int32_T c6_i21;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 73U, 73U, c6_b_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_airDensity1, 0U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_airSpeed1, 1U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_wingSpan1, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_tankerWeight1, 3U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_gravity1, 4U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_vortexStrength, 5U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_wingTipLeftPos, 6U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_wingTipRightPos, 7U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_tailTipLeftPos, 8U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_tailTipRightPos, 9U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tankerMassPos, 10U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_receiverPos, 11U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorL, 12U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_tVorL, 13U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_TVorL, 14U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_vVorL, 15U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorCoreL, 16U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_WVorL, 17U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_thetaVorL, 18U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_WVorLVector, 19U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorR, 20U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_tVorR, 21U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_TVorR, 22U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_vVorR, 23U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorCoreR, 24U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_WVorR, 25U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_thetaVorR, 26U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_WVorRVector, 27U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorW, 28U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_tVorW, 29U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_LVorLength, 30U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_RVorLength, 31U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_gamaLCos, 32U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_gamaRCos, 33U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_TVorW, 34U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_vVorW, 35U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorCoreW, 36U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_WVorW, 37U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_thetaVorW, 38U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_WVorWVector, 39U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorLT, 40U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_tVorLT, 41U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_TVorLT, 42U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_vVorLT, 43U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorCoreLT, 44U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_WVorLT, 45U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_thetaVorLT, 46U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_WVorLTVector, 47U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorRT, 48U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_tVorRT, 49U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_TVorRT, 50U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_vVorRT, 51U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorCoreRT, 52U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_WVorRT, 53U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_thetaVorRT, 54U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_WVorRTVector, 55U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorT, 56U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_tVorT, 57U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_LVorLengthT, 58U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_RVorLengthT, 59U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_gamaLCosT, 60U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_gamaRCosT, 61U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_TVorT, 62U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_vVorT, 63U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_rVorCoreT, 64U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_WVorT, 65U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_thetaVorT, 66U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_WVorTVector, 67U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_WTotalVector, 68U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 69U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 70U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_PosReceiver, 71U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_y, 72U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_airDensity1 = 0.5895;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_airSpeed1 = 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  c6_wingSpan1 = 40.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  c6_tankerWeight1 = 80000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  c6_gravity1 = 9.79434;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 14);
  c6_vortexStrength = 222.67829119381088;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 19);
  for (c6_i8 = 0; c6_i8 < 3; c6_i8++) {
    c6_wingTipLeftPos[c6_i8] = c6_dv2[c6_i8];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 20);
  for (c6_i9 = 0; c6_i9 < 3; c6_i9++) {
    c6_wingTipRightPos[c6_i9] = c6_dv3[c6_i9];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 23);
  for (c6_i10 = 0; c6_i10 < 3; c6_i10++) {
    c6_tailTipLeftPos[c6_i10] = c6_dv4[c6_i10];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 24);
  for (c6_i11 = 0; c6_i11 < 3; c6_i11++) {
    c6_tailTipRightPos[c6_i11] = c6_dv5[c6_i11];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 27);
  for (c6_i12 = 0; c6_i12 < 3; c6_i12++) {
    c6_tankerMassPos[c6_i12] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 30);
  for (c6_i13 = 0; c6_i13 < 3; c6_i13++) {
    c6_receiverPos[c6_i13] = c6_PosReceiver[c6_i13] + c6_tankerMassPos[c6_i13];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 33);
  c6_rVorL = c6_mpower(chartInstance, c6_receiverPos[1] - c6_wingTipLeftPos[1])
    + c6_mpower(chartInstance, c6_receiverPos[2] - c6_wingTipLeftPos[2]);
  c6_b_sqrt(chartInstance, &c6_rVorL);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 34);
  c6_A = -c6_receiverPos[0];
  c6_x = c6_A;
  c6_b_x = c6_x;
  c6_tVorL = c6_b_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 35);
  c6_TVorL = 222.67829119381088;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 36);
  c6_vVorL = 13.360697471628653;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 37);
  c6_b = c6_tVorL;
  c6_b_y = 13.360697471628653 * c6_b;
  c6_b_b = c6_abs(chartInstance, c6_b_y);
  c6_b_sqrt(chartInstance, &c6_b_b);
  c6_rVorCoreL = 2.24 * c6_b_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 40);
  c6_c_b = c6_rVorL;
  c6_c_y = 222.67829119381088 * c6_c_b;
  c6_d_b = c6_mpower(chartInstance, c6_rVorL) + c6_mpower(chartInstance,
    c6_rVorCoreL);
  c6_d_y = 6.2831853071795862 * c6_d_b;
  c6_b_A = c6_c_y;
  c6_B = c6_d_y;
  c6_c_x = c6_b_A;
  c6_e_y = c6_B;
  c6_d_x = c6_c_x;
  c6_f_y = c6_e_y;
  c6_g_y = c6_d_x / c6_f_y;
  c6_e_b = c6_tVorL;
  c6_h_y = 53.44278988651461 * c6_e_b;
  c6_c_A = -c6_mpower(chartInstance, c6_rVorL);
  c6_b_B = c6_h_y;
  c6_e_x = c6_c_A;
  c6_i_y = c6_b_B;
  c6_f_x = c6_e_x;
  c6_j_y = c6_i_y;
  c6_k_y = c6_f_x / c6_j_y;
  c6_g_x = c6_k_y;
  c6_h_x = c6_g_x;
  c6_h_x = muDoubleScalarExp(c6_h_x);
  c6_a = c6_g_y;
  c6_f_b = 1.0 - c6_h_x;
  c6_WVorL = c6_a * c6_f_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 41);
  c6_d_A = c6_receiverPos[2] - c6_wingTipLeftPos[2];
  c6_c_B = c6_receiverPos[1] - c6_wingTipLeftPos[1];
  c6_i_x = c6_d_A;
  c6_l_y = c6_c_B;
  c6_j_x = c6_i_x;
  c6_m_y = c6_l_y;
  c6_n_y = c6_j_x / c6_m_y;
  c6_k_x = c6_n_y;
  c6_thetaVorL = c6_k_x;
  c6_l_x = c6_thetaVorL;
  c6_thetaVorL = c6_l_x;
  c6_thetaVorL = muDoubleScalarAtan(c6_thetaVorL);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 42);
  if (CV_SCRIPT_IF(0, 0, c6_thetaVorL < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 43);
    c6_thetaVorL += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 46);
  c6_m_x = c6_thetaVorL;
  c6_n_x = c6_m_x;
  c6_n_x = muDoubleScalarSin(c6_n_x);
  c6_b_a = -c6_WVorL;
  c6_g_b = c6_n_x;
  c6_o_y = c6_b_a * c6_g_b;
  c6_o_x = c6_thetaVorL;
  c6_p_x = c6_o_x;
  c6_p_x = muDoubleScalarCos(c6_p_x);
  c6_c_a = c6_WVorL;
  c6_h_b = c6_p_x;
  c6_p_y = c6_c_a * c6_h_b;
  c6_dv6[0] = 0.0;
  c6_dv6[1] = c6_o_y;
  c6_dv6[2] = c6_p_y;
  for (c6_i14 = 0; c6_i14 < 3; c6_i14++) {
    c6_WVorLVector[c6_i14] = c6_dv6[c6_i14];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 50);
  c6_rVorR = c6_mpower(chartInstance, c6_receiverPos[1] - c6_wingTipRightPos[1])
    + c6_mpower(chartInstance, c6_receiverPos[2] - c6_wingTipRightPos[2]);
  c6_b_sqrt(chartInstance, &c6_rVorR);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 51);
  c6_e_A = -c6_receiverPos[0];
  c6_q_x = c6_e_A;
  c6_r_x = c6_q_x;
  c6_tVorR = c6_r_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 52);
  c6_TVorR = 222.67829119381088;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 53);
  c6_vVorR = 13.360697471628653;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 54);
  c6_i_b = c6_tVorR;
  c6_q_y = 13.360697471628653 * c6_i_b;
  c6_j_b = c6_abs(chartInstance, c6_q_y);
  c6_b_sqrt(chartInstance, &c6_j_b);
  c6_rVorCoreR = 2.24 * c6_j_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 56);
  c6_k_b = c6_rVorR;
  c6_r_y = 222.67829119381088 * c6_k_b;
  c6_l_b = c6_mpower(chartInstance, c6_rVorR) + c6_mpower(chartInstance,
    c6_rVorCoreR);
  c6_s_y = 6.2831853071795862 * c6_l_b;
  c6_f_A = c6_r_y;
  c6_d_B = c6_s_y;
  c6_s_x = c6_f_A;
  c6_t_y = c6_d_B;
  c6_t_x = c6_s_x;
  c6_u_y = c6_t_y;
  c6_v_y = c6_t_x / c6_u_y;
  c6_m_b = c6_tVorR;
  c6_w_y = 53.44278988651461 * c6_m_b;
  c6_g_A = -c6_mpower(chartInstance, c6_rVorR);
  c6_e_B = c6_w_y;
  c6_u_x = c6_g_A;
  c6_x_y = c6_e_B;
  c6_v_x = c6_u_x;
  c6_y_y = c6_x_y;
  c6_ab_y = c6_v_x / c6_y_y;
  c6_w_x = c6_ab_y;
  c6_x_x = c6_w_x;
  c6_x_x = muDoubleScalarExp(c6_x_x);
  c6_d_a = c6_v_y;
  c6_n_b = 1.0 - c6_x_x;
  c6_WVorR = c6_d_a * c6_n_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 57);
  c6_h_A = c6_receiverPos[2] - c6_wingTipRightPos[2];
  c6_f_B = -c6_receiverPos[1] + c6_wingTipRightPos[1];
  c6_y_x = c6_h_A;
  c6_bb_y = c6_f_B;
  c6_ab_x = c6_y_x;
  c6_cb_y = c6_bb_y;
  c6_db_y = c6_ab_x / c6_cb_y;
  c6_bb_x = c6_db_y;
  c6_thetaVorR = c6_bb_x;
  c6_cb_x = c6_thetaVorR;
  c6_thetaVorR = c6_cb_x;
  c6_thetaVorR = muDoubleScalarAtan(c6_thetaVorR);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 58);
  if (CV_SCRIPT_IF(0, 1, -c6_receiverPos[1] + c6_wingTipRightPos[1] < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 59);
    c6_thetaVorR += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 62);
  c6_db_x = c6_thetaVorR;
  c6_eb_x = c6_db_x;
  c6_eb_x = muDoubleScalarSin(c6_eb_x);
  c6_e_a = c6_WVorR;
  c6_o_b = c6_eb_x;
  c6_eb_y = c6_e_a * c6_o_b;
  c6_fb_x = c6_thetaVorR;
  c6_gb_x = c6_fb_x;
  c6_gb_x = muDoubleScalarCos(c6_gb_x);
  c6_f_a = c6_WVorR;
  c6_p_b = c6_gb_x;
  c6_fb_y = c6_f_a * c6_p_b;
  c6_dv7[0] = 0.0;
  c6_dv7[1] = c6_eb_y;
  c6_dv7[2] = c6_fb_y;
  for (c6_i15 = 0; c6_i15 < 3; c6_i15++) {
    c6_WVorRVector[c6_i15] = c6_dv7[c6_i15];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 66);
  c6_rVorW = c6_mpower(chartInstance, c6_receiverPos[0] - c6_wingTipRightPos[0])
    + c6_mpower(chartInstance, c6_receiverPos[2] - c6_wingTipRightPos[2]);
  c6_b_sqrt(chartInstance, &c6_rVorW);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 67);
  c6_i_A = -c6_receiverPos[0];
  c6_hb_x = c6_i_A;
  c6_ib_x = c6_hb_x;
  c6_tVorW = c6_ib_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 69);
  c6_LVorLength = (c6_mpower(chartInstance, c6_receiverPos[0] -
    c6_wingTipLeftPos[0]) + c6_mpower(chartInstance, c6_receiverPos[1] -
    -15.707963267948966)) + c6_mpower(chartInstance, c6_receiverPos[2] -
    c6_wingTipLeftPos[2]);
  c6_b_sqrt(chartInstance, &c6_LVorLength);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 70);
  c6_RVorLength = (c6_mpower(chartInstance, c6_receiverPos[0] -
    c6_wingTipRightPos[0]) + c6_mpower(chartInstance, c6_receiverPos[1] -
    15.707963267948966)) + c6_mpower(chartInstance, c6_receiverPos[2] -
    c6_wingTipRightPos[2]);
  c6_b_sqrt(chartInstance, &c6_RVorLength);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 72);
  c6_j_A = c6_receiverPos[1] - -15.707963267948966;
  c6_g_B = c6_LVorLength;
  c6_jb_x = c6_j_A;
  c6_gb_y = c6_g_B;
  c6_kb_x = c6_jb_x;
  c6_hb_y = c6_gb_y;
  c6_gamaLCos = c6_kb_x / c6_hb_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 73);
  c6_k_A = -c6_receiverPos[1] + 15.707963267948966;
  c6_h_B = c6_RVorLength;
  c6_lb_x = c6_k_A;
  c6_ib_y = c6_h_B;
  c6_mb_x = c6_lb_x;
  c6_jb_y = c6_ib_y;
  c6_gamaRCos = c6_mb_x / c6_jb_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 75);
  c6_q_b = c6_gamaLCos + c6_gamaRCos;
  c6_kb_y = 222.67829119381088 * c6_q_b;
  c6_l_A = c6_kb_y;
  c6_nb_x = c6_l_A;
  c6_ob_x = c6_nb_x;
  c6_lb_y = c6_ob_x / 2.0;
  c6_g_a = c6_lb_y;
  c6_mb_y = c6_g_a * 4.0;
  c6_m_A = c6_mb_y;
  c6_pb_x = c6_m_A;
  c6_qb_x = c6_pb_x;
  c6_TVorW = c6_qb_x / 3.1415926535897931;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 76);
  c6_r_b = c6_TVorW;
  c6_vVorW = 0.06 * c6_r_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 77);
  c6_h_a = c6_vVorW;
  c6_s_b = c6_tVorW;
  c6_nb_y = c6_h_a * c6_s_b;
  c6_t_b = c6_abs(chartInstance, c6_nb_y);
  c6_b_sqrt(chartInstance, &c6_t_b);
  c6_rVorCoreW = 2.24 * c6_t_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 79);
  c6_i_a = c6_TVorW;
  c6_u_b = c6_rVorW;
  c6_ob_y = c6_i_a * c6_u_b;
  c6_v_b = c6_mpower(chartInstance, c6_rVorW) + c6_mpower(chartInstance,
    c6_rVorCoreW);
  c6_pb_y = 6.2831853071795862 * c6_v_b;
  c6_n_A = c6_ob_y;
  c6_i_B = c6_pb_y;
  c6_rb_x = c6_n_A;
  c6_qb_y = c6_i_B;
  c6_sb_x = c6_rb_x;
  c6_rb_y = c6_qb_y;
  c6_sb_y = c6_sb_x / c6_rb_y;
  c6_w_b = c6_vVorW;
  c6_tb_y = 4.0 * c6_w_b;
  c6_j_a = c6_tb_y;
  c6_x_b = c6_tVorW;
  c6_ub_y = c6_j_a * c6_x_b;
  c6_o_A = -c6_mpower(chartInstance, c6_rVorW);
  c6_j_B = c6_ub_y;
  c6_tb_x = c6_o_A;
  c6_vb_y = c6_j_B;
  c6_ub_x = c6_tb_x;
  c6_wb_y = c6_vb_y;
  c6_xb_y = c6_ub_x / c6_wb_y;
  c6_vb_x = c6_xb_y;
  c6_wb_x = c6_vb_x;
  c6_wb_x = muDoubleScalarExp(c6_wb_x);
  c6_k_a = c6_sb_y;
  c6_y_b = 1.0 - c6_wb_x;
  c6_WVorW = c6_k_a * c6_y_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 80);
  c6_p_A = c6_receiverPos[2] - c6_wingTipRightPos[2];
  c6_k_B = -c6_receiverPos[0] + c6_wingTipRightPos[0];
  c6_xb_x = c6_p_A;
  c6_yb_y = c6_k_B;
  c6_yb_x = c6_xb_x;
  c6_ac_y = c6_yb_y;
  c6_bc_y = c6_yb_x / c6_ac_y;
  c6_ac_x = c6_bc_y;
  c6_thetaVorW = c6_ac_x;
  c6_bc_x = c6_thetaVorW;
  c6_thetaVorW = c6_bc_x;
  c6_thetaVorW = muDoubleScalarAtan(c6_thetaVorW);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 81);
  if (CV_SCRIPT_IF(0, 2, -c6_receiverPos[0] + c6_wingTipRightPos[0] < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 82);
    c6_thetaVorW += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 85);
  c6_cc_x = c6_thetaVorW;
  c6_dc_x = c6_cc_x;
  c6_dc_x = muDoubleScalarSin(c6_dc_x);
  c6_l_a = c6_WVorW;
  c6_ab_b = c6_dc_x;
  c6_cc_y = c6_l_a * c6_ab_b;
  c6_ec_x = c6_thetaVorW;
  c6_fc_x = c6_ec_x;
  c6_fc_x = muDoubleScalarCos(c6_fc_x);
  c6_m_a = c6_WVorW;
  c6_bb_b = c6_fc_x;
  c6_dc_y = c6_m_a * c6_bb_b;
  c6_ec_y[0] = c6_cc_y;
  c6_ec_y[1] = 0.0;
  c6_ec_y[2] = c6_dc_y;
  for (c6_i16 = 0; c6_i16 < 3; c6_i16++) {
    c6_WVorWVector[c6_i16] = c6_ec_y[c6_i16];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 89);
  c6_rVorLT = c6_mpower(chartInstance, c6_receiverPos[1] - c6_wingTipLeftPos[1])
    + c6_mpower(chartInstance, c6_receiverPos[2] - c6_wingTipLeftPos[2]);
  c6_b_sqrt(chartInstance, &c6_rVorLT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 90);
  c6_q_A = -(c6_receiverPos[0] - c6_wingTipLeftPos[0]);
  c6_gc_x = c6_q_A;
  c6_hc_x = c6_gc_x;
  c6_tVorLT = c6_hc_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 91);
  c6_TVorLT = 7.4226097064603627;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 92);
  c6_vVorLT = 0.44535658238762177;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 93);
  c6_cb_b = c6_tVorLT;
  c6_fc_y = 0.44535658238762177 * c6_cb_b;
  c6_db_b = c6_abs(chartInstance, c6_fc_y);
  c6_b_sqrt(chartInstance, &c6_db_b);
  c6_rVorCoreLT = 2.24 * c6_db_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 95);
  c6_eb_b = c6_rVorLT;
  c6_gc_y = 7.4226097064603627 * c6_eb_b;
  c6_fb_b = c6_mpower(chartInstance, c6_rVorLT) + c6_mpower(chartInstance,
    c6_rVorCoreLT);
  c6_hc_y = 6.2831853071795862 * c6_fb_b;
  c6_r_A = c6_gc_y;
  c6_l_B = c6_hc_y;
  c6_ic_x = c6_r_A;
  c6_ic_y = c6_l_B;
  c6_jc_x = c6_ic_x;
  c6_jc_y = c6_ic_y;
  c6_kc_y = c6_jc_x / c6_jc_y;
  c6_gb_b = c6_tVorLT;
  c6_lc_y = 1.7814263295504871 * c6_gb_b;
  c6_s_A = -c6_mpower(chartInstance, c6_rVorLT);
  c6_m_B = c6_lc_y;
  c6_kc_x = c6_s_A;
  c6_mc_y = c6_m_B;
  c6_lc_x = c6_kc_x;
  c6_nc_y = c6_mc_y;
  c6_oc_y = c6_lc_x / c6_nc_y;
  c6_mc_x = c6_oc_y;
  c6_nc_x = c6_mc_x;
  c6_nc_x = muDoubleScalarExp(c6_nc_x);
  c6_n_a = c6_kc_y;
  c6_hb_b = 1.0 - c6_nc_x;
  c6_WVorLT = c6_n_a * c6_hb_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 96);
  c6_t_A = c6_receiverPos[2] - c6_wingTipLeftPos[2];
  c6_n_B = c6_receiverPos[1] - c6_wingTipLeftPos[1];
  c6_oc_x = c6_t_A;
  c6_pc_y = c6_n_B;
  c6_pc_x = c6_oc_x;
  c6_qc_y = c6_pc_y;
  c6_rc_y = c6_pc_x / c6_qc_y;
  c6_qc_x = c6_rc_y;
  c6_thetaVorLT = c6_qc_x;
  c6_rc_x = c6_thetaVorLT;
  c6_thetaVorLT = c6_rc_x;
  c6_thetaVorLT = muDoubleScalarAtan(c6_thetaVorLT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 97);
  if (CV_SCRIPT_IF(0, 3, c6_receiverPos[1] - c6_wingTipLeftPos[1] < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 98);
    c6_thetaVorLT += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 101);
  c6_sc_x = c6_thetaVorLT;
  c6_tc_x = c6_sc_x;
  c6_tc_x = muDoubleScalarSin(c6_tc_x);
  c6_o_a = c6_WVorLT;
  c6_ib_b = c6_tc_x;
  c6_sc_y = c6_o_a * c6_ib_b;
  c6_uc_x = c6_thetaVorLT;
  c6_vc_x = c6_uc_x;
  c6_vc_x = muDoubleScalarCos(c6_vc_x);
  c6_p_a = -c6_WVorLT;
  c6_jb_b = c6_vc_x;
  c6_tc_y = c6_p_a * c6_jb_b;
  c6_dv8[0] = 0.0;
  c6_dv8[1] = c6_sc_y;
  c6_dv8[2] = c6_tc_y;
  for (c6_i17 = 0; c6_i17 < 3; c6_i17++) {
    c6_WVorLTVector[c6_i17] = c6_dv8[c6_i17];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 105);
  c6_rVorRT = c6_mpower(chartInstance, c6_receiverPos[1] - c6_tailTipRightPos[1])
    + c6_mpower(chartInstance, c6_receiverPos[2] - c6_tailTipRightPos[2]);
  c6_b_sqrt(chartInstance, &c6_rVorRT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 106);
  c6_u_A = -(c6_receiverPos[0] - c6_wingTipLeftPos[0]);
  c6_wc_x = c6_u_A;
  c6_xc_x = c6_wc_x;
  c6_tVorRT = c6_xc_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 107);
  c6_TVorRT = 7.4226097064603627;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 108);
  c6_vVorRT = 0.44535658238762177;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 109);
  c6_kb_b = c6_tVorRT;
  c6_uc_y = 0.44535658238762177 * c6_kb_b;
  c6_lb_b = c6_abs(chartInstance, c6_uc_y);
  c6_b_sqrt(chartInstance, &c6_lb_b);
  c6_rVorCoreRT = 2.24 * c6_lb_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 111);
  c6_mb_b = c6_rVorRT;
  c6_vc_y = 7.4226097064603627 * c6_mb_b;
  c6_nb_b = c6_mpower(chartInstance, c6_rVorRT) + c6_mpower(chartInstance,
    c6_rVorCoreRT);
  c6_wc_y = 6.2831853071795862 * c6_nb_b;
  c6_v_A = c6_vc_y;
  c6_o_B = c6_wc_y;
  c6_yc_x = c6_v_A;
  c6_xc_y = c6_o_B;
  c6_ad_x = c6_yc_x;
  c6_yc_y = c6_xc_y;
  c6_ad_y = c6_ad_x / c6_yc_y;
  c6_ob_b = c6_tVorRT;
  c6_bd_y = 1.7814263295504871 * c6_ob_b;
  c6_w_A = -c6_mpower(chartInstance, c6_rVorRT);
  c6_p_B = c6_bd_y;
  c6_bd_x = c6_w_A;
  c6_cd_y = c6_p_B;
  c6_cd_x = c6_bd_x;
  c6_dd_y = c6_cd_y;
  c6_ed_y = c6_cd_x / c6_dd_y;
  c6_dd_x = c6_ed_y;
  c6_ed_x = c6_dd_x;
  c6_ed_x = muDoubleScalarExp(c6_ed_x);
  c6_q_a = c6_ad_y;
  c6_pb_b = 1.0 - c6_ed_x;
  c6_WVorRT = c6_q_a * c6_pb_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 112);
  c6_x_A = c6_receiverPos[2] - c6_tailTipRightPos[2];
  c6_q_B = -c6_receiverPos[1] + c6_tailTipRightPos[1];
  c6_fd_x = c6_x_A;
  c6_fd_y = c6_q_B;
  c6_gd_x = c6_fd_x;
  c6_gd_y = c6_fd_y;
  c6_hd_y = c6_gd_x / c6_gd_y;
  c6_hd_x = c6_hd_y;
  c6_thetaVorRT = c6_hd_x;
  c6_id_x = c6_thetaVorRT;
  c6_thetaVorRT = c6_id_x;
  c6_thetaVorRT = muDoubleScalarAtan(c6_thetaVorRT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 113);
  if (CV_SCRIPT_IF(0, 4, -c6_receiverPos[1] + c6_tailTipRightPos[1] < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 114);
    c6_thetaVorRT += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 117);
  c6_jd_x = c6_thetaVorRT;
  c6_kd_x = c6_jd_x;
  c6_kd_x = muDoubleScalarSin(c6_kd_x);
  c6_r_a = -c6_WVorRT;
  c6_qb_b = c6_kd_x;
  c6_id_y = c6_r_a * c6_qb_b;
  c6_ld_x = c6_thetaVorRT;
  c6_md_x = c6_ld_x;
  c6_md_x = muDoubleScalarCos(c6_md_x);
  c6_s_a = -c6_WVorRT;
  c6_rb_b = c6_md_x;
  c6_jd_y = c6_s_a * c6_rb_b;
  c6_dv9[0] = 0.0;
  c6_dv9[1] = c6_id_y;
  c6_dv9[2] = c6_jd_y;
  for (c6_i18 = 0; c6_i18 < 3; c6_i18++) {
    c6_WVorRTVector[c6_i18] = c6_dv9[c6_i18];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 120);
  c6_rVorT = c6_mpower(chartInstance, c6_receiverPos[0] - c6_tailTipRightPos[0])
    + c6_mpower(chartInstance, c6_receiverPos[2] - c6_tailTipRightPos[2]);
  c6_b_sqrt(chartInstance, &c6_rVorT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 121);
  c6_y_A = -(c6_receiverPos[0] - c6_wingTipLeftPos[0]);
  c6_nd_x = c6_y_A;
  c6_od_x = c6_nd_x;
  c6_tVorT = c6_od_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 123);
  c6_LVorLengthT = (c6_mpower(chartInstance, c6_receiverPos[0] -
    c6_tailTipLeftPos[0]) + c6_mpower(chartInstance, c6_receiverPos[1] -
    -5.1168690345343757)) + c6_mpower(chartInstance, c6_receiverPos[2] -
    c6_tailTipLeftPos[2]);
  c6_b_sqrt(chartInstance, &c6_LVorLengthT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 124);
  c6_RVorLengthT = (c6_mpower(chartInstance, c6_receiverPos[0] -
    c6_tailTipRightPos[0]) + c6_mpower(chartInstance, c6_receiverPos[1] -
    5.1168690345343757)) + c6_mpower(chartInstance, c6_receiverPos[2] -
    c6_tailTipRightPos[2]);
  c6_b_sqrt(chartInstance, &c6_RVorLengthT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 126);
  c6_ab_A = c6_receiverPos[1] - -5.1168690345343757;
  c6_r_B = c6_LVorLengthT;
  c6_pd_x = c6_ab_A;
  c6_kd_y = c6_r_B;
  c6_qd_x = c6_pd_x;
  c6_ld_y = c6_kd_y;
  c6_gamaLCosT = c6_qd_x / c6_ld_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, MAX_int8_T);
  c6_bb_A = -c6_receiverPos[1] + 5.1168690345343757;
  c6_s_B = c6_RVorLengthT;
  c6_rd_x = c6_bb_A;
  c6_md_y = c6_s_B;
  c6_sd_x = c6_rd_x;
  c6_nd_y = c6_md_y;
  c6_gamaRCosT = c6_sd_x / c6_nd_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 129U);
  c6_sb_b = c6_gamaLCosT + c6_gamaRCosT;
  c6_od_y = 7.4226097064603627 * c6_sb_b;
  c6_cb_A = c6_od_y;
  c6_td_x = c6_cb_A;
  c6_ud_x = c6_td_x;
  c6_pd_y = c6_ud_x / 2.0;
  c6_t_a = c6_pd_y;
  c6_qd_y = c6_t_a * 4.0;
  c6_db_A = c6_qd_y;
  c6_vd_x = c6_db_A;
  c6_wd_x = c6_vd_x;
  c6_TVorT = c6_wd_x / 3.1415926535897931;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 130U);
  c6_tb_b = c6_TVorT;
  c6_vVorT = 0.06 * c6_tb_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 131U);
  c6_u_a = c6_vVorT;
  c6_ub_b = c6_tVorT;
  c6_rd_y = c6_u_a * c6_ub_b;
  c6_vb_b = c6_abs(chartInstance, c6_rd_y);
  c6_b_sqrt(chartInstance, &c6_vb_b);
  c6_rVorCoreT = 2.24 * c6_vb_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 133U);
  c6_v_a = c6_TVorT;
  c6_wb_b = c6_rVorT;
  c6_sd_y = c6_v_a * c6_wb_b;
  c6_xb_b = c6_mpower(chartInstance, c6_rVorT) + c6_mpower(chartInstance,
    c6_rVorCoreT);
  c6_td_y = 6.2831853071795862 * c6_xb_b;
  c6_eb_A = c6_sd_y;
  c6_t_B = c6_td_y;
  c6_xd_x = c6_eb_A;
  c6_ud_y = c6_t_B;
  c6_yd_x = c6_xd_x;
  c6_vd_y = c6_ud_y;
  c6_wd_y = c6_yd_x / c6_vd_y;
  c6_yb_b = c6_vVorT;
  c6_xd_y = 4.0 * c6_yb_b;
  c6_w_a = c6_xd_y;
  c6_ac_b = c6_tVorT;
  c6_yd_y = c6_w_a * c6_ac_b;
  c6_fb_A = -c6_mpower(chartInstance, c6_rVorT);
  c6_u_B = c6_yd_y;
  c6_ae_x = c6_fb_A;
  c6_ae_y = c6_u_B;
  c6_be_x = c6_ae_x;
  c6_be_y = c6_ae_y;
  c6_ce_y = c6_be_x / c6_be_y;
  c6_ce_x = c6_ce_y;
  c6_de_x = c6_ce_x;
  c6_de_x = muDoubleScalarExp(c6_de_x);
  c6_x_a = c6_wd_y;
  c6_bc_b = 1.0 - c6_de_x;
  c6_WVorT = c6_x_a * c6_bc_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 134U);
  c6_gb_A = c6_receiverPos[2] - c6_tailTipRightPos[2];
  c6_v_B = -c6_receiverPos[0] + c6_tailTipRightPos[0];
  c6_ee_x = c6_gb_A;
  c6_de_y = c6_v_B;
  c6_fe_x = c6_ee_x;
  c6_ee_y = c6_de_y;
  c6_fe_y = c6_fe_x / c6_ee_y;
  c6_ge_x = c6_fe_y;
  c6_thetaVorT = c6_ge_x;
  c6_he_x = c6_thetaVorT;
  c6_thetaVorT = c6_he_x;
  c6_thetaVorT = muDoubleScalarAtan(c6_thetaVorT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 135U);
  if (CV_SCRIPT_IF(0, 5, -c6_receiverPos[0] + c6_tailTipRightPos[0] < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 136U);
    c6_thetaVorT += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 139U);
  c6_ie_x = c6_thetaVorT;
  c6_je_x = c6_ie_x;
  c6_je_x = muDoubleScalarSin(c6_je_x);
  c6_y_a = -c6_WVorT;
  c6_cc_b = c6_je_x;
  c6_ge_y = c6_y_a * c6_cc_b;
  c6_ke_x = c6_thetaVorT;
  c6_le_x = c6_ke_x;
  c6_le_x = muDoubleScalarCos(c6_le_x);
  c6_ab_a = -c6_WVorT;
  c6_dc_b = c6_le_x;
  c6_he_y = c6_ab_a * c6_dc_b;
  c6_ie_y[0] = c6_ge_y;
  c6_ie_y[1] = 0.0;
  c6_ie_y[2] = c6_he_y;
  for (c6_i19 = 0; c6_i19 < 3; c6_i19++) {
    c6_WVorTVector[c6_i19] = c6_ie_y[c6_i19];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 142U);
  for (c6_i20 = 0; c6_i20 < 3; c6_i20++) {
    c6_WTotalVector[c6_i20] = ((((c6_WVorLVector[c6_i20] + c6_WVorRVector[c6_i20])
      + c6_WVorWVector[c6_i20]) + c6_WVorLTVector[c6_i20]) +
      c6_WVorRTVector[c6_i20]) + c6_WVorTVector[c6_i20];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 146U);
  for (c6_i21 = 0; c6_i21 < 3; c6_i21++) {
    c6_y[c6_i21] = c6_WTotalVector[c6_i21];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -146);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c6_chartNumber, 0U, sf_debug_get_script_id(
    "D:/360Cloud/\xbf\xd5\xd6\xd0\xbc\xd3\xd3\xcd/Program/AirRefueling/TankerVortexWindField.m"));
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i22;
  real_T c6_b_inData[3];
  int32_T c6_i23;
  real_T c6_u[3];
  const mxArray *c6_y = NULL;
  SFc6_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc6_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i22 = 0; c6_i22 < 3; c6_i22++) {
    c6_b_inData[c6_i22] = (*(real_T (*)[3])c6_inData)[c6_i22];
  }

  for (c6_i23 = 0; c6_i23 < 3; c6_i23++) {
    c6_u[c6_i23] = c6_b_inData[c6_i23];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance,
  const mxArray *c6_TkTur2dr, const char_T *c6_identifier, real_T c6_y[3])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_TkTur2dr), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_TkTur2dr);
}

static void c6_b_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3])
{
  real_T c6_dv10[3];
  int32_T c6_i24;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv10, 1, 0, 0U, 1, 0U, 1, 3);
  for (c6_i24 = 0; c6_i24 < 3; c6_i24++) {
    c6_y[c6_i24] = c6_dv10[c6_i24];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_TkTur2dr;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[3];
  int32_T c6_i25;
  SFc6_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc6_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c6_TkTur2dr = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_TkTur2dr), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_TkTur2dr);
  for (c6_i25 = 0; c6_i25 < 3; c6_i25++) {
    (*(real_T (*)[3])c6_outData)[c6_i25] = c6_y[c6_i25];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc6_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc6_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_F16_Real5_nn_1_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[27];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i26;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 27), FALSE);
  for (c6_i26 = 0; c6_i26 < 27; c6_i26++) {
    c6_r0 = &c6_info[c6_i26];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i26);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i26);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i26);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i26);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i26);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i26);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i26);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i26);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[27])
{
  c6_info[0].context = "";
  c6_info[0].name = "TankerVortexWindField";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c6_info[0].fileTimeLo = 1411826324U;
  c6_info[0].fileTimeHi = 0U;
  c6_info[0].mFileTimeLo = 0U;
  c6_info[0].mFileTimeHi = 0U;
  c6_info[1].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c6_info[1].name = "mtimes";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[1].fileTimeLo = 1289494492U;
  c6_info[1].fileTimeHi = 0U;
  c6_info[1].mFileTimeLo = 0U;
  c6_info[1].mFileTimeHi = 0U;
  c6_info[2].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c6_info[2].name = "mrdivide";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[2].fileTimeLo = 1357926348U;
  c6_info[2].fileTimeHi = 0U;
  c6_info[2].mFileTimeLo = 1319708366U;
  c6_info[2].mFileTimeHi = 0U;
  c6_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[3].name = "rdivide";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[3].fileTimeLo = 1346488788U;
  c6_info[3].fileTimeHi = 0U;
  c6_info[3].mFileTimeLo = 0U;
  c6_info[3].mFileTimeHi = 0U;
  c6_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[4].name = "eml_scalexp_compatible";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c6_info[4].fileTimeLo = 1286797196U;
  c6_info[4].fileTimeHi = 0U;
  c6_info[4].mFileTimeLo = 0U;
  c6_info[4].mFileTimeHi = 0U;
  c6_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[5].name = "eml_div";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[5].fileTimeLo = 1313326210U;
  c6_info[5].fileTimeHi = 0U;
  c6_info[5].mFileTimeLo = 0U;
  c6_info[5].mFileTimeHi = 0U;
  c6_info[6].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c6_info[6].name = "mpower";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[6].fileTimeLo = 1286797242U;
  c6_info[6].fileTimeHi = 0U;
  c6_info[6].mFileTimeLo = 0U;
  c6_info[6].mFileTimeHi = 0U;
  c6_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[7].name = "power";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[7].fileTimeLo = 1348170330U;
  c6_info[7].fileTimeHi = 0U;
  c6_info[7].mFileTimeLo = 0U;
  c6_info[7].mFileTimeHi = 0U;
  c6_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c6_info[8].name = "eml_scalar_eg";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[8].fileTimeLo = 1286797196U;
  c6_info[8].fileTimeHi = 0U;
  c6_info[8].mFileTimeLo = 0U;
  c6_info[8].mFileTimeHi = 0U;
  c6_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c6_info[9].name = "eml_scalexp_alloc";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[9].fileTimeLo = 1352399660U;
  c6_info[9].fileTimeHi = 0U;
  c6_info[9].mFileTimeLo = 0U;
  c6_info[9].mFileTimeHi = 0U;
  c6_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c6_info[10].name = "floor";
  c6_info[10].dominantType = "double";
  c6_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[10].fileTimeLo = 1343808780U;
  c6_info[10].fileTimeHi = 0U;
  c6_info[10].mFileTimeLo = 0U;
  c6_info[10].mFileTimeHi = 0U;
  c6_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[11].name = "eml_scalar_floor";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c6_info[11].fileTimeLo = 1286797126U;
  c6_info[11].fileTimeHi = 0U;
  c6_info[11].mFileTimeLo = 0U;
  c6_info[11].mFileTimeHi = 0U;
  c6_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c6_info[12].name = "eml_scalar_eg";
  c6_info[12].dominantType = "double";
  c6_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[12].fileTimeLo = 1286797196U;
  c6_info[12].fileTimeHi = 0U;
  c6_info[12].mFileTimeLo = 0U;
  c6_info[12].mFileTimeHi = 0U;
  c6_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c6_info[13].name = "mtimes";
  c6_info[13].dominantType = "double";
  c6_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[13].fileTimeLo = 1289494492U;
  c6_info[13].fileTimeHi = 0U;
  c6_info[13].mFileTimeLo = 0U;
  c6_info[13].mFileTimeHi = 0U;
  c6_info[14].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c6_info[14].name = "sqrt";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[14].fileTimeLo = 1343808786U;
  c6_info[14].fileTimeHi = 0U;
  c6_info[14].mFileTimeLo = 0U;
  c6_info[14].mFileTimeHi = 0U;
  c6_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[15].name = "eml_error";
  c6_info[15].dominantType = "char";
  c6_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c6_info[15].fileTimeLo = 1343808758U;
  c6_info[15].fileTimeHi = 0U;
  c6_info[15].mFileTimeLo = 0U;
  c6_info[15].mFileTimeHi = 0U;
  c6_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[16].name = "eml_scalar_sqrt";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c6_info[16].fileTimeLo = 1286797138U;
  c6_info[16].fileTimeHi = 0U;
  c6_info[16].mFileTimeLo = 0U;
  c6_info[16].mFileTimeHi = 0U;
  c6_info[17].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c6_info[17].name = "abs";
  c6_info[17].dominantType = "double";
  c6_info[17].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[17].fileTimeLo = 1343808766U;
  c6_info[17].fileTimeHi = 0U;
  c6_info[17].mFileTimeLo = 0U;
  c6_info[17].mFileTimeHi = 0U;
  c6_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[18].name = "eml_scalar_abs";
  c6_info[18].dominantType = "double";
  c6_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[18].fileTimeLo = 1286797112U;
  c6_info[18].fileTimeHi = 0U;
  c6_info[18].mFileTimeLo = 0U;
  c6_info[18].mFileTimeHi = 0U;
  c6_info[19].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c6_info[19].name = "exp";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c6_info[19].fileTimeLo = 1343808780U;
  c6_info[19].fileTimeHi = 0U;
  c6_info[19].mFileTimeLo = 0U;
  c6_info[19].mFileTimeHi = 0U;
  c6_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c6_info[20].name = "eml_scalar_exp";
  c6_info[20].dominantType = "double";
  c6_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c6_info[20].fileTimeLo = 1301306864U;
  c6_info[20].fileTimeHi = 0U;
  c6_info[20].mFileTimeLo = 0U;
  c6_info[20].mFileTimeHi = 0U;
  c6_info[21].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c6_info[21].name = "atan";
  c6_info[21].dominantType = "double";
  c6_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c6_info[21].fileTimeLo = 1343808772U;
  c6_info[21].fileTimeHi = 0U;
  c6_info[21].mFileTimeLo = 0U;
  c6_info[21].mFileTimeHi = 0U;
  c6_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c6_info[22].name = "eml_scalar_atan";
  c6_info[22].dominantType = "double";
  c6_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c6_info[22].fileTimeLo = 1286797118U;
  c6_info[22].fileTimeHi = 0U;
  c6_info[22].mFileTimeLo = 0U;
  c6_info[22].mFileTimeHi = 0U;
  c6_info[23].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c6_info[23].name = "sin";
  c6_info[23].dominantType = "double";
  c6_info[23].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[23].fileTimeLo = 1343808786U;
  c6_info[23].fileTimeHi = 0U;
  c6_info[23].mFileTimeLo = 0U;
  c6_info[23].mFileTimeHi = 0U;
  c6_info[24].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[24].name = "eml_scalar_sin";
  c6_info[24].dominantType = "double";
  c6_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c6_info[24].fileTimeLo = 1286797136U;
  c6_info[24].fileTimeHi = 0U;
  c6_info[24].mFileTimeLo = 0U;
  c6_info[24].mFileTimeHi = 0U;
  c6_info[25].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c6_info[25].name = "cos";
  c6_info[25].dominantType = "double";
  c6_info[25].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[25].fileTimeLo = 1343808772U;
  c6_info[25].fileTimeHi = 0U;
  c6_info[25].mFileTimeLo = 0U;
  c6_info[25].mFileTimeHi = 0U;
  c6_info[26].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[26].name = "eml_scalar_cos";
  c6_info[26].dominantType = "double";
  c6_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c6_info[26].fileTimeLo = 1286797122U;
  c6_info[26].fileTimeHi = 0U;
  c6_info[26].mFileTimeLo = 0U;
  c6_info[26].mFileTimeHi = 0U;
}

static real_T c6_mpower(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance, real_T
  c6_a)
{
  real_T c6_b_a;
  real_T c6_c_a;
  real_T c6_ak;
  real_T c6_d_a;
  real_T c6_e_a;
  real_T c6_b;
  c6_b_a = c6_a;
  c6_c_a = c6_b_a;
  c6_eml_scalar_eg(chartInstance);
  c6_ak = c6_c_a;
  c6_d_a = c6_ak;
  c6_eml_scalar_eg(chartInstance);
  c6_e_a = c6_d_a;
  c6_b = c6_d_a;
  return c6_e_a * c6_b;
}

static void c6_eml_scalar_eg(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance)
{
}

static real_T c6_sqrt(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance, real_T
                      c6_x)
{
  real_T c6_b_x;
  c6_b_x = c6_x;
  c6_b_sqrt(chartInstance, &c6_b_x);
  return c6_b_x;
}

static void c6_eml_error(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance)
{
  int32_T c6_i27;
  static char_T c6_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c6_u[30];
  const mxArray *c6_y = NULL;
  int32_T c6_i28;
  static char_T c6_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c6_b_u[4];
  const mxArray *c6_b_y = NULL;
  for (c6_i27 = 0; c6_i27 < 30; c6_i27++) {
    c6_u[c6_i27] = c6_cv0[c6_i27];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c6_i28 = 0; c6_i28 < 4; c6_i28++) {
    c6_b_u[c6_i28] = c6_cv1[c6_i28];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c6_y, 14, c6_b_y));
}

static real_T c6_abs(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance, real_T
                     c6_x)
{
  real_T c6_b_x;
  c6_b_x = c6_x;
  return muDoubleScalarAbs(c6_b_x);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc6_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_d_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i29;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i29, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i29;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc6_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_F16_Real5_nn_1, const char_T *
  c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_F16_Real5_nn_1), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_F16_Real5_nn_1);
  return c6_y;
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sqrt(SFc6_F16_Real5_nn_1InstanceStruct *chartInstance, real_T
                      *c6_x)
{
  if (*c6_x < 0.0) {
    c6_eml_error(chartInstance);
  }

  *c6_x = muDoubleScalarSqrt(*c6_x);
}

static void init_dsm_address_info(SFc6_F16_Real5_nn_1InstanceStruct
  *chartInstance)
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

void sf_c6_F16_Real5_nn_1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2098095304U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3187998672U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2125641404U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3518030291U);
}

mxArray *sf_c6_F16_Real5_nn_1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("hvHVHnywvvKfC97swIA1wH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_F16_Real5_nn_1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c6_F16_Real5_nn_1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"TkTur2dr\",},{M[8],M[0],T\"is_active_c6_F16_Real5_nn_1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_F16_Real5_nn_1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_F16_Real5_nn_1InstanceStruct *chartInstance;
    chartInstance = (SFc6_F16_Real5_nn_1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _F16_Real5_nn_1MachineNumber_,
           6,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_F16_Real5_nn_1MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_F16_Real5_nn_1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _F16_Real5_nn_1MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"pos_dr2tk");
          _SFD_SET_DATA_PROPS(1,2,0,1,"TkTur2dr");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,90);
        _SFD_CV_INIT_SCRIPT(0,1,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"TankerVortexWindField",0,-1,7134);
        _SFD_CV_INIT_SCRIPT_IF(0,0,1724,1740,-1,1775);
        _SFD_CV_INIT_SCRIPT_IF(0,1,2367,2410,-1,2445);
        _SFD_CV_INIT_SCRIPT_IF(0,2,3749,3792,-1,3827);
        _SFD_CV_INIT_SCRIPT_IF(0,3,4711,4752,-1,4789);
        _SFD_CV_INIT_SCRIPT_IF(0,4,5428,5471,-1,5508);
        _SFD_CV_INIT_SCRIPT_IF(0,5,6835,6878,-1,6913);
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
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        {
          real_T (*c6_pos_dr2tk)[3];
          real_T (*c6_TkTur2dr)[3];
          c6_TkTur2dr = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c6_pos_dr2tk = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c6_pos_dr2tk);
          _SFD_SET_DATA_VALUE_PTR(1U, *c6_TkTur2dr);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _F16_Real5_nn_1MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "saQB8s79t6nKu0fIxgz1ZH";
}

static void sf_opaque_initialize_c6_F16_Real5_nn_1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_F16_Real5_nn_1InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_F16_Real5_nn_1((SFc6_F16_Real5_nn_1InstanceStruct*)
    chartInstanceVar);
  initialize_c6_F16_Real5_nn_1((SFc6_F16_Real5_nn_1InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_F16_Real5_nn_1(void *chartInstanceVar)
{
  enable_c6_F16_Real5_nn_1((SFc6_F16_Real5_nn_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_F16_Real5_nn_1(void *chartInstanceVar)
{
  disable_c6_F16_Real5_nn_1((SFc6_F16_Real5_nn_1InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_F16_Real5_nn_1(void *chartInstanceVar)
{
  sf_c6_F16_Real5_nn_1((SFc6_F16_Real5_nn_1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_F16_Real5_nn_1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_F16_Real5_nn_1
    ((SFc6_F16_Real5_nn_1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_F16_Real5_nn_1();/* state var info */
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

extern void sf_internal_set_sim_state_c6_F16_Real5_nn_1(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_F16_Real5_nn_1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_F16_Real5_nn_1((SFc6_F16_Real5_nn_1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_F16_Real5_nn_1(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_F16_Real5_nn_1(S);
}

static void sf_opaque_set_sim_state_c6_F16_Real5_nn_1(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c6_F16_Real5_nn_1(S, st);
}

static void sf_opaque_terminate_c6_F16_Real5_nn_1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_F16_Real5_nn_1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_F16_Real5_nn_1_optimization_info();
    }

    finalize_c6_F16_Real5_nn_1((SFc6_F16_Real5_nn_1InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_F16_Real5_nn_1((SFc6_F16_Real5_nn_1InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_F16_Real5_nn_1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_F16_Real5_nn_1((SFc6_F16_Real5_nn_1InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_F16_Real5_nn_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_F16_Real5_nn_1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4061949845U));
  ssSetChecksum1(S,(2402108930U));
  ssSetChecksum2(S,(3482840891U));
  ssSetChecksum3(S,(875099985U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_F16_Real5_nn_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_F16_Real5_nn_1(SimStruct *S)
{
  SFc6_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc6_F16_Real5_nn_1InstanceStruct *)utMalloc(sizeof
    (SFc6_F16_Real5_nn_1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_F16_Real5_nn_1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_F16_Real5_nn_1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_F16_Real5_nn_1;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_F16_Real5_nn_1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_F16_Real5_nn_1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_F16_Real5_nn_1;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_F16_Real5_nn_1;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_F16_Real5_nn_1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_F16_Real5_nn_1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_F16_Real5_nn_1;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_F16_Real5_nn_1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_F16_Real5_nn_1;
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

void c6_F16_Real5_nn_1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_F16_Real5_nn_1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_F16_Real5_nn_1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_F16_Real5_nn_1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_F16_Real5_nn_1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
