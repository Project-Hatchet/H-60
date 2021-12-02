params ["_vehicle", "_frameTime"];
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
	(_controlsGroup controlsGroupCtrl 188) ctrlSetText str round (speed _vehicle); // spd
	(_controlsGroup controlsGroupCtrl 189) ctrlSetText str round ((getPos _vehicle) # 2); // pos

	private _target = screenToWorld [0.5, 0.5];
	(_controlsGroup controlsGroupCtrl 172) ctrlSetText (mapGridPosition _target); // tpos
	(_controlsGroup controlsGroupCtrl 151) ctrlSetText str round (_vehicle distance _target); // trange

	private _time = [dayTime] call BIS_fnc_timeToString;
	(_controlsGroup controlsGroupCtrl 190) ctrlSetText _time; // time
  /*
	private _fovShowIndex = 1021 + (_vehicle getVariable "vtx_flir_initFovMode");
	(_ui displayCtrl _fovShowIndex) ctrlShow true;
	{
		if (_x != _fovShowIndex) then {
			(_ui displayCtrl _x) ctrlShow false;
		};
	} forEach [1021, 1022, 1023, 1024, 1025];
} else {
	private _zoomRaw = ([0.5,0.5] distance2D  worldToScreen positionCameraToWorld [0,3,4])
	* (getResolution select 5) / 2;
	if (cameraView != "GUNNER") exitWith {
		{(_ui displayCtrl _x) ctrlShow false;} forEach [1021, 1022, 1023, 1024, 1025];
	};
	(_ui displayCtrl 1021) ctrlShow (_zoomRaw > 0.7 && _zoomRaw < 0.9);
	(_ui displayCtrl 1022) ctrlShow (_zoomRaw > 1.2 && _zoomRaw < 1.4);
	(_ui displayCtrl 1023) ctrlShow (_zoomRaw > 2.4 && _zoomRaw < 2.6);
	(_ui displayCtrl 1024) ctrlShow (_zoomRaw > 11.3 && _zoomRaw < 11.5);
	(_ui displayCtrl 1025) ctrlShow (_zoomRaw > 26);
  */
};


// geolock
(_controlsGroup controlsGroupCtrl 155) ctrlSetText (if((getPilotCameraTarget _vehicle) # 0) then [{"GEOLOCK"}, {""}]);
(_controlsGroup controlsGroupCtrl 154) ctrlSetText (if(false) then [{"TRK COR"}, {""}]);
