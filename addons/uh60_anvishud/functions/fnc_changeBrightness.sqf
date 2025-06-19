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

private _brightness = getUserMFDValue _vehicle select USERMFDV_HMD_A;

//Adjust change amount based on current brightness and polarity passed to the function
private _change = (if(_brightness >= 0.3) then [{0.1}, {0.05}]) * _polarity;
private _value = (_brightness + _change) max 0 min 1;

//Adjust ammo at pylon index to manipulate HMD brightness (alpha)
_vehicle setUserMFDValue [USERMFDV_HMD_A, _value];
