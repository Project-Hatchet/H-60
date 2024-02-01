/*
 * vtx_uh60_engine_fnc_engineEH
 *
 * engine power eventhandler
 *
 * params (array)[(object) vehicle, (bool) turnedOn]
 */

/*
 diag_log format ["%1: engine EH", time];
*/
params ["_vehicle", "_turnedOn", ["_lever","throttle"], "_animEndState", "_animName"];

if(_turnedOn) then {
  setCustomSoundController [_vehicle, 'CustomSoundController9', ((1 - (_vehicle animationPhase 'cabindoor_L')) / 2) + ((1 - (_vehicle animationPhase 'cabindoor_R')) / 2)];
  setCustomSoundController [_vehicle, 'CustomSoundController8', [((_vehicle animationSourcePhase 'Door_RF') + (_vehicle animationSourcePhase 'Door_LF')) / 2, 1] select ((_vehicle animationSourcePhase 'Cockpitdoors_Hide') > 0)];
};

//-Sound Handler
(_vehicle getVariable ["vtx_uh60_sfmplus_engState", ["OFF", "OFF"]]) params ["_eng1State", "_eng2State"];

private _rotorspeed = _vehicle getSoundController "RotorSpeed";

//- Play Sound Globally
[[_vehicle,[_eng1State,_eng2State]], {
  params ["_vehicle","_Vars"];
  //-Engine Start
  if (({_x == "STARTING"} count _Vars > 0) && (_rotorspeed < 0.6)) then {
    [_vehicle,["vtx_soundEngineOnInt","vtx_soundEngineOnExt"],"ON",{(_vehicle getVariable ["vtx_uh60_sfmplus_engState", ["OFF", "OFF"]])},1] call vtx_uh60_Sound_fnc_EngineEH;
  };

  //-Engine Off
  if (({_x == "OFF"} count _Vars > 0) && (_rotorspeed != 0)) then {
    [_vehicle,["vtx_soundEngineOffInt","vtx_soundEngineOffExt"],"OFF",{(_vehicle getVariable ["vtx_uh60_sfmplus_engState", ["OFF", "OFF"]])},1] call vtx_uh60_Sound_fnc_EngineEH;
  };
}] remoteExecCall ['call', [0, -2] select isDedicated];

/////////////////////////////////
if (!local _vehicle) exitWith {};

_vehicle engineOn (_eng1State != "OFF" || _eng2State != "OFF");
