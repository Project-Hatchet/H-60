/* ----------------------------------------------------------------------------
Function: vtx_uh60_sfmplus_fnc_damageApply

Description:
    Applies damage within a defined period of time after exceeding aircraft
    operating limits. 

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

private _rtrDmgHitName = "HitHRotor";
private _timeToMaxDmg  = 30;
private _dmgPerSec     = 1 / _timeToMaxDmg;
private _transientTime = 10;

private _pctNR         = (_heli getVariable "vtx_uh60_sfmplus_engPctNP" select 0) max (_heli getVariable "vtx_uh60_sfmplus_engPctNP" select 1);
private _eng1PctTQ     = _heli getVariable "vtx_uh60_sfmplus_engPctTQ" select 0;
private _eng2PctTQ     = _heli getVariable "vtx_uh60_sfmplus_engPctTQ" select 1;
private _engPctTQ      = _eng1PctTQ max _eng2PctTQ;
private _totRtrDmg     = _heli getHitPointDamage _rtrDmgHitName;
private _isSingleEng   = _heli getVariable "vtx_uh60_sfmplus_isSingleEng";
private _dmgTimerCont  = _heli getVariable "vtx_uh60_sfmplus_dmgTimerCont";
private _dmgTimerTrans = _heli getVariable "vtx_uh60_sfmplus_dmgTimerTrans";
private _damaged = false;

if (isEngineOn _heli) then {
    //With the power levers at idle
    if (_pctNR <= 0.50) then {
        if (_engPctTQ >= 0.30) then {
            _damaged = true;
        };
    };

    if (_pctNR <= 0.9) then {
        if (_engPctTQ >= 0.7) then {
            _damaged = true;
        };
    };

    //With the power levers at fly
    private _torqueLimits = switch (true) do {
        case (_isSingleEng): {[1.35, 1.44]}; // single engine limits
        case (speed _heli <= 148): {[1.20, 1.44]}; // below 80 knots limits
        case (speed _heli >= 148): {[1.00, 1.44]}; // over 80 knots limits
    };
    _torqueLimits params ["_continuousLimit", "_transientLimit"];

    if (_pctNR > 0.9) then {
        if (_engPctTQ <= _continuousLimit) then {
            _dmgTimerTrans = 0;
            _heli setVariable ["vtx_uh60_sfmplus_dmgTimerTrans", _dmgTimerTrans];
            if (vtx_uh60_sfmPlus_showDamageHints) then {[""] call vtx_uh60_misc_fnc_hint;};
        };
        //10 sec transient
        if (_engPctTQ > _continuousLimit && _engPctTQ <= _transientLimit) then {
            _dmgTimerTrans = _dmgTimerTrans + _deltaTime;
            if (vtx_uh60_sfmplus_showDamageHints) then {[format ["Warning!\nYou are at risk of causing damage to your helicopter from excessive torque.\nReduce your torque within\n%1 seconds\nto avoid permanent rotor damage", round (_transientTime - _dmgTimerTrans)]] call vtx_uh60_misc_fnc_hint;};
            if (_dmgTimerTrans >= _transientTime) then {
                _dmgTimerTrans = _transientTime;
                _damaged = true;
            };

            _heli setVariable ["vtx_uh60_sfmplus_dmgTimerTrans", _dmgTimerTrans];
        };
        if (_engPctTQ > _transientLimit) then {
            _damaged = true;
        };
    };
    
    if (_damaged) then {
        vtx_uh60_sfmplus_liftLossTimer  = (vtx_uh60_sfmplus_liftLossTimer + 0.01) max 0 min 1;
        if (vtx_uh60_sfmplus_showDamageHints) then {["Warning! You are currently losing lift due to excessive torque!"] call vtx_uh60_misc_fnc_hint;};
    } else {
        vtx_uh60_sfmplus_liftLossTimer = (vtx_uh60_sfmplus_liftLossTimer - 0.05) max 0 min 1;
        // systemChat "LIFT RECOVERING";
    };
};
