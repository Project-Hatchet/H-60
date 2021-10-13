/*
 * vtx_uh60_misc_fnc_attachCRRC
 */
params ["_boat"];

private _helicopters = nearestObjects [_target, ["vtx_H60_base"], 10];
private _helicopter = _helicopters # 0;

private _attachedBoat = _helicopter getVariable ["vtx_crrc_attached", nil];
if (!isNil "_attachedBoat") exitWith {
    hint "Helicopter already has a CRRC attached";
};


if (count (crew _boat) > 0) exitWith {hint "Boat is not empty"};
_boat lock true;
_boat attachTo [_helicopter, [0,1.5,-0.85]];
_boat enableRopeAttach false;
_helicopter setVariable ["vtx_crrc_attached", _boat, true];
