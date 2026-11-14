#include "..\script_component.hpp"
/*
 * Author: Ampersand
 * Assign pylon on the turret owner.
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Turret Path <ARRAY>
 * 2: Magazine Classname <STRING>
 * 3: Number of rounds <NUMBER>
 * 4: Pylon Index <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [vehicle, [0], "5000Rnd_762x51_Belt", 500, 1] call vtx_uh60_weapons_fnc_assignPylonLocal
 *
 * Public: No
 */

params ["_vehicle", "_turretPath", "_magazineClass", "_numRounds", "_pylon"];
TRACE_5("assignPylonLocal",_vehicle,_turretPath,_magazineClass,_numRounds,_pylon);

if (_turretPath isEqualTo [-1]) then {_turretPath = [];};

_vehicle setPylonLoadout [_pylon, _magazineClass, true, _turretPath];
_vehicle setAmmoOnPylon [_pylon, _numRounds];
