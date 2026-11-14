// vanilla externs referenced by the base body and the shared turret includes
class VehicleSystemsTemplateLeftPilot;
class VehicleSystemsTemplateRightPilot;
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;

// pedestal screens (VTX_ESIS_*, VTX_CLOCK, VTX_FDRight/Left) are owned by uh60_mfd;
// the variants mount them by name

// externs for screen templates owned by the screen addons, which may load
// after us — the MFD mounts below resolve by name when the config is read
// (load-order experiment, 2026-09-05)
class VTX_MFD_1_NOFLIR;
class VTX_MFD_1_CMWS;
class VTX_MFD_1_Monospace;
class VTX_MFD_1_Bold;
class VTX_MFD_2_NOFLIR;
class VTX_MFD_2_CMWS;
class VTX_MFD_2_Monospace;
class VTX_MFD_2_Bold;
class VTX_MFD_3_NOFLIR;
class VTX_MFD_3_CMWS;
class VTX_MFD_3_Monospace;
class VTX_MFD_3_Bold;
class VTX_MFD_4_NOFLIR;
class VTX_MFD_4_CMWS;
class VTX_MFD_4_Monospace;
class VTX_MFD_4_Bold;
class VTX_MFD_1;
class VTX_MFD_2;
class VTX_MFD_3;
class VTX_MFD_4;
class NVGHUD;
class NVGHUD_COPILOT;
class VTX_FMS_L;
class VTX_FMS_R;
class VTX_ESIS_BOOT;

class CfgVehicles {
  #include "crew.hpp"
  class Helicopter_Base_H;
  class Heli_Transport_01_base_F: Helicopter_Base_H {
    class AnimationSources;
    class Turrets
    {
      class MainTurret;
      class CopilotTurret;
    };
    class Attributes;
    class Eventhandlers;
    class Viewoptics;
    class ViewPilot;
    class CargoTurret;
    class Components;
    class Sounds;
    class HitPoints;
    class UserActions;
  };

  // Sole full declaration of the shared base (Phase 1 PR C): a base edit
  // propagates to every variant across all H-60 addons.
  #include "vehicles\H60_base.hpp"

  // Variants live in their own PBOs (leaves of the dependency graph):
  // uh60m (UH60M, SLICK, MEDEVAC), s70i, hh60, mh60m, mh60s.
}; // CfgVehicles

class CfgNonAIVehicles {
  class ProxyRetex;
  class ProxyFuel_probe_extending: ProxyRetex {
    hiddenSelections[] = {HIDDENSELECTIONS};
    model = "\z\vtx\addons\UH60\Data\FuelProbe\Fuel_probe_extending.p3d";
  };
  class ProxyESSS2x: ProxyRetex {
    hiddenSelections[] ={HIDDENSELECTIONS};
    model = "\z\vtx\addons\UH60\ESSS2x.p3d";
  };
};
