/*
 * vtx_uh60_acre_fnc_changeTX
 *
 * changes active radio with TX knob
 *
 * 
 */

params ["_vehicle"];

private _value = round ((_vehicle animationSourcePhase "TX_ROT") * 10); //changes it to 1-4 range

if(vtx_uh60_ui_showDebugMessages) then {
    systemChat str [
        _value
    ];
};

private _workPos = [_vehicle, acre_player, 0, "workKnob"] call acre_sys_intercom_fnc_getStationConfiguration;

private _newWorkPos = ((_value) max 0) min 7;

if (_newWorkPos == _workPos) exitWith {};

private _wiredRacks = [_vehicle, acre_player, 0, "wiredRacks"] call acre_sys_intercom_fnc_getStationConfiguration;
private _monitorPos = [_vehicle, acre_player, 0, "monitorKnob"] call acre_sys_intercom_fnc_getStationConfiguration;

// Set the previous rack to no monitor unless it is selected in the monitor knob
if (_workPos != 0) then {
    private _selectedRack = _wiredRacks select (_workPos - 1);

    private _rackId = _selectedRack select 0;
    if (_rackId != "" && {_selectedRack select 2}) then {
        if (_workPos != _monitorPos) then {
            private _radioId = [_rackId] call acre_sys_rack_fnc_getMountedRadio;

            if (_monitorPos != 7) then {
                _selectedRack set [1, 0];
                if (_radioId != "") then {
                    [_vehicle, acre_player, _radioId] call acre_sys_rack_fnc_stopUsingMountedRadio;
                };
            } else {
                _selectedRack set [1, 1];
            };
        } else {
            _selectedRack set [1, 1];
        };
    };
};

if (_newWorkPos != 0) then {
    private _selectedRack = _wiredRacks select (_newWorkPos - 1); // RackID, Functionality, Has Access
    private _rackId = _selectedRack select 0;
    if ((_rackId != "") && {_selectedRack select 2}) then {
        private _radioId = [_rackId] call acre_sys_rack_fnc_getMountedRadio;
        _selectedRack set [1, 3];

        if ((_newWorkPos != _monitorPos) && {_radioId != ""}) then {
            [_vehicle, acre_player, _radioId] call acre_sys_rack_fnc_startUsingMountedRadio;
            private _pttAssign = [_vehicle] call acre_api_fnc_getMultiPushToTalkAssignment;
            _pttAssign set [2, _radioID];

            [_pttAssign] call acre_api_fnc_setMultiPushToTalkAssignment;
        };
    };
} else {
    private _selectedRack = _wiredRacks select (_workPos - 1);
    private _rackId = _selectedRack select 0;
    if ((_rackId != "") && {_selectedRack select 2} && {_workPos != _monitorPos} && {_monitorPos != 7} ) then {
        private _radioId = [_rackId] call acre_sys_rack_fnc_getMountedRadio;

        _selectedRack set [1, 0];
        if (_radioId != "") then {
            [_vehicle, acre_player, _radioId] call acre_sys_rack_fnc_stopUsingMountedRadio;
        };
    };
};

[_vehicle, acre_player, 0, "workKnob", _newWorkPos] call acre_sys_intercom_fnc_setStationConfiguration;