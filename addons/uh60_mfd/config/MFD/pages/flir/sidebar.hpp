class sidebar {
	COLORED_POLYGON(PB1,0.85,0.1,0.12,0.1,common_black)
	COLORED_POLYGON(EngagementBG,0.85,0.28,0.15,0.21,common_black)
	class white {
		color[] = common_white;
		TEXT_RIGHT_SCALED_SRC(DATE,0.95,0.1,0.04)
				source="time";
				text="%x";
				sourceScale = 1;
		}; // DATE
		TEXT_RIGHT_SCALED_SRC(TIME,0.95,0.15,0.04)
				source="time";
				text="%X";
				sourceScale = 1;
		}; // TIME

		TEXT_RIGHT_SCALED_SRC(WPN_PARAMS_1,0.95,0.3,0.04)
			source="static";
			text="MODE[DIR]";
			sourceScale = 1;
		};
		TEXT_RIGHT_SCALED_SRC(WPN_PARAMS_2,0.95,0.35,0.04)
			source="static";
			text="NEXT MSL";
			sourceScale = 1;
		};
		TEXT_RIGHT_SCALED_SRC(WPN_PARAMS_6,0.95,0.40,0.04)
			source="static";
			text="DES[AUT]:A";
			sourceScale = 1;
		};
		TEXT_RIGHT_SCALED_SRC(WPN_PARAMS_7,0.95,0.45,0.04)
			source="static";
			text="TRK[ PNT ]";
			sourceScale = 1;
		};
		TEXT_RIGHT_SCALED_SRC(WPN_PARAMS_8,0.95,0.55,0.04)
			source="static";
			text="WPN ARM";
			sourceScale = 1;
		};

		TEXT_RIGHT_SCALED_SRC(LASERDIST,0.95,0.9,0.04)
				source="targetDist";
				sourceScale = 1;
		}; // LASERDIST
		TEXT_LEFT_SCALED(B7,(BEZEL_XB5-0.02+0.005),BOTTOM_TEXT_Y,"TAC",TAC_LINE_HEIGHT)
		TEXT_LEFT_SCALED(B8,(BEZEL_XB6-0.03+0.005),BOTTOM_TEXT_Y,"JVMF",TAC_LINE_HEIGHT)
	};
    class MissileSelected {
        condition = "missile";
        class LOBL {
            type="line";
            width = 2;
            points[] ={
                {"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1},
                {"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0+0.025},1},
                {"FLIR_HELLFIRE_REF", {00.025*(3/4), 0+0.025},1},
                {"FLIR_HELLFIRE_REF", {00.025*(3/4), 0-0.025},1},
                {"FLIR_HELLFIRE_REF", {-0.025*(3/4), 0-0.025},1}
            };
        };
    }; // MissileSelected
};