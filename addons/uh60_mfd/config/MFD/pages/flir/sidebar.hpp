class sidebar {
	COLORED_POLYGON(PB1,0.85,0.1,0.12,0.1,common_black)
	COLORED_POLYGON(EngagementBG,0.85,0.28,0.15,0.21,common_black)
	condition = "0";
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
	};
};