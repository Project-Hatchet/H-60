#include "\z\ace\addons\main\script_macros.hpp"

#define ANIMSRC(name,src,per,init) \
class name { \
  source=QUOTE(src); \
  animPeriod=per; \
  initPhase=init; \
}

#define ANIM_INIT(name,init) class name : name {initPhase = init;}

#define POS_MOVE_CABIN_COCKPIT {0.023875,4.2461,-0.577079}
#define IS_NOT_ZEUS if !(isNull curatorCamera) exitWith {false}
#define IS_IN_H60 IS_NOT_ZEUS; \
  private _unit = call CBA_fnc_currentUnit; \
  private _vehicle = vehicle _unit; \
  if !(_vehicle isKindOf "vtx_H60_base") exitWith {false}

#define IS_EITHER_PILOT IS_IN_H60; \
if (_unit isNotEqualTo (driver _vehicle) && {(_vehicle unitTurret _unit) isNotEqualTo [0]}) exitWith {false}

// User MFD Values
#define USERMFDV_WAYPOINTDIRECTION 0 // Waypoint Direction DTK
#define USERMFDV_WAYPOINTDISTANCE 1 // Waypoint Distance 2D
#define USERMFDV_WAYPOINT1X 2 // Waypoint 1 X
#define USERMFDV_WAYPOINT1Y 3 // Waypoint 1 Y
#define USERMFDV_WAYPOINT2X 4 // Waypoint 2 X
#define USERMFDV_WAYPOINT2Y 5 // Waypoint 2 Y
#define USERMFDV_WAYPOINT3X 6 // Waypoint 3 X
#define USERMFDV_WAYPOINT3Y 7 // Waypoint 3 Y
#define USERMFDV_WAYPOINT4X 8 // Waypoint 4 X
#define USERMFDV_WAYPOINT4Y 9 // Waypoint 4 Y
#define USERMFDV_TACFLIRX 10 // TAC FLIR x UNUSED
#define USERMFDV_TACFLIRY 11 // TAC FLIR Y UNUSED
#define USERMFDV_FDRALT 12 // Flight Director Radar Altitude
#define USERMFDV_FDALTP 13 // Flight Director Altitude Pressure
#define USERMFDV_FDALT 14 // Flight Director Altitude
#define USERMFDV_ANVISHUDMODE 15 // ANVIS HUD Mode
#define USERMFDV_JVMFTYPE 16 // JVMF Type
#define USERMFDV_ROTORRPM 17 // Rotor RPM UNUSED
#define USERMFDV_TACCENTERMODE 18 // TAC Center Mode
#define USERMFDV_ENG1NG 19 // Engine 1 NG
#define USERMFDV_ENG1NP 20 // Engine 1 NP
#define USERMFDV_ENG1TGT 21 // Engine 1 TGT
#define USERMFDV_ENG1TQ 22 // Engine 1 TQ
#define USERMFDV_MFD1PAGE 23 // MFD 1 Page Index
#define USERMFDV_MFD2PAGE 24 // MFD 2 Page Index
#define USERMFDV_MFD3PAGE 25 // MFD 3 Page Index
#define USERMFDV_MFD4PAGE 26 // MFD 4 Page Index
#define USERMFDV_TACSHIPX 27 // TAC Ship X
#define USERMFDV_TACSHIPY 28 // TAC Ship Y
#define USERMFDV_TACCURSORX 29 // TAC Cursor X
#define USERMFDV_TACCURSORY 30 // TAC Cursor Y
#define USERMFDV_FMS1PAGE 31 // FMS 1 Page Index
#define USERMFDV_FMS2PAGE 32 // FMS 2 Page Index
#define USERMFDV_WAYPOINT5X 33 // Waypoint 5 X
#define USERMFDV_WAYPOINT5Y 34 // Waypoint 5 Y
#define USERMFDV_WAYPOINT6X 35 // Waypoint 6 X
#define USERMFDV_WAYPOINT6Y 36 // Waypoint 6 Y
#define USERMFDV_VELOCITYX 37 // Velocity X
#define USERMFDV_VELOCITYY 38 // Velocity Y
#define USERMFDV_MFDSOI 39 // MFD SOI State
#define USERMFDV_MFDTACZOOM 40 // MFD TAC Zoom
#define USERMFDV_FDIAS 41 // Flight Director Indicated Airspeed
#define USERMFDV_FDHDG 42 // Flight Director Heading
#define USERMFDV_JVMF1 43 // JVMF 1 UNUSED
#define USERMFDV_JVMF2 44 // JVMF 2 UNUSED
#define USERMFDV_ENG2NG 45 // Engine 2 NG
#define USERMFDV_ENG2NP 46 // Engine 2 NP
#define USERMFDV_ENG2TGT 47 // Engine 2 TGT
#define USERMFDV_ENG2TQ 48 // Engine 2 TQ
#define USERMFDV_ESIS 49  // ESIS countdown
#define USERMFDV_FUELTANK 50  // FUEL TANK STATUS
#define USERMFDV_CAS 53 // CAS OVERLAY Caution and Advisory System
#define USERMFDV_TAC_CENTER 54
#define USERMFDV_TAC_ALIGN 55
#define USERMFDV_TAC_ZOOM 56
#define USERMFDV_TAC_MOVE 57
#define USERMFDV_HMD_R 58 //8)   //HMD Color R
#define USERMFDV_HMD_G 59 //9)   //HMD Color G
#define USERMFDV_HMD_B 60 //10)  //HMD Color B
#define USERMFDV_HMD_A 61 //11)  //HMD Brighhtness
#define USERMFDV_62 62 //12
#define USERMFDV_63 63 //13
#define USERMFDV_64 64 //14
#define USERMFDV_65 65 //15
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
#define HIDDENSELECTION_EM_OVERHEAD 0 // emmisive_overhead,
#define HIDDENSELECTION_EM_DASH 1 // emmisive_frontDash,
#define HIDDENSELECTION_EM_PEDESTAL 2 // emmisive_pedestal,
#define HIDDENSELECTION_EM_RALT 3 // emmisive_ralt,
#define HIDDENSELECTION_EM_ALTP 4 // emmisive_altp,
#define HIDDENSELECTION_EM_ALT 5 // emmisive_alt,
#define HIDDENSELECTION_EM_IAS 6 // emmisive_ias,
#define HIDDENSELECTION_EM_HDG 7 // emmisive_hdg,
#define HIDDENSELECTION_MAP_MFD1 8 // MAP_MFD1,
#define HIDDENSELECTION_MAP_MFD2 9 // MAP_MFD2,
#define HIDDENSELECTION_MAP_MFD3 10 // MAP_MFD3,
#define HIDDENSELECTION_MAP_MFD4 11 // MAP_MFD4,
#define HIDDENSELECTION_MAP_OVERLAY1 12 // MAP_OVERLAY1,
#define HIDDENSELECTION_MAP_OVERLAY2 13 // MAP_OVERLAY2,
#define HIDDENSELECTION_MAP_OVERLAY3 14 // MAP_OVERLAY3,
#define HIDDENSELECTION_MAP_OVERLAY4 15 // MAP_OVERLAY4,
#define HIDDENSELECTION_HULL 16 // Exterrior_Hull,
#define HIDDENSELECTION_MISC 17 // Exterrior_Misc,
#define HIDDENSELECTION_TAIL 18 // Exterrior_Tail,
#define HIDDENSELECTION_MARKINGS 19 // markings,
#define HIDDENSELECTION_NUMBER_L1 20 // left_num_1,
#define HIDDENSELECTION_NUMBER_L2 21 // left_num_2,
#define HIDDENSELECTION_NUMBER_R1 22 // right_num_1,
#define HIDDENSELECTION_NUMBER_R2 23 // right_num_2,
#define HIDDENSELECTION_FUELPROBE 24 // Fuel_Probe,
#define HIDDENSELECTION_MLASS 25 // MLASS,
#define HIDDENSELECTION_LASS 26 // LASS,
#define HIDDENSELECTION_FULL60M 27 // Full60M,
#define HIDDENSELECTION_EM_GOARND 28 // emmisive_goarnd,
#define HIDDENSELECTION_EM_HOVER 29 // emmisive_hvr,
#define HIDDENSELECTION_EM_FMS 30 // emmisive_fms,
#define HIDDENSELECTION_EM_CPLD 31 // emmisive_cpld,
#define HIDDENSELECTION_EM_VS 32 // emmisive_vs

#define HIDDENSELECTIONS "emmisive_overhead", \
          "emmisive_frontDash", \
          "emmisive_pedestal", \
          "emmisive_ralt", \
          "emmisive_altp", \
          "emmisive_alt", \
          "emmisive_ias", \
          "emmisive_hdg", \
          "MAP_MFD1", \
          "MAP_MFD2", \
          "MAP_MFD3", \
          "MAP_MFD4", \
          "MAP_OVERLAY1", \
          "MAP_OVERLAY2", \
          "MAP_OVERLAY3", \
          "MAP_OVERLAY4", \
          "Exterrior_Hull", \
          "Exterrior_Misc", \
          "Exterrior_Tail", \
          "markings", \
          "left_num_1", \
          "left_num_2", \
          "right_num_1", \
          "right_num_2", \
          "Fuel_Probe", \
          "hs_mlass_co", \
          "hs_lass_co", \
          "hs_full60m_co", \
          "emmisive_goarnd", \
          "emmisive_hvr", \
          "emmisive_fms", \
          "emmisive_cpld", \
          "emmisive_vs"

// #ifdef PREP
//     #undef PREP
//     #define PREP(fncName) DFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
// #else
//     #define PREP(fncName) DFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
// #endif
