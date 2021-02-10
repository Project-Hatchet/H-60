/*
 * vtx_uh60_cas_fnc_registerCautionAdvisory
 *
 * registers a caution/advisory in the cas system
 * this gets run on all clients when a caution happens, to synchronize the cautions list
 *
 * params (array)[(object) vehicle,(string) text, (code) clear condition]
 */

params ["_vehicle", "_text", "_clearCondition", ["_caution", false], ["_autoClear", false]];

private _casList = (_vehicle getVariable ["vtx_cas_list",[]]);
private _exists = false;
{ // forEach _casList
    if (_text == _x # 0) exitWith {
        _exists = true;
    };
} forEach _casList;

if (_exists) exitWith {};

// if you are the pilot, make the event run for the crew
if (local _vehicle) then {
    //_this remoteExecCall ["vtx_uh60_cas_fnc_registerCautionAdvisory", ((crew _vehicle) - [player])];
};

_casList pushBack [_text, _clearCondition, _autoClear];
_vehicle setVariable ["vtx_cas_list", _casList];

if (_vehicle == vehicle player) then {
    [_vehicle] call vtx_uh60_cas_fnc_updateCautionsList;
};
_vehicle setVariable ["vtx_cas_queue", (_vehicle getVariable ["vtx_cas_queue",0]) + 1];

if (_caution) then {
    _vehicle animate ["CautionMasterCaution",1];
};
