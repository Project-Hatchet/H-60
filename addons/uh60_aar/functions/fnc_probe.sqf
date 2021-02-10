/*
 * vtx_uh60_aar_fnc_probe
 *
 * handles probe extending and retracting, called from FMS interaction
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

private _state = _vehicle animationPhase "Fuelprobe_Extend";
if (_state < 0.1) exitWith {
    _vehicle animateSource ["Fuelprobe_Extend",1];
};
if (_state > 0.9) exitWith {
    _vehicle animateSource ["Fuelprobe_Extend",0];
};
