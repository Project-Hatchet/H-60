class Extended_PreInit_EventHandlers {
    class vtx_uh60_helisim_preInit {
        init = "call compile preprocessFileLineNumbers '\z\vtx\addons\uh60_helisim\XEH_preInit.sqf';";
    };
};

class Extended_Init_EventHandlers {
    class vtx_H60_base {
        class vtx_uh60_helisim_init_eh {
            init = "_this call vtx_uh60_helisim_fnc_setup";
        };
    };
};

class Extended_GetIn_EventHandlers {
    class vtx_H60_base {
        class vtx_uh60_helisim_getin_eh {
            getIn = "_this call bmkhs_fnc_eventGetIn";
        };
    };
};
