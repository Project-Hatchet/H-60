class LEFT_POS
{
	type="linear";
	source="user";
	sourceIndex=45;
	sourceScale=1;
	min=0;
	max=1;
	minPos[]={0.03,0};
	maxPos[]={0.03,1};
};
class RIGHT_POS: LEFT_POS
{
	sourceIndex=46;
	minPos[]={1-0.03,0};
	maxPos[]={1-0.03,1};
};
class BALL_X: LEFT_POS
{
	sourceIndex=47;
	minPos[]={0,0};
	maxPos[]={1,0};
};
class BALL_Y: LEFT_POS
{
	sourceIndex=48;
	minPos[]={0,0};
	maxPos[]={0,1};
};