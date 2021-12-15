class torqueWrapper {
	condition = "1";
	color[] = {0.082,0.608,0.039,1};
	#define COLLECTIVE_X 0.95
	#define COLLECTIVE_OFFSET 0.05
	class DCLT_HIDE {
		condition=COND_FULL_ONLY;
		class IS_RTD {
			condition="simulRTD";
			TEXT_HMD_L(TORQUE_LBL,0.015,0.81)
				source = "static";
				sourceIndex = 1;
				sourceScale = 1;
				text = "Q";
			}; // TORQUE_LBL
			TEXT_HMD_L(TORQUE_VAL,0.065,0.81)
				source = "rtdRotorTorque";
				sourceIndex = 1;
				sourceScale = 2270;
				text = "";
			}; // TORQUE_VAL

			TEXT_HMD_L(C_LBL,0.015,0.81+SMALL_LINEHEIGHT)
				source = "static";
				sourceIndex = 1;
				sourceScale = 1;
				text = "C";
			}; // TORQUE_LBL
			TEXT_HMD_L(C_VAL,0.065,0.81+SMALL_LINEHEIGHT)
				source = "rtdCollective";
				sourceIndex = 1;
				sourceScale = 100;
				text = "";
			}; // TORQUE_VAL
		};
		class ACOL_ON {
			condition="collisionlights";
			TEXT_HMD_L(TEXT,0.015,0.81-SMALL_LINEHEIGHT)
				source = "static";
				sourceIndex = 1;
				sourceScale = 1;
				text = "A-COL";
			}; // TEXT
		};
		class LIGHTS_ON {
			condition="lights";
			TEXT_HMD_L(TEXT,0.015,0.81-(SMALL_LINEHEIGHT*2))
				source = "static";
				sourceIndex = 1;
				sourceScale = 1;
				text = "LIGHTS";
			}; // TEXT
		};
		class AUTOHOVER_ON {
			condition="autohover";
			blinkingPattern[] = {0.5,0.5};
			TEXT_HMD_L(TEXT,0.015,0.81-(SMALL_LINEHEIGHT*3))
				source = "static";
				sourceIndex = 1;
				sourceScale = 1;
				text = "AUTO HOVER";
			}; // TEXT
		};
	};


	
	class VSI_POLY
	{
		type="polygon";
		points[]=
		{
			{
				{"VSIBar",{-0.01, -0.01},1},
				{"VSIBar",{ 0.01,  0},1},
				{"VSIBar",{-0.01,  0.01},1}
			}
		};
	};
  class VSI_Bracket
  {
    type="line";
    width=4;
    points[]=
    {
      {{0.85,0.55},1},
      {{0.87,0.55},1},
      {{0.87,0.75},1},
      {{0.85,0.75},1},
      {},
      {{0.85,0.65},1},
      {{0.87,0.65},1}
    };
  };

	class METRIC {
		condition = COND_METRIC;
		TEXT_HMD_R(KTS_VAL,0.085,0.41)
			source = "speed";
			sourceIndex = 1;
			sourceScale = 3.6;
			text = "";
		}; // TORQUE_VAL
		TEXT_HMD_R(KTS_LBL,0.085,0.41 + 0.032)
			source = "static";
			sourceIndex = 1;
			sourceScale = 1;
			text = "KMH";
		}; // TORQUE_LBL
		
		TEXT_HMD_R(MSL_ALT_VAL,0.94,0.41)
			source = "altitudeASL";
			sourceIndex = 1;
			sourceScale = 1;
			text = "";
		}; // TORQUE_VAL
		TEXT_HMD_R(MSL_ALT_LBL,0.94,0.41 + 0.032)
			source = "static";
			sourceIndex = 1;
			sourceScale = 1;
			text = "MSL";
		}; // TORQUE_LBL
	};
	class IMPERIAL {
		condition = COND_IMPERIAL;
		TEXT_HMD_R(KTS_VAL,0.085,0.41)
			source = "speed";
			sourceIndex = 1;
			sourceScale = 1.94384;
			text = "";
		}; // TORQUE_VAL
		TEXT_HMD_R(KTS_LBL,0.085,0.41 + 0.032)
			source = "static";
			sourceIndex = 1;
			sourceScale = 1;
			text = "KTS";
		}; // TORQUE_LBL
		
		TEXT_HMD_R(MSL_ALT_VAL,0.94,0.41)
			source = "altitudeASL";
			sourceIndex = 1;
			sourceScale = 3.28;
			text = "";
		}; // TORQUE_VAL
		TEXT_HMD_R(MSL_ALT_LBL,0.94,0.41 + 0.032)
			source = "static";
			sourceIndex = 1;
			sourceScale = 1;
			text = "MSL";
		}; // TORQUE_LBL
	};

	class KTS_Outline {
		type="line";
		width = 3;
		points[] ={
			{{0.01, 0.41 + 0.0}, 1},
			{{0.1,  0.41 + 0.0}, 1},
			{{0.1,  0.41 + 0.07}, 1},
			{{0.01, 0.41 + 0.07}, 1},
			{{0.01, 0.41 + 0.0}, 1}
		}; // points
	}; // KTS_Outline
	class MSL_Outline {
		type="line";
		width = 3;
		points[] ={
			{{0.86 + 0.01, 0.41 + 0.0}, 1},
			{{0.86 + 0.1,  0.41 + 0.0}, 1},
			{{0.86 + 0.1,  0.41 + 0.07}, 1},
			{{0.86 + 0.01, 0.41 + 0.07}, 1},
			{{0.86 + 0.01, 0.41 + 0.0}, 1}
		}; // points
	}; // KTS_Outline
};