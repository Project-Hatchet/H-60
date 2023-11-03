/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_standbyInst

Description:
	Simulates the Standby Insturment's 30 minuet battery

Parameters:
	_heli - The helicopter to get information from [Unit].
	_deltaTime - delta time passed from core

Returns:
	...

Examples:
	...

Author:
	Donov C.
---------------------------------------------------------------------------- */

params ["_heli", "_deltaTime"];

private _ACBusState          = _vehicle getVariable "vtx_uh60_acft_ACBusState";
private _stbyInstBatt        = _vehicle getVariable "vtx_uh60_acft_stbyInstBatt"; //1800 seconds
private _stbyInstSwitchState = _vehicle getVariable "vtx_uh60_acft_stbyInstSwitchState";

if (_ACBusState != "ON" && _stbyInstSwitchState == "ON") then {
	if (_stbyInstBatt >= 0) then {
		_stbyInstBatt = _stbyInstBatt - _deltaTime;
		_vehicle setVariable ["vtx_uh60_acft_stbyInstBatt", _stbyInstBatt, true];
	};
};
if (_ACBusState == "ON") then {
	if (_stbyInstBatt < 1800) then {
		_stbyInstBatt = _stbyInstBatt + _deltaTime;
		_vehicle setVariable ["vtx_uh60_acft_stbyInstBatt", _stbyInstBatt, true];
	};
}; 

//systemChat format ["_stbyInstBatt: %1", _stbyInstBatt];