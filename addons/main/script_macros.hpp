#include "\z\ace\addons\main\script_macros.hpp"

// testing, update fncs on the fly
//#undef PREP
//#define PREP(var1) TRIPLES(ADDON,fnc,var1) = { call compile preProcessFileLineNumbers '\MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT_F\functions\DOUBLES(fnc,var1).sqf' }

#define ANIMSRC(name,src,per,init) \
class name { \
  source=QUOTE(src); \
  animPeriod=per; \
  initPhase=init; \
}

#define ANIM_INIT(name,init) class name : name {initPhase = init;}

#define POS_MOVE_CABIN_COCKPIT {0.023875,4.2461,-0.577079}
#define IS_NOT_ZEUS if !(isNull curatorCamera) exitWith {}
#define IS_IN_H60 IS_NOT_ZEUS; \
  private _unit = call CBA_fnc_currentUnit; \
  private _vehicle = vehicle _unit; \
  if !(_vehicle isKindOf "vtx_H60_base") exitWith {}

#define IS_EITHER_PILOT IS_IN_H60; \
if (_unit isNotEqualTo (driver _vehicle) && {(_vehicle unitTurret _unit) isNotEqualTo [0]}) exitWith {}

// User MFD Values
#define USERMFDV_FUELTANK 50  // FUEL TANK STATUS
#define USERMFDV_CAS 53 // CAS OVERLAY Caution and Advisory System
#define USERMFDV_TAC_CENTER 54
#define USERMFDV_TAC_ALIGN 55
#define USERMFDV_TAC_ZOOM 56
#define USERMFDV_TAC_MOVE 57
#define USERMFDV_LHMD_R 58 //8)   //Left HMD Color R
#define USERMFDV_LHMD_G 59 //9)   //Left HMD Color G
#define USERMFDV_LHMD_B 60 //10)  //Left HMD Color B
#define USERMFDV_LHMD_A 61 //11)  //Left HMD Brighhtness
#define USERMFDV_RHMD_R 62 //12)  //Right HMD Color R
#define USERMFDV_RHMD_G 63 //13)  //Right HMD Color G
#define USERMFDV_RHMD_B 64 //14)  //Right HMD Color B
#define USERMFDV_RHMD_A 65 //15)  //Right HMD Brightness
#define USERMFDV_L00 66 // Overlay	 GEN 1 FAIL
#define USERMFDV_L01 67 // Overlay	 HYD PUMP 1 FAIL
#define USERMFDV_L02 68 // Overlay
#define USERMFDV_L10 69 // Overlay	 CHIP ENG 1
#define USERMFDV_L11 70 // Overlay	 CHIP MAIN MDL SUMP
#define USERMFDV_L12 71 // Overlay	 MAIN XMSN PRES
#define USERMFDV_L13 72 // Overlay	 HULL INTEGRITY CRIT
#define USERMFDV_L14 73 // Overlay	 LEFT STN HANG
#define USERMFDV_L15 74 // Overlay	 ENG 1 STARTER ON
#define USERMFDV_R00 75 // Overlay	 GEN 2 FAIL
#define USERMFDV_R01 76 // Overlay	 HYD PUMP 2
#define USERMFDV_R02 77 // Overlay	 EGI FAIL
#define USERMFDV_R10 78 // Overlay	 CHIP ENG 2
#define USERMFDV_R11 79 // Overlay	 T/R SERVO 1 FAIL
#define USERMFDV_R12 80 // Overlay	 T/R QUAD FAIL
#define USERMFDV_R13 81 // Overlay	 APU FAIL
#define USERMFDV_R14 82 // Overlay	 RIGHT STN HANG
#define USERMFDV_R15 83 // Overlay	 ENG 2 STARTER ON
#define USERMFDV_R20 84 // Overlay	 STBY INST NOT ARMD
#define USERMFDV_R21 85 // Overlay	 STAB FAIL
#define USERMFDV_R22 86 // Overlay	 CMWS FAIL
#define USERMFDV_R23 87 // Overlay	 FLIR FAIL
#define USERMFDV_R24 88 // Overlay	 MFD BUS ERR
#define USERMFDV_R25 89 // Overlay
#define USERMFDV_HELLFIRE_BOX 90 // HF engagement box
#define USERMFDV_HELLFIRE_TRA 91 // HF Trajectory
#define USERMFDV_PRI_CH 92 // PRI CHAN
#define USERMFDV_ALT_CH 93 // ALT CHAN
#define USERMFDV_LST 94 // LST
#define USERMFDV_LRFD 95 // LRFD
#define USERMFDV_ADVISORIES 96 // ADVISORIES
#define USERMFDV_LST_MODE 97 // LST MODE

