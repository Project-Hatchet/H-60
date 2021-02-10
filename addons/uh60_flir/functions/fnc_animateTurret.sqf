/*
 * Author: Ampersand
 * Align the local copilot turret to the local pilotCamera
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_flir_fnc_animateTurret
 */
//vtx_uh60_flir_fnc_animateTurret={

params ["_heli"];
if (vtx_uh60_flir_isCopilotInGunnerView || {!(_heli turretLocal [0]) || {isNull (_heli turretUnit [0])}}) exitWith { false };

private _flirPos = getPilotCameraPosition _heli;
private _flirPosWorld = _heli modelToWorldVisual _flirPos;
private _slewDir = (getPilotCameraDirection _heli) vectorMultiply 5000;
private _position1 = _heli modelToWorldVisual (_flirPos vectorAdd _slewDir);
private _intersections = lineIntersectsSurfaces [AGLToASL _flirPosWorld, AGLToASL _position1, _heli];
if !((_intersections # 0) isEqualTo []) then {
    (_intersections # 0) params ["_intersectPosASL"];
    _heli lockCameraTo [_intersectPosASL, [0]];
};

true
