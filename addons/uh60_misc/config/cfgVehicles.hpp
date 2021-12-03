class cfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F {
        class vxf_cargo;
    };
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class vxf_cargo: vxf_cargo {
            class interaction;
        };
        //class ACE_Actions;
    };
    class vtx_H60_base: Heli_Transport_01_base_F {
        //class ACE_Actions: ACE_Actions {
        //    class ACE_MainActions;
        //};
        class vxf_cargo: vxf_cargo {
            class interaction: interaction {
                class fastRopeRight {
                    condition = "[player, vehicle player] call ace_fastroping_fnc_canFastRope";
                    positionType = "coordinates";
                    position[] = {1.66, 1.585,-0.3};
                    buttonDown = "[player, _this select 0] call ace_fastroping_fnc_fastRope";
                    label = "Fast Rope";
                    radius = 0.3;
                }; // fastRopeRight
                class fastRopeLeft: fastRopeRight {
                    position[] = {-1.66, 1.815,-0.3};
                }; // fastRopeLeft
                class vxf_friesDeployed {
                    condition = "[_this] call ace_fastroping_fnc_canStowFRIES";
                    class ropesNotDeployed {
                        condition = "[_this, player, ""ACE_rope36"", true] call ace_fastroping_fnc_canDeployRopes";
                        class deployRopeRight {
                            positionType = "coordinates";
                            position[] = {1.66, 1.585,-0.09};
                            buttonDown = "[_this select 0, player, ""ACE_rope36""] call ace_fastroping_fnc_deployRopes";
                            label = "Deploy Ropes";
                            radius = 0.3;
                        }; // deployRopeRight
                        class deploytRopeLeft: deployRopeRight {
                            position[] = {-1.66, 1.815,-0.09};
                        }; // deploytRopeLeft
                    }; // ropesNotDeployed
                }; // vxf_friesDeployed
                class vxf_friesNotDeployed {
                    condition = "[_this] call ace_fastroping_fnc_canPrepareFRIES";
                    class prepareFRIES {
                        positionType="coordinates";
                        position[] = {0, 1.7, 0.04};
                        buttonDown = "_this call ace_fastroping_fnc_prepareFRIES";
                        label="Prepare FRIES";
                        radius=0.3;
                    }; // fastRopeRight
                }; // vxf_friesNotDeployed
            }; // interaction
        }; // vxf_cargo
    }; // vtx_H60_base

    class Land_MobileScafolding_01_F;
    class vtx_serviceplatform: Land_MobileScafolding_01_F {
        author = "Project Hatchet Studio";
        displayName = "Blackhawk Service Platform";
        model = "\z\vtx\addons\uh60_misc\data\serviceplatform\Yax_service_test.p3d";
    };
};
