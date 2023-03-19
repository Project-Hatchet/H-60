params ["_vehicle", "_current", "_target"];
private _pages = if (player == driver _vehicle) then [{[25,2]},{[23,2]}];
{
  if (_x == _current) then {
    [_vehicle, (_pages # 0) + _forEachIndex, _target, true] call vtx_uh60_mfd_fnc_switchPage;
  };
} forEach ((getUserMFDValue _vehicle) select _pages);