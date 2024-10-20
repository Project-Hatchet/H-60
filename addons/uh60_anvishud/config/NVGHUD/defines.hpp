
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

#define KMH_TO_KMH 1
#define KMH_TO_KTS 1.8519

#define M_TO_NM 0.000539957
#define M_TO_KM 0.001

#define M_TO_FT 3.28084
#define M_TO_M 1

#define CIRCLE36(BONE,RADIUS) \
{BONE, ANGLE(000,RADIUS), 1}, \
{BONE, ANGLE(030,RADIUS), 1}, \
{BONE, ANGLE(060,RADIUS), 1}, \
{BONE, ANGLE(090,RADIUS), 1}, \
{BONE, ANGLE(120,RADIUS), 1}, \
{BONE, ANGLE(150,RADIUS), 1}, \
{BONE, ANGLE(180,RADIUS), 1}, \
{BONE, ANGLE(210,RADIUS), 1}, \
{BONE, ANGLE(240,RADIUS), 1}, \
{BONE, ANGLE(270,RADIUS), 1}, \
{BONE, ANGLE(300,RADIUS), 1}, \
{BONE, ANGLE(330,RADIUS), 1}, \
{BONE, ANGLE(360,RADIUS), 1}