class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};

class Extended_Init_EventHandlers
{
	class Heli_Transport_01_base_F;
	class vtx_H60_base: Heli_Transport_01_base_F {
		class Fat_Lurch_Helicopter_eh { init = ""; };
	};
};