#define USERNNN(index) user##index
#define USER_EQ(index,val) QUOTE(USERNNN(index) == val)
#define USER_LT(index,val) QUOTE(USERNNN(index) < val)
#define USER_GT(index,val) QUOTE(USERNNN(index) > val)
#define USER_BT(index,val1,val2) QUOTE((USERNNN(index) > val1) * (USERNNN(index) < val2))
#define USERVAL_EQ(index,val) QUOTE(((getUserMFDValue _this) select index) == val)
#define USERVAL_GT(index,val) QUOTE(((getUserMFDValue _this) select index) > val)
#define USERVAL_LT(index,val) QUOTE(((getUserMFDValue _this) select index) < val)
#define USERVAL_BT(index,val1,val2) QUOTE((((getUserMFDValue _this) select index) > val1) * (((getUserMFDValue _this) select INDEX) < val2))

// hiddenSelections[] = {
#define HIDDENSELECTION_EM_OVERHEAD 1 // emmisive_overhead,
#define HIDDENSELECTION_EM_DASH 2 // emmisive_frontDash,
#define HIDDENSELECTION_EM_PEDESTAL 3 // emmisive_pedestal,
#define HIDDENSELECTION_EM_RALT 4 // emmisive_ralt,
#define HIDDENSELECTION_EM_ALTP 5 // emmisive_altp,
#define HIDDENSELECTION_EM_ALT 6 // emmisive_alt,
#define HIDDENSELECTION_EM_IAS 7 // emmisive_ias,
#define HIDDENSELECTION_EM_HDG 8 // emmisive_hdg,
#define HIDDENSELECTION_MAP_MFD1 9 // MAP_MFD1,
#define HIDDENSELECTION_MAP_MFD2 10 // MAP_MFD2,
#define HIDDENSELECTION_MAP_MFD3 11 // MAP_MFD3,
#define HIDDENSELECTION_MAP_MFD4 12 // MAP_MFD4,
#define HIDDENSELECTION_MAP_OVERLAY1 13 // MAP_OVERLAY1,
#define HIDDENSELECTION_MAP_OVERLAY2 14 // MAP_OVERLAY2,
#define HIDDENSELECTION_MAP_OVERLAY3 15 // MAP_OVERLAY3,
#define HIDDENSELECTION_MAP_OVERLAY4 16 // MAP_OVERLAY4,
#define HIDDENSELECTION_HULL 17 // Exterrior_Hull,
#define HIDDENSELECTION_MISC 18 // Exterrior_Misc,
#define HIDDENSELECTION_TAIL 19 // Exterrior_Tail,
#define HIDDENSELECTION_MARKINGS 20 // markings,
#define HIDDENSELECTION_NUMBER_L1 21 // left_num_1,
#define HIDDENSELECTION_NUMBER_L2 22 // left_num_2,
#define HIDDENSELECTION_NUMBER_R1 23 // right_num_1,
#define HIDDENSELECTION_NUMBER_R2 24 // right_num_2,
#define HIDDENSELECTION_FUELPROBE 25 // Fuel_Probe,
#define HIDDENSELECTION_MLASS 26 // Mlass,
#define HIDDENSELECTION_EM_GOARND 27 // emmisive_goarnd,
#define HIDDENSELECTION_EM_HOVER 28 // emmisive_hvr,
#define HIDDENSELECTION_EM_FMS 29 // emmisive_fms,
#define HIDDENSELECTION_EM_CPLD 30 // emmisive_cpld,
#define HIDDENSELECTION_EM_VS 31 // emmisive_vs


// #ifdef PREP
//     #undef PREP
//     #define PREP(fncName) DFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
// #else
//     #define PREP(fncName) DFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
// #endif
