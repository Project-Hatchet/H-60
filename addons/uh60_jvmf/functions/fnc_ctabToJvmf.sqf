params ["_index", "_marker"];
_marker params ["_position", "_iconIndex", "_size", "_direction", "_time", "_sender"];
private _positionType = switch (true) do {
  case (_iconIndex < 14): {"SALUTE"};
  case (_iconIndex < 24): {"MEDIC"};
  case (_iconIndex < 32): {"OTHER"};
};

private _position3d = [_position # 0, _position # 1, getTerrainHeightASL _position];
private _messageComments = switch (_positionType) do {
  case "SALUTE": {
    private _enemyType = [
      "INFANTRY", "MECHANISED INFANTRY", "MOTORISED INFANTRY", "ARMOR", "ROTARY WING", "FIXED WING", "UNKNOWN",
      "INFANTRY", "MACHINEGUN", "ANTI-TANK", "STATIC MG", "STATIC AT", "MORTAR", "ANTI-AIR"
    ] # _iconIndex;
    private _enemySize = [
      "",
      "PATROL",
      "SQUAD",
      "SECTION",
      "PLATOON"
    ] # _size;
    private _direction = [
      "STATIONARY", "MOVING NORTH", "MOVING NORTH-EAST", "MOVING EAST", "MOVING SOUTH-EAST", "MOVING SOUTH", "MOVING SOUTH-WEST", "MOVING WEST", "MOVING NORTH-WEST"
    ] # _direction;
    [
      "SALUTE FOLLOWS",
      _enemyType + " " + _enemySize,
      _direction,
      "AT POSITION " + mapGridPosition _position,
      "AT TIME " + _time
    ]
  };
  case "MEDIC": {
    private _medicalType = [
      "CASUALTY", "CCP", "BAS", "MCI"
    ] # (_iconIndex - 20);
    [_medicalType, "", "", "", "", "", ""]
  };
  case "OTHER": {
    private _otherType = [
      "HQ", "LZ"
    ] # (_iconIndex - 30);
    [_otherType, "", "", "", "", "", ""]
  };
  default {
    ["", "", "", "", "", "", ""]
  };
};

private _gridZone = [] call ace_common_fnc_getMGRSdata;
private _gridStr = [_position3d] call ace_common_fnc_getMapGridFromPos;
private _fullPositionString = format ["%1 %2 %3 %4", _gridZone # 0, _gridZone # 1, _gridStr # 0, _gridStr # 1];

// build the message
private _id = "CTAB" + str _index;
private _recipient = "ALL";
private _messageType = 2;
private _messageContent = [
  _fullPositionString,
  str (round (_position3d # 2)) + " MSL",
  _time + " " + _positionType
] + _messageComments;
private _data = [_position3d];
private _replies = [[_time, name _sender, "SENT", _sender]];

private _result = [
  _id, // TITLE
  name _sender, // SENDER
  _recipient, // RECIPIENTS
  _messageType, //MSG TYPE
  _messageContent, //MSG TEXT
  _data, // MSG DATA
  _replies // REPLIES
];
_result