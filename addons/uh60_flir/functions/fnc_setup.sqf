private _vehicle = vehicle player;

private _pilotCameraConfig = configFile >> "cfgVehicles" >> typeOf _vehicle >> "pilotCamera";

params ["_vehicle"];

private _OpticsIn = _pilotCameraConfig >> "OpticsIn";

private _fovClasses = "true" configClasses _OpticsIn;
private _fovObjects = _fovClasses apply {
	[
		getNumber (_x >> "initFov"),
		getArray (_x >> "visionMode"),
		getArray (_x >> "thermalMode"),
		getText (_x >> "opticsDisplayName")
	]
};

_vehicle setVariable ["vtx_flir_mempoint", getText (_OpticsIn >> "memoryPointDriverOptics")];
_vehicle setVariable ["vtx_flir_turnLimits", [
	getNumber (_OpticsIn >> "minTurn"),
	getNumber (_OpticsIn >> "maxTurn"),
	getNumber (_OpticsIn >> "minElev"),
	getNumber (_OpticsIn >> "maxElev")
]];
_vehicle setVariable ["vtx_flir_fovObjects", _fovObjects];

true