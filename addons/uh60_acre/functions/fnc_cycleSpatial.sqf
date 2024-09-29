/*
 * vtx_uh60_acre_fnc_cycleSpatial
 *
 * handles changing Spatial output
 *
 * params (array)[(object) vehicle, (string) Ear assignment (LEFT, RIGHT or CENTER)]
 */

params ["_vehicle", "_index", "_cycle"];

private _newSpatial = "CENTER";

private _racks = [_vehicle] call acre_sys_rack_fnc_getVehicleRacks;
private _radio = [_racks # _index] call acre_sys_rack_fnc_getMountedRadio;
private _oldSpatial = [_radio] call acre_api_fnc_getRadioSpatial;

if (_cycle == 1) then {
	switch (_oldSpatial) do 
	{
		case "LEFT": {_newSpatial = "RIGHT";};
		case "RIGHT": {_newSpatial = "CENTER";};
		case "CENTER": {_newSpatial = "LEFT";}; 
	};
} else {
	switch (_oldSpatial) do 
	{
		case "LEFT": {_newSpatial = "CENTER";};
		case "RIGHT": {_newSpatial = "LEFT";};
		case "CENTER": {_newSpatial = "RIGHT";}; 
	};
};

_setSpatial = [_radio, _newSpatial] call acre_api_fnc_setRadioSpatial;
true