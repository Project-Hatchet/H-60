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
class VTX_CLOCK;
class VTX_ESIS_Horizon;
class VTX_ESIS_Misc;
class VTX_FDRight;
class VTX_FDLeft;
class VTX_FMS_L;
class VTX_FMS_R;
class VTX_ESIS_BOOT;
// vanilla externs referenced by the shared turret includes (copilot.hpp)
class SensorTemplatePassiveRadar;
class SensorTemplateLaser;
class SensorTemplateDataLink;

class CfgVehicles {
  class Helicopter_Base_H;
  class Heli_Transport_01_base_F: Helicopter_Base_H {
    class AnimationSources;
    class CargoTurret;
    class Turrets;
    class ViewPilot;
  };

  class vtx_H60_base: Heli_Transport_01_base_F {
    #include "CfgAnimationSources.hpp"
    #include "CfgTextureSources.hpp"
    class Armory {
      description = ""; // Remove Ghosthawk text
    };
    class Turrets: Turrets {
      class CopilotTurret;
      class MainTurret;
      class RightDoorGun;
    };
    class MFD;
    #include "hct_minigun.hpp"
    class hct_turret_3 {
    projectPrefix = "vtx_uh60";
      class modules {
          class ui {
              startOnEnter = 0;
          };
      }; // modules
    }; //TC Seat
  }; // vtx_H60_base

  // Sole full declarations of the Army family + civilian bird (Phase 1 PR A):
  // one vehicle per file, all deriving from vtx_H60_base — a base edit
  // propagates to every variant.
  #include "vehicles\UH60M.hpp"
  #include "vehicles\UH60M_MEDEVAC.hpp"
  #include "vehicles\S70M.hpp"
  #include "vehicles\UH60M_SLICK.hpp"

  // vtx_HH60: sole full declaration moved to addons/HH60 (Phase 1 PR B).
}; // CfgVehicles
