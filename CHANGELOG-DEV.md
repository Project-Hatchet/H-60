**0.7.7.4**

 - Fix FD IAS keybind
 - Add condition for ACE actions when cabin doors are blocked by units or FRIES
 
 **0.7.7.3**

 - New editor preview images for MH models
 - Add "Stabilize Hook" Modded Keybind
 - Remove Redundant Hoist CBA Keybinds
 - Remove Redundant MFD CBA Keybinds
 - Remove Redundant FLIR Slew CBA Keybinds
 - Remove Flight Director CBA Keybinds
 - Remove Deprecated Debug Settings

**0.7.7.2**

 - Increase head move range
 - Add MH-60M and DAPs to Air Control buy list

**0.7.7.1**

 - Fix hook deployable when hoist is hidden
 - Fix non-DAP models able to use IZLID
 - Change IZLID keybind text
 - Fix no textures on HH60G radar and FLIR, Close #551

**0.7.6.9**

 - Fix JVMF not displaying messages on leftmost MFD
 - Fix RPT Cannot create entity with abstract type vtx_pylon
 - Fix jvmf empty message check BCE/cTab
 - Fix hoist hook and helper vehicles having inventory and driver seat
 
**0.7.6.8**

 - Add ace actions for viv to ThingX class
 - Change ESSS retextureable
 - Fix MITAS in viewPilot
 - Fix markings in lod
 - Fix ammo refill on pylon handover
 - Fix RPT "Trying to call RemoteExec(Call) with 0 targets for func"
 - Add setting Use Scripted Camera. If disabled, copilot uses turret optics. Desired behaviour is same as pilot camera.

**0.7.6.7**

 - Fix FMS copilot for non-MLASS models
 - Fix Arma keybinds for IAS and HDG knobs

**0.7.6.6**

 - Add IR laser for pilots and doorgunners, keybind under H-60 Weapons

**0.7.6.4**

 - Fix pilot keybind issues by restoring 0.7.5.2, pilot does not access scripted camera
 - Fix reassignment for outboard pylons
 - Fix unreliability in reassigning pylons
 - Added Copilot can use map in fullscreen FLIR

**0.7.6.3**

 - Sound Improvements by @Aaren PR #532
 - Increase the volume factor for distant sounds
 - Adjust engine sound profiles
 - New volume curve for distant sounds to better manage audio levels

**0.7.6.2**

 - Fix LASS default textures
 - Fix FLIR snapping to initial geolock point when turning off geolock
 - Change normal N key to work while in fullscreen, but not in cockpit where it affects pilot personal NODs
 - Fix keybinds in fullscreen for pilot (zoom, fire)

**0.7.6.1**

 - Can turn off wipers
 - More retextureable areas
 - Fix rotor shaft not visible https://github.com/Project-Hatchet/H-60/issues/527

**0.7.5.6**

 - Add wipers and knob animation

**0.7.5.5**

 - Removed Roadway LOD to roof and cabin deck

**0.7.5.4**
 
 - Fix visual glitch when smoke is behind blurred rotors
 - Fix scripted camera crosshairs persisting
 - Improve distance LODs
 - Add Roadway LOD to roof and cabin deck
 - Add ACE action for fold and unfold with progress bar
 - Add keybinds for adjusting Flight Director modes
 
**0.7.5.3**

 - Fix Stabilize Turret keybind needing T+Ctrl instead of responding to Ctrl+T
 - Improve JVMF use CBA events instead of remoteExec
 - Fix stuck master caution https://github.com/Project-Hatchet/H-60/issues/440
 - Fix pilot unable to access fullscreen FLIR https://github.com/Project-Hatchet/H-60/issues/497
 - Fix various RPT spam https://github.com/Project-Hatchet/H-60/issues/506
 - Fix seam in MH exterior
 