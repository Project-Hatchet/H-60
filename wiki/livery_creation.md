## Getting Started
In order to start making liveries you will need the [texture templates for the Hatchet H-60](https://github.com/Project-Hatchet/H-60/releases/tag/textures), 
a graphics editor that supports .psd files  (e.g. Photoshop or GIMP), [Arma 3 Tools](https://store.steampowered.com/app/233800/Arma_3_Tools/) and a text editor of your choice.

## File Structure
File structure example for the pbo:
```
\MODFOLDERNAME\
    \config.cpp
    \data\
        \reskintextures\
            \texture_1.paa
            \texture_2.paa
            \texture_3.paa
            \texture_4.paa
```

You will need to create one config file (with  **.cpp** as the file extension) with this code inside:
```sqf
class CfgVehicles
{
    class vtx_uh60M;
    class YOURCLASSNAME:vtx_uh60M
    {
        scope=2;
        hiddenSelectionsTextures[]=
        {
            "",  //DNU (Do not Use)
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "",  //DNU 
            "\MODFOLDERNAME\FOlDER\Hull_Main_texture.paa",
            "\MODFOLDERNAME\FOLDER\Misc_texture.paa",
            "\MODFOLDERNAME\FOLDER\Hull_Tail_texture.paa",
            "", //Markings
            "", //left_num_1
            "", //left_num_2
            "", //right_num_1
            "", //right_num_2
            "z\vtx\addons\UH60\data\FuelProbe\Fuel_probe_co.paa" //Fuel Probe
        };
        displayName="DISPLAYNAMEHERE";
    };
};
```
Make sure to change the file paths and filenames to your needs. 

Possible inheritance classes:
```
vtx_mh60M
vtx_mh60M_Dap
vtx_uh60M
vtx_uh60M_Slick
vtx_HH60
```
Indexes for hidden selection textures:
```
Hull Main = 16
Misc	  = 17
Hull Tail = 18
Markings  = 19
```
If you want to publish your mod on the workshop you will want to sign it. I recommend this tutorial video
<https://youtu.be/iq4iJOmz8s4>.


## Workflow Example
When creating liveries I would recommend the following things based on my own experience. 

Create a folder named after the livery you are making, which will contain the .psd files and another folder called "Export". Once you have 
created your livery (or your first draft of it) you will want to export the texture from the graphics editor into the Export folder.

Example for naming the file:
```
Main_Hull_Bundesheer_desert_01.png
```
Numbering your textures is highly recommend and will greatly help later on.  

From there convert the .png into a .paa file with ImageToPAA, then create a Arma 3 mission, open the folder of it, and create a folder with the same as the livery folder.
Copy the .paa files from your Export folder into the folder inside the missionfolder. 

Example:
```
\missions\
  \HatchetSkinTesting\
    		\mission.sqm
    		\Bundesheer_Desert\
            		\Main_Hull_Bundesheer_desert_01.paa
            		\Misc_Bundesheer_desert_01.paa
            		\Hull_Tail_Bundesheer_01.paa
            		\Markings_Bundesheer_01.paa
```

If you now place down a Hatchet H-60 in the 3DEN Editor (make sure to give it a unit variable e.g. "Blackhawk") and start the mission you can test your liveries and adjust them.
Just insert the following code into your debug console once loaded in and execute it locally. Make sure to change the file paths so they lead to your .paa files in the missionfolder. 

Example:
```sqf
Blackhawk setObjectTexture [16, "HatchetSkinTesting\Bundesheer_Desert\Main_Hull_Bundesheer_desert_01.paa"];
Blackhawk setObjectTexture [17, "HatchetSkinTesting\Bundesheer_Desert\Misc_Bundesheer_desert_01.paa"];
Blackhawk setObjectTexture [18, "HatchetSkinTesting\Bundesheer_Desert\Hull_Tail_Bundesheer_desert_01.paa"];
Blackhawk setObjectTexture [19, "HatchetSkinTesting\Bundesheer_Desert\Markings_Bundesheer_desert_01.paa"];
```

Now whenever you have a new iteration of a part of the skin you just increase the number at the end of the file by one, copy it into the mission folder and then without needing
to restart the mission test it within seconds.


## Tipps and Tricks
If you want to remove the markings you can just have a empty file path.
```sqf
Blackhawk setObjectTexture [19, ""];
```
