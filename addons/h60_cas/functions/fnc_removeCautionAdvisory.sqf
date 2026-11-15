/*
 * hct_h60_cas_fnc_removeCautionAdvisory
 *
 * removes a caution/advisory in the cas system
 *
 * params (array)[(object) vehicle,(string) text]
 */

params ["_vehicle", ["_text",""]];

if (isNil "hct_h60_cas_cautionsLog") then {hct_h60_cas_cautionsLog = []};

private _casList = (_vehicle getVariable ["hct_cas_list",[]]);
private _listIndex = _casList findIf {(_x # 0) == _text};
private _logIndex = hct_h60_cas_cautionsLog find _text;

// Nothing to remove: skip the MFD redraws. The once-a-second callers
// (updateCautions, wheel brakes) mostly ask for entries that are not there,
// and every change that does need a redraw makes its own.
if (_listIndex == -1 && {_logIndex == -1}) exitWith {};

if (_listIndex > -1) then {
    _casList deleteAt _listIndex;
};
if (_logIndex > -1) then {
    hct_h60_cas_cautionsLog deleteAt _logIndex;
    hct_h60_cas_cautionsUnacked = (hct_h60_cas_cautionsUnacked - 1) max 0;
};

_vehicle setVariable ["hct_cas_list", _casList];
[_vehicle] call hct_h60_cas_fnc_updateCautionsList;
[_vehicle,false] call hct_h60_cas_fnc_updateOverlayList;
