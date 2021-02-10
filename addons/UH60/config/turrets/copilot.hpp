class CopilotTurret: CopilotTurret
{
	CanEject=0;
	gunnerAction=UH60_Pilot;
	gunnerInAction=UH60_Pilot;
	gunnerRightHandAnimName="Cyclic_left";
	gunnerLeftHandAnimName="Collective_left";
	gunnerLeftLegAnimName="Pedal_Left_CP";
	gunnerRightLegAnimName="Pedal_Right_CP";
	memoryPointsGetInGunner="pos codriver";
	memoryPointsGetInGunnerDir="pos codriver dir";

	gunnerGetInAction="copilot_Heli_Light_02_Enter";
	gunnerGetOutAction="copilot_Heli_Light_02_Exit";
	selectionFireAnim="";

	preciseGetInOut=1;
	GunnerDoor="DoorL";
	proxyIndex=13;
	commanding=-1;
	class ViewGunner: ViewPilot
	{
		COPILOTVIEW
	};
	class Components
	{
	};
	class Hitpoints
	{
	};
};
