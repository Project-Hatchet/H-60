/*
#define PREP(var1) TRIPLES(ADDON,fnc,var1) = { call compile preProcessFileLineNumbers '\MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT_F\functions\DOUBLES(fnc,var1).sqf' }

PREP(setup);
PREP(perFrame);
*/
vtx_uh60_sfmplus_fnc_perFrame = { call compile preProcessFileLineNumbers '\z\vtx\addons\uh60_sfmplus\functions\fnc_perFrame.sqf' };
vtx_uh60_sfmplus_fnc_setUp     = { call compile preProcessFileLineNumbers '\z\vtx\addons\uh60_sfmplus\functions\fnc_setUp.sqf' };