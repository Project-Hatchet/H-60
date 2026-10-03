#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(pylonPositionParams) = [];
GVAR(irLaserPFH) = -1;
GVAR(laserEmitters) = [];

vtx_uh60_weapons_laserCodes = [
	1111,
	1112,
	1113,
	1114,
	1115,
	1116
];
vtx_uh60_weapons_laserCodeLetters = [
	'A','B','C','D','E','F'
];

ADDON = true;
