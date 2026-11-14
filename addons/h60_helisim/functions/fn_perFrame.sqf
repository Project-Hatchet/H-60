/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_perFrame

Description:
    Per-frame tick for one local H-60.

Parameters:
    _heli - The helicopter [Object]

Returns:
    Nothing
---------------------------------------------------------------------------- */
params ["_heli"];

[_heli] call vtx_uh60_helisim_fnc_updateLimits;
[_heli] call bmkhs_fnc_coreUpdate;

//ERFS tank follows ERFS_show
private _erfs = (_heli animationSourcePhase "ERFS_show") >= 0.5;
if ((_heli getVariable ["bmkhs_erfsTankInstalled", false]) isNotEqualTo _erfs) then {
    _heli setVariable ["bmkhs_erfsTankInstalled", _erfs, true];
    //Re-share the fuel over the tanks now fitted - Core only re-syncs on a fuel change
    [_heli] call bmkhs_fnc_fuelSet;
};

//The ERFS transfers to both mains on its own while installed, until it is empty
if (_erfs && {!(_heli getVariable ["bmkhs_erfsTankXferOn", false])} && {(_heli getVariable ["bmkhs_erfsTankMass", 0]) > 0.5}) then {
    _heli setVariable ["bmkhs_erfsTankXferOn", true, true];
};

[_heli] call vtx_uh60_helisim_fnc_updateVisuals;
