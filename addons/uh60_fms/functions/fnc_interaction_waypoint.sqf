/*
 * vtx_uh60_fms_fnc_interaction_waypoint
 *
 * handle interaction of waypoint page
 *
 * params (array)[(object) vehicle, (string) action, (misc) _value]
 */

params ["_vehicle", "_action", "_value", ["_pageData", nil]];

switch (_action) do {
    case "cycle": {
        private _group = group player;
        private _waypointIndex = currentWaypoint _group;
        [player, "", (_waypointIndex + _value)] call vtx_uh60_fms_fnc_selectWaypoint;
    };
    case "import": {
        private _waypoints = waypoints group player;
        { // forEach _wayPoints;
            deleteWaypoint [group player, 0];
        } forEach _wayPoints;
        private _autoNext = _vehicle getVariable ["vtx_uh60_fms_import_autoCycle", false];
        private _microDagrWaypoints = [] call ace_microdagr_fnc_deviceGetWaypoints;
        { // forEach _microDagrWaypoints
            _x params ["_label","_position",["_name",""]];
            group player addWaypoint [_position, -1, _forEachIndex, _name];
            [group player, _forEachIndex] setWaypointDescription _label;
            if (!_autoNext) then {
                [group player, _forEachIndex] setWaypointStatements ["false", ""];
            };
            [group player, _forEachIndex] setWaypointVisible false;
        } forEach _microDagrWaypoints;
        _vehicle setUserMFDvalue _value;
    };
    case "flir": {
        getPilotCameraTarget _vehicle params ["_isTracking", "_tgtPosASL", ""];
        if (_isTracking) then {
            private _group = group player;
            private _waypoints = waypoints _group;
            private _waypointIndex = currentWaypoint _group;

            private _wp = _group addWaypoint [_tgtPosASL, -1, count _waypoints, "Track Pos"];
            _wp setWaypointDescription "Track Pos";
            if (!_autoNext) then {
              _wp setWaypointStatements ["false", ""];
            };
            _wp setWaypointVisible false;
            _wp setWaypointType "HOLD";
            //_vehicle setUserMFDvalue _value;
        };
    };
    case "location": {
        // fms_locations_page_list
        private _index = fms_locations_page_index * 4 + _value;
        if (_index < count fms_locations_page_list) then {
            fms_locations_selected = fms_locations_page_list # _index # 1;
            _vehicle setUserMFDvalue _pageData;
        };
    };
    case "store_save_waypoint": {
        if (isNil "fms_locations_selected") exitWith {};
        private _microDagrWaypoints = [] call ace_microdagr_fnc_deviceGetWaypoints;
        private _location = fms_locations_selected;
        private _height = getTerrainHeightASL (locationPosition _location);
        private _position = locationPosition _location;
        _position set [2, _height];
        private _newWP = [text _location, _position];
        _microDagrWaypoints pushBack _newWP;
        ACE_player setVariable ["ace_microdagr_waypoints", _microDagrWaypoints];
        private _wp = group player addWaypoint [_newWP # 1, -1, (count waypoints group player), _newWP # 0];
        _wp setWaypointDescription (_newWP # 0);
        private _autoNext = _vehicle getVariable ["vtx_uh60_fms_import_autoCycle", false];
        if (!_autoNext) then {
            _wp setWaypointStatements ["false", ""];
        };
        _vehicle setUserMFDvalue _pageData;
    };
    case "send": { 
        private _wayPoint = [group player, currentWaypoint group player];
        private _position = waypointPosition _wayPoint;

        private _sender = profileName; 
        private _recipient = "ALL"; 
        private _id = "XMIT WAYPT"; 
        private _messageContent = [
            mapGridPosition _position,
            str (_position # 2),
            waypointDescription _wayPoint,
            "AUTO SENT FROM FMS",
            "", 
            "", 
            "", 
            "", 
            "", 
            ""
        ]; 
        private _message = [_id, _sender, _recipient, 2, _messageContent, [_position], [[_timestamp, _sender, "SENT"]]]; 
        _message call vtx_uh60_jvmf_fnc_attemptSendMessage;
    };
    case "slew_flir_waypt": { 
        private _wayPoint = [group player, currentWaypoint group player];
        private _position = waypointPosition _wayPoint;
        _vehicle setPilotCameraTarget (AGLtoASL (_position));
		[true, (AGLtoASL _position)] remoteExecCall ["vtx_uh60_flir_fnc_syncTurret", crew _vehicle];
    };
    case "slew_flir": { 
        if (isNil "fms_locations_selected") exitWith {};
        private _location = fms_locations_selected;
        _vehicle setPilotCameraTarget (AGLtoASL (locationPosition _location));
		[true, (AGLtoASL (locationPosition _location))] remoteExecCall ["vtx_uh60_flir_fnc_syncTurret", crew _vehicle];
    };
};

[_vehicle] call vtx_uh60_fms_fnc_perSecond;
