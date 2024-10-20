#define MFD_BTN(BTN_VAL,LABEL) \
    class BTN_VAL { \
        positionType="static"; \
        position= BTN_VAL; \
        label=LABEL; \
        radius=0.025; \
        clickSound="vxf_Switch_Sound_2";

#define USERVAL(INDEX,VAL) QUOTE(((getUserMFDValue _this) select INDEX) == VAL)
#define MAINPAGE(INDEX,VAL) QUOTE((((getUserMFDValue _this) select INDEX) > (VAL - 0.01)) && (((getUserMFDValue _this) select INDEX) < (VAL + 0.99)))

class mfd_any {
    MFD_BTN(MFD_13,QUOTE(JVMF))
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_JVMF, true)] call vtx_uh60_mfd_fnc_switchPage);
    };
    MFD_BTN(MFD_14,QUOTE(TAC))
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_TAC, true)] call vtx_uh60_mfd_fnc_switchPage);
    };
    MFD_BTN(MFD_16,QUOTE(EICAS))
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_EICAS, true)] call vtx_uh60_mfd_fnc_switchPage);
    };
    MFD_BTN(MFD_17,QUOTE(ND))
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_ND, true)] call vtx_uh60_mfd_fnc_switchPage);
    };
    MFD_BTN(MFD_18,QUOTE(PFD))
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_PFD, true)] call vtx_uh60_mfd_fnc_switchPage);
    };
};


class pfd {
    condition = MAINPAGE(MFD_PAGE_INDEX,MFD_PAGE_PFD);
    class SUBPAGE_HSI {
        condition = USERVAL(MFD_PAGE_INDEX,PFD_MODE_HSI);
        MFD_BTN(MFD_15,QUOTE(Arc Display))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, PFD_MODE_ARC, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
    };
    class SUBPAGE_ARC {
        condition = USERVAL(MFD_PAGE_INDEX,PFD_MODE_ARC);
        MFD_BTN(MFD_15,QUOTE(Hover Display))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, PFD_MODE_HVR, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
    };
    class SUBPAGE_HVR {
        condition = USERVAL(MFD_PAGE_INDEX,PFD_MODE_HVR);
        MFD_BTN(MFD_15,QUOTE(HSI))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, PFD_MODE_HSI, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
    };
};

class eicas {
    condition= USERVAL(MFD_PAGE_INDEX,MFD_PAGE_EICAS);
    MFD_BTN(MFD_15,QUOTE(IVHMS)) buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_IVHMS, true)] call vtx_uh60_mfd_fnc_switchPage); };
    class COND_SHOW_CCFS {
        condition = QUOTE(SHOW_CCFS == 1);
        MFD_BTN(MFD_4,QUOTE(CCFS))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_CCFS_MENU, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
    };
    MFD_BTN(MFD_3,QUOTE(Test))
        buttonDown ="for ""_i"" from 16 to 39 do {[_this select 0, _i, 2] call vtx_uh60_mfd_fnc_setPylonValue;};vtx_uh60_mfd_eicas_testing = true;";
        buttonUp   ="[_this select 0, false, true] call vtx_uh60_cas_fnc_setMasterCaution;vtx_uh60_mfd_eicas_testing = false;";
    };
};

