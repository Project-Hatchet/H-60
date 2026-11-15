// hct_HH60 — the Air Force HH-60G-dressed airframe (long-term identity:
// HH-60W). Sole full declaration (Phase 1 PR B): merged from UH60's identity
// half and uh60_config's systems half, 2026-09-05. Member order preserved from
// the pre-merge engine result (config-dump proven). The cabin seats are the
// three row sources, CabinSeats_1/2/3_Hide.
// Liveries (data\, data\fire\) and the editor preview ship in this PBO; the
// airframe model and baked textures stay in UH60.

// screen templates (owned by uh60_mfd / uh60_fms / uh60_anvishud; resolve by
// name at config read time)
class HCT_MFD_1;
class HCT_MFD_1_CMWS;
class HCT_MFD_1_Monospace;
class HCT_MFD_1_Bold;
class HCT_MFD_2;
class HCT_MFD_2_CMWS;
class HCT_MFD_2_Monospace;
class HCT_MFD_2_Bold;
class HCT_MFD_3;
class HCT_MFD_3_CMWS;
class HCT_MFD_3_Monospace;
class HCT_MFD_3_Bold;
class HCT_MFD_4;
class HCT_MFD_4_CMWS;
class HCT_MFD_4_Monospace;
class HCT_MFD_4_Bold;
class NVGHUD;
class NVGHUD_COPILOT;
class HCT_CLOCK;
class HCT_ESIS_Horizon;
class HCT_ESIS_Misc;
class HCT_FDRight;
class HCT_FDLeft;
class HCT_FMS_L;
class HCT_FMS_R;
class HCT_ESIS_BOOT;
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
  class hct_H60_base: Heli_Transport_01_base_F {
    class hct_templateFLIR;
    class MFD;
    class BMKHS_HeliSim {
      class Seats;
    };
    class AnimationSources: AnimationSources {
      class FuelProbe_show;
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

  class hct_HH60: hct_H60_base {
    scope = 2;
    forceInGarage = 1;
    editorPreview = "z\vtx\addons\hh60\data\preview\vtx_HH60.jpg";
    displayName = "$STR_hct_h60_HHGMPavehawk";
    memoryPointDriverOptics = "pilotcamera_flir_pos";

    hiddenSelectionsTextures[] = {
      "","","","","","","","","","","","","","","","",
      "z\vtx\addons\hh60\data\Hull_Main_co.paa",
      "z\vtx\addons\hh60\data\Misc_co.paa",
      "z\vtx\addons\hh60\data\Hull_Tail_co.paa",
      "a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa", // "markings",
      "", // "left_num_1",
      "", // "left_num_2",
      "", // "right_num_1",
      "", // "right_num_2",
      "z\vtx\addons\hh60\data\Fuel_probe_co.paa",
      "z\vtx\addons\mh60m\data\mlass_co.paa"
    };
    memoryPointCM[] = {"flare_launcher1","flare_launcher2","flare_launcher_3","flare_launcher_4"};
    memoryPointCMDir[] = {"flare_launcher1_dir","flare_launcher2_dir","flare_launcher_3_dir","flare_launcher_4_dir"};
    class pilotCamera: hct_templateFLIR {};
    weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
    magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
    driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
    class Turrets: Turrets {
#define COPILOT_MOUNT_NVGHUD
      #include "\z\vtx\addons\uh60_config\config\turrets\copilot.hpp"
#undef COPILOT_MOUNT_NVGHUD
      class MainTurret: MainTurret {};
      class RightDoorGun: RightDoorGun {};
      #include "\z\vtx\addons\uh60_config\config\turrets\cargoTurrets.hpp"
      #include "\z\vtx\addons\uh60_config\config\turrets\troopCommander_mh60.hpp"
    };

    transportSoldier=0;
    cargoProxyIndexes[] = {12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
    ace_medical_treatment_patientSeats[] = {4, 5, 7, 8};
    cargoAction[] = {};
    class AnimationSources: AnimationSources {
      ANIM_INIT(FuelProbe_show,1);
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
    #include "\z\vtx\addons\uh60_config\config\vehicleTransport.hpp"
    class MFD: MFD {
      class HCT_MFD_1 :           HCT_MFD_1 {};
      class HCT_MFD_1_CMWS :      HCT_MFD_1_CMWS {};
      class HCT_MFD_1_Monospace : HCT_MFD_1_Monospace {};
      class HCT_MFD_1_Bold :      HCT_MFD_1_Bold {};
      class HCT_MFD_2 :           HCT_MFD_2 {};
      class HCT_MFD_2_CMWS :      HCT_MFD_2_CMWS {};
      class HCT_MFD_2_Monospace : HCT_MFD_2_Monospace {};
      class HCT_MFD_2_Bold :      HCT_MFD_2_Bold {};
      class HCT_MFD_3 :           HCT_MFD_3 {};
      class HCT_MFD_3_CMWS :      HCT_MFD_3_CMWS {};
      class HCT_MFD_3_Monospace : HCT_MFD_3_Monospace {};
      class HCT_MFD_3_Bold :      HCT_MFD_3_Bold {};
      class HCT_MFD_4 :           HCT_MFD_4 {};
      class HCT_MFD_4_CMWS :      HCT_MFD_4_CMWS {};
      class HCT_MFD_4_Monospace : HCT_MFD_4_Monospace {};
      class HCT_MFD_4_Bold :      HCT_MFD_4_Bold {};
      class NVGHUD: NVGHUD {};
      class HCT_CLOCK: HCT_CLOCK {};
      class HCT_ESIS_Horizon: HCT_ESIS_Horizon {};
      class HCT_ESIS_Misc: HCT_ESIS_Misc {};
      class HCT_FDRight: HCT_FDRight {};
      class HCT_FDLeft: HCT_FDLeft {};
      class HCT_FMS_L: HCT_FMS_L {};
      class HCT_FMS_R: HCT_FMS_R {};
      class HCT_ESIS_BOOT: HCT_ESIS_BOOT {};
    };
    // HeliSim seats (SEATS_* in uh60_helisim bmkhs_config/helisim_seats.hpp)
    class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_MH60M };
  }; // hct_HH60

}; // CfgVehicles
