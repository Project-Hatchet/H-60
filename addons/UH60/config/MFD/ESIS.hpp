class ESIS_Horizon
{
    topLeft="ESIS_LH";
    topRight="ESIS_RH";
    bottomLeft="ESIS_LD";
    borderLeft=-0.5;
    borderRight=-0.5;
    borderTop=-0.1;
    borderBottom=-0.9;
    color[]= common_white;
    enableParallax=0;
    class material
    {
        ambient[] = {1, 1, 1, 1};
        diffuse[] = {1, 1, 1, 1};
        emissive[] = {100, 100, 100, 1};
    };
    class Bones
    {
        PITCH_BONES(0.5,0.6,0.3,0.4)
    };
    class Draw { 
        condition = "user49 < 0.1";
        class clip1{
            clipTL[] = {0.25, 0.02};
            clipBR[] = {0.75, 0.55};
    		LEVEL_BACKGROUND(pitch_att_blue,pitch_esis_grey,0.5)
        };//clip1
        class clip2 {
            clipTL[] = {0.25, 0.15};
            clipBR[] = {0.75, 0.47};
    		LEVEL0(0.23)
            LEVEL_SET(5,10,0.02,0.05,0.08)
            LEVEL_SET(15,20,0.02,0.05,0.08)
            LEVEL_SET(25,30,0.02,0.05,0.08)
            LEVEL_SET(35,40,0.02,0.05,0.08)
            LEVEL_SET(45,50,0.02,0.05,0.08)
            LEVEL_SET(55,60,0.02,0.05,0.08)
            LEVEL_SET(65,70,0.02,0.05,0.08)
            LEVEL_SET(75,80,0.02,0.05,0.08)
            LEVEL_SET(85,90,0.02,0.05,0.08)
        }; // clip2
    }; // Draw
};



class ESIS_Misc
{
    topLeft="ESIS_LH";
    topRight="ESIS_RH";
    bottomLeft="ESIS_LD";
    borderLeft=0.0;
    borderRight=0.0;
    borderTop=-0.0;
    borderBottom=0.0;
    color[]= common_white;
    enableParallax=0;
    class material
    {
        ambient[] = {1, 1, 1, 1};
        diffuse[] = {1, 1, 1, 1};
        emissive[] = {100, 100, 100, 1};
    };
    class Bones
    {
        class VSpeed_linear {
            type = "linear";
            source = "vspeed";
            sourceScale = 196.8504;
            min = -300;
            max = 300;
            minPos[]={"0.83", "0.27"};
            maxPos[]={"0.83", "0.73"};
        };
        class Middle{
            type="fixed";
            pos[]={0.5,"0.5"};
        };
        class HorizonBankRot {
            type="rotational";
            source="horizonBank";
            center[]={0.5,0.5};
            min=-1.0472;
            max=1.0472;
            minAngle=50;
            maxAngle=-50;
            aspectRatio=1;
        };
    };//bones
    class Draw { 
        condition = "user49 < 0.1";
        class BlackBars{
            color[]    = {0.1, 0.1, 0.1, 1};
            class PolygonLeft {
                type        = "polygon";
                points[] ={
                    {
                        {{0.0, 0.0},1},
                        {{0.2, 0.0},1},
                        {{0.2, 1.0},1},
                        {{0.0, 1.0},1}}
                    };
                };
                class PolygonRight {
                    type        = "polygon";
                    points[] ={
                        {
                            {{0.8, 0.0},1},
                            {{1.0, 0.0},1},
                            {{1.0, 1.0},1},
                            {{0.8, 1.0},1}}
                        };
                    };
                };//BlackBars

