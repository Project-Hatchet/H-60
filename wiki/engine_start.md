## Description

To manage the engines, we have implemented a system that overrides the default engineOn and engineOff behaviour, now requiring users to go through the correct steps to start the engines.

## Engine Startup

**1. Power**

**On the upper console, enable BATT 1 and 2, and turn on all generators (GEN 1, 2, APU)**

The first thing required to start the engines is ensuring there is power, power is supplied when both battery switches are turned on, without any power generation batteries can support the aircraft systems for roughly 15 minutes. With only battery power, MFD 3(second one from the right) will be powered.

Enabling the generator switches for the engines and APU will make it so these systems will generate power as long as they are running. With generators on and running, all aircraft systems will be running, including all MFDs.

**2. APU**

**On the upper console, set AIR SCE HT/STRT to APU, FUEL PUMP to APU and APU CONT to ON**

The engines are started using pneumatically powered start motors, air for this can be provided from the APU or another engine, for a cold start, AIR SCE HT/STRT to APU will make the start motors use APU air.

Next up we will set the prime/boost fuel pump to APU, which will allow the fuel flow for the APU to start.

Finally, we set APU CONT to ON to start our APU.

**3. Ignition**

**On the dashboard, turn the ignition key to ON.**

**4. Engines**

**On the engine quadrant, set FUEL to DIR, press the starter button, and set ENG CONT to IDLE, and then to FLY.**

To ensure fuel flow we set the FUEL lever to DIR, note that XFD(crossfeed) will also work, but in real life would make the engine feed from both fuel tanks instead of its own.

***When operating with XFD, or at an altitude above 1500m ASL, it is required to enable your FUEL BOOST PUMP for the selected engine on the upper console to provide adequate fuel pressure.***

To allow the engine to start, we enable our starter motors, in certain conditions dependent on air temperature and altitude above sea level, both starter motors could be run at the same time, this document will be updated with a chart in the future, it is generally recommended to run one starter at a time. You can use the EICAS displays (MFDs 2 and 3, center ones by default) to see whether your engines are starting up. The left side of the EICAS display represents the left engine(#1), the right side the right engine(#2).

![EICAS](https://gblobscdn.gitbook.com/assets%2F-LgEua_sCBYEl_WGSABv%2F-LmpQc2DCpln7Fzx8dsw%2F-LmpSERmyfj289d_ELCE%2Fimage.png?alt=media&token=9fe45f1f-fbb5-4c25-85dd-50227bfc37c5)

You can use the power pod on your PFD(same left/right engine arrangement, the center bar shows rotor RPM) to see if your engines are at FLY power.

![Both engines are at fly](https://gblobscdn.gitbook.com/assets%2F-LgEua_sCBYEl_WGSABv%2F-LmpQc2DCpln7Fzx8dsw%2F-LmpRPmQ6WMb6lv0z8_P%2Fimage.png?alt=media&token=980d64a5-7a2c-45a5-b14a-330631675709)

***Troubleshooting tip: The starters automatically turn off when their engine throttle is moved beyond OFF.
When an engine has failed to start, set the throttle for that engine back to OFF, then press the starter for the engine again, and move it to idle and then fly as normal.***

**5. APU OFF**

**Turn APU CONT to OFF, turn AIR SCE HT/STRT to ENG**

The APU is not designed to be run for a long time simultaneously with both engines. Turn APU CONT to OFF, other APU buttons can stay as they were in case an APU restart might be needed later.

Turning AIR SCE HT/STRT to ENG allows the air from one engine to power the other's starter, meaning if a single engine fails the other can be used to restart it.

***Currently, keeping the APU enabled during flight only affects fuel. In future updates it will likely be updated that it might cause overheating and APU damage.***
