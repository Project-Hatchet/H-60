params ["_vehicle"];

private _firedEH = _vehicle getVariable ["vtx_uh60_doorguns_firedEH", -1];
if (_firedEH != -1) then {
    _vehicle removeEventHandler ["Fired", _firedEH];
    _vehicle setVariable ["vtx_uh60_doorguns_firedEH", -1];
};
