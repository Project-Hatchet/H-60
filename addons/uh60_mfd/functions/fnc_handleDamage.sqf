params ["_vehicle"];
{
	_x params ["_hitpoint", "_anim", "_textureIndex", "_mfdIndex"];
	private _damage = _vehicle getHitPointDamage _hitpoint;
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
	if (_damage > 0.2) then {
		private _flickerChance = random 0.9 < _damage;
		if (_flickerChance) then {
			private _flickerStart = random 0.5;
			private _flickerEnd = random 0.5;
			[_vehicle, _mfdIndex, _flickerStart, _flickerEnd] spawn {
				params ["_vehicle", "_mfdIndex", "_flickerStart", "_flickerEnd"];
				private _startValue = (getUserMFDValue _vehicle) # _mfdIndex;
				sleep _flickerStart;
				private _newPage = random 10;
				if (_newPage > 6) then {_newPage = 99};
				_vehicle setUserMFDValue [_mfdIndex, _newPage];
				sleep _flickerEnd;
				_vehicle setUserMFDValue [_mfdIndex, _startValue];
			};
		};
	};
} forEach [
	["mfd1", "MFD1_Hide", 12, 23],
	["mfd2", "MFD2_Hide", 13, 24],
	["mfd3", "MFD3_Hide", 14, 25],
	["mfd4", "MFD4_Hide", 15, 26]
];