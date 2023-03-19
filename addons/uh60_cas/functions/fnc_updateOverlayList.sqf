/*
 * vtx_uh60_cas_fnc_updateOverlayList
 */
params ["_vehicle", ["_canOpen", false], ["_hide", false]];
if (_hide) exitWith {
  [_vehicle, 3, 0] call vtx_uh60_mfd_fnc_setPylonValue;
};
if (count vtx_uh60_cas_cautionsLog == 0) exitWith {
  [_vehicle, 3, 0] call vtx_uh60_mfd_fnc_setPylonValue;
};
for "_i" from 14 to 19 do {
  _vehicle setUserMFDText [_i, ""];
};
{
  if (_forEachIndex > 5) exitWith {};
  _vehicle setUserMFDText [14 + _forEachIndex, _x];
} forEach vtx_uh60_cas_cautionsLog;
if (_canOpen || _vehicle ammoOnPylon 3 > 0) then {
  [_vehicle, 3, 1 + vtx_uh60_cas_cautionsUnacked] call vtx_uh60_mfd_fnc_setPylonValue;
};
[_vehicle, 46, (missionNamespace getVariable ["vtx_uh60_cas_firstAdvisory", 0])] call vtx_uh60_mfd_fnc_setPylonValue;