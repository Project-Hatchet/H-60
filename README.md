<p align="center">
    <a href="https://github.com/Project-Hatchet/H-60/releases">
        <img src="https://img.shields.io/badge/Version-0.7.10-blue.svg?style=flat-square" alt="H-60 Pack Version">
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
    <sup><strong>Requires the latest versions of <a href="https://github.com/CBATeam/CBA_A3/releases">CBA A3</a>, <a href="https://github.com/acemod/ACE3/releases">ACE3</a>, <a href="https://github.com/Project-Hatchet/hatchet-framework">Hatchet Framework</a> and <a href="https://github.com/BradMick/BradMicks-HeliSim-Core">BradMick's HeliSim</a> (1.3.0 or later).<br/></strong></sup>
</p>

The **Hatchet H-60 Pack** is a helicopter pack that brings realistic H-60 series helicopters to Arma 3, using our custom made Hatchet Framework to add detailed interactive cockpits, we strive to create an authentic representation of the H-60 series helicopter.


## Development Guide

### Building with HEMTT
The H-60 is built with [HEMTT](https://hemtt.dev). Install it with `winget install BrettMayson.HEMTT`, then from the repository root:

```
hemtt check    # lint and parse everything - what CI runs on every push
hemtt build    # build the mod into .hemttout/build
```

No Arma 3 Tools are needed: every model and animation in the tree is already binarized, and HEMTT rapifies configs itself. The full build takes under a minute. `docs/RELEASE.md` covers versioning, Dev pushes and Stable releases.

### Changelog
Write what changed for players as a **changelog fragment**: a file `changelog/<pr-number>-<slug>.md` with one `- ` bullet per change (see `changelog/README.md`). CI requires one on any PR that touches `addons/`, unless the PR is labeled `Release Notes: Ignore`. Nobody edits `CHANGELOG-DEV.md` directly: the release PR folds the fragments into it.

### Dev and Stable releases
`docs/RELEASE.md` covers versioning, Workshop Development pushes (`tools/push_dev.py`) and Stable releases (`tools/build_stable.py`).

### Help
If you find any other errors, please ask the dev team in the Project Hatchet Discord server.

<a rel="license" href="https://www.bohemia.net/community/licenses/arma-public-license-nd" target="_blank" ><img src="https://data.bistudio.com/images/license/APL-ND.png" ><br>This work is licensed under the Arma Public License No Derivatives</a>
