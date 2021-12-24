/*
 * Author: Ampersand
 * Check conditions to interact with cabin door
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_this] call vtx_uh60_misc_fnc_canInteractCabinDoor
 */

params ["_caller", "_animName", "_animPhase", "_interactionName"];
private _vehicle = vehicle _caller;

private _side = str _animName select [count _animName, 1]; // Match "L" or "R"
if (_vehicle animationPhase format ["GAU21_%1_Hide", _side] == 0) exitWith {
  hint "Door is blocked";
  false
};

private _doorSeats = [];
{
    private _gunnerName = getText (_x >> "gunnerName");
    if (_gunnerName select [0, 5] == "Door " && {
        (_gunnerName select [5, 1]) == _side // Match "L" or "R"
    }) then {
        _doorSeats pushBack [_forEachIndex];
    };
} forEach ("true" configClasses (configOf _vehicle >> "Turrets"));

private _result = true;
if (_interactionName == "Closed") then {
    if (_vehicle getVariable ["ace_fastroping_deploymentStage", 0] > 0) exitWith {
        hint "Door is blocked by FRIES";
        _result = false;
    };
    if (!(_doorSeats isEqualTo []) && {
      !((_doorSeats apply {_vehicle turretUnit _x}) isEqualTo [objNull, objNull])
    }) exitWith {
        hint "Door is blocked";
        _result = false;
    };
    // True
    {
        _vehicle lockTurret [_x, true];
    } forEach _doorSeats;
    _vehicle setVariable ["ace_fastroping_deploymentStage", -1, true];
} else { // Open
    {
        _vehicle lockTurret [_x, false];
    } forEach _doorSeats;
    _vehicle setVariable ["ace_fastroping_deploymentStage", 0, true];
};

_result

/* door seat
private _doorSeats = [];
private _doorSeatSide = [];
{
    private _gunnerName = getText (_x >> "gunnerName");
    if (_gunnerName select [0, 5] == "Door ") then {
        _doorSeats pushBack [_forEachIndex + 1];
        _doorSeatSide pushBack (_gunnerName select [5, 5]);
    };
} forEach ("true" configClasses (configOf _vehicle >> "Turrets"));

if (_doorSeats isEqualTo []) exitWith {true};

{
    _x params ["_unit", "_role", "_cargoIndex", "_turretPath", "_isPersonTurret"];
    if (_isPersonTurret && {!isNull _unit && {_cargoIndex > -1 && {_turretPath in _doorSeats}}}) exitWith {
        hint "Door is blocked";
        false
    };
} forEach fullCrew [vehicle _caller, "turret", true]
*/

/* params
[
    B Alpha 2-4:1 (CW2 Ampers),
    "cabindoor_R",
    0,
    "Open",
    1,
    {},
    {},
    [
        "r_door",
        "",
        [],
        "anim",
        "cabindoor_R_handle",
        "Right Door",
        0.1,
        "",
        "_this call vtx_uh60_misc_fnc_canInteractCabinDoor",
        [],
        [
            "cabindoor_R",
            1,
            false,
            [0,1],
            ["Open","Closed"],
            {},
            {}
        ],
        []
    ]
]
[B Alpha 2-4:1 (CW2 Ampers),"cabindoor_R",1,"Closed",1,{},{},
    ["r_door","",[],"anim","cabindoor_R_handle","Right Door",0.1,"","_this call vtx_uh60_misc_fnc_canInteractCabinDoor",[],["cabindoor_R",1,false,[0,1],["Open","Closed"],{},{}],[]]
]
*/
