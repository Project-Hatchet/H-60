params ["_origin","_angleX","_angleY"];

scopeName "return";

private _vectorIntersect = [1050, _angleX, _angleY] call CBA_fnc_polar2vect;
private _vectorIntersectDir = vectorNormalized _vectorIntersect;

for "_i" from 0 to 15 step 1 do {
  private _startPos = _origin vectorAdd (_vectorIntersectDir vectorMultiply (_i * 1000));
  private _endPos = _startPos vectorAdd _vectorIntersect;
  private _intersect = lineIntersectsSurfaces [_startPos, _endPos, (vehicle player)];
  if(count _intersect > 0) then {
    (_intersect # 0 # 0) breakOut "return";
  };
};