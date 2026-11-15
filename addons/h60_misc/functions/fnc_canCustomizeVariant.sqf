/*
 * hct_h60_misc_fnc_canCustomizeVariant
 *
 * ACE condition: a toolkit, the part nearby and not already fitted.
 *
 * params [(object) target, (object) player, (array) [class, animation, fitted phase, removed phase, search range]]
 *
 * returns (bool)
 */

params ["_target", "_player", "_params"];
if (!("ToolKit" in (items player))) exitWith {false};
_params params ["_class", "_animation", "_addTarget", "_removeTarget", "_searchRange"];
private _nearestObject = nearestObject [_player, _class];
if (_target animationSourcePhase _animation == _addTarget) exitWith {false};
(!isNull _nearestObject && (player distance _nearestObject < _searchRange))
