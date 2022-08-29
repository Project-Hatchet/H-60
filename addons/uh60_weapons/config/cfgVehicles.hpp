class CfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F {
        class vxf_driver;
        class vxf_copilot;
    }; // Helicopter_Base_H
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class vxf_driver: vxf_driver {
            class interaction;
            class modules;
        }; // vxf_driver
        class vxf_copilot: vxf_copilot {
            class interaction;
            class modules;
        }; // vxf_copilot
        class MFD;
    }; // Heli_Transport_01_base_F
    class vtx_H60_base: Heli_Transport_01_base_F {
        class vxf_driver: vxf_driver {
            class modules: modules {
                class weapons {
                    startOnEnter = 1;
                }; // weapons
            }; // modules
        }; // vxf_driver
        class vxf_copilot: vxf_copilot {
            class modules: modules {
                class weapons {
                    startOnEnter = 1;
                }; // weapons
            }; // modules
        }; // vxf_driver
    }; // vtx_H60_base
    class Boat_F;
    class vtx_pylon: Boat_F {
        //simulation = "car";
        simulation = "shipX";
        safeDepth = 20;
        ace_refuel_canReceive = 0;
        ace_cargo_space = 0;
        ace_cargo_hasCargo = 0;
        // ACRE 2.6.0 Compatibility
        acre_hasInfantryPhone = 0;
        class AcreRacks {};
        class AcreIntercoms {};
        armor = 1000000;
        author = "Project Hatchet Studio";
        cargoAction[] = {"ChopperLight_CB_static_H"};
        memoryPointsGetInCargo = "pos cargo";
        memoryPointsGetInCargoDir = "pos cargo dir";
        preciseGetInOut = 1;
        cost = 0;
        displayName = "Pylon";
        fuelCapacity = 0;
        hasDriver = false;
        hasGunner = false;
        hasCommander = false;
        faction = "BLU_F";
        category = "Air";
        scope=2;
        side = 1;
        editorSubcategory = "vtx_h60";
        /*
        class HitPoints: HitPoints {
            class HitBody: HitBody {
                name = "sling_point";
            };
        };
        */
        hullDamageCauseExplosion = 0;
        icon = "z\vtx\addons\uh60_hoist\data\ui\iconHook.paa";
        picture = "z\vtx\addons\uh60_hoist\data\ui\vtx_hook_ca.paa";
        mapSize = 0.5;
        mass = 100;
        maximumLoad = 0;
        model = "z\vtx\addons\uh60_weapons\pylon.p3d";
        //slingLoadCargoMemoryPoints[] = {"sling_point"}; // Don't make slingable
        transportSoldier=1;
        typicalCargo[] = {};

        class AnimationSources {};
        class CargoTurret {};
        class Components {
            class TransportPylonsComponent {
                uiPicture = "z\vtx\addons\MH60M\Data\UI\vtx_mh60m_dap_3den_ca.paa";
                class pylons {
                    class pylons1 {
                        attachment = "";
                        bay = -1;
                        hardpoints[] = {"VTX_ST_L", "VTX_ST_R", "VTX_ST_OUTBOARD"};
                        maxweight = 1000;
                        mirroredMissilePos = 0;
                        priority = 1;
                        turret[] = {-1};
                        UIposition[] = {0.32,0.28};
                    };
                };
            };
        };
        class CommanderOptics {};
        class DestructionEffects {};
        class Reflectors {};
        class TransportItems {};
        class Turrets {};
    };
}; // CfgVehicles
