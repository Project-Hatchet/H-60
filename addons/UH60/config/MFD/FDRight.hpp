class FDRight
{
	topLeft="FDRight_LT";
	topRight="FDRight_RT";
	bottomLeft="FDRight_LD";
	borderLeft=0;
	borderRight=0;
	borderTop=0;
	borderBottom=0;
	color[]=common_green;
	enableParallax=0;
	font="VTX_UH60M_Font";
	class material
	{
	 ambient[] = {0, 1, 0, 1};
	 diffuse[] = {0, 1, 0, 1};
	 emissive[] = {0, 100, 0, 1};
	};
	class Bones
	{

	}; // Bones
	class Draw
	{
		//size: 0.024,    0.075
		#define TEXT_FD(CLASS,X,Y) \
	        class CLASS { \
	            type = "text"; \
	            align = "center"; \
	            scale = 1; \
	            pos[] = {{X-0.002, Y-0.004}, 1}; \
	            right[] = {{X + 0.026, Y-0.004}, 1}; \
	            down[] = {{X-0.002, Y + 0.079}, 1};
//static
		TEXT_FD(LOC_Text,0.065,0.14)
			source = "static";
			text = "FMS";
		};
		TEXT_FD(GS_Text,0.166,0.14)
			source = "static";
			text = "GS";
		};
		TEXT_FD(GO_Text,0.065,0.56)
			source = "static";
			text = "GO";
		};
		TEXT_FD(ARND_Text,0.065,0.62)
			source = "static";
			text = "ARND";
		};
		TEXT_FD(DECL_Text,0.166,0.59)
			source = "static";
			text = "DECL";
		};
		TEXT_FD(RALT_Text,0.27,0.08)
			source = "static";
			text="RALT";
		};

		TEXT_FD(ALTP_Text,0.373,0.08)
			source = "static";
			text="ALTP";
		};

		TEXT_FD(ALT_Text,0.475,0.08)
			source = "static";
			text="ALT";
		};

		TEXT_FD(IAS_Text,0.582,0.08)
		source = "static";
		text="IAS";
		};

		TEXT_FD(HDG_Text,0.687,0.08)
		source = "static";
		text="HDG";
		};

		TEXT_FD(VS_Text,0.79,0.08)
			source = "static";
			text="VS";
		};
		TEXT_FD(CPLD_Text,0.89,0.08)
			source = "static";
			text="CPLD";
		};
		TEXT_FD(HVR_Text,0.79,0.545)
			source = "static";
			text="HVR";
		};
		TEXT_FD(Dash_Text,0.89,0.545)
			source = "static";
			text="-";
		};





//values
		TEXT_FD(RALT_Value,0.27,0.20)
			source = "user";
			sourceIndex=12;
			sourceScale=1;
		};

		TEXT_FD(ALTP_Value,0.373,0.20)
			source = "user";
			sourceIndex=13;
			sourceScale=1;
		};

		TEXT_FD(ALT_Value,0.475,0.20)
			source = "user";
			sourceIndex=14;
			sourceScale=1;
		};

		TEXT_FD(IAS_Value,0.582,0.20)
			source = "user";
			sourceIndex=45;
			sourceScale=1;
		};

		TEXT_FD(HDG_Value,0.687,0.20)
			source = "user";
			sourceIndex=46;
			sourceScale=1;
		};

		TEXT_FD(VS_Value,0.79,0.20)
			source = "user";
			sourceIndex=17;
			sourceScale=1;
		};

	};	//Draw
};
