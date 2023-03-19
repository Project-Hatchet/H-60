#define YMOD (1/0.75)
#define YMIN 0.25*(YMOD/2)

class TAC_CENTER {
    type="linear";
  source="pylonammo";
  sourceIndex=4;
  sourceScale=1;
  min=0;
  max=1;
    minPos[]={0.5,0.7};
    maxPos[]={0.5,0.5};
};
class TAC_OFFSET_CENTER
{
    type = "fixed";
    pos[]={0.5,0.5};
};
class TAC_HeadingRotation {
  type="rotational";
  source="heading";
  sourceScale = 1;
  center[] = {0,0};
  min = "-360";
  max = "360";
  minAngle = 360;
  maxAngle = -360;
  aspectRatio = 1/0.725;
};
class TAC_North {
  type="rotational";
  source="heading";
  sourceScale = 1;
  center[] = {BEZEL_XB2,BEZEL_Y5+0.1};
  min = "0";
  max = "360";
  minAngle = 0;
  maxAngle = -360;
  aspectRatio = 1/0.725;
};
class TAC_HeadingRotationHeli {
  type="rotational";
  source="heading";
  sourceScale = 1;
  center[] = {0,0};
  min = "-360";
  max = "360";
  minAngle = -360;
  maxAngle = 360;
  aspectRatio = 1/0.725;
};
class TAC_SELF_DIR {
    type="linear";
  source="user";
  sourceIndex=27;
  sourceScale=1;
  min=-30;
  max= 30;
  minPos[]={0.5-15, 0};
  maxPos[]={0.5+15, 0};
};
class TAC_SELF_DIST {
    type="linear";
  source="user";
  sourceIndex=28;
  sourceScale=1;
  min=-30;
  max= 30;
  minPos[]={0,0.5-(15*1.333)};
  maxPos[]={0,0.5+(15*1.333)};
};
class TAC_WP1_Dir {
    type="linear";
  source="user";
  sourceIndex=2;
  sourceScale=1;
  min=-30;
  max= 30;
  minPos[]={0.0-15, 0};
  maxPos[]={0.0+15, 0};
};
class TAC_WP1_DIST {
    type="linear";
  source="user";
  sourceIndex=3;
  sourceScale=1;
  min=-30;
  max= 30;
  minPos[]={0,0.0-(15*1.333)};
  maxPos[]={0,0.0+(15*1.333)};
};

class TAC_WP2_Dir: TAC_WP1_Dir {
  source="user";
  sourceIndex=4;
};
class TAC_WP2_DIST: TAC_WP1_DIST {
  source="user";
  sourceIndex=5;
};

class TAC_WP3_Dir: TAC_WP1_Dir {
  source="user";
  sourceIndex=6;
};
class TAC_WP3_DIST: TAC_WP1_DIST {
  source="user";
  sourceIndex=7;
};

class TAC_WP4_Dir: TAC_WP1_Dir {
  source="user";
  sourceIndex=8;
};
class TAC_WP4_DIST: TAC_WP1_DIST {
  source="user";
  sourceIndex=9;
};

class TAC_WP5_Dir: TAC_WP1_Dir {
  source="user";
  sourceIndex=33;
};
class TAC_WP5_DIST: TAC_WP1_DIST {
  source="user";
  sourceIndex=34;
};

class TAC_WP6_Dir: TAC_WP1_Dir {
  source="user";
  sourceIndex=35;
};
class TAC_WP6_DIST: TAC_WP1_DIST {
  source="user";
  sourceIndex=36;
};
class TAC_TGP_Dir: TAC_WP1_Dir {
  source="user";
  sourceIndex=10;
};
class TAC_TGP_DIST: TAC_WP1_DIST {
  source="user";
  sourceIndex=11;
};
class TAC_JVMF_Dir: TAC_WP1_Dir {
  source="user";
  sourceIndex=43;
};
class TAC_JVMF_DIST: TAC_WP1_DIST {
  source="user";
  sourceIndex=44;
};
class BFT_CENTER
{
    type  = fixed;
    pos[]  = {0.5,0.5};
};
class TAC_PCAS_IPBP_Dir: TAC_WP1_Dir {  sourceIndex=37; };
class TAC_PCAS_IPBP_Dist: TAC_WP1_Dist {  sourceIndex=38; };
class TAC_PCAS_TGT_Dir: TAC_WP1_Dir {  sourceIndex=39; };
class TAC_PCAS_TGT_Dist: TAC_WP1_Dist {  sourceIndex=40; };
class TAC_PCAS_INGR_Dir: TAC_WP1_Dir {  sourceIndex=41; };
class TAC_PCAS_INGR_Dist: TAC_WP1_Dist {  sourceIndex=42; };

class TAC_PCAS_INGR_DirRel: TAC_WP1_Dir {
    center[] = {0,0};
    sourceIndex=41;
};

class TAC_PCAS_FAH1_Dir: TAC_WP1_Dir {
    center[] = {0,0};
    sourceIndex=43;
};
class TAC_PCAS_FAH2_Dir: TAC_WP1_Dir {
    center[] = {0,0};
    sourceIndex=44;
};

class TAC_PCAS_EGR_Dir: TAC_WP1_Dir {  sourceIndex=45; };

class TAC_PCAS_FIXED_LINE
{
    type  = fixed;
    pos[]  = {0,0.25};
};

class TAC_PCAS_OFFCENTER
{
    type  = fixed;
    pos[]  = {-0.5,-0.5};
};
class TAC_CURSOR_X {
    type="linear";
  source="user";
  sourceIndex=29;
  sourceScale=1;
  min=0;
  max=1;
  minPos[]={0,0};
  maxPos[]={1,0};
};
class TAC_CURSOR_Y {
    type="linear";
  source="user";
  sourceIndex=30;
  sourceScale=1;
  min=0;
  max=1;
  minPos[]={0,0};
  maxPos[]={0,1};
};
