/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_interactPowerLever

Description:
  Handles power lever animation and invokes engineReset when a power lever is
  taken to off.  

Parameters:
  _heli   - The helicopter to get information from [Unit].
  _engNum - The desired engine.
  _state  - The state of the power lever (OFF, IDLE, FLY).

Returns:
  ...

Examples:
  ...

Author:
  BradMick
---------------------------------------------------------------------------- */
params ["_heli", "_engNum", "_state"];

private _engState = _heli getVariable "vtx_uh60_sfmplus_engState" select _engNum;

if (_state == "OFF") then {
  [_heli, "vtx_uh60_sfmplus_engPowerLeverState", _engNum, _state, true] call vtx_uh60_sfmplus_fnc_setArrayVariable;

  if (_engState == "ON") then {
    [_heli, _engNum] call vtx_uh60_sfmplus_fnc_engineReset;
  };

  //HeliSim
  //[_heli, _engNum, 0.0] call bmk_fnc_engineSetThrottle;
};

if (_state == "IDLE") then {
  [_heli, "vtx_uh60_sfmplus_engPowerLeverState", _engNum, _state, true] call vtx_uh60_sfmplus_fnc_setArrayVariable;

  //HeliSim
  //[_heli, _engNum, 0.25] call bmk_fnc_engineSetThrottle;
};

if (_state == "FLY") then {
  [_heli, "vtx_uh60_sfmplus_engPowerLeverState", _engNum, _state, true] call vtx_uh60_sfmplus_fnc_setArrayVariable;

  //HeliSim
  //[_heli, _engNum, 1.0] call bmk_fnc_engineSetThrottle;
};
