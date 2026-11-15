/*
 * hct_h60_acre_fnc_fmsSetPreset
 *
 * changes radio channel based on selected preset
 *
 *
 */
params ["_vehicle", "_radioIndex", "_presetIndex", ["_pageData", nil]];

private _radio = [_vehicle, _radioIndex] call hct_h60_acre_fnc_getRadio;
if (_radio isEqualTo "") exitWith {}; // rack or radio not there yet
private _channel = fms_comm_presets_page_index * 4 + _presetIndex;

[_radio, _channel] call acre_api_fnc_setRadioChannel;
_vehicle setUserMFDValue _pageData;

[_vehicle] call hct_h60_fms_fnc_perSecond;
[_vehicle] call hct_h60_acre_fnc_notifyOtherSeat;
