# devbuild

Machine-generated branch: `Main` @ a2b2644 plus every open PR labeled `Ready for Testing`.
In-game version stamp: `0.8.0.51` (stable `Main` is `0.7.10`).
Do not commit to it, review it, or merge it anywhere - it is rebuilt from scratch on every label change.

## In this build

| PR | Title |
|---|---|
| #668 | H-60 overhaul: common base + variant PBOs, vtx -> hct rename, stringtables, bug pass, SCons retired, zero HEMTT warnings |

## Changes since the last Stable (changelog fragments)

 - Fix the HUD help text not showing your Help and Interaction keys, and drop its line for the Flight Director standby key that no longer exists
 - Fix vehicle-in-vehicle loading: finishing a load after leaving loading mode could unload the carrier instead, and every load attempt wrote script errors to the game log
 - Fix Stabilize Hook securing (stowing) the hook instead when pressed by a crew member who does not own the aircraft
 - Fix the hoist winch keys doing nothing for the crew when the aircraft belongs to the server (AI pilot)
 - Fix FLIR track waypoints created from the FMS completing on their own, and the MFD waypoint button failing for map marks and microDAGR waypoints
 - Fix the caution/advisory list sometimes skipping an entry when clearing, and parking brake, backup pump and JVMF advisories writing errors to the game log every second
 - Fix cTab markers of an unknown type importing into JVMF without a label
 - The TAC map cursor now syncs to the rest of the crew at most ten times a second while you slew it, instead of every frame
 - Fix script errors in the game log from the ACRE comm pages and knobs before the radios are ready, the FLIR in gunner view with no FLIR page open, an empty JVMF inbox, the hoist hook repair check, and every module start-up (CAS, FMS, MFD, JVMF, ground)
 - Fix diagonal streaks across the MFDs (TAC map, FLIR and every other page) that turned with your view - the screen glass was mirroring a photo of a grass field
 - The FLIR and sling-camera picture on the MFDs now keeps its proportions on any monitor - it was squeezed sideways, badly on ultrawide (21:9, 32:9) screens
 - Fix the FLIR lock grabbing a vehicle far off that you were not looking at (behind a hill, a building or past your aim point). A narrowly missed target is still caught, but only one in front of what you are aiming at, close to the aim line, inside a window that narrows as you zoom, and in line of sight; aircraft against open sky can now be locked the same way
 - Fix one press of the FLIR lock key sometimes locking and releasing at once
 - Fix the copilot's fullscreen FLIR always opening in daylight TV even with a thermal or NVG mode selected, green-hot never applying in fullscreen, and the MFD FLIR picture coming back in the wrong mode after Zeus or spectator
 - Fix getting out (or respawning) while in the fullscreen FLIR leaving its camera or key hooks behind, and the sling camera continuing to render after you leave the aircraft
 - Rename the pack's identifiers from vtx to hct (Hatchet): classnames (e.g. hct_UH60M, hct_MH60M_DAP), functions, CBA settings, keybinds and addon (CfgPatches) names. Missions made with older versions keep working: the old vtx_* aircraft, crew, stretcher, magazine and addon names still load (as hidden aliases), and the old function names still work. **Your H-60 CBA settings and keybinds reset to defaults once** - set them again in Options > Addon Options / Controls
 - The sound addon now builds as hct_h60_sounds.pbo
 - The editor, Zeus and Addon Options categories are now named "Hatchet H-60" instead of "VTX". Every player-facing name, tooltip and hint now comes from the stringtables, so the pack can be translated
 - Fix a damaged MFD's flicker sometimes leaving the screen stuck on the wrong page, or undoing a page the crew had just selected

_Rebuilt 2026-11-16 19:19 UTC by [this run](https://github.com/Project-Hatchet/H-60/actions/runs/43937995472)._
