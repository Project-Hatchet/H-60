/*
 * vtx_uh60_engine_fnc_autoStop
 *
 * Shuts down aircraft. Called via simple start mode
 *
 * params (object) vehicle
 */

params ["_vehicle"];
[_vehicle, ["startup", "b_fuelsys1"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "b_fuelsys2"], "OFF"] call vxf_interaction_fnc_scriptedInteract;

sleep 1;

[_vehicle, ["startup", "b_gen1"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "b_gen2"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "b_batt1"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "b_batt2"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "fuelPump"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "apucont"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "b_apugen"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "b_stbyinst"], "OFF"] call vxf_interaction_fnc_scriptedInteract;

[_vehicle, ["startup", "b_ignition"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "b_airsce"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "b_fuelsys1"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "b_fuelsys2"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "powerContRTD", "b_engpowercont1"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
[_vehicle, ["startup", "powerContRTD", "b_engpowercont2"], "OFF"] call vxf_interaction_fnc_scriptedInteract;



