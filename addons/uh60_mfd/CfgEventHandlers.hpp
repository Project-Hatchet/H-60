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

class Extended_Init_EventHandlers {
    class vtx_H60_base {
        // Weapon vtx_pylon_mfd was added to stop rpt spam from MFD dummy pylons
        class ADDON {
            init = QUOTE(call FUNC(initPylons));;
        };
    };
};
