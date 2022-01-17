/*
 * vtx_uh60_engine_fnc_startStopHandler
 *
 * handles aircraft engine on and off events called by the player via the scroll menu
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle", "_player", "", "_action"];

if((!local _vehicle) || (!(_vehicle isKindOf "vtx_H60_base"))) exitWith{false};

if(!vtx_uh60m_simpleStartup) exitWith {systemChat "Simple Startup is not enabled";true};

if(_action == "EngineOn") exitWith {
  [_vehicle] spawn vtx_uh60_engine_fnc_autoStart;
  _lastSimpleStart = missionNamespace getVariable ['vtx_uh60_lastSimpleStart', -10];
  vtx_uh60_lastSimpleStart = time;
  true
};

if(_action == "EngineOff") exitWith {
  [_vehicle] spawn vtx_uh60_engine_fnc_autoStop;
  true
};

false

