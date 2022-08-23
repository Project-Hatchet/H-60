params ["_vehicle"];
{
	_x params ["_hitpoint", "_anim", "_textureIndex"];
	if ((_vehicle getHitPointDamage _hitpoint) > 0.4) then {
		if (_vehicle animationPhase _anim < 1) then {
			_vehicle animateSource [_anim, 1];

			_vehicle setObjectTextureGlobal [_textureIndex, format ["z\vtx\addons\uh60_mfd\data\mfd_damage_%1.paa", (1 + (round random 1))]];
		};
	} else {
		if (_vehicle animationPhase _anim > 0) then {
			_vehicle animateSource [_anim, 0];
		};
	};
} forEach [
	["mfd1", "MFD1_Hide", 12],
	["mfd2", "MFD2_Hide", 13],
	["mfd3", "MFD3_Hide", 14],
	["mfd4", "MFD4_Hide", 15]
];