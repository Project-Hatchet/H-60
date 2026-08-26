# Development & testing scripts

These are **functional testing helpers** used during development. They are intentionally kept out of the released PBOs (the build packs only what is inside `addons/`), but they are maintained, working scripts — not abandoned or half-finished code.

Run them from the in-game debug console while in or near a helicopter, e.g.:

```
call compile preprocessFileLineNumbers "<repo>\devScripts\uh60_misc\fnc_instantStart.sqf"
```

## uh60_misc

| Script | What it does |
|---|---|
| `fnc_instantStart.sqf` | Instantly puts the helicopter you are looking at into a fully started state: restores a captured set of engine/electrical variables and switch animation positions, turns the engines on, then clicks through the MFD to deploy the FLIR. Useful for testing anything that needs a running aircraft without sitting through the startup. The scripted-interaction sequence at the bottom (TAC page → FLIR page → deploy) doubles as a repeatable FLIR test. |
| `fnc_alignSearchLightToView.sqf` | Snaps the searchlight to point where your camera is looking — for quickly checking searchlight cone, texture and alignment. |

Notes:

- `fnc_instantStart.sqf` restores a **captured snapshot** of vehicle state, so it bypasses the startup logic rather than fast-forwarding it. The improvement plan (Phase 5.7) intends to replace it with a proper "instant start" dev action that drives the real state machine instead.
- Players wanting a quick start in normal play should use the **Automatic Engine Startup** scroll-menu action, which is the supported, shipped equivalent.
