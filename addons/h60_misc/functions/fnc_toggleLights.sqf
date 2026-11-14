/*
 * vtx_uh60_misc_fnc_toggleLights
 *
 * Applies the exterior/interior light state, optionally flipping the landing or
 * search light first. The aircraft's own animation sources (LandingLight_Show,
 * SearchLight_Show) are the state: any crew seat reads and flips the same value,
 * and a crew member who boards later sees what is actually lit. (They were
 * per-player globals, so the two pilots switched each other's lights off.)
 *
 * animateSource and setPilotLight only take effect for everyone where the
 * aircraft is local, so a toggle from another machine is forwarded to the owner.
 *
 * params (array)[(object) vehicle, (string) light to flip: "landing", "search" or ""]
 */

params [["_vehicle", objNull, [objNull]], ["_light", "", [""]]];
if (isNull _vehicle) exitWith {};

if (!local _vehicle) exitWith {
    ["vtx_uh60_misc_toggleLights", [_vehicle, _light], _vehicle] call CBA_fnc_targetEvent;
};

private _landing = (_vehicle animationSourcePhase "LandingLight_Show") > 0.5;
private _search  = (_vehicle animationSourcePhase "SearchLight_Show") > 0.5;
switch (_light) do {
    case "landing": { _landing = !_landing; };
    case "search": { _search = !_search; };
};

private _cockpit  = _vehicle animationPhase "Switch_lights_cockpit" > 0.5;
private _position = _vehicle animationPhase "Switch_lights_position" > 0.5;

_vehicle animateSource ["LandingLight_Show", [0, 1] select _landing];
_vehicle animateSource ["SearchLight_Show", [0, 1] select _search];
_vehicle animateSource ["CockpitLight_Show", [0, 1] select _cockpit];
_vehicle animateSource ["CabinLight_Show", [0, 1] select _cockpit];
_vehicle animateSource ["PositionLight_Show", [0, 1] select _position];

private _isLightOn = _landing || {_search} || {_position} || {_cockpit};
if (_isLightOn isNotEqualTo isLightOn _vehicle) then {
    _vehicle setPilotLight _isLightOn;
};
