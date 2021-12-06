params ["_vehicle", "_frameTime"];
private _currentVisionMode = _vehicle getVariable ["vtx_flir_initVisionMode", 0];
if (inputAction "cameraVisionMode" > 0 && !vtx_uh60_flir_visionChanging) then {
	_currentVisionMode = if (_currentVisionMode == 3) then [{0}, {_currentVisionMode + 1}];
	camUseNVG (_currentVisionMode == 1);
	(_currentVisionMode > 1) setCamUseTI (_currentVisionMode - 2);
	if(vtx_uh60_hui_showDebugMessages) then {systemChat str _currentVisionMode;};
	_vehicle setVariable ["vtx_flir_initVisionMode", _currentVisionMode];
	vtx_uh60_flir_visionChanging = false;
};
vtx_uh60_flir_visionChanging = (inputAction "cameraVisionMode" > 0);