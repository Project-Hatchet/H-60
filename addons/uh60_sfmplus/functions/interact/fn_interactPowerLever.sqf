/* ----------------------------------------------------------------------------
Function: vtx_sfmplus_fnc_interactPowerLever

Description:
	Handles power lever animation and invokes engineReset when a power lever is
	taken to off.	

Parameters:
	_heli   - The helicopter to get information from [Unit].
	_engNum - The desired engine.
	_state  - The state of the power lever (OFF, IDLE, FLY).

Returns:
	...

Examples:
	...

Author:
	BradMick
---------------------------------------------------------------------------- */
params ["_heli", "_engNum", "_state"];

if(_heli animationphase "plt_rtrbrake" != 0) exitWith {};

private _engState = _heli getVariable "vtx_sfmplus_engState" select _engNum;
private _engPwrLeverAnimName = format["plt_eng%1_throttle", _engNum + 1]; 

if (_state == "OFF") then {
	_heli animateSource[_engPwrLeverAnimName, 0];
	[_heli, "vtx_sfmplus_engPowerLeverState", _engNum, _state, true] call vtx_sfmplus_fnc_setArrayVariable;

	if (_engState == "ON") then {
		[_heli, _engNum] call vtx_sfmplus_fnc_engineReset;
	};

	//HeliSim
	//[_heli, _engNum, 0.0] call bmk_fnc_engineSetThrottle;
};

if (_state == "IDLE") then {
	_heli animateSource[_engPwrLeverAnimName, 0.25];
	[_heli, "vtx_sfmplus_engPowerLeverState", _engNum, _state, true] call vtx_sfmplus_fnc_setArrayVariable;

	//HeliSim
	//[_heli, _engNum, 0.25] call bmk_fnc_engineSetThrottle;
};

if (_state == "FLY") then {
	//0.063 sets the power levers to fly in 16 seconds
	_heli animateSource[_engPwrLeverAnimName, 1, 0.25];
	[_heli, "vtx_sfmplus_engPowerLeverState", _engNum, _state, true] call vtx_sfmplus_fnc_setArrayVariable;

	//HeliSim
	//[_heli, _engNum, 1.0] call bmk_fnc_engineSetThrottle;
};
