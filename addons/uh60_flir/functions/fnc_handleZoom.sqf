params ["_vehicle", "_frameTime"];
private _fovSteps = _vehicle getVariable "vtx_flir_fovObjects";
private _currentIndex = (_vehicle getVariable "vtx_flir_initFovMode");
private _zoomDirection = 0 + (ceil (inputAction "zoomIn")) - (ceil (inputAction "zoomOut"));
if (_zoomDirection != 0 && !vtx_uh60_flir_zoomChanging) then {
	private _nextIndex = _currentIndex + _zoomDirection;
	if (_nextIndex < count _fovSteps && _nextIndex > -1) then {
		vtx_uh60_flir_camera camSetFov (_fovSteps # _nextIndex # 0);
		_vehicle setVariable ["vtx_flir_initFovMode", _nextIndex];
	};
};
vtx_uh60_flir_zoomChanging = (inputAction "zoomIn" > 0 || inputAction "zoomOut" > 0);