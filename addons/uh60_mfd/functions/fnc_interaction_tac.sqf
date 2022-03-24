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
        private _curZoom = _vehicle getVariable ["MAP_Zoom", 1];
        private _newZoom = (_curZoom + _value) max 1 min 30;
        _vehicle setVariable ["MAP_Zoom", _newZoom, true];
        _vehicle setVariable ["MAP_ZoomMult", _newZoom, true];
        _vehicle animateSource ["MAP1_Scale", 1/_newZoom, 1];
        _vehicle setUserMFDValue [40, worldSize / _newZoom / 2];
    };
    case "waypt": {
        private _cursorPos = [] call vtx_uh60_mfd_fnc_tac_cursorToWorld;
        [
            format ["%1/%2", name player, vtx_uh60_mfd_marks],
            _cursorPos,
            ""
        ] call vtx_uh60_fms_fnc_addWaypoint;
        vtx_uh60_mfd_marks = vtx_uh60_mfd_marks + 1;
    };
    case "flir": {
        private _cursorPos = [] call vtx_uh60_mfd_fnc_tac_cursorToWorld;
        _vehicle setPilotCameraTarget (AGLtoASL _cursorPos);
		[true, (AGLtoASL _cursorPos)] remoteExecCall ["vtx_uh60_flir_fnc_syncTurret", crew _vehicle];
    };
    case "centerMode": {
        private _centerMode = _vehicle getVariable ["vtx_uh60_mfd_tac_center_mode", 0];
        if (_centerMode == 3) then {_centerMode = 0} else {_centerMode = _centerMode + 1};
        _vehicle setVariable ["vtx_uh60_mfd_tac_center_mode", _centerMode, true];
    };
};
