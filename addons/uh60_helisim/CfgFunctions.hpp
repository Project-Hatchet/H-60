#define R recompile = 1

class CfgFunctions
{
    class vtx_uh60_helisim_project
    {
        tag = "vtx_uh60_helisim";
        class functions {
            file = "\z\vtx\addons\uh60_helisim\functions";
            class setup           {R;};
            class perFrame        {R;};
            class cockpitInteract {R;};
            class cockpitBind     {R;};
            class cockpitAllowed  {R;};
            class updateCockpit   {R;};
            class updateVisuals   {R;};
        };
    };
};
