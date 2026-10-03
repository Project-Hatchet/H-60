class hct_driver {
    #include "cfgVehiclesParts\cfghctCockpit.hpp"
};

class hct_copilot {
    #include "cfgVehiclesParts\cfghctCockpit.hpp"
};

class hct_cargo {
    class interaction {
        class l_door {
            clickSound = "hct_CabinDoor_Sound";
            position="cabindoor_L_handle";
            positionType="anim";
            label="Left Door";
            animation="cabindoor_L";
            interactionCondition="_this call vtx_uh60_misc_fnc_canInteractCabinDoor";
            animStates[] = {0, 1};
            animLabels[] = {"Open", "Closed"};
            animEnd = "_this call vtx_uh60_misc_fnc_interactedCabinDoor;";
            radius=0.1;
            animSpeed=1;
        }; // l_door
        class r_door {
            clickSound = "hct_CabinDoor_Sound";
            position="cabindoor_R_handle";
            positionType="anim";
            label="Right Door";
            animation="cabindoor_R";
            interactionCondition="_this call vtx_uh60_misc_fnc_canInteractCabinDoor";
            animStates[] = {0, 1};
            animLabels[] = {"Open", "Closed"};
            animEnd = "_this call vtx_uh60_misc_fnc_interactedCabinDoor;";
            radius=0.1;
            animSpeed=1;
        }; // r_door
        class toCockpit {
          condition = "isNull driver hct_vehicle || {isNull (hct_vehicle turretUnit [0])}";
          positionType = "coordinates";
          position[] = POS_MOVE_CABIN_COCKPIT;
          label = "Move To Cockpit";
          radius = 0.1;
          buttonDown = "call vtx_uh60_misc_fnc_moveToCockpit";
        }; // toCockpit
    };
};
