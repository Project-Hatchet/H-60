**Changelog**
- MFD FLIR Page overhaul
  - FLIR synchronization between crew fixed
  - FLIR no longer drifts when copilot controls it
  - FLIR no longer drifts when slewing while helicopter is moving
  - Laser spot tracker implemented (manual mode and 4 bar scan)
  - Weapons information subpage added to FLIR
  - Hellfire launch settings can be configured from MFD
  - Hellfire launch symbology and TOF implemented
  - Waypoints can be created and slewed to
  - Currently aimed at waypoint is displayed
  - Pylons can be reassigned between pilot and copilot through WPN CTRL subpage
  - Laser designator channel can be configured
  - Laser spot tracker designator channel can be configured
  - Hellfire primary and alternate channels can be configured
  - FLIR is stowed by default and has 25 second cooldown when starting
  - General update of MFD FLIR page UI
  - Pylons can be jetissoned to reduce weight and improve performance

- MFD EICAS Page & Damage system overhaul
  - EICAS shows in depth cautions for component damage
  - FLIR can get shot out and fail
  - RWR can get shot out and fail
  - MFDs can get shot out and fail
  - Implemented advisories for new JVMF messages and replies
  - Implemented an advisory for when the laser is on 
  - Master caution system functional
  - Caution overlay added to ND and TAC pages to alert user of new cautions and advisories

- MFD TAC Page overhaul
  - TAC map redesigned to match real one
  - TAC map and cursor are now fully synchronized between players
  - Vt7 added to maps
  - TAC "hooking" implemented (user can overlay cursor on vehicle or group to see info)
  - Forward mode added where own heli is in bottom 3/4ths of screen instead of centered
  - Map types can be selected (topo, sattelite, custom)
  - Custom maps implemented (just place a file called tac.paa in the mission folder)
  - BFT renders more reliably at more zoom levels

- MFD PFD Page overhaul
  - Artificial horizon now has a better center marker
  - ARC subpage showing waypoints
  - HOVER subpage showing hover info
  - Radar altimeter gets hidden above working altitude

- HUD improvements
  - New variant of HUD added for the HH and UH variants
  - HUD monocle overlay added when using HUD without NVGs
  - HUD no longer disappears for copilot

- SFMPlus / Overtorque changes
  - Overtorque no longer causes damage
  - Overtorque now causes a reduction in main rotor RPM - and a loss of lift
  - An SFM rotor RPM limiting script has replaced the anti lift script, meaning rotors will now realistically idle
  - RPM limiter is once again functional in AFM
  - Sling loading cargo is now counted in to the torque calculation

- Rotor brake implemented
  - Rotor brake is now functional
  - Rated for use up to idle
  - Rotor brake interlock will stop users from setting PCLs to FLY with rotor brake on
  - When engaging brake with over NR of over 60, damage to the main rotor system will occur
  - Doing a full rotor brake stop with rotors at full RPM will result in a complete destruction of the rotors

- Flight Director expansion
  - FMS Coupled mode implemented. When FMS is coupled the aircraft will follow the heading to the current waypoint
  - Auto hover implemented
  - Standby keybind fixed - now works in SFM and disables all FD modes

- Interactive customizaiton
  - Door number tape can now be adjusted with ACE Interactions
  - Engine cover markings can be changed with ACE Interactions
  - Doors, probe and hoist can be attached and removed in game by players with a toolkit in their inventory
    - In zeus or editor, the following items can be found in the "Empty" category: "Blackhawk Fuel Probe", "Blackhawk Hoist", "Blackhawk Cockpit Doors"

- Art, model & variant updates
  - Major texture & material overhaul
  - Model update for the MH-60M, added variant-specific ASE and antennas
  - MH-60M MLASS(4 pylon) variant added
  - New model and texture added for AGM-114
  - New model and texture added for M261 Rocket Pod
  - Model update for HH-60G/M, exterior more accurately resembles a -G model now
  - New texture for HH-60G/M
  - Firefighting skin added for HH-60G/M
  - Rotor transparency fixed, should result in less graphical glitches
  - Cockpit doors are animated
  - Cockpit window glass material updated
  - Pilots are no longer invisible from cargo LOD
  - Cockpit light now also paired with cabin light (will be split out in to separate switches in the future)
  - Cold start panel functional with battery and APU indicatorss
  - M-230 Sound overhauled to be on par with Apache mod

- Misc bugfixes & improvements
  - Flare launch mempoints updated to fire flares forward
  - Geo physx lod updated to stop satan dragging the 60 back down to hell
  - Wheel brakes fixed
  - AI can now fire doorguns
  - Heavier helicopters are no longer more agile
  - Removed sensor panel from copilot seat
  - Added automatic startup feature (usable from action menu)
  - Removed "altis_flooded" pbo

- Known issues:
  - Controlling TAC as copilot can be laggy at times, especially with high ping to the pilot