class CfgVehicles {
  class Helicopter_Base_H;
  class Heli_Transport_01_base_F: Helicopter_Base_H {
    class AnimationSources;
  };

  class vtx_H60_base: Heli_Transport_01_base_F {
    #include "CfgAnimationSources.hpp"
    #include "CfgTextureSources.hpp"
  };
};
