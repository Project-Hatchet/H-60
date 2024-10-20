/*
 * vtx_uh60_mfd_fnc_cyclePylonValue
 */

params ["_vehicle", "_index"];

private _cur = _vehicle ammoOnPylon _index;
private _target = 0;
if (_cur == 0) then {
	_target = 1;
};

[_vehicle, _index, _target] call vtx_uh60_mfd_fnc_setPylonValue;