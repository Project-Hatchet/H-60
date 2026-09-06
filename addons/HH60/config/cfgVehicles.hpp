// vtx_HH60 — the Air Force HH-60G-dressed airframe (long-term identity:
// HH-60W). Sole full declaration (Phase 1 PR B): merged from UH60's identity
// half and uh60_config's systems half, 2026-09-05. Member order preserved from
// the pre-merge engine result (config-dump proven). CabinSeats_Hide collision
// resolved to the live value: initPhase=0 (uh60_config's granular replacement
// always won; UH60's ,1 was dead-but-misleading).
// Assets stay in UH60 — path references need no dependency edge.

// screen templates (owned by uh60_mfd / uh60_fms / uh60_anvishud; resolve by
// name at config read time)
class VTX_MFD_1;
class VTX_MFD_1_CMWS;
class VTX_MFD_1_Monospace;
class VTX_MFD_1_Bold;
class VTX_MFD_2;
class VTX_MFD_2_CMWS;
class VTX_MFD_2_Monospace;
class VTX_MFD_2_Bold;
class VTX_MFD_3;
class VTX_MFD_3_CMWS;
class VTX_MFD_3_Monospace;
class VTX_MFD_3_Bold;
class VTX_MFD_4;
class VTX_MFD_4_CMWS;
class VTX_MFD_4_Monospace;
class VTX_MFD_4_Bold;
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
// vanilla externs referenced by the shared turret includes
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

  // content-free re-open: forward declarations only, so the merged variant
  // below resolves its parents at rapify time (owned by UH60/uh60_config)
  class vtx_H60_base: Heli_Transport_01_base_F {
    class vtx_templateFLIR;
    class MFD;
    class AnimationSources: AnimationSources {
      class FuelProbe_show;
      class CabinSeats_Hide;
      class HH60Flares_show;
      class HH60GRadar_show;
      class HH60GFlir_show;
      class MAWS_Tubes_Show;
      class ERFS_show;
      class Minigun_Sight_L_hide;
      class Minigun_Sight_R_hide;
      class GunnerSeats_Hide;
      class CabinSeats_1_Hide;
      class CabinSeats_2_Hide;
      class CabinSeats_3_Hide;
      class cabindoor_L;
      class cabindoor_R;
    };
    class Turrets: Turrets {
      class CopilotTurret;
      class MainTurret;
      class RightDoorGun;
    };
  };

  class vtx_HH60: vtx_H60_base {
    scope = 2;
    forceInGarage = 1;
    editorPreview = "z\vtx\addons\UH60\Data\Preview\vtx_HH60.jpg";
    displayName = "$STR_VTX_UH60_HHGMPavehawk";
    memoryPointDriverOptics = "pilotcamera_flir_pos";

    hiddenSelectionsTextures[] = {
      "","","","","","","","","","","","","","","","",
      "z\vtx\addons\UH60\Data\HH60\Hull_Main_co.paa",
      "z\vtx\addons\UH60\Data\HH60\Misc_co.paa",
      "z\vtx\addons\UH60\Data\HH60\Hull_Tail_co.paa",
      "a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa", // "markings",
      "", // "left_num_1",
      "", // "left_num_2",
      "", // "right_num_1",
      "", // "right_num_2",
      "z\vtx\addons\UH60\Data\HH60\Fuel_probe_co.paa",
      "z\vtx\addons\mh60m\data\mlass_co.paa"
    };
    memoryPointCM[] = {"flare_launcher1","flare_launcher2","flare_launcher_3","flare_launcher_4"};
    memoryPointCMDir[] = {"flare_launcher1_dir","flare_launcher2_dir","flare_launcher_3_dir","flare_launcher_4_dir"};
    class pilotCamera: vtx_templateFLIR {};
    weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
    magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
    driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
    class Turrets: Turrets {
#define COPILOT_MOUNT_NVGHUD
      #include "\z\vtx\addons\UH60\config\turrets\copilot.hpp"
#undef COPILOT_MOUNT_NVGHUD
      class MainTurret: MainTurret {};
      class RightDoorGun: RightDoorGun {};
      #include "\z\vtx\addons\UH60\config\turrets\cargoTurrets.hpp"
      #include "\z\vtx\addons\MH60M\config\turrets\troopCommander.hpp"
    };

    transportSoldier=0;
    cargoProxyIndexes[] = {12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
    ace_medical_treatment_patientSeats[] = {4, 5, 7, 8};
    cargoAction[] = {};
    class AnimationSources: AnimationSources {
      ANIM_INIT(FuelProbe_show,1);
      class CabinSeats_Hide: CabinSeats_Hide {
        initPhase = 0;
        onPhaseChanged = "";
      };
      ANIM_INIT(HH60Flares_show,1);
      ANIM_INIT(HH60GRadar_show,1);
      ANIM_INIT(HH60GFlir_show,1);
      ANIM_INIT(MAWS_Tubes_Show,1);
      ANIM_INIT(ERFS_show,1);
      ANIM_INIT(Minigun_Sight_L_hide,1);
      ANIM_INIT(Minigun_Sight_R_hide,1);
      class GunnerSeats_Hide: GunnerSeats_Hide {
        initPhase = 0;
        onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[1], [2]] ;";
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
    #include "\z\vtx\addons\UH60\config\vehicleTransport.hpp"
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
  }; // vtx_HH60
}; // CfgVehicles
