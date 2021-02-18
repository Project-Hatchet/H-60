#include "script_component.hpp"

GVAR(carriers) = [];

GVAR(loadAction) = [ // create action
    QGVAR(loadAction),
    localize LSTRING(LoadCargo),
    "\a3\ui_f\data\IGUI\Cfg\VehicleToggles\VehicleCargoIconOn2_ca.paa",
    {[_target, _player] call FUNC(startLoading)},
    {[ace_player, _target] call FUNC(canConfigureCargo)},
    nil,
    nil,
    5
] call ace_interact_menu_fnc_createAction;

["AllVehicles", "init", { // on air vehicle init, add action to class if has pylons
    params ["_vehicle"];
    private _typeOf = typeOf _vehicle;

    if (_typeOf in GVAR(carriers)) exitWith {};
    if !(vehicleCargoEnabled _vehicle) exitWith {};

    GVAR(carriers) pushBack _typeOf;
    [_typeOf, 0, ["ACE_MainActions"], GVAR(loadAction)] call ace_interact_menu_fnc_addActionToClass;
}, true, [], true] call CBA_fnc_addClassEventHandler;

GVAR(unloadAction) = [ // create action
    QGVAR(unloadAction),
    localize "STR_A3_moduleDepot_Unload",
    "\a3\ui_f\data\IGUI\Cfg\Actions\unloadVehicle_ca.paa",
    {
        [QGVAR(setVehicleCargo), [objNull, _target]] call CBA_fnc_localEvent},
    {!isNull (isVehicleCargo _target)}
] call ace_interact_menu_fnc_createAction;
["All", 0, ["ACE_MainActions"], GVAR(unloadAction), true] call ace_interact_menu_fnc_addActionToClass;

["vtx_H60_base", "GetIn", {call FUNC(onGetInOut)}, true, [], true] call CBA_fnc_addClassEventHandler;
["vtx_H60_base", "GetOut", {call FUNC(onGetInOut)}, true, [], true] call CBA_fnc_addClassEventHandler;

[QGVAR(setVehicleCargo), {
    params ["_carrier", "_cargo"];
    TRACE_5("setVehicleCargo",_carrier,_cargo);
    private _currentCarrier = [_carrier, isVehicleCargo _cargo] select (isNull _carrier);

    _carrier setVehicleCargo _cargo;
    [_currentCarrier] call FUNC(checkBlockedSeats);
}] call CBA_fnc_addEventHandler;

// display event handler
["MouseZChanged", {_this select 1 call FUNC(handleScrollWheel)}] call CBA_fnc_addDisplayHandler;
