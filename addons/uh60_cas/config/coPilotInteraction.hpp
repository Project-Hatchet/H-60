class cas_panel {
    class MasterCaution {
        positionType="coordinates";
        position[]={-0.58,5.1,-0.23};
        label="Master Caution";
        radius=0.1;
        clickSound="hct_Switch_Sound";
        buttonUp="_this call vtx_uh60_cas_fnc_clearCautionsList";
    };
};

class landinglight {
    class landinglight_elev {
        positionType="anim";
        position="b_landinglight_l";
        label="Landing Light";
        radius=0.025;
        animation="landinglight_elev";
        scrollIncrement = 0.05;
        dragRange = 0.4;
        looping = 0;
        animLimits[] = {0, RAD90};
        dragStart="";
        dragging="";
        dragStop="";
        buttonUp="vtx_uh60_misc_landingLightOn = !vtx_uh60_misc_landingLightOn; _this call vtx_uh60_misc_fnc_toggleLights;";
    }; // landinglight_elev
};
class searchlight {
    class searchlight {
        positionType="anim";
        position="b_searchlight_l";
        label="Search Light";
        radius=0.025;
        animation="searchlight_elev";
        animationH="searchlight_turn";
        scrollIncrement = 0.05;
        dragRange = 0.4;
        looping = 0;
        animLimits[] = {0, RAD90};
        animLimitsH[] = {-RAD90, RAD90};
        dragStart="";
        dragging="";
        dragStop="";
        buttonUp="vtx_uh60_misc_searchLightOn = !vtx_uh60_misc_searchLightOn; _this call vtx_uh60_misc_fnc_toggleLights;";
    }; // searchlight
};
