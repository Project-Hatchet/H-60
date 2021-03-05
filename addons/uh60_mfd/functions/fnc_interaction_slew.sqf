/*
 * vtx_uh60_mfd_fnc_interaction_slew
 */
params ["_action", "_value"];
private _vehicle = vehicle player;
if (!([_vehicle, "mfd", "vtx_H60_base"] call vxf_core_fnc_hasModule)) exitWith {};

private _mfdState = (getUserMFDValue _vehicle) # 39;
if (_action == "slewX" || _action == "slewY") exitWith {
	if (_mfdState == -1) then {
		if (_action == "slewX") then {vtx_uh60_mfd_slewX = _value;};
		if (_action == "slewY") then {vtx_uh60_mfd_slewY = _value;};
	} else {
		if (_action == "slewY") then {
			_vehicle setUserMFDValue [39, (_mfdState - _value) max 0 min 5];
		} else {
			_vehicle setUserMFDValue [39, 5];
		};
	};
};

if (_action == "slewAction" && _mfdState == -1) exitWith {
	_vehicle setUserMFDValue [39, 0];
};

if (_action == "slewAction") exitWith {
	switch (_mfdState) do {
		case 0: {
			[_vehicle,'waypt'] call vtx_uh60_mfd_fnc_interaction_tac;
		};
		case 1: {
			[_vehicle,'flir'] call vtx_uh60_mfd_fnc_interaction_tac;
		};
		case 2: {
			[_vehicle,'zoom', 1] call vtx_uh60_mfd_fnc_interaction_tac;
		};
		case 3: {
			[_vehicle,'zoom', -1] call vtx_uh60_mfd_fnc_interaction_tac;
		};
		case 4: {
			private _centerMode = _vehicle getVariable ["vtx_uh60_mfd_tac_center_mode", 0];
			if (_centerMode == 3) then {_centerMode = 0} else {_centerMode = _centerMode + 1};
			_vehicle setVariable ["vtx_uh60_mfd_tac_center_mode", _centerMode, true];
		};
		case 5: {
			_vehicle setUserMFDValue [39, -1];
		};
	};
};
