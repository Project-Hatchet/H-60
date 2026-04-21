#include "..\script_component.hpp"
/*
 * Author: Ampersand
 * Draw IR lasers.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call vtx_uh60_weapons_fnc_irLaserPFH
 *
 */

#define LASER_MAX 3000

if (GVAR(laserEmitters) isEqualTo []) exitWith {
  GVAR(irLaserPFH) call CBA_fnc_removePerFrameHandler;
  GVAR(irLaserPFH) = -1;
};

{
  _x params ["_vehicle", "_begSel", "_endSel"];
  // [_vehicle, "memptPos", 0] // vehicle forward
  // [_vehicle, [x1, y1, z1], [x2, y2, z2]]
  // [_vehicle, "memptPos", "memptDir"]

  private _begPos = if (_begSel isEqualType []) then {
    _vehicle modelToWorldVisualWorld _begSel
  } else {
    _vehicle modelToWorldVisualWorld (_vehicle selectionPosition _begSel)
  };
  private _dir = if (_endSel isEqualTo 0) then {
    vectorDirVisual _vehicle
  } else {
    if (_endSel isEqualType []) then {
      _begPos vectorFromTo (_vehicle modelToWorldVisualWorld _endSel)
    } else {
      _begPos vectorFromTo (_vehicle modelToWorldVisualWorld (_vehicle selectionPosition _endSel))
    };
  };
  private _endPos = _begPos vectorAdd (_dir vectorMultiply LASER_MAX);

  private _intersects = [];
  while { _intersects isEqualTo [] } do {
    // drawLaser has an internal maximum distance it can draw, so we may need to draw multiple segments
    drawLaser [_begPos, _dir, [250, 0, 0, 1], [], 0, 1, LASER_MAX, true]; // Draw a segment
    if (
      (_begPos distance positionCameraToWorld [0,0,0]) > viewDistance
      && {(_endPos distance positionCameraToWorld [0,0,0]) > viewDistance}
    ) exitWith {}; // just exit loop if we've drawn far enough
    _intersects = lineIntersectsSurfaces [_begPos, _endPos, _aircraft];
    if (_intersects isEqualTo []) then { // Check if we hit anything
      _begPos = _endPos; // if we didn't then move up the startpos to where the last draw ended
      _endPos = _endPos vectorAdd (_dir vectorMultiply LASER_MAX);
    };
  };
  drawLaser [_begPos, _dir, [250, 0, 0, 1], [], 0.5, 1, LASER_MAX, true]; // final draw from actual origin
} forEach GVAR(laserEmitters);
