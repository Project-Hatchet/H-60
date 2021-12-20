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
 * [_vehicle] call vtx_uh60_flir_fnc_syncPilots
 */

params ["_vehicle", ["_sync", true]];

_pilot = driver _vehicle;
_copilot = _vehicle turretUnit [0];

// only run for player pilot and copilot
private _isNotInCockpit = switch (player) do {
    case _pilot: {
        vtx_uh60_flir_playerIsPilot = true;
        vtx_uh60_flir_playerIsCopilot = false;
        vtx_uh60_flir_otherPilotIsPlayer = isPlayer _copilot;
        vtx_uh60_flir_otherPilot = _copilot;
        false
    };
    case _copilot: {
        vtx_uh60_flir_playerIsPilot = false;
        vtx_uh60_flir_playerIsCopilot = true;
        vtx_uh60_flir_otherPilotIsPlayer = isPlayer _pilot;
        vtx_uh60_flir_otherPilot = _pilot;
        false
    };
    default {
        vtx_uh60_flir_playerIsPilot = false;
        vtx_uh60_flir_playerIsCopilot = false;
        vtx_uh60_flir_otherPilot = objNull;
        vtx_uh60_flir_otherPilotIsPlayer = false;
        true
    };
};

if (vtx_uh60_flir_otherPilotIsPlayer && {_sync}) then {
  ["vtx_uh60_flir_syncPilots", [], [vtx_uh60_flir_otherPilot]] call CBA_fnc_targetEvent;
};

_isNotInCockpit