class tac {
    condition = MAINPAGE(MFD_PAGE_INDEX,MFD_PAGE_TAC);
    MFD_BTN(MFD_15,QUOTE(FLIR)) buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_FLIR, true)] call vtx_uh60_mfd_fnc_switchPage); };
    MFD_BTN(MFD_4,QUOTE(Center mode)) buttonUp="[vehicle player,4] call vtx_uh60_mfd_fnc_cyclePylonValue;"; };
    MFD_BTN(MFD_20,QUOTE(Zoom out)) buttonUp="[vehicle player,'zoom', -1] call vtx_uh60_mfd_fnc_interaction_tac;"; };
    MFD_BTN(MFD_21,QUOTE(Zoom in)) buttonUp="[vehicle player,'zoom', 1] call vtx_uh60_mfd_fnc_interaction_tac;"; };
    // MFD_BTN(MFD_24,QUOTE(Orientation)) buttonUp="[vehicle player,5] call vtx_uh60_mfd_fnc_cyclePylonValue;"; };
    class mainPage {
        condition = USERVAL(MFD_PAGE_INDEX,MFD_PAGE_TAC);
        class RegularRightPanel {
            condition = "(_this ammoOnPylon 3) == 0";
            MFD_BTN(MFD_7,QUOTE(Map Mode)) 
                buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, TAC_MODE_MAPCONF, true)] call vtx_uh60_mfd_fnc_switchPage);
            };
            MFD_BTN(MFD_11,QUOTE(Map movement)) buttonUp="[vehicle player,7] call vtx_uh60_mfd_fnc_cyclePylonValue;"; };
        };
        class CASOverlayOpen {
            condition = "(_this ammoOnPylon 3) > 0";
            MFD_BTN(MFD_9,QUOTE(Hide CAS Display)) buttonUp="[vehicle player,'false', true] call vtx_uh60_cas_fnc_updateOverlayList;"; };
        };
    };
    
    class SUBPAGE_MAPCONF {
        condition = USERVAL(MFD_PAGE_INDEX,TAC_MODE_MAPCONF);
        MFD_BTN(MFD_8,QUOTE(Topo)) 
            buttonUp="[vehicle player, 'topo'] call vtx_uh60_mfd_fnc_tac_setMapTexture";
        };
        MFD_BTN(MFD_9,QUOTE(Sat)) 
            buttonUp="[vehicle player, 'sat'] call vtx_uh60_mfd_fnc_tac_setMapTexture";
        };
        MFD_BTN(MFD_10,QUOTE(Custom)) 
            buttonUp="[vehicle player, 'cust'] call vtx_uh60_mfd_fnc_tac_setMapTexture";
        };
        MFD_BTN(MFD_11,QUOTE(Off)) 
            buttonUp="[vehicle player, 'off'] call vtx_uh60_mfd_fnc_tac_setMapTexture";
        };
        MFD_BTN(MFD_12,QUOTE(Return)) 
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_TAC, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
    };
};

class jvmf {
    condition= USERVAL(MFD_PAGE_INDEX,MFD_PAGE_JVMF);
    MFD_BTN(MFD_24,QUOTE(New message)) buttonUp="createDialog 'vtx_uh60_jvmf_writeDialog';"; };
    MFD_BTN(MFD_23,QUOTE(Prev MSG)) buttonUp="[vehicle player,'cycle', -1] call vtx_uh60_jvmf_fnc_mfdInteraction;"; };
    MFD_BTN(MFD_22,QUOTE(Next MSG)) buttonUp="[vehicle player,'cycle', 1] call vtx_uh60_jvmf_fnc_mfdInteraction;"; };
    MFD_BTN(MFD_21,QUOTE(Sel Waypt)) buttonUp="[vehicle player,'waypt'] call vtx_uh60_jvmf_fnc_mfdInteraction;"; };
    MFD_BTN(MFD_3,QUOTE(ACK)) buttonUp="[vehicle player, 'ACK'] call vtx_uh60_jvmf_fnc_reply"; };
    MFD_BTN(MFD_4,QUOTE(WILCO)) buttonUp="[vehicle player, 'WILCO'] call vtx_uh60_jvmf_fnc_reply"; };
    MFD_BTN(MFD_5,QUOTE(HAVECO)) buttonUp="[vehicle player, 'HAVECO'] call vtx_uh60_jvmf_fnc_reply"; };
    MFD_BTN(MFD_6,QUOTE(CANTCO)) buttonUp="[vehicle player, 'CANTCO'] call vtx_uh60_jvmf_fnc_reply"; };
    MFD_BTN(MFD_15,QUOTE(IVHMS)) buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_IVHMS, true)] call vtx_uh60_mfd_fnc_switchPage); };
};

