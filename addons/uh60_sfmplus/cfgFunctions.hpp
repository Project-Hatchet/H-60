#ifdef __A3_DEBUG__
#define R recompile = 1
#else
#define R recompile = 0
#endif

class CfgFunctions
{
	class vtx_uh60_project_sfmplus
	{
        tag = "vtx_uh60_sfmplus";
		class aero {
			file = "\z\vtx\addons\uh60_sfmplus\functions\aero";
			class aeroStabilator {R;};
		};
		class core {
			file = "\z\vtx\addons\uh60_sfmplus\functions\core";
			class coreConfig {R;};
			class coreUpdate  {R;};
		};
		class damage {
			file = "\z\vtx\addons\uh60_sfmplus\functions\damage";
			class damageApply {R;};
		};
		class engine {
			file = "\z\vtx\addons\uh60_sfmplus\functions\engine";
			class engine  {R;};
			class engineController {R;};
            class engineReset {R;};
			class engineVariables {R;};
		};
		class fuel {
			file = "\z\vtx\addons\uh60_sfmplus\functions\fuel";
			class fuelSet {R;};
		};
		class interact {
			file = "\z\vtx\addons\uh60_sfmplus\functions\interact";
			class interactPowerLever {R;};
			class interactStartSwitch {R;};
		};
		class mass {
			file = "\z\vtx\addons\uh60_sfmplus\functions\mass";
			class massSet {R;};
		};
		class utility {
			file = "\z\vtx\addons\uh60_sfmplus\functions";
			class clampedMove {R;};
			class getArea {R;};
			class getInput {R;};
			class linearInterp {R;};
			//class perFrame {R;};
			class setArrayVariable {R;};
			//class setup {R;};
		};
    };
};