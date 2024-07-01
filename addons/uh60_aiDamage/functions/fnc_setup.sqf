/*	
 * vtx_uh60_aiDamage_fnc_setup
 *
 * adds event handlers for damage checking
*/

params ["_bird"];

//init set variable.  Failsafe incase I messed up somehow 
_bird setVariable ["VTX_AICompDamage", true];
_pilots = [(fullCrew _bird # 0 # 0), (fullCrew _bird # 1 # 0)];
	{
	if (_x in allPlayers) then {
			_bird setVariable ["VTX_AICompDamage", false];
		} else {
			_bird setVariable ["VTX_AICompDamage", true];
		};
} forEach _pilots;


// checks to see if x part was hit and passes it to a switch in another function
_bird addEventHandler["HitPart", {
	params["_target","","","","","_hitParts","_ammo"];

	_partsCheckedArray = ["hitengine1", "hitengine2", "mainrotorgearbox", "tailgearbox"];
	_hitDmg = _ammo # 0;

	{
		if (_x in _partsCheckedArray) then {
			[_target, _x] call vtx_uh60_aiDamage_fnc_dmgTracker;
		};
	} forEach _hitParts;
}];

//Checks to see if a player is in the pilot or copilot seat
_bird addEventHandler["getIn", {
	params ["_vehicle", "_role", "_unit", "_turret"];
	_pilots = [(fullCrew _vehicle # 0 # 0), (fullCrew _vehicle # 1 # 0)];
	{
		if (_x in allPlayers) then {
				_vehicle setVariable ["VTX_AICompDamage", false];
			} else {
				_vehicle setVariable ["VTX_AICompDamage", true];
			};
	} forEach _pilots;
}];