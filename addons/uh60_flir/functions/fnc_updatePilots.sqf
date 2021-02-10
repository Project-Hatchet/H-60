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
 * [_heli] call vtx_uh60_flir_fnc_updatePilots
 */
//vtx_uh60_flir_fnc_updatePilots={

//params ["_heli", "_role", "_unit", "_turret"]; // GetIn/GetOut
//params ["_heli", "_unit1", "_unit2"]; // SeatSwitched
params ["_heli"];

_pilot = driver _heli;
_copilot = _heli turretUnit [0];

if (vtx_uh60_flir_useCopilotAI && {isNil "vtx_uh60_flir_camera" && {_copilot isKindOf "B_UAV_AI"}}) then {
    deleteVehicle _copilot;
};

// only run for player pilot and copilot
switch (player) do {
    case _pilot: {
        vtx_uh60_flir_playerIsPilot = true;
        vtx_uh60_flir_playerIsCopilot = false;
        vtx_uh60_flir_otherPilotIsPlayer = isPlayer _copilot;
        vtx_uh60_flir_otherPilot = _copilot;
        if !vtx_uh60_flir_otherPilotIsPlayer then {
            vtx_uh60_flir_isCopilotInGunnerView = false;
        };
        if vtx_uh60_flir_otherPilotIsPlayer then {
            _heli removeWeaponTurret ["laserdesignator_pilotcamera", [-1]];
            _heli removeMagazineTurret ["laserbatteries", [-1]];
        } else {
            if (!("laserDesignator_pilotCamera" in (_heli weaponsTurret [-1]))) then {
                _heli addWeaponTurret ["laserdesignator_pilotcamera", [-1]];
                _heli addMagazineTurret ["laserbatteries", [-1]];
            };
            if (vtx_uh60_flir_useCopilotAI && {!isNil "vtx_uh60_flir_camera" && {isNull vtx_uh60_flir_otherPilot}}) then {
                vtx_uh60_flir_otherPilot = group player createUnit ["B_UAV_AI", [0,0,0],[],0,"NONE"];
                vtx_uh60_flir_otherPilot moveInTurret [vehicle player, [0]];
                vtx_uh60_flir_otherPilot setName ["FLIR","","FLIR"];
            };
        };
    };
    case _copilot: {
        vtx_uh60_flir_playerIsPilot = false;
        vtx_uh60_flir_playerIsCopilot = true;
        vtx_uh60_flir_otherPilotIsPlayer = isPlayer _pilot;
        vtx_uh60_flir_otherPilot = _pilot;

        // view change EH
        if (player getVariable ["vtx_uh60_flir_copilotCameraViewEHID", -1] == -1) then {

            private _id = ["cameraView", {
                private _heli = vehicle player;
                if (
                    !(_heli isKindOf "vtx_h60_base") || {
                    _heli turretUnit [0] != player
                    }
                ) exitWith {
                    // clean up
                    ["cameraView", player getVariable ["vtx_uh60_flir_copilotCameraViewEHID", -1]] call CBA_fnc_removePlayerEventHandler;
                    player setVariable ["vtx_uh60_flir_copilotCameraViewEHID", nil];
                };
                params ["", "_newView"];
                vtx_uh60_flir_isCopilotInGunnerView = _newView isEqualTo "GUNNER";

                //_heli lockCameraTo [objNull, [0]];
                // if copilot in gunner view then disable pilot slew control
                if vtx_uh60_flir_otherPilotIsPlayer then {
                    ["vtx_uh60_flir_syncCopilotView", vtx_uh60_flir_isCopilotInGunnerView, vtx_uh60_flir_otherPilot] call CBA_fnc_targetEvent;
                };
            }] call CBA_fnc_addPlayerEventHandler;
            player setVariable ["vtx_uh60_flir_copilotCameraViewEHID", _id];

        };
    };
    default {
        vtx_uh60_flir_playerIsPilot = false;
        vtx_uh60_flir_playerIsCopilot = false;
        //vtx_uh60_flir_otherPilot = objNull;
        vtx_uh60_flir_otherPilotIsPlayer = false;
    };
};

true
