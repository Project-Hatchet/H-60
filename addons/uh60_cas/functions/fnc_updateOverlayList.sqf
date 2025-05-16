#include "script_component.hpp"
/*
 * vtx_uh60_cas_fnc_updateOverlayList
 */
params ["_vehicle", ["_canOpen", false], ["_hide", false]];
if (_hide) exitWith {
	//[_vehicle, 3, 0] call vtx_uh60_mfd_fnc_setPylonValue;
  _vehicle setUserMFDValue [USERMFDV_CAS, 0];
};
if (count vtx_uh60_cas_cautionsLog == 0) exitWith {
	//[_vehicle, 3, 0] call vtx_uh60_mfd_fnc_setPylonValue;
  _vehicle setUserMFDValue [USERMFDV_CAS, 0];
};
for "_i" from 14 to 19 do {
	_vehicle setUserMFDText [_i, ""];
};
{
	if (_forEachIndex > 5) exitWith {};
	_vehicle setUserMFDText [14 + _forEachIndex, _x];
} forEach vtx_uh60_cas_cautionsLog;
//if (_canOpen || (_vehicle ammoOnPylon 3) isNotEqualTo 0) then {
if (_canOpen || (getuserMFDValue _vehicle select USERMFDV_CAS) isNotEqualTo 0) then {
	//[_vehicle, 3, 1 + vtx_uh60_cas_cautionsUnacked] call vtx_uh60_mfd_fnc_setPylonValue;
  _vehicle setUserMFDValue [USERMFDV_CAS, 1 + vtx_uh60_cas_cautionsUnacked];
};
//[_vehicle, 46, (missionNamespace getVariable ["vtx_uh60_cas_firstAdvisory", 0])] call vtx_uh60_mfd_fnc_setPylonValue;
_vehicle setUserMFDValue [USERMFDV_ADVISORIES, missionNamespace getVariable ["vtx_uh60_cas_firstAdvisory", 0]];
