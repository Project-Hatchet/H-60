params ["_vehicle", "_frameTime"];
if (!vtx_aar_probeDeployed) exitWith {};
if (isNil "vtx_uh60_aar_basket") exitWith {};
private _rope = vtx_uh60_aar_basket getVariable "vtx_aar_rope";
private _tanker = vtx_uh60_aar_basket getVariable "vtx_aar_tanker";
[_vehicle, _tanker, vtx_uh60_aar_basket, _rope, _frameTime] call vtx_uh60_aar_fnc_handleConnection;
