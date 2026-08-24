<p align="center">
    <a href="https://github.com/Project-Hatchet/H-60/releases">
        <img src="https://img.shields.io/badge/Version-0.7.6.0-blue.svg?style=flat-square" alt="H-60 Pack Version">
    </a>
    <a href="https://steamcommunity.com/sharedfiles/filedetails/?id=1745501605">
        <img src="https://img.shields.io/steam/downloads/1745501605" alt="H-60 Pack" >
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
The H-60 is built with SConstruct, or for short, SCONS.

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

#### Pushing a build to the Steam Workshop Development branch
`tools/push_dev.py` builds the mod from a named git ref and uploads it to the Development branch Workshop item in one step:

```
python tools/push_dev.py --branch <ref> --note-from-changelog --bump               # usual dev push
python tools/push_dev.py --branch <ref> --note-from-changelog --version 0.7.9.1    # first push of a new cycle
python tools/push_dev.py --branch <ref> --note-from-changelog --bump --preview-note  # see the note, change nothing
python tools/push_dev.py --branch <ref> --note "what changed" --dry-run             # build and verify only
```

Write what changed for players under a `**Unreleased**` header at the top of `CHANGELOG-DEV.md` on the branch you are pushing. The script stamps the new version into `addons/main/script_version.hpp`, retitles that block to the version, commits both on the branch, and uses the block as the Workshop change note - so the in-game version, the changelog and the Workshop always agree.

Versioning: Stable releases are `X.Y.Z`; Development builds carry the *next* Stable's number with the build digit counting up per push (`0.7.9.1`, `0.7.9.2`, ...). Start a cycle with `--version`, continue with `--bump`. Bump the patch number for routine Stable promotions and the minor number for substantial ones.

It refuses to run on a dirty working tree, wipes the AddonBuilder sync mirror first (it syncs additively, so deleted files would otherwise ship again), verifies that every addon produced a fresh PBO, and asks for confirmation before uploading. The upload goes through `PublisherCmd` from Arma 3 Tools using the Steam client already logged in on your machine, so you need contributor rights on the Workshop item and nothing else. The script only knows the Development branch item - promoting to Stable is done by hand on purpose.




<a rel="license" href="https://www.bohemia.net/community/licenses/arma-public-license-nd" target="_blank" ><img src="https://data.bistudio.com/images/license/APL-ND.png" ><br>This work is licensed under the Arma Public License No Derivatives</a>