                class Heading_Scale
                {
                    type="scale";
                    horizontal=1;
                    NeverEatSeaWeed=1;
                    source="heading";
                    sourceScale=0.100000;
                    sourcelength=2;
                    width=10;
                    top=    0.20;
                    center=    0.50;
                    bottom=    0.80;
                    lineXleft=0.865;
                    lineYright=0.90;
                    lineXleftMajor=0.865;
                    lineYrightMajor=0.90;
                    majorLineEach=2;
                    numberEach=2;
                    step="1.5";
                    stepSize="(0.8 - 0.2) / 8";
                    align="center";
                    scale=1;
                    pos[]={0.19,0.895};
                    right[]={0.285,0.895};
                    down[]={0.19,0.980};
                };//Heading_Scale
                class HeadingArrow{
                    type="line";
                    width=10;
                    points[]={
                        {{0.5, 0.865},1},{{0.5, 0.98},1}
                    };
                };//HeadingArrow
                class Speed_scale{
                    type = "scale";
                    scale = 2;
                    source = "speed";
                    sourceScale=1.94384;
                    sourcelength=1;
                    align = "left";
                    width=10;
                    lineXleft =         0.165;
                    lineYright =         0.2;
                    lineXleftMajor =     0.165;
                    lineYrightMajor =     0.2;
                    top =         "1";
                    center =     "0.5";
                    bottom =     "0";
                    step = 10;
                    StepSize = "(1)/8";
                    horizontal = 0;
                    numberEach = 2;
                    majorLineEach = 2;
                    pos[] =     {0.115    ,0.95};
                    right[] =     {0.215    ,0.95};
                    down[] =     {0.115    ,1.05};
                };//Speed_scale

