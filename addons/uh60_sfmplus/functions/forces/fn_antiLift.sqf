/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_antiLift

Description:
	Applies a negative lift force if the player attempts to takeoff with the
    engines at idle.

Parameters:
	_heli - The helicopter to get information from [Unit].

Returns:
	...

Examples:
	...

Author:
	BradMick
---------------------------------------------------------------------------- */
params ["_heli", "_deltaTime"];

if (isEngineOn _heli) then {
    private _objCtr     = _heli selectionPosition ["modelCenter", "Memory"];
    private _forcePos   = _heli getVariable "vtx_uh60_sfmplus_forcePos";
    private _forcePoint = _objCtr vectorAdd _forcePos;
    private _forceVec   = vectorNormalized (_forcePoint vectorDiff _objCtr);

    private _eng1Np    = _heli getVariable "vtx_uh60_sfmplus_engPctNP" select 0;
    private _eng2Np    = _heli getVariable "vtx_uh60_sfmplus_engPctNP" select 1;
    private _rtrRPM    = _eng1Np max _eng2Np;
    private _forceMult = linearConversion[0.0, 0.98, _rtrRPM, 1.0, 0.0];

    private _negLiftForce = ((_curMass * -9.806) * _forceMult) * vtx_uh60_sfmplus_collectiveOutput;
    private _negLift = _forceVec vectorMultiply (_negLiftForce * _deltaTime);
    _heli addForce[_heli vectorModelToWorld _negLift, _forcePos];


    #ifdef __A3_DEBUG__
    //Draw the force vector
    [_heli, _objCtr, _forcePoint, _colorGreen] call DRAW_LINE;

    #endif
};