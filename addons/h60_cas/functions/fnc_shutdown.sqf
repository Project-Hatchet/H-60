/*
 * hct_h60_cas_fnc_shutdown
 *
 * Hatchet module hook: removes this vehicle's caution-system Hit handler.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];

private _hitEH = _vehicle getVariable ["hct_h60_cas_hitEH", -1];
if (_hitEH != -1) then {
    _vehicle removeEventHandler ["Hit", _hitEH];
    _vehicle setVariable ["hct_h60_cas_hitEH", -1];
};
