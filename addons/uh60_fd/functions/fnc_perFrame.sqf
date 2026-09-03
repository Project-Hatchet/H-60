/*
 * vtx_uh60_fd_fnc_perFrame
 *
 * runs the per frame updates of the flight director, this is where its active control is done
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */

#include "defines.hpp"

params ["_vehicle", "_frameTime"];


_vehicle setUserMFDvalue [37, (velocityModelSpace _vehicle) # 0];
_vehicle setUserMFDvalue [38, (velocityModelSpace _vehicle) # 1];

private _autohoverKeyDetected = (inputAction "autoHover" > 0 || inputAction "autoHoverCancel" > 0);
if (_autohoverKeyDetected && !GET("autoHoverKeyDown",false)) then {
    SET("autoHoverKeyDown", true);
    [_vehicle, "HVR"] call vtx_uh60_fd_fnc_modeSet;
};
if (!_autohoverKeyDetected) then {
    SET("autoHoverKeyDown", false);
};

if (!isEngineOn _vehicle) exitWith {};
if (!local _vehicle) exitWith {};
if (isAutoHoverOn _vehicle && !(_vehicle getVariable ["hvr", false])) exitWith {
    player action ["AutoHoverCancel", _vehicle];
};

private _rotorState = _vehicle animationPhase "hrotor";
private _lastRotorAnim = GET("lastRotorAnim",_rotorState);
if (_rotorState > _lastRotorAnim) then {
    SET("rotorRPM", (_rotorState - _lastRotorAnim));
};
SET("lastRotorAnim", _rotorState);

private _altCode = GET("alt_mode",nil);
if (!isNil "_altCode") then {_this call _altCode} else {
    if (vtx_uh60m_simpleCollective && difficultyEnabledRTD) then {
        private _collective = (inputAction "HeliCollectiveRaise") - (inputAction "HeliCollectiveLower");
        if (_collective != 0) then {
            SET("collectiveHeld", GET("collectiveHeld",0) + _frameTime);
        } else {
            SET("collectiveHeld", 1);
        };
        [_vehicle, _frameTime, _collective * 8 * ((GET("collectiveHeld",0) / 3) min 3)] call vtx_uh60_fd_fnc_verticalVelocity;
    };
};


private _pitchCode = GET("pitch_mode",nil);
if (!isNil "_pitchCode") then {_this call _pitchCode};

private _rollCode = GET("roll_mode",nil);
if (!isNil "_rollCode") then {_this call _rollCode};
