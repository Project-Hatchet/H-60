/*
 * Author: Ampersand
 * Geolock the pilotCamera to where it is curerntly pointing, used for tracking while slewing since object detection would cause it to be unable to slew off a large building
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_flir_fnc_trackPilotCamera
 */
//vtx_uh60_flir_fnc_trackPilotCamera={
private _heli = vehicle player;

private _flirPos = getPilotCameraPosition _heli;
private _flirPosWorld = _heli modelToWorldVisual _flirPos;
private _slewDir = (getPilotCameraDirection _heli) vectorMultiply 5000;
private _position1 = _heli modelToWorldVisual (_flirPos vectorAdd _slewDir);
private _intersections = lineIntersectsSurfaces [AGLToASL _flirPosWorld, AGLToASL _position1, _heli];
if !((_intersections # 0) isEqualTo []) then {
    (_intersections # 0) params ["_intersectPosASL"];
    _heli setPilotCameraTarget _intersectPosASL;
    [_intersectPosASL] call vtx_uh60_flir_fnc_syncAnimation;
    [_slewDir, _intersectPosASL] call vtx_uh60_flir_fnc_syncPilotCamera;
};

true
