//BMKHS_CONTROL redefined: Core's uses __EVAL, which Addon Builder compiles to <null>.
#include "\bmkhs_helisim\controlMacros.hpp"

#undef BMKHS_CONTROL
#define BMKHS_CONTROL(cname,ptok,pnum,vdisplayName) \
class bmkhs_ctrl_##cname##_##ptok {\
    displayName = vdisplayName;\
    tooltip     = vdisplayName;\
    onActivate  = QUOTE(if (vehicle player isKindOf 'vtx_H60_base') then {[ARR_3(vehicle player,'cname',pnum)] call vtx_uh60_helisim_fnc_cockpitBind});\
}

class CfgUserActions {
    #include "..\headers\bmkhs_controls.hpp"
};

#undef QUOTE
#define QUOTE(x) #x
#define BMKHS_CTRL_CLASS(cname,ptok) bmkhs_ctrl_##cname##_##ptok
#undef BMKHS_CONTROL
#define BMKHS_CONTROL(cname,ptok,pnum,vdisplayName) QUOTE(BMKHS_CTRL_CLASS(cname,ptok))
#undef BMKHS_CONTROL_SEP
#define BMKHS_CONTROL_SEP() ,

class UserActionGroups {
    class vtx_uh60_cockpit_helisim {
        name = "UH-60 HeliSim Cockpit Controls";
        group[] = {
            #include "..\headers\bmkhs_controls.hpp"
        };
    };
};
