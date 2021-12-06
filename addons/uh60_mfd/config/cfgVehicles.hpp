class CfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F {
        class vxf_driver;
        class vxf_copilot;
    }; // Helicopter_Base_H
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class vxf_driver: vxf_driver {
            class interaction;
            class modules;
        }; // vxf_driver
        class vxf_copilot: vxf_copilot {
            class interaction;
            class modules;
        }; // vxf_copilot
        class MFD;
    }; // Heli_Transport_01_base_F
    class vtx_H60_base: Heli_Transport_01_base_F {
        class vxf_driver: vxf_driver {
            class modules: modules {
                class mfd {
                    startOnEnter = 1;
                }; // MFD
            }; // modules
            class interaction: interaction {
                class MFD_3 {
                    #define MFD_PAGE_INDEX MFD_3_PAGE_INDEX
                    #define MFD_1 B_MFD3_1
                    #define MFD_2 B_MFD3_2
                    #define MFD_3 B_MFD3_3
                    #define MFD_4 B_MFD3_4
                    #define MFD_5 B_MFD3_5
                    #define MFD_6 B_MFD3_6

                    #define MFD_7 B_MFD3_7
                    #define MFD_8 B_MFD3_8
                    #define MFD_9 B_MFD3_9
                    #define MFD_10 B_MFD3_10
                    #define MFD_11 B_MFD3_11
                    #define MFD_12 B_MFD3_12

                    #define MFD_13 B_MFD3_13
                    #define MFD_14 B_MFD3_14
                    #define MFD_15 B_MFD3_15
                    #define MFD_16 B_MFD3_16
                    #define MFD_17 B_MFD3_17
                    #define MFD_18 B_MFD3_18

                    #define MFD_19 B_MFD3_19
                    #define MFD_20 B_MFD3_20
                    #define MFD_21 B_MFD3_21
                    #define MFD_22 B_MFD3_22
                    #define MFD_23 B_MFD3_23
                    #define MFD_24 B_MFD3_24
                    #include "interaction.hpp"
                }; // MFD3
                class MFD_4 {
                    #undef MFD_PAGE_INDEX
                    #undef MFD_1
                    #undef MFD_2
                    #undef MFD_3
                    #undef MFD_4
                    #undef MFD_5
                    #undef MFD_6

                    #undef MFD_7
                    #undef MFD_8
                    #undef MFD_9
                    #undef MFD_10
                    #undef MFD_11
                    #undef MFD_12

                    #undef MFD_13
                    #undef MFD_14
                    #undef MFD_15
                    #undef MFD_16
                    #undef MFD_17
                    #undef MFD_18

                    #undef MFD_19
                    #undef MFD_20
                    #undef MFD_21
                    #undef MFD_22
                    #undef MFD_23
                    #undef MFD_24

                    #define MFD_PAGE_INDEX MFD_4_PAGE_INDEX
                    #define MFD_1 B_MFD4_1
                    #define MFD_2 B_MFD4_2
                    #define MFD_3 B_MFD4_3
                    #define MFD_4 B_MFD4_4
                    #define MFD_5 B_MFD4_5
                    #define MFD_6 B_MFD4_6

                    #define MFD_7 B_MFD4_7
                    #define MFD_8 B_MFD4_8
                    #define MFD_9 B_MFD4_9
                    #define MFD_10 B_MFD4_10
                    #define MFD_11 B_MFD4_11
                    #define MFD_12 B_MFD4_12

                    #define MFD_13 B_MFD4_13
                    #define MFD_14 B_MFD4_14
                    #define MFD_15 B_MFD4_15
                    #define MFD_16 B_MFD4_16
                    #define MFD_17 B_MFD4_17
                    #define MFD_18 B_MFD4_18

                    #define MFD_19 B_MFD4_19
                    #define MFD_20 B_MFD4_20
                    #define MFD_21 B_MFD4_21
                    #define MFD_22 B_MFD4_22
                    #define MFD_23 B_MFD4_23
                    #define MFD_24 B_MFD4_24
                    #include "interaction.hpp"
                }; // MFD4
            }; // interaction
        }; // vxf_driver
        class vxf_copilot: vxf_copilot {
            class modules: modules {
                class mfd {
                    startOnEnter = 1;
                }; // MFD
            }; // modules
            class interaction: interaction {
                class MFD_1_Interaction {
                    #undef MFD_PAGE_INDEX
                    #undef MFD_1
                    #undef MFD_2
                    #undef MFD_3
                    #undef MFD_4
                    #undef MFD_5
                    #undef MFD_6

                    #undef MFD_7
                    #undef MFD_8
                    #undef MFD_9
                    #undef MFD_10
                    #undef MFD_11
                    #undef MFD_12

                    #undef MFD_13
                    #undef MFD_14
                    #undef MFD_15
                    #undef MFD_16
                    #undef MFD_17
                    #undef MFD_18

                    #undef MFD_19
                    #undef MFD_20
                    #undef MFD_21
                    #undef MFD_22
                    #undef MFD_23
                    #undef MFD_24

                    #define MFD_PAGE_INDEX MFD_1_PAGE_INDEX
                    #define MFD_1 B_MFD1_1
                    #define MFD_2 B_MFD1_2
                    #define MFD_3 B_MFD1_3
                    #define MFD_4 B_MFD1_4
                    #define MFD_5 B_MFD1_5
                    #define MFD_6 B_MFD1_6

                    #define MFD_7 B_MFD1_7
                    #define MFD_8 B_MFD1_8
                    #define MFD_9 B_MFD1_9
                    #define MFD_10 B_MFD1_10
                    #define MFD_11 B_MFD1_11
                    #define MFD_12 B_MFD1_12

                    #define MFD_13 B_MFD1_13
                    #define MFD_14 B_MFD1_14
                    #define MFD_15 B_MFD1_15
                    #define MFD_16 B_MFD1_16
                    #define MFD_17 B_MFD1_17
                    #define MFD_18 B_MFD1_18

                    #define MFD_19 B_MFD1_19
                    #define MFD_20 B_MFD1_20
                    #define MFD_21 B_MFD1_21
                    #define MFD_22 B_MFD1_22
                    #define MFD_23 B_MFD1_23
                    #define MFD_24 B_MFD1_24
                    #include "interaction.hpp"
                }; // MFD3
                class MFD_2_Interaction {
                    #undef MFD_PAGE_INDEX
                    #undef MFD_1
                    #undef MFD_2
                    #undef MFD_3
                    #undef MFD_4
                    #undef MFD_5
                    #undef MFD_6

                    #undef MFD_7
                    #undef MFD_8
                    #undef MFD_9
                    #undef MFD_10
                    #undef MFD_11
                    #undef MFD_12

                    #undef MFD_13
                    #undef MFD_14
                    #undef MFD_15
                    #undef MFD_16
                    #undef MFD_17
                    #undef MFD_18

                    #undef MFD_19
                    #undef MFD_20
                    #undef MFD_21
                    #undef MFD_22
                    #undef MFD_23
                    #undef MFD_24

                    #define MFD_PAGE_INDEX MFD_2_PAGE_INDEX
                    #define MFD_1 B_MFD2_1
                    #define MFD_2 B_MFD2_2
                    #define MFD_3 B_MFD2_3
                    #define MFD_4 B_MFD2_4
                    #define MFD_5 B_MFD2_5
                    #define MFD_6 B_MFD2_6

                    #define MFD_7 B_MFD2_7
                    #define MFD_8 B_MFD2_8
                    #define MFD_9 B_MFD2_9
                    #define MFD_10 B_MFD2_10
                    #define MFD_11 B_MFD2_11
                    #define MFD_12 B_MFD2_12

                    #define MFD_13 B_MFD2_13
                    #define MFD_14 B_MFD2_14
                    #define MFD_15 B_MFD2_15
                    #define MFD_16 B_MFD2_16
                    #define MFD_17 B_MFD2_17
                    #define MFD_18 B_MFD2_18

                    #define MFD_19 B_MFD2_19
                    #define MFD_20 B_MFD2_20
                    #define MFD_21 B_MFD2_21
                    #define MFD_22 B_MFD2_22
                    #define MFD_23 B_MFD2_23
                    #define MFD_24 B_MFD2_24
                    #include "interaction.hpp"
                }; // MFD4
            }; // interaction
        }; // vxf_copilot
        class MFD: MFD {
            #undef MFD_PAGE_INDEX
            #define MFD_PAGE_INDEX MFD_1_PAGE_INDEX
            class MFD_1
            {
            	topLeft="MFD1_LH";
            	topRight="MFD1_RH";
            	bottomLeft="MFD1_LD";
                #include "MFD\MFD.hpp"
            }; // MFD_1
            class MFD_1_CMWS
            {
                    topLeft="MFD1_LH";topRight="MFD1_RH"; bottomLeft="MFD1_LD";
                #include "MFD\pages\tac_cmws.hpp"
            }; // MFD_1
            class MFD_1_Monospace {
                topLeft="MFD1_LH";topRight="MFD1_RH"; bottomLeft="MFD1_LD";
                #include "MFD\pages\jvmf\jvmf_monospace.hpp"
            }; // MFD_1
            #undef MFD_PAGE_INDEX
            #define MFD_PAGE_INDEX MFD_2_PAGE_INDEX
            class MFD_2
            {
            	topLeft="MFD2_LH";
            	topRight="MFD2_RH";
            	bottomLeft="MFD2_LD";
                #include "MFD\MFD.hpp"
            }; // MFD_2
            class MFD_2_CMWS
            {
                topLeft="MFD2_LH"; topRight="MFD2_RH"; bottomLeft="MFD2_LD";
                #include "MFD\pages\tac_cmws.hpp"
            }; // MFD_2
            class MFD_2_Monospace {
                topLeft="MFD2_LH";topRight="MFD2_RH"; bottomLeft="MFD2_LD";
                #include "MFD\pages\jvmf\jvmf_monospace.hpp"
            }; // MFD_2
            #undef MFD_PAGE_INDEX
            #define MFD_PAGE_INDEX MFD_3_PAGE_INDEX
            class MFD_3
            {
            	topLeft="MFD3_LH";
            	topRight="MFD3_RH";
            	bottomLeft="MFD3_LD";
                #include "MFD\MFD.hpp"
            }; // MFD_3
            class MFD_3_CMWS
            {
                    topLeft="MFD3_LH";topRight="MFD3_RH";bottomLeft="MFD3_LD";
                    #include "MFD\pages\tac_cmws.hpp"
            }; // MFD_3
            class MFD_3_Monospace {
                topLeft="MFD3_LH";topRight="MFD3_RH"; bottomLeft="MFD3_LD";
                #include "MFD\pages\jvmf\jvmf_monospace.hpp"
            }; // MFD_3
            #undef MFD_PAGE_INDEX
            #define MFD_PAGE_INDEX MFD_4_PAGE_INDEX
            class MFD_4
            {
            	topLeft="MFD4_LH";
            	topRight="MFD4_RH";
            	bottomLeft="MFD4_LD";
                #include "MFD\MFD.hpp"
            }; // MFD_4
            class MFD_4_CMWS
            {
                    topLeft="MFD4_LH";topRight="MFD4_RH";bottomLeft="MFD4_LD";
                    #include "MFD\pages\tac_cmws.hpp"
            }; // MFD_4
            class MFD_4_Monospace {
                topLeft="MFD4_LH";topRight="MFD4_RH"; bottomLeft="MFD4_LD";
                #include "MFD\pages\jvmf\jvmf_monospace.hpp"
            }; // MFD_1
            class ESIS_BOOT
            {
                #include "MFD\ESIS_BOOT.hpp"
            };
        }; // MFD
    }; // vtx_H60_base
}; // CfgVehicles
