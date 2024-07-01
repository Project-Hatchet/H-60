/*
 * vtx_uh60_aiDamage_fnc_dmgTracker
 *
 * Tracks the total AI damage on the bird and detonates the bird if it's beyond a certian threshold
 *
 * params (vehicle)
 *
 */

params["_bird", "_compHit", "_dmg"];

switch (_compHit) do {
	//engine
	case "hitengine1": {
		_bird setHitPointDamage["hitengine", ((_bird getHitPointDamage("hitengine1") + _bird getHitPointDamage("hitengine2"))/2)];
	};
	case "hitengine2": {
		_bird setHitPointDamage["hitengine", ((_bird getHitPointDamage("hitengine1") + _bird getHitPointDamage("hitengine2"))/2)];
	};
	//vRotor
	case "mainrotorgearbox": {
		_bird setHitPointDamage["hitvrotor", (_bird getHitPointDamage("mainrotorgearbox"))];
	};
	//hRotor 
	case "tailgearbox": {
		_bird setHitPointDamage["hithrotor", (_bird getHitPointDamage("tailgearbox"))];
	};
};