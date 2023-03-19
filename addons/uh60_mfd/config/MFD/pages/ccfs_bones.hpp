class LEFT_POS
{
  type="linear";
  source="user";
  sourceIndex=2;
  sourceScale=1;
  min=0;
  max=1;
  minPos[]={0.03,0};
  maxPos[]={0.03,1};
};
class RIGHT_POS: LEFT_POS
{
  sourceIndex=3;
  minPos[]={1-0.03,0};
  maxPos[]={1-0.03,1};
};
class BALL_X: LEFT_POS
{
  sourceIndex=4;
  minPos[]={0,0};
  maxPos[]={1,0};
};
class BALL_Y: LEFT_POS
{
  sourceIndex=5;
  minPos[]={0,0};
  maxPos[]={0,1};
};