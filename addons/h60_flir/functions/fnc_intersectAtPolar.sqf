/*
 * hct_h60_flir_fnc_intersectAtPolar
 *
 * Ray-casts from a point along a polar direction in 1 km segments (lineIntersectsSurfaces is range-limited).
 *
 * params [(array) origin ASL, (number) azimuth, (number) elevation, (object) object to ignore (default: vehicle player)]
 *
 * returns [(array) position ASL, (object) hit object or objNull for terrain] or nil on no hit
 */

params ["_origin","_angleX","_angleY", ["_ignore", objNull, [objNull]]];
if (isNull _ignore) then { _ignore = vehicle player; }; // old behaviour for callers that pass none

scopeName "return";

private _vectorIntersect = [1050, _angleX, _angleY] call CBA_fnc_polar2vect;
private _vectorIntersectDir = vectorNormalized _vectorIntersect;

for "_i" from 0 to 15 step 1 do {
  private _startPos = _origin vectorAdd (_vectorIntersectDir vectorMultiply (_i * 1000));
  private _endPos = _startPos vectorAdd _vectorIntersect;
  private _intersect = lineIntersectsSurfaces [_startPos, _endPos, _ignore];
  if(count _intersect > 0) then {
    (_intersect # 0) params ["_intersectPos", "", "_hitObject", "_hitParent"];
    [_intersectPos, [_hitObject, _hitParent] select (!isNull _hitParent)] breakOut "return";
  };
};
