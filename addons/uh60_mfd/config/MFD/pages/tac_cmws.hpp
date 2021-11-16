borderLeft=0;
borderRight=0.25;
borderTop=0;
borderBottom=0;
color[]=common_white;
enableParallax=0;
font="RobotoCondensedLight";
class material {
	ambient[] = {1, 1, 1, 1};
	diffuse[] = {0.5, 0.5, 0.5, 1};
	emissive[] = {100, 100, 100, 1};
};

class Bones {
        class TAC_CMWS_Offset
        {
            type	= fixed;
            pos[]	= {0.285, 0.757};
        };
};

class Draw {
    condition = COND_ISNUMBER(MFD_PAGE_INDEX,MFD_PAGE_TAC);
    class TAC_CMWS
    {
        //  type = sensor;
        #ifdef SENSOR_SIZE
            #undef SENSOR_SIZE
        #endif
        #define SENSOR_SIZE(SIZE) \
        pos[]	= {TAC_CMWS_Offset,{(0+SIZE)*0.725, 0+SIZE}, 1}; \
        down[]	= {TAC_CMWS_Offset,{(0-SIZE)*0.725, 0-SIZE}, 1}
        SENSOR_SIZE(-0.17);

        showTargetTypes = 1+2+8+64+1024;    // RWR only
        //showTargetTypes = 1+2+4+8+16+32+64+128+256+512+1024;
        width = 1; // default width of lines can by different in case of class XXXX used instead of arrays
        range=4000;
        sensorLineType = 2; // same as "lineType"
        sensorLineWidth = 3;
        class MissileThreat
        {
            color[] = {1,0,0};
            class MissleText{
                type="text";
                source="static";
                text="M";
                scale=1;
                sourceScale=1;
                align = "center";
                pos[]= {{0.00, -0.015}, 1};
                right[]= {{0.06, -0.015}, 1};
                down[]= {{0.00, 0.015}, 1};
            };
            class MissileBox
            {
                type = "line";
                width = 5.0000;
                points[] ={
                    {{-0.015, -0.015},1},
                    {{0.015, -0.015},1},
                    {{0.015, 0.015},1},
                    {{-0.015, 0.015},1},
                    {{-0.015, -0.015},1}
                };
            };
        };
        class markingThreat
        {
            color[] = {1,1,0}; // radar is tracking you actively
            class background {
            	type        = "polygon";
            	points[] ={
            		{
            			{{-0.015, 0.015},1},
            			{{0.015, 0.015},1},
            			{{0.015, -0.015},1},
            			{{-0.015, -0.015},1}
            		}
            	}; // points
            }; // background
            class unknownTarget
            {
                type = "line";
                width = 5.0000;
                points[] ={
                    {{-0.015, -0.015},1},
                    {{0.015, -0.015},1},
                    {{0.015, 0.015},1},
                    {{-0.015, 0.015},1},
                    {{-0.015, -0.015},1},{},
                    {{-0.002, -0.002},1},
                    {{0.002, 0.002},1},{},
                    {{-0.002, 0.002},1},
                    {{0.002, -0.002},1}
                };
            };
        };
        class lockingThreat
        {
            color[] = {1,0,0};
            class background {
            	type        = "polygon";
            	points[] ={
            		{
            			{{-0.015, 0.015},1},
            			{{0.015, 0.015},1},
            			{{0.015, -0.015},1},
            			{{-0.015, -0.015},1}
            		}
            	}; // points
            }; // background
            class TargetBox
            {
                type = "line"; // locking, you're in for a bad time
                width = 5.0000;
                points[] ={
                    {{-0.015,0},1},
                    {{0, -0.015 },1},
                    {{0.015,0 },1},
                    {{0, 0.015 },1},
                    {{-0.015,0},1},{},
                    {{-0.005,0.005},1},
                    {{0,-0.005},1},
                    {{0.005,0.005},1}
                };
            };
        };
        //rwr
        class rwr
        {
            class TargetBox
            {
                type = "line"; // there's a radar, but stuff isn't happening yet
                width = 5.0000;
                points[] ={
                    {{-0.015, -0.015},1},
                    {{0.015, -0.015},1},
                    {{0.015, 0.015},1},
                    {{-0.015, 0.015},1},
                    {{-0.015, -0.015},1},{},
                    {{-0.005,0.005},1},
                    {{0,-0.005},1},
                    {{0.005,0.005},1}
                };
            };
        };
        class rwrFriendly: rwr
        {
           color[]	= common_green;
        };
        class rwrEnemy: rwr
        {
          color[]	= common_red;
        };
        //ground
        class targetGround
        {
            class TargetBox { };
        };
        class targetAir
        {
        };
    };
};
