/*
 * vtx_uh60_Cas_fnc_setup
 *
 * starts up the caution and advisory system module
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];
if (!vtx_uh60m_enabled_cas) exitWith {false};
#define SET_GLOBAL_DEFAULT(VAR,DEFAULT) _vehicle setVariable [VAR, _vehicle getVariable [VAR, DEFAULT], true];
#define SET_DEFAULT(VAR,DEFAULT) _vehicle setVariable [VAR, _vehicle getVariable [VAR, DEFAULT]];
SET_GLOBAL_DEFAULT("vtx_cas_list",[])
SET_DEFAULT("vtx_cas_queue", 0)

vtx_uh60_cas_hitEH = _vehicle addEventHandler ["hit", vtx_uh60_cas_fnc_updateCautions];
vtx_uh60_cas_cautionsLog = [];
vtx_uh60_cas_cautionsUnacked = 0;

[_vehicle] call vtx_uh60_cas_fnc_updateCautionsList;
SET_DEFAULT("vtx_cas_rotorIgnored", false);

for [{ _i = 3 }, { _i < 39 }, { _i = _i + 1 }] do {
  [_vehicle, _i, 0] call vtx_uh60_mfd_fnc_setPylonValue;
};

true
