params ["_object", "_type", "_side"];
private _position = switch (_this # 1) do {
  case "ground": {
    if (typeName (_this # 0) == "GROUP") then [{getPos leader (_this # 0)}, {getPos (_this # 0)}];
  };
  case "waypoint": {waypointPosition (_this # 0)};
  default {[-10000,0,0]};
};
private _gridArea = [worldName] call ace_common_fnc_getMGRSdata;
private _grid = [_position] call ace_common_fnc_getMapGridFromPos;
private _gridStr = format ["%1    %2    %3    %4", _gridArea select 0, _gridArea select 1, _grid select 0, _grid select 1];
private _direction = round (player getDir _position);
private _distance = round ((player distance _position) * 0.000539957);
private _result = ["","",""];
if (_type == "ground") then {
  if (_side != "friendly") exitWith {
    _result
  };
  private _groupType = if (typeName _object == "GROUP") then [{"DISMOUNT"}, {getText ((configOf _object) >> "displayName")}];
  _result = [
    _gridStr,
    (if (typeName _object == "GROUP") then [{groupId _object}, {groupId group _object}]),
    format["HDG %1 / %2 NM", _direction, _distance],
    _groupType,
    _position
  ];
};
if (_type == "waypoint") then {
  _result = [
    _gridStr,
    waypointDescription (_this # 0),
    format["HDG %1 / %2 NM", _direction, _distance],
    "WAYPOINT",
    _position
  ]
};
_result