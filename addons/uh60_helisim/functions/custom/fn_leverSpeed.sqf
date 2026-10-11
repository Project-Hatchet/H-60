/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_leverSpeed

Description:
    Hatchet's animSpeedCode for a power lever: the speed of this move. IDLE to FLY takes
    the engine's leverTravelTime, as HeliSim's governor does; every other move HeliSim makes
    at once, and the lever takes a hand's pace (HAND_SECONDS). See docs/HATCHET.md.

Parameters:
    _args   - Hatchet's arguments: [vehicle, animation, target label, target phase,
              current phase] [Array]
    _engine - The lever's engine, 0-based [Number]

Returns:
    Hatchet's animation speed, phase per second [Number]
---------------------------------------------------------------------------- */
#define HAND_SECONDS 0.5

params ["_args", "_engine"];
_args params ["_heli", "", "_label", "_target", "_phase"];

private _seconds = HAND_SECONDS;
if (_label == "FLY") then {
    //Core's own value - published by coreConfig, or the declaration it reads where it has not run
    private _engines = _heli getVariable ["bmkhs_engines", []];
    _seconds = if (_engine < count _engines) then {
        (_engines # _engine) get "leverTravelTime"
    } else {
        getNumber ((("true" configClasses (configOf _heli >> "BMKHS_HeliSim" >> "Engines")) # _engine) >> "Governor" >> "leverTravelTime")
    };
};

(abs (_target - _phase)) / (_seconds max 0.01)
