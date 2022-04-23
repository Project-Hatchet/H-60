#define ICON_SCALE 1
#define BFT_ICON_W 1
#define BFT_ICON_H (BFT_ICON_W * 0.75)

#define BACKGROUND_RECTANGLE \
    class BlackOverlay { \
        color[] = {0.05,0.05,0.05,0.5}; \
		alpha = 0.9; \
        class BlackPoly \
        { \
            type = "polygon"; \
            width = 2; \
            points[] = { \
                { \
                    {{1.2*BFT_ICON_W*-0.02, 1.2*BFT_ICON_H*0.02}, 1}, \
                    {{1.2*BFT_ICON_W*0.02,  1.2*BFT_ICON_H*0.02}, 1}, \
                    {{1.2*BFT_ICON_W*0.02,  1.2*BFT_ICON_H*-0.02}, 1}, \
                    {{1.2*BFT_ICON_W*-0.02, 1.2*BFT_ICON_H*-0.02}, 1} \
                } \
            }; \
        };



#define BOX_CONTENT_START(COLOR) \
    class Blue { \
        color[] = COLOR; \
		alpha = 1; \
        class Line \
        { \
            type = "line"; \
            width = 2; \
            points[] = { \
				{{1.0*BFT_ICON_W*-0.02, 1.0*BFT_ICON_H*0.02}, 1}, \
				{{1.0*BFT_ICON_W*0.02,  1.0*BFT_ICON_H*0.02}, 1}, \
				{{1.0*BFT_ICON_W*0.02,  1.0*BFT_ICON_H*-0.02}, 1}, \
				{{1.0*BFT_ICON_W*-0.02, 1.0*BFT_ICON_H*-0.02}, 1}, \
				{{1.0*BFT_ICON_W*-0.02, 1.0*BFT_ICON_H*0.02}, 1},{},

#define BOX_CONTENT_END \
            }; \
        }; \
	};


#define RECTANGLE_POINTS \
	{{BFT_ICON_W*-0.02, BFT_ICON_H*0.02}, 1}, \
	{{BFT_ICON_W*0.02,  BFT_ICON_H*0.02}, 1}, \
	{{BFT_ICON_W*0.02,  BFT_ICON_H*-0.02}, 1}, \
	{{BFT_ICON_W*-0.02, BFT_ICON_H*-0.02}, 1} \

#define AIRCRAFT_POINTS \
	{{0.6*BFT_ICON_W*-0.02, 0.6*BFT_ICON_H*-0.02}, 1}, \
	{{0.6*BFT_ICON_W* 0.02, 0.6*BFT_ICON_H* 0.02}, 1}, \
	{{0.6*BFT_ICON_W* 0.02, 0.6*BFT_ICON_H*-0.02}, 1}, \
	{{0.6*BFT_ICON_W*-0.02, 0.6*BFT_ICON_H* 0.02}, 1}, \
	{{0.6*BFT_ICON_W*-0.02, 0.6*BFT_ICON_H*-0.02}, 1}

#define INFANTRY_POINTS \
	{{BFT_ICON_W*-0.02, BFT_ICON_H*-0.02}, 1}, \
	{{BFT_ICON_W* 0.02, BFT_ICON_H* 0.02}, 1},{}, \
	{{BFT_ICON_W* 0.02, BFT_ICON_H*-0.02}, 1}, \
	{{BFT_ICON_W*-0.02, BFT_ICON_H* 0.02}, 1}

#define AMORED_POINTS \
   {BFT_ANGLE(0,0.013), 1}, \
  {BFT_ANGLE(30,0.013), 1}, \
  {BFT_ANGLE(60,0.013), 1}, \
  {BFT_ANGLE(90,0.013), 1}, \
 {BFT_ANGLE(120,0.013), 1}, \
 {BFT_ANGLE(150,0.013), 1}, \
 {BFT_ANGLE(180,0.013), 1}, \
 {BFT_ANGLE(210,0.013), 1}, \
 {BFT_ANGLE(240,0.013), 1}, \
 {BFT_ANGLE(270,0.013), 1}, \
 {BFT_ANGLE(300,0.013), 1}, \
 {BFT_ANGLE(330,0.013), 1}, \
   {BFT_ANGLE(0,0.013), 1}

#define ARMORED(COLOR) \
	BACKGROUND_RECTANGLE \
		BOX_CONTENT_START(COLOR) \
			AMORED_POINTS \
		BOX_CONTENT_END \
	};

#define AIRCAFT(COLOR) \
	BACKGROUND_RECTANGLE \
		BOX_CONTENT_START(COLOR) \
			AIRCRAFT_POINTS \
		BOX_CONTENT_END \
	};

#define UNKNOWN(COLOR) \
	BACKGROUND_RECTANGLE \
		BOX_CONTENT_START(COLOR) \
		BOX_CONTENT_END \
	};

#define INFANTRY(COLOR) \
	BACKGROUND_RECTANGLE \
		BOX_CONTENT_START(COLOR) \
			INFANTRY_POINTS \
		BOX_CONTENT_END \
		TEXT_MID_SCALED(MYTEXT,0,-0.025,"",0.05) \
	};

#define TEST_BOX(COLOR,TEXT) \
	class BlackOverlay {\
		condition = "0";\
	};
	// BACKGROUND_RECTANGLE \
	// 	BOX_CONTENT_START(COLOR)};}; \
	// 		TEXT_MID_SCALED(MYTEXT,0,-0.025,TEXT,0.05) \
	// 	}; \
	// };

