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

true
