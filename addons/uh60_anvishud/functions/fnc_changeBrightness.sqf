#include "script_component.hpp"
/*
 * vtx_uh60_anvishud_fnc_changeBrightness
 *
 * Adjusts brightness of the HMD
 *
 * params (array)[(object) vehicle, (boolean) isDriver, (integer) polarity (1 or -1)]
 *
 */

params ["_vehicle", "_polarity"];

private _isDriver = (driver vehicle player) isEqualTo player;

//Determine correct pylon index based on L or R seat
private _index = if(_isDriver) then [{USERMFDV_RHMD_A}, {USERMFDV_LHMD_A}];

//_ammoCount = (_vehicle) ammoOnPylon _index;
private _brightness = getuserMFDValue _vehicle select _index;

//Adjust change amount based on current brightness and polarity passed to the function
private _change = (if(_brightness >= 0.3) then [{0.1}, {0.05}]) * _polarity;

private _value = (_brightness + _change) max 0 min 1;

//Adjust ammo at pylon index to manipulate HMD brightness (alpha)
_vehicle setUserMFDValue [_index, _value];

if(vtx_uh60_ui_showDebugMessages) then {systemChat Format["HMD Brightness: %1%2", (getuserMFDValue _vehicle select _index)*100, "%"]};


