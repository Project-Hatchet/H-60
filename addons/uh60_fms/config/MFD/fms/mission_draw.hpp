TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
	source = "static";
	text = "MISSION SYSTEMS";
}; // HEADER_TEXT

TEXT_FMS_L(L1,FMS_MARGIN_L,FMS_Y1)
	source = "static";
	text = "< WEAPONS";
}; // L5

TEXT_FMS_L(L2,FMS_MARGIN_L,FMS_Y2)
	source = "static";
	text = "< RADAR";
}; // L5

TEXT_FMS_L(L3,FMS_MARGIN_L,FMS_Y3-FMS_HALF_LINE)
	source = "static";
	text = "HMD";
}; // L3
class HMD_ON {
	condition="user15>0";
	TEXT_FMS_L(L3,FMS_MARGIN_L,FMS_Y3+FMS_HALF_LINE)
		source = "static";
		text = "ON";
	}; // L3
};
class HMD_OFF {
	condition="(user15<1)*(user15>-1)";
	TEXT_FMS_L(L3,FMS_MARGIN_L,FMS_Y3+FMS_HALF_LINE)
		source = "static";
		text = "OFF";
	}; // L3
};
class HMD_NOT_CAPABLE {
	condition="user15<0";
	TEXT_FMS_L(L3,FMS_MARGIN_L,FMS_Y3+FMS_HALF_LINE)
		source = "static";
		text = "NOT INST";
	}; // L3
};

TEXT_FMS_R(R1,FMS_MARGIN_R,FMS_Y1)
	source = "static";
	text = "ASE >";
}; // L5

TEXT_FMS_R(R2,FMS_MARGIN_R,FMS_Y2)
	source = "static";
	text = "FLIR >";
}; // L5

TEXT_FMS_L(L5,FMS_MARGIN_L,FMS_Y5)
	source = "static";
	text = "< MENU";
}; // L5
