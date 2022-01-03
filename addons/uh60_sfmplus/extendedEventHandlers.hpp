class Extended_PreInit_EventHandlers {
	class vtx_uh60_sfmplus_ah64_PreInits {
		init = "call compile preprocessFileLineNumbers 'z\vtx\addons\uh60_sfmplus\functions\event\fn_eventPreInit.sqf';";
	};
};

class Extended_GetIn_EventHandlers {
	class vtx_h60_base {
		class vtx_uh60_sfmplus_ah64base_getin_eh {
			getIn = "_this call vtx_uh60_sfmplus_fnc_eventGetIn";
		};
	};
};

class Extended_Init_EventHandlers {
    class vtx_h60_base {
        class vtx_uh60_sfmplus {
            init = "[_this] spawn vtx_uh60_sfmplus_fnc_coreConfig";
        };
    };
};
