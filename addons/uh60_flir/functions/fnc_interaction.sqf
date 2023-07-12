params ["_vehicle", "_button", "_var"];
	// systemchat str _this;
switch (_button) do {
	case "WAYPT_SLEW": {
		private _currentWaypointIndex = currentWaypoint group player;
		private _waypoints = waypoints group player;

		if (_currentWaypointIndex < count _waypoints) exitWith { // valid base game waypoint
			private _target = AGLToASL waypointPosition [group player, _currentWaypointIndex];
			_vehicle setPilotCameraTarget _target;
			[[], _target] call vtx_uh60_flir_fnc_syncPilotCamera;
		};
	};
	case "WAYPT_CREATE": {
		(getPilotCameraTarget _vehicle) params ["_stabilized", "_position"];
		if (!_stabilized) exitWith {};
		private _targets = _vehicle getVariable ["vtx_uh60_flir_targets", 0];
        [
            format ["TGT %1 %2", _targets + 1, name player],
            _position,
            ""
        ] call vtx_uh60_fms_fnc_addWaypoint;
		_vehicle setVariable ["vtx_uh60_flir_targets", _targets + 1];
	};
	case "LST_CHAN": {
		private _laserCodeIndex = _vehicle ammoOnPylon 44;
		if (_laserCodeIndex == -1) then {_laserCodeIndex = 0};
		if (_laserCodeIndex < 5) then {_laserCodeIndex = _laserCodeIndex + 1} else {_laserCodeIndex = 0};
		[_vehicle, 44, _laserCodeIndex] call vtx_uh60_mfd_fnc_setPylonValue;
	};
	case "LST_MODE": {
		private _laserCodeIndex = _vehicle ammoOnPylon 47;
		if (_laserCodeIndex == -1) then {_laserCodeIndex = 0};
		if (_laserCodeIndex < 2) then {_laserCodeIndex = _laserCodeIndex + 1} else {_laserCodeIndex = 0};
		[_vehicle, 47, _laserCodeIndex] call vtx_uh60_mfd_fnc_setPylonValue;
		if (_laserCodeIndex == 2) then {
			_vehicle setVariable ["vtx_uh60_flir_fnc_lstTrackStartTime", time + 5, true];
		};
	};
	case "LRFD_CHAN": {
		private _laserCodeIndex = _vehicle ammoOnPylon 45;
		if (_laserCodeIndex == -1) then {_laserCodeIndex = 0};
		if (_laserCodeIndex < 5) then {_laserCodeIndex = _laserCodeIndex + 1} else {_laserCodeIndex = 0};
		[_vehicle, 45, _laserCodeIndex] call vtx_uh60_mfd_fnc_setPylonValue;
		private _lrfdCode = [_vehicle, "LRFD"] call vtx_uh60_weapons_fnc_getLaserCode;
		_vehicle setVariable ["ace_laser_code", _lrfdCode, true];
	};
	case "UNSTOW": {
		// systemchat str _this;
		_vehicle setVariable ["vtx_uh60_flir_boot_time", cba_missionTime, true];
		// _vehicle setVariable ["vtx_uh60_flir_stowed", false, true];
		// [_vehicle, _var, 5] call vtx_uh60_mfd_fnc_switchPage;
	};
	case "STOW": {
		_vehicle setVariable ["vtx_uh60_flir_stowed", true, true];
	};
};