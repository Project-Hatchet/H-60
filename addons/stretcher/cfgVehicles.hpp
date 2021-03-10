class CfgVehicles {
  class LandVehicle;
  class StaticWeapon: LandVehicle    {
    class Turrets;
    class MainTurret;
    class ACE_Actions {
      class ACE_MainActions {};
    };
  };
  class GVAR(stretcher): StaticWeapon {
    _generalMacro = QGVAR(stretcher);
    ace_refuel_canReceive = 0;
    ace_cargo_space = 0;
    ace_cargo_hasCargo = 0;
    // ACRE 2.6.0 Compatibility
    acre_hasInfantryPhone = 0;
    class AcreRacks {};
    class AcreIntercoms {};
    armor = 1000000;
    author = "Ampersand";
    cargoAction[] = {"ChopperLight_CB_static_H"};
    cost = 0;
    displayName = "$STR_A3_CfgVehicles_Land_Stretcher_01_f0"; // Stretcher
    hasDriver = false;
    hasGunner = false;
    hasCommander = false;
    hullDamageCauseExplosion = 0;
    icon = QPATHTOF("data\ui\stretcher_icon.paa");
    picture = QPATHTOF("data\ui\stretcher_groupBar.paa");
    mapSize = 2;
    mass = 7;
    maximumLoad = 0;
    model = QPATHTOF("data\stretcher.p3d");
    scope = 2;
    //slingLoadCargoMemoryPoints[] = {"sling_point"}; // Don't make slingable
    transportSoldier = 1;
    typicalCargo[] = {};
  };
};
