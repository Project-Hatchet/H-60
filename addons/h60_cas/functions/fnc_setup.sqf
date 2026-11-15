#include "script_component.hpp"
/*
 * hct_h60_Cas_fnc_setup
 *
 * starts up the caution and advisory system module
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];
if (!hct_h60_enabled_cas) exitWith {false};
#define SET_GLOBAL_DEFAULT(VAR,DEFAULT) _vehicle setVariable [VAR, _vehicle getVariable [VAR, DEFAULT], true];
#define SET_DEFAULT(VAR,DEFAULT) _vehicle setVariable [VAR, _vehicle getVariable [VAR, DEFAULT]];
// Local only: every client keeps its own list (registerCautionAdvisory never
// broadcasts). This used to broadcast the list - code conditions included - on
// every seat entry, overwriting the other crew's lists with this client's.
SET_DEFAULT("hct_cas_list",[])
SET_DEFAULT("hct_cas_queue", 0)

// one Hit handler per vehicle: replace any left by a setup without a shutdown
private _oldEH = _vehicle getVariable ["hct_h60_cas_hitEH", -1];
if (_oldEH != -1) then { _vehicle removeEventHandler ["Hit", _oldEH]; };
_vehicle setVariable ["hct_h60_cas_hitEH", _vehicle addEventHandler ["Hit", hct_h60_cas_fnc_updateCautions]];
hct_h60_cas_cautionsLog = [];
hct_h60_cas_cautionsUnacked = 0;
hct_h60_cas_firstAdvisory = 0;

[_vehicle] call hct_h60_cas_fnc_updateCautionsList;
SET_DEFAULT("hct_cas_rotorIgnored", false);

for "_i" from USERMFDV_CAS to (USERMFDV_HELLFIRE_BOX - 1) do {
  _vehicle setUserMFDValue [_i, 0];
};

true
