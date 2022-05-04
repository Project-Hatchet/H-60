alpha = BACKGROUND_ALPHA;
class backgroundWrapper {
  color[] = common_black;
	class polygon {
		type        = "polygon";
		points[] ={
			{
				{{0, 0},1},
				{{1, 0},1},
				{{1, 1},1},
				{{0, 1},1}
			}
		};
	};
}; // backgroundWrapper

class HEADER_BARS_TOP {
  type="line";
  width = 3;
  lineType = 2;
  points[] ={
    {{0+0.1, 0.1},1},
    {{0+0.4, 0.1},1},{},
    {{1-0.1, 0.1},1},
    {{1-0.4, 0.1},1}
  };
}; // HEADER_BARS
TEXT_MID_SCALED(MAIN,0.5,0.08,"MAIN",0.04)
// TEXT_LEFT_SCALED(FRW_STATUS,0.1,0.12,"FRAMEWORK STATUS: ACTIVE",0.04)
// TEXT_RIGHT_SCALED(ACPOWERED,0.75,0.12,"AIRCRAFT: RUNNING",0.04)
TEXT_LEFT_SCALED_USERTEXT(FRW_STATUS,0.1,0.12,1,0.04)
TEXT_RIGHT_SCALED_USERTEXT(ACPOWERED,0.75,0.12,2,0.04)

class HEADER_BARS_BOTTOM {
  type="line";
  width = 3;
  lineType = 2;
  points[] ={
    {{0+0.1, 0.18},1},
    {{1-0.1, 0.18},1}
  };
}; // HEADER_BARS_BOTTOM


// TEXT_MID_SCALED(VHTYPE,0.5,0.20,"UH-60M",0.035)
TEXT_MID_SCALED(TITLE1,0.5,0.23,"INTEGRATED VEHICLE HEALTH",0.035)
TEXT_MID_SCALED(TITLE2,0.5,0.26,"MANAGEMENT SYSTEM",0.035)
TEXT_MID_SCALED(ACVERLBL,0.45,0.30,"AIRCRAFT VERSION: ",0.035)
#define VERSIONSTRING STR(VERSION)
TEXT_MID_SCALED(ACVER,0.63,0.30,VERSIONSTRING,0.035)
// TEXT_MID_SCALED(DATE,0.5,0.33,"DATE 2021/12/04 14:50Z",0.035)
TEXT_MID_SCALED_USERTEXT(VHTYPE,0.5,0.20,3,0.035)
TEXT_MID_SCALED_USERTEXT(DATE,0.5,0.33,4,0.035)


/*
private _modules = vehicle player getVariable "htf_modules";
_mods =_modules apply {(_x # 0) + (if (_x # 1) then [{"/ACT"},{"/STB"}])} joinString " | ";
[ 
_mods select [0,62], 
_mods select [62,62], 
_mods select [124,62] 
]

["engine/ACT | fd/ACT | jvmf/ACT | flir/STB | misc/ACT | cas/ACT"," | ui/ACT | aar/ACT | acre/STB | anvishud/STB | fms/ACT | mfd/","ACT | interaction/ACT"]
*/
TEXT_LEFT_SCALED(MODULES,0.1,0.6,"VEHICLE MODULES",0.035)
// TEXT_LEFT_SCALED(MODULES1,0.1,0.63,"engine/ACT | fd/ACT | jvmf/ACT | flir/STB | misc/ACT | cas/ACT",0.035)
// TEXT_LEFT_SCALED(MODULES2,0.1,0.66," | ui/ACT | aar/ACT | acre/STB | anvishud/STB | fms/ACT | mfd/",0.035)
// TEXT_LEFT_SCALED(MODULES3,0.1,0.69,"ACT | interaction/ACT",0.035)

TEXT_LEFT_SCALED_USERTEXT(MODULES1,0.1,0.63,5,0.035)
TEXT_LEFT_SCALED_USERTEXT(MODULES2,0.1,0.66,6,0.035)
TEXT_LEFT_SCALED_USERTEXT(MODULES3,0.1,0.69,7,0.035)

// TEXT_MID_SCALED(AFM,1-0.25,0.4,"ADVANCED FLIGHT MODEL",0.035)
// TEXT_MID_SCALED(CONFIG,1-0.25,0.43,"htf_DRIVER",0.035)
// TEXT_MID_SCALED(CONFIG1,0.25,0.4+(0.03*0),"Arma3 207",0.035)
// TEXT_MID_SCALED(CONFIG2,0.25,0.4+(0.03*1),"148579 Diag",0.035)
// TEXT_MID_SCALED(CONFIG3,0.25,0.4+(0.03*2),"Windows x64",0.035)
TEXT_MID_SCALED_USERTEXT(AFM,1-0.25,0.4,8,0.035)
TEXT_MID_SCALED_USERTEXT(CONFIG,1-0.25,0.43,9,0.035)
TEXT_MID_SCALED_USERTEXT(CONFIG1,0.25,0.4+(0.03*0),10,0.035)
TEXT_MID_SCALED_USERTEXT(CONFIG2,0.25,0.4+(0.03*1),11,0.035)
TEXT_MID_SCALED_USERTEXT(CONFIG3,0.25,0.4+(0.03*2),12,0.035)

