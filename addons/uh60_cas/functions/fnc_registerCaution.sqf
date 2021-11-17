params ["_vehicle"];

[_vehicle] call vtx_uh60_cas_fnc_updateCautionPanel;
_vehicle animate ["CautionMasterCaution",1];