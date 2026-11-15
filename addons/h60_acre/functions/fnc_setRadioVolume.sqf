/*
 * hct_h60_acre_fnc_setRadioVolume
 *
 * sets up the acre module
 *
 * params (array)[(SCALAR) radio index, (object) vehicle, (SCALAR) volume(0 to 0.75)]
 */

params ["_index", "_vehicle", "_value"];

_value = _value * (1/0.75); // changes it to a 0-1 range
private ["_activeRadios", "_wiredRacks", "_selectedRack", "_workPos"];

private _radio = [_vehicle, _index] call hct_h60_acre_fnc_getRadio;
if (_radio isEqualTo "") exitWith {}; // rack or radio not there yet
_activeRadios = [] call acre_api_fnc_getCurrentRadioList;
_wiredRacks = [_vehicle, acre_player, 0, "wiredRacks"] call acre_sys_intercom_fnc_getStationConfiguration;
_selectedRack = _wiredRacks param [_index, []];
if (_selectedRack isEqualTo []) exitWith {};
_workPos = [_vehicle, acre_player, 0, "workKnob"] call acre_sys_intercom_fnc_getStationConfiguration;


if(hct_h60_devMode) then {
    systemChat str [
        [_radio, player] call acre_sys_rack_fnc_isRadioAccessible,
        [_radio, player] call acre_sys_rack_fnc_isRadioHearable
    ];
};

[_radio, _value] call acre_sys_radio_fnc_setRadioVolume; 
if (_value == 0 && (_radio in _activeRadios)) then { 
    _selectedRack set [1,0]; 
} else { 
    if (_value > 0 && !(_radio in _activeRadios) && _index + 1 == _workPos) then { 
        _selectedRack set [1,3]; 
    } else { 
        _selectedRack set [1,1]; 
    }; 
};
