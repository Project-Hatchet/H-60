/*
 * vtx_uh60_mfd_fnc_switchPage
 *
 * handles the setup of the mfd system
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle", "_mfdIndex", "_pageIndex", "_propagate"];
#include "..\config\mfdDefines.hpp"

if ((_mfdIndex == MFD_1_PAGE_INDEX || _mfdIndex == MFD_1_PAGE_INDEX) && _pageIndex == MFD_PAGE_CCFS_MENU) exitWith {
  ["Warning\nThe CCFS can only be opened on MFD 2 and 3"] call vtx_uh60_misc_fnc_hint;
};

if (_propagate) exitWith {
    if(vtx_uh60_ui_showDebugMessages) then {systemChat "MFD MP Sync";};
    [_vehicle, _mfdIndex, _pageIndex, false] remoteExecCall ["vtx_uh60_mfd_fnc_switchPage", crew _vehicle];diag_log "switchPage mfd";
};

_vehicle setUserMFDValue [_mfdIndex, _pageIndex];

private _slingCam = false;
switch (_pageIndex) do {
    case MFD_PAGE_TAC: {
        private _mapName = format ["z\vtx\addons\uh60_mfd\data\maps\%1.paa", worldName];
        if (fileExists _mapName) then {
          _vehicle setObjectTexture [MAP_SELECTION(_mfdIndex), _mapName];
          _vehicle setObjectMaterial [MAP_SELECTION(_mfdIndex), "z\vtx\addons\uh60_mfd\data\Emmisive\Emmisive_2.rvmat"];
        } else {
          private _fallbackMap = getText (configFile >> "CfgWorlds" >> worldName >> "pictureMap");
          _vehicle setObjectTexture [MAP_SELECTION(_mfdIndex), _fallbackMap];
          _vehicle setObjectMaterial [MAP_SELECTION(_mfdIndex), "z\vtx\addons\uh60_mfd\data\Emmisive\Emmisive_2.rvmat"];
        };
        _vehicle setObjectTexture [MFD_OVERLAY(_mfdIndex), "z\vtx\addons\uh60_mfd\data\Overlay_ca.paa"];
    };
    case MFD_PAGE_FLIR: {
      _vehicle setObjectTexture [MFD_OVERLAY(_mfdIndex), "#(argb,512,512,1)r2t(vtx_uh60_flir_feed,1.0)"];
      _vehicle setObjectMaterial [MFD_OVERLAY(_mfdIndex), "\A3\Structures_F\Items\Electronics\Data\electronics_screens.rvmat"];
      if (isNil "vtx_uh60_flir_controllable" || {!vtx_uh60_flir_controllable}) then {
        _slingCam = true;
      } else {

        [_vehicle] call vtx_uh60_flir_fnc_pipStart;
      };
    };
    case MFD_PAGE_IVHMS: {
        [_vehicle] call vtx_uh60_mfd_fnc_ivhms;
    };
    default {
      _vehicle setObjectTexture [MAP_SELECTION(_mfdIndex), ""];
      _vehicle setObjectTexture [MFD_OVERLAY(_mfdIndex), ""];
      _vehicle setObjectMaterial [MAP_SELECTION(_mfdIndex), ""];
      _vehicle setObjectMaterial [MFD_OVERLAY(_mfdIndex), ""];
    };
};

if (_pageIndex != MFD_PAGE_IVHMS) then {
    vtx_uh60_mfd_allowText = true;
    {
        if ((getUserMFDValue _vehicle) # _x == MFD_PAGE_IVHMS) then {
            _vehicle setUserMFDvalue [_x,[1,0,0,1] # _forEachIndex];
        };
    } forEach [MFD_1_PAGE_INDEX, MFD_2_PAGE_INDEX, MFD_3_PAGE_INDEX, MFD_4_PAGE_INDEX];
    for "_i" from 0 to 19 step 1 do { _vehicle setUserMFDText [_i, ""]; };
};

[_vehicle, _slingCam] call vtx_uh60_mfd_fnc_slingCam;

private _anyFLIROpened = false;
{
 if ((getUserMFDValue _vehicle) # _x == MFD_PAGE_FLIR) exitWith {_anyFLIROpened = true };
} forEach [MFD_1_PAGE_INDEX, MFD_2_PAGE_INDEX, MFD_3_PAGE_INDEX, MFD_4_PAGE_INDEX];

if (!_anyFLIROpened) then {[_vehicle] call vtx_uh60_flir_fnc_pipStop;};
