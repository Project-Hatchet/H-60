params ["_vehicle", "_type"];
private _pylon = switch (_type) do {
	case "PRI CHAN": {42};
	case "ALT CHAN": {43};
	case "LRFD": {45};
	case "LST": {44};
};
private _index = _vehicle ammoOnPylon _pylon;
if (_index == -1) exitWith {1111};
vtx_uh60_weapons_laserCodes # _index;