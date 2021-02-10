class torqueWrapper {
	condition = "simulRTD";
	color[] = common_blue;
    TEXT_HMD_L(TORQUE_LBL,0.015,0.82)
        source = "static";
        sourceIndex = 1;
        sourceScale = 1;
        text = "Q";
	}; // TORQUE_LBL
    TEXT_HMD_L(TORQUE_VAL,0.065,0.82)
        source = "rtdRotorTorque";
        sourceIndex = 1;
        sourceScale = 2270;
        text = "";
    }; // TORQUE_VAL

	#define COLLECTIVE_X 0.9
	#define COLLECTIVE_OFFSET 0.05
	BAR(COLLECTIVEBAR,"rtdCollectiveBar",COLLECTIVE_X-COLLECTIVE_OFFSET,0.8,0.01)
	class greenWrap {
		color[] = common_green;
		LINE(COLLECTIVE_BOTTOM,8,COLLECTIVE_X-0.05-0.03-COLLECTIVE_OFFSET,0.8,COLLECTIVE_X+0.03-COLLECTIVE_OFFSET,0.8)

		LINE(COLLECTIVE_MIDDLE_L,8,COLLECTIVE_X-0.03-COLLECTIVE_OFFSET,0.68,COLLECTIVE_X-0.01-COLLECTIVE_OFFSET,0.68)
		LINE(COLLECTIVE_MIDDLE_R,8,COLLECTIVE_X+0.01-COLLECTIVE_OFFSET,0.68,COLLECTIVE_X+0.03-COLLECTIVE_OFFSET,0.68)

		LINE(COLLECTIVE_TOP,8,COLLECTIVE_X-0.05-0.03-COLLECTIVE_OFFSET,0.57,COLLECTIVE_X+0.03-COLLECTIVE_OFFSET,0.57)
	};
    TEXT_HMD_L(C_LBL,0.815,0.82)
        source = "static";
        sourceIndex = 1;
        sourceScale = 1;
        text = "C";
	}; // TORQUE_LBL
    TEXT_HMD_L(C_VAL,0.865,0.82)
        source = "rtdCollective";
        sourceIndex = 1;
        sourceScale = 100;
        text = "";
    }; // TORQUE_VAL
};

class blueWrapper {
color[] = common_blue;
	LINE(VSI_MIDDLE_L,8,COLLECTIVE_X-0.05-0.03-COLLECTIVE_OFFSET,0.68,COLLECTIVE_X-0.05-0.01-COLLECTIVE_OFFSET,0.68)
	LINE(VSI_MIDDLE_R,8,COLLECTIVE_X-0.05+0.01-COLLECTIVE_OFFSET,0.68,COLLECTIVE_X-0.05+0.03-COLLECTIVE_OFFSET,0.68)
	BAR(VSIBar,"VSIBar",COLLECTIVE_X-0.05-COLLECTIVE_OFFSET,0.685,0.01)
	TEXT_HMD_R(VSI_LBL,0.78,0.71)
		source = "static";
		sourceIndex = 1;
		sourceScale = 1;
		text = "VS";
	}; // TORQUE_LBL
	TEXT_HMD_R(VSI_VAL,0.78,0.742)
		sourceScale = 196.85;
		source="vspeed";
		sourceIndex = 1;
		text = "";
	}; // TORQUE_VAL

	TEXT_HMD_R(KTS_VAL,0.085,0.2)
		source = "speed";
		sourceIndex = 1;
		sourceScale = 1.94384;
		text = "";
	}; // TORQUE_VAL
	TEXT_HMD_R(KTS_LBL,0.085,0.232)
		source = "static";
		sourceIndex = 1;
		sourceScale = 1;
		text = "KTS";
	}; // TORQUE_LBL

	class KTS_Outline {
		type="line";
		width = 3;
		points[] ={
			{{0.01, 0.2}, 1},
			{{0.1, 0.2}, 1},
			{{0.1, 0.27}, 1},
			{{0.01, 0.27}, 1},
			{{0.01, 0.2}, 1}
		}; // points
	}; // WP_Point_Square
}; // blueWrapper
