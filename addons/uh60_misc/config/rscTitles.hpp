//Developer panel - HeliSim state, and the automatic engine start while it runs.
//Shown on its own layer by vtx_uh60_misc_fnc_devPanel; nothing else draws here.
class RscTitles {
    class vtx_uh60_misc_devOverlay {
        idd = 86010;
        movingEnable = 0;
        duration = 1e9;
        fadein = 0;
        fadeout = 0;
        onLoad = "uiNamespace setVariable ['vtx_uh60_misc_devOverlay', _this select 0];";
        class controls {
            //Two columns: state (and the automatic start) on the left, HeliSim's settings on the
            //right. fnc_devPanel sizes each to its text.
            class Left: RscStructuredText {
                idc = 1000;
                x = "safeZoneX + 0.555 * safeZoneW";
                y = "safeZoneY + 0.08 * safeZoneH";
                w = "0.215 * safeZoneW";
                h = "0.5 * safeZoneH";
                size = "0.03 * safeZoneH";
                colorBackground[] = {0, 0, 0, 0.65};
                text = "";
            };
            class Right: Left {
                idc = 1001;
                x = "safeZoneX + 0.775 * safeZoneW";
            };
        };
    };
};
