
class ND_CENTER
{
    type = "fixed";
    pos[]={0.4,0.5};
};

class ND_HeadingRotation {
	type="rotational";
	source="heading";
	sourceScale = 1;
	center[] = {0.4,0.5};
	min = "0";
	max = "360";
	minAngle = 360;
	maxAngle = 0;
	aspectRatio = 1/0.725;
};

class ND_WaypointDirection {
	type="rotational";
	source="user";
	sourceIndex=0;
	sourceScale = 1;
	center[] = {0,0};
	min = "0";
	max = "360";
	minAngle = 360;
	maxAngle = 0;
	aspectRatio = 1;
};

class ND_RALTRotation1 : ND_HeadingRotation {
	center[] = {0.87,0.15};
	source="altitudeAGL";
	sourceScale = 3.2808399;
	min = "0";
	max = "100";
	minAngle = -180;
	maxAngle = 0;
};
class ND_RALTRotation2 : ND_RALTRotation1 {
	source="altitudeAGL";
	min = "100";
	max = "400";
	minAngle = 0;
	maxAngle = 90;
};
class ND_RALTRotation3 : ND_RALTRotation2 {
	source="altitudeAGL";
	min = "400";
	max = "1000";
	minAngle = 90;
	maxAngle = 135;
};
class FD_ND_RALTRotation1 : ND_RALTRotation1 {
	source="user";
	sourceIndex=12;
	sourceScale = 1;
	min = "0";
	max = "100";
};
class FD_ND_RALTRotation2 : ND_RALTRotation2 {
	source="user";
	sourceIndex=12;
	sourceScale = 1;
};
class FD_ND_RALTRotation3 : ND_RALTRotation3 {
	source="user";
	sourceIndex=12;
	sourceScale = 1;
};

class ND_HeadingRotationWind : ND_HeadingRotation {
	minAngle = 360;
	maxAngle = 0;
	center[] = {0.1,0.18};
	aspectRatio = 1/0.725;
};
class ND_RotationWind : ND_HeadingRotationWind {
	center[] = {0,0};
	minAngle = 360;
	maxAngle = 0;
	source="windage";
	aspectRatio = 1;
};
class ND_WP1_Dir {
	type="rotational";
	source="user";
	sourceIndex=2;
	sourceScale = 1;
	center[] = {0.4,0.5};
	min = "-360";
	max = "360";
	minAngle = -360;
	maxAngle = 360;
	aspectRatio = 1/0.725;
};
class ND_WP1_DIST {
    type="linear";
	source="user";
	sourceIndex=3;
	sourceScale=1;
	min=0;
	max=1;
	minPos[]={0,0.5};
	maxPos[]={0,0};
};

class ND_WP2_Dir: ND_WP1_Dir {
	source="user";
	sourceIndex=4;
};
class ND_WP2_DIST: ND_WP1_DIST {
	source="user";
	sourceIndex=5;
};

class ND_WP3_Dir: ND_WP1_Dir {
	source="user";
	sourceIndex=6;
};
class ND_WP3_DIST: ND_WP1_DIST {
	source="user";
	sourceIndex=7;
};

class ND_WP4_Dir: ND_WP1_Dir {
	source="user";
	sourceIndex=8;
};
class ND_WP4_DIST: ND_WP1_DIST {
	source="user";
	sourceIndex=9;
};

class ND_WP5_Dir: ND_WP1_Dir {
	source="user";
	sourceIndex=33;
};
class ND_WP5_DIST: ND_WP1_DIST {
	source="user";
	sourceIndex=34;
};

class ND_WP6_Dir: ND_WP1_Dir {
	source="user";
	sourceIndex=35;
};
class ND_WP6_DIST: ND_WP1_DIST {
	source="user";
	sourceIndex=36;
};
class ND_TGP_Dir: ND_WP1_Dir {
	source="user";
	sourceIndex=10;
};
class ND_TGP_DIST: ND_WP1_DIST {
	source="user";
	sourceIndex=11;
};
class ND_LOC_Dir: ND_WP1_Dir {
	source="user";
	sourceIndex=41;
};
class ND_LOC_DIST: ND_WP1_DIST {
	source="user";
	sourceIndex=42;
};
class ND_JVMF_Dir: ND_WP1_Dir {
	source="user";
	sourceIndex=43;
};
class ND_JVMF_DIST: ND_WP1_DIST {
	source="user";
	sourceIndex=44;
};

class ND_WP_VEH_DIR {
	type="rotational";
	source="heading";
	sourceIndex=0;
	sourceScale = 1;
	center[] = {0,0};
	min = "0";
	max = "360";
	minAngle = 0;
	maxAngle = 360;
	aspectRatio = 1;
};
class ND_WP_DIR {
	type="rotational";
	source="user";
	sourceIndex=0;
	sourceScale = 1;
	center[] = {0.4,0.5};
	min = "0";
	max = "360";
	minAngle = 0;
	maxAngle = 360;
	aspectRatio = 1;
};
class ND_WP_DIST {
	type="linear";
	source="user";
	sourceIndex=1;
	sourceScale=1;
	min=0;
	max=100;
	minPos[]={0,-0.5};
	maxPos[]={0,0};
};
#define HSI_HVR_10KTS 0.04
class ND_HOVER_VEL_X {
	type="linear";
	source="user";
	sourceIndex=37;
	sourceScale=0.51444563338;
	min=-1;
	max=1;
	minPos[]={(HSI_HVR_10KTS*4),0};
	maxPos[]={-(HSI_HVR_10KTS*4),0};
};
class ND_HOVER_VEL_Y: ND_HOVER_VEL_X {
	source="user";
	sourceIndex=38;
	minPos[]={0,	-(HSI_HVR_10KTS*4)};
	maxPos[]={0,	(HSI_HVR_10KTS*4)};
};
