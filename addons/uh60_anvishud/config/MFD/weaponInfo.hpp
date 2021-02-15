#define MARGIN_L 0.02
TEXT_HMD_L(WEAPON_NAME,0.015,0.81+(SMALL_LINEHEIGHT*2))
    source = "weapon";
    sourceScale = 1;
    text = "";
}; // MARGIN_L
// class weapons_selected {
//     condition = "mgun+rocket+bomb+missile";
//     class STA1_SEL {
//         condition="pylonselected1";
//         TEXT_HMD_L(AMMO_NAME,MARGIN_L,0.92)
//             source = "pylonMagazineName";
//             sourceIndex = 1;
//             sourceScale = 1;
//             text = "";
//         }; // AMMO_NAME
//     }; // STA1_SEL
//     class STA2_SEL {
//         condition="pylonselected2";
//         TEXT_HMD_L(AMMO_NAME,MARGIN_L,0.92)
//             source = "pylonMagazineNameShort";
//             sourceIndex = 2;
//             sourceScale = 1;
//             text = "";
//         }; // AMMO_NAME
//     }; // STA2_SEL
// };