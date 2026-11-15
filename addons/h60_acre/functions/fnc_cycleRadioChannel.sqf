/*
 * hct_h60_acre_fnc_cycleRadioChannel
 *
 * handles cycling radio channel
 *
 *
 */
params ["_vehicle","_index","_cycle"];

private _newChannel = nil;

private _radio = [_vehicle, _index] call hct_h60_acre_fnc_getRadio;
if (_radio isEqualTo "") exitWith {false}; // rack or radio not there yet
private _oldChannel = [_radio] call acre_api_fnc_getRadioChannel;

if (_cycle == 1) then {
	if (_oldChannel == 99) exitWith {_newChannel = 1;};
	_newChannel = _oldChannel + 1;
} else {
	if (_oldChannel == 1) exitWith {_newChannel = 99;};
	_newChannel = _oldChannel -1;
};

[_radio, _newChannel] call acre_api_fnc_setRadioChannel;
[_vehicle] call hct_h60_acre_fnc_notifyOtherSeat;
true
