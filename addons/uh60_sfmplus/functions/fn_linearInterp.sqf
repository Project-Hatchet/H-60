/* ----------------------------------------------------------------------------
Function: fza_fnc_linearInterp

Description:
	Performs linear interpolation given a 2d array of values.

	Each element in the array _arr is a "row" of values, upon which the first
	index is the one that we should match up with x. There can be unlimited
	values in those arrays, as long as they are all of equal length.

	Each value's index must be in ascending order.

Parameters:
	_arr - the aforementioned array
	_key - the value that should be interpolated

Returns:
	Array of results

Examples:
    --- Code
	_interpArray = [[0, -1, 4, 5], 
	                [2, -2, 6, 7], 
					[6, -5, 0, 14]]
	
	_badInterpArray = [[0, -1, 4, 5], 
	                   [6, -5, 0, 14], 
					   [2, -2, 6, 7]]
	//BAD, indexes are out of order

	_result = [_interpArray, 1] call fza_fnc_linearInterp
	//_result => [1, -1.5, 5, 6]

	_result = [_interpArray, -2] call fza_fnc_linearInterp //Below range
	//_result => [0, -1, 4, 5]
	
	_result = [_interpArray, 10] call fza_fnc_linearInterp //Above range
	//_result => [2, -2, 6, 7]
    ---

Author:
	mattysmith22
---------------------------------------------------------------------------- */
params["_arr", "_key"];

private _upperIndex = _arr findIf {
    _x select 0 > _key
}; //Find the index of the value above key

if (_upperIndex == 0) exitWith {
    _arr select 0;
}; //If it is below the values that can be interpolated

if (_upperIndex == -1) exitWith {
    _arr select(count _arr - 1);
}; //If it is below the values that can be interpolated

private _lowerIndex = _upperIndex - 1;

private _lowerRow = (_arr select _lowerIndex);
private _upperRow = (_arr select _upperIndex);

private _lerp = {
    params["_lowKey", "_highKey", "_lowVal", "_highVal", "_intendedKey"];
    _lowVal + (_highVal - _lowVal) / (_highKey - _lowKey) * (_intendedKey - _lowKey);
};

_out = []; {
    _out pushBack([_lowerRow select 0, _upperRow select 0, _x, _upperRow select _forEachIndex, _key] call _lerp);
}
forEach(_lowerRow);
_out;