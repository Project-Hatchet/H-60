/*
 * Author: Ampersand
 * Check status of pilots and assign vars for perFrame
 * Add/remove laser for pilot based on player copilot
 * Add/remove AI copilot based on setting for animating the turret
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle] call hct_h60_flir_fnc_syncPilots
 */

params [["_vehicle", hct_vehicle], ["_sync", true]];

private _pilot = driver _vehicle;
private _copilot = _vehicle turretUnit [0];

// only run for player pilot and copilot
private _isNotInCockpit = switch (player) do {
    case _pilot: {
        hct_h60_flir_playerIsPilot = true;
        hct_h60_flir_playerIsCopilot = false;
        hct_h60_flir_otherPilotIsPlayer = isPlayer _copilot;
        hct_h60_flir_otherPilot = _copilot;
        false
    };
    case _copilot: {
        hct_h60_flir_playerIsPilot = false;
        hct_h60_flir_playerIsCopilot = true;
        hct_h60_flir_otherPilotIsPlayer = isPlayer _pilot;
        hct_h60_flir_otherPilot = _pilot;
        false
    };
    default {
        hct_h60_flir_playerIsPilot = false;
        hct_h60_flir_playerIsCopilot = false;
        hct_h60_flir_otherPilot = objNull;
        hct_h60_flir_otherPilotIsPlayer = false;
        true
    };
};

if (hct_h60_flir_otherPilotIsPlayer && {_sync}) then {
  ["hct_h60_flir_syncPilots", [_vehicle], [hct_h60_flir_otherPilot]] call CBA_fnc_targetEvent;
};

_isNotInCockpit