                class VSpeed_scale{
                    class Triangle {
                        type        = "polygon";
                        points[] ={{{"VSpeed_linear",{0.025, 0.0},1},{"VSpeed_linear",{-0.025, 0.025},1},{"VSpeed_linear",{-0.025, -0.025},1}}};
                    };//Triangle
                    class Lines{
                        type="line";
                        width=4;
                        points[]={
                            {{0.86, 0.5},1},{{0.89, 0.5},1},{},
                            {{0.86, 0.52875},1},{{0.89, 0.52875},1},{},
                            {{0.86, 0.557},1},{{0.89, 0.5575},1},{},
                            {{0.86, 0.58625},1},{{0.89, 0.58625},1},{},
                            {{0.86, 0.615},1},{{0.89, 0.615},1},{},
                            {{0.86, 0.64375},1},{{0.89, 0.64375},1},{},
                            {{0.86, 0.6725},1},{{0.89, 0.6725},1},{},
                            {{0.86, 0.70125},1},{{0.89, 0.70125},1},{},
                            {{0.86, 0.73},1},{{0.89, 0.73},1},{},
                            {{0.86, 0.27},1},{{0.89, 0.27},1},{},
                            {{0.86, 0.47125},1},{{0.89, 0.47125},1},{},
                            {{0.86, 0.4425},1},{{0.89, 0.4425},1},{},
                            {{0.86, 0.41375},1},{{0.89, 0.41375},1},{},
                            {{0.86, 0.385},1},{{0.89, 0.385},1},{},
                            {{0.86, 0.35625},1},{{0.89, 0.35625},1},{},
                            {{0.86, 0.3275},1},{{0.89, 0.3275},1},{},
                            {{0.86, 0.29875},1},{{0.89, 0.29875},1},{},
                        };
                    };//lines
                    class Text_0{
                        type="text";
                        source="static";
                        text="0";
                        scale=1;
                        sourceScale=1;
                        align = "right";
                        pos[]= {{0.90, 0.47}, 1};
                        right[]= {{0.97, 0.47}, 1};
                        down[]= {{0.90, 0.54}, 1};
                    };
                    class Text_1:Text_0{
                        text="1";
                        pos[]= {{0.90, "0.423-0.035"}, 1};
                        right[]= {{0.97, "0.423-0.035"}, 1};
                        down[]= {{0.90, "0.423+0.035"}, 1};
                    };
                    class Text_2:Text_0{
                        text="2";
                        pos[]= {{0.90, "0.3467-0.035"}, 1};
                        right[]= {{0.97, "0.3467-0.035"}, 1};
                        down[]= {{0.90, "0.3467+0.035"}, 1};
                    };
                    class Text_3:Text_0{
                        text="3";
                        pos[]= {{0.90, 0.235}, 1};
                        right[]= {{0.97, 0.235}, 1};
                        down[]= {{0.90, 0.305}, 1};
                    };
                    class Text_N1:Text_0{
                        text="1";
                        pos[]= {{0.90, "0.5767-0.035"}, 1};
                        right[]= {{0.97,"0.5767-0.035"}, 1};
                        down[]= {{0.90, "0.5767+0.035"}, 1};
                    };
                    class Text_N2:Text_0{
                        text="2";
                        pos[]= {{0.90, "0.653-0.035"}, 1};
                        right[]= {{0.97,"0.653-0.035"}, 1};
                        down[]= {{0.90, "0.653+0.035"}, 1};
                    };
                    class Text_N3:Text_0{
                        text="3";
                        pos[]= {{0.90, 0.695}, 1};
                        right[]= {{0.97, 0.695}, 1};
                        down[]= {{0.90, 0.765}, 1};
                    };
                };//VSpeed_scale
                class AircraftSymbolCenter{
                    class White{
                        color[]    = common_white;
                        class P1 {
                            type        = "polygon";
                            points[] ={{{{0.22, 0.480},1},{{0.30, 0.480},1},{{0.30, 0.52},1},{{0.22, 0.52},1}}};
                        };//P1
                        class P2 {
                            type        = "polygon";
                            points[] ={{{{0.31, 0.480},1},{{0.415, 0.480},1},{{0.415, 0.52},1},{{0.31, 0.52},1}}};
                        };//P2
                        class P3 {
                            type        = "polygon";
                            points[] ={{{{0.375, 0.480},1},{{0.415, 0.480},1},{{0.415, 0.56},1},{{0.375, 0.56},1}}};
                        };//P3
                        class P4 {
                            type        = "polygon";
                            points[] ={{{{0.78, 0.480},1},{{0.7, 0.480},1},{{0.7, 0.52},1},{{0.78, 0.52},1}}};
                        };//P4
                        class P5 {
                            type        = "polygon";
                            points[] ={{{{0.69, 0.480},1},{{0.585, 0.480},1},{{0.585, 0.52},1},{{0.69, 0.52},1}}};
                        };//P5
                        class P6 {
                            type        = "polygon";
                            points[] ={{{{0.625, 0.480},1},{{0.585, 0.480},1},{{0.585, 0.56},1},{{0.625, 0.56},1}}};
                        };//P6
                        class P7 {
                            type        = "polygon";
                            points[] ={{{{0.48, 0.480},1},{{0.52, 0.480},1},{{0.52, 0.52},1},{{0.48, 0.52},1}}};
                        };//P7
                        //speed
                        class P8 {
                            type        = "polygon";
                            points[] ={{{{0.02, 0.460},1},{{0.2, 0.460},1},{{0.2, 0.54},1},{{0.02, 0.54},1}}};
                        };//P8
                        class P9 {
                            type        = "polygon";
                            points[] ={{{{0.12, 0.440},1},{{0.2, 0.440},1},{{0.2, 0.56},1},{{0.12, 0.56},1}}};
                        };//P9
                        //alt
                        class P10 {
                            type        = "polygon";
                            points[] ={{{{0.76, 0.12},1},{{0.98, 0.12},1},{{0.98, 0.20},1},{{0.76, 0.20},1}}};
                        };//P10
                        class P11 {
                            type        = "polygon";
                            points[] ={{{{0.98, 0.10},1},{{0.9, 0.10},1},{{0.9, 0.22},1},{{0.98, 0.22},1}}};
                        };//P11
                    };//white
                    class Black{
                        color[]    = {0, 0, 0, 1};
                        class P1 {
                            type        = "polygon";
                            points[] ={{{{0.23, 0.49},1},{{0.29, 0.49},1},{{0.29, 0.51},1},{{0.23, 0.51},1}}};
                        };//P1
                        class P2 {
                            type        = "polygon";
                            points[] ={{{{0.32, 0.49},1},{{0.405, 0.490},1},{{0.405, 0.51},1},{{0.32, 0.51},1}}};
                        };//P2
                        class P3 {
                            type        = "polygon";
                            points[] ={{{{0.385, 0.490},1},{{0.405, 0.490},1},{{0.405, 0.55},1},{{0.385, 0.55},1}}};
                        };//P3
                        class P4 {
                            type        = "polygon";
                            points[] ={{{{0.77, 0.49},1},{{0.71, 0.49},1},{{0.71, 0.51},1},{{0.77, 0.51},1}}};
                        };//P4
                        class P5 {
                            type        = "polygon";
                            points[] ={{{{0.68, 0.49},1},{{0.595, 0.490},1},{{0.595, 0.51},1},{{0.68, 0.51},1}}};
                        };//P5
                        class P6 {
                            type        = "polygon";
                            points[] ={{{{0.615, 0.490},1},{{0.595, 0.490},1},{{0.595, 0.55},1},{{0.615, 0.55},1}}};
                        };//P6
                        class P7 {
                            type        = "polygon";
                            points[] ={{{{0.49, 0.490},1},{{0.51, 0.490},1},{{0.51, 0.51},1},{{0.49, 0.51},1}}};
                        };//P7
                        //speed
                        class P8 {
                            type        = "polygon";
                            points[] ={{{{0.025, 0.465},1},{{0.195, 0.465},1},{{0.195, 0.535},1},{{0.025, 0.535},1}}};
                        };//P8
                        class P9 {
                            type        = "polygon";
                            points[] ={{{{0.125, 0.445},1},{{0.195, 0.445},1},{{0.195, 0.555},1},{{0.125, 0.555},1}}};
                        };//P9
                        //alt
                        class P10 {
                            type        = "polygon";
                            points[] ={{{{0.765, 0.125},1},{{0.975, 0.125},1},{{0.975, 0.195},1},{{0.765, 0.195},1}}};
                        };//P10
                        class P11 {
                            type        = "polygon";
                            points[] ={{{{0.975, 0.105},1},{{0.905, 0.105},1},{{0.905, 0.215},1},{{0.975, 0.215},1}}};
                        };//P11
                    };//black
                };//AircraftSymbolCenter

