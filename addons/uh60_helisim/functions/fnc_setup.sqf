#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_setup

Description:
    Initialises HeliSim Core for the H-60 and hands it this aircraft's
    configuration. Called once per aircraft from the pack's own init EH.

Parameters:
    _heli - The helicopter [Object]

Returns:
    Nothing

Author:
    BradMick
---------------------------------------------------------------------------- */
params ["_heli"];

//Once per aircraft.
if (_heli getVariable ["bmkhs_initialised", false]) exitWith {};

[_heli] call bmkhs_fnc_coreInit;
[_heli, configOf _heli >> "BMKHS_HeliSim"] call bmkhs_fnc_coreConfig;
