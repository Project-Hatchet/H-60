class vxf_driver: vxf_driver {
    class modules: modules {
        class acre {
            startOnEnter = 1;
        };
    };
    /*class interaction: interaction {
        class acreConfig {
            condition="vtx_uh60_acre_enabled";
            class Knob_radioVolume1 {
                positionType="static";
                position="knob_comm1_R";
                label="Comm 1 volume";
                radius=0.025;
                animation="COMM1_ROT";
                scrollIncrement = 0.2;
                dragRange = 0.3;
                looping = 0;
                animLimits[] = {0, 0.75};
                dragStart="";
                dragging="([0] + _this) call vtx_uh60_acre_fnc_setRadioVolume";
                dragStop="([0] + _this) call vtx_uh60_acre_fnc_setRadioVolume";
            }; // Knob_radioVolume1
            class Knob_radioVolume2: Knob_radioVolume1 {
                position="knob_comm2_R";
                label="Comm 2 volume";
                animation="COMM2_ROT";
                dragging="([1] + _this) call vtx_uh60_acre_fnc_setRadioVolume";
                dragStop="([1] + _this) call vtx_uh60_acre_fnc_setRadioVolume";
            }; // Knob_radioVolume2
            class Knob_radioVolume3: Knob_radioVolume1 {
                position="knob_comm3_R";
                label="Comm 3 volume";
                animation="COMM3_ROT";
                dragging="([2] + _this) call vtx_uh60_acre_fnc_setRadioVolume";
                dragStop="([2] + _this) call vtx_uh60_acre_fnc_setRadioVolume";
            }; // Knob_radioVolume3
            class Knob_radioVolume4: Knob_radioVolume1 {
                position="knob_comm4_R";
                label="Comm 4 volume";
                animation="COMM4_ROT";
                dragging="([3] + _this) call vtx_uh60_acre_fnc_setRadioVolume";
                dragStop="([3] + _this) call vtx_uh60_acre_fnc_setRadioVolume";
            }; // Knob_radioVolume4
            class Knob_masterVolume: Knob_radioVolume1 {
                position="knob_MVOL_R";
                label="Master volume";
                animation="MVOL_ROT";
            }; // Knob_masterVolume
            class knob_tx {
                positionType="static";
                position="knob_tx_R";
                label="TX Mode";
                radius=0.025;
                animation="TX_ROT";
                animSpeed=0;
                looping=0;
                animStates[] = {0, 0.091, 0.182, 0.273, 0.364};
                animLabels[] = {"ICS", "1", "2", "3", "4"};
                animEnd="";
                clickSound="vxf_Switch_Sound";
            }; // knob_tx
        }; // acreConfig
    }; // interaction*/
}; // pilot

class vxf_copilot: vxf_copilot {
    class modules: modules {
        class acre {
            startOnEnter = 1;
        };
    };
    /*class interaction: interaction {
        class acreConfig {
            condition="vtx_uh60_acre_enabled";

        }; // acreConfig
    }; // interaction*/
}; // copilot
