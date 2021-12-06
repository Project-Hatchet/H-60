[] spawn {
	if (!isNil "vtx_uh60_flir_camera") then {
		vtx_uh60_flir_camera cameraEffect ["terminate", "back"];
		camDestroy vtx_uh60_flir_camera;
		"filmGrain" ppEffectEnable false;
		15 cutText ["", "PLAIN"];
	};
	sleep 1;

	vtx_uh60_flir_fnc_startPilotCamera = {
		params ["_vehicle"];
		vtx_uh60_flir_camera = "camera" camCreate [0,0,0];
		private _initFovStep = ((_vehicle getVariable "vtx_flir_fovObjects") # (_vehicle getVariable ["vtx_flir_initFovMode",0]));
		vtx_uh60_flir_camera camSetFov (_initFovStep # 0);
		vtx_uh60_flir_fov = _initFovStep;
		vtx_uh60_flir_camera cameraEffect ["internal", "BACK"];
		15 cutRsc ["vtx_uh60_flir_cameraOverlay", "PLAIN"];
		showCinemaBorder false;
		
		"filmGrain" ppEffectAdjust [0.5, 2, 1, 1, 1];
		"filmGrain" ppEffectCommit 0;
		"filmGrain" ppEffectEnable true;
	};

	test_fnc_perFrame = {
		// pilotCamera
		// zoomIn, zoomOut
		// cameraVisionMode
		// AimDown, AimLeft, AimRight, AimUp
		params ["_vehicle", "_frameTime"];
		if (isNil "vtx_uh60_flir_camera") exitWith {};
		_this call vtx_uh60_flir_fnc_handleMovement;
		_this call vtx_uh60_flir_fnc_handleZoom;
		_this call vtx_uh60_flir_fnc_handleVisionMode;
		_this call vtx_uh60_flir_fnc_updateUIValues;
	};

	vtx_uh60_flir_fnc_updateUIValues = {
		params ["_vehicle", "_frameTime"];
		private _ui = uiNamespace getVariable "vtx_uh60_flir_ui";
		private _controlsGroup = _ui displayCtrl 170;

		(_controlsGroup controlsGroupCtrl 156) ctrlSetText str (round (getDir vtx_uh60_flir_camera)); // DIR

		private _visText = ["DTV", "NVG", "WHT", "BHOT"] # (_vehicle getVariable ["vtx_flir_initVisionMode", 0]);
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
		
		private _fovShowIndex = 1021 + (_vehicle getVariable "vtx_flir_initFovMode");
		(_ui displayCtrl _fovShowIndex) ctrlShow true;
		{
			if (_x != _fovShowIndex) then {
				(_ui displayCtrl _x) ctrlShow false;
			};
		} forEach [1021, 1022, 1023, 1024, 1025];

		// geolock
		(_controlsGroup controlsGroupCtrl 155) ctrlSetText (if(vtx_uh60_flir_stabilized) then [{"GEOLOCK"}, {""}]);
		(_controlsGroup controlsGroupCtrl 154) ctrlSetText (if(false) then [{"TRK COR"}, {""}]);
	};

	vtx_uh60_flir_fnc_handleMovement = {
		params ["_vehicle", "_frameTime"];
		private _memPoint = _vehicle getVariable "vtx_flir_mempoint";
		private _vehicleCamPos = _vehicle modelToWorldVisual (_vehicle selectionPosition _memPoint);
		vtx_uh60_flir_camera camSetPos _vehicleCamPos;
		_this call vtx_uh60_flir_fnc_handleStabilization;
		if (vtx_uh60_flir_stabilized) then {
			_this call vtx_uh60_flir_fnc_stabilizedMovement;
		} else {
			_this call vtx_uh60_flir_fnc_unstabilizedMovement;
		};
		vtx_uh60_flir_camera camCommit 0;
	};

	vtx_uh60_flir_fnc_unstabilizedMovement = {
		params ["_vehicle", "_frameTime"];
		(vtx_uh60_flir_camera call BIS_fnc_getPitchBank) params ["_pitch"];
		private _currentFovIndex = ((_vehicle getVariable "vtx_flir_initFovMode") * 1.5 + 1);
		private _slewMod = 0.25 / _currentFovIndex;
		if (inputAction "AimLeft" > 0 || inputAction "AimRight" > 0) then {
			private _newDir = 0 - (inputAction "AimLeft") + (inputAction "AimRight");
			vtx_uh60_flir_camera setDir ((getDir vtx_uh60_flir_camera) + (_newDir * _slewMod));
		};
		if (inputAction "AimDown" > 0 || inputAction "AimUp" > 0) then {
			private _pitchChange = 0 - (inputAction "AimDown") + (inputAction "AimUp");
			_pitch = _pitch + (_pitchChange * _slewMod);
		};
		[vtx_uh60_flir_camera, _pitch, 0] call BIS_fnc_setPitchBank;
	};

	vtx_uh60_flir_fnc_stabilizedMovement = {
		params ["_vehicle", "_frameTime"];
		private _xSlew = 0 - (inputAction "AimLeft") + (inputAction "AimRight");
		private _ySlew = 0 - (inputAction "AimDown") + (inputAction "AimUp");
		if (_xSlew == 0 && _ySlew == 0) exitWith {};
		private _direction = getDir vtx_uh60_flir_camera;
		private _currentFovIndex = ((_vehicle getVariable "vtx_flir_initFovMode") + 1);
		private _slewMod = 2 / _currentFovIndex;
		private _targetMod2D = [[(_xSlew * _slewMod), (_ySlew * _slewMod)], -_direction] call BIS_fnc_rotateVector2D;
		vtx_uh60_flir_stabTarget = vtx_uh60_flir_stabTarget vectorAdd [_targetMod2D # 0, _targetMod2D # 1, 0];
	};

	vtx_uh60_flir_stabilizing = false;
	vtx_uh60_flir_stabilized = false;
	vtx_uh60_flir_stabTarget = nil;
	vtx_uh60_flir_fnc_handleStabilization = {
		params ["_vehicle", "_frameTime"];
		if (inputAction "vehLockTurretView" > 0 && !vtx_uh60_flir_stabilizing) then {
			if(vtx_uh60m_trackIR_interaction_systemChat) then {systemChat str time;};
			_this call vtx_uh60_flir_fnc_toggleStabilization;
		};
		if (vtx_uh60_flir_stabilized) then {
			private _vector = (getPosASL vtx_uh60_flir_camera) vectorFromTo (AGLtoASL vtx_uh60_flir_stabTarget);
			private _polar = _vector call CBA_fnc_vect2Polar;
			vtx_uh60_flir_camera setDir (_polar # 1);
			[vtx_uh60_flir_camera, _polar # 2, 0] call BIS_fnc_setPitchBank;
			drop ["\a3\data_f\Cl_basic","","Billboard",1,20,vtx_uh60_flir_stabTarget,[0,0,0],1,1.275,1.0,0.0,[1],[[1,0,0,1]],[0],0.0,2.0,"","",""];
		};
		vtx_uh60_flir_stabilizing = (inputAction "vehLockTurretView" > 0);
		vtx_uh60_flir_camera camCommit 0;
	};

	vtx_uh60_flir_fnc_toggleStabilization = {
		params ["_vehicle"];
		if (!vtx_uh60_flir_stabilized) then {
			if(vtx_uh60m_trackIR_interaction_systemChat) then {systemChat "STAB ON";};
			private _target = screenToWorld [0.5, 0.5];
			vtx_uh60_flir_stabTarget = _target;
			vtx_uh60_flir_stabilized = true;
		} else {
			if(vtx_uh60m_trackIR_interaction_systemChat) then {systemChat "STAB OFF";};
			vtx_uh60_flir_stabilized = false;
		};
		vtx_uh60_flir_camera camCommit 0;
	};

	vtx_uh60_flir_zoomChanging = false;
	vtx_uh60_flir_fnc_handleZoom = {
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
	};

	vtx_uh60_flir_visionChanging = false;
	vtx_uh60_flir_fnc_handleVisionMode = {
		params ["_vehicle", "_frameTime"];
		private _currentVisionMode = _vehicle getVariable ["vtx_flir_initVisionMode", 0];
		if (inputAction "cameraVisionMode" > 0 && !vtx_uh60_flir_visionChanging) then {
			_currentVisionMode = if (_currentVisionMode == 3) then [{0}, {_currentVisionMode + 1}];
			camUseNVG (_currentVisionMode == 1);
			(_currentVisionMode > 1) setCamUseTI (_currentVisionMode - 2);
			systemChat str _currentVisionMode;
			_vehicle setVariable ["vtx_flir_initVisionMode", _currentVisionMode];
			vtx_uh60_flir_visionChanging = false;
		};
		vtx_uh60_flir_visionChanging = (inputAction "cameraVisionMode" > 0);
	};

	vtx_uh60_flir_fnc_handleKeyInputs = {
		params ["_mouseButtons"];
	};
	
	private _vehicle = vehicle player;
	[_vehicle] call vtx_uh60_flir_fnc_startPilotCamera;
};