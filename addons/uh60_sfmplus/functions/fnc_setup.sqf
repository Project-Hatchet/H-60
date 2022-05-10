// vtx_uh60_sfmplus_fnc_setup
params ["_vehicle"];

vtx_uh60_sfmplus_mass = getMass _vehicle;
[_vehicle] call vtx_uh60_sfmplus_fnc_coreConfig;

true