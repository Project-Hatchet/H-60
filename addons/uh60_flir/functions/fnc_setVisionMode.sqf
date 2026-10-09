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

if (_sync && vtx_uh60_flir_otherPilotIsPlayer) then {
  ["vtx_uh60_flir_syncVisionMode", [_effect], [vtx_uh60_flir_otherPilot]] call CBA_fnc_targetEvent;
};

true
