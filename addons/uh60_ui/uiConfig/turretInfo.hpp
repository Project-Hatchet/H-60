class RscUnitInfo;
class Rsc_vtx_MELB_Turret_UnitInfo: RscUnitInfo
{
    idd = 300;
    onLoad = "uiNamespace setVariable [""vtx_uh60_flir_ui"",(_this select 0)];['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay');";
    controls[] = {"MELB_GUI"}; //, "SeekerT", "SeekerT2", "SeekerT_m", "SeekerT_n", "SeekerT_n2"};
    class VScrollbar;
    class HScrollbar;
    /*
    class SeekerT: RscPicture {
        idc = 1021;
        x = "(32-20) * 	(safezoneW / 64) + 	(safeZoneX)";
        y = "0 * 		(safezoneH / 40) + 	(safeZoneY)";
        w = "40 * 		(safezoneW / 64)";
        h = "40 * 		(safezoneH / 40)";
        text = "z\vtx\addons\uh60_flir\data\melb_flir_w_ca.paa";
    };
    class SeekerT2: RscPicture {
        idc = 1022;
        x = "(32-20) * 	(safezoneW / 64) + 	(safeZoneX)";
        y = "0 * 		(safezoneH / 40) + 	(safeZoneY)";
        w = "40 * 		(safezoneW / 64)";
        h = "40 * 		(safezoneH / 40)";
        text = "z\vtx\addons\uh60_flir\data\melb_flir_w2_ca.paa";
    };
    class SeekerT_m: RscPicture {
        idc = 1023;
        x = "(32-20) * 	(safezoneW / 64) + 	(safeZoneX)";
        y = "0 * 		(safezoneH / 40) + 	(safeZoneY)";
        w = "40 * 		(safezoneW / 64)";
        h = "40 * 		(safezoneH / 40)";
        text = "z\vtx\addons\uh60_flir\data\melb_flir_m_ca.paa";
    };
    class SeekerT_n: RscPicture {
        idc = 1024;
        x = "(32-20) * 	(safezoneW / 64) + 	(safeZoneX)";
        y = "0 * 		(safezoneH / 40) + 	(safeZoneY)";
        w = "40 * 		(safezoneW / 64)";
        h = "40 * 		(safezoneH / 40)";
        text = "z\vtx\addons\uh60_flir\data\melb_flir_n_ca.paa";
    };
    class SeekerT_n2: RscPicture {
        idc = 1025;
        x = "(32-20) * 	(safezoneW / 64) + 	(safeZoneX)";
        y = "0 * 		(safezoneH / 40) + 	(safeZoneY)";
        w = "40 * 		(safezoneW / 64)";
        h = "40 * 		(safezoneH / 40)";
        text = "z\vtx\addons\uh60_flir\data\melb_flir_n2_ca.paa";
    };
    */
    #include "MELB_GUI.hpp"
};
