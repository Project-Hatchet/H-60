/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_engineController

Description:
	Monitors and controls engine states.

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

private _engState  = _heli getVariable "vtx_uh60_sfmplus_engState";
private _eng1State = _engState select 0;
private _eng2State = _engState select 1;

if ((_eng1State == "STARTING" || _eng2State == "STARTING") && local _heli) then {
	_heli setVariable ["vtx_uh60_estarted", true, true];
	// _heli engineOn true;
};

private _isSingleEng     = _heli getVariable "vtx_uh60_sfmplus_isSingleEng";
private _engPwrLvrState  = _heli getVariable "vtx_uh60_sfmplus_engPowerLeverState";
private _eng1PwrLvrState = _engPwrLvrState select 0;
private _eng2PwrLvrState = _engPwrLvrState select 1;

if ((_eng1PwrLvrState isEqualTo _eng2PwrLvrState) && (_eng1State == "ON" && _eng2State == "ON")) then {
	_isSingleEng = false;
} else {
	_isSingleEng = true;
};
_heli setVariable ["vtx_uh60_sfmplus_isSingleEng", _isSingleEng];

if (isMultiplayer && local _heli && (_heli getVariable "vtx_uh60_sfmplus_lastTimePropagated") + 5 < time) then {
	{
		_heli setVariable [_x, _heli getVariable _x, true];
	} forEach [
		"vtx_uh60_sfmplus_engFF",
		"vtx_uh60_sfmplus_engBaseNG",
		"vtx_uh60_sfmplus_engPctNG",
		"vtx_uh60_sfmplus_engBaseNP",
		"vtx_uh60_sfmplus_engPctNP",
		"vtx_uh60_sfmplus_engBaseTQ",
		"vtx_uh60_sfmplus_engPctTQ",
		"vtx_uh60_sfmplus_engBaseTGT",
		"vtx_uh60_sfmplus_engTGT",
		"vtx_uh60_sfmplus_engBaseOilPSI",
		"vtx_uh60_sfmplus_engOilPSI"
	];
	_heli setVariable ["vtx_uh60_sfmplus_lastTimePropagated", time, true];
};

[_heli, 0, _deltaTime] call vtx_uh60_sfmplus_fnc_engine;
[_heli, 1, _deltaTime] call vtx_uh60_sfmplus_fnc_engine;

private _no1EngDmg = _heli getHitPointDamage "hitengine1";
private _no2EngDmg = _heli getHitPointDamage "hitengine2";

if (_no1EngDmg > 0.5) then {
	[_heli, "vtx_uh60_sfmplus_engState", 0, "OFF", true] call vtx_uh60_sfmplus_fnc_setArrayVariable;
};

if (_no2EngDmg > 0.5) then {
	[_heli, "vtx_uh60_sfmplus_engState", 1, "OFF", true] call vtx_uh60_sfmplus_fnc_setArrayVariable;
};

if (_eng1State == "OFF" && _eng2State == "OFF" && local _heli) then {
	_heli setVariable ["vtx_uh60_estarted", false, true];
	// _heli engineOn false;
};

private _eng1Np    = _heli getVariable "vtx_uh60_sfmplus_engPctNP" select 0;
private _eng2Np    = _heli getVariable "vtx_uh60_sfmplus_engPctNP" select 1;
private _rtrRPM    = _eng1Np max _eng2Np;
private _realRPM = _heli animationPhase "rotortilt";
private _lastUpdate = _heli getVariable ["vtx_uh60_sfmplus_lastUpdate", 0];
if (cba_missionTime > _lastUpdate + 0.3 && _rtrRPM > 0.05) then {
	systemChat str [_realRPM / 11, _rtrRPM];
	_rtrRPM = _rtrRPM - (vtx_uh60_sfmplus_liftLossTimer * 0.45); 
	systemChat str ["ADJUSTED RPM", _rtrRPM];
	if ((_realRPM / 11) > _rtrRPM) then {
		// systemchat "BREAKING ROTOR";
		_heli setHitpointDamage ["HitHRotor", 0.9];
		// _heli engineOn false;
	} else {
		// systemchat "FIXING ROTOR";
		_heli setHitpointDamage ["HitHRotor", 0];
		_heli engineOn true;
	};
	_heli setVariable ["vtx_uh60_sfmplus_lastUpdate", cba_missionTime];
};