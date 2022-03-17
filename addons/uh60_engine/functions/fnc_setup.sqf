/*
 * vtx_uh60_engine_fnc_setup
 *
 * starts up the engine module, managing the engine power and startup procedure
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];
if (!vtx_uh60m_enabled_engine) exitWith {false};

vtx_uh60_engine_engineEH = _vehicle addEventHandler ["engine", vtx_uh60_engine_fnc_engineEH];
vtx_uh60_engine_lastFuelLevel = fuel _vehicle;
vtx_uh60_engine_lastAltitude = ((getPosASL _vehicle) # 2);
#define SET_GLOBAL_DEFAULT(VAR,DEFAULT) _vehicle setVariable [VAR, _vehicle getVariable [VAR, DEFAULT], true];
SET_GLOBAL_DEFAULT("ENG1_PWR", 0)
SET_GLOBAL_DEFAULT("ENG1_PWR", 0)
SET_GLOBAL_DEFAULT("ENG_START1", false)
SET_GLOBAL_DEFAULT("ENG_START2", false)
SET_GLOBAL_DEFAULT("BATT1_ENABLED", false)
SET_GLOBAL_DEFAULT("BATT2_ENABLED", false)
SET_GLOBAL_DEFAULT("BATT1_POWER", 100)
SET_GLOBAL_DEFAULT("BATT2_POWER", 100)
SET_GLOBAL_DEFAULT("POWER_DRAIN_RATE", 0.11)
SET_GLOBAL_DEFAULT("APU_POWER", false)
//SET_GLOBAL_DEFAULT("ESIS_COUNTER", 70)
//_vehicle setUserMFDValue [49, 70];

_vehicle enableAutoTrimRTD true;

//Let EICAS know parking brake is on & double check brakeRTD is on
if ((_vehicle animationPhase "handle_wheelbrake") == 1) then {
    [_vehicle, true, "ON"] call vtx_uh60_engine_fnc_wheelBrakes;
} else {
    [_vehicle, true, "OFF"] call vtx_uh60_engine_fnc_wheelBrakes;
};
//Monitor parking brake value
player addEventHandler ["SelectedRotorLibActionPerformed", {
    params ["_caller", "_target", "_enumNumber", "_actionId"];
    if    (!local _caller || !local _target) exitWith {};
    private _desiredState = if (_enumNumber == 4) then [{1},{0}];
    _target animateSource ["Handle_wheelbrake", _desiredState, true];
    [_target, (_enumNumber == 4)] call vtx_uh60_engine_fnc_wheelBrakes;
}];

//New aircraft module
//--Master ignition key (mik)
_vehicle setVariable ["vtx_uh60_acft_mikSwitchState",      "OFF"];
//--Standby instrument switch
_vehicle setVariable ["vtx_uh60_acft_stbyInstSwitchState", "OFF"];
//--Battery
_vehicle setVariable ["vtx_uh60_acft_batt1SwitchState",    "OFF"];
_vehicle setVariable ["vtx_uh60_acft_batt2SwitchState",    "OFF"];
//--APU
_vehicle setVariable ["vtx_uh60_acft_apuStartDelay_sec",   5.0  ];
_vehicle setVariable ["vtx_uh60_acft_apuRPM_pct",          0.0  ];
_vehicle setVariable ["vtx_uh60_acft_apuPwrSwitchState",   "OFF"];
_vehicle setVariable ["vtx_uh60_acft_apuFuelSwitchState",  "OFF"];
_vehicle setVariable ["vtx_uh60_acft_apuState",            "OFF"];
//--Generators
//----APU
_vehicle setVariable ["vtx_uh60_acft_apuGenSwitchState",   "OFF"];
_vehicle setVariable ["vtx_uh60_acft_apuGenState",         "OFF"];
//----Eng 1
_vehicle setVariable ["vtx_uh60_acft_eng1StarterState",    "OFF"];
_vehicle setVariable ["vtx_uh60_acft_eng1GenSwitchState",  "OFF"];
_vehicle setVariable ["vtx_uh60_acft_eng1GenState",        "OFF"];
//----Eng 2
_vehicle setVariable ["vtx_uh60_acft_eng2StarterState",    "OFF"];
_vehicle setVariable ["vtx_uh60_acft_eng2GenSwitchState",  "OFF"];
_vehicle setVariable ["vtx_uh60_acft_eng2GenState",        "OFF"];
//--Electical Bus
_vehicle setVariable ["vtx_uh60_acft_battBusState",        "OFF"];
_vehicle setVariable ["vtx_uh60_acft_ACBusState",          "OFF"];
_vehicle setVariable ["vtx_uh60_acft_DCBusState",          "OFF"];
//--Air source switch
_vehicle setVariable ["vtx_uh60_acft_airsrceSwitchState",  "OFF"];   //ENG, OFF, APU
//Engines
//--Fuel system levers
_vehicle setVariable ["vtx_uh60_acft_eng1FuelSysLeverState", "OFF"];
_vehicle setVariable ["vtx_uh60_acft_eng2FuelSysLeverState", "OFF"];
//--Power control levers
_vehicle setVariable ["vtx_uh60_acft_eng1PwrCtrlLeverState", "OFF"];
_vehicle setVariable ["vtx_uh60_acft_eng2PwrCtrlLeverState", "OFF"];
//--RotorLib
_vehicle setVariable ["vtx_uh60_acft_rtdDesiredRPM",          20900];
_vehicle setVariable ["vtx_uh60_acft_rtd100PctTqVal",           481]; //Nm (355ft-lbs)


true
