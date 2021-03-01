/*
 * vtx_uh60_mfd_fnc_interaction_tac
 *
 * handles tac page interaction
 *
 * params (array)[(object) vehicle, (string) action, (misc) _value]
 */

params ["_vehicle", "_action", "_value"];

switch (_action) do {
    case "zoom": {
        private _curZoom = _vehicle getVariable ["MAP_Zoom", 0];
        private _zoomStages = [0, 0.2, 0.4, 0.6, 0.8, 1];
        private _scales = [1, 1.2, 1.5, 1.95, 2.8, 5];
        private _curIndex = _zoomStages find _curZoom;
        private _newIndex = _curIndex + _value;
        if (_newIndex < 0) exitWith {};
        if (_newIndex >= count _zoomStages) exitWith {};
        _vehicle setVariable ["MAP_Zoom", _zoomStages # _newIndex, true];
        _vehicle setVariable ["MAP_ZoomMult", _scales # _newIndex, true];
        _vehicle animateSource ["MAP1_Scale", _zoomStages # _newIndex, 1];
    };
    case "waypt": {
        private _cursorPos = [] call vtx_uh60_mfd_fnc_tac_cursorToWorld;
        private _microDagrWaypoints = [] call ace_microdagr_fnc_deviceGetWaypoints;
        private _newWP = [format ["MARK %1", count _microDagrWaypoints], _cursorPos];
        _microDagrWaypoints pushBack _newWP;
        ACE_player setVariable ["ace_microdagr_waypoints", _microDagrWaypoints];
        private _wp = group player addWaypoint [_newWP # 1, -1, (count waypoints group player), _newWP # 0];
        _wp setWaypointDescription (_newWP # 0);
        _wp setWaypointStatements ["false", ""];
    };
    case "flir": {
        private _cursorPos = [] call vtx_uh60_mfd_fnc_tac_cursorToWorld;
        _vehicle setPilotCameraTarget (AGLtoASL _cursorPos);
		[true, (AGLtoASL _cursorPos)] remoteExecCall ["vtx_uh60_flir_fnc_syncTurret", crew _vehicle];
    };
};
