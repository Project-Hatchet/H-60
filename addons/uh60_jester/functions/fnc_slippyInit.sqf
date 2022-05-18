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
		if ((random 1) == 0) then { _slippySound say3d "Death1"; } else {_slippySound say3d "Death2";};
		vehicle _unit vehicleChat "Aaah!";
	};
}];

vehicle _slippy addEventHandler ["IncomingMissile", {
	params["_target"];
	_slippySound = fullCrew _target # 1 # 0;
	_rng = (random 3)
	if (_rng == 0) then { _slippySound say3d "Missile1"; } else-if (_rng == 1) then { _slippySound say3d "Missile2";} else-if (_rng == 2) then { _slippySound say3d "Missile2";} else { _slippySound say3d "Missile3";};
}];

//Check for Objects behind tail 
Check_Tail = {
	params ["_vehicle"];
	private["_hasInformed", "_slippyCheckThing", "_slippyCheckTerrain"];
	_hasInformed = false;

	while {(fullCrew _vehicle # 0 # 1) == "driver"} do {

		_slippySound = fullCrew _vehicle # 1 # 0;
		
		if ((getPosATL _vehicle) # 2 < 2 && !_hasInformed) then {
			_slippyCheckThing = (_vehicle modelToWorld [0, -10, -1.5]) nearObjects 5;
			_slippyCheckTerrain = nearestTerrainObjects[(_vehicle modelToWorld [0, -10, -1.5]),[],5];
			if ("Thing" countType _slippyCheckThing > 0 || count _slippyCheckTerrain > 0) then {				//Thing and Static so far include everything
				_hasInformed = true;
				sleep 2;
				_vehicle vehicleChat "Watch-out Behind You!"; //Test Statement, subject to change
				_rng = (random 2)
				if (_rng == 0) then { _slippySound say3d "Tail1"; } else-if (_rng == 1) then { _slippySound say3d "Tail2";} else { _slippySound say3d "Tail3";};
			};
		};

		if ((getPosATL _vehicle) # 2 >= 2) then {  //Prevents Spam
			_hasInformed = false;
		};

		sleep 2; //Delay to prevent spam
	};
};
/*
//Talk to player on vehicle entry
vehicle _slippy addEventHandler ["GetIn", {
	params ["_vehicle", "_role", "_unit", "_turret"];
	_pilot = fullCrew _vehicle # 0 # 1;								//pilot check
	
	_slippySound = fullCrew _vehicle # 1 # 0;						//Jank
	if (_pilot == "driver" ) then {
		_slippySound say3D    "Intro";
		_vehicle vehicleChat "Don't worry, Slippy's Here!";			//Test Statement
	};

	[_vehicle] spawn Check_Tail;
}];
*/
//Cargo All Out
vehicle _slippy addEventHandler ["GetOut", {
	params ["_vehicle", "_role", "_unit", "_turret"];
	private["_hasCargo"];
	
	_slippySound = fullCrew _vehicle # 1 # 0;						//Jank
	_hasCargo = false;
	{
		if ((assignedVehicleRole (_x # 0)) # 0 == "cargo") then {
			_hasCargo = true;
		}; 
	} forEach (fullCrew _vehicle);

	if (!_hasCargo) then {
		_rng = (random 2)
		if (_rng == 0) then { _slippySound say3d "AllOut1"; } else-if (_rng == 1) then { _slippySound say3d "AllOut2";} else { _slippySound say3d "AllOut3";};
		_vehicle vehicleChat "Let's Go!";			//Test Statement
	};
	hint "I made it!";
}];

hint "Events Created";

//TODO add in target found 
//TODO Startup checks