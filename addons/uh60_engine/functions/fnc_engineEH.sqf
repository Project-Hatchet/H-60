/*
 * vtx_uh60_engine_fnc_engineEH
 *
 * engine power eventhandler
 *
 * params (array)[(object) vehicle, (bool) turnedOn]
 */

params ["_vehicle", "_turnedOn", ["_lever","throttle"], "_animEndState", "_animName"];

if(_turnedOn) then {
  setCustomSoundController [_vehicle, 'CustomSoundController9', ((1 - (_vehicle animationPhase 'cabindoor_L')) / 2) + ((1 - (_vehicle animationPhase 'cabindoor_R')) / 2)];
  setCustomSoundController [_vehicle, 'CustomSoundController8', [((_vehicle animationSourcePhase 'Door_RF') + (_vehicle animationSourcePhase 'Door_LF')) / 2, 1] select ((_vehicle animationSourcePhase 'Cockpitdoors_Hide') > 0)];
};

//-Sound Handler
(_vehicle getVariable ["bmkhs_engState", ["OFF", "OFF"]]) params ["_eng1State", "_eng2State"];

private _rotorspeed = _vehicle getSoundController "RotorSpeed";

//- Play Sound Globally (rotorspeed must travel with the event - it was a
//- sender-local variable the receivers never had, so the start/shutdown
//- sound conditions errored on every remote client)
[
  "vtx_uh60_engine_playEngineSound",
  [_vehicle, [_eng1State,_eng2State], _rotorspeed]
] call CBA_fnc_globalEvent;

//engineOn is not set here - uh60_helisim decides it each frame from the start switches and
//power levers, and HeliSim runs the engines from it.
