class RscUnitInfo;
class Rsc_vtx_MELB_Turret_UnitInfo: RscUnitInfo
{
    idd = 300;
    onLoad = "uiNamespace setVariable [""vtx_uh60_flir_ui"",(_this select 0)];['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay');";
    controls[] = {"MELB_GUI"};
    class VScrollbar;
    class HScrollbar;
    #include "MELB_GUI.hpp"
};
