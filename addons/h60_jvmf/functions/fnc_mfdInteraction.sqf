/*
 * hct_h60_jvmf_fnc_mfdInteraction
 *
 * Hanldes mfd interaction
 */

params ["_vehicle", "_subject", "_value"];

if (_subject == "cycle") then {
    hct_jvmf_selected_idx = (hct_jvmf_selected_idx + _value) max 0 min ((count hct_jvmf_messages) - 1);
    [_vehicle] call hct_h60_jvmf_fnc_drawJVMF;
};
if (_subject == "waypt" && {hct_jvmf_selected_idx >= 0} && {hct_jvmf_selected_idx < count hct_jvmf_messages}) then {
    private _message = hct_jvmf_messages # hct_jvmf_selected_idx;
    _message params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];
    private _wayptId = format ["JVMF%1%2", _sender, hct_jvmf_selected_idx];
    if (_type == 2) then {
        _data params ["_position"];
        if ([_wayptId] call hct_h60_fms_fnc_hasWaypoint) then {
            [player, _wayptId] call hct_h60_fms_fnc_selectWaypoint;
        } else {
            [_text # 2, _position, _wayptId] call hct_h60_fms_fnc_addWaypoint;
        };
    };
};
