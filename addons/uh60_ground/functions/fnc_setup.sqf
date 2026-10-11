/*
 * vtx_uh60_ground_fnc_setup
 *
 * starts up the ground module: the parking brake
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];
if (!vtx_uh60m_enabled_ground) exitWith {false};

//Let EICAS know parking brake is on
if ((_vehicle animationPhase "handle_wheelbrake") == 1) then {
    [_vehicle, true, "ON"] call vtx_uh60_ground_fnc_wheelBrakes;
} else {
    [_vehicle, true, "OFF"] call vtx_uh60_ground_fnc_wheelBrakes;
};

true
