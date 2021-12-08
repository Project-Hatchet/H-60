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
vtx_uh60_anvishud_setting_color params ["_r", "_g", "_b", "_a"];
_vehicle setPylonLoadout ["dummy10", "vtx_1000rnd_dummy", true];
_vehicle setPylonLoadout ["dummy11", "vtx_1000rnd_dummy", true];
_vehicle setPylonLoadout ["dummy12", "vtx_1000rnd_dummy", true];
_vehicle setPylonLoadout ["dummy13", "vtx_1000rnd_dummy", true];
_vehicle setAmmoOnPylon ["dummy10", _r * 1000];
_vehicle setAmmoOnPylon ["dummy11", _g * 1000];
_vehicle setAmmoOnPylon ["dummy12", _b * 1000];
_vehicle setAmmoOnPylon ["dummy13", _a * 1000];

true
