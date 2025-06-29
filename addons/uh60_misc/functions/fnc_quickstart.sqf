params ["_vehicle"];

[_vehicle, ["startup", "b_gen1"], "ON"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_gen2"], "ON"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;

[_vehicle, ["startup", "b_batt1"], "ON"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_batt2"], "ON"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;

[_vehicle, ["startup", "fuelPump"], "APU BOOST"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "apucont"], "ON"] call hct_interaction_fnc_scriptedInteract;		sleep 0.5;
sleep 12;

[_vehicle, ["startup", "b_apugen"], "ON"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_stbyinst"], "ARM"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;

[_vehicle, ["startup", "b_ignition"], "ON"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_airsce"], "APU"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_fuelsys1"], "DIR"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_fuelsys2"], "DIR"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
sleep 1;
[_vehicle, ["startup", "b_starter1"]] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "powerContRTD", "b_engpowercont1"], "IDLE"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "b_starter2"]] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "powerContRTD", "b_engpowercont2"], "IDLE"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;

sleep 5;
[_vehicle, ["startup", "powerContRTD", "b_engpowercont1"], "FLY"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
[_vehicle, ["startup", "powerContRTD", "b_engpowercont2"], "FLY"] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
sleep 15;
[_vehicle, ["startup", "apucont"], "OFF"] call hct_interaction_fnc_scriptedInteract;
_vehicle setObjectTextureGlobal ["markings","\z\vtx\addons\uh60_misc\data\markings\markings_studentdriver.paa"];
_vehicle setVariable ["vtx_autostarted", true];

["vtx_uh60_misc_autoStarted", _vehicle] call CBA_fnc_localEvent;
