#define RGBA256(R,G,B,A) {R/256,G/256,B/256,A}
class uh60_tab_dacas {
  idd = 20001;
  movingEnable = true;
//   onLoad="_this spawn vtx_uh60_tab_fnc_ui_init";
//   onDestroy="call vtx_uh60_tab_fnc_killFeed";
  class Controls {
	class IGUIBack_2200: IGUIBack
	{
		idc = 2200;
		x = 0.1;
		y = 0.18;
		w = 0.8125;
		h = 0.64;
      	colorBackground[] = RGBA256(51,58,117,1);
	};
	class RscPicture_1200: RscPicture
	{
		idc = 1200;
		text = "z\vtx\addons\uh60_jvmf\data\screen2.paa";
		x = 0;
		y = 0;
		w = 1;
		h = 1;
	};
	class RscButton_1600: RscButton
	{
		idc = 1600;
		text = "JVMF Inbox"; //--- ToDo: Localize;
		x = 0.15;
		y = 0.2;
		w = 0.15;
		h = 0.04;
	};
	class RscButton_1601: RscButton
	{
		idc = 1601;
		text = "ROVER"; //--- ToDo: Localize;
		x = 0.3;
		y = 0.2;
		w = 0.15;
		h = 0.04;
	};
	class RscButton_1602: RscButton
	{
		idc = 1602;
		text = "MAP"; //--- ToDo: Localize;
		x = 0.45;
		y = 0.2;
		w = 0.15;
		h = 0.04;
	};
    class uh60_tab_UAVi_IGUI_elements_group: RscControlsGroup {
      idc = 75001;
      x = "0";
      y = "0";
      w = "safeZoneW";
      h = "safezoneH";
      class controls {
		  #include "pages\inbox.hpp"
	  };
	};
  };
};