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

//The pack starts itself. Nothing outside it calls in.
class Extended_Init_EventHandlers {
    class vtx_H60_base {
        class ADDON {
            init = QUOTE(_this call FUNC(setup));
        };
    };
};

//Restarts the aircraft's frame clock on entry, so the first frame does not see the whole time
//the aircraft sat empty.
class Extended_GetIn_EventHandlers {
    class vtx_H60_base {
        class ADDON {
            getIn = "_this call bmkhs_fnc_eventGetIn";
        };
    };
};
