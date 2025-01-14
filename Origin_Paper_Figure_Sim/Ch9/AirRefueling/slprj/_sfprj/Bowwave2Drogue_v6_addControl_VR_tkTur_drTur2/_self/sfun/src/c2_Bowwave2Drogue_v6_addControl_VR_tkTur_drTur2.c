/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2_sfun.h"
#include "c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[28] = { "V0", "xc", "yc", "zc", "xr",
  "yr", "theta_x", "deltaTheta", "tt1", "tt2", "theta1", "theta2", "kc", "xxc",
  "yyc", "r", "beta1", "theta", "alpha", "f", "nargin", "nargout", "x", "y", "z",
  "Fx", "Fy", "Fz" };

/* Function Declarations */
static void initialize_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static void initialize_params_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static void enable_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static void disable_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static void c2_update_debugger_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTu
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static const mxArray
  *get_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static void set_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray *c2_st);
static void finalize_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static void sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static void c2_chartstep_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static void initSimStructsc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static void registerMessagesc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray *c2_Fz, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[30]);
static real_T c2_mpower
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, real_T c2_a);
static void c2_eml_scalar_eg
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static real_T c2_sqrt
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, real_T c2_x);
static void c2_eml_error
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);
static real_T c2_abs
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, real_T c2_x);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray
   *c2_b_is_active_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2, const char_T
   *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sqrt
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, real_T *c2_x);
static void init_dsm_address_info
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance);

/* Function Definitions */
static void initialize_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2 =
    0U;
}

static void initialize_params_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
}

static void enable_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTu
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
}

static const mxArray
  *get_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T *c2_Fx;
  real_T *c2_Fy;
  real_T *c2_Fz;
  c2_Fz = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_Fy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Fx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(4), FALSE);
  c2_hoistedGlobal = *c2_Fx;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_Fy;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_Fz;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal =
    chartInstance->c2_is_active_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_Fx;
  real_T *c2_Fy;
  real_T *c2_Fz;
  c2_Fz = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_Fy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Fx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_Fx = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "Fx");
  *c2_Fy = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "Fy");
  *c2_Fz = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "Fz");
  chartInstance->c2_is_active_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2 =
    c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
    "is_active_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTu(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
}

