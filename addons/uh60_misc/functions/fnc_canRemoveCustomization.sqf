	params ["_target", "_player", "_params"];
	_params params ["_class", "_animation", "_addTarget", "_removeTarget"];
	if (!("ToolKit" in (items player))) exitWith {false};
	if (_target animationSourcePhase _animation == _removeTarget) exitWith {false};
	true