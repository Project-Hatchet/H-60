class vtx_uh60_jvmf_inboxDialog {
    idd = 20001;
    movingEnable = true;
    onLoad = "_this call vtx_uh60_jvmf_fnc_prepareInboxDialog;";
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
		class backgroundPicture: RscPicture {
			idc = 999;
			text = "z\vtx\addons\uh60_jvmf\data\screen2.paa";
        	x = 0.350562 * safezoneW + safezoneX;
        	y = 0.065 * safezoneH + safezoneY;
        	w = 0.305187 * safezoneW;
        	h = 0.800 * safezoneH;
		};
        class RscText_1001: RscText
        {
        	idc = 1001;
        	text = "NEW MSG"; //--- ToDo: Localize;
        	x = 0.47875 * safezoneW + safezoneX;
        	y = 0.235 * safezoneH + safezoneY;
        	w = 0.825 * safezoneW;
        	h = 0.022 * safezoneH;
        };
        class RscButton_1602: RscButton
        {
        	idc = 1602;
        	text = "FREETEXT"; //--- ToDo: Localize;
        	x = 0.456875 * safezoneW + safezoneX;
        	y = 0.255 * safezoneH + safezoneY;
        	w = 0.04125 * safezoneW;
        	h = 0.022 * safezoneH;
            onButtonClick="closeDialog 2;createDialog ""vtx_uh60_jvmf_writeDialog"";";
        };
        class RscButton_1603: RscButton
        {
        	idc = 1603;
        	text = "POSREP"; //--- ToDo: Localize;
        	x = 0.50 * safezoneW + safezoneX;
        	y = 0.255 * safezoneH + safezoneY;
        	w = 0.04125 * safezoneW;
        	h = 0.022 * safezoneH;
            onButtonClick="closeDialog 2;createDialog ""vtx_uh60_jvmf_positionDialog"";";
        };
        class RscButton_1604: RscButton
        {
        	idc = 1604;
        	text = "JVMF INBOX"; //--- ToDo: Localize;
        	x = 0.4 * safezoneW + safezoneX;
        	y = 0.235 * safezoneH + safezoneY;
        	w = 0.054 * safezoneW;
        	h = 0.044 * safezoneH;
            onButtonClick="";
        };
		class RscListBox1: RscListBox
		{
			font = "EtelkaMonospacePro";
        	idc = 1337;
        	x = 0.396875 * safezoneW + safezoneX;
        	y = 0.29 * safezoneH + safezoneY;
        	w = 0.215 * safezoneW;
        	h = 0.38 * safezoneH;
		};
        class RscButton_1600: RscButton
        {
        	idc = 1600;
        	text = "Open"; //--- ToDo: Localize;
        	x = 0.572187 * safezoneW + safezoneX;
        	y = 0.67 * safezoneH + safezoneY;
        	w = 0.04125 * safezoneW;
        	h = 0.022 * safezoneH;
            onButtonClick="_this spawn vtx_uh60_jvmf_fnc_openMessage";
        };
    };
};
