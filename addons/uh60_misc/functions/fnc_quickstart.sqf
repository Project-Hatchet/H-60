/*
 * vtx_uh60_misc_fnc_quickstart
 *
 * Developer-mode automatic engine start. Not a supported way to start the aircraft: it
 * exists so a developer can get an H-60 running without working the cockpit, and it says
 * so on the developer panel the whole time it runs (fnc_devPanel). Offered as the vehicle
 * action "Automatic Engine Startup (DEV)" while the CBA setting vtx_uh60_devMode is on.
 *
 * State-driven, not timed. Every switch goes through Hatchet - vtx_uh60_helisim_fnc_cockpitBind,
 * the same path a click or a keybind takes (docs/HATCHET.md) - after asking whether HeliSim
 * allows the move, and every step then waits on HeliSim's published state (battery bus, APU
 * up to speed, bleed air, engine state and Ng, generators on line) with a timeout. A refused
 * move or a wait that times out aborts the sequence where it stands: the cockpit is left as
 * it is, and the reason goes to the panel and the RPT ([VTX QUICKSTART] lines).
 *
 * Arguments:
 *   0: The helicopter <OBJECT> - the player must be its pilot and it must be local
 *
 * Run with spawn - it sleeps.
 */
params ["_heli"];

if (_heli getVariable ["vtx_uh60_misc_qsRunning", false]) exitWith {};
_heli setVariable ["vtx_uh60_misc_qsRunning", true];

private _run   = diag_tickTime;
private _step  = 0;
private _total = 23;
_heli setVariable ["vtx_uh60_misc_qsRun", _run];

//The developer panel (fnc_devPanel) shows vtx_uh60_misc_qs while it is set

//State for the developer panel, and one RPT line per change
private _fnc_status = {
    params ["_title", ["_phase", "RUN"], ["_note", ""]];
    _heli setVariable ["vtx_uh60_misc_qs", [_step, _total, _title, _phase, _note, _run]];
    diag_log text format ["[VTX QUICKSTART] %1 %2/%3 %4%5 (t+%6 s)", _phase, _step, _total, _title,
        ["", " - " + _note] select (_note != ""), (diag_tickTime - _run) toFixed 1];
};

private _controls = configOf _heli >> "BMKHS_HeliSim" >> "Controls";
private _fnc_posName = {
    params ["_ctrl", "_idx"];
    private _cfg = ("getText (_x >> 'variableName') == _ctrl" configClasses _controls) param [0, configNull];
    configName (("true" configClasses (_cfg >> "Positions")) param [_idx, configNull])
};

private _fnc_eng = {
    params ["_e"];
    format ["ENG%1 %2, Ng %3, TGT %4, PCL %5", _e + 1,
        (_heli getVariable ["bmkhs_engState", []]) param [_e, "?"],
        ((_heli getVariable ["bmkhs_engPctNg", []]) param [_e, 0]) toFixed 3,
        ((_heli getVariable ["bmkhs_engTgt", []]) param [_e, 0]) toFixed 0,
        (_heli getVariable ["bmkhs_engPowerLeverState", []]) param [_e, "?"]]
};

//Poll a condition until it holds or the timeout passes. Returns whether it holds. Throws
//on its own if the pilot leaves, the aircraft dies or developer mode is switched off.
private _fnc_poll = {
    params ["_cond", "_timeout"];
    private _until = diag_tickTime + _timeout;
    waitUntil {
        sleep 0.1;
        (call _cond) || {diag_tickTime > _until} || {!alive _heli} || {driver _heli != player}
            || {!(missionNamespace getVariable ["vtx_uh60_devMode", false])}
    };
    if (!alive _heli || {driver _heli != player}) then {throw "the pilot left the seat, or the aircraft was destroyed"};
    if !(missionNamespace getVariable ["vtx_uh60_devMode", false]) then {throw "developer mode was switched off"};
    call _cond
};
//The same, aborting with the reason (_why is code, so it reads the state at the moment it gave up)
private _fnc_wait = {
    params ["_cond", "_timeout", "_why"];
    if !([_cond, _timeout] call _fnc_poll) then {
        throw format ["%1 (gave up after %2 s)", call _why, _timeout];
    };
};

