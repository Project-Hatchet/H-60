/*
 * vtx_uh60_misc_fnc_devPanel
 *
 * The developer panel (CBA setting vtx_uh60_devMode), two columns on the right of the screen.
 * Left: HeliSim's live state for the H-60 the player is in - buses, APU, bleed air, engine
 * state and Ng, levers, generators, and the reason Core recorded for a refused lever move -
 * so a hung or refused switch names its blocker on screen; while an automatic start runs
 * (fnc_quickstart sets vtx_uh60_misc_qs) its step, what it is waiting for and why it
 * stopped sit above that. Right: a snapshot of HeliSim's own CBA settings (realism, rotor
 * model, environment, the control, keyboard and testing switches), so a report carries the
 * configuration it was flown with.
 *
 * Called four times a second from the per-frame handler in XEH_postInit. With the setting
 * off, or the player not in an H-60, it takes the layer down.
 *
 * Arguments:
 *   0: The vehicle the player is in <OBJECT>
 */
params ["_heli"];

#define LAYER (["vtx_uh60_misc_devOverlay"] call BIS_fnc_rscLayer)
#define IDC_LEFT  1000
#define IDC_RIGHT 1001

private _display = uiNamespace getVariable ["vtx_uh60_misc_devOverlay", displayNull];
private _show = (missionNamespace getVariable ["vtx_uh60_devMode", false]) && {_heli isKindOf "vtx_H60_base"};
if (!_show) exitWith {
    if (!isNull _display) then { LAYER cutText ["", "PLAIN"]; };
};

if (isNull _display) then {
    LAYER cutRsc ["vtx_uh60_misc_devOverlay", "PLAIN", 0, false];
    _display = uiNamespace getVariable ["vtx_uh60_misc_devOverlay", displayNull];
};
if (isNull _display) exitWith {};

private _yn = {["<t color='#ff8080'>no</t>", "<t color='#80ff80'>yes</t>"] select (_this param [0, false])};
private _get = {_heli getVariable [_this select 0, _this select 1]};
private _why = {private _w = _heli getVariable [_this select 0, ""]; ["-", _w] select (_w != "")};
//A CBA setting of Core's, as yes/no
private _set = {[missionNamespace getVariable [_this select 0, false]] call _yn};

//Narrow columns: one or two values a line, nothing that wraps

// ── Left: state ──────────────────────────────────────────────────────────────
private _left = [
    "<t size='1.15' color='#ff6060'>DEVELOPER MODE</t>",
    "<t size='0.85' color='#c0c0c0'>UH-60M > Developer. Not for play.</t>",
    format ["<t size='0.85' color='#c0c0c0'>%1   H-60 %2</t>", typeOf _heli,
        getText (configFile >> "CfgPatches" >> "vtx_uh60" >> "versionStr")],
    format ["<t size='0.85' color='#c0c0c0'>local %1   HeliSim %2</t>",
        [local _heli] call _yn, [["bmkhs_initialised", false] call _get] call _yn]
];

//The automatic start, while one runs
private _qs = _heli getVariable "vtx_uh60_misc_qs";
if (!isNil "_qs") then {
    _qs params ["_step", "_total", "_title", "_phase", "_note", "_t0"];
    private _phaseColor = switch (_phase) do {
        case "DONE": {"#80ff80"};
        case "FAIL": {"#ff6060"};
        default      {"#ffd060"};
    };
    _left append [
        "",
        "<t color='#ff6060'>AUTOMATIC ENGINE START</t>",
        "<t size='0.85' color='#c0c0c0'>not a supported feature</t>",
        format ["<t color='%1'>%2</t>  step %3/%4  t+%5 s", _phaseColor, _phase, _step, _total, (diag_tickTime - _t0) toFixed 0],
        format ["<t size='1.05'>%1</t>", _title]
    ];
    if (_note != "") then {
        _left pushBack format ["<t color='%1'>%2</t>", _phaseColor, _note];
    };
};

private _engState = ["bmkhs_engState", []] call _get;
private _engNg    = ["bmkhs_engPctNg", []] call _get;
private _engTgt   = ["bmkhs_engTgt", []] call _get;
private _engLvr   = ["bmkhs_engPowerLeverState", []] call _get;
private _fuelSys  = ["OFF", "DIR", "XFD"];
private _airSrc   = ["ENG", "OFF", "APU"];

