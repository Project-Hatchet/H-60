/*
 * hct_h60_misc_fnc_removeCustomization
 *
 * ACE action: removes a fitted part and puts it in the player's hands (ACE carry).
 *
 * params [(object) target, (object) player, (array) [class, animation, fitted phase, removed phase]]
 */

	params ["_target", "_player", "_params"];
	_params params ["_class", "_animation", "_addTarget", "_removeTarget"];
	_target animateSource [_animation, _removeTarget];
	private _object = _class createVehicle [0,0,0];
	_object attachTo [_player, [0,0,0]];
	[_player, _object] call ace_dragging_fnc_startCarry;
