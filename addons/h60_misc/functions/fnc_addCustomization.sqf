/*
 * hct_h60_misc_fnc_addCustomization
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
	// the part may still be in the player's hands (removing one starts an ACE
	// carry): let go of it first so ACE's carry state is cleaned up properly
	if ((_player getVariable ["ace_dragging_carriedObject", objNull]) isEqualTo _nearestObject) then {
		[_player, _nearestObject] call ace_dragging_fnc_dropObject_carry;
	};
	deleteVehicle _nearestObject;
	_target animateSource [_animation, _addTarget];
