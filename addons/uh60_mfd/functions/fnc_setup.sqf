/*
 * vtx_uh60_mfd_fnc_setup
 *
 * handles the setup of the mfd system
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];
if (!vtx_uh60m_enabled_mfd) exitWith {
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
_vehicle setVariable ["vtx_uh60_mfd_tac_center_mode", _vehicle getVariable ["vtx_uh60_mfd_tac_center_mode", 0]];
vtx_uh60_mfd_tac_mapPos = [0,0,0];
vtx_uh60_mfd_tac_cursorPos = [0.5,0.5];
vtx_uh60_mfd_slewX = 0;
vtx_uh60_mfd_slewY = 0;

true
