/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_interactStartSwitch

Description:
  Sets start switch state for the engine sim.

Parameters:
  _heli   - The helicopter to get information from [Unit].
  _engNum - The desired engine.

Returns:
  Whether to register a click (boolean).

Examples:
  ...

Author:
  BradMick
---------------------------------------------------------------------------- */
params ["_heli", "_engNum"];

private _engState    = _heli getVariable "vtx_uh60_sfmplus_engState" select _engNum;

switch (_engState) do {
  case "STARTING": {
    _engState = "OFF";
    [_heli, "vtx_uh60_sfmplus_engState", _engNum, _engState, true] call vtx_uh60_sfmplus_fnc_setArrayVariable;

    true;
  };
  case "OFF": {
    _engState = "STARTING";
    [_heli, "vtx_uh60_sfmplus_engState", _engNum, _engState, true] call vtx_uh60_sfmplus_fnc_setArrayVariable;

    true;
  };
  default {
    false;
  }
};
