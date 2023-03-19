#define CARET_SCALE 1.1
class WaypointDirectionBase
{
  type="linear";
  source="user";
  sourceIndex=0;
  min=0;
  max=360;
  sourceScale=1;
  minPos[]={ CARET_SCALE,0};
  maxPos[]={-CARET_SCALE,0};
};

class WaypointDirectionCorrection
{
  type="linear";
  source="heading";
  min=0;
  max=360;
  sourceScale=1;
  minPos[]={-CARET_SCALE,0};
  maxPos[]={ CARET_SCALE,0};
};

class WaypointDirectionBaseInv
{
  type="linear";
  source="user";
  sourceIndex=0;
  min=0;
  max=360;
  sourceScale=1;
  minPos[]={ CARET_SCALE+CARET_SCALE,0};
  maxPos[]={-CARET_SCALE+CARET_SCALE,0};
};

class WaypointDirectionCorrectionInv
{
  type="linear";
  source="heading";
  min=0;
  max=360;
  sourceScale=1;
  minPos[]={-CARET_SCALE+CARET_SCALE,0};
  maxPos[]={ CARET_SCALE+CARET_SCALE,0};
};

class WaypointDirectionLimits
{
  type = "limit";
  limits[] = {0.1,0,0.9,1};
};