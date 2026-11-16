/*
 * hct_h60_acre_fnc_initComms
 *
 * initializes acre comms systems once BUS is on
 *
 * 
 */
params ["_vehicle"];

private _monitorPos = [_vehicle, acre_player, 0, "monitorKnob"] call acre_sys_intercom_fnc_getStationConfiguration;

[_vehicle, acre_player, 0, "workKnob", 0] call acre_sys_intercom_fnc_setStationConfiguration;
if (_monitorPos != 7) then {
    [_vehicle, acre_player, 0, "monitorKnob", 7] call acre_sys_intercom_fnc_setStationConfiguration;
};


for "_i" from 1 to 4 do {
    private _value = (_vehicle animationSourcePhase format ["COMM%1_ROT", _i]) * (1/0.75);
    private _radio = [_vehicle, (_i - 1)] call hct_h60_acre_fnc_getRadio;
    if (_radio isEqualTo "") then {continue}; // rack or radio not there yet
    [_radio, _value] call acre_sys_radio_fnc_setRadioVolume;
    [_radio, _i] call acre_api_fnc_setRadioChannel;
    private _wiredRacks = [_vehicle, acre_player, 0, "wiredRacks"] call acre_sys_intercom_fnc_getStationConfiguration;
    (_wiredRacks param [_i - 1, []]) set [1, 1];
};
