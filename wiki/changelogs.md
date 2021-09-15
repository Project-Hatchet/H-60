# Changelogs

## How changelogs work

Changelogs works just how it sounds; they are telling you what changed in each release.<br>
Versions labeled "RC" are Release Candidates. Those versions are released for testing purposes on Github and are not uploaded on steam.

## [0.3.1]

### Stretcher
* Add Stretcher vehicle
* 3 variants with different animations and editorPreview
* Compatible with ViV, slingload, ACE drag and carry, load patient
* Add Stretcher inventory item
* Add Unfold Stretcher ACE Self Action, enabled by item

### Doorgun
* Fix right doorgun pointing wrong way

### FLIR
* Fix ui conflict with RHS MELB

### SFM
* Improve brakes, maxBrakeTorque from 1500 to 2500

### MISC
* Fix CRRC Assault Boat attach action

### ViV
* Fix conflict with ACE scrollwheel handling
* Disallow loading units directly

### Model
* Fix rpt spam: Unsupported UVsets, autocenter agm
* Fix low-offset hellfires from RC1

### Hoist
* Improve Attach Hook action distance, increased
* Improve consistency of get out position
* Improve reliability by disable the hook seat when a unit is attached already and vice versa
* Fix duplicate string

### Weapons
* Add H60 versions of L and N variants of ACE Hellfire missiles

### Flight Direction
* Improve keybinds by disabling them while in Zeus

### Mission
* max players from 20 to 6
* default tickets from 300 to 500
* enemy spawn rate from 200% to 150%
* switched non-pylon-gau21 to additional DAP

## [0.3.1 RC]

Stretcher:
* Add Stretcher vehicle
* 3 variants with different animations
* Compatible with ViV, slingload, ACE drag and carry, load patient
* Add Stretcher inventory item
* Add Unfold Stretcher ACE self-action, enabled by item

Doorgun:
* Fix right doorgun pointing wrong way

FLIR:
* Fix UI conflict with RHS MELB

SFM:
* Improve brakes, maxBrakeTorque from 1500 to 2000

MISC:
* Fix Assault Boat attach action

ViV:
* Fix conflict with ACE scrollwheel handling

Model:
* Fix rpt spam: Unsupported UV sets, autocenter agm

Hoist:
* Improve Attach Hootk action distance, increased
* Improve consistency of get out position
* Improve reliability by disable the hook seat when unit is attached already and vice versa
* Fix duplicate string

Weapons:
* Add H60 versions of L and N variants of ACE Hellfire missiles

Flight Direction:
* Improve keybinds by disabling them while in Zeus

Mission:
* max players from 20 to 6
* default tickets from 300 to 500
* enemy spawn rate from 200% to 150%
* switched non-pylon-gau21 to additional DAP

## [0.3.0 RC](https://github.com/Project-Hatchet/H-60/releases/tag/0.3.0)
Admin:
* .editorconfig indent size from 4 to 2
* minor version from 0.2.1 to 0.3.0
* stringtables in most components
* Full build resources added: binarized p3ds

Cockpit:
* Stage 1 of pilotCamera-based flir for all models except UH-60M
* Multiplayer view angle sync
* Missile cam custom info boxes for pylon models
* copilot head limit matches pilot
* New HMD features including waypoint info, metric units, declutter modes, accessible through FMS

Animation Sources:
* <code>GunnerSeats_Hide</code>
* <code>Minigun_Mount_L_hide ammo box, belt, armature</code>
* <code>Minigun_Mount_R_hide ammo box, belt, armature</code>
* <code>Minigun_L_hide</code>
* <code>Minigun_R_hide</code>

Model related:
* Front wheel dampers no longer collapse
* SFM has wheel brakes
* Cabin doors closed and open state don't clip or leave gaps
* Hoist hook no longer slingloadable
* Floor FFV seats individually accessible

Vehicle-in-vehicle:
* HH-60 and MH-60M viv space btween gunner seats and ERFS, blocks and is blocked by passengers in the floor FFV seats, door seats not affected
* UH-60M MEDEVAC viv space from bulkhead to bulkhead, door ffv seats
* Added FD RALT Toggle keybind, request your favourite here #71

Outstanding issues:
* vtx_MH60S, vtx_MH60S_GAU21L doorguners no vxf, but vtx_MH60S_Pylons is fine
* doorgunner seats not hidden in ViewPilot and ViewCargo LODs
* warning on entering UH60M pilot seat:
<code>Warning Message: No entry 'bin\config.bin/RscInGameUI.'.
Warning Message: No entry '.idd'.
Warning Message: '/' is not a value</code>

## [0.3.0 - First major release of 2021](https://github.com/Project-Hatchet/H-60/releases/tag/v0.3.0)
Admin:
* .editorconfig indent size from 4 to 2
* minor version from 0.2.1 to 0.3.0
* stringtables in most components

Cockpit:
* stage 1 of pilotCamera-based flir for all models except UH-60M
* copilot head limit matches pilot
* New HMD features including waypoint info, metric units, declutter modes

Animation Sources:
* <code>GunnerSeats_Hide</code>
* <code>Minigun_Mount_L_hide ammo box, belt, armature</code>
* <code>Minigun_Mount_R_hide ammo box, belt, armature</code>
* <code>Minigun_L_hide</code>
* <code>Minigun_R_hide</code>

Model related:
* Front wheel dampers no longer collapse
* Cabin doors closed and open state don't clip or leave gaps
* Hoist hook no longer slingloadable
* Floor FFV seats individually accessible

Vehicle-in-vehicle:
* HH-60 and MH-60M viv space btween gunner seats and ERFS, blocks and is blocked by passengers in the floor FFV seats, door seats not affected

Added FD RALT Toggle keybind
## [0.2.0 - Frankenstein](https://github.com/Project-Hatchet/H-60/releases/tag/v0.2.0)
Development structure changed to the ACE project structure using the P drive.

Added:
* Functionality should match the current steam release
* Map and group bar pictures
* Pylon presets for DAP
* Custom Info Boxes
* MH-60M: Gunner view
* DAP: Gunner view and Missile view

Tweaked:
* Slingcam location moved to near hook on non MH-60M models

Fixed:
* Disabled FLIR keybinds on non MH-60M models
* ACE Hellfire Guidance for H60 hellfires
* Editor Attributes Pylons menu UI

