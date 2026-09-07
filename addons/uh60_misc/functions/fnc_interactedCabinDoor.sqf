/*
 * Author: BroBeans
 * Complete the cabin door opening/closing process from the hatchet interaction.
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [_vehicle, _anim] call vtx_uh60_misc_fnc_interactedCabinDoor
 */
params ["_vehicle", "_animName", "_animPhase"];

private _side = str _animName select [count _animName, 1]; // Match "L" or "R"
private _doorSeats = [];
{
    private _gunnerName = getText (_x >> "gunnerName");
    if (_gunnerName select [0, 5] == "Door " && {
        (_gunnerName select [5, 1]) == _side // Match "L" or "R"
    }) then {
        _doorSeats pushBack [_forEachIndex];
    };
} forEach ("true" configClasses (configOf _vehicle >> "Turrets"));

{
    _vehicle lockTurret [_x, (_animPhase == "Closed")];
} forEach _doorSeats;

[[_vehicle, 'CustomSoundController9', ((1 - (_vehicle animationPhase 'cabindoor_L')) + (1 - (_vehicle animationPhase 'cabindoor_R'))) / 2]] remoteExecCall ['setCustomSoundController', crew _vehicle];
