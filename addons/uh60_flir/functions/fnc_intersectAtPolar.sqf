params ["_origin","_angleX","_angleY"];

scopeName "return";

private _vectorIntersect = [950, _angleX, _angleY] call CBA_fnc_polar2vect;
private _vectorIntersectDir = vectorNormalized _vectorIntersect;

for "_i" from 0 to 15 step 1 do {
  private _startPos = _origin vectorAdd (_vectorIntersectDir vectorMultiply (_i * 1000));
  private _endPos = _startPos vectorAdd _vectorIntersect;
  private _intersect = terrainIntersectAtASL  [_startPos, _endPos];
  if(!([0,0,0] isEqualTo _intersect)) then {
	  systemChat str _intersect;
    _intersect breakOut "return";
  };
};