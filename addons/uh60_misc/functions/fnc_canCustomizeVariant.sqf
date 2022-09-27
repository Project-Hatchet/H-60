params ["_target", "_player", "_params"];
if (!("ToolKit" in (items player))) exitWith {false};
_params params ["_class", "_animation", "_addTarget", "_removeTarget", "_searchRange"];
private _nearestObject = nearestObject [_player, _class];
if (_target animationSourcePhase _animation == _addTarget) exitWith {false};
(!isNull _nearestObject && (player distance _nearestObject < _searchRange))