#include "..\script_component.hpp"
/*
 * hct_h60_misc_fnc_attachCRRC
 */
params ["_boat"];

private _helicopters = nearestObjects [_target, [QBASE_CLASS], 10];
private _helicopter = _helicopters # 0;

private _attachedBoat = _helicopter getVariable ["hct_crrc_attached", nil];
if (!isNil "_attachedBoat") exitWith {
    hint (localize "STR_hct_h60_misc_CRRCAlreadyAttached");
};


if (count (crew _boat) > 0) exitWith {hint (localize "STR_hct_h60_misc_BoatIsNotEmpty")};
_boat lock true;
_boat attachTo [_helicopter, [0,1.5,-0.85]];
_boat enableRopeAttach false;
_helicopter setVariable ["hct_crrc_attached", _boat, true];
