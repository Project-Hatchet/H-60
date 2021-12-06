/*
 * vtx_uh60_acre_fnc_setRadioVolume
 *
 * sets up the acre module
 *
 * params (array)[(SCALAR) radio index, (object) vehicle, (SCALAR) volume(0 to 0.75)]
 */

params ["_index", "_vehicle", "_value"];

_value = _value * (1/0.75); // changes it to a 0-1 range

private _racks = [_vehicle] call acre_sys_rack_fnc_getVehicleRacks;
private _radio = [_racks # _index] call acre_sys_rack_fnc_getMountedRadio;
private _activeRadios = [] call acre_api_fnc_getCurrentRadioList;

if(vtx_uh60_ui_showDebugMessages) then {
    systemChat str [
        [_radio, player] call acre_sys_rack_fnc_isRadioAccessible,
        [_radio, player] call acre_sys_rack_fnc_isRadioHearable
    ];
};

[_radio, _value] call acre_sys_radio_fnc_setRadioVolume;
if (_value == 0 && (_radio in _activeRadios)) then {
    [_vehicle, player, _radio] call acre_sys_rack_fnc_stopUsingMountedRadio;
} else {
    if (_vol > 0 && !(_radio in _activeRadios)) then {
        [_vehicle, player, _radio] call acre_sys_rack_fnc_startUsingMountedRadio;
    };
};
