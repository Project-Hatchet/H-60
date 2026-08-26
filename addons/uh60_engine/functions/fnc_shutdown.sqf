params ["_vehicle"];

private _ehId = _vehicle getVariable "vtx_uh60_engine_engineEH";
if (!isNil "_ehId") then {
    _vehicle removeEventHandler ["engine", _ehId];
    _vehicle setVariable ["vtx_uh60_engine_engineEH", nil];
};
