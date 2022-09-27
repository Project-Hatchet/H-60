// vtx_uh60_sfmplus_fnc_setup
params ["_vehicle"];

[_vehicle] call vtx_uh60_sfmplus_fnc_coreConfig;
vtx_uh60_sfmplus_liftLossTimer = 0;
vtx_uh60_sfmplus_realMass = 1000;
vtx_uh60_sfmplus_massModifier = 0.5;

true