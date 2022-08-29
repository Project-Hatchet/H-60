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


private _eng1Np    = _heli getVariable "vtx_uh60_sfmplus_engPctNP" select 0;
private _eng2Np    = _heli getVariable "vtx_uh60_sfmplus_engPctNP" select 1;
private _rtrRPM    = _eng1Np max _eng2Np;
// _rtrRPM = 0.69;
if (_rtrRPM > 0 && _rtrRPM < 0.7) then {
    private _adjustedAnimRPM = vtx_uh60_rotorRPM * 20;
    private _realRPM = _heli animationPhase "rotortilt";
    systemChat str [_realRPM / 10, _rtrRPM];
    if ((_realRPM / 10) > _rtrRPM) then {
        systemchat "BREAKING";
        // _heli setHitpointDamage ["HitHRotor", 0.9];
        _heli engineOn false;
    } else {
        systemchat "FIXING";
        // _heli setHitpointDamage ["HitHRotor", 0];
        _heli engineOn true;
    };
};
// systemChat str ["RPM", _rtrRPM];
