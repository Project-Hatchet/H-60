/*
 * vtx_uh60_jvmf_fnc_mfdInteraction
 *
 * Hanldes mfd interaction
 */

params ["_vehicle", "_subject", "_value"];

if (_subject == "cycle") then {
    vtx_jvmf_selected_idx = (vtx_jvmf_selected_idx + _value) max 0 min ((count vtx_jvmf_messages) - 1);
    [_vehicle] call vtx_uh60_jvmf_fnc_drawJVMF;
};
if (_subject == "waypt") then {
    private _message = vtx_jvmf_messages # vtx_jvmf_selected_idx;
    _message params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];
    private _wayptId = format ["JVMF%1%2", _sender, vtx_jvmf_selected_idx];
    if (_type == 2) then {
        _data params ["_position"];
        if ([_wayptId] call vtx_uh60_fms_fnc_hasWaypoint) then {
            [player, _wayptId] call vtx_uh60_fms_fnc_selectWaypoint;
        } else {
            [_text # 2, _position, _wayptId] call vtx_uh60_fms_fnc_addWaypoint;
        };
    };
};
