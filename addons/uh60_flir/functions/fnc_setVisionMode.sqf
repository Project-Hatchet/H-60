/*
 * Author: Ampersand
 * Set the vision mode for scripted camera and pip
 *
 * Arguments:
 * 0: Effect <ARRAY>
 * 0: Sync <BOOLEAN>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_effect] call vtx_uh60_flir_fnc_setVisionMode
 */

params ["_effect", ["_sync", true]];

vtx_uh60_flir_pipEffect = _effect;
"vtx_uh60_flir_feed" setPiPEffect vtx_uh60_flir_pipEffect;

if (vtx_uh60_flir_isInScriptedCamera) then {
  camUseNVG (vtx_uh60_flir_pipEffect isEqualTo [1]);
  if (vtx_uh60_flir_pipEffect in [[2], [7]]) then {
    true setCamUseTI (vtx_uh60_flir_pipEffectsHashMap get vtx_uh60_flir_pipEffect);
  } else {
    false setCamUseTI 0
  };
};
if (!vtx_uh60_flir_otherPilotIsPlayer || !_sync) exitWith { false };

["vtx_uh60_flir_syncVisionMode", [_effect], [vtx_uh60_flir_otherPilot]] call CBA_fnc_targetEvent;

true

/*

vtx_uh60_flir_pipEffectsHashMap = createHashMapFromArray [
  ["Normal", [0]],
  ["NVG", [1]],
  ["Ti", [2]],
  [0, [2]], // thermalMode[] white-hot
  [1, [7]], // thermalMode[] black-hot
  [2, [8]], // thermalMode[] green-hot
  // backwards for getting value for setCamUseTI
  [[2], 0], // thermalMode[] white-hot
  [[7], 1], // thermalMode[] black-hot
  [[8], 2] // thermalMode[] green-hot
];

*/