static void sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
  real_T *c2_x;
  real_T *c2_Fx;
  real_T *c2_y;
  real_T *c2_z;
  real_T *c2_Fy;
  real_T *c2_Fz;
  c2_Fz = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_Fy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_Fx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_x, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_Fx, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_y, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_z, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_Fy, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_Fz, 5U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2MachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_x;
  real_T c2_y;
  real_T c2_z;
  uint32_T c2_debug_family_var_map[28];
  real_T c2_V0;
  real_T c2_xc;
  real_T c2_yc;
  real_T c2_zc;
  real_T c2_xr;
  real_T c2_yr;
  real_T c2_theta_x;
  real_T c2_deltaTheta;
  real_T c2_tt1;
  real_T c2_tt2;
  real_T c2_theta1;
  real_T c2_theta2;
  real_T c2_kc;
  real_T c2_xxc;
  real_T c2_yyc;
  real_T c2_r;
  real_T c2_beta1;
  real_T c2_theta;
  real_T c2_alpha;
  real_T c2_f;
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 3.0;
  real_T c2_Fx;
  real_T c2_Fy;
  real_T c2_Fz;
  real_T c2_d0;
  real_T c2_b;
  real_T c2_b_y;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_b_b;
  real_T c2_c_y;
  real_T c2_A;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_d_y;
  real_T c2_d1;
  real_T c2_c_b;
  real_T c2_e_y;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_d_b;
  real_T c2_f_y;
  real_T c2_b_A;
  real_T c2_B;
  real_T c2_h_x;
  real_T c2_g_y;
  real_T c2_i_x;
  real_T c2_h_y;
  real_T c2_i_y;
  real_T c2_e_b;
  real_T c2_j_y;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_f_b;
  real_T c2_k_y;
  real_T c2_c_A;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_l_y;
  real_T c2_d2;
  real_T c2_g_b;
  real_T c2_m_y;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_h_b;
  real_T c2_n_y;
  real_T c2_d_A;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_o_y;
  real_T c2_d3;
  real_T c2_i_b;
  real_T c2_p_y;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_j_b;
  real_T c2_q_y;
  real_T c2_e_A;
  real_T c2_b_B;
  real_T c2_t_x;
  real_T c2_r_y;
  real_T c2_u_x;
  real_T c2_s_y;
  real_T c2_t_y;
  real_T c2_k_b;
  real_T c2_u_y;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_l_b;
  real_T c2_v_y;
  real_T c2_f_A;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_w_y;
  real_T c2_ab_x;
  real_T c2_bb_x;
  real_T c2_m_b;
  real_T c2_x_y;
  real_T c2_cb_x;
  real_T c2_db_x;
  real_T c2_n_b;
  real_T c2_y_y;
  real_T c2_eb_x;
  real_T c2_fb_x;
  real_T c2_ab_y;
  real_T c2_gb_x;
  real_T c2_hb_x;
  real_T c2_o_b;
  real_T c2_p_b;
  real_T c2_ib_x;
  real_T c2_jb_x;
  real_T c2_g_A;
  real_T c2_c_B;
  real_T c2_kb_x;
  real_T c2_bb_y;
  real_T c2_lb_x;
  real_T c2_cb_y;
  real_T c2_db_y;
  real_T c2_mb_x;
  real_T c2_nb_x;
  real_T c2_h_A;
  real_T c2_d_B;
  real_T c2_ob_x;
  real_T c2_eb_y;
  real_T c2_pb_x;
  real_T c2_fb_y;
  real_T c2_gb_y;
  real_T c2_qb_x;
  real_T c2_rb_x;
  real_T c2_i_A;
  real_T c2_sb_x;
  real_T c2_tb_x;
  real_T c2_hb_y;
  real_T c2_ub_x;
  real_T c2_vb_x;
  real_T c2_q_b;
  real_T c2_j_A;
  real_T c2_e_B;
  real_T c2_wb_x;
  real_T c2_ib_y;
  real_T c2_xb_x;
  real_T c2_jb_y;
  real_T c2_kb_y;
  real_T c2_yb_x;
  real_T c2_ac_x;
  real_T c2_k_A;
  real_T c2_f_B;
  real_T c2_bc_x;
  real_T c2_lb_y;
  real_T c2_cc_x;
  real_T c2_mb_y;
  real_T c2_nb_y;
  real_T c2_dc_x;
  real_T c2_ec_x;
  real_T c2_fc_x;
  real_T c2_gc_x;
  real_T c2_ob_y;
  real_T c2_hc_x;
  real_T c2_ic_x;
  real_T c2_r_b;
  real_T c2_pb_y;
  real_T c2_jc_x;
  real_T c2_kc_x;
  real_T c2_a;
  real_T c2_s_b;
  real_T c2_qb_y;
  real_T c2_l_A;
  real_T c2_lc_x;
  real_T c2_mc_x;
  real_T c2_rb_y;
  real_T c2_t_b;
  real_T c2_sb_y;
  real_T c2_nc_x;
  real_T c2_oc_x;
  real_T c2_tb_y;
  real_T c2_b_a;
  real_T c2_u_b;
  real_T c2_ub_y;
  real_T c2_pc_x;
  real_T c2_qc_x;
  real_T c2_c_a;
  real_T c2_v_b;
  real_T c2_m_A;
  real_T c2_g_B;
  real_T c2_rc_x;
  real_T c2_vb_y;
  real_T c2_sc_x;
  real_T c2_wb_y;
  real_T c2_xb_y;
  real_T c2_d_a;
  real_T c2_w_b;
  real_T c2_n_A;
  real_T c2_h_B;
  real_T c2_tc_x;
  real_T c2_yb_y;
  real_T c2_uc_x;
  real_T c2_ac_y;
  real_T c2_bc_y;
  real_T c2_e_a;
  real_T c2_x_b;
  real_T *c2_b_Fz;
  real_T *c2_b_Fy;
  real_T *c2_b_Fx;
  real_T *c2_b_z;
  real_T *c2_cc_y;
  real_T *c2_vc_x;
  c2_b_Fz = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_Fy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_cc_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_Fx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_vc_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_vc_x;
  c2_b_hoistedGlobal = *c2_cc_y;
  c2_c_hoistedGlobal = *c2_b_z;
  c2_x = c2_hoistedGlobal;
  c2_y = c2_b_hoistedGlobal;
  c2_z = c2_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 28U, 28U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_V0, 0U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_xc, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_yc, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_zc, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_xr, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_yr, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_theta_x, 6U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_deltaTheta, 7U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_tt1, 8U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_tt2, 9U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_theta1, 10U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_theta2, 11U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_kc, 12U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_xxc, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_yyc, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_r, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_beta1, 16U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_theta, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_alpha, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f, 19U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 20U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 21U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_x, 22U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_y, 23U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_z, 24U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Fx, 25U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Fy, 26U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Fz, 27U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_V0 = 120.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
  c2_xc = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_yc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_zc = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
  c2_xr = 2.235;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  c2_yr = 0.4839;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
  c2_theta_x = 0.22288;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
  if (CV_EML_IF(0, 1, 0, c2_x <= c2_xc)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
    c2_d0 = (c2_mpower(chartInstance, c2_x - c2_xc) + c2_mpower(chartInstance,
              c2_y - c2_yc)) + c2_mpower(chartInstance, c2_z - c2_zc);
    c2_b_sqrt(chartInstance, &c2_d0);
    c2_b = c2_d0 + 0.75541;
    c2_b_y = -2.5 * c2_b;
    c2_b_x = c2_b_y;
    c2_c_x = c2_b_x;
    c2_c_x = muDoubleScalarExp(c2_c_x);
    c2_b_b = c2_c_x;
    c2_c_y = 120.0 * c2_b_b;
    c2_Fx = c2_V0 - c2_c_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
    if (CV_EML_IF(0, 1, 1, c2_x <= c2_xc + 2.0)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
      c2_A = c2_mpower(chartInstance, c2_x - c2_xc);
      c2_d_x = c2_A;
      c2_e_x = c2_d_x;
      c2_d_y = c2_e_x / 0.85;
      c2_d1 = (c2_d_y + c2_mpower(chartInstance, c2_y - c2_yc)) + c2_mpower
        (chartInstance, c2_z - c2_zc);
      c2_b_sqrt(chartInstance, &c2_d1);
      c2_c_b = c2_d1 + 0.75541;
      c2_e_y = -2.5 * c2_c_b;
      c2_f_x = c2_e_y;
      c2_g_x = c2_f_x;
      c2_g_x = muDoubleScalarExp(c2_g_x);
      c2_d_b = c2_g_x;
      c2_f_y = 120.0 * c2_d_b;
      c2_b_A = c2_mpower(chartInstance, c2_y) + c2_mpower(chartInstance, c2_z);
      c2_b_sqrt(chartInstance, &c2_b_A);
      c2_B = c2_x;
      c2_h_x = c2_b_A;
      c2_g_y = c2_B;
      c2_i_x = c2_h_x;
      c2_h_y = c2_g_y;
      c2_i_y = c2_i_x / c2_h_y;
      c2_e_b = c2_abs(chartInstance, c2_abs(chartInstance, c2_i_y) -
                      0.22664539494376879);
      c2_j_y = -5.0 * c2_e_b;
      c2_j_x = c2_j_y;
      c2_k_x = c2_j_x;
      c2_k_x = muDoubleScalarExp(c2_k_x);
      c2_f_b = c2_k_x;
      c2_k_y = 5.8630045941210422 * c2_f_b;
      c2_c_A = c2_mpower(chartInstance, c2_x - c2_xr);
      c2_l_x = c2_c_A;
      c2_m_x = c2_l_x;
      c2_l_y = c2_m_x / 2.0;
      c2_d2 = (c2_l_y + c2_mpower(chartInstance, c2_y - c2_yr)) + c2_mpower
        (chartInstance, c2_z - c2_zc);
      c2_b_sqrt(chartInstance, &c2_d2);
      c2_g_b = c2_d2 + 1.1;
      c2_m_y = -2.6 * c2_g_b;
      c2_n_x = c2_m_y;
      c2_o_x = c2_n_x;
      c2_o_x = muDoubleScalarExp(c2_o_x);
      c2_h_b = c2_o_x;
      c2_n_y = 120.0 * c2_h_b;
      c2_Fx = ((c2_V0 - c2_f_y) + c2_k_y) - c2_n_y;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
      c2_d_A = c2_mpower(chartInstance, c2_x - c2_xc);
      c2_p_x = c2_d_A;
      c2_q_x = c2_p_x;
      c2_o_y = c2_q_x / 0.85;
      c2_d3 = (c2_o_y + c2_mpower(chartInstance, c2_y - c2_yc)) + c2_mpower
        (chartInstance, c2_z - c2_zc);
      c2_b_sqrt(chartInstance, &c2_d3);
      c2_i_b = c2_d3 + 0.75541;
      c2_p_y = -2.5 * c2_i_b;
      c2_r_x = c2_p_y;
      c2_s_x = c2_r_x;
      c2_s_x = muDoubleScalarExp(c2_s_x);
      c2_j_b = c2_s_x;
      c2_q_y = 120.0 * c2_j_b;
      c2_e_A = c2_mpower(chartInstance, c2_y) + c2_mpower(chartInstance, c2_z);
      c2_b_sqrt(chartInstance, &c2_e_A);
      c2_b_B = c2_x;
      c2_t_x = c2_e_A;
      c2_r_y = c2_b_B;
      c2_u_x = c2_t_x;
      c2_s_y = c2_r_y;
      c2_t_y = c2_u_x / c2_s_y;
      c2_k_b = c2_abs(chartInstance, c2_abs(chartInstance, c2_t_y) -
                      0.22664539494376879);
      c2_u_y = -5.0 * c2_k_b;
      c2_v_x = c2_u_y;
      c2_w_x = c2_v_x;
      c2_w_x = muDoubleScalarExp(c2_w_x);
      c2_l_b = c2_w_x;
      c2_v_y = 5.8630045941210422 * c2_l_b;
      c2_f_A = c2_mpower(chartInstance, c2_x - c2_xr);
      c2_x_x = c2_f_A;
      c2_y_x = c2_x_x;
      c2_w_y = c2_y_x / 2.0;
      c2_ab_x = (c2_w_y + c2_mpower(chartInstance, c2_y - c2_yr)) + c2_mpower
        (chartInstance, c2_z - c2_zc);
      c2_bb_x = c2_ab_x;
      if (c2_bb_x < 0.0) {
        c2_eml_error(chartInstance);
      }

      c2_bb_x = muDoubleScalarSqrt(c2_bb_x);
      c2_m_b = c2_bb_x + 1.1;
      c2_x_y = -2.6 * c2_m_b;
      c2_cb_x = c2_x_y;
      c2_db_x = c2_cb_x;
      c2_db_x = muDoubleScalarExp(c2_db_x);
      c2_n_b = c2_db_x;
      c2_y_y = 120.0 * c2_n_b;
      c2_Fx = ((c2_V0 - c2_q_y) + c2_v_y) - c2_y_y;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
      c2_eb_x = c2_Fx;
      c2_fb_x = c2_eb_x;
      c2_ab_y = muDoubleScalarAbs(c2_fb_x);
      if (CV_EML_IF(0, 1, 2, c2_ab_y > 100.0)) {
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
        c2_gb_x = c2_Fx;
        c2_hb_x = c2_gb_x;
        c2_hb_x = muDoubleScalarSign(c2_hb_x);
        c2_o_b = c2_hb_x;
        c2_Fx = 100.0 * c2_o_b;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
  c2_deltaTheta = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 60);
  c2_tt1 = 0.22288;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
  c2_tt2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 62);
  c2_theta1 = 0.22288;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 63);
  c2_theta2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 66);
  c2_kc = 0.089388949060565631;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
  c2_xxc = c2_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 68);
  c2_p_b = c2_xxc;
  c2_yyc = 0.089388949060565631 * c2_p_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 70);
  c2_ib_x = c2_mpower(chartInstance, c2_y - c2_yyc) + c2_mpower(chartInstance,
    c2_z);
  c2_r = c2_ib_x;
  if (c2_r < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_jb_x = c2_r;
  c2_r = c2_jb_x;
  c2_r = muDoubleScalarSqrt(c2_r);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 72);
  if (CV_EML_IF(0, 1, 3, c2_y - c2_yyc >= 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 73);
    c2_g_A = c2_z;
    c2_c_B = c2_y - c2_yyc;
    c2_kb_x = c2_g_A;
    c2_bb_y = c2_c_B;
    c2_lb_x = c2_kb_x;
    c2_cb_y = c2_bb_y;
    c2_db_y = c2_lb_x / c2_cb_y;
    c2_mb_x = c2_db_y;
    c2_beta1 = c2_mb_x;
    c2_nb_x = c2_beta1;
    c2_beta1 = c2_nb_x;
    c2_beta1 = muDoubleScalarAtan(c2_beta1);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 75);
    c2_h_A = c2_z;
    c2_d_B = c2_y - c2_yyc;
    c2_ob_x = c2_h_A;
    c2_eb_y = c2_d_B;
    c2_pb_x = c2_ob_x;
    c2_fb_y = c2_eb_y;
    c2_gb_y = c2_pb_x / c2_fb_y;
    c2_qb_x = c2_gb_y;
    c2_rb_x = c2_qb_x;
    c2_rb_x = muDoubleScalarAtan(c2_rb_x);
    c2_beta1 = c2_rb_x + 3.1415926535897931;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 78);
  c2_i_A = c2_beta1;
  c2_sb_x = c2_i_A;
  c2_tb_x = c2_sb_x;
  c2_hb_y = c2_tb_x / 2.0;
  c2_ub_x = c2_hb_y;
  c2_vb_x = c2_ub_x;
  c2_vb_x = muDoubleScalarCos(c2_vb_x);
  c2_q_b = c2_vb_x;
  c2_theta = 0.22288 * c2_q_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 80);
  if (CV_EML_IF(0, 1, 4, c2_x >= 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 81);
    c2_j_A = c2_r;
    c2_e_B = c2_x;
    c2_wb_x = c2_j_A;
    c2_ib_y = c2_e_B;
    c2_xb_x = c2_wb_x;
    c2_jb_y = c2_ib_y;
    c2_kb_y = c2_xb_x / c2_jb_y;
    c2_yb_x = c2_kb_y;
    c2_alpha = c2_yb_x;
    c2_ac_x = c2_alpha;
    c2_alpha = c2_ac_x;
    c2_alpha = muDoubleScalarAtan(c2_alpha);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 83);
    c2_k_A = c2_r;
    c2_f_B = c2_x;
    c2_bc_x = c2_k_A;
    c2_lb_y = c2_f_B;
    c2_cc_x = c2_bc_x;
    c2_mb_y = c2_lb_y;
    c2_nb_y = c2_cc_x / c2_mb_y;
    c2_dc_x = c2_nb_y;
    c2_ec_x = c2_dc_x;
    c2_ec_x = muDoubleScalarAtan(c2_ec_x);
    c2_alpha = c2_ec_x + 3.1415926535897931;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 86);
  c2_fc_x = c2_r;
  c2_gc_x = c2_fc_x;
  c2_ob_y = muDoubleScalarAbs(c2_gc_x);
  if (CV_EML_IF(0, 1, 5, c2_ob_y < 0.0001)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 87);
    c2_Fz = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 88);
    c2_Fy = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 90);
    c2_hc_x = c2_theta;
    c2_ic_x = c2_hc_x;
    c2_ic_x = muDoubleScalarSin(c2_ic_x);
    c2_r_b = c2_ic_x;
    c2_pb_y = 72.0 * c2_r_b;
    c2_jc_x = c2_theta;
    c2_kc_x = c2_jc_x;
    c2_kc_x = muDoubleScalarCos(c2_kc_x);
    c2_a = c2_pb_y;
    c2_s_b = c2_kc_x;
    c2_qb_y = c2_a * c2_s_b;
    c2_l_A = c2_r;
    c2_lc_x = c2_l_A;
    c2_mc_x = c2_lc_x;
    c2_rb_y = c2_mc_x / 1.5;
    c2_t_b = 1.0 + c2_rb_y;
    c2_sb_y = -1.5 * c2_t_b;
    c2_nc_x = c2_alpha - c2_theta;
    c2_oc_x = c2_nc_x;
    c2_tb_y = muDoubleScalarAbs(c2_oc_x);
    c2_b_a = c2_sb_y;
    c2_u_b = c2_tb_y;
    c2_ub_y = c2_b_a * c2_u_b;
    c2_pc_x = c2_ub_y;
    c2_qc_x = c2_pc_x;
    c2_qc_x = muDoubleScalarExp(c2_qc_x);
    c2_c_a = c2_qb_y;
    c2_v_b = c2_qc_x;
    c2_f = c2_c_a * c2_v_b;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 91);
    c2_m_A = c2_y - c2_yyc;
    c2_g_B = c2_r;
    c2_rc_x = c2_m_A;
    c2_vb_y = c2_g_B;
    c2_sc_x = c2_rc_x;
    c2_wb_y = c2_vb_y;
    c2_xb_y = c2_sc_x / c2_wb_y;
    c2_d_a = c2_xb_y;
    c2_w_b = c2_f;
    c2_Fy = c2_d_a * c2_w_b;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 92);
    c2_n_A = c2_z;
    c2_h_B = c2_r;
    c2_tc_x = c2_n_A;
    c2_yb_y = c2_h_B;
    c2_uc_x = c2_tc_x;
    c2_ac_y = c2_yb_y;
    c2_bc_y = c2_uc_x / c2_ac_y;
    c2_e_a = c2_bc_y;
    c2_x_b = c2_f;
    c2_Fz = c2_e_a * c2_x_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -92);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_Fx = c2_Fx;
  *c2_b_Fy = c2_Fy;
  *c2_b_Fz = c2_Fz;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
}

