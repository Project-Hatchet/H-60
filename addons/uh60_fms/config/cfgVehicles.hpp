class CfgVehicles {
  class Helicopter_Base_F;
  class Helicopter_Base_H: Helicopter_Base_F {
    class hatchet_driver;
    class hatchet_copilot;
  }; // Helicopter_Base_H
  class Heli_Transport_01_base_F: Helicopter_Base_H {
    class hatchet_driver: hatchet_driver {
      class interaction;
      class modules;
    }; // hatchet_driver
    class hatchet_copilot: hatchet_copilot {
      class interaction;
      class modules;
    }; // hatchet_copilot
    class MFD;
  }; // Heli_Transport_01_base_F
  class vtx_H60_base: Heli_Transport_01_base_F {
    class hatchet_driver: hatchet_driver {
      class modules: modules {
        class fms {
          startOnEnter = 1;
        }; // fms
      }; // modules
      class interaction: interaction {
        class FMS {
          #define FMS_PAGE_INDEX FMS_R_PAGE_INDEX
          #define FMS_1 FMS_R_1
          #define FMS_2 FMS_R_2
          #define FMS_3 FMS_R_3
          #define FMS_4 FMS_R_4
          #define FMS_5 FMS_R_5
          #define FMS_6 FMS_R_6
          #define FMS_7 FMS_R_7
          #define FMS_8 FMS_R_8
          #define FMS_9 FMS_R_9
          #define FMS_10 FMS_R_10
          #include "interaction.hpp"
        }; // FMS
      }; // interaction
    }; // hatchet_driver
    class hatchet_copilot: hatchet_copilot {
      class modules: modules {
        class fms {
          startOnEnter = 1;
        }; // fms
      }; // modules
      class interaction: interaction {
        class FMS {
          #undef FMS_PAGE_INDEX
          #undef FMS_1
          #undef FMS_2
          #undef FMS_3
          #undef FMS_4
          #undef FMS_5
          #undef FMS_6
          #undef FMS_7
          #undef FMS_8
          #undef FMS_9
          #undef FMS_10
          #define FMS_PAGE_INDEX FMS_L_PAGE_INDEX
          #define FMS_1 FMS_L_1
          #define FMS_2 FMS_L_2
          #define FMS_3 FMS_L_3
          #define FMS_4 FMS_L_4
          #define FMS_5 FMS_L_5
          #define FMS_6 FMS_L_6
          #define FMS_7 FMS_L_7
          #define FMS_8 FMS_L_8
          #define FMS_9 FMS_L_9
          #define FMS_10 FMS_L_10
          #include "interaction.hpp"
        }; // FMS
      }; // interaction
    }; // hatchet_copilot
    class MFD: MFD {
      #undef FMS_PAGE_INDEX
      #define FMS_PAGE_INDEX FMS_R_PAGE_INDEX
      class FMS_R
      {
      	topLeft="FMS_ScreenR_LH";
      	topRight="FMS_ScreenR_RH";
      	bottomLeft="FMS_ScreenR_LD";
        #include "MFD\FMS.hpp"
      }; // FMS_R
      #undef FMS_PAGE_INDEX
      #define FMS_PAGE_INDEX FMS_L_PAGE_INDEX
      class FMS_L
      {
      	topLeft="FMS_ScreenL_LH";
      	topRight="FMS_ScreenL_RH";
      	bottomLeft="FMS_ScreenL_LD";
        #include "MFD\FMS.hpp"
      }; // FMS_L
    }; // MFD
  }; // vtx_H60_base
}; // CfgVehicles
