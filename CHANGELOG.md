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
