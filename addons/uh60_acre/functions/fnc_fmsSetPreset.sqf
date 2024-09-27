/*
 * vtx_uh60_acre_fnc_fmsSetPreset
 *
 * changes radio channel based on selected preset
 *
 * 
 */
params ["_vehicle", "_radioIndex", "_presetIndex", ["_pageData", nil]];

_racks = [_vehicle] call acre_sys_rack_fnc_getVehicleRacks;
_radio = [_racks # _radioIndex] call acre_sys_rack_fnc_getMountedRadio;
_channel = fms_comm_presets_page_index * 4 + _presetIndex;

[_radio, _channel] call acre_api_fnc_setRadioChannel;
_vehicle setUserMFDvalue _pageData;

[_vehicle] call vtx_uh60_fms_fnc_perSecond;