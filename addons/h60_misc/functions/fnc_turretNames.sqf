/*
 * hct_h60_misc_fnc_turretNames
 *
 * Every turret of the vehicle's class with its gunnerName - the key the seat-swap
 * table (XEH_preInit) is written in. Config never changes in a mission, so it is
 * read once per class: the swap actions' dry runs (ACE conditions, re-run while the
 * menu is open) and the lock reconcile (every crew change on every H-60) look
 * seats up here instead of walking the turret config each time.
 *
 * params (array)[(object) vehicle]
 * returns (hashmap) turret path -> gunnerName, every turret including FFV
 */
params [["_veh", objNull, [objNull]]];

if (isNil "hct_h60_misc_turretNameCache") then { hct_h60_misc_turretNameCache = createHashMap; };
private _type = typeOf _veh;
private _names = hct_h60_misc_turretNameCache get _type;
if (isNil "_names") then {
    _names = createHashMapFromArray ((allTurrets [_veh, true]) apply {
        [_x, getText (([_veh, _x] call BIS_fnc_turretConfig) >> "gunnerName")]
    });
    if (_type != "") then { hct_h60_misc_turretNameCache set [_type, _names]; };
};
_names
