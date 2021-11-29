[
  "UH-60M Blackhawk",
  "vtx_uh60m_c_rmtsby",
  LSTRING(Standby),
  {},{
    if (!difficultyEnabledRTD) exitWith {};
    ZEUS_EXIT
    private _vehicle = vehicle player;
    if ([_vehicle, "ui", "vtx_H60_base"] call vxf_core_fnc_hasModule) then {
      [_vehicle, "STBY"] call vtx_uh60_fd_fnc_modeSet;
    };
  },
  [15, [false, true, false]],
  false
] call CBA_fnc_addKeybind;

[
  "UH-60M Blackhawk",
  "vtx_uh60_fd_raltToggle",
  LSTRING(RALTToggle),
  {},{
    if (!difficultyEnabledRTD) exitWith {};
    ZEUS_EXIT
    private _vehicle = vehicle player;
    if ([_vehicle, "ui", "vtx_H60_base"] call vxf_core_fnc_hasModule) then {
      [vehicle player, "RALT"] call vtx_uh60_fd_fnc_modeSet;
    };
  }
] call CBA_fnc_addKeybind;