// TEXT_MID_SCALED(CONFIG4,1-0.5,0.4+(0.03*0),"tempMissionSP",0.035)
// TEXT_MID_SCALED(CONFIG5,1-0.5,0.4+(0.03*1),"1 players",0.035)
// TEXT_MID_SCALED(CONFIG6,1-0.5,0.4+(0.03*2),"VR SP",0.035)
// TEXT_MID_SCALED(CONFIG7,1-0.5,0.4+(0.03*3),"58.19",0.035)
TEXT_MID_SCALED_USERTEXT(CONFIG4,1-0.5,0.4+(0.03*0),13,0.035)
TEXT_MID_SCALED_USERTEXT(CONFIG5,1-0.5,0.4+(0.03*1),14,0.035)
TEXT_MID_SCALED_USERTEXT(CONFIG6,1-0.5,0.4+(0.03*2),15,0.035)
TEXT_MID_SCALED_USERTEXT(CONFIG7,1-0.5,0.4+(0.03*3),16,0.035)


TEXT_LEFT_SCALED(LEFT1,0.01,0.18,"END OF",0.035)
TEXT_LEFT_SCALED(LEFT2,0.01,0.18+0.03,"OP",0.035)

TEXT_LEFT_SCALED(LEFT3,0.01,0.45,"DATA",0.035)
TEXT_LEFT_SCALED(LEFT4,0.01,0.45+0.03,"RECVRY",0.035)

TEXT_LEFT_SCALED(LEFT5,0.01,0.87,"RTN",0.035)


TEXT_RIGHT_SCALED(RIGHT1,1-0.05,0.33,"TOGGLE",0.035)

TEXT_RIGHT_SCALED(RIGHT2,1-0.05,0.84,"ADMIN",0.035)
TEXT_RIGHT_SCALED(RIGHT3,1-0.05,0.87,"LOGIN",0.035)

/*
private _mods = getLoadedModsInfo apply {((_x # 1) regexReplace ["\W",""]) select [0,15]} joinString "|";
[
_mods select [0,62],
_mods select [62,62],
_mods select [124,62]
]

[
"ACECompatRHSAFR|ACECompatRHSGRE|ACECompatRHSUSA|vtx|HatchetFra",
"mewor|RHSGREF|ace|RHSAFRF|RHSUSAF|CBA_A3|aow|enoch|tank|tacops",
"|orange|argo|jets|expansion|mark|heli|kart|curator|A3"]
*/

// TEXT_LEFT_SCALED(MODS,0.1,0.75,"ACECompatRHSAFR|ACECompatRHSGRE|ACECompatRHSUSA|vtx|HatchetFra",0.035)
// TEXT_LEFT_SCALED(MODS2,0.1,0.78,"mewor|RHSGREF|ace|RHSAFRF|RHSUSAF|CBA_A3|aow|enoch|tank|tacops",0.035)
// TEXT_LEFT_SCALED(MODS3,0.1,0.81,"|orange|argo|jets|expansion|mark|heli|kart|curator|A3",0.035)
TEXT_LEFT_SCALED_USERTEXT(MODS,0.1,0.75,17,0.035)
TEXT_LEFT_SCALED_USERTEXT(MODS2,0.1,0.78,18,0.035)
TEXT_LEFT_SCALED_USERTEXT(MODS3,0.1,0.81,19,0.035)

TEXT_MID_SCALED(LOGIN,0.5,0.85,"TO LOG IN AS ADMINISTRATOR PRESS ADMIN LOGIN",0.035)
class BOTTOM_BAR {
  type="line";
  width = 3;
  lineType = 1;
  points[] ={
    {{0+0.1, 0.9},1},
    {{1-0.1, 0.9},1}
  };
}; // BOTTOM_BAR

TEXT_MID_SCALED(TOP1,0.15,0.01,"MAIN",0.035)
TEXT_MID_SCALED(TOP2,0.25,0.01,"MAINT",0.035)
TEXT_MID_SCALED(TOP3,0.35,0.01,"ADMIN",0.035)


#define BOTTOM_TEXT_Y 0.96
TEXT_LEFT_SMALL(B1,0.095,BOTTOM_TEXT_Y,"PFD")
TEXT_LEFT_SMALL(B2,0.2,BOTTOM_TEXT_Y,"ND")
TEXT_LEFT_SMALL(B3,0.325,BOTTOM_TEXT_Y,"EICAS")

TEXT_LEFT_SMALL(B6,0.75,BOTTOM_TEXT_Y,"IVHMS")
TEXT_LEFT_SMALL(B7,0.86,BOTTOM_TEXT_Y,"TAC")
TEXT_LEFT_SMALL(B8,0.98,BOTTOM_TEXT_Y,"JVMF")