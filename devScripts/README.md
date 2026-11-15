# Development & testing scripts

Functional testing helpers used during development. They are kept out of the released PBOs (the build packs only what is inside `addons/`), but they are maintained, working scripts.

Run them from the in-game debug console while in or near a helicopter, e.g.:

```
call compile preprocessFileLineNumbers "<repo>\devScripts\h60_misc\fnc_alignSearchLightToView.sqf"
```

## h60_misc

| Script | What it does |
|---|---|
| `fnc_alignSearchLightToView.sqf` | Snaps the searchlight to point where your camera is looking — for quickly checking searchlight cone, texture and alignment. |

For a running aircraft, use the shipped **Automatic Engine Startup (DEV)** vehicle action: turn on Developer Mode (Addon Options > Hatchet H-60 > Developer). It drives HeliSim's real start sequence with its progress on the developer panel. The snapshot-restoring `fnc_instantStart.sqf` it replaced has been removed.