//Move a control through Hatchet, after asking whether it may move (Core's interlocks plus
//the H-60's own, exactly as a click is checked), then wait for HeliSim to show it there.
//A starter button springs back, so its caller waits on the engine instead.
private _fnc_move = {
    params ["_ctrl", "_idx", "_title", ["_button", false]];
    _step = _step + 1;
    [_title] call _fnc_status;

    if !([[_heli, "", "", [_ctrl, _idx] call _fnc_posName], _ctrl] call vtx_uh60_helisim_fnc_cockpitAllowed) then {
        private _why = _heli getVariable [format ["bmkhs_%1GateWhy", _ctrl], ""];
        throw format ["%1 refused - %2", _title,
            ["the H-60 interlock (other engine still starting)", "blocked by " + _why] select (_why != "")];
    };

    private _there = {(_heli getVariable [format ["bmkhs_%1Idx", _ctrl], -1]) == _idx};
    [_heli, _ctrl, _idx] call vtx_uh60_helisim_fnc_cockpitBind;
    if (_button) exitWith {};
    if !([_there, 3] call _fnc_poll) then {
        //Hatchet drops a move while that control's animation is still running - once more
        [_heli, _ctrl, _idx] call vtx_uh60_helisim_fnc_cockpitBind;
        [_there, 3, {format ["%1 - HeliSim never saw the control arrive (Hatchet did not move it)", _title]}] call _fnc_wait;
    };
};

