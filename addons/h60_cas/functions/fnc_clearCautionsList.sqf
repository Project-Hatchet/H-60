/*
 * hct_h60_cas_fnc_clearCautionsList
 *
 * clears clearable master cautions
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle", ["_autoClearOnly", false]];

// a copy: removeCautionAdvisory deletes from the vehicle's list (the same
// array), which would skip the entry after each one removed
private _casList = +(_vehicle getVariable ["hct_cas_list",[]]);

{ // forEach _casList;
    _x params ["_text", "_condition", "_autoClear"];
    if (_autoClear || {!_autoClearOnly}) then {
        // an empty condition ({}, e.g. PARKING BRAKE) returns nothing: such an
        // entry is cleared by its owner, never by the list - keep it
        private _active = call _condition;
        if (!isNil "_active" && {!_active}) then {
            [_vehicle, _text] call hct_h60_cas_fnc_removeCautionAdvisory;
        };
    };
} forEach _casList;
if(!_autoClearOnly) then {
    [_vehicle, false] call hct_h60_cas_fnc_setMasterCaution;
};
