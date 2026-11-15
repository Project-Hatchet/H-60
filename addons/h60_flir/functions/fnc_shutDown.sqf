/*
 * hct_h60_flir_fnc_shutDown
 *
 * Hatchet module hook: turns the FLIR effects off and removes this seat's FLIR event handlers.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];

// setup exits before creating these on airframes without a pilot camera
if (!isNil "hct_h60_flir_grainEffect") then { hct_h60_flir_grainEffect ppEffectEnable false; };
// the stowed blackout too - it could stay on after leaving fullscreen-stowed
if (!isNil "hct_h60_flir_blackColor") then { hct_h60_flir_blackColor ppEffectEnable false; };
hct_h60_flir_grainOn = nil;
hct_h60_flir_blackOn = nil;
hct_h60_flir_stowedHintShown = false;
if (!(isEngineOn _vehicle)) then {
    _vehicle setPilotCameraTarget objNull;
    _vehicle setPilotCameraDirection [0, 1, 0];
    [_vehicle] call hct_h60_flir_fnc_syncAnimation;
};

if (!isNil "hct_h60_flir_camera") then {
  [_vehicle] call hct_h60_flir_fnc_pipStop;
};

{
  _x call CBA_fnc_removePlayerEventHandler;
} count hct_h60_flir_playerCBAEHs;

{
  _vehicle removeEventHandler _x;
} count hct_h60_flir_vehicleEHs;

{
  player removeEventHandler _x;
} count hct_h60_flir_playerEHs;

call hct_h60_flir_fnc_initVars;
