
// SRC
#define TEXT_LEFT_SCALED_SRC(CLASS,X,Y,SCALE) \
	class CLASS { \
		type = "text"; \
		align = "right"; \
		scale = 1; \
		pos[] = {{X, Y}, 1}; \
		right[] = {{X + (SCALE*1), Y}, 1}; \
		down[] = {{X, Y + SCALE}, 1};

#define TEXT_MID_SCALED_SRC(CLASS,X,Y,SCALE) \
	class CLASS { \
		type = "text"; \
		align = "center"; \
		scale = 1; \
		pos[] = {{X, Y}, 1}; \
		right[] = {{X + (SCALE*1), Y}, 1}; \
		down[] = {{X, Y + SCALE}, 1};

#define TEXT_RIGHT_SCALED_SRC(CLASS,X,Y,SCALE) \
	class CLASS { \
		type = "text"; \
		align = "left"; \
		scale = 1; \
		pos[] = {{X, Y}, 1}; \
		right[] = {{X + (SCALE*1), Y}, 1}; \
		down[] = {{X, Y + SCALE}, 1};

// USERTEXT
#define TEXT_LEFT_SCALED_USERTEXT(CLASS,X,Y,IDX,SCALE) \
	TEXT_LEFT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "userText"; \
        sourceIndex = IDX; \
        sourceScale = 1; \
		text = ""; \
	};

#define TEXT_MID_SCALED_USERTEXT(CLASS,X,Y,IDX,SCALE) \
	TEXT_MID_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "userText"; \
        sourceIndex = IDX; \
        sourceScale = 1; \
		text = ""; \
	};

#define TEXT_RIGHT_SCALED_USERTEXT(CLASS,X,Y,IDX,SCALE) \
	TEXT_RIGHT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "userText"; \
        sourceIndex = IDX; \
        sourceScale = 1; \
		text = ""; \
	};

// STATIC
#define TEXT_RIGHT_SCALED(CLASS,X,Y,TEXT,SCALE) \
	TEXT_RIGHT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "static"; \
		text = TEXT; \
	};


#define TEXT_MID_SCALED(CLASS,X,Y,TEXT,SCALE) \
	TEXT_MID_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "static"; \
		text = TEXT; \
	};

#define TEXT_LEFT_SCALED(CLASS,X,Y,TEXT,SCALE) \
	TEXT_LEFT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = "static"; \
		text = TEXT; \
	};

// SOURCE
#define TEXT_LEFT_SCALED_SOURCE(CLASS,X,Y,SCALE,SOURCE,SOURCEINDEX,SOURCESCALE,DECIMALS) \
	TEXT_LEFT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = SOURCE; \
        sourceIndex = SOURCEINDEX; \
		sourceScale = SOURCESCALE; \
        sourcePrecision = DECIMALS; \
	};

#define TEXT_MID_SCALED_SOURCE(CLASS,X,Y,SCALE,SOURCE,SOURCEINDEX,SOURCESCALE,DECIMALS) \
	TEXT_MID_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = SOURCE; \
        sourceIndex = SOURCEINDEX; \
		sourceScale = SOURCESCALE; \
        sourcePrecision = DECIMALS; \
	};


#define TEXT_RIGHT_SCALED_SOURCE(CLASS,X,Y,SCALE,SOURCE,SOURCEINDEX,SOURCESCALE,DECIMALS) \
	TEXT_RIGHT_SCALED_SRC(CLASS,X,Y,SCALE) \
		source = SOURCE; \
        sourceIndex = SOURCEINDEX; \
		sourceScale = SOURCESCALE; \
        sourcePrecision = DECIMALS; \
	};


// pitch

#define PITCH_BASE(X1,X2,Y1,Y2) \
    class Level0 \
    { \
        pos0[] = {X1, Y1}; \
        pos10[] = {X2, Y2}; \
        type = "horizon"; \
        angle = 0; \
    };

#define PITCH_LEVEL(CNAME,ANG) \
    class CNAME##_pos: Level0 {angle=ANG;}; \
    class CNAME##_neg: Level0 {angle=-ANG;};

// angles


#define ANGLEX(DEG,RADIUS) (sin DEG * (RADIUS))
#define ANGLEY(DEG,RADIUS) (cos DEG * (RADIUS))
#define ANGLE(DEG,RADIUS) {ANGLEX(DEG,RADIUS), ANGLEY(DEG,RADIUS)}