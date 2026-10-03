/*
 * vtx_uh60_engine_fnc_starterState
 *
 * manages starter state
 *
 * params (array)[(object) vehicle, (string) animation name, (string) animation end state]
 */

params ["_vehicle", "_animName", "_animEndState"];

[_vehicle] call vtx_uh60_cas_fnc_updateCautions;

private _mikSwitchState = _vehicle getVariable "vtx_uh60_acft_mikSwitchState";
private _dcBusState     = _vehicle getVariable "vtx_uh60_acft_DCBusState";

//The start switch latches the engine's starter ON, or cancels a start that has not lit yet.
//uh60_helisim reads the latch with the power levers to decide when HeliSim's engines run.
{
    _x params ["_engNum", "_starterVar", "_leverVar"];
    if (_animName == format ["STARTER%1", _engNum + 1]
        && {_mikSwitchState == "ON"}
        && {_dcBusState == "ON"}
        && {(_vehicle getVariable _leverVar) == "OFF"}
        && {((_vehicle getVariable "bmkhs_engState") select _engNum) == "OFF"}) then {
        _vehicle setVariable [_starterVar, ["ON", "OFF"] select ((_vehicle getVariable _starterVar) == "ON"), true];
    };
} forEach [
    [0, "vtx_uh60_acft_eng1StarterState", "vtx_uh60_acft_eng1PwrCtrlLeverState"],
    [1, "vtx_uh60_acft_eng2StarterState", "vtx_uh60_acft_eng2PwrCtrlLeverState"]
];
