/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_setup

Description:
    Initialises HeliSim Core for the H-60. Once per aircraft.

Parameters:
    _heli - The helicopter [Object]

Returns:
    Nothing
---------------------------------------------------------------------------- */
params ["_heli"];

if (_heli getVariable ["bmkhs_initialised", false]) exitWith {};

//Set before coreConfig, which reads them.
if (local _heli) then {
    _heli setVariable ["ESIS_START_TIME", _heli getVariable ["ESIS_START_TIME", CBA_missionTime], true];
    _heli setVariable ["bmkhs_erfsTankInstalled", (_heli animationSourcePhase "ERFS_show") >= 0.5, true];
};

[_heli] call bmkhs_fnc_coreInit;
[_heli, configOf _heli >> "BMKHS_HeliSim"] call bmkhs_fnc_coreConfig;
