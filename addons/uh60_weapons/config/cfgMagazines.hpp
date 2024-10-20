class cfgMagazines {
  class VehicleMagazine;
  class PylonMissile_Missile_HARM_x1;
  class PylonRack_Missile_HARM_x1;
  class PylonRack_4Rnd_ACE_Hellfire_AGM114K;
  class PylonRack_4Rnd_ACE_Hellfire_AGM114N;
  class VTX_4Rnd_ACE_Hellfire_AGM114K: PylonRack_4Rnd_ACE_Hellfire_AGM114K { // 4x Launcher Support Rack
    hardpoints[] = {"VTX_ST_L","VTX_ST_R","VTX_ST_OUTBOARD"};
    displayName = "4x AGM-114K [H60]";
    //count = 4;
    weight = 251.92;
    //hardpoints[] = {"UNI_SCALPEL", "CUP_NATO_HELO_LARGE", "RHS_HP_HELLFIRE_RACK", "RHS_HP_LONGBOW_RACK"};
    ammo = "VTX_Hellfire_AGM114K";
    pylonWeapon = "vtx_hellfire_launcher";
    class mfdElements {
      class VTX_H60 {
        #include "hellfireMFD.hpp"
      };
    };
  };
  class VTX_4Rnd_ACE_Hellfire_AGM114N: PylonRack_4Rnd_ACE_Hellfire_AGM114N { // 4x Launcher Support Rack
    hardpoints[] = {"VTX_ST_L","VTX_ST_R","VTX_ST_OUTBOARD"};
    displayName = "4x AGM-114N [H60]";
    //count = 4;
    weight = 251.92;
    mass = 257; // 65 for launcher, 48 per missile
    //hardpoints[] = {"UNI_SCALPEL", "CUP_NATO_HELO_LARGE", "RHS_HP_HELLFIRE_RACK", "RHS_HP_LONGBOW_RACK"};
    ammo = "VTX_Hellfire_AGM114N";
    pylonWeapon = "vtx_hellfire_launcher_N";
    class mfdElements {
      class VTX_H60 {
        #include "hellfireMFD.hpp"
      };
    };
  };
  class VTX_M230_Chaingun_L: VehicleMagazine {
    scope = 2;
    ammo = "vtx_30mm_shells_hedp";
    descriptionShort = "Single-barrel chain-driven autocannon firing 30x113 mm M789 High Explosive Dual Purpose (HEDP) rounds.";
    displayname = "M230 HEDP [H60]";
    displayNameShort = "M230 HEDP";
    initspeed = 805;
    pylonWeapon = "vtx_chaingun_hedp";
    muzzlePos = "muzzlePos";
    muzzleEnd = "muzzleEnd";
    weight = 164.3;
    tracersEvery = 1;
    lastRoundsTracer = 1;
    count = 300;
    hardpoints[] =    {"VTX_ST_L"};
    model = \z\vtx\addons\uh60_weapons\Data\M230\M230_L.p3d;
    class mfdElements {
      class VTX_H60 {
        #include "gunMFD.hpp"
      };
    };
  };
  class VTX_M230_Chaingun_R: VTX_M230_Chaingun_L {
    hardpoints[] =    {"VTX_ST_R"};
    model = \z\vtx\addons\uh60_weapons\Data\M230\M230_R.p3d;
  };
  class VTX_M230_Chaingun_L_AP: VTX_M230_Chaingun_L {
    scope = 2;
    ammo = "vtx_30mm_shells_ap";
    descriptionShort = "Single-barrel chain-driven autocannon firing 30x113 mm AP rounds.";
    displayname = "M230 AP [H60]";
    displayNameShort = "M230 AP";
    pylonWeapon = "vtx_chaingun_ap";
  };
  class VTX_M230_Chaingun_R_AP: VTX_M230_Chaingun_L_AP {
    weight = 164.3;
    hardpoints[] =    {"VTX_ST_R"};
    model = \z\vtx\addons\uh60_weapons\Data\M230\M230_R.p3d;
  };

  class PylonRack_12Rnd_missiles;
	class VTX_PylonRack_M261_M229: PylonRack_12Rnd_missiles {
    hardpoints[] = {"VTX_ST_L","VTX_ST_R","VTX_ST_OUTBOARD"};
		author = "Ampersand";
		count = 19;
    displayName = "19x Hydra 70 M229 [H60]";
    displayNameShort = "Hydra 70 M229";
    mass = 300.4; // 36.3 kg launcher, 6.2 per motor, 7.7 per warhead
    model = QPATHTOF(fza_pod_m261.p3d);
    pylonWeapon = "vtx_hydra";
    class mfdElements {
      class VTX_H60 {
        #include "rocketMFD.hpp"
      };
    };
	};
  class PylonRack_12Rnd_PG_missiles;
  class VTX_PylonRack_M261_DAGR: PylonRack_12Rnd_PG_missiles {
    hardpoints[] = {"VTX_ST_L","VTX_ST_R","VTX_ST_OUTBOARD"};
    ammo = "ACE_Hydra70_DAGR";
    author = "Ampersand";
    count = 19;
    displayName = "19x DAGR [H60]";
    displayNameShort = "DAGR";
    mass = 336.5; // 36.3 kg launcher, 15.8 per rocket
    model = QPATHTOF(fza_pod_m261.p3d);
    pylonWeapon = "vtx_dagr";
    class mfdElements {
      class VTX_H60 {
        #include "rocketMFD.hpp"
      };
    };
  };
  class VTX_PylonRack_M261_APKWS: PylonRack_12Rnd_PG_missiles {
    hardpoints[] = {"VTX_ST_L","VTX_ST_R","VTX_ST_OUTBOARD"};
    ammo = "VTX_APKWS";
    author = "Ampersand";
    count = 19;
    displayName = "19x APKWS [H60]";
    displayNameShort = "APKWS";
    mass = 336.5; // 36.3 kg launcher, 15.8 per rocket
    model = QPATHTOF(fza_pod_m261.p3d);
    pylonWeapon = "vtx_apkws";
    class mfdElements {
      class VTX_H60 {
        #include "rocketMFD.hpp"
      };
    };
  };
  class VTX_PylonMissile_Missile_HARM_x1_HL: PylonMissile_Missile_HARM_x1 {
    hardpoints[] = {"VTX_ST_L","VTX_ST_R","VTX_ST_OUTBOARD","B_HARM_RAIL","I_HARM_RAIL","B_HARM","I_HARM"};
    ammo = "vtx_ammo_Missile_HARM_HL";
    count = 1;
    mass = 10;
    author = "Yax (at him on discord)";
    displayName = "1x AGM-88 Hobby Lobby [H60]";
    displayNameShort = "AGM-88HL";
    model = QPATHTOF(hl_88.p3d);
    pylonWeapon = "vtx_weapon_HARMLauncher_HL";
    descriptionShort="Held together with duct tape and powered by a hobby lobby motor.  Explodes into glitter";
    description = "Improvised anti radiation munitions, designed by highschoolers.  Held together with duct tape and powered by a hobby lobby motor.  Carries a payload of confetti and glitter.  Guided by a raspberryPI running the 'The Missile knows where it is' meme.  It's really just an advanced way to mark a target.";
  };
};
