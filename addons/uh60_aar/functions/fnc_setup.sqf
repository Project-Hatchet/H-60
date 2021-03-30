/*
 * vtx_uh60_aar_fnc_setup
 *
 * Starts the air to air refueling module
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];
if (vtx_uh60m_disabled_aar) exitWith {false};

private _config = (_vehicle getVariable "vxf_config");
private _probePos = (_config >> "modules" >> "aar" >> "probePos") call BIS_fnc_getCfgData;
_vehicle setVariable ["vtx_aar_probePos", _probePos];
vtx_aar_probeCondition = compile (getText (_config >> "modules" >> "aar" >> "probeCondition"));
vtx_aar_probeDeployed = _vehicle call vtx_aar_probeCondition;
vtx_aar_transferRate = getNumber (_config >> "modules" >> "aar" >> "fillRate");
vtx_uh60_aar_basketSize = 2;

true;
