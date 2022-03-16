/*
**	fnc_slippyInit
**  Adds Slippy as a CoPilot Companion
**
**	Add the Following Script to CoPilot
**	[this] spawn vtx_uh60_jester_fnc_slippyInit
**
**  No, I'm not sorry -Donov
*/

params["_slippy"];

vehicle _slippy addEventHandler ["Hit", {
	params ["_unit"];
	_slippySound = fullCrew vehicle _unit # 1 # 0;		//This line is jank

	if (!alive vehicle _unit) then {
		if ((random 1) == 0) then { _slippySound say3d "Slippy_Death1"; } else {_slippySound say3d "Slippy_Death2";};
	};
}];

vehicle _slippy addEventHandler ["IncomingMissile", {
	params["_target"];
	_slippySound = fullCrew _target # 1 # 0;
	
	if ((random 1) == 0) then { _slippySound say3d "Slippy_Missile1"; } else { _slippySound say3d "Slippy_Missile2";};
}];


//TODO raycast for objects near the tail
//vehicle _slippy addEventHandler ["LandedTouchDown", {
	//Sudo Code 
	//Check if object is near tail
	//Inform pilot about 2 seconds after touchdown
//}];

vehicle _slippy addEventHandler ["GetIn", {
	params ["_vehicle", "_role", "_unit", "_turret"];
	//Check if pilot gets in
	_pilot = fullCrew _vehicle # 0 # 1;
	//Arma jank to get "Jester" to say the voice line
	_slippySound = fullCrew _vehicle # 1 # 0;
	if (_pilot == "driver" ) then {
		_slippySound say3D    "Slippy_Intro";
	};
}];

hint "Events Created";

//TODO add in target found 
