vtx_uh60_misc_fnc_loadingScreen = {

	_setText = {
		params ["_idc", "_text", "_groupIDC"];
		private _ctrl = if (isNil "_groupIDC") then {(_display displayCtrl _idc)} else {((_display displayCtrl _groupIDC) controlsGroupCtrl _idc)};
		_ctrl ctrlSetStructuredText parseText _text;
		// _ctrl ctrlSetText _text;
		_ctrl ctrlShow true;
		_ctrl ctrlCommit 0;
	};
	params ["_display", "_action"];
	if(vtx_uh60_ui_showDebugMessages) then {systemchat str _this;};
	(_display displayCtrl 1001) ctrlSetText "Project Hatchet H-60 Pack";
	(_display displayCtrl 1001) ctrlShow false;
	(_display displayCtrl 1001) ctrlCommit 0;
	[1001, "Project Hatchet H-60 Pack"] call _setText;
	[1002, "By the Project Hatchet Team"] call _setText;
	[1102, "Map description goes here"] call _setText;

	// (_display displayCtrl 2300)  ctrlShow true; // mission
	// (_display displayCtrl 2300) ctrlCommit 0; // mission

	(_display displayCtrl 999) ctrlShow true; // idk
	(_display displayCtrl 999) ctrlSetText "\z\vtx\addons\UH60_Misc\data\splash\construction.paa";
	(_display displayCtrl 999) ctrlSetPosition [safezonex, safezoney, safezonew, safezoneh];
	(_display displayCtrl 999) ctrlCommit 0; // idk


	(_display displayCtrl 2310)  ctrlShow false; // arma 3 image in background
	(_display displayCtrl 2310) ctrlCommit 0; // arma 3 image in background

	(_display displayCtrl 2301) ctrlShow true; // disclaimer
	(_display displayCtrl 2301) ctrlCommit 0; // disclaimer
	[1009, "Project Hatchet Loader", 2301] call _setText;
	[1101, "Loading the Project Hatchet H-60 Pack<br/>Due to technical limitations of the arma engine, we need to pre-load the Hathet H-60 Pack to avoid loading freezes during gameplay.", 2301] call _setText;

	(_display displayCtrl 104) progressSetPosition 0.5; // loading bar
	(_display displayCtrl 104) ctrlCommit 0;
};

[] spawn {
sleep 0.1;
findDisplay 46 createDisplay "RscDisplayLoadProjectHatchet";
};
