/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_getArea

Description:
	Returns the area of a four point polygon.

Parameters:
	_A, _B, _C, _D 

Returns:
	...

Examples:
	...

Author:
	BradMick
---------------------------------------------------------------------------- */
params ["_A","_B","_C","_D"];

private _AB = vectorMagnitude (_B vectorDiff _A);
private _BC = vectorMagnitude (_B vectorDiff _C);
private _CD = vectorMagnitude (_C vectorDiff _D);
private _DA = vectorMagnitude (_A vectorDiff _D);

private _s = (_AB + _BC + _CD + _DA) * 0.5;
private _A2 = (_s - _AB) * (_s - _BC) * (_s - _CD) * (_s - _DA);

//Return area
sqrt _A2;


