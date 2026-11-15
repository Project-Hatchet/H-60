/*
 * hct_h60_mfd_fnc_shutDown
 *
 * Hatchet module hook: clears this seat's MFD screen textures.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];

// the sling camera renders picture-in-picture every frame while it exists: it outlived the
// aircraft when nothing destroyed it on the way out
if (!isNil "hct_h60_mfd_slingCam") then {
  [_vehicle, false] call hct_h60_mfd_fnc_slingCam;
};

_vehicle setObjectTexture [8, ""];
_vehicle setObjectTexture [9, ""];
_vehicle setObjectTexture [10, ""];
_vehicle setObjectTexture [11, ""];

_vehicle setObjectTexture [12, ""];
_vehicle setObjectTexture [13, ""];
_vehicle setObjectTexture [14, ""];
_vehicle setObjectTexture [15, ""];