static void registerMessagesc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct *chartInstance;
  chartInstance =
    (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray *c2_Fz, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Fz), &c2_thisId);
  sf_mex_destroy(&c2_Fz);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d4;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d4, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d4;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Fz;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct *chartInstance;
  chartInstance =
    (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct *)
    chartInstanceVoid;
  c2_Fz = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Fz), &c2_thisId);
  sf_mex_destroy(&c2_Fz);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray
  *sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[30];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 30), FALSE);
  for (c2_i0 = 0; c2_i0 < 30; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[30])
{
  c2_info[0].context = "";
  c2_info[0].name = "mpower";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[0].fileTimeLo = 1286797242U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[1].name = "power";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[1].fileTimeLo = 1348170330U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[2].name = "eml_scalar_eg";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[2].fileTimeLo = 1286797196U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[3].name = "eml_scalexp_alloc";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[3].fileTimeLo = 1352399660U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[4].name = "floor";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[4].fileTimeLo = 1343808780U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[5].name = "eml_scalar_floor";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[5].fileTimeLo = 1286797126U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c2_info[6].name = "eml_scalar_eg";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[6].fileTimeLo = 1286797196U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c2_info[7].name = "mtimes";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[7].fileTimeLo = 1289494492U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "";
  c2_info[8].name = "sqrt";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[8].fileTimeLo = 1343808786U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[9].name = "eml_error";
  c2_info[9].dominantType = "char";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[9].fileTimeLo = 1343808758U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[10].name = "eml_scalar_sqrt";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[10].fileTimeLo = 1286797138U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "";
  c2_info[11].name = "mtimes";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[11].fileTimeLo = 1289494492U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "";
  c2_info[12].name = "exp";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c2_info[12].fileTimeLo = 1343808780U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c2_info[13].name = "eml_scalar_exp";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c2_info[13].fileTimeLo = 1301306864U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "";
  c2_info[14].name = "mrdivide";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[14].fileTimeLo = 1357926348U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 1319708366U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[15].name = "rdivide";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[15].fileTimeLo = 1346488788U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[16].name = "eml_scalexp_compatible";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[16].fileTimeLo = 1286797196U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[17].name = "eml_div";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[17].fileTimeLo = 1313326210U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context = "";
  c2_info[18].name = "sin";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[18].fileTimeLo = 1343808786U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[19].name = "eml_scalar_sin";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[19].fileTimeLo = 1286797136U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context = "";
  c2_info[20].name = "abs";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[20].fileTimeLo = 1343808766U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[21].name = "eml_scalar_abs";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[21].fileTimeLo = 1286797112U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context = "";
  c2_info[22].name = "tan";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/tan.m";
  c2_info[22].fileTimeLo = 1343808786U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/tan.m";
  c2_info[23].name = "eml_scalar_tan";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_tan.m";
  c2_info[23].fileTimeLo = 1286797138U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context = "";
  c2_info[24].name = "sign";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[24].fileTimeLo = 1354342864U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[25].name = "eml_scalar_sign";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c2_info[25].fileTimeLo = 1354342864U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context = "";
  c2_info[26].name = "atan";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c2_info[26].fileTimeLo = 1343808772U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c2_info[27].name = "eml_scalar_atan";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c2_info[27].fileTimeLo = 1286797118U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context = "";
  c2_info[28].name = "cos";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[28].fileTimeLo = 1343808772U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[29].name = "eml_scalar_cos";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[29].fileTimeLo = 1286797122U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
}

