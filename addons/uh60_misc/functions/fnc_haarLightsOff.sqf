params ["_heli"];

private _lights = _heli getVariable ["vtx_haarLightSources", []]; 
{ 
	deleteVehicle _x; 
} forEach _lights;

_heli setVariable ["vtx_haarLightsOn", false, true];