class ND_CMWS_SENSOR {
	type = "sensor";
	pos[]	= {{0.53-0.4,0.5-0.4},1};
	down[]	= {{0.53+0.4,0.5+0.4},1};

	/*	1 - Sensor sectors,
		2 - Threats,
		4 - Marked tgt symbol,
		8 - Own detection,
		16 - Remote detection,
		32 - Active detection,
		64 - Passive detection,
		128 - Ground tgts,
		256 - Air tgts,
		512 - Men,
		1024 - Special (laser, NV)
		*/
	showTargetTypes = "2+8+64+128+256";
	width = 1; // default width of lines can by different in case of class XXXX used instead of arrays
	range=4000;
	sensorLineType = 2; // same as "lineType"
	sensorLineWidth = 3;
	class MissileThreat
	{
		BLACK_BACKGROUND
			class red {
				color[] = common_red;
				class TargetLines
				{
					type = "line";
					width = 2;
					points[] = {
						{{1.1*-0.02, 1.1*0.02}, 1},
						{{1.1*0.02,  1.1*0.02}, 1},
						{{1.1*0.02,  1.1*-0.02}, 1},
						{{1.1*-0.02, 1.1*-0.02}, 1},
						{{1.1*-0.02, 1.1*0.02}, 1}
					};
				};
				TEXT_MID_SCALED(TEXT,0,-0.025,"M",0.05)
			};
		};
	};
	class rwr // there's a radar, but stuff isn't happening yet
	{
		BLACK_BACKGROUND
			class white {
				color[] = common_white;
				class TargetLines
				{
					type = "line";
					width = 3;
					points[] = {
						SQUARE_POINTS,
						{{0.8* 0.00, 0.8*-0.02}, 1}, // top center
						{{0.8*-0.02, 0.8* 0.02}, 1}, // bottom left
						{{0.8* 0.02, 0.8* 0.02}, 1}, // bottom right
						{{0.8* 0.00, 0.8*-0.02}, 1}  // top center
					};
				}; // lines
			}; // white
		}; // background
	};
	class lockingThreat: rwr{
		color[] = RGBA256(160/4,30/4,30/4,0.05);
		class TargetLines
		{
			type = "polygon";
			width = 2;
			points[] = {
				{
					{{2.5*-0.02, 2.5*0.02}, 1},
					{{2.5*0.02,  2.5*0.02}, 1},
					{{2.5*0.02,  2.5*-0.02}, 1},
					{{2.5*-0.02, 2.5*-0.02}, 1}
				}
			};
		};
		BLACK_BACKGROUND_RADAR
	}; // locking, you're in for a bad time
	class markingThreat: rwr{
		color[] = RGBA256(230/4,230/4,40/4,0.05);
		class TargetLines
		{
			type = "polygon";
			width = 2;
			points[] = {
				{
					{{2.5*-0.02, 2.5*0.02}, 1},
					{{2.5*0.02,  2.5*0.02}, 1},
					{{2.5*0.02,  2.5*-0.02}, 1},
					{{2.5*-0.02, 2.5*-0.02}, 1}
				}
			};
		};
		BLACK_BACKGROUND_RADAR
	}; // radar is tracking you actively
	class rwrFriendly: rwr{
		color[] = common_blue;
		class TargetLines
		{
			type = "line";
			width = 2;
			points[] = {
				SQUARE_POINTS,{},
				TRIANGLE_POINTS
			};
		};
	};
	class rwrEnemy: rwr{};
	class rwrGroup: rwr{};
	class rwrDestroyed: rwr{};
};
