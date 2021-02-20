params ["_stabilized", "_values"];

private _localStabilized = (getPilotCameraTarget (vehicle player)) # 0;
if (_stabilized) then {
	vehicle player setPilotCameraTarget _values;
} else {
	if (_localStabilized) then {
		vehicle player setPilotCameraTarget objNull;
	};
	vehicle player setPilotCameraDirection _values;
};