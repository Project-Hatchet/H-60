TEXT_FMS_C(HEADING_DIR,0.5,0)
    source = "heading";
    sourceScale = 1;
    text = "";
}; // TEST_TEXT
class HeadingIndicatorBox
{
    type = "line";
    width = 4;
    points[] = {
        {"HUDCenter", {-0.045, -0.445}, 1},
        {"HUDCenter", {-0.045, -0.5}, 1},
        {"HUDCenter", {0.045, -0.5}, 1},
        {"HUDCenter", {0.045, -0.445}, 1},
        {"HUDCenter", {-0.045, -0.445}, 1}
    };
};
class HEADINGTAPE_DCLT {
    condition=COND_FULL_ONLY;
    class HeadingScale
    {
        type = "scale";
        NeverEatSeaWeed = 1;
        horizontal = 1;
        source = "heading";
        sourceScale = 1;
        width = 5;
        top = 0.1;
        center = 0.5;
        bottom = 0.9;
        lineXleft = 0.105;
        lineYright = 0.115;
        lineXleftMajor = 0.095;
        lineYrightMajor = 0.115;
        majorLineEach = 5;
        numberEach = 5;
        step = "18 / 9";
        stepSize = "(0.70 - 0.3) / 15";
        align = "center";
        scale = 1;
        pos[] = {0.096, 0.0546};
        right[] = {0.143, 0.0546};
        down[] = {0.096, 0.093};
    };
    class HeadingIndicatorArrow
    {
        type = "polygon";
        points[] = {{{"HUDCenter", {-0.015, -0.445}, 1}, {"HUDCenter", {0, -0.435}, 1}, {"HUDCenter", {0.015, -0.445}, 1}}};
    };
    class altitude_caret {
        type="line";
        width = 3;
        points[] ={
            {"AltitudeEdge", {-0.015, -0.015}, 1},
            {"AltitudeEdge", {0.02, 0}, 1},
            {"AltitudeEdge", {-0.015, 0.015}, 1}
        }; // points
    }; // altitude_caret
    class altitude_AP_caret {
        color[] = common_purple;
        condition="simulRTD";
        class altitude_caret {
            type="line";
            width = 3;
            points[] ={
                {"RALT_AP", {-0.015, -0.015}, 1},
                {"RALT_AP", {0.02, 0}, 1},
                {"RALT_AP", {-0.015, 0.015}, 1}
            }; // points
        }; // altitude_caret
    };
    #define ALT_INTERVAL 0.03
    LINE(ALT_CARET_0,5,0.97,0.5+(ALT_INTERVAL*0),1,0.5+(ALT_INTERVAL*0))
    LINE(ALT_CARET_1,5,0.98,0.5+(ALT_INTERVAL*1),1,0.5+(ALT_INTERVAL*1))
    LINE(ALT_CARET_2,5,0.98,0.5+(ALT_INTERVAL*2),1,0.5+(ALT_INTERVAL*2))
    LINE(ALT_CARET_3,5,0.98,0.5+(ALT_INTERVAL*3),1,0.5+(ALT_INTERVAL*3))
    LINE(ALT_CARET_4,5,0.98,0.5+(ALT_INTERVAL*4),1,0.5+(ALT_INTERVAL*4))
    LINE(ALT_CARET_5,5,0.97,0.5+(ALT_INTERVAL*5),1,0.5+(ALT_INTERVAL*5))
    LINE(ALT_CARET_6,5,0.98,0.5+(ALT_INTERVAL*6),1,0.5+(ALT_INTERVAL*6))
    LINE(ALT_CARET_7,5,0.98,0.5+(ALT_INTERVAL*7),1,0.5+(ALT_INTERVAL*7))
    LINE(ALT_CARET_8,5,0.98,0.5+(ALT_INTERVAL*8),1,0.5+(ALT_INTERVAL*8))
    LINE(ALT_CARET_9,5,0.98,0.5+(ALT_INTERVAL*9),1,0.5+(ALT_INTERVAL*9))
    LINE(ALT_CARET_10,5,0.97,0.5+(ALT_INTERVAL*10),1,0.5+(ALT_INTERVAL*10))
    LINE(ALT_CARET_TOP,5,0.97,1.5,1,1.5)
    LINE(ALT_CARET_MID,5,0.97,1.5,1,1.5)
    LINE(ALT_CARET_06,5,0.97,1.6,1,1.6)
    LINE(ALT_CARET_07,5,0.97,1.7,1,1.7)
    LINE(ALT_CARET_BOTTOM,5,0.97,1.8,1,1.8)

    class HEADINGTAPE_METRIC {
        condition = COND_METRIC;
        class altitude_caret_label {
            type="text";
            source="altitudeAGL";
            sourceIndex=7;
            scale=1.5;
            sourceScale=1;
            align = "left";
            text="0";
            pos[]= {"AltitudeEdge", 1,{0.04 - 0.06, 0.0 - 0.02}, 1};
            right[]= {"AltitudeEdge", 1,{0.085 - 0.06, 0.0 - 0.02}, 1};
            down[]= {"AltitudeEdge", 1,{0.04 - 0.06, 0.045 - 0.02}, 1};
        };
    };
    class HEADINGTAPE_IMPERIAL {
        condition = COND_IMPERIAL;
        class altitude_caret_label {
            type="text";
            source="altitudeAGL";
            sourceIndex=7;
            scale=1.5;
            sourceScale=3.28084;
            align = "left";
            text="0";
            pos[]= {"AltitudeEdge", 1,{0.04 - 0.06, 0.0 - 0.02}, 1};
            right[]= {"AltitudeEdge", 1,{0.085 - 0.06, 0.0 - 0.02}, 1};
            down[]= {"AltitudeEdge", 1,{0.04 - 0.06, 0.045 - 0.02}, 1};
        };
    };

    class WPDir_Caret
    {
        condition="WPvalid";
        class WPCaret
        {
            type="line";
            width=4;
            points[]=
            {
                {"WP_DIR_BONE",1,"WP_DIR_LIMITS",1,{-0.010, 0.015},1},
                {"WP_DIR_BONE",1,"WP_DIR_LIMITS",1,{ 0.000, 0.000},1},
                {"WP_DIR_BONE",1,"WP_DIR_LIMITS",1,{ 0.010, 0.015},1}
            };					
        };				
    };
};