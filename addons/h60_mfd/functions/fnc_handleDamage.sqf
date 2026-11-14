/*
 * vtx_uh60_mfd_fnc_handleDamage
 *
 * MFD damage, once per second: a screen whose hitpoint is past 0.9 goes dark with
 * a cracked texture (on the aircraft's owner); a damaged screen (> 0.2) randomly
 * flickers to another page and back.
 *
 * Flickers run on CBA delays, one at a time per screen, and only put the page back
 * if the screen still shows the flicker page. (They were spawned scripts: two
 * overlapping flickers left the screen stuck on the garbage page, and a page the
 * crew selected during a flicker was reverted.)
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];
{
	_x params ["_hitpoint", "_anim", "_textureIndex", "_mfdIndex"];
	private _damage = _vehicle getHitPointDamage _hitpoint;
	if (local _vehicle) then {
		if (_damage > 0.9) then {
			if (_vehicle animationPhase _anim < 1) then {
				_vehicle animateSource [_anim, 1];

				_vehicle setObjectTextureGlobal [_textureIndex, format ["z\vtx\addons\uh60_mfd\data\mfd_damage_%1.paa", (1 + (round random 1))]];
			};
		} else {
			if (_vehicle animationPhase _anim > 0) then {
				_vehicle animateSource [_anim, 0];
			};
		};
	};
	private _flickerVar = format ["vtx_uh60_mfd_flicker_%1", _mfdIndex];
	if (_damage > 0.2 && {random 0.9 < _damage} && {isNil {_vehicle getVariable _flickerVar}}) then {
		_vehicle setVariable [_flickerVar, true];
		[{
			params ["_vehicle", "_mfdIndex", "_flickerEnd", "_flickerVar"];
			if (isNull _vehicle) exitWith {};
			private _startValue = (getUserMFDValue _vehicle) # _mfdIndex;
			private _newPage = random 10;
			if (_newPage > 6) then {_newPage = 99};
			_vehicle setUserMFDValue [_mfdIndex, _newPage];
			[{
				params ["_vehicle", "_mfdIndex", "_startValue", "_newPage", "_flickerVar"];
				if (isNull _vehicle) exitWith {};
				if (((getUserMFDValue _vehicle) # _mfdIndex) == _newPage) then {
					_vehicle setUserMFDValue [_mfdIndex, _startValue];
				};
				_vehicle setVariable [_flickerVar, nil];
			}, [_vehicle, _mfdIndex, _startValue, _newPage, _flickerVar], _flickerEnd] call CBA_fnc_waitAndExecute;
		}, [_vehicle, _mfdIndex, random 0.5, _flickerVar], random 0.5] call CBA_fnc_waitAndExecute;
	};
} forEach [
	["mfd1", "MFD1_Hide", 12, 23],
	["mfd2", "MFD2_Hide", 13, 24],
	["mfd3", "MFD3_Hide", 14, 25],
	["mfd4", "MFD4_Hide", 15, 26]
];
