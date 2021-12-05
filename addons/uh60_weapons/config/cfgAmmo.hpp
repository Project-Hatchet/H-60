class CfgAmmo {
  class M_Scalpel_AT;
  class ACE_Hellfire_AGM114K: M_Scalpel_AT {class ace_missileguidance;};
  class ACE_Hellfire_AGM114N: M_Scalpel_AT {class ace_missileguidance;};
  class VTX_Hellfire_AGM114K: ACE_Hellfire_AGM114K {
    displayName = "AGM-114K Hellfire";
    model = "z\vtx\addons\uh60_weapons\fza_agm114k.p3d";
    proxyShape = "z\vtx\addons\uh60_weapons\fza_agm114k.p3d";
    class ace_missileguidance: ace_missileguidance {
      enabled = 1; // Missile Guidance must be explicitly enabled
    };
  };
  class VTX_Hellfire_AGM114N: ACE_Hellfire_AGM114N {
    displayName = "AGM-114N Hellfire";
    model = "z\vtx\addons\uh60_weapons\fza_agm114k.p3d";
    proxyShape = "z\vtx\addons\uh60_weapons\fza_agm114k.p3d";
    class ace_missileguidance: ace_missileguidance {
      enabled = 1; // Missile Guidance must be explicitly enabled
    };
  };
  class Rocket_04_HE_F;
  class VTX_Rocket_APKWS: Rocket_04_HE_F {
    displayName = "M156 WP";
    indirectHit = 1;
    indirectHitRange = 10;
    explosive = 1;
  };
  class itc_ammo_Hydra_M257 : Rocket_04_HE_F {
    displayName = "M257 ILLUM";
    indirectHit = 1;
    indirectHitRange = 1;
    explosive = 0.1;
  };
  class FlareCore;
  class itc_ammo_m257_helper: FlareCore { //ILLUM
    model = "\A3\weapons_f\ammo\shell";
    effectFlare = "CounterMeasureFlare";
    aimAboveTarget[] = {50, 80, 140, 200, 260, 320, 380};
    aimAboveDefault = 4;
    triggerSpeedCoef = 1;
    triggerTime = 0.001;
    lightColor[] = {0.95, 0.95, 1, 0.5};
    smokeColor[] = {1, 1, 1, 0.5};
    brightness = 50;
    //intensity = 180000;
    //flareSize = 500;
    timeToLive = 90;
    ace_rearm_caliber = 155;
    //explosionTime = 1;
  };
};
