/*
 * vtx_uh60_fms_fnc_interaction_pageChange
 *
 * handle page changes
 *
 * params (array)[(object) vehicle, (array) newpage]
 */

params ["_vehicle", "_newPage", "_propagate"];

if (_propagate) exitWith {
    [_vehicle, _newPage, false] remoteExecCall ["vtx_uh60_fms_fnc_interaction_pageChange", crew _vehicle];diag_log "pageChange";
};

_vehicle setUserMFDValue _newPage;
[_vehicle] call vtx_uh60_fms_fnc_perSecond;
