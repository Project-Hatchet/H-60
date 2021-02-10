#define MFD_BTN(BTN_VAL,LABEL) \
    class BTN_VAL { \
        positionType="static"; \
        position= BTN_VAL; \
        label=LABEL; \
        radius=0.025; \
        clickSound="vxf_Switch_Sound_2";

#define USERVAL(INDEX,VAL) QUOTE(((getUserMFDValue _this) select INDEX) == VAL)

class mfd_any {
    MFD_BTN(MFD_13,QUOTE(JVMF))
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_JVMF, true)] call vtx_uh60_mfd_fnc_switchPage);
    };
    MFD_BTN(MFD_14,QUOTE(TAC))
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_TAC, true)] call vtx_uh60_mfd_fnc_switchPage);
    };
    MFD_BTN(MFD_15,QUOTE(FLIR))
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_FLIR, true)] call vtx_uh60_mfd_fnc_switchPage);
    };
    MFD_BTN(MFD_16,QUOTE(EICAS))
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_EICAS, true)] call vtx_uh60_mfd_fnc_switchPage);
    };
    MFD_BTN(MFD_18,QUOTE(PFD))
        buttonUp= QUOTE([ARR_4((_this select 0), MFD_PAGE_INDEX, MFD_PAGE_PFD, true)] call vtx_uh60_mfd_fnc_switchPage);
    };
};

class tac {
    condition= USERVAL(MFD_PAGE_INDEX,MFD_PAGE_TAC);
    MFD_BTN(MFD_20,QUOTE(Zoom out)) buttonUp="[vehicle player,'zoom', -1] call vtx_uh60_mfd_fnc_interaction_tac;"; };
    MFD_BTN(MFD_21,QUOTE(Zoom in)) buttonUp="[vehicle player,'zoom', 1] call vtx_uh60_mfd_fnc_interaction_tac;"; };
};

class jvmf {
    condition= USERVAL(MFD_PAGE_INDEX,MFD_PAGE_JVMF);
    MFD_BTN(MFD_23,QUOTE(Prev MSG)) buttonUp="[vehicle player,'cycle', -1] call vtx_uh60_jvmf_fnc_mfdInteraction;"; };
    MFD_BTN(MFD_22,QUOTE(Next MSG)) buttonUp="[vehicle player,'cycle', 1] call vtx_uh60_jvmf_fnc_mfdInteraction;"; };
    MFD_BTN(MFD_8,QUOTE(New message)) buttonUp="createDialog 'vtx_uh60_jvmf_writeDialog';"; };
    MFD_BTN(MFD_1,QUOTE(ACK)) buttonUp="[vehicle player, 'ACK'] call vtx_uh60_jvmf_fnc_reply"; };
    MFD_BTN(MFD_2,QUOTE(WILCO)) buttonUp="[vehicle player, 'WILCO'] call vtx_uh60_jvmf_fnc_reply"; };
    MFD_BTN(MFD_5,QUOTE(HAVECO)) buttonUp="[vehicle player, 'HAVECO'] call vtx_uh60_jvmf_fnc_reply"; };
    MFD_BTN(MFD_6,QUOTE(CANTCO)) buttonUp="[vehicle player, 'CANTCO'] call vtx_uh60_jvmf_fnc_reply"; };
};

class flir {
    condition= USERVAL(MFD_PAGE_INDEX,MFD_PAGE_FLIR);
    MFD_BTN(MFD_5,QUOTE(NAV)) buttonUp="[vehicle player] call vtx_uh60_flir_fnc_nav"; };
};
