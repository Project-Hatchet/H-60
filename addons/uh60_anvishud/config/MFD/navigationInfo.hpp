
TEXT_HMD_R_SCALE(WP_NAME,0.94,0.85,TEXT_SIZE_SMALL)
	source="userText";
	sourceScale=1;
	sourceIndex=7;
}; // WP_NAME

class IMPERIAL {
    condition = COND_IMPERIAL;
    TEXT_HMD_R_SCALE(WP_DIST_NM,0.87,0.85+SMALL_LINEHEIGHT,TEXT_SIZE_SMALL)
        source="static";
        sourceScale=1;
        text="NM /";
    }; // WP_DIST_NM
    TEXT_HMD_R_SCALE(WP_DIST,0.87-0.09,0.85+SMALL_LINEHEIGHT,TEXT_SIZE_SMALL)
        source="WPDist";
        sourceScale=0.000539957;
        sourceLength=3;
        sourcePrecision=1;
    }; // WP_DIST
};
class METRIC {
    condition = COND_METRIC;
    TEXT_HMD_R_SCALE(WP_DIST_NM,0.87,0.85+SMALL_LINEHEIGHT,TEXT_SIZE_SMALL)
        source="static";
        sourceScale=1;
        text="KM /";
    }; // WP_DIST_NM
    TEXT_HMD_R_SCALE(WP_DIST,0.87-0.09,0.85+SMALL_LINEHEIGHT,TEXT_SIZE_SMALL)
        source="WPDist";
        sourceScale=0.001;
        sourceLength=3;
        sourcePrecision=1;
    }; // WP_DIST
};
TEXT_HMD_R_SCALE(WP_DIR,0.94,0.85+SMALL_LINEHEIGHT,TEXT_SIZE_SMALL)
	source="user";
	sourceIndex=0;
	sourceScale=1;
}; // WP_DIR
TEXT_HMD_R_SCALE(WP_DIR_DEG,0.96,0.85+SMALL_LINEHEIGHT,TEXT_SIZE_SMALL)
    source="static";
    sourceScale=1;
    text="°";
}; // WP_DIR_DEG

TEXT_HMD_R_SCALE(WP_TOF,0.94,0.85+(SMALL_LINEHEIGHT*2),TEXT_SIZE_SMALL)
	source="usertext";
	sourceIndex=8;
	sourceScale=1;
}; // WP_DIR