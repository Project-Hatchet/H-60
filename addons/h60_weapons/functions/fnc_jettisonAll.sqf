/*
 * vtx_uh60_weapons_fnc_jettisonAll
 *
 * Jettisons every store on pylons 1-4 (not the M230 chain guns): each is moved to
 * a falling dummy that drops after a short random delay. Called from the cockpit
 * JETT button.
 *
 * params: none (acts on hct_vehicle)
 */

private _vehicle = missionNamespace getVariable ["hct_vehicle", objNull];
if (isNull _vehicle) exitWith {};

private _magazines = getPylonMagazines _vehicle;
{
	_x params ["_pylon", "_position", "_damageThreshold"];
	// airframes with fewer pylons simply have nothing at the higher indices
	private _magazine = _magazines param [_pylon - 1, ""];
	if (_magazine != "" && {!(_magazine in ["VTX_M230_Chaingun_R", "VTX_M230_Chaingun_L"])}) then {
		private _ammo = _vehicle ammoOnPylon _pylon;
		private _pylonDummy = "vtx_pylon" createVehicle [0,0,0];
		_pylonDummy setPylonLoadout [1, _magazine, false, []];
		_pylonDummy setAmmoOnPylon [1, _ammo];
		_pylonDummy attachTo [_vehicle, _position];
		_pylonDummy disableCollisionWith _vehicle;
		_pylonDummy allowDamage false;
		_vehicle setPylonLoadout [_pylon, "", false, []];
		// release after a random delay (was a spawned script with sleep per store)
		[{
			params ["_dummy"];
			if (isNull _dummy) exitWith {};
			detach _dummy;
			_dummy addTorque [-5 + random 10, -5 + random 10, -5 + random 10];
			// jettisoned stores used to stay in the world for the rest of the mission
			[{deleteVehicle _this}, _dummy, 300] call CBA_fnc_waitAndExecute;
		}, [_pylonDummy], random 2] call CBA_fnc_waitAndExecute;
	};
} forEach [
	[1, [-2, 2.4, -1.4], 0.5],
	[2, [ 2, 2.4, -1.4], 0.5],
	[3, [-2.8, 2.3, -1.4], 0.5],
	[4, [ 2.8, 2.3, -1.4], 0.5]
];