static real_T c2_mpower
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  real_T c2_d_a;
  real_T c2_e_a;
  real_T c2_b;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_c_a;
  c2_d_a = c2_ak;
  c2_eml_scalar_eg(chartInstance);
  c2_e_a = c2_d_a;
  c2_b = c2_d_a;
  return c2_e_a * c2_b;
}

static void c2_eml_scalar_eg
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
}

static real_T c2_sqrt
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sqrt(chartInstance, &c2_b_x);
  return c2_b_x;
}

static void c2_eml_error
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance)
{
  int32_T c2_i1;
  static char_T c2_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  int32_T c2_i2;
  static char_T c2_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  for (c2_i1 = 0; c2_i1 < 30; c2_i1++) {
    c2_u[c2_i1] = c2_cv0[c2_i1];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    c2_b_u[c2_i2] = c2_cv1[c2_i2];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c2_y, 14, c2_b_y));
}

static real_T c2_abs
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  return muDoubleScalarAbs(c2_b_x);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct *chartInstance;
  chartInstance =
    (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i3;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i3, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i3;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct *chartInstance;
  chartInstance =
    (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray
   *c2_b_is_active_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2, const char_T
   *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sqrt
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
   *chartInstance, real_T *c2_x)
{
  if (*c2_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  *c2_x = muDoubleScalarSqrt(*c2_x);
}

static void init_dsm_address_info
  (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
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

void sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1392329679U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(918185758U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1273793658U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2772540578U);
}

mxArray
  *sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("mQ0EByTtQwhHY5CMgzjE4E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray
  *sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray
  *sf_get_sim_state_info_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"Fx\",},{M[1],M[8],T\"Fy\",},{M[1],M[9],T\"Fz\",},{M[8],M[0],T\"is_active_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct
      *chartInstance;
    chartInstance =
      (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2MachineNumber_,
           2,
           1,
           1,
           6,
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
            (_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Fx");
          _SFD_SET_DATA_PROPS(2,1,1,0,"y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"z");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Fy");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Fz");
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
        _SFD_CV_INIT_EML(0,1,1,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2117);
        _SFD_CV_INIT_EML_IF(0,1,0,1061,1069,1138,1597);
        _SFD_CV_INIT_EML_IF(0,1,1,1138,1152,1346,1597);
        _SFD_CV_INIT_EML_IF(0,1,2,1546,1560,-1,1593);
        _SFD_CV_INIT_EML_IF(0,1,3,1780,1793,1823,1864);
        _SFD_CV_INIT_EML_IF(0,1,4,1896,1903,1927,1961);
        _SFD_CV_INIT_EML_IF(0,1,5,1963,1979,2000,2116);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_x;
          real_T *c2_Fx;
          real_T *c2_y;
          real_T *c2_z;
          real_T *c2_Fy;
          real_T *c2_Fz;
          c2_Fz = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_Fy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_Fx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_Fx);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_z);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_Fy);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_Fz);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "f4DY677RiTxcF2bsVXUsRC";
}

static void sf_opaque_initialize_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (void *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
    ((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
     chartInstanceVar);
  initialize_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
    ((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (void *chartInstanceVar)
{
  enable_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
    ((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (void *chartInstanceVar)
{
  disable_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
    ((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (void *chartInstanceVar)
{
  sf_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
    ((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*)
    get_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
    ((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2();/* state var info */
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

extern void
  sf_internal_set_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
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
    sf_get_sim_state_info_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
    ((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SimStruct* S)
{
  return
    sf_internal_get_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2(S);
}

static void
  sf_opaque_set_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2(S,
    st);
}

static void sf_opaque_terminate_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
       chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2_optimization_info();
    }

    finalize_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
      ((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
       chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
    ((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
      ((SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1135565067U));
  ssSetChecksum1(S,(2104822239U));
  ssSetChecksum2(S,(939468507U));
  ssSetChecksum3(S,(1423343888U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2(SimStruct
  *S)
{
  SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct *chartInstance;
  chartInstance =
    (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct *)utMalloc
    (sizeof(SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2;
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

void c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Bowwave2Drogue_v6_addControl_VR_tkTur_drTur2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
