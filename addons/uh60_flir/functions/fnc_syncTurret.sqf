params ["_stabilized", "_values"];

if (_stabilized) then {
	vehicle player setPilotCameraTarget _values;
} else {
	vehicle player setPilotCameraDirection _values;
};