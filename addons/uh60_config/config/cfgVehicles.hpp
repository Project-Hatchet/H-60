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

  class vtx_HH60 : vtx_H60_base {
    class AnimationSources: AnimationSources {
      ANIM_INIT(FuelProbe_show,1);
      ANIM_INIT(HH60Flares_show,1);
      ANIM_INIT(HH60GRadar_show,1);
      ANIM_INIT(HH60GFlir_show,1);
      class GunnerSeats_Hide: GunnerSeats_Hide {
        initPhase = 0;
        onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[1], [2]] ;";
      };
      class CabinSeats_Hide: CabinSeats_Hide {
        initPhase = 0;
        onPhaseChanged = "";
      };
      ANIM_INIT(CabinSeats_1_Hide,1);
      ANIM_INIT(CabinSeats_2_Hide,1);
      ANIM_INIT(CabinSeats_3_Hide,1);
      // Door seats
      class cabindoor_L: cabindoor_L {
        onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[5], [6]] ;";
      };
      class cabindoor_R: cabindoor_R {
        onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[3], [4]] ;";
      };
    }; // AnimationSources
    class MFD: MFD {
      class VTX_MFD_1 :           VTX_MFD_1 {};
      class VTX_MFD_1_CMWS :      VTX_MFD_1_CMWS {};
      class VTX_MFD_1_Monospace : VTX_MFD_1_Monospace {};
      class VTX_MFD_1_Bold :      VTX_MFD_1_Bold {};
      class VTX_MFD_2 :           VTX_MFD_2 {};
      class VTX_MFD_2_CMWS :      VTX_MFD_2_CMWS {};
      class VTX_MFD_2_Monospace : VTX_MFD_2_Monospace {};
      class VTX_MFD_2_Bold :      VTX_MFD_2_Bold {};
      class VTX_MFD_3 :           VTX_MFD_3 {};
      class VTX_MFD_3_CMWS :      VTX_MFD_3_CMWS {};
      class VTX_MFD_3_Monospace : VTX_MFD_3_Monospace {};
      class VTX_MFD_3_Bold :      VTX_MFD_3_Bold {};
      class VTX_MFD_4 :           VTX_MFD_4 {};
      class VTX_MFD_4_CMWS :      VTX_MFD_4_CMWS {};
      class VTX_MFD_4_Monospace : VTX_MFD_4_Monospace {};
      class VTX_MFD_4_Bold :      VTX_MFD_4_Bold {};
      class NVGHUD: NVGHUD {};
      class VTX_CLOCK: VTX_CLOCK {};
      class VTX_ESIS_Horizon: VTX_ESIS_Horizon {};
      class VTX_ESIS_Misc: VTX_ESIS_Misc {};
      class VTX_FDRight: VTX_FDRight {};
      class VTX_FDLeft: VTX_FDLeft {};
      class VTX_FMS_L: VTX_FMS_L {};
      class VTX_FMS_R: VTX_FMS_R {};
      class VTX_ESIS_BOOT: VTX_ESIS_BOOT {};
    };
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        class MFD {
              class NVGHUD: NVGHUD_COPILOT {};
        };
      };
      class MainTurret: MainTurret {};
      class RightDoorGun: RightDoorGun {};
    };
  }; // vtx_HH60
}; // CfgVehicles
