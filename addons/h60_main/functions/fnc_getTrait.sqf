#include "..\script_component.hpp"
/*
 * Author: Snow
 * Reads a variant trait: the config property vtx_trait_<name> of a vehicle's
 * CfgVehicles class. Variant PBOs set traits; the common base declares the
 * defaults. Lets SQF ask "does this airframe have X" instead of listing
 * variant classnames, so variants can move or be added without touching code.
 * Results are cached per class and trait (config never changes in a mission).
 *
 * Arguments:
 * 0: Vehicle or classname <OBJECT|STRING>
 * 1: Trait name, without the vtx_trait_ prefix <STRING>
 * 2: Default when the class or property is missing <ANY> (default: 0)
 *
 * Return Value:
 * Number, text or array from config, else the default <ANY>
 *
 * Example:
 * [vehicle player, "irLaser"] call vtx_main_fnc_getTrait
 *
 * Public: Yes
 */

params [["_vehicle", objNull, [objNull, ""]], ["_trait", "", [""]], ["_default", 0]];

private _type = [typeOf _vehicle, _vehicle] select (_vehicle isEqualType "");
if (_type isEqualTo "" || {_trait isEqualTo ""}) exitWith {_default};

if (isNil QGVAR(traitCache)) then { GVAR(traitCache) = createHashMap; };
private _key = _type + ">" + _trait;
private _value = GVAR(traitCache) get _key;
if (isNil "_value") then {
    private _cfg = configFile >> "CfgVehicles" >> _type >> ("vtx_trait_" + _trait);
    _value = switch (true) do {
        case (isNumber _cfg): { getNumber _cfg };
        case (isText _cfg): { getText _cfg };
        case (isArray _cfg): { getArray _cfg };
        default { _default };
    };
    GVAR(traitCache) set [_key, _value];
};
_value
