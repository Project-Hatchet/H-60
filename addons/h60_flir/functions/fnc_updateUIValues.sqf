/*
 * vtx_uh60_flir_fnc_updateUIValues
 *
 * Fills the fullscreen FLIR overlay readouts (direction, range, grid, time, ...).
 *
 * params [(object) vehicle, (number) frame time]
 */

params ["_vehicle", "_frameTime"];
#include "\bmkhs_helisim\functions\core\core.hpp"
private _ui = uiNamespace getVariable "vtx_uh60_flir_ui";
private _controlsGroup = _ui displayCtrl 170;

if (vtx_uh60_flir_isInScriptedCamera) then {
	//if (isNil "vtx_uh60_flir_camera") exitWith {};
	(_controlsGroup controlsGroupCtrl 156) ctrlSetText str (round (getDir vtx_uh60_flir_camera)); // DIR

	private _visText = vtx_uh60_flir_visionModeNamesHashMap get vtx_uh60_flir_pipEffect;
	(_controlsGroup controlsGroupCtrl 153) ctrlSetText _visText; // VIS

	(_controlsGroup controlsGroupCtrl 158) ctrlSetText (if (isLaserOn _vehicle) then [{"LRF ARMED"}, {""}]); // LSR

	private _zoomRaw = ([0.5,0.5] distance2D  worldToScreen positionCameraToWorld [0,3,4])
	* (getResolution select 5) / 2;
	(_controlsGroup controlsGroupCtrl 180) ctrlSetText format["%1x", _zoomRaw toFixed 1]; // zoom

	(_controlsGroup controlsGroupCtrl 171) ctrlSetText (mapGridPosition _vehicle); // spd
	(_controlsGroup controlsGroupCtrl 188) ctrlSetText str round (((getUserMFDValue _vehicle) # 103) * MPS_TO_KNOTS); // spd - HeliSim ground speed, kt (USERMFDV_GS)
	(_controlsGroup controlsGroupCtrl 189) ctrlSetText str round (((getUserMFDValue _vehicle) # 101) * METERS_TO_FEET); // pos - HeliSim radar altitude, ft (USERMFDV_RADALT)

	private _target = screenToWorld [0.5, 0.5];
	(_controlsGroup controlsGroupCtrl 172) ctrlSetText (mapGridPosition _target); // tpos
	(_controlsGroup controlsGroupCtrl 151) ctrlSetText str round (_vehicle distance _target); // trange

	private _time = [dayTime] call BIS_fnc_timeToString;
	(_controlsGroup controlsGroupCtrl 190) ctrlSetText _time; // time
};

// geolock
(_controlsGroup controlsGroupCtrl 155) ctrlSetText (["", "GEOLOCK"] select (getPilotCameraTarget _vehicle # 0));
//(_controlsGroup controlsGroupCtrl 154) ctrlSetText (if(false) then [{"TRK COR"}, {""}]);
