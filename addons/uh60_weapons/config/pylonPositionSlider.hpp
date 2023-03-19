class RscSlider;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class GVAR(pylonPosition) {
    idd = 7777;
    onUnload = "missionNamespace setVariable ['vtx_uh60_weapons_pylonPositionParams', []]";
    class controls {
        class GVAR(pylonPosition_Slider): RscSlider
        {
          idc = 1900;
          text = "Pylon Position"; //--- ToDo: Localize;
          x = 0.296875 * safezoneW + safezoneX;
          y = 0.4375 * safezoneH + safezoneY;
          w = 0.41025 * safezoneW;
          h = 0.055 * safezoneH;
          sliderPosition = 0;
          sliderRange[] = {PYLON_POS_MIN, PYLON_POS_MAX};
          sliderStep = 0.001;
        };
        class GVAR(pylonPosition_ok): RscButtonMenuOK
        {
          x = 0.296875 * safezoneW + safezoneX;
          y = 0.510417 * safezoneH + safezoneY;
          w = 0.2 * safezoneW;
          h = 0.055 * safezoneH;
          text = "OK";
          action = "";
        };
        class GVAR(pylonPosition_reset): RscButtonMenuCancel
        {
          x = 0.5 * safezoneW + safezoneX;
          y = 0.510417 * safezoneH + safezoneY;
          w = 0.2 * safezoneW;
          h = 0.055 * safezoneH;
          text = "Reset";
          action = "(missionNamespace getVariable 'vtx_uh60_weapons_pylonPositionParams') params ['_v', '_a']; _v animateSource [_a, 0, true];";
        };
    };
};
