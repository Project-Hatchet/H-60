params ["_index", "_marker"];
_marker params ["_position", "_iconIndex", "_size", "_direction", "_time", "_sender"];

#if __has_include("\z\ctab\addons\core\config.bin")
	#include "cTab\1erGTD.sqf"
#else
	#include "cTab\cTab.sqf"
#endif

private _positionType = switch (true) do {
	case (_iconIndex in SALUTE_IDs): {"SALUTE"};
	case (_iconIndex in MEDIC_IDs): {"MEDIC"};
	case (_iconIndex in OTHER_IDs): {"OTHER"};

	// ControlPoint
	#ifdef ControlPoint_IDs
		case (_iconIndex in ControlPoint_IDs): {"ControlPoint"};
	#endif

	// Manoeuvre
	#ifdef Manoeuvre_IDs
		case (_iconIndex in Manoeuvre_IDs): {"Manoeuvre"};
	#endif

	// Sustainment
	#ifdef Sustainment_IDs
		case (_iconIndex in Sustainment_IDs): {"Sustainment"};
	#endif

	default {"UNKOWN"};
};

#if __has_include("\z\ctab\addons\core\config.bin")
	if ((_iconIndex >= 100) && (_size > 0)) then {
		_time = format ["%1-%2", ["A","B","C","D","E","F"] # (_size - 1), _time];
	};
#endif


private _position3d = [_position # 0, _position # 1, getTerrainHeightASL _position];
private _messageComments = switch (_positionType) do {
	case "SALUTE": {
		private _enemyType = SALUTE_ICON # (SALUTE_IDs find _iconIndex);
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
		private _medicalType = MEDIC_ICON # (MEDIC_IDs find _iconIndex);
		[_medicalType, "", "", "", "", "", ""]
	};
	case "OTHER": {
		private _otherType = OTHER_ICON # (OTHER_IDs find _iconIndex);
		[_otherType, "", "", "", "", "", ""]
	};

	// ControlPoint
	#ifdef ControlPoint_IDs
		case "ControlPoint": {
			private _otherType = ControlPoint_ICON # (ControlPoint_IDs find _iconIndex);
			[_otherType, "", "", "", "", "", ""]
		};
	#endif
	// Manoeuvre
	#ifdef Manoeuvre_IDs
		case "Manoeuvre": {
			private _otherType = Manoeuvre_ICON # (Manoeuvre_IDs find _iconIndex);
			[_otherType, "", "", "", "", "", ""]
		};
	#endif
	// Sustainment
	#ifdef Sustainment_IDs
		case "Sustainment": {
			private _otherType = Sustainment_ICON # (Sustainment_IDs find _iconIndex);
			[_otherType, "", "", "", "", "", ""]
		};
	#endif

	case "UNKNOWN": {
		["UNKNOWN", "", "", "", "", "", ""]
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