class CopilotTurret: CopilotTurret {
  CanEject=0;
  gunnerAction = "UH60_Pilot";
  gunnerInAction = "UH60_Pilot";
  // #510 RESOLVED (2026-09-07): canHideGunner is deliberately NOT set here. The
  // legacy canHideGunner=0 line that lived here was the root cause - the engine
  // reads an explicit 0 as "gunner can never hide" = permanently turned out, so
  // attenuation never engaged (copilot loud). Flipping it to 1 fixed the sound
  // but put the seat on the turn-out render path - the same gutted-console
  // fallback as the #556 optics incident. Vanilla helicopter copilots leave it
  // unset (resolves -1): seat counts as inside AND renders LODTurnedIn. Do not
  // reintroduce this property in either polarity.
  viewGunnerInExternal = 1; // vanilla CargoTurret value; 0-flip tested 2026-09-07, no effect on sound, don't touch
  gunnerUsesPilotView = 1;
  soundAttenuationTurret = "VTX_H60_CabinAttenuation"; // #510: the stock SemiOpen profile was too mild - custom EQ profile in H60_SFX
  disableSoundAttenuation = 0;
  // 1100 = View - Pilot LOD; without these the turret defaults to the door-gunner
  // View - Gunner LOD and the copilot cockpit loses its upper console (#556)
  LODTurnedIn = 1100;
  LODTurnedOut = 1100;
  memoryPointGunnerOptics = "";
  memoryPointGunnerOutOptics = "";
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
  // No OpticsIn: the #556 A/B proved an optics turret broke the copilot console,
  // and the 2026-10-06 optics probe found its aim limits also hijack the
  // copilot's mouse. A copilot optics seat needs its own pass.
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
#ifdef COPILOT_MOUNT_NVGHUD
  // Variant-level NVG HUD mount (uh60_config's vehicle files define the flag);
  // the base include leaves it undefined so vtx_H60_base's copilot stays bare.
  class MFD {
    class NVGHUD: NVGHUD_COPILOT {};
  };
#endif
};
