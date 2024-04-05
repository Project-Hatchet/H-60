// -APU
class vtx_APUSoundLoop_Ext_SoundSet: vtx_Standard_External_Base
{
	soundshaders[] = 
	{
		"vtx_APUSoundLoop_Ext_SoundShader"
	};
	volumefactor=0.25;
};

//External
class vtx_Rotor_Distance_SoundSet: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_Rotor_Distance_SoundShader"
	};
	volumeFactor=0.5;
	distancefilter="vtx_Distant_Engine_Filter";
	sound3dprocessingtype="vtx_Distant_3DProcessor";
	doppler=1;
};
class vtx_Engine_Distance_SoundSet: vtx_Rotor_Distance_SoundSet
{
	soundshaders[]=
	{
		"vtx_Engine_Distance_SoundShader"
	};
	volumeFactor=0.5;
	shape="vtx_Front_Shape";
	doppler=1;
};
class vtx_EngineExt_SoundSet: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_EngineExt_SoundShader"
	};
	volumefactor=1.25;
	volumecurve="vtx_Tail_Rotor_Curve";
	shape="vtx_Rear_Shape";
	sound3dprocessingtype="vtx_TailRotor_3DProcessor";
	posoffset[]={0,0,-10};
	doppler=1;
};
class vtx_RotorExt_SoundSet: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_RotorExt_SoundShader"
	};
	volumeFactor=0.75;
};
class vtx_Turbine_Ext_SoundSet: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_Turbine_Ext_SoundShader"
	};
	volumeFactor=1;
	shape="vtx_Turbine_Shape";
	sound3dprocessingtype="vtx_Turbine_3DProcessor";
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// -APU
class vtx_ApuSoundLoop_Int_Soundet: vtx_Internal_Base
{
	soundshaders[] = 
	{
		"vtx_ApuSoundLoop_Int_SoundShader"
	};
	volumefactor=vtx_Vol_Multi_Int(0.35);
};

//Internal
class vtx_EngineInt_SoundSet: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_EngineInt_SoundShader"
	};
	volumefactor=vtx_Vol_Multi_Int(0.8);
};
class vtx_RotorInt_SoundSet: vtx_EngineInt_SoundSet
{
	soundshaders[]=
	{
		"vtx_RotorInt_SoundShader"
	};
};
class vtx_Engine_Transport_SoundSet_Base: vtx_EngineInt_SoundSet
{
	soundshaders[] = 
	{
		"vtx_Engine_Transport_SoundShader_Base"
	};
};