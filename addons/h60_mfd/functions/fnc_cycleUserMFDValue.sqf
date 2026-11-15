/*
 * hct_h60_mfd_fnc_cycleUserMFDValue
 */

params ["_vehicle", "_index"];

//private _cur = _vehicle ammoOnPylon _index; // later
private _cur = getUserMFDValue _vehicle select _index; // later

private _target = 0;
if (_cur == 0) then {
	_target = 1;
};

[_vehicle, _index, _target] call hct_h60_mfd_fnc_setPylonValue;
