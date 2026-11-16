class Extended_PreInit_EventHandlers {
    class hct_h60_helisim_preInit {
        init = "call compile preprocessFileLineNumbers '\z\vtx\addons\uh60_helisim\XEH_preInit.sqf';";
    };
};

//The pack starts itself. Nothing outside it calls in.
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
