class RscInGameUI
{
    #include "turretInfo.hpp"
    class RscUnitInfoAir;
    class vtx_uh60_rscUnitInfoMinimal: RscUnitInfoAir
    {
        onLoad="[(vehicle player), ""ui"", _this # 0] call vxf_core_fnc_start;";
        controls[] = {
            //"CA_BackgroundVehicle",
            //"CA_BackgroundVehicleTitle",
            //"CA_Vehicle",
            "CA_VehicleRole",
            "HelpText",
            "Interaction",
            "HelpOverlay",
            "HelpOverlayGunner"
        };
		class HelpText: RscIGText
		{
			idc = 4001119;
			x = safezoneX + 0.015;
			y = safezoneY + 0.01;
			w = 0.5;
            h = 0.15;
			text = "Press H For Help";
		};
        class Interaction: RscPicture
        {
			idc = 4001120;
			x = safezoneX + safezoneW / 2 - 0.02;
			y = safezoneY + safezoneH / 2 - 0.02;
			w = 0.04;
            h = 0.04;
			text = "\A3\ui_f\data\igui\cfg\cursors\iconComplex_ca.paa";
        };
        class HelpOverlay: RscControlsGroup {
			idc = 4001121;
            x = safezoneX;
            y = safezoneY;
            w = safezoneW;
            h = safezoneH;
            class Controls {
                class InteractionText: RscIGText
                {
                    idc = 1;
                    x = 0.015;
                    y = 0.035;
                    w = 1;
                    h = 0.15;
                    text = "Interaction: F";
                };
                class LeverNext: InteractionText
                {
                    idc = 2;
                    y = 0.055;
                    text = "Lever next: mousewheel up";
                };
                class LeverPrev: InteractionText
                {
                    idc = 3;
                    y = 0.075;
                    text = "Lever previous: mousewheel down";
                };
                class FDStby: InteractionText
                {
                    idc = 4;
                    y = 0.095;
                    text = "Flight Director Standby: Control + Tab";
                };
        		class RTDWarning: vtx_centerText
        		{
        			idc = 5;
        			x = 0;
        			y = 0;
        			w = safeZoneW;
                    h = 0.08;
                    size = 0.15;
                    colorText[] = {1,0,0,1};
        			text = "Please enable Advanced Flight Model(AFM) for full functionality";
        		};
        		class RTDSimple2: RTDWarning
        		{
        			idc = 6;
        			x = 0;
        			y = 0.05;
        			w = safeZoneW;
        			text = "Consider enabling the simple collective option in CBA to allow for simple AFM flying with keyboard & mouse";
        		};

                #define ENGSTARTW 0.5
                #define ENGSTARTH 0.25
                class EngineStartBackground: IGUIBack
                {
                        idc = 7;
                    	x = safeZoneW - ENGSTARTW;
                    	y = 0;
                    	w = ENGSTARTW;
                    	h = 0.2;
                        colorBackground[] = {0,0,0,0.75};
                };

                class EngineStart1: RscIGText
                {
                    idc = 8;
                    x = safeZoneW - ENGSTARTW + 0.015;
                    y = 0.01;
                    w = ENGSTARTW - 0.015;
                    h = 0.05;
                    text = "To start your engine";
                };
                class EngineStart2: EngineStart1
                {
                    idc = 9;
                    y = 0.04;
                    text = "Turn on your batteries on the ceiling panel(upper console)";
                };
                class EngineStart3: EngineStart1
                {
                    idc = 10;
                    y = 0.07;
                    text = "Continue with the startup checklist on your FMS computer";
                };
                class EngineStart4: EngineStart1
                {
                    idc = 11;
                    y = 0.10;
                    text = "The FMS can be found by your knee";
                };
                class EngineStart5: EngineStart1
                {
                    idc = 12;
                    y = 0.13;
                    text = "Full manual at http://uh-60m.gitbook.io";
                };
            };
        };

        class HelpOverlayGunner: RscControlsGroup {
			idc = 4001122;
            x = safezoneX;
            y = safezoneY;
            w = safezoneW;
            h = safezoneH;
            class Controls {
            class GunBackground: IGUIBack
            {
                    idc = 7;
                    x = safeZoneW - ENGSTARTW;
                    y = 0;
                    w = ENGSTARTW;
                    h = 0.2;
                    colorBackground[] = {0,0,0,0.75};
            };
                class GunStart1: RscIGText
                {
                    idc = 13;
                    x = safeZoneW - ENGSTARTW + 0.015;
                    y = 0.01;
                    w = ENGSTARTW - 0.015;
                    h = 0.05;
                    text = "To enable your doorgun:";
                };
                class GunStart2: GunStart1
                {
                    idc = 14;
                    y = 0.04;
                    text = "1. Flip the red safety cover between your hands";
                };
                class GunStart3: GunStart1
                {
                    idc = 15;
                    y = 0.07;
                    text = "1. Turn the power switch under the safety cover on";
                };
                class GunStart4: GunStart1
                {
                    idc = 16;
                    y = 0.10;
                    text = "You can check your ammo by interacting with the ammo box besides you";
                };
            };
        };
    };
};
