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
        _group setCurrentWaypoint [_group, (_waypointIndex + _value)];
    };
    case "import": {
        private _waypoints = waypoints group player;
        { // forEach _wayPoints;
            deleteWaypoint [group player, 0];
        } forEach _wayPoints;
        private _autoNext = _vehicle getVariable ["vtx_uh60_fms_import_autoCycle", false];
        private _microDagrWaypoints = [] call ace_microdagr_fnc_deviceGetWaypoints;
        { // forEach _microDagrWaypoints
            group player addWaypoint [_x # 1, -1, _forEachIndex, _x # 0];
            [group player, _forEachIndex] setWaypointDescription (_x # 0);
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
    case "store_save_mark": {
        if (isNil "fms_locations_selected") exitWith {};
        private _location = fms_locations_selected;
        fms_markpoint = [text _location, locationPosition _location];
        [text _location, locationPosition _location] remoteExec ["vtx_uh60_fms_fnc_setMarkPoint", crew _vehicle];diag_log "waypoint";
        _vehicle setUserMFDvalue _pageData;
    };
};

[_vehicle] call vtx_uh60_fms_fnc_perSecond;
