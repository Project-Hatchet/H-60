class CfgVehicles {
    class Heli_Transport_01_base_F;
    class vtx_H60_base: Heli_Transport_01_base_F {
        class vxf_turret_1 {
            projectPrefix = "vtx_uh60";
            class modules {
                class doorguns {
                    startOnEnter = 1;
                }; // doorguns
                class ui: doorguns {
                    startOnEnter = 0;
                };
            }; // modules
            class interaction {
                class ammoCan {
                    positionType="coordinates";
                    position[]={-0.8,3.8,-1};
                    label="";
                    radius=0.08;
                    buttonUp="hint format[""%1 Rounds remaining"", (_this # 0) magazineTurretAmmo [""vtx_2000Rnd_65x39_Belt_Tracer_Red"", [1]]];";
                    clickSound="vxf_Switch_Sound";
                }; // ammoCan
                class toCockpit {
                  condition = "isNull driver vxf_vehicle || {isNull (vxf_vehicle turretUnit [0])}";
                  positionType = "coordinates";
                  position[] = POS_MOVE_CABIN_COCKPIT;
                  label = "Move To Cockpit";
                  radius = 0.1;
                  buttonDown = "call vtx_uh60_misc_fnc_moveToCockpit";
                }; // toCockpit
                class coverUp {
                    condition="(_this animationPhase ""Switch_minigun_safe_cover_l"") > 0.5";
                    class safetyCover {
                        positionType="anim";
                        position="b_minigun_safe_cover_l";
                        label="Safety on";
                        radius=0.08;
                        buttonUp="[(_this # 0), false, ""l""] call vtx_uh60_doorguns_fnc_coverSwitch;";
                        clickSound="vxf_Switch_Sound";
                    }; // safetyCover
                    class powerOn {
                        condition="(_this animationPhase ""Switch_minigun_safe_l"") > 0.5";
                        class powerButton {
                            positionType="anim";
                            position="b_minigun_safe_l";
                            label="Power off";
                            radius=0.08;
                            buttonUp="[(_this # 0), false, ""l""] call vtx_uh60_doorguns_fnc_powerSwitch;";
                            clickSound="vxf_Switch_Sound";
                        }; // powerButton
                    }; // powerOn
                    class powerOff {
                        condition="(_this animationPhase ""Switch_minigun_safe_l"") < 0.5";
                        class powerButton {
                            positionType="anim";
                            position="b_minigun_safe_l";
                            label="Power on";
                            radius=0.08;
                            buttonUp="[(_this # 0), true, ""l""] call vtx_uh60_doorguns_fnc_powerSwitch;";
                            clickSound="vxf_Switch_Sound";
                        }; // powerButton
                    }; // powerOff
                }; // coverUp
                class coverDown {
                    condition="(_this animationPhase ""Switch_minigun_safe_cover_l"") < 0.5";
                    class safetyCover {
                        positionType="anim";
                        position="b_minigun_safe_l";
                        label="Safety cover up";
                        radius=0.08;
                        buttonUp="[(_this # 0), true, ""l""] call vtx_uh60_doorguns_fnc_coverSwitch;";
                        clickSound="vxf_Switch_Sound";
                    }; // safetyCover
                }; // coverDown
            }; // interaction
        }; // vxf_gunner
        class vxf_turret_2 {
            projectPrefix = "vtx_uh60";
            class modules {
                class doorguns {
                    startOnEnter = 1;
                }; // doorguns
                class ui: doorguns {
                    startOnEnter = 0;
                };
            }; // modules
            class interaction {
                class ammoCan {
                    positionType="coordinates";
                    position[]={0.8,3.8,-1};
                    label="";
                    radius=0.08;
                    buttonUp="hint format[""%1 Rounds remaining"", (_this # 0) magazineTurretAmmo [""vtx_2000Rnd_65x39_Belt_Tracer_Red"", [2]]];";
                    clickSound="vxf_Switch_Sound";
                }; // ammoCan
                class toCockpit {
                  condition = "isNull driver vxf_vehicle || {isNull (vxf_vehicle turretUnit [0])}";
                  positionType = "coordinates";
                  position[] = POS_MOVE_CABIN_COCKPIT;
                  label = "Move To Cockpit";
                  radius = 0.1;
                  buttonDown = "call vtx_uh60_misc_fnc_moveToCockpit";
                }; // toCockpit
                class coverUp {
                    condition="(_this animationPhase ""Switch_minigun_safe_cover_r"") > 0.5";
                    class safetyCover {
                        positionType="anim";
                        position="b_minigun_safe_cover_r";
                        label="Safety on";
                        radius=0.08;
                        buttonUp="[(_this # 0), false, ""r""] call vtx_uh60_doorguns_fnc_coverSwitch;";
                        clickSound="vxf_Switch_Sound";
                    }; // safetyCover
                    class powerOn {
                        condition="(_this animationPhase ""Switch_minigun_safe_r"") > 0.5";
                        class powerButton {
                            positionType="anim";
                            position="b_minigun_safe_r";
                            label="Power off";
                            radius=0.08;
                            buttonUp="[(_this # 0), false, ""r""] call vtx_uh60_doorguns_fnc_powerSwitch;";
                            clickSound="vxf_Switch_Sound";
                        }; // powerButton
                    }; // powerOn
                    class powerOff {
                        condition="(_this animationPhase ""Switch_minigun_safe_r"") < 0.5";
                        class powerButton {
                            positionType="anim";
                            position="b_minigun_safe_r";
                            label="Power on";
                            radius=0.08;
                            buttonUp="[(_this # 0), true, ""r""] call vtx_uh60_doorguns_fnc_powerSwitch;";
                            clickSound="vxf_Switch_Sound";
                        }; // powerButton
                    }; // powerOff
                }; // coverUp
                class coverDown {
                    condition="(_this animationPhase ""Switch_minigun_safe_cover_r"") < 0.5";
                    class safetyCover {
                        positionType="anim";
                        position="b_minigun_safe_r";
                        label="Safety cover up";
                        radius=0.08;
                        buttonUp="[(_this # 0), true, ""r""] call vtx_uh60_doorguns_fnc_coverSwitch;";
                        clickSound="vxf_Switch_Sound";
                    }; // safetyCover
                }; // coverDown
            }; // interaction
        }; // vxf_gunner
    }; // vtx_H60_base
}; // CfgVehicles