class flir {
    condition= MAINPAGE(MFD_PAGE_INDEX,MFD_PAGE_FLIR);
    class stowed {
        condition = USERVAL(MFD_PAGE_INDEX,FLIR_MODE_STOWED);
        MFD_BTN(MFD_1,QUOTE(DEPLOY FLIR))
            buttonUp= QUOTE([ARR_3((_this select 0), 'UNSTOW', MFD_PAGE_INDEX)] call vtx_uh60_flir_fnc_interaction);
        };
    };
    class home {
        condition = USERVAL(MFD_PAGE_INDEX,MFD_PAGE_FLIR);
        MFD_BTN(MFD_1,QUOTE(WPN MENU))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, FLIR_MODE_ATTACK, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
        MFD_BTN(MFD_6,QUOTE(LSR MENU))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, FLIR_MODE_LASER, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
        MFD_BTN(MFD_11,QUOTE(Slew To Waypoint)) buttonUp="[vxf_vehicle,'WAYPT_SLEW'] call vtx_uh60_flir_fnc_interaction"; };
        MFD_BTN(MFD_12,QUOTE(Create Waypoint)) buttonUp="[vxf_vehicle,'WAYPT_CREATE'] call vtx_uh60_flir_fnc_interaction"; };
    };
    class attack {
        condition = USERVAL(MFD_PAGE_INDEX,FLIR_MODE_ATTACK);
        MFD_BTN(MFD_1,QUOTE(DECLUTTER))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_FLIR, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
        MFD_BTN(MFD_6,QUOTE(LSR MENU))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, FLIR_MODE_LASER, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
        MFD_BTN(MFD_7,QUOTE(Primary Channel)) buttonUp="[vxf_vehicle,'PRI_CHAN'] call vtx_uh60_weapons_fnc_interaction"; };
        MFD_BTN(MFD_8,QUOTE(Alternative Channel)) buttonUp="[vxf_vehicle,'ALT_CHAN'] call vtx_uh60_weapons_fnc_interaction"; };
        MFD_BTN(MFD_9,QUOTE(Launch Trajectory)) buttonUp="[vxf_vehicle,'HF_TRAJ'] call vtx_uh60_weapons_fnc_interaction"; };
        MFD_BTN(MFD_12,QUOTE(Weapon Control))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, FLIR_MODE_WPN_ASSIGN, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
    };
    class weapon_assign {
        condition = USERVAL(MFD_PAGE_INDEX,FLIR_MODE_WPN_ASSIGN);
        MFD_BTN(MFD_12,QUOTE(Weapon Control))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, FLIR_MODE_ATTACK, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
        MFD_BTN(MFD_7,QUOTE(Pilot)) buttonUp="[vxf_vehicle,'RIB','PILOT'] call vtx_uh60_weapons_fnc_interaction"; };
        MFD_BTN(MFD_8,QUOTE(Copilot)) buttonUp="[vxf_vehicle,'RIB','COPILOT'] call vtx_uh60_weapons_fnc_interaction"; };
        MFD_BTN(MFD_9,QUOTE(Pilot)) buttonUp="[vxf_vehicle,'ROB','PILOT'] call vtx_uh60_weapons_fnc_interaction"; };
        MFD_BTN(MFD_10,QUOTE(Copilot)) buttonUp="[vxf_vehicle,'ROB','COPILOT'] call vtx_uh60_weapons_fnc_interaction"; };
        
        MFD_BTN(MFD_24,QUOTE(Pilot)) buttonUp="[vxf_vehicle,'LIB','PILOT'] call vtx_uh60_weapons_fnc_interaction"; };
        MFD_BTN(MFD_23,QUOTE(Copilot)) buttonUp="[vxf_vehicle,'LIB','COPILOT'] call vtx_uh60_weapons_fnc_interaction"; };
        MFD_BTN(MFD_22,QUOTE(Pilot)) buttonUp="[vxf_vehicle,'LOB','PILOT'] call vtx_uh60_weapons_fnc_interaction"; };
        MFD_BTN(MFD_21,QUOTE(Copilot)) buttonUp="[vxf_vehicle,'LOB','COPILOT'] call vtx_uh60_weapons_fnc_interaction"; };
    };
    class laser {
        condition = USERVAL(MFD_PAGE_INDEX,FLIR_MODE_LASER);
        MFD_BTN(MFD_1,QUOTE(WPN MENU))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, FLIR_MODE_ATTACK, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
        MFD_BTN(MFD_6,QUOTE(DECLUTTER))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_FLIR, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
        MFD_BTN(MFD_7,QUOTE(Laser Spot Tracker Channel)) buttonUp="[vxf_vehicle,'LST_CHAN'] call vtx_uh60_flir_fnc_interaction"; };
        MFD_BTN(MFD_8,QUOTE(Laser Spot Tracker Mode)) buttonUp="[vxf_vehicle,'LST_MODE'] call vtx_uh60_flir_fnc_interaction"; };
        MFD_BTN(MFD_24,QUOTE(Laser Designator Channel)) buttonUp="[vxf_vehicle,'LRFD_CHAN'] call vtx_uh60_flir_fnc_interaction"; };
    };
    // MFD_BTN(MFD_1,QUOTE(LASE)) buttonUp="[vxf_vehicle,'LASER'] call vtx_uh60_weapons_fnc_interaction"; };
    // MFD_BTN(MFD_7,QUOTE(CHAN)) buttonUp="[vxf_vehicle,'HF_CHAN'] call vtx_uh60_weapons_fnc_interaction"; };
    // MFD_BTN(MFD_8,QUOTE(TRAJ)) buttonUp="[vxf_vehicle,'HF_TRAJ'] call vtx_uh60_weapons_fnc_interaction"; };
    // // MFD_BTN(MFD_4,QUOTE(WPT)) buttonUp="[vxf_vehicle] call vtx_uh60_flir_fnc_mfdWaypoint"; };
    // // MFD_BTN(MFD_5,QUOTE(NAV)) buttonUp="[vxf_vehicle] call vtx_uh60_flir_fnc_mfdNav"; };
    // // MFD_BTN(MFD_6,QUOTE(SLG)) buttonUp="[vxf_vehicle] call vtx_uh60_mfd_fnc_slingCam"; };
    // MFD_BTN(MFD_15,QUOTE(IVHMS)) buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_IVHMS, true)] call vtx_uh60_mfd_fnc_switchPage); };
    
    // MFD_BTN(MFD_20,QUOTE(MSL)) buttonUp="[vxf_vehicle,'SEL_MSL'] call vtx_uh60_weapons_fnc_interaction"; };
    // MFD_BTN(MFD_23,QUOTE(RKT)) buttonUp="[vxf_vehicle,'SEL_RKT'] call vtx_uh60_weapons_fnc_interaction"; };
    // MFD_BTN(MFD_24,QUOTE(GUN)) buttonUp="[vxf_vehicle,'SEL_GUN'] call vtx_uh60_weapons_fnc_interaction"; };
};

