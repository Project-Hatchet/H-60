/*
 * hct_h60_mfd_fnc_renderBFTUnits
 *
 * Shows cTab's blue-force-tracking contacts (and the aircraft's laser spot) as
 * BLUFOR-reported sensor targets for the TAC page. Runs each second while cTab
 * is loaded.
 *
 * Only what this function reported last time and is no longer listed gets
 * un-reported. (It used to un-report every vehicle and unit in the mission each
 * second - also clearing targets other scripts and mods had reported.)
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];
if (isNil "cTabBFTmembers") exitWith {};

private _objects = (missionNamespace getVariable ["hct_h60_mfd_ctab_markers", []])
    + (cTabBFTmembers apply {_x # 0})
    + (cTabBFTgroups apply {_x # 0})
    + (cTabBFTvehicles apply {_x # 0})
    + cTabUAVlist;

private _laserTarget = laserTarget _vehicle;
if (!isNull _laserTarget) then {
    _objects pushBack _laserTarget;
};
_objects = _objects select {_x isEqualType objNull && {!isNull _x}};

{
    blufor reportRemoteTarget [_x, -1];
    _x confirmSensorTarget [west, false];
} forEach ((missionNamespace getVariable ["hct_h60_mfd_bftReported", []]) - _objects);

{
    blufor reportRemoteTarget [_x, 2];
    _x confirmSensorTarget [west, true];
} forEach _objects;

hct_h60_mfd_bftReported = _objects;
