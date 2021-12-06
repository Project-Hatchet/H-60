/*
 * vtx_uh60_mfd_fnc_switchPage
 *
 * handles the setup of the mfd system
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle", "_mfdIndex", "_pageIndex", "_propagate"];
#include "..\config\mfdDefines.hpp"

if (_propagate) exitWith {
    if(vtx_uh60m_trackIR_interaction_systemChat) then {systemChat "MFD MP Sync";};
    [_vehicle, _mfdIndex, _pageIndex, false] remoteExecCall ["vtx_uh60_mfd_fnc_switchPage", crew _vehicle];diag_log "switchPage mfd";
};

_vehicle setUserMFDValue [_mfdIndex, _pageIndex];

_vehicle setObjectTexture [MAP_SELECTION(_mfdIndex), ""];
_vehicle setObjectTexture [MFD_OVERLAY(_mfdIndex), ""];
switch (_pageIndex) do {
    case MFD_PAGE_TAC: {
        _map = getText (configFile >> "CfgWorlds" >> worldName >> "pictureMap");
        _vehicle setObjectTexture [MAP_SELECTION(_mfdIndex), _map];
        _vehicle setObjectTexture [MFD_OVERLAY(_mfdIndex), "z\vtx\addons\uh60_mfd\data\Overlay_ca.paa"];
    };
    case MFD_PAGE_FLIR: {
        [_vehicle] call vtx_uh60_flir_fnc_startCamera;
        _vehicle setObjectTexture [MFD_OVERLAY(_mfdIndex), "#(argb,512,512,1)r2t(vtx_uh60_flir_feed,1.0)"];
    };
};

private _anyFLIROpened = false;
{
 if ((getUserMFDValue _vehicle) # _x == MFD_PAGE_FLIR) exitWith {_anyFLIROpened = true };
} forEach [MFD_1_PAGE_INDEX, MFD_2_PAGE_INDEX, MFD_3_PAGE_INDEX, MFD_4_PAGE_INDEX];

if (!_anyFLIROpened) then {[_vehicle] call vtx_uh60_flir_fnc_stopCamera;};
