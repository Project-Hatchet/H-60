/*
 * vtx_uh60_anvishud_fnc_setup
 *
 * initial setup of ANVIS/HUD-24T
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

if (!(typeOf _vehicle in ["vtx_MH60S_Pylons_GAU21L","vtx_MH60S_GAU21L","vtx_MH60S_Pylons","vtx_MH60S","vtx_MH60M_DAP","vtx_MH60M"])) exitWith { false };

_vehicle setUserMFDValue [15, vtx_uh60_anvishud_defaultMode];
true
