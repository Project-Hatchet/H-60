#include "..\script_component.hpp"
/*
 * Author: Snow
 * Returns the root classes of a numeric variant trait: every CfgVehicles class
 * whose vtx_trait_<name> is 1 while its parent's is not. Registering an
 * inheriting ACE action or CBA class event handler on these roots reaches
 * exactly the classes that have the trait (subclasses included) without
 * double-registering a subclass. Cached per trait; one config scan each.
 *
 * Arguments:
 * 0: Trait name, without the vtx_trait_ prefix <STRING>
 *
 * Return Value:
 * Classnames <ARRAY of STRING>
 *
 * Example:
 * ["crewChiefTurnOut"] call vtx_main_fnc_getTraitClasses
 *
 * Public: Yes
 */

params [["_trait", "", [""]]];
if (_trait isEqualTo "") exitWith {[]};

if (isNil QGVAR(traitClassCache)) then { GVAR(traitClassCache) = createHashMap; };
private _classes = GVAR(traitClassCache) get _trait;
if (isNil "_classes") then {
    private _property = "vtx_trait_" + _trait;
    private _condition = format [
        "getNumber (_x >> '%1') == 1 && {getNumber (inheritsFrom _x >> '%1') != 1}",
        _property
    ];
    _classes = (_condition configClasses (configFile >> "CfgVehicles")) apply {configName _x};
    GVAR(traitClassCache) set [_trait, _classes];
};
+_classes
