/*
 * vtx_uh60_fd_fnc_updatePanel
 *
 * updates the values on the panel
 *
 * params (array)[(object) vehicle]
 */

#include "defines.hpp"

params ["_vehicle"];

_vehicle setUserMFDValue [12, GET_RALT];
_vehicle setUserMFDValue [13, GET_ALTP];
_vehicle setUserMFDValue [14, GET_ALT];
_vehicle setUserMFDValue [45, GET_IAS];
_vehicle setUserMFDValue [46, GET_HDG];
//_vehicle setUserMFDValue [17, GET_VS];

_vehicle setObjectTextureGlobal [3, LIGHT_TEXTURE(GET_RALT_STATE)];
_vehicle setObjectTextureGlobal [4, LIGHT_TEXTURE(GET_ALTP_STATE)];
_vehicle setObjectTextureGlobal [5, LIGHT_TEXTURE(GET_ALT_STATE)];
_vehicle setObjectTextureGlobal [6, LIGHT_TEXTURE(GET_IAS_STATE)];
_vehicle setObjectTextureGlobal [7, LIGHT_TEXTURE(GET_HDG_STATE)];
//_vehicle setObjectTextureGlobal [8, LIGHT_TEXTURE(GET_VS_STATE)];

true
