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
 * [_effect] call hct_h60_flir_fnc_setVisionMode
 */

params ["_effect", ["_sync", true]];

hct_h60_flir_pipEffect = _effect;
"hct_h60_flir_feed" setPiPEffect hct_h60_flir_pipEffect;

if (hct_h60_flir_isInScriptedCamera) then {
  camUseNVG (hct_h60_flir_pipEffect isEqualTo [1]);
  if (hct_h60_flir_pipEffect in [[2], [7]]) then {
    true setCamUseTI (hct_h60_flir_pipEffectsHashMap get hct_h60_flir_pipEffect);
  } else {
    false setCamUseTI 0
  };
};

if (_sync && hct_h60_flir_otherPilotIsPlayer) then {
  ["hct_h60_flir_syncVisionMode", [_effect], [hct_h60_flir_otherPilot]] call CBA_fnc_targetEvent;
};

true
