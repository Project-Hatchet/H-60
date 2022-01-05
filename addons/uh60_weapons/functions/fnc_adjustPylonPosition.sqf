#include "script_component.hpp"
/*
 * Author: Ampersand
 * Adjust pylon forward and backwards
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 * 1: Unit <OBJECT>
 * 2: Side <NUMBER> 0: Left, 1: Right
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli, _player, 0] call vtx_uh60_weapons_fnc_adjustPylonPosition
 */

params ["_heli", "", "_side"];

private _anim = ["PylonForward_L", "PylonForward_R"] select _side;
GVAR(pylonPositionParams) = [_heli, _anim];
systemChat str GVAR(pylonPositionParams);
createDialog QGVAR(pylonPosition);
private _okButton = (findDisplay 7777) displayCtrl 1;
private _currentPos = _heli animationSourcePhase _anim;
_okButton ctrlSetText (format ["Pylon Position: %1 m", _currentPos]);

private _slider = (findDisplay 7777) displayCtrl 1900;
_slider sliderSetPosition _currentPos;
_slider ctrlAddEventHandler ["SliderPosChanged", {
    params ["_control", "_newValue"];
    (missionNamespace getVariable 'vtx_uh60_weapons_pylonPositionParams') params ['_v', '_a'];
    _v animateSource [_a, _newValue, true];
    private _okButton = (findDisplay 7777) displayCtrl 1;
    _okButton ctrlSetText format ["Pylon Position: %1 m", _newValue];
}];