class nd {
    condition = MAINPAGE(MFD_PAGE_INDEX,MFD_PAGE_ND);
    class SUBPAGE_ALL {
        condition = USERVAL(MFD_PAGE_INDEX,ND_MODE_ALL);
        MFD_BTN(MFD_2,QUOTE(Declutter))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, ND_MODE_NAV, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
    };
    class SUBPAGE_NAV {
        condition = USERVAL(MFD_PAGE_INDEX,ND_MODE_NAV);
        MFD_BTN(MFD_2,QUOTE(Declutter))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, ND_MODE_CMWS, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
    };
    class SUBPAGE_CMWS {
        condition = USERVAL(MFD_PAGE_INDEX,ND_MODE_CMWS);
        MFD_BTN(MFD_2,QUOTE(Declutter))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, ND_MODE_HOVER, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
    };
    class SUBPAGE_HOVER {
        condition = USERVAL(MFD_PAGE_INDEX,ND_MODE_HOVER);
        MFD_BTN(MFD_2,QUOTE(Declutter))
            buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, ND_MODE_ALL, true)] call vtx_uh60_mfd_fnc_switchPage);
        };
    };
    
    class RegularRightPanel {
        condition = "(_this ammoOnPylon 3) == 0";
        MFD_BTN(MFD_9,QUOTE(Next Waypoint)) buttonUp="[vehicle player,""cycle"", 1] call vtx_uh60_fms_fnc_interaction_waypoint;"; };
        MFD_BTN(MFD_10,QUOTE(Previous Waypoint)) buttonUp="[vehicle player,""cycle"", -1] call vtx_uh60_fms_fnc_interaction_waypoint;"; };
    };
    class CASOverlayOpen {
        condition = "(_this ammoOnPylon 3) > 0";
        MFD_BTN(MFD_9,QUOTE(Hide CAS Display)) buttonUp="[vehicle player,'false', true] call vtx_uh60_cas_fnc_updateOverlayList;"; };
    };
    MFD_BTN(MFD_15,QUOTE(IVHMS)) buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_IVHMS, true)] call vtx_uh60_mfd_fnc_switchPage); };
};

