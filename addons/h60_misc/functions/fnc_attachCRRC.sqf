#include "..\script_component.hpp"
/*
 * hct_h60_misc_fnc_attachCRRC
 */
params ["_boat"];

private _helicopter = (nearestObjects [_boat, [QBASE_CLASS], 10]) param [0, objNull]; // was _target: only defined in the ACE caller
if (isNull _helicopter) exitWith {}; // flew off between the menu and the click

private _attachedBoat = _helicopter getVariable ["hct_crrc_attached", nil];
if (!isNil "_attachedBoat") exitWith {
    hint (localize "STR_hct_h60_misc_CRRCAlreadyAttached");
};


if (crew _boat isNotEqualTo []) exitWith {hint (localize "STR_hct_h60_misc_BoatIsNotEmpty")};
_boat lock true;
_boat attachTo [_helicopter, [0,1.5,-0.85]];
_boat enableRopeAttach false;
_helicopter setVariable ["hct_crrc_attached", _boat, true];