try {
    //Preconditions
    if !(missionNamespace getVariable ["vtx_uh60_devMode", false]) then {throw "developer mode is off"};
    if !(local _heli) then {throw "the aircraft is not local to this machine"};
    if !(_heli getVariable ["bmkhs_initialised", false]) then {throw "HeliSim has not initialised this aircraft"};
    if (isNull (_heli getVariable ["hct_config", configNull])) then {throw "this aircraft has no Hatchet cockpit"};
    if (isNil "vtx_uh60_helisim_fnc_cockpitBind") then {throw "the HeliSim bridge (uh60_helisim) is not loaded"};
    if (((_heli getVariable ["bmkhs_engState", []]) findIf {_x != "OFF"}) >= 0) then {throw "an engine is already running or starting"};

    private _engine      = (_heli getVariable ["bmkhs_engines", []]) param [0, createHashMap];
    private _idleNg      = _engine getOrDefault ["idleNg", 0.679];
    private _leverTravel = _engine getOrDefault ["leverTravelTime", 8];

    //Electrical
    ["gen1Sw",      1, "No.1 GEN - ON"]  call _fnc_move;
    ["gen2Sw",      1, "No.2 GEN - ON"]  call _fnc_move;
    ["batt1Switch", 1, "No.1 BATT - ON"] call _fnc_move;
    ["batt2Switch", 1, "No.2 BATT - ON"] call _fnc_move;
    [{_heli getVariable ["bmkhs_battBusOn", false]}, 5, {
        format ["battery bus never came up (batt1 %1, batt2 %2)",
            (_heli getVariable ["bmkhs_batt1Power_pct", 0]) toFixed 2, (_heli getVariable ["bmkhs_batt2Power_pct", 0]) toFixed 2]
    }] call _fnc_wait;

    //APU
    ["fuelPump", 1, "FUEL PUMP - APU BOOST"] call _fnc_move;
    ["apuBtn",   1, "APU CONT - ON"]         call _fnc_move;
    _step = _step + 1;
    ["APU spooling up"] call _fnc_status;
    [{_heli getVariable ["bmkhs_apuOn", false]}, 30, {
        if (_heli getVariable ["bmkhs_apuBtnOn", false]) then {
            format ["APU never came up to speed (rpm %1, gate: %2)",
                (_heli getVariable ["bmkhs_apuRPM_pct", 0]) toFixed 2, _heli getVariable ["bmkhs_apuRPM_pctGateWhy", "-"]]
        } else {
            "APU dropped off line - HeliSim switched APU CONT back off"
        }
    }] call _fnc_wait;

    ["apuGenSw", 1, "APU GEN - ON"] call _fnc_move;
    [{_heli getVariable ["bmkhs_acBusOn", false]}, 5, {"AC bus never came up on the APU generator"}] call _fnc_wait;
    ["stbyInst",  1, "STBY INST - ARM"]    call _fnc_move;
    ["ignition",  1, "ENG IGNITION - ON"]  call _fnc_move;
    ["airSource", 2, "AIR SOURCE - APU"]   call _fnc_move;
    [{_heli getVariable ["bmkhs_pneuAvail", false]}, 5, {"no bleed air for the starters (PNEU never came up)"}] call _fnc_wait;
    ["eng1FuelSys", 1, "No.1 FUEL SYS - DIR"] call _fnc_move;
    ["eng2FuelSys", 1, "No.2 FUEL SYS - DIR"] call _fnc_move;

    //Engines, one at a time: starter, lever to IDLE once the spool turns, then wait for
    //self-sustain (Core flips STARTING to ON at selfSustNg) and a settled idle
    {
        private _e = _x;
        private _n = str (_e + 1);
        [format ["eng%1StartSw", _n], 1, format ["ENG %1 STARTER - press", _n], true] call _fnc_move;
        [{((_heli getVariable ["bmkhs_engPctNg", []]) param [_e, 0]) > 0.10}, 8, {
            format ["ENG %1 starter is not turning the spool (PNEU %2, ignition %3) - %4", _n,
                _heli getVariable ["bmkhs_pneuAvail", false], _heli getVariable ["bmkhs_ignitionOn", false], [_e] call _fnc_eng]
        }] call _fnc_wait;
        [format ["eng%1PwrLvr", _n], 1, format ["ENG %1 PCL - IDLE", _n]] call _fnc_move;
        _step = _step + 1;
        [format ["ENG %1 lighting off", _n]] call _fnc_status;
        [{((_heli getVariable ["bmkhs_engState", []]) param [_e, "OFF"]) == "ON"}, 90, {
            format ["ENG %1 never reached self-sustain - %2", _n, [_e] call _fnc_eng]
        }] call _fnc_wait;
        [{((_heli getVariable ["bmkhs_engPctNg", []]) param [_e, 0]) >= 0.99 * _idleNg}, 60, {
            format ["ENG %1 never settled at idle - %2", _n, [_e] call _fnc_eng]
        }] call _fnc_wait;
    } forEach [0, 1];

    //Both levers to FLY. No.1 takes No.2 with it while that engine idles (the linked
    //levers, docs/HATCHET.md); if it did not, move No.2 itself.
    ["eng1PwrLvr", 2, "ENG 1 PCL - FLY"] call _fnc_move;
    if ((_heli getVariable ["bmkhs_eng2PwrLvrIdx", 0]) != 2) then {
        ["eng2PwrLvr", 2, "ENG 2 PCL - FLY"] call _fnc_move;
    } else {
        _step = _step + 1;
        ["ENG 2 PCL - FLY (followed No.1)"] call _fnc_status;
    };
    _step = _step + 1;
    ["Engines accelerating to FLY - waiting for Nr and both generators"] call _fnc_status;
    [{(_heli getVariable ["bmkhs_gen1", 0]) >= 1 && {(_heli getVariable ["bmkhs_gen2", 0]) >= 1}}, _leverTravel + 60, {
        format ["generators never came on line (Nr %1, gen1 %2, gen2 %3) - %4; %5",
            (_heli getVariable ["bmkhs_rtrRpm", 0]) toFixed 2, _heli getVariable ["bmkhs_gen1", 0], _heli getVariable ["bmkhs_gen2", 0],
            [0] call _fnc_eng, [1] call _fnc_eng]
    }] call _fnc_wait;

    ["apuBtn", 0, "APU CONT - OFF"] call _fnc_move;

    //The visible mark of an automatic start
    _heli setObjectTextureGlobal ["markings", "\z\vtx\addons\uh60_misc\data\markings\markings_studentdriver.paa"];
    _heli setVariable ["vtx_autostarted", true];
    ["vtx_uh60_misc_autoStarted", _heli] call CBA_fnc_localEvent;

    ["Automatic start complete", "DONE"] call _fnc_status;
} catch {
    private _title = (_heli getVariable ["vtx_uh60_misc_qs", []]) param [2, ""];
    [_title, "FAIL", _exception] call _fnc_status;
};

_heli setVariable ["vtx_uh60_misc_qsRunning", false];

//Leave the result up to read, unless another run has taken the panel over
sleep ([20, 10] select (((_heli getVariable ["vtx_uh60_misc_qs", []]) param [3, ""]) == "DONE"));
if ((_heli getVariable ["vtx_uh60_misc_qsRun", 0]) == _run) then {
    _heli setVariable ["vtx_uh60_misc_qs", nil];
};
