class vxf_driver {
    #include "cfgVehiclesParts\cfgVxfCockpit.hpp"
};

class vxf_copilot {
    #include "cfgVehiclesParts\cfgVxfCockpit.hpp"
};

class vxf_cargo {
    class interaction {
        class l_door {
            clickSound="";
            position="cabindoor_L_handle";
            positionType="anim";
            label="Left Door";
            animation="cabindoor_L";
            interactionCondition="_this call vtx_uh60_misc_fnc_canCloseCabindoor";
            animStates[] = {0, 1};
            animLabels[] = {"Open", "Closed"};
            animEnd="";
            radius=0.1;
            animSpeed=1;
        }; // l_door
        class r_door {
            clickSound="";
            position="cabindoor_R_handle";
            positionType="anim";
            label="Right Door";
            animation="cabindoor_R";
            interactionCondition="_this call vtx_uh60_misc_fnc_canCloseCabindoor";
            animStates[] = {0, 1};
            animLabels[] = {"Open", "Closed"};
            animEnd="";
            radius=0.1;
            animSpeed=1;
        }; // r_door
    };
};
