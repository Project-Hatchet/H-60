params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
// systemchat "HELLFIRE LAUNCHED";
private _vehicle = vehicle player;
if (vehicle _gunner == _vehicle) then {
	addCamShake [1, 0.2, 10]; 
};