_left append [
    "",
    "<t color='#a0c0ff'>HeliSim</t>",
    format ["BATT %1  AC %2  DC %3",
        [["bmkhs_battBusOn", false] call _get] call _yn, [["bmkhs_acBusOn", false] call _get] call _yn,
        [["bmkhs_dcBusOn", false] call _get] call _yn],
    format ["PNEU %1  IGN %2  AIR SRC %3",
        [["bmkhs_pneuAvail", false] call _get] call _yn, [["bmkhs_ignitionOn", false] call _get] call _yn,
        _airSrc param [["bmkhs_airSourceIdx", 1] call _get, "?"]],
    format ["APU CONT %1  rpm %2  on %3",
        [["bmkhs_apuBtnOn", false] call _get] call _yn, (["bmkhs_apuRPM_pct", 0] call _get) toFixed 2,
        [["bmkhs_apuOn", false] call _get] call _yn],
    format ["   gate %1", ["bmkhs_apuRPM_pctGateWhy"] call _why],
    format ["   pump %1  fuel %2  acc OK %3",
        [["bmkhs_fuelPumpOn", false] call _get] call _yn, [["bmkhs_apuFuelAvail", false] call _get] call _yn,
        [["bmkhs_accHydPsiStartOk", false] call _get] call _yn],
    format ["FUEL SYS 1 %1  2 %2",
        _fuelSys param [["bmkhs_eng1FuelSysIdx", 0] call _get, "?"], _fuelSys param [["bmkhs_eng2FuelSysIdx", 0] call _get, "?"]]
];
{
    private _e = _x;
    _left append [
        format ["ENG %1 %2  PCL %3", _e + 1, _engState param [_e, "?"], _engLvr param [_e, "?"]],
        format ["   Ng %1  TGT %2", (_engNg param [_e, 0]) toFixed 3, (_engTgt param [_e, 0]) toFixed 0],
        format ["   FLY gate %1", [format ["bmkhs_eng%1PwrLvrGateWhy", _e + 1]] call _why]
    ];
} forEach [0, 1];
_left append [
    format ["Nr %1  rotor brake %2",
        (["bmkhs_rtrRpm", 0] call _get) toFixed 2, [["bmkhs_rotorBrakeOn", false] call _get] call _yn],
    format ["GEN 1 %1  2 %2  APU %3",
        [(["bmkhs_gen1", 0] call _get) >= 1] call _yn, [(["bmkhs_gen2", 0] call _get) >= 1] call _yn,
        [(["bmkhs_apuGen", 0] call _get) >= 1] call _yn]
];

// ── Right: HeliSim's CBA settings ────────────────────────────────────────────
//(BradMick's HeliSim > Flight model / Controls / Keyboard / Testing), read from their
//globals. The list values are Core's own constants (core.hpp).
private _realism = switch (missionNamespace getVariable ["bmkhs_helisimRealismSetting", -1]) do {
    case 0:  {"Casual"};
    case 2:  {"Realistic"};
    default  {"?"};
};
private _rotor = ["Simple", "BET"] param [missionNamespace getVariable ["bmkhs_rotorModel", 0], "?"];
private _env   = ["Standard Day", "Europe Summer", "Europe Winter", "Middle East", "C. Asia Summer", "C. Asia Winter", "Asia"]
    param [missionNamespace getVariable ["bmkhs_helisimEnvironment", 0], "?"];

private _right = [
    "<t size='1.15' color='#a0c0ff'>HeliSim settings</t>",
    format ["<t size='0.85' color='#c0c0c0'>Core %1 (%2), as set now</t>",
        getText (configFile >> "CfgPatches" >> "bmkhs_helisim" >> "versionStr"),
        getText (configFile >> "CfgPatches" >> "bmkhs_helisim" >> "hash")],
    "",
    format ["Realism %1  rotor %2", _realism, _rotor],
    format ["Env %1", _env],
    "",
    "<t color='#a0c0ff'>Controls</t>",
    format ["Ctr trim: cyclic %1  pedal %2", ["bmkhs_cyclicCenterTrimMode"] call _set, ["bmkhs_pedalCenterTrimMode"] call _set],
    format ["Springless: cyclic %1  pedals %2", ["bmkhs_springlessCyclic"] call _set, ["bmkhs_springlessPedals"] call _set],
    format ["Mouse joystick %1  sens %2", ["bmkhs_mouseAsJoystick"] call _set,
        (missionNamespace getVariable ["bmkhs_mouseSense", 0]) toFixed 1],
    "",
    "<t color='#a0c0ff'>Keyboard</t>",
    format ["Sticky: pitch %1  roll %2  yaw %3", ["bmkhs_keyboardStickyPitch"] call _set,
        ["bmkhs_keyboardStickyRoll"] call _set, ["bmkhs_keyboardStickyYaw"] call _set],
    format ["Auto: pedal %1  pitch %2  roll %3", ["bmkhs_autoPedal"] call _set,
        ["bmkhs_autoPitch"] call _set, ["bmkhs_autoRoll"] call _set],
    "",
    "<t color='#a0c0ff'>Testing</t>",
    format ["Wind off %1  VRS warn %2", ["bmkhs_windDisabled"] call _set, ["bmkhs_vrsWarning"] call _set],
    format ["Fixed GW %1  (%2 lb)", ["bmkhs_testGwtEnabled"] call _set, missionNamespace getVariable ["bmkhs_testGwtLbs", "?"]],
    format ["Debug: FM %1  sys %2  eng %3", ["bmkhs_fmDebug"] call _set, ["bmkhs_sysDebug"] call _set, ["bmkhs_engDisplay"] call _set],
    format ["   forces %1  flight log %2", ["bmkhs_forcesDebug"] call _set, ["bmkhs_flightLog"] call _set]
];

//Each column is fitted to its own text, so nothing is cut off at any resolution or aspect ratio
{
    _x params ["_idc", "_lines"];
    private _ctrl = _display displayCtrl _idc;
    _ctrl ctrlSetStructuredText parseText (_lines joinString "<br/>");
    (ctrlPosition _ctrl) params ["_px", "_py", "_pw"];
    _ctrl ctrlSetPosition [_px, _py, _pw, (ctrlTextHeight _ctrl) + 0.01];
    _ctrl ctrlCommit 0;
} forEach [[IDC_LEFT, _left], [IDC_RIGHT, _right]];