#define LINE_VERT(COLOR,SIZE) \
 	class verticalLine { \
        color[] = COLOR; \
		alpha = 1; \
        class Line \
        { \
            type = "line"; \
            width = 4; \
            points[] = { \
				{{-SIZE, 0}, 1}, \
				{{ SIZE, 0}, 1} \
			}; \
		}; \
 	};
	

#define POI_SQUARE_SCALE 0.75
#define POI_BLACK_BACKGROUND \
    class BlackOverlay { \
        color[] = {0.05,0.05,0.05,0.5}; \
        class BlackPoly \
        { \
            type = "polygon"; \
            width = 2; \
            points[] = { \
                { \
                    {{POI_SQUARE_SCALE*-0.02, POI_SQUARE_SCALE*0.02}, 1}, \
                    {{POI_SQUARE_SCALE*0.02,  POI_SQUARE_SCALE*0.02}, 1}, \
                    {{POI_SQUARE_SCALE*0.02,  POI_SQUARE_SCALE*-0.02}, 1}, \
                    {{POI_SQUARE_SCALE*-0.02, POI_SQUARE_SCALE*-0.02}, 1} \
                } \
            }; \
        };

class BFT
{
    type = sensor;
	#ifdef SENSOR_SIZE
		#undef SENSOR_SIZE
	#endif
    // #define SENSOR_SIZE(numb)\
    //     pos[]	= {{0,0}, 1};\
    //     down[]	= {{1,1}, 1};
    // SENSOR_SIZE(-0.01)
	pos[]	= {{0,-0.15}, 1};
	down[]	= {{1, 1.15}, 1};

    showTargetTypes = 1+2+4+8+16+32+64+128+256+512+1024;    // RWR only
    width = 1; // default width of lines can by different in case of class XXXX used instead of arrays
    range=user40;
    sensorLineType = 3; // same as "lineType"
    sensorLineWidth = 0;
	class MissileThreat {};
	class lockingThreat {}; // locking, you're in for a bad time
	class markingThreat {}; // radar is tracking you actively
	class rwrFriendly {};
	class rwrEnemy {};
	class rwrGroup {};
	class rwrDestroyed {};
	class markedTarget {TEXT_MID_SCALED(MYTEXT,0,-0.025,"MT",0.05)};
	class assignedTarget {};
	class target {TEXT_MID_SCALED(MYTEXT,0,-0.025,"T",0.05)};
	class targetFriendly {TEXT_MID_SCALED(MYTEXT,0,-0.025,"TF",0.05)};
	class targetEnemy {TEXT_MID_SCALED(MYTEXT,0,-0.025,"TE",0.05)};
	class targetGroup {};
	class targetDestroyed {};
	class targetGround { ARMORED(common_white) };
	class targetGroundFriendly { ARMORED(common_blue) };
	class targetGroundEnemy { ARMORED(common_red) };
	class targetGroundGroup { ARMORED(common_green) };
	class targetGroundDestroyed { ARMORED(common_purple) };
	class targetGroundRemote { ARMORED(common_white) };
	class targetGroundRemoteFriendly { ARMORED(common_blue) };
	class targetGroundRemoteEnemy { ARMORED(common_red) };
	class targetGroundRemoteGroup { ARMORED(common_green) };
	class targetGroundRemoteDestroyed { ARMORED(common_purple) };
	class targetLaser {};
	class targetLaserFriendly {};
	class targetLaserEnemy {};
	class targetLaserGroup {};
	class targetNVG {TEXT_MID_SCALED(MYTEXT,0,-0.025,"IR-CIV",0.05)};
	class targetNVGFriendly {TEXT_MID_SCALED(MYTEXT,0,-0.025,"IR-BLUE",0.05)};
	class targetNVGEnemy {
		POI_BLACK_BACKGROUND
			class red {
				color[] = common_purple;
				class TargetLines
				{
					type = "line";
					width = 2;
					points[] = {
						{{POI_SQUARE_SCALE*-0.02, POI_SQUARE_SCALE*0.02}, 1},
						{{POI_SQUARE_SCALE*0.02,  POI_SQUARE_SCALE*0.02}, 1},
						{{POI_SQUARE_SCALE*0.02,  POI_SQUARE_SCALE*-0.02}, 1},
						{{POI_SQUARE_SCALE*-0.02, POI_SQUARE_SCALE*-0.02}, 1},
						{{POI_SQUARE_SCALE*-0.02, POI_SQUARE_SCALE*0.02}, 1}
					};
				};
				TEXT_MID_SCALED(TEXT,0,-0.019,"i",0.035)
			};
		};
	};
	class targetNVGGroup {TEXT_MID_SCALED(MYTEXT,0,-0.025,"IR-GRP",0.05)};
	class targetMan { INFANTRY(common_white) };
	class targetManFriendly { INFANTRY(common_blue) };
	class targetManEnemy { INFANTRY(common_red) };
	class targetManGroup { INFANTRY(common_green) };
	class targetManRemote { INFANTRY(common_white) };
	class targetManRemoteFriendly { INFANTRY(common_blue) };
	class targetManRemoteEnemy { INFANTRY(common_red) };
	class targetManRemoteGroup { INFANTRY(common_green) };
	class targetAir { AIRCAFT(common_white) };
	class targetAirFriendly { AIRCAFT(common_blue) };
	class targetAirEnemy { AIRCAFT(common_red) };
	class targetAirGroup { AIRCAFT(common_green) };
	class targetAirDestroyed {};
	class targetAirRemote { AIRCAFT(common_white) };
	class targetAirRemoteFriendly { AIRCAFT(common_blue) };
	class targetAirRemoteEnemy { AIRCAFT(common_red) };
	class targetAirRemoteGroup { AIRCAFT(common_green) };
	class targetAirRemoteDestroyed {};
};
