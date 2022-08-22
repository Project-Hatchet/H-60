/*
 * vtx_uh60_mfd_fnc_perSecond
 *
 * handles occasional updates of data for MFDs
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];
if (!isNil "test_fnc_perSec") exitWith {_this call test_fnc_perSec};

[_vehicle, 9, str round ((vectorMagnitude wind) * 1.94384)] call vtx_uh60_mfd_fnc_setUserText;
private _stabAnim = _vehicle animationPhase "Stabilator_rotate";
private _stabAngle = ceil (80 - (_stabAnim * 1.1111111 + 13));
[_vehicle, 11, str (_stabAngle min 40 max 0)] call vtx_uh60_mfd_fnc_setUserText;

[_vehicle] call vtx_uh60_mfd_fnc_renderBFTUnits;
[_vehicle] call vtx_uh60_mfd_fnc_tac_getHook;
if (local _vehicle) then {
	[_vehicle] call vtx_uh60_mfd_fnc_handleDamage;
};