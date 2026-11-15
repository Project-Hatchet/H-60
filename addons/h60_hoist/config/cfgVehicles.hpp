class CfgVehicles
{
    // Hoist self-actions are registered script-side in ACE_Actions.sqf
    // (ace_interact_menu_fnc_addActionToClass): a config ACE_SelfActions
    // block on hct_H60_base would overwrite inherited actions instead of
    // merging with them.

    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class hct_detachHook {
                displayName = "Detach Hook";
                condition = "[player] call hct_h60_hoist_fnc_isAttachedHook";
                statement = "[player] call hct_h60_hoist_fnc_detachHook";
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
    class hct_hook_base: Boat_F {
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
    class hct_hook_helper: hct_hook_base {
        displayName = "Rescue Hoist Hook Helper";
        author = "Project Hatchet Studios";
        model = "z\vtx\addons\uh60_hoist\data\vtx_hook_helper.p3d";
        slingLoadCargoMemoryPoints[] = {"sling_point"};
    };

    class hct_hook: hct_hook_base {
        _generalMacro = "hct_hook";
        class ACE_Actions {
          class ACE_MainActions {};
        };
        class ACE_SelfActions {
            class HCT_GetInHeli {
                displayName = "Get In Helicopter";
                condition = "[_player] call hct_h60_hoist_fnc_canMoveHookToHeli";
                statement = "[_player] call hct_h60_hoist_fnc_moveHookToHeli";
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
    };
};
