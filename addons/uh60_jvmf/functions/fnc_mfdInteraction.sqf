/*
 * vtx_uh60_jvmf_fnc_mfdInteraction
 *
 * Hanldes mfd interaction
 */

params ["_vehicle", "_subject", "_value"];

if (_subject == "cycle") then {
    VTX_JVMF_SELECTED_IDX = (VTX_JVMF_SELECTED_IDX + _value) max 0 min ((count VTX_JVMF_MESSAGES) - 1);
    [_vehicle] call vtx_uh60_jvmf_fnc_drawJVMF;
};
