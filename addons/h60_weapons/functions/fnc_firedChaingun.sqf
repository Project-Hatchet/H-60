/*
 * hct_h60_weapons_fnc_firedChaingun
 *
 * Fired (M230 chain gun): camera shake for the firing crew.
 *
 * params Fired event handler arguments
 */

params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

private _vehicle = vehicle player;
if (vehicle _gunner == _vehicle) then {
	addCamShake [1, 0.2, 10]; 
};
