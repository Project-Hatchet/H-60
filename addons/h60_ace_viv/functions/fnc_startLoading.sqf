#include "script_component.hpp"
/*
 * Author: Ampersand
 * Start PFH for loading viv cargo
 *
 * Arguments:
 * 0: Carrier <OBJECT>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * Unit can configure the aircraft's pylons <BOOL>
 *
 * Example:
 * [_heli, ace_player] call vtx_ace_viv_fnc_startLoading
 *
 * Public: No
 */

params ["_carrier", "_unit"];

GVAR(isReady) = true;
GVAR(carrier) = _carrier;
GVAR(cargo) = objNull;

// select no weapon and stop sprinting
_unit action ["SwitchWeapon", _unit, _unit, 299];
[_unit, "AmovPercMstpSnonWnonDnon", 0] call ace_common_fnc_doAnimation;
[_unit, "forceWalk", "VTX_ACE_VIV", true] call ace_common_fnc_statusEffect_set;
[_unit, "blockThrow", "VTX_ACE_VIV", true] call ace_common_fnc_statusEffect_set;
[_carrier, true] call FUNC(lockSeats);

// add mouse button action and hint
[localize LSTRING(LoadCargo), "", localize "STR_3DEN_Display3DEN_ControlsHint_Cancel"] call ace_interaction_fnc_showMouseHint;

_unit setVariable [QGVAR(Load), [
    _unit, "DefaultAction",
    {GVAR(isReady)},
    {
        if (isNull cursorObject) exitWith {};
        private _canVehicleCargo = GVAR(carrier) canVehicleCargo cursorObject;
        private _vehName = {
            getText (configOf _this >> "displayName")
        };
        if (cursorObject isKindOf "CAManBase") exitWith {hint format ["Cannot load cargo %1 into carrier %2", cursorObject call _vehName, GVAR(carrier) call _vehName]};
        if !(_canVehicleCargo # 1) exitWith {hint format ["Cannot load cargo %1 into carrier %2", cursorObject call _vehName, GVAR(carrier) call _vehName]};
        if !(_canVehicleCargo # 0) exitWith {hint format ["Carrier %2 is too full to fit cargo %1", cursorObject call _vehName, GVAR(carrier) call _vehName]};
        if ((cursorObject distance GVAR(carrier)) > GVAR(loadDistance)) exitWith {hint format ["Cargo %1 is too far from carrier %2", cursorObject call _vehName, GVAR(carrier) call _vehName]};
        if (cursorObject getVariable [QGVAR(isLoading), false]) exitWith {hint format ["Cargo %1 is already being loaded by %2", cursorObject call _vehName, cursorObject getVariable [QGVAR(loader), "Unknown Unit"]]};

        // Start loading
        GVAR(cargo) = cursorObject;
        _unit setVariable [QGVAR(isLoading), true, true];
        GVAR(cargo) setVariable [QGVAR(isLoading), true, true];
        GVAR(cargo) setVariable [QGVAR(loader), name _unit, true];

        private _timeToLoad = 2 + (getMass GVAR(cargo) / 100);
        [
            _timeToLoad,
            [],
            {
                [QGVAR(setVehicleCargo), [GVAR(carrier), GVAR(cargo)]] call CBA_fnc_localEvent;
                _unit setVariable [QGVAR(isLoading), false, true];
                GVAR(cargo) setVariable [QGVAR(isLoading), false, true];
                GVAR(cargo) setVariable [QGVAR(loader), "", true];
                GVAR(cargo) = objNull;
            },
            {
                TRACE_1("unload progressBar fail",_this);
                _unit setVariable [QGVAR(isLoading), false, true];
                GVAR(cargo) setVariable [QGVAR(isLoading), false, true];
                GVAR(cargo) setVariable [QGVAR(loader), "", true];
                GVAR(cargo) = objNull;
            },
            localize "STR_A3_MP_GroundSupport_ProgressBar_LoadingGroup",
            {true},
            ["isNotInside"]
        ] call ace_common_fnc_progressBar;
    }
] call ace_common_fnc_addActionEventHandler];
