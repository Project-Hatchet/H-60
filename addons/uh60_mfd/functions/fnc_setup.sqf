/*
 * vtx_uh60_mfd_fnc_setup
 *
 * handles the setup of the mfd system
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];
if (vtx_uh60m_disabled_mfd) exitWith {
    _vehicle setUserMFDvalue [23,1];
    _vehicle setUserMFDvalue [24,0];
    _vehicle setUserMFDvalue [25,0];
    _vehicle setUserMFDvalue [26,1];
    false
};

_vehicle setUserMFDvalue [23,1];
_vehicle setUserMFDvalue [24,0];
_vehicle setUserMFDvalue [25,0];
_vehicle setUserMFDvalue [26,1];
vtx_uh60_map_lastPosition = [0,0,0];
true
