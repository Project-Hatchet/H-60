/*
 * vtx_uh60_ground_fnc_pbArm
 *
 * Arms the SFM ground-handling chains for this machine when they are not
 * already running: the slope-hold and taxi drive, both on the vehicle
 * OWNER. Called every second from fnc_perSecond, which is what quietly
 * re-arms them after locality changes (the 47G cab-PFH re-arm pattern).
 * Brake INPUT is not armed here: the Armakeybinds "Parking Brake" bind
 * calls fnc_pbToggle directly.
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];
if (local _vehicle && {!(_vehicle getVariable ["vtx_uh60_ground_pbHoldOn", false])}) then {
    _vehicle setVariable ["vtx_uh60_ground_pbHoldOn", true];
    [_vehicle] call vtx_uh60_ground_fnc_pbHoldTick;
};
if (local _vehicle && {!(_vehicle getVariable ["vtx_uh60_ground_taxiOn", false])}
    && {[_vehicle] call bmkhs_fnc_stateOnGround}) then {
    _vehicle setVariable ["vtx_uh60_ground_taxiOn", true];
    // unconditional breadcrumb: proves in the RPT that the chain armed,
    // independent of the vtx_uh60_taxiDebug console flag
    diag_log format ["VTXTAXI armed on %1", typeOf _vehicle];
    [_vehicle] call vtx_uh60_ground_fnc_taxiTick;
};
