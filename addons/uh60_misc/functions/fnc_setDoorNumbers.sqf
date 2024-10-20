/*
 * [_heli, "01"] call vtx_uh60_misc_fnc_setDoorNumbers
 */
params ["_heli", "_doorNumbers"];

private _tens = _doorNumbers select [0, 1];
private _ones = _doorNumbers select [1, 1];

private _characterToPath = {
  if (_this == "") exitWith {""};
  if (_this in "0123456789") then {
    "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_" + _this + "_ca.paa"
  } else {
    ""
  }
};

_tens = _tens call _characterToPath;
_ones = _ones call _characterToPath;

_heli setObjectTextureGlobal [20, _tens];
_heli setObjectTextureGlobal [21, _ones];
_heli setObjectTextureGlobal [22, _tens];
_heli setObjectTextureGlobal [23, _ones];
