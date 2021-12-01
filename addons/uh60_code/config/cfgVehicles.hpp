#define ANIM_INIT(name,init) class name : name {initPhase = init;}

class CfgVehicles {
  class Helicopter_Base_H;
  class Heli_Transport_01_base_F: Helicopter_Base_H {
    class AnimationSources;
  };

  class vtx_H60_base: Heli_Transport_01_base_F {
    #include "CfgAnimationSources.hpp"
    #include "CfgTextureSources.hpp"
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
  /* Each model still needs its custom initPase onPhaseChanged
  class vtx_MH60M: vtx_H60_base {
    class AnimationSources: AnimationSources {};
  };
  class vtx_MH60M: vtx_H60_base {
    class AnimationSources: AnimationSources {};
  };
  class vtx_UH60M: vtx_H60_base {
    class AnimationSources: AnimationSources {};
  };
  */
};
