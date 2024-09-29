/*
 * vtx_uh60_acre_fnc_cycleRadioChannel
 *
 * handles cycling radio channel
 *
 * 
 */
params ["_vehicle","_index","_cycle"];

private _newChannel = nil;

_racks = [_vehicle] call acre_sys_rack_fnc_getVehicleRacks;
_radio = [_racks # _index] call acre_sys_rack_fnc_getMountedRadio;  
_oldChannel = [_radio] call acre_api_fnc_getRadioChannel;

if (_cycle == 1) then {
	if (_oldChannel == 99) exitWith {_newChannel = 1;};
	_newChannel = _oldChannel + 1;
} else {
	if (_oldChannel == 1) exitWith {_newChannel = 99;};
	_newChannel = _oldChannel -1;
};

[_radio, _newChannel] call acre_api_fnc_setRadioChannel;
true