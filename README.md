<p align="center">
    <a href="">
        <img src="https://img.shields.io/badge/Version-0.5.2.40-blue.svg?style=flat-square" alt="H-60 Pack Version">
    </a>
    <a href="https://steamcommunity.com/sharedfiles/filedetails/?id=1745501605">
        <img src="https://img.shields.io/badge/Steam-dev%20build-orange?logo=steam" alt="H-60 Pack">
    </a>
    <a href="https://github.com/Project-Hatchet/public_h-60/issues">
        <img src="https://img.shields.io/github/issues-raw/Project-Hatchet/public_h-60.svg?label=Issues" alt="H-60 Pack Issues">
    </a>
    <a href="https://discord.gg/58Pt5EGjvQ">
        <img src="https://img.shields.io/discord/487939925938012161.svg?label=Discord&colorB=7683D5" alt="H-60 Pack Discord">
    </a>
</p>
<p align="center">
    <sup><strong>Requires the latest versions of <a href="https://github.com/CBATeam/CBA_A3/releases">CBA A3</a>, <a href="https://github.com/acemod/ACE3/releases">ACE3</a> and <a href="https://github.com/Project-Hatchet/hatchet-framework">Hatchet Framework</a>.<br/></strong></sup>
</p>

The **Hatchet H-60 Pack** is a helicopter pack that brings realistic H-60 series helicopters to Arma 3, using our custom made Hatchet Framework to add detailed interactive cockpits, we strive to create an authentic representation of the H-60 series helicopter.


## Development Guide

### SConstruct(SCONS) Build environment
The H-60 is built with SConstcut, or for short, SCONS.

#### Prerequisite: python > 3
To install scons, you require python 3.
To check what python version you have installed, you can use the `python --version` command

#### Scons installation
Once you confirmed you have python installed, you can use the command
`python -m pip install scons`
To install scons

#### Troubleshooting
**PATH Warning**
Important: when installing scons, you might find the following error:
```
WARNING: The scripts scons-configure-cache.exe, scons.exe and sconsign.exe are installed in 'C:\Users\<user>\AppData\Local\Programs\Python\Python39\Scripts' which is not on PATH.
Consider adding this directory to PATH or, if you prefer to suppress this warning, use --no-warn-script-location.
```
If you find this, you will have to add the python folder to your PATH.
If you don't know how to add variables to your PATH, you can find more information here https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/

**Other errors**
If you find any other errors, please ask the dev team in the Project Hatchet discord server.

#### Usage
Once installed, you should be able to open the project's root folder in your terminal, and run `scons`.
This should generate fully built PBOs in your addons folder.




<a rel="license" href="https://www.bohemia.net/community/licenses/arma-public-license-nd" target="_blank" ><img src="https://data.bistudio.com/images/license/APL-ND.png" ><br>This work is licensed under the Arma Public License No Derivatives</a>
