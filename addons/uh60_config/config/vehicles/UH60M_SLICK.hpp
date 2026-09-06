// vtx_UH60M_SLICK — the armed ViV-cargo variant (miniguns SHOWN for
// self-defense; Riverman's 2026-08-17 armament ruling). Sole full declaration
// (Phase 1 PR A): merged from UH60's identity half and uh60_config's systems
// half. UH60's five overridden hide-lines (GunnerSeats/Minigun/Mount = 1) were
// dead values the later loader always beat — the live 0s below are the ruling.
// Member order preserved from the pre-merge engine result (config-dump proven).
class vtx_UH60M_SLICK: vtx_H60_base {
  scope = 2;
  forceInGarage = 1;
  displayName = "UH-60M Slick";
  transportSoldier=0;
  cargoProxyIndexes[] = {};
  cargoAction[] = {};
  typicalCargo[] = {"vtx_uh60_doorgunner"};

  class AnimationSources: AnimationSources {
    ANIM_INIT(CabinSeats_Hide,1);
    ANIM_INIT(Hoist_hide,1);
    class GunnerSeats_Hide: GunnerSeats_Hide {
      initPhase = 0;
      onPhaseChanged = "";
    };
    // Guns shown (armament ruling)
    ANIM_INIT(Minigun_L_hide,0);
    ANIM_INIT(Minigun_R_hide,0);
    ANIM_INIT(Minigun_Mount_L_hide,0);
    ANIM_INIT(Minigun_Mount_R_hide,0);
    ANIM_INIT(Minigun_Sight_L_hide,1);
    ANIM_INIT(Minigun_Sight_R_hide,1);
    // Seats
    ANIM_INIT(CabinSeats_1_Hide,1);
    ANIM_INIT(CabinSeats_2_Hide,1);
    ANIM_INIT(CabinSeats_3_Hide,1);
    // Door seats
    class cabindoor_L: cabindoor_L {
      initPhase = 1;
      onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[3], [4]] ;";
    };
    class cabindoor_R: cabindoor_R {
      initPhase = 1;
      onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[1], [2]] ;";
    };
  }; // AnimationSources
  class Turrets: Turrets {
#define COPILOT_MOUNT_NVGHUD
    #include "..\..\..\UH60\config\turrets\copilot.hpp"
#undef COPILOT_MOUNT_NVGHUD
    class MainTurret: MainTurret {};
    class RightDoorGun: RightDoorGun {};
    #include "..\..\..\UH60\config\turrets\cargoTurretsDoor.hpp"
  };
  #include "..\..\..\UH60\config\vehicleTransportSlick.hpp"
  class MFD: MFD {
    class VTX_MFD_1_NOFLIR :           VTX_MFD_1_NOFLIR {};
    class VTX_MFD_1_CMWS :      VTX_MFD_1_CMWS {};
    class VTX_MFD_1_Monospace : VTX_MFD_1_Monospace {};
    class VTX_MFD_1_Bold :      VTX_MFD_1_Bold {};
    class VTX_MFD_2_NOFLIR :           VTX_MFD_2_NOFLIR {};
    class VTX_MFD_2_CMWS :      VTX_MFD_2_CMWS {};
    class VTX_MFD_2_Monospace : VTX_MFD_2_Monospace {};
    class VTX_MFD_2_Bold :      VTX_MFD_2_Bold {};
    class VTX_MFD_3_NOFLIR :           VTX_MFD_3_NOFLIR {};
    class VTX_MFD_3_CMWS :      VTX_MFD_3_CMWS {};
    class VTX_MFD_3_Monospace : VTX_MFD_3_Monospace {};
    class VTX_MFD_3_Bold :      VTX_MFD_3_Bold {};
    class VTX_MFD_4_NOFLIR :           VTX_MFD_4_NOFLIR {};
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
}; // vtx_UH60M_SLICK
