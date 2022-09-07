	params ["_target", "_player", "_params"];
	_params params ["_class", "_animation", "_addTarget", "_removeTarget"];
	_target animateSource [_animation, _removeTarget];
	private _object = _class createVehicle [0,0,0];
	[_player, _object] call ace_dragging_fnc_carryObject;