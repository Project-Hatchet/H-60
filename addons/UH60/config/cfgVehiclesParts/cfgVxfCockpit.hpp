projectPrefix = "vtx_uh60";
class modules {
    class engine {
        startOnEnter = 1;
    };
    class fd: engine {};
    class jvmf: engine {};
    class flir: engine {};
    class misc: engine {};
    class cas: engine {};
    class ui: engine {
        startOnEnter = 0;
    };
};
class interaction {
    crossHair=0;
    #include "interaction\help.hpp"
    class startUp {
        #define BTN_RADIUS_SWITCH 0.015
        class Lights_collision {
            positionType="static";
            position="b_lights_collision";
            label="Collision lights";
            radius=BTN_RADIUS_SWITCH;
            animation="Switch_lights_collision";
            animSpeed=0;
            animStates[] = {0.5, 1};
            animLabels[] = {"OFF", "ON"};
            animEnd="(_this # 0) setCollisionLight !(isCollisionLightOn (_this # 0))";
            clickSound="vxf_Switch_Sound";
        }; // Lights_collision
        class Lights_position {
            positionType="static";
            position="b_lights_position";
            label="Position lights";
            radius=BTN_RADIUS_SWITCH;
            animation="Switch_lights_position";
            animSpeed=0;
            animStates[] = {0.5, 1};
            animLabels[] = {"OFF", "ON"};
            animEnd="_this call vtx_uh60_misc_fnc_toggleLights";
            clickSound="vxf_Switch_Sound";
        }; // Lights_position
        class Lights_cockpit {
            positionType="static";
            position="b_lights_cockpit";
            label="Cockpit light";
            radius=BTN_RADIUS_SWITCH;
            animation="Switch_lights_cockpit";
            animSpeed=0;
            animStates[] = {0.5, 1};
            animLabels[] = {"OFF", "ON"};
            animEnd="_this call vtx_uh60_misc_fnc_toggleLights";
            clickSound="vxf_Switch_Sound";
        }; // Lights_position
        class fuelPump {
            positionType="static";
            position="b_fuelpump";
            label="Fuel Pump";
            radius=BTN_RADIUS_SWITCH;
            animation="Switch_fuelpump";
            animSpeed=0;
            animStates[] = {0.5, 0};
            animLabels[] = {"OFF", "APU BOOST"};
            animEnd="_this call vtx_uh60_engine_fnc_apuState";
            clickSound="vxf_Switch_Sound";
        }; // fuelPump
        class apucont {
            positionType="static";
            position="b_apucont";
            label="APU CONT";
            radius=BTN_RADIUS_SWITCH;
            animation="Switch_apucont";
            animSpeed=0;
            animStates[] = {0.5, 0};
            animLabels[] = {"OFF", "ON"};
            animEnd="_this call vtx_uh60_engine_fnc_apuState; _this call vtx_uh60_engine_fnc_batteryState";
            clickSound="vxf_Switch_Sound_3";
        }; // apucont
        class b_airsce : apucont {
            position="b_airsce";
            label="AIR SCE";
            animation="Switch_airsce";
            animStates[] = {1, 0.5, 0};
            animLabels[] = {"ENG" ,"OFF", "APU"};
            clickSound="vxf_Switch_Sound_3";
            animEnd="";
        }; // b_airsce
        class b_batt1 : apucont {
            position="b_batt1";
            label="BATT 1";
            animation="Switch_batt1";
            animEnd="_this call vtx_uh60_engine_fnc_batteryState";
            clickSound="vxf_Switch_Sound_3";
        }; // b_batt1
        class b_batt2 : b_batt1 {
            position="b_batt2";
            label="BATT 2";
            animation="Switch_batt2";
            animEnd="_this call vtx_uh60_engine_fnc_batteryState";
        }; // b_batt2
        class b_stbyinst : b_batt1 {
            position="b_stbyinst";
            label="STBY INST";
            animation="Switch_stbyinst";
            animLabels[] = {"OFF", "ARM"};
            animEnd="_this call vtx_uh60_engine_fnc_batteryState";
        }; // b_stbyinst
        class b_fuelboostpump1 : b_batt1 {
            position="b_fuelboostpump1";
            label="FUEL PUMP BOOST 1";
            animation="Switch_fuelboostpump1";
        }; // b_fuelboostpump1
        class b_fuelboostpump2 : b_batt1 {
            position="b_fuelboostpump2";
            label="FUEL PUMP BOOST 2";
            animation="Switch_fuelboostpump2";
        }; // b_fuelboostpump2
        class b_gen1 : b_batt1 {
            position="b_gen1";
            label="GEN 1";
            animation="Switch_gen1";
            animEnd="_this call vtx_uh60_engine_fnc_batteryState";
        }; // b_gen1
        class b_gen2 : b_batt1 {
            position="b_gen2";
            label="GEN 2";
            animation="Switch_gen2";
            animEnd="_this call vtx_uh60_engine_fnc_batteryState";
        }; // b_gen2
        class b_apugen : b_batt1 {
            position="b_apugen";
            label="APU GEN";
            animation="Switch_apugen";
            animEnd="_this call vtx_uh60_engine_fnc_apuState; _this call vtx_uh60_engine_fnc_batteryState";
        }; // b_apugen
        class b_fuelsys1 {
            positionType="anim";
            position="b_fuelsys1";
            label="FUEL SYS 1";
            radius=0.035;
            animSpeed=1;
            animation="Lever_fuelsys1";
            animStates[] = {0,0.6,1};
            animLabels[] = {"OFF", "DIR","XFD"};
            animEnd="[(_this # 0), false, ""fuel""] remoteExecCall [""vtx_uh60_engine_fnc_engineEH"", crew (_this # 0)];diag_log ""fuelsys"";";
        }; // b_fuelsys1
        class b_fuelsys2: b_fuelsys1 {
            position="b_fuelsys2";
            label="FUEL SYS 2";
            animation="Lever_fuelsys2";
        }; // b_fuelsys2
        class b_ignition {
            positionType="static";
            position="b_ignition";
            label="Engine Ignition";
            radius=0.045;
            animSpeed=5;
            animation="Switch_ignition";
            animStates[] = {0, 1};
            animLabels[] = {"OFF", "ON"};
            animEnd="_this call vtx_uh60_engine_fnc_starterState";
        }; // b_ignition
        class b_starter1 {
            positionType="anim";
            position="b_starter1";
            label="Engine Start 1";
            radius=0.025;
            buttonUp="[_this # 0, ""STARTER1"", ""ON""] call vtx_uh60_engine_fnc_starterState";
            clickSound="vxf_Switch_Sound";
        }; // b_starter1
        class b_starter2 {
            positionType="anim";
            position="b_starter2";
            label="Engine Start 2";
            radius=0.025;
            buttonUp="[_this # 0, ""STARTER2"", ""ON""] call vtx_uh60_engine_fnc_starterState";
            clickSound="vxf_Switch_Sound";
        }; // b_starter2
        class powerContRFM {
            condition="!difficultyEnabledRTD";
            class b_engpowercont1 {
                interactionCondition = "_this call vtx_uh60_engine_fnc_rotorBrakeInterlock";
                positionType="anim";
                position="b_engpowercont1";
                label="ENG POWER CONT 1";
                radius=0.035;
                animation="Lever_engpower1";
                animSpeed=0.5;
                animStates[] = {0,0.85};
                animLabels[] = {"OFF","FLY"};
                animEnd="[(_this # 0), (_this # 2 != ""OFF"")] remoteExecCall [""vtx_uh60_engine_fnc_engineEH"", crew (_this # 0)];diag_log ""powercont"";";
            }; // b_engpowercont1
            class b_engpowercont2: b_engpowercont1 {
                position="b_engpowercont2";
                label="ENG POWER CONT 2";
                animation="Lever_engpower2";
            }; // b_engpowercont2
        }; // powerContRFM
        class powerContRTD {
            condition="difficultyEnabledRTD";
            class b_engpowercont1 {
                interactionCondition = "_this call vtx_uh60_engine_fnc_rotorBrakeInterlock";
                positionType="anim";
                position="b_engpowercont1";
                label="ENG POWER CONT 1";
                radius=0.035;
                animation="Lever_engpower1";
                animSpeed=0.5;
                animStates[] = {0,0.23,0.85};
                animLabels[] = {"OFF", "IDLE","FLY"};
                animEnd="[(_this # 0), (_this # 2 != ""OFF"")] remoteExecCall [""vtx_uh60_engine_fnc_engineEH"", crew (_this # 0)];diag_log ""powerocnt"";";
            }; // b_engpowercont1
            class b_engpowercont2: b_engpowercont1 {
                position="b_engpowercont2";
                label="ENG POWER CONT 2";
                animation="Lever_engpower2";
            }; // b_engpowercont2
        }; // powerContRTD
        class l_rotorbrake : b_airsce {
            clickSound="";
            position="RotorBrake";
            positionType="anim";
            label="Rotor Brake";
            animation="Lever_RotorBrake";
            animStates[] = {0, 1};
            animLabels[] = {"OFF", "ON"};
            animEnd="";
            radius=0.1;
            animSpeed=1;
        }; // l_rotorbrake
        class l_wheelbrake : b_airsce {
            clickSound="";
            position="handle_wheelbrake";
            positionType="anim";
            label="Parking Brake";
            animation="Handle_wheelbrake";
            animStates[] = {1, 0};
            animLabels[] = {"ON", "OFF"};
            animEnd="_this call vtx_uh60_engine_fnc_wheelBrakes;";
            radius=0.1;
            animSpeed=3;
        }; // l_wheelbrake
    }; // startUp
    class misc {
            class b_ap_ralt_L {
                    positionType="static";
                    position="ap_fdL_1";
                    label="RALT AP";
                    radius=BTN_RADIUS_SWITCH;
                    clickSound="vxf_Switch_Sound";
                    buttonUp="[(_this # 0), ""RALT""] call vtx_uh60_fd_fnc_modeSet;";
                }; // ralt
            class b_ap_ralt_R : b_ap_ralt_L {
                    position="ap_fdR_1";
                    label="RALT AP";
                }; // ralt
        class b_ap_altp_L : b_ap_ralt_L {
                     position="ap_fdL_2";
                     label="ALTP AP";
                     buttonUp="[(_this # 0), ""ALTP""] call vtx_uh60_fd_fnc_modeSet;";
                 }; // altp
        class b_ap_altp_R : b_ap_altp_L {
                    position="ap_fdR_2";
                    label="ALTP AP";
        }; // altp
        class b_ap_alt_L : b_ap_ralt_L {
                    position="ap_fdL_3";
                    label="ALT AP";
                    buttonUp="[(_this # 0), ""ALT""] call vtx_uh60_fd_fnc_modeSet;";
         }; // alt
        class b_ap_alt_R : b_ap_alt_L {
                    position="ap_fdR_3";
         }; // alt
        class b_ap_ias_L : b_ap_ralt_L {
                    position="ap_fdL_4";
                    label="IAS AP";
                    buttonUp="[(_this # 0), ""IAS""] call vtx_uh60_fd_fnc_modeSet;";
         }; // IAS
        class b_ap_ias_R : b_ap_ias_L {
                    position="ap_fdR_4";
        }; // IAS
        class b_ap_hdg_L : b_ap_ralt_L {
                    position="ap_fdL_5";
                    label="HDG AP";
                    buttonUp="[(_this # 0), ""HDG""] call vtx_uh60_fd_fnc_modeSet;";
        }; // HDG
        class b_ap_hdg_R : b_ap_hdg_L {
                    position="ap_fdR_5";
        }; // HDG
        class Knob_LightUpperConsole {
            positionType="static";
            position="knob_lights_uprcsl";
            label="Upper Console Light";
            radius=0.025;
            animation="Knob_LightUpperConsole";
            scrollIncrement = 0.2;
            dragRange = 0.2;
            looping = 0;
            animLimits[] = {0, 1};
            dragStart="";
            dragging="(_this # 0) setObjectMaterialGlobal[0,format [""\z\vtx\addons\UH60\Data\Cockpit\Emmisive\Emmisive_%1.rvmat"",round(((_this # 0) animationPhase ""Knob_LightUpperConsole"")*10)]]";
            dragStop="(_this # 0) setObjectMaterialGlobal[0,format [""\z\vtx\addons\UH60\Data\Cockpit\Emmisive\Emmisive_%1.rvmat"",round(((_this # 0) animationPhase ""Knob_LightUpperConsole"")*10)]]";
        }; // Knob_LightUpperConsole
        class Knob_LightLowerConsole : Knob_LightUpperConsole {
            position="knob_lights_lwrcsl";
            label="Lower Console Light";
            animation="Knob_LightLowerConsole";
            dragStart="";
            dragging="(_this # 0) setObjectMaterialGlobal[2,format [""\z\vtx\addons\UH60\Data\Cockpit\Emmisive\Emmisive_%1.rvmat"",round(((_this # 0) animationPhase ""Knob_LightLowerConsole"")*10)]]";
            dragStop="(_this # 0) setObjectMaterialGlobal[2,format [""\z\vtx\addons\UH60\Data\Cockpit\Emmisive\Emmisive_%1.rvmat"",round(((_this # 0) animationPhase ""Knob_LightLowerConsole"")*10)]]";
        }; // Knob_LightLowerConsole
        class Knob_LightInstPanel : Knob_LightUpperConsole {
            position="knob_lights_instpnl";
            label="Instrument Panel Light";
            animation="Knob_LightInstPanel";
            dragStart="";
            dragging="(_this # 0) setObjectMaterialGlobal[1,format [""\z\vtx\addons\UH60\Data\Cockpit\Emmisive\Emmisive_%1.rvmat"",round(((_this # 0) animationPhase ""Knob_LightInstPanel"")*10)]]";
            dragStop="(_this # 0) setObjectMaterialGlobal[1,format [""\z\vtx\addons\UH60\Data\Cockpit\Emmisive\Emmisive_%1.rvmat"",round(((_this # 0) animationPhase ""Knob_LightInstPanel"")*10)]]";
        }; // Knob_LightInstPanel
        //FlightDirectorControls
        class KnobFDRight_RALT : Knob_LightUpperConsole {
            position="knob_fdR_1";
            label="RALT Select";
            scrollIncrement = 0.1;
            animLimits[] = {0, 10};
            dragRange = 0.5*5;
            animation="FD_1_ROT";
            looping = 1;
            dragStart="";
            dragging="(_this # 0) setUserMFDValue [12, (round(((_this # 0) animationSourcePhase ""FD_1_ROT"")*10))*10]";
            dragStop="(_this # 0) setUserMFDValue [12, (round(((_this # 0) animationSourcePhase ""FD_1_ROT"")*10))*10]";
            buttonUp="[(_this # 0), ""RALT""] call vtx_uh60_fd_fnc_psync;";
        }; // KnobFDRight_RALT
        class KnobFDLeft_RALT : KnobFDRight_RALT {position="knob_fdL_1";};// KnobFDLeft_RALT
        class KnobFDRight_ALTP : KnobFDRight_RALT {
            position="knob_fdR_2";
            animLimits[] = {0, 20};
            dragRange = 0.5*10;
            label="ALTP Select";
            animation="FD_2_ROT";
            dragging="(_this # 0) setUserMFDValue [13, (round(((_this # 0) animationSourcePhase ""FD_2_ROT"")*10))*100]";
            dragStop="(_this # 0) setUserMFDValue [13, (round(((_this # 0) animationSourcePhase ""FD_2_ROT"")*10))*100]";
            buttonUp="[(_this # 0), ""ALTP""] call vtx_uh60_fd_fnc_psync;";
        }; // KnobFDRight_ALTP
        class KnobFDLeft_ALTP : KnobFDRight_ALTP {position="knob_fdL_2";};// KnobFDLeft_ALTP
        class KnobFDRight_ALT : KnobFDRight_RALT {
            position="knob_fdR_3";
            animLimits[] = {0, 20};
            dragRange = 0.5*10;
            label="ALT Select";
            animation="FD_3_ROT";
            dragging="(_this # 0) setUserMFDValue [14, (round(((_this # 0) animationSourcePhase ""FD_3_ROT"")*10))*100]";
            dragStop="(_this # 0) setUserMFDValue [14, (round(((_this # 0) animationSourcePhase ""FD_3_ROT"")*10))*100]";
            buttonUp="[(_this # 0), ""ALT""] call vtx_uh60_fd_fnc_psync;";
        }; // KnobFDRight_ALT
        class KnobFDLeft_ALT : KnobFDRight_ALT {position="knob_fdL_3";};// KnobFDLeft_ALT
        //class KnobFDRightIAS : KnobFDRight_RALT {
        //    position="knob_fdR_4";
        //    animLimits[] = {0, 2};
        //    dragRange = 0.5*0.65;
        //    label="IAS Select";
        //    animation="FD_4_ROT";
        //    dragging="(_this # 0) setUserMFDValue [15, (round(((_this # 0) animationSourcePhase ""FD_4_ROT"")*10))*10]";
        //    dragStop="(_this # 0) setUserMFDValue [15, (round(((_this # 0) animationSourcePhase ""FD_4_ROT"")*10))*10]";
        //    buttonUp="[(_this # 0), ""IAS""] call vtx_uh60_fd_fnc_psync;";
        //}; // KnobFDRight_IAS
        //class KnobFDLeftIAS : KnobFDRightIAS {position="knob_fdL_4";};// KnobFDLeft_IAS
        //class KnobFDRightHDG : KnobFDRight_RALT {
        //    position="knob_fdR_5";
        //    animLimits[] = {0, 10};
        //    scrollIncrement = 1/36;
        //    dragRange = 0.5*9;
        //    label="HDG Select";
        //    animation="FD_5_ROT";
        //    dragging="(_this # 0) setUserMFDValue [16, (round(((_this # 0) animationSourcePhase ""FD_5_ROT"")*36))]";
        //    dragStop="(_this # 0) setUserMFDValue [16, (round(((_this # 0) animationSourcePhase ""FD_5_ROT"")*36))]";
        //    buttonUp="[(_this # 0), ""HDG""] call vtx_uh60_fd_fnc_psync;";
        //}; // KnobFDRight_IAS
        //class KnobFDLeftHDG : KnobFDRightHDG {position="knob_fdL_5";};// KnobFDLeftHDG
        class toCabin {
          condition = "isNull (vxf_vehicle turretUnit [1]) || {isNull (vxf_vehicle turretUnit [2])}";
          positionType = "coordinates";
          position[] = POS_MOVE_CABIN_COCKPIT;
          label = "Move To Cabin";
          radius = 0.1;
          buttonDown = "call vtx_uh60_misc_fnc_moveToCabin";
        }; // toCabin
    }; // misc
    class MFDs {
    };
};
