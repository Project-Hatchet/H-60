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

The older SCons build (`SConstruct`) is still in the tree for the transition and is still exercised by CI, but new work should use HEMTT; it is retired once a Stable has shipped from HEMTT.

**Other errors**
If you find any other errors, please ask the dev team in the Project Hatchet discord server.

#### Pushing a build to the Steam Workshop Development branch
`tools/push_dev.py` builds the mod from a named git ref with HEMTT and uploads it to the Development branch Workshop item in one step:

```
python tools/push_dev.py --branch <ref> --note-from-changelog --bump               # usual dev push
python tools/push_dev.py --branch <ref> --note-from-changelog --version 0.7.9.1    # first push of a new cycle
python tools/push_dev.py --branch <ref> --note-from-changelog --bump --preview-note  # see the note, change nothing
python tools/push_dev.py --branch <ref> --note "what changed" --dry-run             # build and verify only
```

Write what changed for players under a `**Unreleased**` header at the top of `CHANGELOG-DEV.md` on the branch you are pushing. The script stamps the new version into `addons/main/script_version.hpp`, retitles that block to the version, commits both on the branch, and uses the block as the Workshop change note - so the in-game version, the changelog and the Workshop always agree.

Versioning: Stable releases are `X.Y.Z`; Development builds carry the *next* Stable's number with the build digit counting up per push (`0.7.9.1`, `0.7.9.2`, ...). Start a cycle with `--version`, continue with `--bump`. Bump the patch number for routine Stable promotions and the minor number for substantial ones.

It refuses to run on a dirty working tree or on a local branch that differs from origin, replaces `release/@H-60` with the fresh HEMTT output so nothing stale can ship, verifies that every addon produced a fresh PBO, and asks for confirmation before uploading. The upload goes through `PublisherCmd` from Arma 3 Tools using the Steam client already logged in on your machine, so you need contributor rights on the Workshop item and nothing else. The script only knows the Development branch item - promoting to Stable is done by hand on purpose.




<a rel="license" href="https://www.bohemia.net/community/licenses/arma-public-license-nd" target="_blank" ><img src="https://data.bistudio.com/images/license/APL-ND.png" ><br>This work is licensed under the Arma Public License No Derivatives</a>
