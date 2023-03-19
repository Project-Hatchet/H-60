#define PCAS_TARGET_SYMBOL_SIZE 0.015
#define BLACK_WHITE_LINE(STARTDIR,STARTDIST,ENDDIR,ENDDIST,CLASS) \
    class CLASS##_WRAP { \
        color[]={0,0,0,1}; \
        class CLASS { \
            type="line"; \
            width = 8; \
            points[] ={ \
                {STARTDIST, 1, STARTDIR, 1}, \
                {ENDDIST, 1, ENDDIR, 1} \
            }; \
        }; \
        class CLASS##_white { \
            color[]={1,1,1,1}; \
            class Ingress_Line_white { \
                type="line"; \
                width = 4; \
                points[] ={ \
                    {STARTDIST, 1, STARTDIR, 1}, \
                    {ENDDIST, 1, ENDDIR, 1} \
                }; \
            }; \
        }; \
    };

#define BLACK_WHITE_LINE_RELEND(STARTDIR,STARTDIST,ENDDIR,ENDDIST,CLASS) \
    class CLASS##_WRAP { \
        color[]={0,0,0,1}; \
        class CLASS { \
            type="line"; \
            width = 8; \
            points[] ={ \
                {STARTDIST, 1, STARTDIR, 1}, \
                {STARTDIST, 1, STARTDIR, 1, {ENDDIR, 0, 0.25}, 1} \
            }; \
        }; \
        class CLASS##_white { \
            color[]={1,1,1,1}; \
            class Ingress_Line_white { \
                type="line"; \
                width = 4; \
                points[] ={ \
                    {STARTDIST, 1, STARTDIR, 1}, \
                    {STARTDIST, 1, STARTDIR, 1, {ENDDIR, 0, 0.25}, 1} \
                }; \
            }; \
        }; \
    };

class PCAS_HAS_TARGET {
    condition = ((user39 > -1) * (user40 > -1));
    class PCAS_HAS_INGRESS {
        condition = ((user37 > -1) * (user38 > -1));
        BLACK_WHITE_LINE("TAC_PCAS_INGR_Dir","TAC_PCAS_INGR_Dist","TAC_PCAS_TGT_Dir","TAC_PCAS_TGT_Dist",INGR_LINE)
        class    IP_TEXT {
            type="text";
            source="static";
            text="IN";
            scale=1;
            sourceScale=1;
            align = "right";
            pos[]= {"TAC_PCAS_INGR_Dist", 1, "TAC_PCAS_INGR_Dir", 1,{0.04 - 0.02, 0.0}, 1};
            right[]= {"TAC_PCAS_INGR_Dist", 1, "TAC_PCAS_INGR_Dir", 1,{0.085 - 0.02, 0.00}, 1};
            down[]= {"TAC_PCAS_INGR_Dist", 1, "TAC_PCAS_INGR_Dir", 1,{0.04 - 0.02, 0.045}, 1};
        }; // IP_TEXT
        class PCAS_HAS_BPIP {
            condition = ((user37 > -1) * (user38 > -1));
            BLACK_WHITE_LINE("TAC_PCAS_INGR_Dir","TAC_PCAS_INGR_Dist","TAC_PCAS_IPBP_Dir","TAC_PCAS_IPBP_Dist",INGR_LINE)
            class BP_TEXT {
                type="text";
                source="static";
                text="BP";
                scale=1;
                sourceScale=1;
                align = "right";
                pos[]= {"TAC_PCAS_IPBP_Dist", 1, "TAC_PCAS_IPBP_Dir", 1,{0.04 - 0.02, 0.0}, 1};
                right[]= {"TAC_PCAS_IPBP_Dist", 1, "TAC_PCAS_IPBP_Dir", 1,{0.085 - 0.02, 0.00}, 1};
                down[]= {"TAC_PCAS_IPBP_Dist", 1, "TAC_PCAS_IPBP_Dir", 1,{0.04 - 0.02, 0.045}, 1};
            }; // BP_TEXT
        }; // PCAS_HAS_BPIP
    }; // PCAS_HAS_INGRESS

    class PCAS_HAS_EGRESS {
        condition = (user45 > -1);
        BLACK_WHITE_LINE("TAC_PCAS_TGT_Dir","TAC_PCAS_TGT_Dist","TAC_PCAS_EGR_Dir","TAC_PCAS_INGR_Dist",EGR_LINE)
        class    IP_TEXT {
            type="text";
            source="static";
            text="OUT";
            scale=1;
            sourceScale=1;
            align = "right";
            pos[]= {"TAC_PCAS_INGR_Dist", 1, "TAC_PCAS_EGR_Dir", 1,{0.04 - 0.02, 0.0}, 1};
            right[]= {"TAC_PCAS_INGR_Dist", 1, "TAC_PCAS_EGR_Dir", 1,{0.085 - 0.02, 0.00}, 1};
            down[]= {"TAC_PCAS_INGR_Dist", 1, "TAC_PCAS_EGR_Dir", 1,{0.04 - 0.02, 0.045}, 1};
        }; // IP_TEXT
    }; // PCAS_HAS_EGRESS
    class PCAS_HAS_FAH {
        condition = ((user43 > -1) * (user44 > -1));
        class TEST_FAH_LINE_WRAP {
            BLACK_WHITE_LINE_RELEND("TAC_PCAS_TGT_Dir","TAC_PCAS_TGT_Dist","TAC_PCAS_FAH1_Dir","TAC_PCAS_INGR_Dist",FAH_1_LINE)
            BLACK_WHITE_LINE_RELEND("TAC_PCAS_TGT_Dir","TAC_PCAS_TGT_Dist","TAC_PCAS_FAH2_Dir","TAC_PCAS_INGR_Dist",FAH_2_LINE)
        };
    }; // PCAS_HAS_FAH
    color[] = {0.7,0,0,1};
  class TargetDiamond {
    type        = "polygon";
    points[] ={
      {
        {"TAC_PCAS_TGT_DIST", 1, "TAC_PCAS_TGT_Dir", 1, {0, PCAS_TARGET_SYMBOL_SIZE},1},
        {"TAC_PCAS_TGT_DIST", 1, "TAC_PCAS_TGT_Dir", 1, {PCAS_TARGET_SYMBOL_SIZE, 0},1},
        {"TAC_PCAS_TGT_DIST", 1, "TAC_PCAS_TGT_Dir", 1, {0, -PCAS_TARGET_SYMBOL_SIZE},1},
        {"TAC_PCAS_TGT_DIST", 1, "TAC_PCAS_TGT_Dir", 1, {-PCAS_TARGET_SYMBOL_SIZE, 0},1}
      }
    }; // points
  }; // TargetDiamond
}; // PCAS_HAS_TARGET

class PCAS_HAS_BPIP {
    condition = ((user37 > -1) * (user38 > -1));
    color[] = {0,0,0.7,1};
  class BPIPTRIANGLE {
    type        = "polygon";
    points[] ={
      {
        {"TAC_PCAS_IPBP_DIST", 1, "TAC_PCAS_IPBP_Dir", 1, {-PCAS_TARGET_SYMBOL_SIZE, 0.01},1},
        {"TAC_PCAS_IPBP_DIST", 1, "TAC_PCAS_IPBP_Dir", 1, {0, -PCAS_TARGET_SYMBOL_SIZE},1},
        {"TAC_PCAS_IPBP_DIST", 1, "TAC_PCAS_IPBP_Dir", 1, {PCAS_TARGET_SYMBOL_SIZE, 0.01},1}
      }
    }; // points
  }; // BPIPTRIANGLE
}; // PCAS_HAS_BP
