#include "script_component.hpp"

params ["_vehicle", "_type"];
private _pylon = switch (_type) do {
	case "PRI CHAN": {USERMFDV_PRI_CH};
	case "ALT CHAN": {USERMFDV_ALT_CH};
	case "LRFD": {USERMFDV_LRFD};
	case "LST": {USERMFDV_LST};
};
private _index = getuserMFDValue _vehicle select _pylon;
if (_index == -1) exitWith {1111};

vtx_uh60_weapons_laserCodes # _index;
