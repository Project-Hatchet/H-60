// Rapify scaffold for variant addons, not config content.
// Include INSIDE `class CfgVehicles {` before the variant declarations. It is a
// content-free re-open of the common base (owned by uh60_config/config/vehicles/
// H60_base.hpp) so `class X: X` re-opens inside a variant resolve in the variant
// PBO's own translation unit. Keep in sync when the base gains members a variant
// re-opens. Adds nothing at runtime.
class Helicopter_Base_H;
class Heli_Transport_01_base_F: Helicopter_Base_H {
  class AnimationSources;
  class CargoTurret;
  class Turrets;
  class ViewPilot;
  class Components;
};
class vtx_H60_base: Heli_Transport_01_base_F {
  #include "CfgAnimationSourcesInherit.hpp"
  class ViewPilot;
  class vtx_templateFLIR;
  class Components;
  class MFD;
  class hct_turret_1;
  class hct_turret_2;
  class Turrets: Turrets {
    class CopilotTurret;
    class MainTurret;
    class RightDoorGun;
  };
};
