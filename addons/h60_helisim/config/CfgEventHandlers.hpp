class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_Init_EventHandlers {
    class hct_H60_base {
        class hct_h60_helisim_init_eh {
            init = "_this call hct_h60_helisim_fnc_setup";
        };
    };
};

class Extended_GetIn_EventHandlers {
    class hct_H60_base {
        class hct_h60_helisim_getin_eh {
            getIn = "_this call bmkhs_fnc_eventGetIn";
        };
    };
};
