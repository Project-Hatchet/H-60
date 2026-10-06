**0.7.10**

  - FIXED:
    - Door seats lock with the correct cabin door on each side, and walking up to a door no longer makes its seats' interactions disappear #612
    - UH-60M Slick door gunner seats are usable again - they were being locked by the cabin door logic #626
    - Cabin sound: door gunners and MEDEVAC window seats are muffled when turned in and hear the full slipstream when turned out; bench and door seats are muffled #617
    - Flight director and fuel readouts no longer leak between aircraft - each helicopter keeps its own state, which also addresses the spinning/rolling on the ground after a pilot/copilot handoff #597
    - FMS fuel page shows each aircraft's own consumption, time and range #597
    - Move to Cabin is always available and falls back through door gunner, troop commander and cargo seats; Move to Cockpit goes to the pilot seat first #604
    - FLIR: geolock indicator disappears when the lock is dropped #606
    - FLIR: no camera drift at rest - slew deadzone corrected, with a new setting to tune it #594
    - MFD Create Waypoint works on the first press #615
    - Waypoint 1 draws its marker on the TAC map, including a lone first waypoint #625
    - ACRE radio on/off and channel changes now show on both pilots' FMS immediately; frequency readout fits its outline #595 #601
    - ERFS tanks carried with ACE no longer collide with the aircraft #623
    - MH-60M cockpit doors no longer appear on spawn #599
    - S-70i instrument corrections #624
    - EICAS no longer floods the game log #614
  - ADDED:
    - MFOS (Martin Baker) crew chief seats at the gun stations on every variant #626
    - MH-60M DAP aft crew station: two crew chief seats with personal-weapon fire, Turn Out / Turn In via ACE interact to the cargo door sill (the vacated seat stays reserved), and two emergency passenger door seats #626
    - S-70i: two crew chief seats and the hoist pendant seat; ships with the hoist fitted #626
    - ERFS tanks attached and removed via ACE interact (toolkit plus a nearby ERFS tank object); DAPs spawn with ERFS fitted; weight and fuel capacity follow #605
    - TDC Waypoint Set and Slew keybinds: drop a waypoint where the FLIR is designating (numbered from 99 downward) and slew to a waypoint; FMS NAV selection can now be cleared #615
    - Simple Flight Model ground handling: the parking brake holds on slopes up to about 17 degrees and releases above 8 km/h, ground taxi with cyclic and pedals up to 20 km/h (no rearward taxi), and a Parking Brake keybind under Configure Addons > H-60 Cockpit #621
    - Editor preview images for the UH-60M Slick, HH-60M MEDEVAC and S-70i #624
    - View Gunner LOD in the aircraft model #626
  - CHANGES/IMPROVEMENTS:
    - Hoist control belongs to the pilots and the "(hoist controls)" door seat only; door gunners and passengers can no longer operate it, and the Stabilize Hook keybind works again #627
    - S-70i classname renamed from vtx_S70M to vtx_S70i - missions and compositions that placed the old class must be updated #624
    - MH-60M DAP interior cabin seating removed in favour of the aft crew station above #626
    - Internal restructure: all aircraft config now lives in one addon and the HH-60 is its own addon. Server admins: the PBO set has changed, re-copy the whole mod folder rather than individual files #603 #607 #608 #609
  - KNOWN ISSUES:
    - Copilot and Troop Commander seats are still loud inside - waiting on a model fix
    - Under SFM the tail wheel can lift under full forward cyclic while taxiing; high-speed rolling landings behave as before

**0.7.9**

  - FIXED:
    - Rescue hoist in multiplayer: the hook and anyone riding it now lower away from the aircraft instead of staying stuck at the cabin #576
    - Engine and APU start/shutdown sounds are now heard by other players nearby, and sound playback works on servers with strict remoteExec whitelists #577 #578
    - Engine systems no longer get confused when more than one aircraft is running #577
    - Pilot's fullscreen FLIR now refreshes its overlay readouts (like the GEOLOCK indicator) #592
    - IZLID IR laser beam draws from the correct position - pilot and copilot each get their own beam #579
    - FLIR weapons page no longer floods the game log with errors on aircraft with missing or 4-pylon weapon stations #566
    - Error when paging through an empty FMS page list #573
    - Flight director ALT increase/decrease keybinds #561
    - Rescue Hoist scroll menu showing the wrong name #563
    - Script errors left behind by previously removed functions, and several config typos with in-game effects #562 #569 #572
    - Internal numbering of the helicopter's texture slots so retextures apply to the right parts #565
    - Autohover and countermeasure keybinds no longer work from the cabin and rear crew seats #557 #589
  - ADDED:
    - Fire Laser [HOLD] and IZLID [HOLD] keybinds - active while held, off on release #580 #581 #584
  - REMOVED:
    - Leftover debug text printed to players; developer-only scripts and raw texture sources are no longer packed - the mod download is smaller #564 #570 #571

