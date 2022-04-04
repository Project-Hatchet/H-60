/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_getInput

Description:
	Handles keyboard and HOTAS input for the simulation.

Parameters:
	_heli - The helicopter to get information from [Unit].

Returns:
	...

Examples:
	...

Author:
	BradMick
---------------------------------------------------------------------------- */
params ["_heli"];

private _collectiveVal = 0.0;

if (difficultyEnabledRTD) then {
	_collectiveVal = _heli animationSourcePhase "collectiveRTD";
} else {
	_collectiveVal = _heli animationSourcePhase "collective";
};

private _collectiveOut = 0.0;
if (vtx_uh60_sfmPlusKeyboardOnly) then {
	_collectiveVal = [_collectiveVal, 0.5, 1.0] call BIS_fnc_clamp;
	_collectiveOut = linearConversion[ 0.5, 1.0, _collectiveVal, 0.0, 2.0];
	private _V_mps            = abs vectorMagnitude [velocity _heli select 0, velocity _heli select 1];
	private _collectiveOutMod = linearConversion [0.00, 12.35, _V_mps, 0.780, 2.0, true];

	_collectiveOut = [_collectiveOut, 0.0, _collectiveOutMod] call BIS_fnc_clamp;

	systemChat format ["_collectiveVal = %1 - _collectiveOutMod = %2 - _collectiveOut = %3", _collectiveVal, _collectiveOutMod, _collectiveOut];
} else {
	_collectiveOut = linearConversion[-1.0, 1.0, _collectiveVal, 0.0, 1.0];
};

vtx_uh60_sfmplus_collectiveOutput = _collectiveOut

