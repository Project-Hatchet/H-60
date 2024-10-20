params ["_vehicle", "_frameTime"];
if (vtx_uh60_rotorRPM < 0.04) exitWith {};
// systemChat str ["running ias", _frameTime];

private _desiredSpeedKts = (round((_vehicle animationSourcePhase "FD_4_ROT")*10))*10;
private _desiredSpeed = _desiredSpeedKts * 1.852;
private _desiredPitch = -1 * ([_vehicle, "ias", _frameTime, _desiredSpeed, speed _vehicle] call vxf_util_fnc_pidRun);

[_vehicle, _frameTime, _desiredPitch max -15 min 15] call vtx_uh60_fd_fnc_achievePitch;