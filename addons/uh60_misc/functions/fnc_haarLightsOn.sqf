params ["_heli", "_IR"];

private _heli = vehicle player;
private _haarLightRelPoint = [0.7, 5.8, -0.85];
private _haarLightSource = "#lightreflector" createVehicle (_heli modelToWorld _haarLightRelPoint);
_haarLightSource attachTo [_heli, _haarLightRelPoint];

_heli setVariable ["vtx_haarLightsOn", true, true];

if (_IR isEqualTo true) then {
	_haarLightSource setLightIR true;	
};

private _color = [0.25, 1, 1];
private _ambient = [1, 1, 1];
private _intensity = 500;
private _dayVisible = false;
private _conePars = [25, 10, 1];
private _attenuation = [6, 1, 10, 50];
private _vector3D = [[[0.1, 1, 0], [0, 0, 1]], 0, -5, 0] call BIS_fnc_transformVectorDirAndUp;

_haarLightSource setLightColor _color;
_haarLightSource setLightAmbient _ambient;
_haarLightSource setLightIntensity _intensity;
_haarLightSource setLightDayLight _dayVisible;
_haarLightSource setLightConePars _conePars;
_haarLightSource setLightAttenuation _attenuation;
_haarLightSource setVectorDirAndUp _vector3D;

_heli setVariable ["vtx_haarLightSources", [_haarLightSource], false];