params ["_vehicle"];
if (isNil "cTabBFTmembers") exitWith {};
{
  blufor reportRemoteTarget [_x, -1];
  _x confirmSensorTarget [west, false];
} forEach (vehicles + allUnits);

private _objects = [] + (missionNamespace getVariable ["vtx_uh60_mfd_ctab_markers", []]);
if (!isNil "cTabBFTmembers") then {
  _objects = _objects + (cTabBFTmembers apply {_x # 0}) + (cTabBFTgroups apply {_x # 0}) + (cTabBFTvehicles apply {_x # 0}) + cTabUAVlist;
} else {
  // later we'll do non ctab shit here
};
{
  blufor reportRemoteTarget [_x, 2];
  _x confirmSensorTarget [west, true];
} forEach _objects;

private _laserTarget = laserTarget _vehicle;
if (!isNull (_laserTarget)) then {
  blufor reportRemoteTarget [_laserTarget, 2];
  _laserTarget confirmSensorTarget [west, true];
};