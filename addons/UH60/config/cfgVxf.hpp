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
            interactionCondition="_this call vtx_uh60_misc_fnc_canInteractCabinDoor";
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
            interactionCondition="_this call vtx_uh60_misc_fnc_canInteractCabinDoor";
            animStates[] = {0, 1};
            animLabels[] = {"Open", "Closed"};
            animEnd="";
            radius=0.1;
            animSpeed=1;
        }; // r_door
        class T_rack1 {
            clickSound="";
            position="b_stretcher_tl";
            positionType="anim";
            label="Top stretcher";
            animation="StretcherRack_Fold_T";
            interactionCondition="_this call vtx_uh60_misc_fnc_canInteractCabinDoor";
            animStates[] = {0, 1};
            animLabels[] = {"Lowered", "Raised"};
            animEnd="";
            radius=0.1;
            animSpeed=1;
        }; // top stretcher
        class T_rack2 {
            clickSound="";
            position="b_stretcher_tr";
            positionType="anim";
            label="Top stretcher";
            animation="StretcherRack_Fold_T";
            interactionCondition="_this call vtx_uh60_misc_fnc_canInteractCabinDoor";
            animStates[] = {0, 1};
            animLabels[] = {"Lowered", "Raised"};
            animEnd="";
            radius=0.1;
            animSpeed=1;
        }; // top stretcher
        class B_rack1 {
            clickSound="";
            position="b_stretcher_bl";
            positionType="anim";
            label="Bottom stretcher";
            animation="StretcherRack_Fold_B";
            interactionCondition="_this call vtx_uh60_misc_fnc_canInteractCabinDoor";
            animStates[] = {0, 1};
            animLabels[] = {"Lowered", "Raised"};
            animEnd="";
            radius=0.1;
            animSpeed=1;
        }; // bottom stretcher
        class B_rack2 {
            clickSound="";
            position="b_stretcher_br";
            positionType="anim";
            label="Bottom stretcher ";
            animation="StretcherRack_Fold_B";
            interactionCondition="_this call vtx_uh60_misc_fnc_canInteractCabinDoor";
            animStates[] = {0, 1};
            animLabels[] = {"Lowered", "Raised"};
            animEnd="";
            radius=0.1;
            animSpeed=1;
        }; // bottom stretcher
    };
};
