class Door_LF
{
	type = "rotation";
	source = "Door_LF";
	memory = "true";
	minValue = 0;
	maxValue = 1;
	angle0 = 0;
	angle1 = "rad -70";
	selection = "cockpitdoor_left";
	axis = "axis_cockpitdoor_left";
};
class Door_RF
{
	type = "rotation";
	source = "Door_RF";
	memory = "true";
	minValue = 0;
	maxValue = 1;
	angle0 = 0;
	angle1 = "rad 70";
	selection = "cockpitdoor_right";
	axis = "axis_cockpitdoor_right";
};
class Door_LF_Hide
{
	type = "hide";
	source = "Cockpitdoors_Hide";
	selection = "cockpitdoor_left";
	minValue = 0;
	maxValue = 1;
	hideValue = 0.001;
};
class Door_RF_Hide
{
	type = "hide";
	source = "Cockpitdoors_Hide";
	selection = "cockpitdoor_right";
	minValue = 0;
	maxValue = 1;
	hideValue = 0.001;
};
class Cockpitdoors_Hinges_Hide
{
	type = "hide";
	source = "Cockpitdoors_Hide";
	selection = "cockpitdoors_hinges";
	minValue = 0;
	maxValue = 1;
	hideValue = 0.001;
};