class CopilotTurret: CopilotTurret {
  weapons[]=
  {
      //"Laserdesignator_mounted"
  };
  magazines[] = {};
  // Animation class
  body = "";
  gun = "";

  // Animation source
  animationSourceBody = "";
  animationSourceGun = "";
  stabilizedInAxes = 0;
  minElev = -180;
  maxElev = 40;
  initElev = 0;
  minTurn = -180;
  maxTurn = 180;
  initTurn = 0;
  minFov = 0.25;
  maxFov = 0.9;
  initFov = 0.75;
  // #556 HOTFIX: optics classes removed. An optics turret makes the engine
  // render the View-Gunner LOD, which vtx_uh60.p3d does not have, so the
  // copilot fell back to a gutted resolution LOD (see-through console).
  // A/B-proven in-game 2026-08-16: only physical absence of OpticsIn heals it.
  // Restore the optics (and this seat's turret FLIR view) once the model
  // gains a View - Gunner (1000) LOD - a copy of View - Pilot (1100) works.
  memoryPointGunnerOptics = "";
  memoryPointGunnerOutOptics = "";
  gunBeg = "flir_cam_dir";
  gunEnd = "flir_cam_pos";
  turretFollowFreeLook = 0;
  turretInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
  // #include "OpticsIn.hpp"
  CanEject=0;
  gunnerAction = "UH60_Pilot";
  gunnerInAction = "UH60_Pilot";
  canHideGunner = 1;
  forceHideGunner = 1;
  soundAttenuationTurret = "SemiOpenHeliAttenuation";
  viewGunnerInExternal = 1;
  gunnerUsesPilotView = 1;
  // 1100 = View - Pilot LOD; without these the turret defaults to the door-gunner
  // View - Gunner LOD and the copilot cockpit loses its upper console (#556)
  LODTurnedIn = 1100;
  LODTurnedOut = 1100;
  gunnerRightHandAnimName="Cyclic_left";
  gunnerLeftHandAnimName="Collective_left";
  gunnerLeftLegAnimName="Pedal_Left_CP";
  gunnerRightLegAnimName="Pedal_Right_CP";
  memoryPointsGetInGunner="pos codriver";
  memoryPointsGetInGunnerDir="pos codriver dir";

  gunnerGetInAction="copilot_Heli_Light_02_Enter";
  gunnerGetOutAction="copilot_Heli_Light_02_Exit";
  selectionFireAnim="";

  preciseGetInOut=1;
  GunnerDoor="Door_LF";
  proxyIndex=3;
  commanding=-1;
  class ViewGunner: ViewPilot {
    #include "ViewPilot.hpp"
  };
  class Hitpoints {};
  class Components {
    class SensorsManagerComponent {
      class Components {
        class LaserSensorComponent: SensorTemplateLaser {};
        class PassiveRadarSensorComponent: SensorTemplatePassiveRadar {
          angleRangeHorizontal 	= 360;
          angleRangeVertical 		= 360;
        };
        class DatalinkSensorComponent: SensorTemplateDataLink {
          angleRangeHorizontal 	= 360;
          angleRangeVertical 		= 360;
        };
      };
    };
    class VehicleSystemsDisplayManagerComponentLeft {};
    class VehicleSystemsDisplayManagerComponentRight {};
  };
};
