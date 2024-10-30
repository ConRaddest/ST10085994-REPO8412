#include "MPPTTestEnviroment.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "MPPTTestEnviroment_private.h"
#include "rt_logging_mmi.h"
#include "MPPTTestEnviroment_capi.h"
#include "MPPTTestEnviroment_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; extern ssExecutionInfo gblExecutionInfo ; RTWExtModeInfo *
gblRTWExtModeInfo = NULL ; void raccelForceExtModeShutdown ( boolean_T
extModeStartPktReceived ) { if ( ! extModeStartPktReceived ) { boolean_T
stopRequested = false ; rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , &
stopRequested ) ; } rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_engine_exec.h"
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "24.1 (R2024a) 19-Nov-2023" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 } ;
const char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const
char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_engine_exec.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void MdlInitialize ( void ) { rtDW . exeralr4po = rtP .
UnitDelay_InitialCondition ; { int32_T i , j ; real_T * As = ( real_T * )
rtDW . mzxjwgc5lv . AS ; real_T * Bs = ( real_T * ) rtDW . mzxjwgc5lv . BS ;
real_T * Cs = ( real_T * ) rtDW . mzxjwgc5lv . CS ; real_T * Ds = ( real_T *
) rtDW . mzxjwgc5lv . DS ; real_T * X0 = ( real_T * ) & rtDW . g5ufooow0i [ 0
] ; for ( i = 0 ; i < 4 ; i ++ ) { X0 [ i ] = ( rtP . StateSpace_X0_param [ i
] ) ; } for ( i = 0 ; i < 4 ; i ++ ) { for ( j = 0 ; j < 4 ; j ++ ) As [ i *
4 + j ] = ( rtP . StateSpace_AS_param [ i + j * 4 ] ) ; for ( j = 0 ; j < 5 ;
j ++ ) Bs [ i * 5 + j ] = ( rtP . StateSpace_BS_param [ i + j * 4 ] ) ; } for
( i = 0 ; i < 6 ; i ++ ) { for ( j = 0 ; j < 4 ; j ++ ) Cs [ i * 4 + j ] = (
rtP . StateSpace_CS_param [ i + j * 6 ] ) ; } for ( i = 0 ; i < 6 ; i ++ ) {
for ( j = 0 ; j < 5 ; j ++ ) Ds [ i * 5 + j ] = ( rtP . StateSpace_DS_param [
i + j * 6 ] ) ; } { int_T * switch_status = ( int_T * ) rtDW . mzxjwgc5lv .
SWITCH_STATUS ; int_T * gState = ( int_T * ) rtDW . mzxjwgc5lv . G_STATE ;
real_T * yswitch = ( real_T * ) rtDW . mzxjwgc5lv . Y_SWITCH ; int_T *
switchTypes = ( int_T * ) rtDW . mzxjwgc5lv . SWITCH_TYPES ; int_T * idxOutSw
= ( int_T * ) rtDW . mzxjwgc5lv . IDX_OUT_SW ; int_T * switch_status_init = (
int_T * ) rtDW . mzxjwgc5lv . SWITCH_STATUS_INIT ; switch_status [ 0 ] = 0 ;
switch_status_init [ 0 ] = 0 ; gState [ 0 ] = ( int_T ) 0.0 ; yswitch [ 0 ] =
1 / 0.001 ; switchTypes [ 0 ] = ( int_T ) 3.0 ; idxOutSw [ 0 ] = ( ( int_T )
0.0 ) - 1 ; switch_status [ 1 ] = 0 ; switch_status_init [ 1 ] = 0 ; gState [
1 ] = ( int_T ) 0.0 ; yswitch [ 1 ] = 1 / 0.001 ; switchTypes [ 1 ] = ( int_T
) 7.0 ; idxOutSw [ 1 ] = ( ( int_T ) 0.0 ) - 1 ; } } } void MdlStart ( void )
{ { bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
 "Simulink.signaleditorblock.SimulationData.getData('TVBQVFRlc3RFbnZpcm9tZW50L1NpZ25hbCBFZGl0b3I=','1')"
; fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0 ; fromwksInfo
-> nDataPoints = 300 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0 ; rtDW . jqrqq3twqe . TimePtr = fromwksInfo -> time ;
rtDW . jqrqq3twqe . DataPtr = fromwksInfo -> data ; rtDW . jqrqq3twqe .
RSimInfoPtr = fromwksInfo ; } rtDW . h1nceqotqd . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
 "Simulink.signaleditorblock.SimulationData.getData('TVBQVFRlc3RFbnZpcm9tZW50L1NpZ25hbCBFZGl0b3I=','2')"
; fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace_Data0 ; fromwksInfo ->
nDataPoints = 301 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0 ; rtDW . j4uq2hdcjm . TimePtr = fromwksInfo -> time ;
rtDW . j4uq2hdcjm . DataPtr = fromwksInfo -> data ; rtDW . j4uq2hdcjm .
RSimInfoPtr = fromwksInfo ; } rtDW . cvaln4lwyx . PrevIndex = 0 ; } {
FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 ,
sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
 "Simulink.signaleditorblock.SimulationData.getData('TVBQVFRlc3RFbnZpcm9tZW50L1NpZ25hbCBFZGl0b3I=','3')"
; fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . FromWorkspace1_Data0 ; fromwksInfo
-> nDataPoints = 301 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace1_Time0 ; rtDW . lazvpzocdc . TimePtr = fromwksInfo -> time ;
rtDW . lazvpzocdc . DataPtr = fromwksInfo -> data ; rtDW . lazvpzocdc .
RSimInfoPtr = fromwksInfo ; } rtDW . axcms0d2td . PrevIndex = 0 ; } { rtDW .
mzxjwgc5lv . AS = ( real_T * ) calloc ( 4 * 4 , sizeof ( real_T ) ) ; rtDW .
mzxjwgc5lv . BS = ( real_T * ) calloc ( 4 * 5 , sizeof ( real_T ) ) ; rtDW .
mzxjwgc5lv . CS = ( real_T * ) calloc ( 6 * 4 , sizeof ( real_T ) ) ; rtDW .
mzxjwgc5lv . DS = ( real_T * ) calloc ( 6 * 5 , sizeof ( real_T ) ) ; rtDW .
mzxjwgc5lv . DX_COL = ( real_T * ) calloc ( 6 , sizeof ( real_T ) ) ; rtDW .
mzxjwgc5lv . TMP2 = ( real_T * ) calloc ( 5 , sizeof ( real_T ) ) ; rtDW .
mzxjwgc5lv . BD_COL = ( real_T * ) calloc ( 4 , sizeof ( real_T ) ) ; rtDW .
mzxjwgc5lv . TMP1 = ( real_T * ) calloc ( 4 , sizeof ( real_T ) ) ; rtDW .
mzxjwgc5lv . XTMP = ( real_T * ) calloc ( 4 , sizeof ( real_T ) ) ; rtDW .
mzxjwgc5lv . SWITCH_STATUS = ( int_T * ) calloc ( 2 , sizeof ( int_T ) ) ;
rtDW . mzxjwgc5lv . SW_CHG = ( int_T * ) calloc ( 2 , sizeof ( int_T ) ) ;
rtDW . mzxjwgc5lv . G_STATE = ( int_T * ) calloc ( 2 , sizeof ( int_T ) ) ;
rtDW . mzxjwgc5lv . Y_SWITCH = ( real_T * ) calloc ( 2 , sizeof ( real_T ) )
; rtDW . mzxjwgc5lv . SWITCH_TYPES = ( int_T * ) calloc ( 2 , sizeof ( int_T
) ) ; rtDW . mzxjwgc5lv . IDX_OUT_SW = ( int_T * ) calloc ( 2 , sizeof (
int_T ) ) ; rtDW . mzxjwgc5lv . SWITCH_STATUS_INIT = ( int_T * ) calloc ( 2 ,
sizeof ( int_T ) ) ; rtDW . mzxjwgc5lv . USWLAST = ( real_T * ) calloc ( 2 ,
sizeof ( real_T ) ) ; } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) {
real_T jhxzj0j1yk ; real_T lculvq11lu ; real_T cwomxrvrgs ; real_T tmp [ 10 ]
; real_T kihd0txh5z_idx_1 ; real_T ocj3sfrhu0 ; real_T oy3r5akymm ; int32_T i
; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . akyt3lfkwh = rtDW . exeralr4po
; } { real_T t = ssGetTaskTime ( rtS , 0 ) ; real_T * pTimeValues = ( real_T
* ) rtDW . jqrqq3twqe . TimePtr ; real_T * pDataValues = ( real_T * ) rtDW .
jqrqq3twqe . DataPtr ; int numPoints , lastPoint ; FWksInfo * fromwksInfo = (
FWksInfo * ) rtDW . jqrqq3twqe . RSimInfoPtr ; numPoints = fromwksInfo ->
nDataPoints ; lastPoint = numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) {
jhxzj0j1yk = 0.0 ; } else if ( t == pTimeValues [ lastPoint ] ) { jhxzj0j1yk
= pDataValues [ lastPoint ] ; } else if ( t > pTimeValues [ lastPoint ] ) {
jhxzj0j1yk = 0.0 ; } else { int_T currTimeIndex = rtDW . h1nceqotqd .
PrevIndex ; if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } jhxzj0j1yk =
pDataValues [ currTimeIndex ] ; rtDW . h1nceqotqd . PrevIndex = currTimeIndex
; } } { real_T t = ssGetTaskTime ( rtS , 0 ) ; real_T * pTimeValues = (
real_T * ) rtDW . j4uq2hdcjm . TimePtr ; real_T * pDataValues = ( real_T * )
rtDW . j4uq2hdcjm . DataPtr ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . j4uq2hdcjm . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t < pTimeValues
[ 0 ] ) { lculvq11lu = 0.0 ; } else if ( t == pTimeValues [ lastPoint ] ) {
lculvq11lu = pDataValues [ lastPoint ] ; } else if ( t > pTimeValues [
lastPoint ] ) { lculvq11lu = 0.0 ; } else { int_T currTimeIndex = rtDW .
cvaln4lwyx . PrevIndex ; if ( t < pTimeValues [ currTimeIndex ] ) { while ( t
< pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t
>= pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } lculvq11lu =
pDataValues [ currTimeIndex ] ; rtDW . cvaln4lwyx . PrevIndex = currTimeIndex
; } } { real_T t = ssGetTaskTime ( rtS , 0 ) ; real_T * pTimeValues = (
real_T * ) rtDW . lazvpzocdc . TimePtr ; real_T * pDataValues = ( real_T * )
rtDW . lazvpzocdc . DataPtr ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . lazvpzocdc . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t < pTimeValues
[ 0 ] ) { cwomxrvrgs = 0.0 ; } else if ( t == pTimeValues [ lastPoint ] ) {
cwomxrvrgs = pDataValues [ lastPoint ] ; } else if ( t > pTimeValues [
lastPoint ] ) { cwomxrvrgs = 0.0 ; } else { int_T currTimeIndex = rtDW .
axcms0d2td . PrevIndex ; if ( t < pTimeValues [ currTimeIndex ] ) { while ( t
< pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t
>= pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } cwomxrvrgs =
pDataValues [ currTimeIndex ] ; rtDW . axcms0d2td . PrevIndex = currTimeIndex
; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ddr3qqcafj = 0.0 ; } if (
rtP . u_CurrentSetting_e1l1w3mxse == 1 ) { if ( rtP .
u_CurrentSetting_fz0kzbgp5d == 1 ) { if ( rtP . u_CurrentSetting_khaqidsf01
== 1 ) { oy3r5akymm = jhxzj0j1yk ; } else { oy3r5akymm = lculvq11lu ; } }
else if ( rtP . u_CurrentSetting_m1x0003fvm == 1 ) { oy3r5akymm = cwomxrvrgs
; } else { oy3r5akymm = 0.0 ; } } else { oy3r5akymm = rtB . ddr3qqcafj ; }
ocj3sfrhu0 = rtP . uSref_Gain * oy3r5akymm ; rtB . njil4ymwjf = rtB .
bq01lft3hq * ocj3sfrhu0 ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { { real_T
accum ; int_T * switch_status = ( int_T * ) rtDW . mzxjwgc5lv . SWITCH_STATUS
; int_T * switch_status_init = ( int_T * ) rtDW . mzxjwgc5lv .
SWITCH_STATUS_INIT ; int_T * SwitchChange = ( int_T * ) rtDW . mzxjwgc5lv .
SW_CHG ; int_T * gState = ( int_T * ) rtDW . mzxjwgc5lv . G_STATE ; real_T *
yswitch = ( real_T * ) rtDW . mzxjwgc5lv . Y_SWITCH ; int_T * switchTypes = (
int_T * ) rtDW . mzxjwgc5lv . SWITCH_TYPES ; int_T * idxOutSw = ( int_T * )
rtDW . mzxjwgc5lv . IDX_OUT_SW ; real_T * DxCol = ( real_T * ) rtDW .
mzxjwgc5lv . DX_COL ; real_T * tmp2 = ( real_T * ) rtDW . mzxjwgc5lv . TMP2 ;
real_T * BDcol = ( real_T * ) rtDW . mzxjwgc5lv . BD_COL ; real_T * tmp1 = (
real_T * ) rtDW . mzxjwgc5lv . TMP1 ; real_T * uswlast = ( real_T * ) rtDW .
mzxjwgc5lv . USWLAST ; int_T newState ; int_T swChanged = 0 ; int loopsToDo =
20 ; real_T temp ; memcpy ( switch_status_init , switch_status , 2 * sizeof (
int_T ) ) ; memcpy ( uswlast , & rtB . h0wrsbi0st [ 0 ] , 2 * sizeof ( real_T
) ) ; do { if ( loopsToDo == 1 ) { swChanged = 0 ; { int_T i1 ; for ( i1 = 0
; i1 < 2 ; i1 ++ ) { swChanged = ( ( SwitchChange [ i1 ] = switch_status_init
[ i1 ] - switch_status [ i1 ] ) != 0 ) ? 1 : swChanged ; switch_status [ i1 ]
= switch_status_init [ i1 ] ; } } } else { real_T * Cs = ( real_T * ) rtDW .
mzxjwgc5lv . CS ; real_T * Ds = ( real_T * ) rtDW . mzxjwgc5lv . DS ; { int_T
i1 ; real_T * y0 = & rtB . h0wrsbi0st [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ )
{ accum = 0.0 ; accum += * ( Cs ++ ) * rtDW . g5ufooow0i [ 0 ] ; accum += * (
Cs ++ ) * rtDW . g5ufooow0i [ 1 ] ; accum += * ( Cs ++ ) * rtDW . g5ufooow0i
[ 2 ] ; accum += * ( Cs ++ ) * rtDW . g5ufooow0i [ 3 ] ; accum += * ( Ds ++ )
* rtP . SwitchCurrents_Value [ 0 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 1 ] ; accum += * ( Ds ++ ) * rtB . akyt3lfkwh ; accum
+= * ( Ds ++ ) * rtB . njil4ymwjf ; accum += * ( Ds ++ ) * rtP . eee_Value ;
y0 [ i1 ] = accum ; } } swChanged = 0 ; newState = rtB . h0wrsbi0st [ 0 ] >
0.0 ? 1 : ( ( rtB . h0wrsbi0st [ 0 ] < 0.0 ) ? 0 : switch_status [ 0 ] ) ;
swChanged = ( ( SwitchChange [ 0 ] = newState - switch_status [ 0 ] ) != 0 )
? 1 : swChanged ; switch_status [ 0 ] = newState ; newState = ( ( rtB .
h0wrsbi0st [ 1 ] > 0.0 ) && ( gState [ 1 ] > 0 ) ) || ( rtB . h0wrsbi0st [ 1
] < 0.0 ) ? 1 : ( ( ( rtB . h0wrsbi0st [ 1 ] > 0.0 ) && gState [ 1 ] == 0 ) ?
0 : switch_status [ 1 ] ) ; swChanged = ( ( SwitchChange [ 1 ] = newState -
switch_status [ 1 ] ) != 0 ) ? 1 : swChanged ; switch_status [ 1 ] = newState
; } if ( swChanged ) { real_T * As = ( real_T * ) rtDW . mzxjwgc5lv . AS ;
real_T * Cs = ( real_T * ) rtDW . mzxjwgc5lv . CS ; real_T * Bs = ( real_T *
) rtDW . mzxjwgc5lv . BS ; real_T * Ds = ( real_T * ) rtDW . mzxjwgc5lv . DS
; real_T a1 ; { int_T i1 ; for ( i1 = 0 ; i1 < 2 ; i1 ++ ) { if (
SwitchChange [ i1 ] != 0 ) { a1 = 1000.0 * SwitchChange [ i1 ] ; temp = 1 / (
1 - Ds [ i1 * 6 ] * a1 ) ; { int_T i2 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) {
DxCol [ i2 ] = Ds [ i2 * 5 + i1 ] * temp * a1 ; } } DxCol [ i1 ] = temp ;
BDcol [ 0 ] = Bs [ 0 + i1 ] * a1 ; BDcol [ 1 ] = Bs [ 5 + i1 ] * a1 ; BDcol [
2 ] = Bs [ 10 + i1 ] * a1 ; BDcol [ 3 ] = Bs [ 15 + i1 ] * a1 ; memcpy ( tmp1
, & Cs [ i1 * 4 ] , 4 * sizeof ( real_T ) ) ; memset ( & Cs [ i1 * 4 ] , '\0'
, 4 * sizeof ( real_T ) ) ; memcpy ( tmp2 , & Ds [ i1 * 5 ] , 5 * sizeof (
real_T ) ) ; memset ( & Ds [ i1 * 5 ] , '\0' , 5 * sizeof ( real_T ) ) ; {
int_T i2 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { a1 = DxCol [ i2 ] ; Cs [ i2 * 4
+ 0 ] += a1 * tmp1 [ 0 ] ; Cs [ i2 * 4 + 1 ] += a1 * tmp1 [ 1 ] ; Cs [ i2 * 4
+ 2 ] += a1 * tmp1 [ 2 ] ; Cs [ i2 * 4 + 3 ] += a1 * tmp1 [ 3 ] ; { int_T i3
; for ( i3 = 0 ; i3 < 5 ; i3 ++ ) { Ds [ i2 * 5 + i3 ] += a1 * tmp2 [ i3 ] ;
} } } } a1 = BDcol [ 0 ] ; As [ 0 + 0 ] += a1 * Cs [ i1 * 4 + 0 ] ; As [ 0 +
1 ] += a1 * Cs [ i1 * 4 + 1 ] ; As [ 0 + 2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [
0 + 3 ] += a1 * Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ; i2 < 5 ; i2
++ ) { Bs [ 0 + i2 ] += a1 * Ds [ i1 * 5 + i2 ] ; } } a1 = BDcol [ 1 ] ; As [
4 + 0 ] += a1 * Cs [ i1 * 4 + 0 ] ; As [ 4 + 1 ] += a1 * Cs [ i1 * 4 + 1 ] ;
As [ 4 + 2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [ 4 + 3 ] += a1 * Cs [ i1 * 4 + 3
] ; { int_T i2 ; for ( i2 = 0 ; i2 < 5 ; i2 ++ ) { Bs [ 5 + i2 ] += a1 * Ds [
i1 * 5 + i2 ] ; } } a1 = BDcol [ 2 ] ; As [ 8 + 0 ] += a1 * Cs [ i1 * 4 + 0 ]
; As [ 8 + 1 ] += a1 * Cs [ i1 * 4 + 1 ] ; As [ 8 + 2 ] += a1 * Cs [ i1 * 4 +
2 ] ; As [ 8 + 3 ] += a1 * Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ; i2
< 5 ; i2 ++ ) { Bs [ 10 + i2 ] += a1 * Ds [ i1 * 5 + i2 ] ; } } a1 = BDcol [
3 ] ; As [ 12 + 0 ] += a1 * Cs [ i1 * 4 + 0 ] ; As [ 12 + 1 ] += a1 * Cs [ i1
* 4 + 1 ] ; As [ 12 + 2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [ 12 + 3 ] += a1 *
Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ; i2 < 5 ; i2 ++ ) { Bs [ 15 +
i2 ] += a1 * Ds [ i1 * 5 + i2 ] ; } } } } } } } while ( swChanged > 0 && --
loopsToDo > 0 ) ; if ( loopsToDo == 0 ) { real_T * Cs = ( real_T * ) rtDW .
mzxjwgc5lv . CS ; real_T * Ds = ( real_T * ) rtDW . mzxjwgc5lv . DS ; { int_T
i1 ; real_T * y0 = & rtB . h0wrsbi0st [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ )
{ accum = 0.0 ; accum += * ( Cs ++ ) * rtDW . g5ufooow0i [ 0 ] ; accum += * (
Cs ++ ) * rtDW . g5ufooow0i [ 1 ] ; accum += * ( Cs ++ ) * rtDW . g5ufooow0i
[ 2 ] ; accum += * ( Cs ++ ) * rtDW . g5ufooow0i [ 3 ] ; accum += * ( Ds ++ )
* rtP . SwitchCurrents_Value [ 0 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 1 ] ; accum += * ( Ds ++ ) * rtB . akyt3lfkwh ; accum
+= * ( Ds ++ ) * rtB . njil4ymwjf ; accum += * ( Ds ++ ) * rtP . eee_Value ;
y0 [ i1 ] = accum ; } } } rtB . ofammli3u4 [ 0 ] = ( real_T ) switch_status [
0 ] ; rtB . ofammli3u4 [ 1 ] = ( real_T ) switch_status [ 1 ] ; } rtB .
j1iluh4g4l = rtP . donotdeletethisgain_Gain * rtB . h0wrsbi0st [ 2 ] ; }
kihd0txh5z_idx_1 = rtP . mapminmax_ymax - rtP . mapminmax_ymin ; oy3r5akymm =
kihd0txh5z_idx_1 / ( rtP . mapminmax_xmax [ 0 ] - rtP . mapminmax_xmin [ 0 ]
) * ( oy3r5akymm - rtP . mapminmax_xmin [ 0 ] ) + rtP . mapminmax_ymin ;
kihd0txh5z_idx_1 = kihd0txh5z_idx_1 / ( rtP . mapminmax_xmax [ 1 ] - rtP .
mapminmax_xmin [ 1 ] ) * ( rtP . Temperature_Value - rtP . mapminmax_xmin [ 1
] ) + rtP . mapminmax_ymin ; tmp [ 0 ] = ( ( rtP . IW111_Value [ 0 ] *
oy3r5akymm + rtP . IW111_Value [ 1 ] * kihd0txh5z_idx_1 ) + rtP . b1_Value [
0 ] ) * rtP . Gain_Gain ; tmp [ 1 ] = ( ( rtP . IW112_Value [ 0 ] *
oy3r5akymm + rtP . IW112_Value [ 1 ] * kihd0txh5z_idx_1 ) + rtP . b1_Value [
1 ] ) * rtP . Gain_Gain ; tmp [ 2 ] = ( ( rtP . IW113_Value [ 0 ] *
oy3r5akymm + rtP . IW113_Value [ 1 ] * kihd0txh5z_idx_1 ) + rtP . b1_Value [
2 ] ) * rtP . Gain_Gain ; tmp [ 3 ] = ( ( rtP . IW114_Value [ 0 ] *
oy3r5akymm + rtP . IW114_Value [ 1 ] * kihd0txh5z_idx_1 ) + rtP . b1_Value [
3 ] ) * rtP . Gain_Gain ; tmp [ 4 ] = ( ( rtP . IW115_Value [ 0 ] *
oy3r5akymm + rtP . IW115_Value [ 1 ] * kihd0txh5z_idx_1 ) + rtP . b1_Value [
4 ] ) * rtP . Gain_Gain ; tmp [ 5 ] = ( ( rtP . IW116_Value [ 0 ] *
oy3r5akymm + rtP . IW116_Value [ 1 ] * kihd0txh5z_idx_1 ) + rtP . b1_Value [
5 ] ) * rtP . Gain_Gain ; tmp [ 6 ] = ( ( rtP . IW117_Value [ 0 ] *
oy3r5akymm + rtP . IW117_Value [ 1 ] * kihd0txh5z_idx_1 ) + rtP . b1_Value [
6 ] ) * rtP . Gain_Gain ; tmp [ 7 ] = ( ( rtP . IW118_Value [ 0 ] *
oy3r5akymm + rtP . IW118_Value [ 1 ] * kihd0txh5z_idx_1 ) + rtP . b1_Value [
7 ] ) * rtP . Gain_Gain ; tmp [ 8 ] = ( ( rtP . IW119_Value [ 0 ] *
oy3r5akymm + rtP . IW119_Value [ 1 ] * kihd0txh5z_idx_1 ) + rtP . b1_Value [
8 ] ) * rtP . Gain_Gain ; tmp [ 9 ] = ( ( rtP . IW1110_Value [ 0 ] *
oy3r5akymm + rtP . IW1110_Value [ 1 ] * kihd0txh5z_idx_1 ) + rtP . b1_Value [
9 ] ) * rtP . Gain_Gain ; kihd0txh5z_idx_1 = 0.0 ; for ( i = 0 ; i < 10 ; i
++ ) { kihd0txh5z_idx_1 += ( 1.0 / ( muDoubleScalarExp ( tmp [ i ] ) + rtP .
one_Value ) * rtP . Gain1_Gain - rtP . one1_Value ) * rtP . IW211_Value [ i ]
; } rtB . csrrphvxwc = rtB . j1iluh4g4l - ( ( rtP . mapminmax_reverse_xmax -
rtP . mapminmax_reverse_xmin ) / ( rtP . mapminmax_reverse_ymax - rtP .
mapminmax_reverse_ymin ) * ( ( kihd0txh5z_idx_1 + rtP . b2_Value ) - rtP .
mapminmax_reverse_ymin ) + rtP . mapminmax_reverse_xmin ) ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtB . csrrphvxwc >= rtP .
Saturation_UpperSat ) { rtDW . esoqq5ahh2 = 1 ; } else if ( rtB . csrrphvxwc
> rtP . Saturation_LowerSat ) { rtDW . esoqq5ahh2 = 0 ; } else { rtDW .
esoqq5ahh2 = - 1 ; } } if ( rtDW . esoqq5ahh2 == 1 ) { rtB . g40trl0ym0 = rtP
. Saturation_UpperSat ; } else if ( rtDW . esoqq5ahh2 == - 1 ) { rtB .
g40trl0ym0 = rtP . Saturation_LowerSat ; } else { rtB . g40trl0ym0 = rtB .
csrrphvxwc ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { if ( rtP .
u_CurrentSetting_ojtqhpabmt == 1 ) { rtB . abocamivf3 = 0.0 ; } else if ( rtP
. u_CurrentSetting_o4g41xxlfn == 1 ) { rtB . abocamivf3 = ( ( rtB .
g40trl0ym0 != rtP . Constant_Value ) && ( rtB . g40trl0ym0 >= ( (
muDoubleScalarRem ( ssGetTaskTime ( rtS , 2 ) + rtP . Constant3_Value , rtP .
Constant2_Value ) * rtP . uib1_Gain * 2.0 - 1.0 ) + 1.0 ) * 0.5 ) ) ; } else
{ rtB . abocamivf3 = 0.0 ; } rtB . lkf3m54okc = rtP .
donotdeletethisgain_Gain_d1o5clwpjv * rtB . h0wrsbi0st [ 5 ] * rtP .
Rs_array_Value + rtB . j1iluh4g4l ; rtB . pd05mevuny = ( muDoubleScalarExp (
1.0 / rtB . c3maug3nzc * rtB . lkf3m54okc ) - rtP . one_Value_irz0kd4ki2 ) *
rtB . g1elq1ywpj ; rtB . kpvk44fokn = rtB . lkf3m54okc / rtP .
Rsh_array_5Sref_Value ; } rtB . lzs1gqogb3 = ( rtB . lkf3m54okc / rtP .
Rsh_array_Value * ocj3sfrhu0 + rtB . pd05mevuny ) - rtB . kpvk44fokn ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . ezp5fomtbc = rtP .
donotdeletethisgain_Gain_a3rouvps5o * rtB . h0wrsbi0st [ 4 ] * ( rtP .
donotdeletethisgain_Gain_g2mnwthege * rtB . h0wrsbi0st [ 3 ] ) ; }
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID3 ( int_T tid ) { real_T
gyuvhypjss ; real_T ler2ph3iwy ; ler2ph3iwy = rtP . Temperature_Value + rtP .
u_K_Value ; rtB . bq01lft3hq = ( ( ler2ph3iwy - rtP . Tref_K_Value ) * rtP .
alpha_Isc_Gain + rtP . IL_module_Value ) * rtP . PVArray_Npar ; gyuvhypjss =
ler2ph3iwy / rtP . Tref_K2_Value ; rtB . g1elq1ywpj = muDoubleScalarExp ( rtP
. EgRef_Value - ( ( ler2ph3iwy - rtP . Tref_K1_Value ) * rtP . dEgdT_Gain +
rtP . one1_Value_kceix1hyz1 ) * rtP . EgRef_Gain / ( rtP . k1_Gain *
ler2ph3iwy ) ) * ( rtP . I0_array_Gain * muDoubleScalarPower ( gyuvhypjss ,
3.0 ) ) ; rtB . c3maug3nzc = rtP . VT_ref_array_Gain * gyuvhypjss ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . exeralr4po = rtB . lzs1gqogb3 ; {
const real_T * As = ( real_T * ) rtDW . mzxjwgc5lv . AS ; const real_T * Bs =
( real_T * ) rtDW . mzxjwgc5lv . BS ; real_T * xtmp = ( real_T * ) rtDW .
mzxjwgc5lv . XTMP ; real_T accum ; accum = 0.0 ; accum += * ( As ++ ) * rtDW
. g5ufooow0i [ 0 ] ; accum += * ( As ++ ) * rtDW . g5ufooow0i [ 1 ] ; accum
+= * ( As ++ ) * rtDW . g5ufooow0i [ 2 ] ; accum += * ( As ++ ) * rtDW .
g5ufooow0i [ 3 ] ; accum += * ( Bs ++ ) * rtP . SwitchCurrents_Value [ 0 ] ;
accum += * ( Bs ++ ) * rtP . SwitchCurrents_Value [ 1 ] ; accum += * ( Bs ++
) * rtB . akyt3lfkwh ; accum += * ( Bs ++ ) * rtB . njil4ymwjf ; accum += * (
Bs ++ ) * rtP . eee_Value ; xtmp [ 0 ] = accum ; accum = 0.0 ; accum += * (
As ++ ) * rtDW . g5ufooow0i [ 0 ] ; accum += * ( As ++ ) * rtDW . g5ufooow0i
[ 1 ] ; accum += * ( As ++ ) * rtDW . g5ufooow0i [ 2 ] ; accum += * ( As ++ )
* rtDW . g5ufooow0i [ 3 ] ; accum += * ( Bs ++ ) * rtP . SwitchCurrents_Value
[ 0 ] ; accum += * ( Bs ++ ) * rtP . SwitchCurrents_Value [ 1 ] ; accum += *
( Bs ++ ) * rtB . akyt3lfkwh ; accum += * ( Bs ++ ) * rtB . njil4ymwjf ;
accum += * ( Bs ++ ) * rtP . eee_Value ; xtmp [ 1 ] = accum ; accum = 0.0 ;
accum += * ( As ++ ) * rtDW . g5ufooow0i [ 0 ] ; accum += * ( As ++ ) * rtDW
. g5ufooow0i [ 1 ] ; accum += * ( As ++ ) * rtDW . g5ufooow0i [ 2 ] ; accum
+= * ( As ++ ) * rtDW . g5ufooow0i [ 3 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 0 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 1 ] ; accum += * ( Bs ++ ) * rtB . akyt3lfkwh ; accum
+= * ( Bs ++ ) * rtB . njil4ymwjf ; accum += * ( Bs ++ ) * rtP . eee_Value ;
xtmp [ 2 ] = accum ; accum = 0.0 ; accum += * ( As ++ ) * rtDW . g5ufooow0i [
0 ] ; accum += * ( As ++ ) * rtDW . g5ufooow0i [ 1 ] ; accum += * ( As ++ ) *
rtDW . g5ufooow0i [ 2 ] ; accum += * ( As ++ ) * rtDW . g5ufooow0i [ 3 ] ;
accum += * ( Bs ++ ) * rtP . SwitchCurrents_Value [ 0 ] ; accum += * ( Bs ++
) * rtP . SwitchCurrents_Value [ 1 ] ; accum += * ( Bs ++ ) * rtB .
akyt3lfkwh ; accum += * ( Bs ++ ) * rtB . njil4ymwjf ; accum += * ( Bs ++ ) *
rtP . eee_Value ; xtmp [ 3 ] = accum ; rtDW . g5ufooow0i [ 0 ] = xtmp [ 0 ] ;
rtDW . g5ufooow0i [ 1 ] = xtmp [ 1 ] ; rtDW . g5ufooow0i [ 2 ] = xtmp [ 2 ] ;
rtDW . g5ufooow0i [ 3 ] = xtmp [ 3 ] ; { int_T * gState = ( int_T * ) rtDW .
mzxjwgc5lv . G_STATE ; * ( gState ++ ) = ( int_T ) 0.0 ; * ( gState ++ ) = (
int_T ) rtB . abocamivf3 ; } } } UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID3 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> jnz5kaloxr = rtB .
csrrphvxwc - rtP . Saturation_UpperSat ; _rtZCSV -> ar5fnf0tyl = rtB .
csrrphvxwc - rtP . Saturation_LowerSat ; } void MdlTerminate ( void ) {
rt_FREE ( rtDW . jqrqq3twqe . RSimInfoPtr ) ; rt_FREE ( rtDW . j4uq2hdcjm .
RSimInfoPtr ) ; rt_FREE ( rtDW . lazvpzocdc . RSimInfoPtr ) ; { free ( rtDW .
mzxjwgc5lv . AS ) ; free ( rtDW . mzxjwgc5lv . BS ) ; free ( rtDW .
mzxjwgc5lv . CS ) ; free ( rtDW . mzxjwgc5lv . DS ) ; free ( rtDW .
mzxjwgc5lv . DX_COL ) ; free ( rtDW . mzxjwgc5lv . TMP2 ) ; free ( rtDW .
mzxjwgc5lv . BD_COL ) ; free ( rtDW . mzxjwgc5lv . TMP1 ) ; free ( rtDW .
mzxjwgc5lv . XTMP ) ; free ( rtDW . mzxjwgc5lv . G_STATE ) ; free ( rtDW .
mzxjwgc5lv . SWITCH_STATUS ) ; free ( rtDW . mzxjwgc5lv . SW_CHG ) ; free (
rtDW . mzxjwgc5lv . SWITCH_STATUS_INIT ) ; } } static void
mr_MPPTTestEnviroment_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) ; static void
mr_MPPTTestEnviroment_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_MPPTTestEnviroment_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ;
static void mr_MPPTTestEnviroment_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_MPPTTestEnviroment_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex
i , int j , uint_T bitVal ) ; static void
mr_MPPTTestEnviroment_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex
i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_MPPTTestEnviroment_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_MPPTTestEnviroment_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_MPPTTestEnviroment_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_MPPTTestEnviroment_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_MPPTTestEnviroment_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void
mr_MPPTTestEnviroment_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_MPPTTestEnviroment_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_MPPTTestEnviroment_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_MPPTTestEnviroment_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_MPPTTestEnviroment_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_MPPTTestEnviroment_GetDWork ( ) {
static const char_T * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" ,
"NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 ,
ssDWFieldNames ) ; mr_MPPTTestEnviroment_cacheDataAsMxArray ( ssDW , 0 , 0 ,
( const void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char_T *
rtdwDataFieldNames [ 7 ] = { "rtDW.exeralr4po" , "rtDW.g5ufooow0i" ,
"rtDW.h1nceqotqd" , "rtDW.cvaln4lwyx" , "rtDW.axcms0d2td" , "rtDW.a5z1oau2kb"
, "rtDW.esoqq5ahh2" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 ,
7 , rtdwDataFieldNames ) ; mr_MPPTTestEnviroment_cacheDataAsMxArray (
rtdwData , 0 , 0 , ( const void * ) & ( rtDW . exeralr4po ) , sizeof ( rtDW .
exeralr4po ) ) ; mr_MPPTTestEnviroment_cacheDataAsMxArray ( rtdwData , 0 , 1
, ( const void * ) & ( rtDW . g5ufooow0i ) , sizeof ( rtDW . g5ufooow0i ) ) ;
mr_MPPTTestEnviroment_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void *
) & ( rtDW . h1nceqotqd ) , sizeof ( rtDW . h1nceqotqd ) ) ;
mr_MPPTTestEnviroment_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void *
) & ( rtDW . cvaln4lwyx ) , sizeof ( rtDW . cvaln4lwyx ) ) ;
mr_MPPTTestEnviroment_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void *
) & ( rtDW . axcms0d2td ) , sizeof ( rtDW . axcms0d2td ) ) ;
mr_MPPTTestEnviroment_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void *
) & ( rtDW . a5z1oau2kb ) , sizeof ( rtDW . a5z1oau2kb ) ) ;
mr_MPPTTestEnviroment_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void *
) & ( rtDW . esoqq5ahh2 ) , sizeof ( rtDW . esoqq5ahh2 ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_MPPTTestEnviroment_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_MPPTTestEnviroment_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW ,
0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber (
ssDW , 0 , 1 ) ; mr_MPPTTestEnviroment_restoreDataFromMxArray ( ( void * ) &
( rtDW . exeralr4po ) , rtdwData , 0 , 0 , sizeof ( rtDW . exeralr4po ) ) ;
mr_MPPTTestEnviroment_restoreDataFromMxArray ( ( void * ) & ( rtDW .
g5ufooow0i ) , rtdwData , 0 , 1 , sizeof ( rtDW . g5ufooow0i ) ) ;
mr_MPPTTestEnviroment_restoreDataFromMxArray ( ( void * ) & ( rtDW .
h1nceqotqd ) , rtdwData , 0 , 2 , sizeof ( rtDW . h1nceqotqd ) ) ;
mr_MPPTTestEnviroment_restoreDataFromMxArray ( ( void * ) & ( rtDW .
cvaln4lwyx ) , rtdwData , 0 , 3 , sizeof ( rtDW . cvaln4lwyx ) ) ;
mr_MPPTTestEnviroment_restoreDataFromMxArray ( ( void * ) & ( rtDW .
axcms0d2td ) , rtdwData , 0 , 4 , sizeof ( rtDW . axcms0d2td ) ) ;
mr_MPPTTestEnviroment_restoreDataFromMxArray ( ( void * ) & ( rtDW .
a5z1oau2kb ) , rtdwData , 0 , 5 , sizeof ( rtDW . a5z1oau2kb ) ) ;
mr_MPPTTestEnviroment_restoreDataFromMxArray ( ( void * ) & ( rtDW .
esoqq5ahh2 ) , rtdwData , 0 , 6 , sizeof ( rtDW . esoqq5ahh2 ) ) ; } }
mxArray * mr_MPPTTestEnviroment_GetSimStateDisallowedBlocks ( ) { mxArray *
data = mxCreateCellMatrix ( 4 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static
const char_T * blockType [ 4 ] = { "S-Function" , "Scope" , "Scope" ,
"S-Function" , } ; static const char_T * blockPath [ 4 ] = {
"MPPTTestEnviroment/powergui/EquivalentModel1/State-Space" ,
"MPPTTestEnviroment/Scope2" , "MPPTTestEnviroment/Time Scope" ,
"MPPTTestEnviroment/powergui/EquivalentModel1/State-Space" , } ; static const
int reason [ 4 ] = { 0 , 0 , 0 , 2 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] <
4 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript (
data , 2 , subs ) ; mxSetCell ( data , offset , mxCreateString ( blockType [
subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2
, subs ) ; mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0
] ] ) ) ; subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs )
; mxSetCell ( data , offset , mxCreateDoubleScalar ( ( real_T ) reason [ subs
[ 0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0
) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 3 ) ;
ssSetNumBlocks ( rtS , 162 ) ; ssSetNumBlockIO ( rtS , 17 ) ;
ssSetNumBlockParams ( rtS , 1997 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 1.0E-5 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 160205490U ) ;
ssSetChecksumVal ( rtS , 1 , 299420185U ) ; ssSetChecksumVal ( rtS , 2 ,
1323767297U ) ; ssSetChecksumVal ( rtS , 3 , 761063030U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; executionInfo -> gblObjects_ . numToFiles = 0 ;
executionInfo -> gblObjects_ . numFrFiles = 0 ; executionInfo -> gblObjects_
. numFrWksBlocks = 3 ; executionInfo -> gblObjects_ . numModelInputs = 0 ;
executionInfo -> gblObjects_ . numRootInportBlks = 0 ; executionInfo ->
gblObjects_ . inportDataTypeIdx = NULL ; executionInfo -> gblObjects_ .
inportDims = NULL ; executionInfo -> gblObjects_ . inportComplex = NULL ;
executionInfo -> gblObjects_ . inportInterpoFlag = NULL ; executionInfo ->
gblObjects_ . inportContinuous = NULL ; ( void ) memset ( ( char_T * ) rtS ,
0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo , 0 ,
sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 25 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
MPPTTestEnviroment_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive
( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "MPPTTestEnviroment" ) ;
ssSetPath ( rtS , "MPPTTestEnviroment" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 300.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 4
} ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 4 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "DSTATE" , "DSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"MPPTTestEnviroment/PV Array/Diode Rsh/Unit Delay" ,
"MPPTTestEnviroment/powergui/EquivalentModel1/State-Space" } ; static const
char_T * rt_LoggedStateNames [ ] = { "DSTATE" , "DSTATE" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } }
; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtDW . exeralr4po ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) rtDW . g5ufooow0i ; } rtliSetLogT
( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS )
, "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "xFinal" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; static uint8_T zcAttributes [ 2 ] = { ( ZC_EVENT_ALL
) , ( ZC_EVENT_ALL ) } ; ssSetStepSize ( rtS , 1.0E-5 ) ; ssSetMinStepSize (
rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError (
rtS , 0 ) ; ssSetMaxStepSize ( rtS , 1.0E-5 ) ; ssSetSolverMaxOrder ( rtS , -
1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL )
) ; ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetSolverZcSignalAttrib ( rtS ,
zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 2 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 2 ) ; } ssSetChecksumVal ( rtS , 0 , 160205490U
) ; ssSetChecksumVal ( rtS , 1 , 299420185U ) ; ssSetChecksumVal ( rtS , 2 ,
1323767297U ) ; ssSetChecksumVal ( rtS , 3 , 761063030U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 9 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; systemRan [ 8 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_MPPTTestEnviroment_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_MPPTTestEnviroment_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_MPPTTestEnviroment_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } executionInfo -> simulationOptions_ . stateSaveName_ =
rtliGetLogX ( ssGetRTWLogInfo ( rtS ) ) ; executionInfo -> simulationOptions_
. finalStateName_ = rtliGetLogXFinal ( ssGetRTWLogInfo ( rtS ) ) ;
executionInfo -> simulationOptions_ . outputSaveName_ = rtliGetLogY (
ssGetRTWLogInfo ( rtS ) ) ; return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID3 ( tid ) ; }
