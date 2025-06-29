class RscDisplayLoadMission;
class RscDisplayLoadProjectHatchet : RscDisplayLoadMission {
	enableDisplay = 1;
	enableSimulation = 1;
	idd = 101;
	movingEnable = 1;
	onLoad = "_this call vtx_uh60_misc_fnc_loadingScreen;";
	onUnload = "_this call vtx_uh60_misc_fnc_loadingScreen;";
	scriptName = "";
	scriptPath = "";
};

