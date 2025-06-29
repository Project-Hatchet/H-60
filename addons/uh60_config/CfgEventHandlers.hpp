class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_Init_EventHandlers {
  class vtx_H60_base {
    class ADDON {
      init = QUOTE(call FUNC(initH60));
    };
  };
};

class Extended_TurnOut_EventHandlers {
    class vtx_h60_base {
        class ADDON {
            turnOut = QUOTE(call FUNC(handleTurnOut));
        };
    };
};
