class MELB_GUI: RscControlsGroup
{
    idc = 170;
    class VScrollbar: VScrollbar
    {
        width = 0;
    };
    class HScrollbar: HScrollbar
    {
        height = 0;
    };
    x = "0 *     (0.01875 * SafezoneH) +     (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
    y = "0 *     (0.025 * SafezoneH) +     (SafezoneY)";
    w = "53.5 *     (0.01875 * SafezoneH)";
    h = "40 *     (0.025 * SafezoneH)";
    class controls
    {
        class TextDistance: RangeText
        {
            idc = 1010;
            text = "RNG";
            font = "PuristaMedium";
            sizeEx = "0.0255*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "41.8 *     (0.01875 * SafezoneH)";
            y = "4.8 *     (0.025 * SafezoneH)";
            w = "3*     (0.01875 * SafezoneH)";
            h = "1.2 *     (0.025 * SafezoneH)";
        };
        class CA_Distance: RscText
        {
            idc = 151;
            sizeEx = "0.0295*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            font = "PuristaMedium";
            x = "46 *     (0.01875 * SafezoneH)";
            y = "4.8 *     (0.025 * SafezoneH)";
            w = "4 *     (0.01875 * SafezoneH)";
            h = "1.2 *     (0.025 * SafezoneH)";
        };
        class TextSpeed: RangeText
        {
            idc = 1010;
            text = "SPD";
            font = "PuristaMedium";
            sizeEx = "0.0255*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "2.5 *     (0.01875 * SafezoneH)";
            y = "4.8 *     (0.025 * SafezoneH)";
            w = "8 *     (0.01875 * SafezoneH)";
            h = "1.2 *     (0.025 * SafezoneH)";
        };
        class CA_Speed: RangeText
        {
            idc = 188;
            sizeEx = "0.0295*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            font = "PuristaMedium";
            text = "120";
            x = "8 *     (0.01875 * SafezoneH)";
            y = "4.8 *     (0.025 * SafezoneH)";
            w = "4 *     (0.01875 * SafezoneH)";
            h = "1.2 *     (0.025 * SafezoneH)";
        };
        class TextAlt: RangeText
        {
            idc = 1010;
            text = "ALT";
            font = "PuristaMedium";
            sizeEx = "0.0255*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "2.5 *     (0.01875 * SafezoneH)";
            y = "5.6 *     (0.025 * SafezoneH)";
            w = "8 *     (0.01875 * SafezoneH)";
            h = "1.2 *     (0.025 * SafezoneH)";
        };
        class CA_Alt: RangeText
        {
            idc = 189;
            sizeEx = "0.0295*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            font = "PuristaMedium";
            text = "3825";
            x = "8 *     (0.01875 * SafezoneH)";
            y = "5.6 *     (0.025 * SafezoneH)";
            w = "4 *     (0.01875 * SafezoneH)";
            h = "1.2 *     (0.025 * SafezoneH)";
        };
        class CA_VisionMode: RscText
        {
            idc = 152;
            sizeEx = "0.022*SafezoneH";
            colorText[] = {0,0,0,1};
            colorBackground[] = {1,1,1,1};
            shadow = 0;
            font = "PuristaMedium";
            text = "VIS";
            x = "25.75 *     (0.01875 * SafezoneH)";
            y = "7.25 *     (0.025 * SafezoneH)";
            w = "1.5 *     (0.01875 * SafezoneH)";
            h = "0.6 *     (0.025 * SafezoneH)";
        };
        class CA_FlirMode: RscText
        {
            idc = 153;
            sizeEx = "0.022*SafezoneH";
            shadow = 2;
            colorText[] = {1,1,1,1};
            font = "PuristaMedium";
            text = "BHOT";
            x = "25.5*     (0.01875 * SafezoneH)";
            y = "7.75 *     (0.025 * SafezoneH)";
            w = "2*     (0.01875 * SafezoneH)";
            h = "0.8 *     (0.025 * SafezoneH)";
        };
        class TextACPOS: RangeText
        {
            idc = 1010;
            text = "CRAFT POS";
            font = "PuristaMedium";
            sizeEx = "0.0255*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "2.5 *     (0.01875 * SafezoneH)";
            y = "3 *     (0.025 * SafezoneH)";
            w = "8 *     (0.01875 * SafezoneH)";
            h = "1.2 *     (0.025 * SafezoneH)";
        };
        class ValueACPOS: RangeText
        {
            idc = 171;
            font = "PuristaMedium";
            sizeEx = "0.0295*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "2.5 *     (0.01875 * SafezoneH)";
            y = "4 *     (0.025 * SafezoneH)";
            w = "6 *     (0.01875 * SafezoneH)";
            h = "1 *     (0.025 * SafezoneH)";
        };
        class TextTPOS: RangeText
        {
            idc = 1010;
            text = "TARGET POS";
            font = "PuristaMedium";
            sizeEx = "0.0255*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "41.8*     (0.01875 * SafezoneH)";
            y = "3 *     (0.025 * SafezoneH)";
            w = "8 *     (0.01875 * SafezoneH)";
            h = "1.2 *     (0.025 * SafezoneH)";
        };
        class ValueTPOS: RangeText
        {
            idc = 172;
            font = "PuristaMedium";
            sizeEx = "0.0295*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "41.8*     (0.01875 * SafezoneH)";
            y = "4 *     (0.025 * SafezoneH)";
            w = "6 *     (0.01875 * SafezoneH)";
            h = "1 *     (0.025 * SafezoneH)";
        };
        class ValueTime: RangeText
        {
            idc = 190;
            text = "20:28:35";
            font = "PuristaMedium";
            sizeEx = "0.0295*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "2.5*     (0.01875 * SafezoneH)";
            y = "9 *     (0.025 * SafezoneH)";
            w = "6 *     (0.01875 * SafezoneH)";
            h = "1 *     (0.025 * SafezoneH)";
        };
        class TextLaser: RangeText
        {
            idc = 158;
            text = "LRF        ARMED";
            font = "PuristaMedium";
            sizeEx = "0.0255*SafezoneH";
            colorText[] = {0.9,0,0,1};
            shadow = 2;
            x = "3*     (0.01875 * SafezoneH)";
            y = "14.1 *     (0.025 * SafezoneH)";
            w = "13 *     (0.01875 * SafezoneH)";
            h = "2 *     (0.025 * SafezoneH)";
        };
        class CA_Heading: RscText
        {
            idc = 156;
            sizeEx = "0.0255*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            font = "PuristaMedium";
            text = "023";
            x = "27.25*     (0.01875 * SafezoneH)";
            y = "5 *     (0.025 * SafezoneH)";
            w = "4 *     (0.01875 * SafezoneH)";
            h = "1.2 *     (0.025 * SafezoneH)";
        };
        class TextHDG: RangeText
        {
            idc = 1010;
            text = "HDG";
            font = "PuristaMedium";
            sizeEx = "0.0255*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "24*     (0.01875 * SafezoneH)";
            y = "5*     (0.025 * SafezoneH)";
            w = "4 *     (0.01875 * SafezoneH)";
            h = "1.2 *     (0.025 * SafezoneH)";
        };
        class OpticsZoom1: RangeText
        {
            idc = 180;
            text = "28x";
            colorText[] = {1,1,1,1};
            font = "PuristaMedium";
            sizeEx = "0.0255*SafezoneH";
            shadow = 2;
            x = "5 *     (0.01875 * SafezoneH)";
            y = "25 *     (0.025 * SafezoneH)";
            w = "6 *     (0.01875 * SafezoneH)";
            h = "1 *     (0.025 * SafezoneH)";
        };
        class TextZOOM: RangeText
        {
            idc = 1010;
            text = "ZOOM";
            font = "PuristaMedium";
            sizeEx = "0.0255*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "2.5 *     (0.01875 * SafezoneH)";
            y = "25 *     (0.025 * SafezoneH)";
            w = "4 *     (0.01875 * SafezoneH)";
            h = "1 *     (0.025 * SafezoneH)";
        };
        class ValueGEOLOCK: RscText
        {
            idc = 154;
            text = "TRK COR";
            font = "PuristaMedium";
            sizeEx = "0.0255*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "42*     (0.01875 * SafezoneH)";
            y = "33 *     (0.025 * SafezoneH)";
            w = "8 *     (0.01875 * SafezoneH)";
            h = "1 *     (0.025 * SafezoneH)";
        };
        class TextGEOLOCK: RangeText
        {
            idc = 155;
            text = "GEOLOCK";
            font = "PuristaMedium";
            sizeEx = "0.0255*SafezoneH";
            colorText[] = {1,1,1,1};
            shadow = 2;
            x = "42*     (0.01875 * SafezoneH)";
            y = "32 *     (0.025 * SafezoneH)";
            w = "8 *     (0.01875 * SafezoneH)";
            h = "1.2 *     (0.025 * SafezoneH)";
        };
    };
};
