class cfgMagazines {
  class VehicleMagazine;
  class PylonRack_4Rnd_ACE_Hellfire_AGM114K;
  class PylonRack_4Rnd_ACE_Hellfire_AGM114N;
  class HCT_4Rnd_ACE_Hellfire_AGM114K: PylonRack_4Rnd_ACE_Hellfire_AGM114K { // 4x Launcher Support Rack
    hardpoints[] = {"HCT_ST_L","HCT_ST_R","HCT_ST_OUTBOARD"};
    displayName = "$STR_hct_h60_weapons_N4xAGM114KH60";
    //count = 4;
    weight = 251.92;
    //hardpoints[] = {"UNI_SCALPEL", "CUP_NATO_HELO_LARGE", "RHS_HP_HELLFIRE_RACK", "RHS_HP_LONGBOW_RACK"};
    ammo = "HCT_Hellfire_AGM114K";
    pylonWeapon = "hct_hellfire_launcher";
    class mfdElements {
      class HCT_H60 {
        #include "hellfireMFD.hpp"
      };
    };
  };
  class HCT_4Rnd_ACE_Hellfire_AGM114N: PylonRack_4Rnd_ACE_Hellfire_AGM114N { // 4x Launcher Support Rack
    hardpoints[] = {"HCT_ST_L","HCT_ST_R","HCT_ST_OUTBOARD"};
    displayName = "$STR_hct_h60_weapons_N4xAGM114NH60";
    //count = 4;
    weight = 251.92;
    mass = 257; // 65 for launcher, 48 per missile
    //hardpoints[] = {"UNI_SCALPEL", "CUP_NATO_HELO_LARGE", "RHS_HP_HELLFIRE_RACK", "RHS_HP_LONGBOW_RACK"};
    ammo = "HCT_Hellfire_AGM114N";
    pylonWeapon = "hct_hellfire_launcher_N";
    class mfdElements {
      class HCT_H60 {
        #include "hellfireMFD.hpp"
      };
    };
  };
  class HCT_M230_Chaingun_L: VehicleMagazine {
    scope = 2;
    ammo = "hct_30mm_shells_hedp";
    descriptionShort = "$STR_hct_h60_weapons_SingleBarrelChainDrivenAutocannonFiring30x113MmM";
    displayname = "$STR_hct_h60_weapons_M230HEDPH60";
    displayNameShort = "$STR_hct_h60_weapons_M230HEDP";
    initspeed = 805;
    pylonWeapon = "hct_chaingun_hedp";
    muzzlePos = "muzzlePos";
    muzzleEnd = "muzzleEnd";
    weight = 164.3;
    count = 300;
    hardpoints[] =    {"HCT_ST_L"};
    model = "\z\vtx\addons\uh60_weapons\Data\M230\M230_L.p3d";
    class mfdElements {
      class HCT_H60 {
        #include "gunMFD.hpp"
      };
    };
  };
  class HCT_M230_Chaingun_R: HCT_M230_Chaingun_L {
    hardpoints[] =    {"HCT_ST_R"};
    model = "\z\vtx\addons\uh60_weapons\Data\M230\M230_R.p3d";
  };

  class PylonRack_12Rnd_missiles;
	class HCT_PylonRack_M261_M229: PylonRack_12Rnd_missiles {
    hardpoints[] = {"HCT_ST_L","HCT_ST_R","HCT_ST_OUTBOARD"};
		author = "Ampersand";
		count = 19;
    displayName = "$STR_hct_h60_weapons_N19xHydra70M229H60";
    displayNameShort = "$STR_hct_h60_weapons_Hydra70M229";
    mass = 300.4; // 36.3 kg launcher, 6.2 per motor, 7.7 per warhead
    model = QPATHTOF(fza_pod_m261.p3d);
    pylonWeapon = "hct_hydra";
    class mfdElements {
      class HCT_H60 {
        #include "rocketMFD.hpp"
      };
    };
	};
  class PylonRack_12Rnd_PG_missiles;
  class HCT_PylonRack_M261_DAGR: PylonRack_12Rnd_PG_missiles {
    scope = 1;
    //hardpoints[] = {"HCT_ST_L","HCT_ST_R","HCT_ST_OUTBOARD"};
    hardpoints[] = {};
    ammo = "ACE_Hydra70_DAGR";
    author = "Ampersand";
    count = 19;
    displayName = "$STR_hct_h60_weapons_N19xDAGRH60";
    displayNameShort = "$STR_hct_h60_weapons_DAGR";
    mass = 336.5; // 36.3 kg launcher, 15.8 per rocket
    model = QPATHTOF(fza_pod_m261.p3d);
    pylonWeapon = "hct_dagr";
    class mfdElements {
      class HCT_H60 {
        #include "rocketMFD.hpp"
      };
    };
  };
  class HCT_PylonRack_M261_APKWS: PylonRack_12Rnd_PG_missiles {
    hardpoints[] = {"HCT_ST_L","HCT_ST_R","HCT_ST_OUTBOARD"};
    ammo = "HCT_APKWS";
    author = "Ampersand";
    count = 19;
    displayName = "$STR_hct_h60_weapons_N19xAPKWSH60";
    displayNameShort = "$STR_hct_h60_weapons_APKWS";
    mass = 336.5; // 36.3 kg launcher, 15.8 per rocket
    model = QPATHTOF(fza_pod_m261.p3d);
    pylonWeapon = "hct_apkws";
    class mfdElements {
      class HCT_H60 {
        #include "rocketMFD.hpp"
      };
    };
  };
};
