/*
 * hct_h60_misc_fnc_canRemoveCustomization
 *
 * ACE condition: a toolkit and the part fitted.
 *
 * params [(object) target, (object) player, (array) [class, animation, fitted phase, removed phase]]
 *
 * returns (bool)
 */

	params ["_target", "_player", "_params"];
	_params params ["_class", "_animation", "_addTarget", "_removeTarget"];
	if (!("ToolKit" in (items player))) exitWith {false};
	if (_target animationSourcePhase _animation == _removeTarget) exitWith {false};
	true
