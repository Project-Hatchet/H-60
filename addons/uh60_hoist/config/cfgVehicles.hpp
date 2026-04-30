class CfgVehicles
{
    /* These overwrite inherited actions for some reason
    class Heli_Transport_01_base_F;
    class vtx_H60_base: Heli_Transport_01_base_F {
        class ACE_SelfActions {
            class VTX_Hoist {
                displayName = "Hoist";
                icon = "z\vtx\addons\uh60_hoist\data\ui\iconHook.paa";
                class VTX_Hoist_DeployHook {
                    displayName = "Deploy Hook";
                    condition = "call vtx_uh60_hoist_fnc_canDeployHook";
                    statement = "call vtx_uh60_hoist_fnc_deployHook";
                };
                class VTX_Hoist_SecureHook {
                    displayName = "Secure Hook";
                    condition = "call vtx_uh60_hoist_fnc_canSecureHook";
                    statement = "call vtx_uh60_hoist_fnc_secureHook";
                };
                class VTX_Hoist_PullIntoHeli {
                    displayName = "Pull In Hook Occupant";
                    condition = "call vtx_uh60_hoist_fnc_canRecoverPerson";
                    statement = "call vtx_uh60_hoist_fnc_recoverPerson";
                };
                class VTX_Hoist_MoveHeliToHook {
                    displayName = "Move To Hook";
                    condition = "[_player] call vtx_uh60_hoist_fnc_canMoveHeliToHook";
                    statement = "[_player] call vtx_uh60_hoist_fnc_moveHeliToHook";
                };
                class VTX_Hoist_RaiseHookToHeli {
                    displayName = "Raise Hook To Heli";
                    condition = "call vtx_uh60_hoist_fnc_isHoistReady";
                    statement = "call vtx_uh60_hoist_fnc_raiseHookToHeli";
                };
                class VTX_Hoist_LowerHookToGround {
                    displayName = "Lower Hook To Ground";
                    condition = "call vtx_uh60_hoist_fnc_isHoistReady";
                    statement = "call vtx_uh60_hoist_fnc_lowerHookToGround";
                };
                class VTX_Hoist_Working {
                    displayName = "Working...";
                    condition = "!(call vtx_uh60_hoist_fnc_isHoistReady)";
                    statement = "";
                };
            };
        };
    };
    */

    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class vtx_detachHook {
                displayName = "Detach Hook";
                condition = "[player] call vtx_uh60_hoist_fnc_isAttachedHook";
                statement = "[player] call vtx_uh60_hoist_fnc_detachHook";
                icon = "z\vtx\addons\uh60_hoist\data\ui\iconHook.paa";
                priority = 2.6;
                showDisabled = 1;
                exceptions[] = {"isNotInside", "isNotSwimming"};
            };
        };
    };
    class Ship_F;
    class Boat_F: Ship_F {
        class Turrets;
    };
    class vtx_hook_base: Boat_F {
        scope = 1;
        //simulation = "car";
        simulation = "shipX";
        safeDepth = 20;
        fuelCapacity = 0;
        hasDriver = 0;
        mass = 180;
        maximumLoad = 0;
        ace_refuel_canReceive = 0;
        ace_cargo_space = 0;
        ace_cargo_hasCargo = 0;
        acre_hasInfantryPhone = 0;
        class HitPoints;
        class ACE_Actions {};
        class AcreRacks {};
        class AcreIntercoms {};
        class AnimationSources {};
        class Components {};
        class DestructionEffects {};
        class Reflectors {};
        class TransportItems {};
        class Turrets {};

    };
    class vtx_hook_helper: vtx_hook_base {
        displayName = "Rescue Hoist Hook Helper";
        author = "Project Hatchet Studios";
        model = "z\vtx\addons\uh60_hoist\data\vtx_hook_helper.p3d";
        slingLoadCargoMemoryPoints[] = {"sling_point"};
    };

    class vtx_hook: vtx_hook_base {
        _generalMacro = "vtx_hook";
        class ACE_Actions {
          class ACE_MainActions {};
        };
        class ACE_SelfActions {
            class VTX_GetInHeli {
                displayName = "Get In Helicopter";
                condition = "[_player] call vtx_uh60_hoist_fnc_canMoveHookToHeli";
                statement = "[_player] call vtx_uh60_hoist_fnc_moveHookToHeli";
                selection = "sling_point";
                exceptions[] = {};
            };
        };
        // ACRE 2.6.0 Compatibility
        armor = 1000000;
        author = "Project Hatchet Studios";
        cargoAction[] = {"ChopperLight_CB_static_H"};
        memoryPointsGetInCargo = "pos cargo";
        memoryPointsGetInCargoDir = "pos cargo dir";
        preciseGetInOut = 1;
        cost = 0;
        displayName = "Rescue Hoist Hook";
        hullDamageCauseExplosion = 0;
        icon = "z\vtx\addons\uh60_hoist\data\ui\iconHook.paa";
        picture = "z\vtx\addons\uh60_hoist\data\ui\vtx_hook_ca.paa";
        mapSize = 0.5;
        model = "z\vtx\addons\uh60_hoist\data\vtx_hook.p3d";
        //slingLoadCargoMemoryPoints[] = {"sling_point"}; // Don't make slingable
        transportSoldier=1;
        typicalCargo[] = {};
    };
};
