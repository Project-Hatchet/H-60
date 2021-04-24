
## Showing/Hiding Player Body

The player body is hidden for cockpit users by default, to allow better visibility inside the cockpit. The player's body can be shown again by pressing H to go in to help mode, and proceeding to interact on the white dot in the center of the windshield.


![Player Body Selection](https://gblobscdn.gitbook.com/assets%2F-LgEua_sCBYEl_WGSABv%2F-LnTwxK83hA4Cg3p3fMn%2F-LnTxqx3uHRO5R9sbGZI%2Fimage.png?alt=media&token=82fbeef3-cddf-4ccc-b180-fc3c6e7ea1ee)


---

## Simple Collective Mode

We strongly suggest the UH-60M is flown using advanced flight model(AFM). We understand that this might be difficult for some to get used to, especially those flying with keyboard, so we've implemented a simple collective mode, that makes the AFM collective function like the standard flight model one.


![Easy Collective](https://gblobscdn.gitbook.com/assets%2F-LgEua_sCBYEl_WGSABv%2F-LnTwxK83hA4Cg3p3fMn%2F-LnTyKcyc1WJRukm1U7U%2Fimage.png?alt=media&token=1b537d21-5f1d-49cf-bd9b-a4b2995f4718)


	Simple Collective can be enabled in the CBA Addon Settings for the UH-60M.

When enabled, the helicopter will try always stay level, then will ascend at 1000 foot per minute(fpm) when the users uses the `collective raise` keybind, and descend at 1000fpm if the player uses the `collective lower` keybind.

Simple collective does not work with analog collective input at the moment, only keyboard collective.


**Simple collective is an autopilot mode that relies on previous collective input and vertical velocity to decide desired collective.**

**This means that, for example, when holding down collective lower when landed, it will drastically lower the average collective, and you will need to hold collective raise for a longer time to make it climb again.**


## Free-moving interaction cursor for trackIR users

For trackIR users, there is the option to use a free-moving cursor to interact with the cockpit, this option can be enabled from the UH-60M CBA Settings menu by selecting "Detached Interaction Cursor".