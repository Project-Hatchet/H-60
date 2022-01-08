class CfgVehicles {
  class Helicopter_Base_H;
  class Heli_Transport_01_base_F: Helicopter_Base_H {
    class AnimationSources;
    class CargoTurret;
    class Turrets;
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
  }; // vtx_H60_base

  class vtx_UH60M: vtx_H60_base {
    class AnimationSources: AnimationSources {
      ANIM_INIT(Hoist_hide,1);
      class CabinSeats_1_Hide {
        displayName = "Hide Cabin Seats (Front)";
        source="user";
        animPeriod=1;
        initPhase=0;
        mass = -MASS_CABINSEATS3;
        lockCargoAnimationPhase = 1;
        lockCargo[] = { 8, 9, 10 };
      };
      class CabinSeats_2_Hide {
        displayName = "Hide Cabin Seats (Middle)";
        source="user";
        animPeriod=1;
        initPhase=0;
        mass = -MASS_CABINSEATS4;
        lockCargoAnimationPhase = 1;
        lockCargo[] = { 4, 5, 6, 7 };
        forceAnimatePhase = 0;
        forceAnimate[] = {
          "GAU21_L_Hide", 1,
          "GAU21_R_Hide", 1
        };
      };
      class CabinSeats_3_Hide {
        displayName = "Hide Cabin Seats (Rear)";
        source="user";
        animPeriod=1;
        initPhase=0;
        mass = -MASS_CABINSEATS4;
        lockCargoAnimationPhase = 1;
        lockCargo[] = { 0, 1, 2, 3 };
        forceAnimatePhase = 0;
        forceAnimate[] = {
          "ERFS_show", 0,
          "GAU21_L_Hide", 1,
          "GAU21_R_Hide", 1
        };
      };
    }; // AnimationSources
  }; // vtx_UH60M

  class vtx_UH60M_MEDEVAC: vtx_H60_base {
    scope = 2;
    cargoAction[] = {
      "passenger_low01",
      "passenger_generic01_leanleft",
      "passenger_generic01_leanleft",
      "passenger_generic01_leanright"
    };
    cargoProxyIndexes[] = {1, 2, 3, 4, 24, 25, 6, 7, 12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
    displayName = "UH-60M MEDEVAC";
    hiddenSelectionsTextures[] = {
      "","","","","","","","","","","","","","","","",
      "z\vtx\addons\uh60_misc\data\textures\UH-60M_US_Army_Medevac\main_co.paa",
      "z\vtx\addons\UH60\Data\Exterior\Misc_co.paa",
      "z\vtx\addons\uh60_misc\data\textures\UH-60M_US_Army_Medevac\tail_co.paa",
      "","","","","", // Markings, door numbers L1, L2, R1, R2
      "z\vtx\addons\UH60\Data\FuelProbe\Fuel_probe_co.paa"
    };
    transportSoldier=4;
    class AnimationSources: AnimationSources {
      ANIM_INIT(CabinSeats_1_Hide,1);
      ANIM_INIT(CabinSeats_2_Hide,1);
      ANIM_INIT(Hoist_hide,0);
      ANIM_INIT(Minigun_Mount_L_hide,1);
      ANIM_INIT(Minigun_Mount_R_hide,1);
      ANIM_INIT(Minigun_L_hide,1);
      ANIM_INIT(Minigun_R_hide,1);
      // Door seats
      class cabindoor_L: cabindoor_L {
        onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[5], [6]] ;";
      };
      class cabindoor_R: cabindoor_R {
        onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[3], [4]] ;";
      };
    }; // AnimationSources
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {};
      #include "turrets\doorgunsFFV.hpp"
      #include "..\..\UH60\config\turrets\cargoTurrets.hpp"
    };
    #include "..\..\UH60\config\vehicleTransport.hpp"
    class vxf_turret_1 {};
    class vxf_turret_2 {};
  };

  class vtx_UH60M_SLICK: vtx_H60_base {
    class AnimationSources: AnimationSources {
      ANIM_INIT(CabinSeats_1_Hide,1);
      ANIM_INIT(CabinSeats_2_Hide,1);
      ANIM_INIT(CabinSeats_3_Hide,1);
      // Guns
      ANIM_INIT(Minigun_Mount_L_hide,1);
      ANIM_INIT(Minigun_Mount_R_hide,1);
      ANIM_INIT(Minigun_L_hide,1);
      ANIM_INIT(Minigun_R_hide,1);
      class GunnerSeats_Hide: GunnerSeats_Hide {
        initPhase = 1;
        onPhaseChanged = "";
      };
      // Door seats
      class cabindoor_L: cabindoor_L {
        onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[3], [4]] ;";
      };
      class cabindoor_R: cabindoor_R {
        onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[1], [2]] ;";
      };
    }; // AnimationSources
  }; // vtx_UH60M_SLICK

  class vtx_HH60 : vtx_H60_base {
    class AnimationSources: AnimationSources {
      ANIM_INIT(FuelProbe_show,1);
      ANIM_INIT(HH60Flares_show,1);
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
  }; // vtx_HH60
}; // CfgVehicles
