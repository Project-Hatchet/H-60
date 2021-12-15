/*
 * vtx_uh60_anvishud_fnc_Hud_Brt
 *
 * Dims the HMD
 *
 * params []
 */

//Determine correct pylon index based on L or R seat
_index = 8;
_turretPath = player call CBA_fnc_turretPath;
if (_turretPath isEqualTo []) then {_index = 9};

//Adjust ammo at pylon index to manipulate HMD alpha
_ammoCount = (vehicle player) ammoOnPylon _index;
if(_ammoCount > 0) then {
 	vehicle player setAmmoOnPylon [_index, _ammoCount - 100];
};

if(vtx_uh60_ui_showDebugMessages) then {systemChat Format["HMD Brightness: %1%2", (vehicle player ammoOnPylon _index)/10, "%"]};
