#define STRINGIFY(s) #s
#define action_tablet_open(CLASS, NAME) \
  class CLASS { \
    displayName = NAME; \
    condition = [_player,STRINGIFY(CLASS)] call ace_common_fnc_hasItem; \
    statement = STRINGIFY(createDialog ""vtx_uh60_jvmf_inboxDialog"";); \
    priority = 2.6; \
    showDisabled = 1; \
    exceptions[] = {"isNotInside","isNotSitting"}; \
  };

class cfgVehicles {
  class Man;
  class CAManBase: Man {
    class ACE_SelfActions {
      class ACE_Equipment {
        action_tablet_open(uh60_jvmf_tablet, "JVMF Tablet")
      };
    };
  };
};
