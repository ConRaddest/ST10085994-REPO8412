#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "MPPTTestEnviroment_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 19
#endif
#ifndef SS_INT64
#define SS_INT64 20
#endif
#else
#include "builtin_typeid_types.h"
#include "MPPTTestEnviroment.h"
#include "MPPTTestEnviroment_capi.h"
#include "MPPTTestEnviroment_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"MPPTTestEnviroment/Product" ) , TARGET_STRING ( "Load Power" ) , 0 , 0 , 0 ,
0 , 0 } , { 1 , 0 , TARGET_STRING ( "MPPTTestEnviroment/      3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"MPPTTestEnviroment/MPPT Algorithms/      5" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"MPPTTestEnviroment/MPPT Algorithms/ANN/Saturation" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 2 } , { 4 , 0 , TARGET_STRING (
"MPPTTestEnviroment/MPPT Algorithms/ANN/Add" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 2 } , { 5 , 0 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/VT_ref_array" ) , TARGET_STRING ( "VT"
) , 0 , 0 , 0 , 0 , 3 } , { 6 , 0 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Product" ) , TARGET_STRING ( "Idiode"
) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Product4" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 3 } , { 8 , 0 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Product5" ) , TARGET_STRING (
"IRsh_5%" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Add1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 2 } , { 10 , 0 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Unit Delay" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/IL ctrl/Npar" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 3 } , { 12 , 0 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/IL ctrl/Product1" ) , TARGET_STRING ( "IL" ) , 0
, 0 , 0 , 0 , 2 } , { 13 , 0 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/V_PV/do not delete this gain" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Vdiode/Add1" ) , TARGET_STRING ( "Vd" ) , 0 , 0
, 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"MPPTTestEnviroment/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING
( "" ) , 0 , 0 , 1 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"MPPTTestEnviroment/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING
( "" ) , 1 , 0 , 2 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0
, 0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 17
, TARGET_STRING ( "MPPTTestEnviroment/PV Array" ) , TARGET_STRING ( "Npar" )
, 0 , 0 , 0 } , { 18 , TARGET_STRING ( "MPPTTestEnviroment/Temperature" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 19 , TARGET_STRING (
"MPPTTestEnviroment/      1" ) , TARGET_STRING ( "CurrentSetting" ) , 1 , 0 ,
0 } , { 20 , TARGET_STRING ( "MPPTTestEnviroment/      2" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 0 , 0 } , { 21 , TARGET_STRING (
"MPPTTestEnviroment/      3" ) , TARGET_STRING ( "CurrentSetting" ) , 1 , 0 ,
0 } , { 22 , TARGET_STRING ( "MPPTTestEnviroment/      4" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 0 , 0 } , { 23 , TARGET_STRING (
"MPPTTestEnviroment/      5" ) , TARGET_STRING ( "CurrentSetting" ) , 1 , 0 ,
0 } , { 24 , TARGET_STRING (
"MPPTTestEnviroment/Current Measurement/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 25 , TARGET_STRING (
"MPPTTestEnviroment/MPPT Algorithms/      1" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 0 , 0 } , { 26 , TARGET_STRING (
"MPPTTestEnviroment/MPPT Algorithms/      3" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 0 , 0 } , { 27 , TARGET_STRING (
"MPPTTestEnviroment/MPPT Algorithms/      4" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 0 , 0 } , { 28 , TARGET_STRING (
"MPPTTestEnviroment/MPPT Algorithms/      5" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 0 , 0 } , { 29 , TARGET_STRING (
"MPPTTestEnviroment/MPPT Algorithms/      6" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 0 , 0 } , { 30 , TARGET_STRING (
"MPPTTestEnviroment/Signal Editor/From Workspace" ) , TARGET_STRING ( "Time0"
) , 0 , 3 , 0 } , { 31 , TARGET_STRING (
"MPPTTestEnviroment/Signal Editor/From Workspace" ) , TARGET_STRING ( "Data0"
) , 0 , 3 , 0 } , { 32 , TARGET_STRING (
"MPPTTestEnviroment/Signal Editor/From Workspace1" ) , TARGET_STRING (
"Time0" ) , 0 , 3 , 0 } , { 33 , TARGET_STRING (
"MPPTTestEnviroment/Signal Editor/From Workspace1" ) , TARGET_STRING (
"Data0" ) , 0 , 3 , 0 } , { 34 , TARGET_STRING (
"MPPTTestEnviroment/Signal Editor/fromWS_Signal 1" ) , TARGET_STRING (
"Time0" ) , 0 , 4 , 0 } , { 35 , TARGET_STRING (
"MPPTTestEnviroment/Signal Editor/fromWS_Signal 1" ) , TARGET_STRING (
"Data0" ) , 0 , 4 , 0 } , { 36 , TARGET_STRING (
"MPPTTestEnviroment/Voltage Measurement/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING (
"MPPTTestEnviroment/D1/Model/eee" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 38 , TARGET_STRING ( "MPPTTestEnviroment/MPPT Algorithms/ANN/Saturation"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"MPPTTestEnviroment/MPPT Algorithms/ANN/Saturation" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Rsh_array" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 41 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Rsh_array_5%Sref" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Tref_K1" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 43 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Tref_K2" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 44 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/one" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 45 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/one1" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 46 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/EgRef" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 47 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/I0_array" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 48 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/VT_ref_array" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/dEgdT" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 50 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 51 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/IL ctrl/0_K" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 52 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/IL ctrl/IL_module" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 53 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/IL ctrl/Tref_K" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 54 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/IL ctrl/1//Sref" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 55 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/IL ctrl/alpha_Isc" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 56 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/I_PV/do not delete this gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/V_PV/do not delete this gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Vdiode/Rs_array_" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 59 , TARGET_STRING (
"MPPTTestEnviroment/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING
( "AS_param" ) , 0 , 5 , 0 } , { 60 , TARGET_STRING (
"MPPTTestEnviroment/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING
( "BS_param" ) , 0 , 6 , 0 } , { 61 , TARGET_STRING (
"MPPTTestEnviroment/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING
( "CS_param" ) , 0 , 7 , 0 } , { 62 , TARGET_STRING (
"MPPTTestEnviroment/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING
( "DS_param" ) , 0 , 8 , 0 } , { 63 , TARGET_STRING (
"MPPTTestEnviroment/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING
( "X0_param" ) , 0 , 9 , 0 } , { 64 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Subsystem/EgRef" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING (
"MPPTTestEnviroment/PV Array/Diode Rsh/Subsystem/k1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 66 , TARGET_STRING (
"MPPTTestEnviroment/powergui/EquivalentModel1/Sources/SwitchCurrents" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 67 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/b{1}"
) , TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 68 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 2/b{2}"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 69 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Process Input 1/mapminmax"
) , TARGET_STRING ( "xmin" ) , 0 , 2 , 0 } , { 70 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Process Input 1/mapminmax"
) , TARGET_STRING ( "xmax" ) , 0 , 2 , 0 } , { 71 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Process Input 1/mapminmax"
) , TARGET_STRING ( "ymin" ) , 0 , 0 , 0 } , { 72 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Process Input 1/mapminmax"
) , TARGET_STRING ( "ymax" ) , 0 , 0 , 0 } , { 73 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Process Output 1/mapminmax_reverse"
) , TARGET_STRING ( "xmin" ) , 0 , 0 , 0 } , { 74 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Process Output 1/mapminmax_reverse"
) , TARGET_STRING ( "xmax" ) , 0 , 0 , 0 } , { 75 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Process Output 1/mapminmax_reverse"
) , TARGET_STRING ( "ymin" ) , 0 , 0 , 0 } , { 76 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Process Output 1/mapminmax_reverse"
) , TARGET_STRING ( "ymax" ) , 0 , 0 , 0 } , { 77 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/PWM Generator (5KHz)/Compare To Zero/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 78 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/IW{1,1}/IW{1,1}(1,:)'"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 79 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/IW{1,1}/IW{1,1}(10,:)'"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 80 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/IW{1,1}/IW{1,1}(2,:)'"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 81 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/IW{1,1}/IW{1,1}(3,:)'"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 82 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/IW{1,1}/IW{1,1}(4,:)'"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 83 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/IW{1,1}/IW{1,1}(5,:)'"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 84 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/IW{1,1}/IW{1,1}(6,:)'"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 85 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/IW{1,1}/IW{1,1}(7,:)'"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 86 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/IW{1,1}/IW{1,1}(8,:)'"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 87 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/IW{1,1}/IW{1,1}(9,:)'"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 88 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/tansig/one"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 89 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/tansig/one1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 90 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/tansig/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 91 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 1/tansig/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 92 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/Function Fitting Neural Network/Layer 2/LW{2,1}/IW{2,1}(1,:)'"
) , TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 93 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/PWM Generator (5KHz)/Sawtooth Generator/Model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 94 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/PWM Generator (5KHz)/Sawtooth Generator/Model/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 95 , TARGET_STRING (
 "MPPTTestEnviroment/MPPT Algorithms/ANN/PWM Generator (5KHz)/Sawtooth Generator/Model/1\\ib1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . ezp5fomtbc , & rtB . ddr3qqcafj ,
& rtB . abocamivf3 , & rtB . g40trl0ym0 , & rtB . csrrphvxwc , & rtB .
c3maug3nzc , & rtB . pd05mevuny , & rtB . g1elq1ywpj , & rtB . kpvk44fokn , &
rtB . lzs1gqogb3 , & rtB . akyt3lfkwh , & rtB . bq01lft3hq , & rtB .
njil4ymwjf , & rtB . j1iluh4g4l , & rtB . lkf3m54okc , & rtB . h0wrsbi0st [ 0
] , & rtB . ofammli3u4 [ 0 ] , & rtP . PVArray_Npar , & rtP .
Temperature_Value , & rtP . u_CurrentSetting_khaqidsf01 , & rtP .
u_CurrentSetting_m1x0003fvm , & rtP . u_CurrentSetting_na1jc0pnhw , & rtP .
u_CurrentSetting_fz0kzbgp5d , & rtP . u_CurrentSetting_e1l1w3mxse , & rtP .
donotdeletethisgain_Gain_a3rouvps5o , & rtP . u_CurrentSetting , & rtP .
u_CurrentSetting_mybde2y4s0 , & rtP . u_CurrentSetting_hs31nmoa3a , & rtP .
u_CurrentSetting_ojtqhpabmt , & rtP . u_CurrentSetting_o4g41xxlfn , & rtP .
FromWorkspace_Time0 [ 0 ] , & rtP . FromWorkspace_Data0 [ 0 ] , & rtP .
FromWorkspace1_Time0 [ 0 ] , & rtP . FromWorkspace1_Data0 [ 0 ] , & rtP .
fromWS_Signal1_Time0 [ 0 ] , & rtP . fromWS_Signal1_Data0 [ 0 ] , & rtP .
donotdeletethisgain_Gain_g2mnwthege , & rtP . eee_Value , & rtP .
Saturation_UpperSat , & rtP . Saturation_LowerSat , & rtP . Rsh_array_Value ,
& rtP . Rsh_array_5Sref_Value , & rtP . Tref_K1_Value , & rtP . Tref_K2_Value
, & rtP . one_Value_irz0kd4ki2 , & rtP . one1_Value_kceix1hyz1 , & rtP .
EgRef_Gain , & rtP . I0_array_Gain , & rtP . VT_ref_array_Gain , & rtP .
dEgdT_Gain , & rtP . UnitDelay_InitialCondition , & rtP . u_K_Value , & rtP .
IL_module_Value , & rtP . Tref_K_Value , & rtP . uSref_Gain , & rtP .
alpha_Isc_Gain , & rtP . donotdeletethisgain_Gain_d1o5clwpjv , & rtP .
donotdeletethisgain_Gain , & rtP . Rs_array_Value , & rtP .
StateSpace_AS_param [ 0 ] , & rtP . StateSpace_BS_param [ 0 ] , & rtP .
StateSpace_CS_param [ 0 ] , & rtP . StateSpace_DS_param [ 0 ] , & rtP .
StateSpace_X0_param [ 0 ] , & rtP . EgRef_Value , & rtP . k1_Gain , & rtP .
SwitchCurrents_Value [ 0 ] , & rtP . b1_Value [ 0 ] , & rtP . b2_Value , &
rtP . mapminmax_xmin [ 0 ] , & rtP . mapminmax_xmax [ 0 ] , & rtP .
mapminmax_ymin , & rtP . mapminmax_ymax , & rtP . mapminmax_reverse_xmin , &
rtP . mapminmax_reverse_xmax , & rtP . mapminmax_reverse_ymin , & rtP .
mapminmax_reverse_ymax , & rtP . Constant_Value , & rtP . IW111_Value [ 0 ] ,
& rtP . IW1110_Value [ 0 ] , & rtP . IW112_Value [ 0 ] , & rtP . IW113_Value
[ 0 ] , & rtP . IW114_Value [ 0 ] , & rtP . IW115_Value [ 0 ] , & rtP .
IW116_Value [ 0 ] , & rtP . IW117_Value [ 0 ] , & rtP . IW118_Value [ 0 ] , &
rtP . IW119_Value [ 0 ] , & rtP . one_Value , & rtP . one1_Value , & rtP .
Gain_Gain , & rtP . Gain1_Gain , & rtP . IW211_Value [ 0 ] , & rtP .
Constant2_Value , & rtP . Constant3_Value , & rtP . uib1_Gain , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 16 , 2 , 0 } , { rtwCAPI_VECTOR , 18 , 2
, 0 } , { rtwCAPI_VECTOR , 20 , 2 , 0 } } ; static const uint_T
rtDimensionArray [ ] = { 1 , 1 , 6 , 1 , 2 , 1 , 301 , 1 , 300 , 1 , 4 , 4 ,
4 , 5 , 6 , 4 , 6 , 5 , 4 , 1 , 10 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 1.0E-5 , 0.0 , 1.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 2 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ]
, ( const void * ) & rtcapiStoredFloats [ 2 ] , ( int8_T ) 1 , ( uint8_T ) 0
} , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( NULL ) , (
NULL ) , 3 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 17 , rtRootInputs , 0 , rtRootOutputs , 0 } , {
rtBlockParameters , 79 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 160205490U , 299420185U , 1323767297U ,
761063030U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * MPPTTestEnviroment_GetCAPIStaticMap (
void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void MPPTTestEnviroment_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion (
( * rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void MPPTTestEnviroment_host_InitializeDataMapInfo (
MPPTTestEnviroment_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
