/*
 * vtx_uh60_anvishud_fnc_Hud_Brt
 *
 * Dims the HMD
 *
 * params []
 */

_ammoCount = (vehicle player) ammoOnPylon 11;
if(_ammoCount <1000) then {
 	vehicle player setAmmoOnPylon [11, _ammoCount + 100];
};