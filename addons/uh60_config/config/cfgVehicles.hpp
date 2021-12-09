class CfgVehicles {
  class Helicopter_Base_H;
  class Heli_Transport_01_base_F: Helicopter_Base_H {
    class AnimationSources;
    class UserActions;
  };

  class vtx_H60_base: Heli_Transport_01_base_F {
    #include "CfgAnimationSources.hpp"
    #include "CfgTextureSources.hpp"
    #include "CfgUserActions.hpp"
  };

  class vtx_UH60M: vtx_H60_base {
    #include "CfgAnimationSourcesInherit.hpp"
  };
  class vtx_UH60M_SLICK: vtx_H60_base {
    class AnimationSources: AnimationSources {
      class CabinSeats_Hide: CabinSeats_Hide {
        initPhase = 1;
        lockCargo[] = {};
      };
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
    };
  };
  class vtx_HH60 : vtx_UH60M {
    class AnimationSources: AnimationSources {
      ANIM_INIT(HH60Flares,1);
      class GunnerSeats_Hide: GunnerSeats_Hide {
        initPhase = 0;
        onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[1], [2]] ;";
      };
      // Door seats
      class cabindoor_L: cabindoor_L {
        onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[5], [6]] ;";
      };
      class cabindoor_R: cabindoor_R {
        onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[3], [4]] ;";
      };
    };
  };
  class vtx_MH60M: vtx_H60_base {
    class AnimationSources: AnimationSources {
      ANIM_INIT(Cockpitdoors_Hide,1);
      ANIM_INIT(RADAR_HIDE,0);
      ANIM_INIT(FLIR_HIDE,0);
      ANIM_INIT(Fuelprobe,1);
      ANIM_INIT(CabinSeats_Hide,1);
      ANIM_INIT(MAWS_Tubes_Show,1);
      ANIM_INIT(ERFS,1);
    };
  };
  class vtx_MH60M_DAP: vtx_MH60M {
    class AnimationSources: AnimationSources {
      ANIM_INIT(Cockpitdoors_Hide,1);
      ANIM_INIT(LASS_Show,1);
      ANIM_INIT(GunnerSeats_Hide,1);
      ANIM_INIT(CabinSeats_Hide,1);
    };
  };
  class vtx_MH60S_Pylons_GAU21L: vtx_H60_base {
    class AnimationSources: AnimationSources {
      ANIM_INIT(ESSS_Show,1);
      ANIM_INIT(CabinSeats_Hide,1);
      ANIM_INIT(GAU21_L_Hide,0);
      ANIM_INIT(MAWS_Tubes_Show,1);
      ANIM_INIT(FLIR_HIDE,0);
      ANIM_INIT(FLIR_BACK,1);
    };
  };
  class vtx_MH60S_GAU21L: vtx_H60_base {
    class AnimationSources: AnimationSources {
      ANIM_INIT(CabinSeats_Hide,1);
      ANIM_INIT(GAU21_L_Hide,0);
      ANIM_INIT(MAWS_Tubes_Show,1);
      ANIM_INIT(FLIR_HIDE,0);
      ANIM_INIT(FLIR_BACK,1);
    };
  };
  class vtx_MH60S_Pylons: vtx_H60_base {
    class AnimationSources: AnimationSources {
      ANIM_INIT(ESSS_Show,1);
      ANIM_INIT(CabinSeats_Hide,1);
      ANIM_INIT(MAWS_Tubes_Show,1);
      ANIM_INIT(FLIR_HIDE,0);
      ANIM_INIT(FLIR_BACK,1);
    };
  };
  class vtx_MH60S: vtx_H60_base {
    class AnimationSources: AnimationSources {
      ANIM_INIT(MAWS_Tubes_Show,1);
      ANIM_INIT(FLIR_HIDE,0);
      ANIM_INIT(FLIR_BACK,1);
    };
  };
};
