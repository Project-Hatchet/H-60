class cfgMagazines {
  class VehicleMagazine;
  class PylonRack_4Rnd_ACE_Hellfire_AGM114K;
  class PylonRack_4Rnd_ACE_Hellfire_AGM114L;
  class PylonRack_4Rnd_ACE_Hellfire_AGM114N;
  class VTX_4Rnd_ACE_Hellfire_AGM114K: PylonRack_4Rnd_ACE_Hellfire_AGM114K { // 4x Launcher Support Rack
    displayName = "4x AGM-114K [H60]";
    //count = 4;
    mass = 245; // 65 for launcher, 45 per missile
    //hardpoints[] = {"UNI_SCALPEL", "CUP_NATO_HELO_LARGE", "RHS_HP_HELLFIRE_RACK", "RHS_HP_LONGBOW_RACK"};
    ammo = "VTX_Hellfire_AGM114K";
    pylonWeapon = "vtx_hellfire_launcher";
  };
  class VTX_4Rnd_ACE_Hellfire_AGM114L: PylonRack_4Rnd_ACE_Hellfire_AGM114L { // 4x Launcher Support Rack
    displayName = "4x AGM-114L [H60]";
    //count = 4;
    mass = 261; // 65 for launcher, 49 per missile
    //hardpoints[] = {"UNI_SCALPEL", "CUP_NATO_HELO_LARGE", "RHS_HP_HELLFIRE_RACK", "RHS_HP_LONGBOW_RACK"};
    ammo = "VTX_Hellfire_AGM114L";
    pylonWeapon = "vtx_hellfire_launcher_L";
  };
  class VTX_4Rnd_ACE_Hellfire_AGM114N: PylonRack_4Rnd_ACE_Hellfire_AGM114N { // 4x Launcher Support Rack
    displayName = "4x AGM-114N [H60]";
    //count = 4;
    weight = 180;
    mass = 257; // 65 for launcher, 48 per missile
    //hardpoints[] = {"UNI_SCALPEL", "CUP_NATO_HELO_LARGE", "RHS_HP_HELLFIRE_RACK", "RHS_HP_LONGBOW_RACK"};
    ammo = "VTX_Hellfire_AGM114N";
    pylonWeapon = "vtx_hellfire_launcher_N";
  };
  class VTX_M230_Chaingun_L_HEI: VehicleMagazine {
    scope = 2;
    ammo = "vtx_300Rnd_30mm_shells_hedp";
    descriptionShort = "Single-barrel chain-driven autocannon firing 30x113 mm M789 High Explosive Dual Purpose (HEDP) rounds.";
    displayname = "30x113 mm HEI";
    displayNameShort = "30x113 HEI";
    initspeed = 805;
    pylonWeapon = "vtx_chaingun_hei";
    muzzlePos = "muzzlePos";
    muzzleEnd = "muzzleEnd";
    mass = 180; // cannon 60 kg, 300 * 0.34 kg per round
    tracersEvery = 1;
    lastRoundsTracer = 1;
    count = 300;
    hardpoints[] =    {"VTX_ST_L"};
    model = \z\vtx\addons\uh60_weapons\Data\M230\M230_L.p3d;
  };
  class VTX_M230_Chaingun_R_HEI: VehicleMagazine {
    scope = 2;
    ammo = "vtx_300Rnd_30mm_shells_hedp";
    displayname = "30x113 mm HEI";
    displayNameShort = "30x113 HEI";
    initspeed = 805;
    pylonWeapon = "vtx_chaingun_hei";
    muzzlePos = "muzzlePos";
    muzzleEnd = "muzzleEnd";
    weight = 180;
    mass = 180;
    tracersEvery = 1;
    lastRoundsTracer = 1;
    count = 300;
    hardpoints[] =    {"VTX_ST_R"};
    model = \z\vtx\addons\uh60_weapons\Data\M230\M230_R.p3d;
  };

  class PylonRack_12Rnd_missiles;
	class VTX_PylonRack_M261_M229: PylonRack_12Rnd_missiles {
		author = "Ampersand";
		count = 19;
    displayName = "19x Hydra 70 M229 [H60]";
    displayNameShort = "19x Hydra 70 M229";
    mass = 300.4; // 36.3 kg launcher, 6.2 per motor, 7.7 per warhead
    model = QPATHTOF(fza_pod_m261.p3d);
	};
  class PylonRack_12Rnd_PG_missiles;
  class VTX_PylonRack_M261_DAGR: PylonRack_12Rnd_PG_missiles {
    ammo = "ACE_Hydra70_DAGR";
    author = "Ampersand";
    count = 19;
    displayName = "19x DAGR [H60]";
    displayNameShort = "19x DAGR";
    mass = 336.5; // 36.3 kg launcher, 15.8 per rocket
    model = QPATHTOF(fza_pod_m261.p3d);
    pylonWeapon = "vtx_dagr";
  };
  class VTX_M230_Chaingun_L_AP: VTX_M230_Chaingun_L_HEI {
    scope = 2;
    ammo = "vtx_300Rnd_30mm_shells_ap";
    displayname = "30x113 mm AP";
    displayNameShort = "30x113 AP";
    pylonWeapon = "vtx_chaingun_ap";
  };
  class VTX_M230_Chaingun_R_AP: VTX_M230_Chaingun_R_HEI {
    scope = 2;
    ammo = "vtx_300Rnd_30mm_shells_ap";
    displayname = "30x113 mm AP";
    displayNameShort = "30x113 AP";
    pylonWeapon = "vtx_chaingun_ap";
  };
  class VTX_PylonRack_M261_APKWS: PylonRack_12Rnd_PG_missiles {
    ammo = "VTX_APKWS";
    author = "Ampersand";
    count = 19;
    displayName = "19x APKWS [H60]";
    displayNameShort = "19x APKWS";
    mass = 336.5; // 36.3 kg launcher, 15.8 per rocket
    model = QPATHTOF(fza_pod_m261.p3d);
    pylonWeapon = "vtx_apkws";
  };
};
