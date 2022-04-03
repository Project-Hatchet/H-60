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
	_collectiveOut = linearConversion[ 0.5, 1.0, _collectiveVal, 0.0, 2.0];

	private _V_mps            = abs vectorMagnitude [velocity _heli select 0, velocity _heli select 1];
	private _collectiveOutMod = linearConversion [0.00, 12.35, _V_mps, 0.780, 0.926, true];

	_collectiveOut = [_collectiveOut, 0.0, _collectiveOutMod] call BIS_fnc_clamp;
} else {
	_collectiveOut = linearConversion[-1.0, 1.0, _collectiveVal, 0.0, 1.0];
};

vtx_uh60_sfmplus_collectiveOutput = _collectiveOut

