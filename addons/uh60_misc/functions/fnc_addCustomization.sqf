  params ["_target", "_player", "_params"];
  _params params ["_class", "_animation", "_addTarget", "_removeTarget"];
  private _nearestObject = nearestObject [_player, _class];
  private _hasNearObject = (!isNull _nearestObject && (player distance _nearestObject < 5));
  if (!hasNearObject) exitWith {};
  deleteVehicle _nearestObject;
  _target animateSource [_animation, _addTarget];