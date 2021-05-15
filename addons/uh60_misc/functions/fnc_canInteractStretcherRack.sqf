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
 * [_this] call vtx_uh60_misc_fnc_canInteractStretcherRack
 */

params ["_caller", "_animName", "_animPhase", "_interactionName"];
private _vehicle = vehicle _caller;

// FFV 13,14,16,22 should be disabled if stretchers are folded down
// Cargo 24 and 25 should be enalbled if stretchers are folded up
private _doorSeats = [];

private _result = true;
if (_interactionName == "Lowered") then {
  private _blockedByFFV = false;
  _blockedByFFV = {
    if (!isNull (_vehicle turretUnit [_x]) ) exitWith { true};
  } forEach [4,5,7,11]; // FFV seats clipping the stretcher

  if (_blockedByFFV) then {
    _result = false;
  } else {
    // Unlock cargo
    if (_animName == "Top stretcher") then {
      _heli lockCargo [10, false];
    } else {
      _heli lockCargo [11, false];
    };
    // Lock FFV
    {
      _heli lockTurret [_x, true];
    } forEach [4,5,7,11];
  }
} else { // Raised
  private _blockedByStretcherOccupant = false;
  _blockedByStretcherOccupant = {
    _x params ["_unit", "_role", "_cargoIndex", "_turretPath", "_personTurret"];
    if (
      _cargoIndex in [10, 11]
      && {!isNull _unit}
      && {_role == "cargo"}
      && {_turretPath isEqualTo []}
      && {!_personTurret}
    ) exitWith { true};
  } forEach (fullCrew [_vehicle, "cargo"]); // FFV seats clipping the stretcher

  if (_blockedByStretcherOccupant) then {
    _result = false;
  } else {
    // Lock cargo
    if (_animName == "Top stretcher") then {
      _heli lockCargo [10, true];
    } else {
      _heli lockCargo [11, true];
    };
    // Unlock FFV
    if (
      (_animName == "Top stretcher" && {_heli animationPhase "StretcherRack_Fold_B" == 1})
      || (_animName == "Bottom stretcher" && {_heli animationPhase "StretcherRack_Fold_T" == 1})
    ) then {
      {
        _heli lockTurret [_x, false];
      } forEach [4,5,7,11];
    };
  }
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
