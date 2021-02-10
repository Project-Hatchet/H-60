class CfgAmmo {
  class M_Scalpel_AT;
  class ACE_Hellfire_AGM114K: M_Scalpel_AT {
    class ace_missileguidance;
  };
  class VTX_Hellfire_AGM114K: ACE_Hellfire_AGM114K {
    displayName = "AGM-114K Hellfire";
    model = "z\vtx\addons\uh60_weapons\fza_agm114k.p3d";
    proxyShape = "z\vtx\addons\uh60_weapons\fza_agm114k.p3d";
      class ace_missileguidance: ace_missileguidance {
        enabled = 1; // Missile Guidance must be explicitly enabled
      };
  };
};
