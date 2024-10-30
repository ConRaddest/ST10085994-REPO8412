#ifndef MPPTTestEnviroment_h_
#define MPPTTestEnviroment_h_
#ifndef MPPTTestEnviroment_COMMON_INCLUDES_
#define MPPTTestEnviroment_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "MPPTTestEnviroment_types.h"
#include "mwmathutil.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME MPPTTestEnviroment
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (17) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T akyt3lfkwh ; real_T ddr3qqcafj ; real_T njil4ymwjf ;
real_T h0wrsbi0st [ 6 ] ; real_T ofammli3u4 [ 2 ] ; real_T j1iluh4g4l ;
real_T csrrphvxwc ; real_T g40trl0ym0 ; real_T abocamivf3 ; real_T lkf3m54okc
; real_T pd05mevuny ; real_T kpvk44fokn ; real_T lzs1gqogb3 ; real_T
ezp5fomtbc ; real_T bq01lft3hq ; real_T g1elq1ywpj ; real_T c3maug3nzc ; } B
; typedef struct { real_T exeralr4po ; real_T g5ufooow0i [ 4 ] ; struct {
void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } jqrqq3twqe ; struct
{ void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } j4uq2hdcjm ;
struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } lazvpzocdc
; struct { void * AS ; void * BS ; void * CS ; void * DS ; void * DX_COL ;
void * BD_COL ; void * TMP1 ; void * TMP2 ; void * XTMP ; void *
SWITCH_STATUS ; void * SWITCH_STATUS_INIT ; void * SW_CHG ; void * G_STATE ;
void * USWLAST ; void * XKM12 ; void * XKP12 ; void * XLAST ; void * ULAST ;
void * IDX_SW_CHG ; void * Y_SWITCH ; void * SWITCH_TYPES ; void * IDX_OUT_SW
; void * SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; } mzxjwgc5lv ; struct {
void * LoggedData ; } eekerhptxj ; struct { void * LoggedData ; } lklwansiy2
; struct { int_T PrevIndex ; } h1nceqotqd ; struct { int_T PrevIndex ; }
cvaln4lwyx ; struct { int_T PrevIndex ; } axcms0d2td ; int_T a5z1oau2kb [ 11
] ; int_T esoqq5ahh2 ; } DW ; typedef struct { real_T jnz5kaloxr ; real_T
ar5fnf0tyl ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T PVArray_Npar ; real_T mapminmax_xmax [ 2 ] ;
real_T mapminmax_reverse_xmax ; real_T mapminmax_xmin [ 2 ] ; real_T
mapminmax_reverse_xmin ; real_T mapminmax_ymax ; real_T
mapminmax_reverse_ymax ; real_T mapminmax_ymin ; real_T
mapminmax_reverse_ymin ; real_T uib1_Gain ; real_T Constant_Value ; real_T
UnitDelay_InitialCondition ; real_T fromWS_Signal1_Time0 [ 300 ] ; real_T
fromWS_Signal1_Data0 [ 300 ] ; real_T FromWorkspace_Time0 [ 301 ] ; real_T
FromWorkspace_Data0 [ 301 ] ; real_T FromWorkspace1_Time0 [ 301 ] ; real_T
FromWorkspace1_Data0 [ 301 ] ; real_T uSref_Gain ; real_T StateSpace_AS_param
[ 16 ] ; real_T StateSpace_BS_param [ 20 ] ; real_T StateSpace_CS_param [ 24
] ; real_T StateSpace_DS_param [ 30 ] ; real_T StateSpace_X0_param [ 4 ] ;
real_T donotdeletethisgain_Gain ; real_T Gain_Gain ; real_T Gain1_Gain ;
real_T Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T
Constant3_Value ; real_T Constant2_Value ; real_T
donotdeletethisgain_Gain_d1o5clwpjv ; real_T
donotdeletethisgain_Gain_a3rouvps5o ; real_T
donotdeletethisgain_Gain_g2mnwthege ; real_T SwitchCurrents_Value [ 2 ] ;
real_T IW111_Value [ 2 ] ; real_T IW1110_Value [ 2 ] ; real_T IW112_Value [ 2
] ; real_T IW113_Value [ 2 ] ; real_T IW114_Value [ 2 ] ; real_T IW115_Value
[ 2 ] ; real_T IW116_Value [ 2 ] ; real_T IW117_Value [ 2 ] ; real_T
IW118_Value [ 2 ] ; real_T IW119_Value [ 2 ] ; real_T b1_Value [ 10 ] ;
real_T one_Value ; real_T one1_Value ; real_T IW211_Value [ 10 ] ; real_T
b2_Value ; real_T u_K_Value ; real_T Temperature_Value ; real_T Tref_K_Value
; real_T alpha_Isc_Gain ; real_T IL_module_Value ; real_T Rs_array_Value ;
real_T one1_Value_kceix1hyz1 ; real_T Tref_K1_Value ; real_T dEgdT_Gain ;
real_T EgRef_Gain ; real_T Tref_K2_Value ; real_T I0_array_Gain ; real_T
EgRef_Value ; real_T k1_Gain ; real_T Rsh_array_Value ; real_T
Rsh_array_5Sref_Value ; real_T VT_ref_array_Gain ; real_T
one_Value_irz0kd4ki2 ; real_T eee_Value ; uint8_T u_CurrentSetting ; uint8_T
u_CurrentSetting_mybde2y4s0 ; uint8_T u_CurrentSetting_hs31nmoa3a ; uint8_T
u_CurrentSetting_o4g41xxlfn ; uint8_T u_CurrentSetting_khaqidsf01 ; uint8_T
u_CurrentSetting_m1x0003fvm ; uint8_T u_CurrentSetting_fz0kzbgp5d ; uint8_T
u_CurrentSetting_na1jc0pnhw ; uint8_T u_CurrentSetting_e1l1w3mxse ; uint8_T
u_CurrentSetting_ojtqhpabmt ; } ; extern const char_T *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern mxArray * mr_MPPTTestEnviroment_GetDWork ( ) ; extern void
mr_MPPTTestEnviroment_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_MPPTTestEnviroment_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * MPPTTestEnviroment_GetCAPIStaticMap ( void )
; extern SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ;
extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs (
int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T tid ) ; void
MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
