params ["_vehicle"]; 

[_vehicle, ["startup", "b_gen1"], "ON"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_gen2"], "ON"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;

[_vehicle, ["startup", "b_batt1"], "ON"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_batt2"], "ON"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;

[_vehicle, ["startup", "fuelPump"], "APU BOOST"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "apucont"], "ON"] call vxf_interaction_fnc_scriptedInteract;		sleep 0.5;
sleep 12;

[_vehicle, ["startup", "b_apugen"], "ON"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_stbyinst"], "ARM"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
 
[_vehicle, ["startup", "b_ignition"], "ON"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_airsce"], "APU"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_fuelsys1"], "DIR"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_fuelsys2"], "DIR"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
sleep 1;  
[_vehicle, ["startup", "b_starter1"]] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "powerContRTD", "b_engpowercont1"], "IDLE"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_starter2"]] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "powerContRTD", "b_engpowercont2"], "IDLE"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
 
sleep 5;  
[_vehicle, ["startup", "powerContRTD", "b_engpowercont1"], "FLY"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "powerContRTD", "b_engpowercont2"], "FLY"] call vxf_interaction_fnc_scriptedInteract;  sleep 0.5;
sleep 15;  
[_vehicle, ["startup", "apucont"], "OFF"] call vxf_interaction_fnc_scriptedInteract;
_vehicle setObjectTextureGlobal ["markings","\z\vtx\addons\uh60_misc\data\markings\markings_studentdriver.paa"];
_vehicle setVariable ["vtx_autostarted", true];

[QGVAR(autostarted), _vehicle] call CBA_fnc_localEvent;