                class Value_Speed{
                    type="text";
                    source="speed";
                    scale=1;
                    sourceScale=1.94384;
                    align = "left";
                    pos[]= {{0.18, 0.45}, 1};
                    right[]= {{0.28, 0.45}, 1};
                    down[]= {{0.18, 0.55}, 1};
                };
                class Value_Alt{
                    type="text";
                    source="altitudeASL";
                    scale=1;
                    sourceScale=3.28084;
                    align = "left";
                    pos[]= {{0.96, 0.11}, 1};
                    right[]= {{1.06, 0.11}, 1};
                    down[]= {{0.96, 0.21}, 1};
                };
                class Bank_Marks{
                    type="line";
                    width=8;
                    points[]={
                        {"Middle", {0.306418, -0.257115},1},//40
                        {"Middle", {0.260455, -0.218548},1},{},
                        {"Middle", {0.257115, -0.306418},1},//50
                        {"Middle", {0.218548, -0.260455},1},{},
                        {"Middle", {0.200000, -0.346410},1},//60
                        {"Middle", {0.170000, -0.294449},1},{},
                        {"Middle", {0.136808, -0.375877},1},//70
                        {"Middle", {0.116287, -0.319495},1},{},
                        {"Middle", {0.069459, -0.393923},1},//80
                        {"Middle", {0.059040, -0.334835},1},{},
                        {"Middle", {0.000000, -0.400000},1},//90
                        {"Middle", {0.000000, -0.340000},1},{},
                        {"Middle", {-0.069459, -0.393923},1},//100
                        {"Middle", {-0.059040, -0.334835},1},{},
                        {"Middle", {-0.136808, -0.375877},1},//110
                        {"Middle", {-0.116287, -0.319495},1},{},
                        {"Middle", {-0.200000, -0.346410},1},//120
                        {"Middle", {-0.170000, -0.294449},1},{},
                        {"Middle", {-0.257115, -0.306418},1},//130
                        {"Middle", {-0.218548, -0.260455},1},{},
                        {"Middle", {-0.306418, -0.257115},1},//140
                        {"Middle", {-0.260455, -0.218548},1},{},
                    };
                };
                class StaticTriangle {
                    type        = "polygon";
                    points[] ={{{"Middle",{0, "-0.35"},1},{"Middle",{-0.025, "-0.4"},1},{"Middle",{0.025, "-0.4"},1}}};
                };
                class Bank_triangle {
                    type        = "polygon";
                    points[] ={{{"HorizonBankRot",{0, "0+0.33"},1},{"HorizonBankRot",{-0.025, "-0.05+0.33"},1},{"HorizonBankRot",{0.025, "-0.05+0.33"},1}}};
                };//Triangle
                class Bank_Rectangle {
                    type        = "polygon";
                    points[] ={{{"HorizonBankRot",{-0.025, "-0.06+0.33"},1},{"HorizonBankRot",{0.025, "-0.06+0.33"},1},{"HorizonBankRot",{0.025, "-0.08+0.33"},1},{"HorizonBankRot",{-0.025, "-0.08+0.33"},1}}};
                };//Rectangle
            }; // Draw
        };//end
