#include "script_component.hpp"

params ["_vehicle", "_type"];
private _pylon = switch (_type) do {
	case "PRI CHAN": {USERMFDV_PRI_CH};
	case "ALT CHAN": {USERMFDV_ALT_CH};
	case "LRFD": {USERMFDV_LRFD};
	case "LST": {USERMFDV_LST};
	default {-1};
};
if (_pylon == -1) exitWith {1111};

// the MFD value is user-driven and can be outside the code table (#436)
private _index = floor (getUserMFDValue _vehicle select _pylon);
if (_index < 0 || {_index >= count vtx_uh60_weapons_laserCodes}) exitWith {1111};

vtx_uh60_weapons_laserCodes # _index;
