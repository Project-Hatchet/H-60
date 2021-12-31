/* ----------------------------------------------------------------------------
Function: vtx_sfmplus_fnc_aeroStabilator

Description:
    Creates a stabilator object which automatically schedules as a function of
    collective position and airspeed.

Parameters:
	_heli      - The helicopter to get information from [Unit].
    _deltaTime - Passed delta time from core update.

Returns:
    ...

Examples:
    ...

Author:
	BradMick
---------------------------------------------------------------------------- */
params ["_heli", "_deltaTime"];

private _config = configFile >> "CfgVehicles" >> typeof _heli >> "vtx_SfmPlus";

if (!local _heli) exitWith {};

private _colorRed = [1,0,0,1]; private _colorGreen = [0,1,0,1]; private _colorBlue = [0,0,1,1]; private _colorWhite = [1,1,1,1];

DRAW_LINE = {
	params ["_heli", "_p1", "_p2", "_col"];
	drawLine3D [_heli modelToWorldVisual _p1, _heli modelToWorldVisual _p2, _col];
};

private _objCtr  = _heli selectionPosition ["modelCenter", "Memory"];
private _stabPos = _heli getVariable "vtx_sfmplus_stabPos";
private _stabPvt = _objCtr vectorAdd _stabPos;

private _intStabTable = [getArray (_config >> "stabTable"), vtx_sfmplus_collectiveOutput] call vtx_fnc_linearInterp;

private _stabOutputTable = [[15.43, _intStabTable select 1],  //30kts
							[36.01, _intStabTable select 2],  //70kts
							[46.30, _intStabTable select 3],  //90kts
							[56.59, _intStabTable select 4],  //110kts
							[61.73, _intStabTable select 5],  //120kts
                            [77.17, _intStabTable select 6]]; //150kts

private _V_mps = abs vectorMagnitude [velocity _heli select 0, velocity _heli select 1];
private _theta = 0.0;
if (vtx_uh60_sfmPlusKeyboardOnly) then {
    _theta = getNumber (_config >> "stabKeyTheta");
    //systemChat format ["Stab keyboard!"];
} else {
    _theta = [_stabOutputTable, _V_mps] call vtx_fnc_linearInterp select 1;
    //systemChat format ["Stab joystick!"];
};

//Stab coords    |     |
//               |-----|
//    A-------------H-------------B
//    |             |             |
//    E-------------G-------------F
//    |             |             |
//    D-------------I-------------C
private _width  = _heli getVariable "vtx_sfmplus_stabWidth";
private _length = _heli getVariable "vtx_sfmplus_stabLength";

private _halfWidth = _width / 2;

private _A = _stabPvt vectorAdd [-_halfWidth, 0, 0];
private _B = _stabPvt vectorAdd [_halfWidth, 0, 0];
private _C = _stabPvt vectorAdd [_halfWidth, cos _theta * (-_length), sin _theta * _length];
private _D = _stabPvt vectorAdd [-_halfWidth, cos _theta * (-_length), sin _theta * _length];

private _E = (_A vectorAdd _D) vectorMultiply 0.5;
private _F = (_B vectorAdd _C) vectorMultiply 0.5;
private _G = (_E vectorAdd _F) vectorMultiply 0.5;

private _H = (_A vectorAdd _B) vectorMultiply 0.5;
private _I = (_D vectorAdd _C) vectorMultiply 0.5;

private _liftLine  = _E vectorDiff _F;
private _chordLine = _H vectorDiff _I;

private _liftVec = vectorNormalized (_chordLine vectorCrossProduct _liftLine);
_liftVec = _liftVec;

private _stabLine = vectorNormalized _chordLine;
_stabLine = _stabLine;

private _relWind = vectornormalized(_heli vectorWorldToModel (velocity _heli));
_relWind = _relWind;

private _AoA = (_relWind # 2 atan2 _relWind # 1) + _theta;
_AoA = [_AoA] call CBA_fnc_simplifyAngle180;

private _intAirfoilTable = [getArray (_config >> "stabAirfoilTable"), _AoA] call vtx_fnc_linearInterp;
private _CL = _intAirfoilTable select 1;

private _area = [_A, _B, _C, _D] call vtx_sfmplus_fnc_getArea;
private _liftForce = -_CL * 0.5 * 1.225 * _area * (_V_mps * _V_mps);

private _lift = _liftVec vectorMultiply (_liftForce * _deltaTime);
_heli addForce[_heli vectorModelToWorld _lift, _G];

#ifdef __A3_DEBUG__
/*
hintsilent format ["Collective Out = %1
                   \nStab Pos = %2
                   \nCollective Low = %3
                   \nCollective High = %4", _collOut, _theta, inputAction "HeliCollectiveLowerCont", inputAction "HeliCollectiveRaiseCont"];
*/
[_heli, _objCtr, _stabPvt, _colorWhite] call DRAW_LINE;

//Draw the stabilator
[_heli, _A, _B, _colorWhite] call DRAW_LINE;
[_heli, _B, _C, _colorWhite] call DRAW_LINE;
[_heli, _C, _D, _colorWhite] call DRAW_LINE;
[_heli, _D, _A, _colorWhite] call DRAW_LINE;
//Draw the fwd chord line originating from the pivot
[_heli, _H, _H vectorAdd _stabLine, _colorWhite] call DRAW_LINE;
//Draw the lift line
[_heli, _E, _F, _colorGreen] call DRAW_LINE;
//Draw the lift vector
[_heli, _G, _G vectorAdd _liftVec, _colorBlue] call DRAW_LINE;
//Draw the velocity vector
[_heli, _H, _H vectorAdd _relWind, _colorRed] call DRAW_LINE;
#endif