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

//Check for Death
vehicle _slippy addEventHandler ["Hit", {
	params ["_unit"];
	_slippySound = fullCrew vehicle _unit # 1 # 0;		//This line is jank to get the copilot to speak for slippy
	
	if (!alive vehicle _unit) then {
		if ((random 1) == 0) then { _slippySound say3d "Slippy_Death1"; } else {_slippySound say3d "Slippy_Death2";};
		vehicle _unit vehicleChat "Aaah!";
	};
}];

vehicle _slippy addEventHandler ["IncomingMissile", {
	params["_target"];
	_slippySound = fullCrew _target # 1 # 0;
	
	if ((random 1) == 0) then { _slippySound say3d "Slippy_Missile1"; } else { _slippySound say3d "Slippy_Missile2";};
}];

//Check for Objects behind tail 
//TODO - Add in trees somehow (god help me)
Check_Tail = {
	params ["_vehicle"];
	private["_hasInformed", "_slippyCheck"];
	_hasInformed = false;

	while {(fullCrew _vehicle # 0 # 1) == "driver"} do {

		_slippySound = fullCrew _vehicle # 1 # 0;
		
		if ((getPosATL _vehicle) # 2 < 2 && !_hasInformed) then {
			_slippyCheck = (_vehicle modelToWorld [0, -10, -1.5]) nearObjects 5;
			if ("Thing" countType _slippyCheck > 0 || "Static" countType _slippyCheck > 0) then {				//Thing and Static so far include everything
				_hasInformed = true;
				sleep 2;
				_vehicle vehicleChat "Watch-out Behind You!"; //Test Statement, subject to change
				_slippySound say3d "Slippy_Tail";
			};
		};

		if ((getPosATL _vehicle) # 2 >= 2) then {  //Prevents Spam
			_hasInformed = false;
		};

		sleep 2; //Delay to prevent spam
	};
};

//Talk to player on vehicle entry
vehicle _slippy addEventHandler ["GetIn", {
	params ["_vehicle", "_role", "_unit", "_turret"];
	_pilot = fullCrew _vehicle # 0 # 1;								//pilot check
	
	_slippySound = fullCrew _vehicle # 1 # 0;						//Jank
	if (_pilot == "driver" ) then {
		_slippySound say3D    "Slippy_Intro";
		_vehicle vehicleChat "Don't worry, Slippy's Here!";			//Test Statement
	};

	[_vehicle] spawn Check_Tail;
}];

hint "Events Created";

//TODO add in target found 