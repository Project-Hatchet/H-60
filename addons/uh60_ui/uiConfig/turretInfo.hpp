class RscUnitInfo;
class Rsc_MELB_Turret_UnitInfo: RscUnitInfo
{
    idd = 300;
    onLoad = "['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay');";
    controls[] = {"MELB_GUI"};
    class VScrollbar;
    class HScrollbar;
    #include "MELB_GUI.hpp"
};
