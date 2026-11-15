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
	// No base class: uh60_config and uh60_helisim re-open this XEH class without one,
	// and a mixed declaration made the result depend on load order. CBA overrides an
	// inherited XEH entry by name, so blanking Fat_Lurch needs no inheritance.
	class hct_H60_base {
		class Fat_Lurch_Helicopter_eh { init = ""; };
	};
};
