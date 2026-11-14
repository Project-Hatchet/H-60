/*
 * vtx_uh60_misc_fnc_addCustomization
 *
 * ACE action: fits a carried part (e.g. an ERFS tank) to the aircraft, consuming the object.
 *
 * params [(object) target, (object) player, (array) [class, animation, fitted phase, removed phase]]
 */

	params ["_target", "_player", "_params"];
	_params params ["_class", "_animation", "_addTarget", "_removeTarget"];
	private _nearestObject = nearestObject [_player, _class];
	private _hasNearObject = (!isNull _nearestObject && (player distance _nearestObject < 5));
	if (!_hasNearObject) exitWith {};
	deleteVehicle _nearestObject;
	_target animateSource [_animation, _addTarget];
