#include "..\script_component.hpp"
/*
 * hct_h60_acre_fnc_getRadio
 *
 * The radio mounted in one of the vehicle's ACRE racks, by rack index. ACRE
 * builds the racks after the vehicle spawns, so early clicks on the comm
 * pages can arrive before a rack or its radio exists: those read "" here
 * instead of indexing past the rack list.
 *
 * params (array)[(object) vehicle, (number) rack index, 0-based]
 * returns (string) radio id, or "" when there is none
 */
params [["_vehicle", objNull, [objNull]], ["_index", -1, [0]]];

private _rackId = ([_vehicle] call acre_sys_rack_fnc_getVehicleRacks) param [_index, ""];
if (_rackId isEqualTo "") exitWith {""};
[_rackId] call acre_sys_rack_fnc_getMountedRadio
