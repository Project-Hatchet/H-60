params ["_vehicle", ["_origins", [[0,-6,-5]]]];
if (!local _vehicle) exitWith {};
[_vehicle, _origins] call vtx_uh60_aar_fnc_initBaskets;
/*
[{
    params ["_args", "_pfhId"];
    _args params ["_vehicle"];
    if (!alive _vehicle) exitWith {
     [_pfhId] call CBA_fnc_removePerFrameHandler;
    };
    [_vehicle] call vtx_uh60_aar_fnc_positionBaskets;
}, 0, [_vehicle]] call CBA_fnc_addPerFrameHandler;
*/
