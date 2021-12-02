
class RscTitles {
  class vtx_uh60_flir_cameraOverlay {
    idd = 86005;
    movingEnable = 1;
    duration = 9999999;
    fadein = 0;
    fadeout = 0;
    onLoad = "uiNamespace setVariable [""vtx_uh60_flir_ui"",(_this select 0)];"; // ((_this select 0) displayCtrl -1) progressSetPosition 0.5
		class VScrollbar;
		class HScrollbar;
		class controls {
			class SeekerT: RscPicture {
				idc = 1021;
				x = "(32-20) * 	(safezoneW / 64) + 	(safeZoneX)";
				y = "0 * 		(safezoneH / 40) + 	(safeZoneY)";
				w = "40 * 		(safezoneW / 64)";
				h = "40 * 		(safezoneH / 40)";
				text = "z\vtx\addons\uh60_flir\data\melb_flir_w_ca.paa";
			};
      /*
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
  };
  class vtx_uh60_flir_crossHair {
    idd = 86005;
    movingEnable = 1;
    duration = 9999999;
    fadein = 0;
    fadeout = 0;
    onLoad = "uiNamespace setVariable [""vtx_uh60_flir_ui"",(_this select 0)];"; // ((_this select 0) displayCtrl -1) progressSetPosition 0.5
		class VScrollbar;
		class HScrollbar;
		class controls {
			class SeekerT: RscPicture {
				idc = 1021;
				x = "(32-20) * 	(safezoneW / 64) + 	(safeZoneX)";
				y = "0 * 		(safezoneH / 40) + 	(safeZoneY)";
				w = "40 * 		(safezoneW / 64)";
				h = "40 * 		(safezoneH / 40)";
				text = "z\vtx\addons\uh60_flir\data\melb_flir_w_ca.paa";
			};
		};
  };
};
