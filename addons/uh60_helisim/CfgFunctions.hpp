#define R recompile = 1

class CfgFunctions
{
    class vtx_uh60_helisim_project
    {
        tag = "vtx_uh60_helisim";
        //The bridge to HeliSim
        class functions {
            file = "\z\vtx\addons\uh60_helisim\functions";
            class setup           {R;};
            class perFrame        {R;};
        };
        //The H-60's own
        class custom {
            file = "\z\vtx\addons\uh60_helisim\functions\custom";
            class cockpitInteract {R;};
            class cockpitBind     {R;};
            class cockpitAllowed  {R;};
            class leverSpeed      {R;};
            class fmcInput        {R;};
            class fdKnob          {R;};
            class updateCockpit   {R;};
            class updateVisuals   {R;};
            class updateLimits    {R;};
        };
    };
};
