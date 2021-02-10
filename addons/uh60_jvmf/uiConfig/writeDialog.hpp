class vtx_uh60_jvmf_writeDialog {
    idd = 20001;
    movingEnable = true;
    onLoad = "";
    class Controls {
        class IGUIBack_2200: IGUIBack
        {
        	idc = 2200;
        	x = 0.386562 * safezoneW + safezoneX;
        	y = 0.225 * safezoneH + safezoneY;
        	w = 0.237187 * safezoneW;
        	h = 0.484 * safezoneH;
            colorBackground[] = {0.1,0.1,0.1,1};
        };
        class RscText_1000: RscText
        {
        	idc = 1000;
        	text = "New JVMF Message"; //--- ToDo: Localize;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.247 * safezoneH + safezoneY;
        	w = 0.0773437 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscListbox_1500: RscText
        {
        	idc = 1500;
        	text = "Freetext"; //--- ToDo: Localize;
        	x = 0.474219 * safezoneW + safezoneX;
        	y = 0.269 * safezoneH + safezoneY;
        	w = 0.0825 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscText_1001: RscText
        {
        	idc = 1001;
        	text = "Message type"; //--- ToDo: Localize;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.269 * safezoneH + safezoneY;
        	w = 0.0773437 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscText_1002: RscText
        {
        	idc = 1002;
        	text = "TARGET:"; //--- ToDo: Localize;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.313 * safezoneH + safezoneY;
        	w = 0.04125 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscEdit_1400: RscEdit
        {
        	idc = 1400;
        	x = 0.438125 * safezoneW + safezoneX;
        	y = 0.313 * safezoneH + safezoneY;
        	w = 0.0721875 * safezoneW;
        	h = 0.022 * safezoneH;
            onKeyUp="(_this select 0) ctrlSetText ((ctrlText (_this select 0)) select [0,18])";
        };
        class RscText_1003: RscText
        {
        	idc = 1003;
        	text = "Content:"; //--- ToDo: Localize;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.379 * safezoneH + safezoneY;
        	w = 0.0464063 * safezoneW;
        	h = 0.022 * safezoneH;
            onKeyUp="(_this select 0) ctrlSetText ((ctrlText (_this select 0)) select [0,18])";
        };
        class RscText_1004: RscText
        {
        	idc = 1004;
        	text = "MSG ID:"; //--- ToDo: Localize;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.335 * safezoneH + safezoneY;
        	w = 0.04125 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscEdit_1401: RscEdit
        {
        	idc = 1401;
        	x = 0.438125 * safezoneW + safezoneX;
        	y = 0.335 * safezoneH + safezoneY;
        	w = 0.0721875 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscText_1005: RscText
        {
        	idc = 1005;
        	text = "Every line has a character limit of 50"; //--- ToDo: Localize;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.401 * safezoneH + safezoneY;
        	w = 0.128906 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class ContentText: RscEdit
        {
        	idc = 1402;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.423 * safezoneH + safezoneY;
        	w = 0.216563 * safezoneW;
        	h = 0.022 * safezoneH;
            onKeyUp="(_this select 0) ctrlSetText ((ctrlText (_this select 0)) select [0,60])";
        };
        class RscEdit_1403: ContentText
        {
        	idc = 1403;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.445 * safezoneH + safezoneY;
        	w = 0.216563 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscEdit_1404: ContentText
        {
        	idc = 1404;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.467 * safezoneH + safezoneY;
        	w = 0.216563 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscEdit_1405: ContentText
        {
        	idc = 1405;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.489 * safezoneH + safezoneY;
        	w = 0.216563 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscEdit_1406: ContentText
        {
        	idc = 1406;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.511 * safezoneH + safezoneY;
        	w = 0.216563 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscEdit_1407: ContentText
        {
        	idc = 1407;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.533 * safezoneH + safezoneY;
        	w = 0.216563 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscEdit_1408: ContentText
        {
        	idc = 1408;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.555 * safezoneH + safezoneY;
        	w = 0.216563 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscEdit_1409: ContentText
        {
        	idc = 1409;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.577 * safezoneH + safezoneY;
        	w = 0.216563 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscEdit_1410: ContentText
        {
        	idc = 1410;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.599 * safezoneH + safezoneY;
        	w = 0.216563 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscEdit_1411: ContentText
        {
        	idc = 1411;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.621 * safezoneH + safezoneY;
        	w = 0.216563 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscButton_1600: RscButton
        {
        	idc = 1600;
        	text = "Send"; //--- ToDo: Localize;
        	x = 0.572187 * safezoneW + safezoneX;
        	y = 0.665 * safezoneH + safezoneY;
        	w = 0.04125 * safezoneW;
        	h = 0.022 * safezoneH;
            onButtonClick="_this call vtx_uh60_jvmf_fnc_submitFreetext";
        };
        class RscButton_1601: RscButton
        {
        	idc = 1601;
        	text = "Cancel"; //--- ToDo: Localize;
        	x = 0.520625 * safezoneW + safezoneX;
        	y = 0.665 * safezoneH + safezoneY;
        	w = 0.04125 * safezoneW;
        	h = 0.022 * safezoneH;
            onButtonClick="closeDialog 2";
        };
    };
};