class ccfs_menu {
    condition= USERVAL(MFD_PAGE_INDEX,MFD_PAGE_CCFS_MENU);
    MFD_BTN(MFD_20,QUOTE(Join game))
        buttonUp= QUOTE([ARR_3((_this select 0), 1, MFD_PAGE_INDEX)] call vtx_uh60_mfd_fnc_ccfs_interaction_ccfs);
    };
    MFD_BTN(MFD_21,QUOTE(Next room))
        buttonUp= QUOTE([ARR_3((_this select 0), 2, MFD_PAGE_INDEX)] call vtx_uh60_mfd_fnc_ccfs_interaction_ccfs);
    };
    MFD_BTN(MFD_22,QUOTE(Prev room))
        buttonUp= QUOTE([ARR_3((_this select 0), 3, MFD_PAGE_INDEX)] call vtx_uh60_mfd_fnc_ccfs_interaction_ccfs);
    };
    MFD_BTN(MFD_23,QUOTE(Host game))
        buttonUp= QUOTE([ARR_3((_this select 0), 4, MFD_PAGE_INDEX)] call vtx_uh60_mfd_fnc_ccfs_interaction_ccfs);
    };
    MFD_BTN(MFD_15,QUOTE(IVHMS)) 
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_IVHMS, true)] call vtx_uh60_mfd_fnc_switchPage); 
    };
};

class ccfs_game {
    condition= USERVAL(MFD_PAGE_INDEX,MFD_PAGE_CCFS);
    MFD_BTN(MFD_1,QUOTE(Exit))
        buttonUp= QUOTE([ARR_3((_this select 0), 5, MFD_PAGE_INDEX)] call vtx_uh60_mfd_fnc_ccfs_interaction_ccfs);
    };
    MFD_BTN(MFD_6,QUOTE(Pause/Play))
        buttonUp= QUOTE([ARR_3((_this select 0), 6, MFD_PAGE_INDEX)] call vtx_uh60_mfd_fnc_ccfs_interaction_ccfs);
    };
    MFD_BTN(MFD_15,QUOTE(IVHMS)) 
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_IVHMS, true)] call vtx_uh60_mfd_fnc_switchPage); 
    };
};


class ivhms {
    condition= USERVAL(MFD_PAGE_INDEX,MFD_PAGE_IVHMS);
    MFD_BTN(MFD_4,QUOTE(Exit))
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_IVHMS_NUMS, true)] call vtx_uh60_mfd_fnc_switchPage); 
    };
};