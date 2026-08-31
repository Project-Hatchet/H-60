#include "script_component.hpp"
#include "\z\vtx\addons\uh60_fms\config\fmsDefines.hpp"

[QGVAR(radioUpdated), {
  params ["_vehicle"];
  // don't bother refreshing if they're not even on a comm page
  private _fmsPageIndex = if (player == driver _vehicle) then {FMS_R_PAGE_INDEX} else {FMS_L_PAGE_INDEX};
  private _currentPage = (getUserMFDValue _vehicle) # _fmsPageIndex;
  if (_currentPage in [FMS_PAGE_COMM_ACRE, FMS_PAGE_COMM_INFO_ACRE]) then {
    [_vehicle] call vtx_uh60_fms_fnc_perSecond;
  };
}] call CBA_fnc_addEventHandler;
