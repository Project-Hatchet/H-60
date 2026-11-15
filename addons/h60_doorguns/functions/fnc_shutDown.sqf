/*
 * hct_h60_doorguns_fnc_shutDown
 *
 * Hatchet module hook: removes this vehicle's door-gun Fired handler.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];

private _firedEH = _vehicle getVariable ["hct_h60_doorguns_firedEH", -1];
if (_firedEH != -1) then {
    _vehicle removeEventHandler ["Fired", _firedEH];
    _vehicle setVariable ["hct_h60_doorguns_firedEH", -1];
};
