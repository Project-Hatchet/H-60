/*
 * vtx_uh60_acre_fnc_radioStatusUpdate
 *
 * turns radio on/off
 *
 *
 */

params ["_vehicle", "_index"];

private _status = _vehicle getVariable [(format ["vtx_uh60_radio_%1", _index]),0];

private _wiredRacks = [_vehicle, acre_player, 0, "wiredRacks"] call acre_sys_intercom_fnc_getStationConfiguration;
private _selectedRack = _wiredRacks select (_index);
// Set the previous rack to no monitor unless it is selected in the monitor knob

if (_status == 0) then {
	_selectedRack set [1, 3];
	_vehicle setVariable [(format ["vtx_uh60_radio_%1", _index]), 1, true];
} else {
	private _selectedRack = _wiredRacks select (_index);
 	_selectedRack set [1,0];
		_vehicle setVariable [(format ["vtx_uh60_radio_%1", _index]), 0, true];
};
[_vehicle] call vtx_uh60_fms_fnc_perSecond;
[_vehicle] call vtx_uh60_acre_fnc_notifyOtherSeat;
