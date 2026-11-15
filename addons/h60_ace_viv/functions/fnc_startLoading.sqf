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
 * [_heli, ace_player] call hct_h60_ace_viv_fnc_startLoading
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
[_unit, "forceWalk", "hct_h60_ace_viv", true] call ace_common_fnc_statusEffect_set;
[_unit, "blockThrow", "hct_h60_ace_viv", true] call ace_common_fnc_statusEffect_set;
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
        if (cursorObject isKindOf "CAManBase") exitWith {hint format [(localize "STR_hct_h60_ace_viv_CannotLoad"), cursorObject call _vehName, GVAR(carrier) call _vehName]};
        if !(_canVehicleCargo # 1) exitWith {hint format [(localize "STR_hct_h60_ace_viv_CannotLoad"), cursorObject call _vehName, GVAR(carrier) call _vehName]};
        if !(_canVehicleCargo # 0) exitWith {hint format [(localize "STR_hct_h60_ace_viv_CarrierFull"), cursorObject call _vehName, GVAR(carrier) call _vehName]};
        if ((cursorObject distance GVAR(carrier)) > GVAR(loadDistance)) exitWith {hint format [(localize "STR_hct_h60_ace_viv_CargoTooFar"), cursorObject call _vehName, GVAR(carrier) call _vehName]};
        if (cursorObject getVariable [QGVAR(isLoading), false]) exitWith {hint format [(localize "STR_hct_h60_ace_viv_CargoBeingLoaded"), cursorObject call _vehName, cursorObject getVariable [QGVAR(loader), "Unknown Unit"]]};

        // Start loading. This runs from an addAction statement, where the
        // caller is ACE_player (the handler only fires for them). The unit,
        // carrier and cargo ride in the progress bar's args: its callbacks run
        // later from a PFH, and the loading mode (GVAR(carrier)/GVAR(cargo))
        // may have been left - and nulled - while the bar ran.
        private _unit = ACE_player;
        private _cargo = cursorObject;
        GVAR(cargo) = _cargo;
        _unit setVariable [QGVAR(isLoading), true, true];
        _cargo setVariable [QGVAR(isLoading), true, true];
        _cargo setVariable [QGVAR(loader), name _unit, true];

        private _fnc_release = {
            params ["_unit", "", "_cargo"];
            _unit setVariable [QGVAR(isLoading), false, true];
            _cargo setVariable [QGVAR(isLoading), false, true];
            _cargo setVariable [QGVAR(loader), "", true];
            if (GVAR(cargo) isEqualTo _cargo) then {GVAR(cargo) = objNull};
        };

        private _timeToLoad = 2 + (getMass _cargo / 100);
        [
            _timeToLoad,
            [_unit, GVAR(carrier), _cargo, _fnc_release],
            {
                (_this # 0) params ["_unit", "_carrier", "_cargo", "_fnc_release"];
                if (!isNull _carrier && {!isNull _cargo}) then {
                    [QGVAR(setVehicleCargo), [_carrier, _cargo]] call CBA_fnc_localEvent;
                };
                (_this # 0) call _fnc_release;
            },
            {
                TRACE_1("load progressBar fail",_this);
                (_this # 0) params ["", "", "", "_fnc_release"];
                (_this # 0) call _fnc_release;
            },
            localize "STR_A3_MP_GroundSupport_ProgressBar_LoadingGroup",
            {true},
            ["isNotInside"]
        ] call ace_common_fnc_progressBar;
    }
] call ace_common_fnc_addActionEventHandler];
