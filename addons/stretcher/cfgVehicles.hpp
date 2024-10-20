class CfgVehicles {
  class Man;
  class CAManBase: Man {
    class ACE_SelfActions {
      class ACE_Equipment {
        class GVAR(1) {
          displayName = CSTRING(Unfold);
          condition = QUOTE('vtx_stretcher_item' in items _player);
          exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
          statement = QUOTE([_player] call FUNC(unfold));
          showDisabled = 0;
          icon = QPATHTOF(data\ui\stretcher_icon.paa);
        };
      };
    };
  };

  class Item_Base_F;
  class GVAR(item): Item_Base_F {
    author = "Ampersand";
    displayName = "$STR_A3_CfgVehicles_Land_Stretcher_01_f0"; // Stretcher
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "Items";
    editorPreview = QPATHTOF(data\ui\stretcher_item_preview.jpg);
    class TransportItems {
      class _xx_vtx_stretcher_item {
        count = 1;
        name = GVAR(item);
      };
    };
  };

  class Tank_F;
  class GVAR(1): Tank_F {
    ace_dragging_canDrag = 1;
    ace_dragging_dragDirection = 90;
    ace_dragging_dragPosition[] = {0, 1, 0};
    ace_dragging_canCarry = 1;
    ace_dragging_carryDirection = 90;
    ace_dragging_carryPosition[] = {0, 1, 0};
    class ACE_SelfActions {};
    _generalMacro = QGVAR(1);
    ace_refuel_canReceive = 0;
    ace_cargo_space = 0;
    ace_cargo_hasCargo = 0;
    ace_cookoff_probability = 0;
    armor = 1000000;
    author = "Project Hatchet Studio";
    cargoGetInAction[] = {"GetInLow"};
    cargoGetOutAction[] = {"GetOutLow"};
    cargoAction[] = {"passenger_injured_medevac_truck01"}; //"passenger_injured_medevac_truck01","passenger_injured_medevac_truck02","passenger_injured_medevac_truck03"
    ejectDeadCargo = 0;
    cargoProxyIndexes[] = {1};
    editorCategory = "EdCat_Things";
    editorSubcategory = "EdSubcat_Military";
    cost = 0;
    displayName = "$STR_A3_CfgVehicles_Land_Stretcher_01_f0"; // Stretcher
    hasDriver = 0;
    hasGunner = 0;
    hasCommander = 0;
    icon = QPATHTOF(data\ui\stretcher_icon.paa);
    picture = QPATHTOF(data\ui\stretcher_groupBar.paa);
    editorPreview = QPATHTOF(data\ui\stretcher_preview.jpg);
    mapSize = 2;
    mass = 200;
    maximumLoad = 0;
    tf_isolatedAmount = 0;
    maxCompression = 0;
    maxDroop = 0;
    numberPhysicalWheels = 0;
    model = QPATHTOF(data\stretcher.p3d);
    scope = 2;
    scopeCurator = 2;
    side = 3;
    crew = "";
    DLC = "";
    simulation = "TankX";
    faction = "Default";
    destrType = "DestructNo";
    explosionEffect = "";
    fuelExplosionPower = 0;
    editorForceEmpty = 1;
    explosionShielding = 0;
    hullDamageCauseExplosion = 0;
    crewVulnerable = 1;
    crewExplosionProtection = 0;
    irTarget = 0;
    allowTabLock = 0;
    autocenter = 1;
    preciseGetInOut = 1;
  	memoryPointsGetInCargo = "pos_cargo";
  	memoryPointsGetInCargoDir = "pos_cargo_dir";
    slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
    transportSoldier = 1;
    typicalCargo[] = {};
    textureList[] = {};
    class AnimationSources {};
    class Components {};
    class DestructionEffects {};
    class TextureSources {};
    class Turrets {};
    class VehicleTransport {
    	class Cargo {
    		parachuteClass = "";	// Type of parachute used when dropped in air. When empty then parachute is not used.
    		canBeTransported = 1;				// 0 (false) / 1 (true)
    		dimensions[] = { "BBox_1_1_pos", "BBox_1_2_pos" }; // Memory-point-based override of automatic bounding box
    	};
    };
  };
  class GVAR(2): GVAR(1) {
    _generalMacro = QGVAR(2);
    cargoAction[] = {"passenger_injured_medevac_truck02"}; //"passenger_injured_medevac_truck01","passenger_injured_medevac_truck02","passenger_injured_medevac_truck03"
  };
  class GVAR(3): GVAR(1) {
    _generalMacro = QGVAR(3);
    cargoAction[] = {"passenger_injured_medevac_truck03"}; //"passenger_injured_medevac_truck01","passenger_injured_medevac_truck02","passenger_injured_medevac_truck03"
  };
};