**0.7.8.1**

  - FIXED:
    - Copilot seat: cockpit interior (upper console and instruments) renders again and the get-in animation is back; the copilot's dedicated camera view is temporarily disabled until the model is updated #556
    - FLIR: lock and track vehicles from every view (PiP and fullscreen, pilot and copilot); pressing lock again releases #538
    - FLIR: ground points stay locked where you leave them when slewing; moving the camera while tracking a vehicle drops to a ground hold
    - FLIR snapping back to the first geolock point when turning geolock off
    - Flight director IAS keybind; IAS and HDG knob keybinds
    - Hoist hook deployable while the hoist was hidden; hook and helper vehicles having an inventory and driver seat
    - Non-DAP models able to use the IZLID
    - Missing textures on the HH-60G radar and FLIR #551
    - JVMF messages not showing on the leftmost MFD; empty-message check with BCE/cTab
    - FMS copilot on non-MLASS models
    - Pylon reassignment reliability, outboard pylon reassignment, ammo refill on pylon handover
    - MITAS in pilot view, markings LOD, rotor shaft not visible #527
    - Various RPT errors (abstract vtx_pylon entity, RemoteExec with 0 targets)

  - ADDED:
    - IR laser (IZLID) for pilots and door gunners, keybind under H-60 Weapons
    - Stabilize Hook keybind
    - ACE actions to load the cabin as vehicle-in-vehicle cargo (ThingX)
    - MH-60M and DAPs on the Air Control buy list
    - Editor preview images for the MH models
    - Copilot can use the map while in fullscreen FLIR
    - ACE door actions are blocked while units or FRIES are in the doorway

  - CHANGES/IMPROVEMENTS:
    - Sound improvements: engine profiles and a new distant-sound volume curve (thanks @Aaren) #532
    - ESSS and more areas retexturable; LASS default textures fixed
    - Wipers can be turned off
    - Increased head movement range
    - Redundant CBA keybinds for hoist, MFD, FLIR slew and flight director removed in favor of the Arma keybinds; deprecated debug settings removed
    - IZLID keybind text
    - N key works in fullscreen FLIR but not in the cockpit, where it affects the pilot's own NODs

**0.7.6**

  - FIXED:
    - Various RPT Spam #407, #506
    - Gap in MH Model #506
    - Master Caution Conditional Checks #440 - Master Caution light should now extinguish once all cautions on the CAS are cleared on their own.
    - Fullscreen FLIR for Pilot #497
    - Stabilize Turret keybind needing T+Ctrl instead of responding to Ctrl+T
    - Improve JVMF use CBA events instead of remoteExec
    - Visual glitch when smoke is behind blurred rotors
    - Scripted camera crosshairs persisting

  - ADDED:
    - ACE action for fold and unfold with progress bar (requires toolkit)
    - Keybinds for adjusting Flight Director modes
    - Windshield Wipers and Wiper Knob interaction

  - CHANGES/IMPROVEMENTS:
    - Improved Distance LODs


**0.7.5.1**

 - Fixed: MFD interactions using old framework variable

**0.7.5**

 - Added: Slewable Landing light and Search light, controls via keybind and interaction on collective
 - Added: Ability to open and close the gunner windows when miniguns are hidden and gunner is not turned out. Windows closed blocks FFV.
 - Added: Add 3DEN attribute for removing fuel probe only, not adding it
 - Added: Unarmed slick version for civilian faction: S-70M
 - Improved: Suspension tuned for 9000 kg mass and removed physx lod wheel mesh to prevent extreme AFM jump
 - Improved: Distance LODs
 - Changed: MFD values using 2.20 increased values instead of pylons
 - Changed: APKWS instead of DAGR in Loadouts
 - Fixed: Fuel Probe not extending unless USAF mod is loaded

**0.7.3 Stable Changelog**
- MAJOR FEATURE UPDATES
  - ACRE Integration
    - ICS for limited cargo seats
    - Troop Commander seats with access to ICS & personal radio booster (UH60M & MH60M)
    - Improvements to Copilots radio functionality
    - Radios no longer tied to FFCS system, in fact, please avoid using that and use the FMS instead.

  - Modded Keybinds
    - Most cockpit switches
    - FLIR
    - Flight Director
    - MFDs

- CHANGES/FIXES/IMPROVEMENTS

  - Audio
    - Various config and script improvements
    - Fix remoteExec call use

  - HAAR
    - Compatibility with USAF Tankers module
    - Removed bespoke AAR Functions and KV-44 Blackfish variant

  - M230/30mm
    - ACE Frag settings for the 30mm have been adjusted to stop inadvertently killing DAP Pilots
    - 30mm Ammo Config now matches the Apache Longbow Project config (they're the same weapon) 🤷
    - Removes AP variant of the M230. Ammo Config above contains an AP submunition
    - Base Class for 30mm Ammo changed
    - 30mm Tracers Removed

  - M134 Minigun/Door Guns
    - Updates Tracer count to 1-in-5
    - Removes Minigun EOTech Sights
    - Fixes Minigun Burst continuing after releasing the trigger
    - Door Guns now have realistic traversal and elevation limits. Limits are the same for Turned In and Turned Out modes

  - AI Engagement
    - AI should now target the helicopter (more) appropriately. As of this build, most vehicles will engage the helicopter now. Only infantry that will engage the aircraft are AA and AT Launcher Rifleman.

  - Virtual Garage/Editor
    - Removed Broken "Remove Cockpit Door"  Garage Option | Replaced with Individual "Hide L/R Cockpit Door" Option
    - Added "Close L/R Cabin Door" Garage Option
    - UH Variants spawn with cabin doors closed
    - Removed Garage Options to Add/Remove MH/HH-Specific Parts to all variants (with exception of the ERFS Tank). In-game removal of the Probe remains unchanged.
    - Added the different variants to the Virtual Garage
    - Removed the OPFOR Variants of the aircraft

  - MFD/Interaction
    - Topo Maps for the TAC uploaded at 4k as a temp fix for 8k not working
    - Removed ACE LST Function to avoid confliction with the MFD-Based LST Feature
    - Fixed Help UI showing up unwantedly on seat swap
    - Fixed Interaction setup not running on seat swap
    - Fix IVHMS Scroll Wheel action not displaying when no battery power is applied
    - JVMF Delete Message function added
    - Skis can be added via ACE

  - Miscellaneous
    - ACE/CBA Minimum Version Requirement added after missile guidance update
    - Changes to some weird spellings
    - MEDEVAC Variant renamed to HH-60M
    - Transferred Debug settings from Framework Addon Options to the H60 Addon Options
