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
    class AnimationSources: AnimationSources {};
  };
  /* Each model still needs its custom init states and maybe some animations should not be allowed
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
