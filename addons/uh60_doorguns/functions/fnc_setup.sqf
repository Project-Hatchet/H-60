/*
 * vtx_uh60_doorguns_fnc_setup
 */

params ["_vehicle"];

vtx_m134_lastFired = cba_missionTime;
vtx_m134_ppEffects = [];
vtx_m134_ppEffectIntensity = 0;
vtx_m134_firedEh = _vehicle addeventhandler ["fired", {_this call vtx_uh60_doorguns_fnc_fired;}];

true
