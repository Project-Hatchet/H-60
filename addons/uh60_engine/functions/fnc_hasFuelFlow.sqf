/*
 * vtx_uh60_engine_fnc_hasFuelFlow
 *
 * Checks if there is sufficient fuel flow for an engine to operate
 *
 * Params: (array)[(object) vehicle, (string)fuelSysLever]
 */

params ["_vehicle", "_fuelSysLever", "_boosterSwitch"];

private _altASLKFt = ((getPosASL player) # 2) * 3.28 / 1000;
private _boosterEnabled = (_vehicle animationPhase _boosterSwitch) == 0;

private _isCrossFeed = (_vehicle animationPhase _fuelSysLever) == 1;
private _isFuelFeed = (_vehicle animationPhase _fuelSysLever) > 0.5;

private _fuelFlow = 1;

if (!(_isFuelFeed)) exitWith {0};
if (_isCrossFeed && !(_boosterEnabled)) then {_fuelFlow = _fuelFlow / 2};
if (_altASLKFt > 5 && !(_boosterEnabled)) then {
    private _altOverMin = (_altASLKFt - 5);
    private _altDivision = (_altOverMin / 2) max 1;
    if(vtx_uh60_ui_showDebugMessages) then {systemChat str [_altOverMin, _altDivision];};
    _fuelFlow = _fuelFlow / _altDivision;
};

_fuelFlow
