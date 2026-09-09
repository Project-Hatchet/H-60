/*
 * vtx_uh60_engine_fnc_pbArm
 *
 * Arms the SFM ground-handling chains for this machine when they are not
 * already running: the slope-hold and taxi drive, both on the vehicle
 * OWNER. Called every second from fnc_perSecond, which is what quietly
 * re-arms them after locality changes (the 47G cab-PFH re-arm pattern).
 * Effectively a no-op under AFM/RTD - every chain exits on its first
 * tick there.
 *
 * Brake INPUT is not armed here: under SFM the Armakeybinds "Parking
 * Brake" bind calls fnc_pbToggle directly, and under AFM the RotorLib
 * action EH in fnc_setup handles the vanilla brake key. (A vanilla
 * HeliWheelsBrake inputAction watcher was tried and deleted 2026-09-08:
 * the action reads 0 under SFM - RPT-proven - and under AFM a watcher
 * would double-fire against the RotorLib EH on a shared binding.)
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];
if (local _vehicle && {!(_vehicle getVariable ["vtx_uh60_engine_pbHoldOn", false])}) then {
    _vehicle setVariable ["vtx_uh60_engine_pbHoldOn", true];
    [_vehicle] call vtx_uh60_engine_fnc_pbHoldTick;
};
if (local _vehicle && {!(_vehicle getVariable ["vtx_uh60_engine_taxiOn", false])}
    && {isTouchingGround _vehicle}) then {
    _vehicle setVariable ["vtx_uh60_engine_taxiOn", true];
    // unconditional breadcrumb: proves in the RPT that the chain armed,
    // independent of the vtx_uh60_taxiDebug console flag
    diag_log format ["VTXTAXI armed on %1", typeOf _vehicle];
    [_vehicle] call vtx_uh60_engine_fnc_taxiTick;
};
