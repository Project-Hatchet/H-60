#define STRINGIFY(s) #s
#define action_tablet_open(CLASS, NAME) \
  class CLASS { \
    displayName = NAME; \
    condition = [_player,STRINGIFY(CLASS)] call ace_common_fnc_hasItem; \
    statement = [STRINGIFY(CLASS)] call vtx_uh60_tab_tablet_fnc_open; \
    priority = 2.6; \
    showDisabled = 1; \
    exceptions[] = {"isNotInside","isNotSitting"}; \
  };

class cfgVehicles {
  class Man;
  class CAManBase: Man {
    class ACE_SelfActions {
      class ACE_Equipment {
        class uh60_tab_Open {
          displayName = "Open JVMF Tablet";
          condition = "false";
          statement = "createDialog ""vtx_uh60_jvmf_inboxDialog"";";
          priority = 2.6;
          showDisabled = 1;
          exceptions[] = {};
        };
      };
    };
  };
};
