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
};
