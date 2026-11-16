class hct_driver: hct_driver {
  class modules: modules {
      class acre {
          startOnEnter = 1;
      };
  };
  class interaction: interaction {
    class FMS {
      #ifdef FMS_PAGE_INDEX
      #undef FMS_PAGE_INDEX
      #endif
      #define FMS_PAGE_INDEX FMS_R_PAGE_INDEX
      class FMS_Keypad {
        class FMS_BTN_COM {
          positionType = "coordinates";
          position[] = {0.0688477,4.81626,-0.629442};
          label = "COM";
          radius = 0.025;
          buttonUp = QUOTE([ARR_3((_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_COMM_ACRE)],true)] call hct_h60_fms_fnc_interaction_pageChange);
        };
      };
    };
  };
};

class hct_copilot: hct_copilot {
    class modules: modules {
        class acre {
            startOnEnter = 1;
        };
    };
    class interaction: interaction {
        class FMS {
          #undef FMS_PAGE_INDEX
          #define FMS_PAGE_INDEX FMS_L_PAGE_INDEX
          class FMS_Keypad {
              class FMS_BTN_COM {
                positionType = "coordinates";
                position[] = {-0.1992183,4.81418,-0.629442};
                label = "COM";
                radius = 0.025;
                buttonUp = QUOTE([ARR_3((_this select 0),[ARR_2(FMS_PAGE_INDEX,FMS_PAGE_COMM_ACRE)],true)] call hct_h60_fms_fnc_interaction_pageChange);
              };
          };
        };
    }; // interaction
}; // copilot
