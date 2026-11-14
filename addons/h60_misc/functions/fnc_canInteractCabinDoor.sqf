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
// for ace interact from outside
// [_target, "cabinDoor_L", _animPhase] call vtx_uh60_misc_fnc_canInteractCabinDoor;},
private _isHCT = !isNil "hct_player" && {_caller == hct_player};
private _vehicle = [_caller, vehicle _caller] select _isHCT;

private _side = str _animName select [count _animName, 1]; // Match "L" or "R"
if (_vehicle animationPhase format ["GAU21_%1_Hide", _side] == 0) exitWith {
  if (_isHCT) then {
    hint "Door is blocked";
  };
  false
};

// Door seats per class and side, from config once (this runs every frame while
// an ACE menu is open, and on every Hatchet hover)
if (isNil "vtx_uh60_misc_doorSeatCache") then { vtx_uh60_misc_doorSeatCache = createHashMap; };
private _cacheKey = typeOf _vehicle + _side;
private _doorSeats = vtx_uh60_misc_doorSeatCache get _cacheKey;
if (isNil "_doorSeats") then {
    _doorSeats = [];
    {
        private _gunnerName = getText (_x >> "gunnerName");
        if (_gunnerName select [0, 5] == "Door " && {
            (_gunnerName select [5, 1]) == _side // Match "L" or "R"
        }) then {
            _doorSeats pushBack [_forEachIndex];
        };
    } forEach ("true" configClasses (configOf _vehicle >> "Turrets"));
    vtx_uh60_misc_doorSeatCache set [_cacheKey, _doorSeats];
};

// An open door (phase < 0.9; 1 = closed) cannot be shut onto deployed FRIES ropes.
// This block used to only hint - its `false` was discarded - and it hinted every
// frame for anyone with the ACE menu open.
if (_animPhase < 0.9 && {_vehicle getVariable ["ace_fastroping_deploymentStage", 0] > 0}) exitWith {
    if (_isHCT) then {
        hint "Door is blocked by FRIES";
    };
    false
};
if (!(_doorSeats isEqualTo []) && {
  !((_doorSeats apply {_vehicle turretUnit _x}) isEqualTo [objNull, objNull])
}) exitWith {
    if (_isHCT) then {
        hint "Door is blocked";
    };
    false;
};

true


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
