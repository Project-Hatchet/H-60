#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

/*
 * 0 - freetext
 * 1 - 5-line CAS
 * 2 - location
 */

VTX_JVMF_MESSAGES = [
   [
       "WELCOME", // TITLE
       "SYSTEM", // SENDER
       "ALL", // RECIPIENTS
       0, //MSG TYPE
       [
           "Welcome to the JVMF System",
           "This is a default message",
           "The JVMF system allows messages to be sent between users",
           "JVMF messages may carry data that is displayed on your TAC",
           "Use the NEW button on the right to compose a new message",
           "Messages are sent to everybody automatically",
           "The TITLE portion consists of the sender, recipient, and msg ID",
           "",
           "You can use the buttons in the top to send a standard reply",
           "The reply will consist of your name, the reply and a timestamp"
       ], //MSG TEXT
       [], // MSG DATA
       [
            [
                "12:00",
                "System",
                "SENT"
            ]
        ] // REPLIES
   ],
//    [
//        "TEST MESSAGE", // TITLE
//        "IMAGINARY JTAC", // SENDER
//        "ALL", // RECIPIENTS
//        1, //MSG TYPE
//        [
//            "TYPE 2, USE ROCKETS",
//            "500M NORTH OF AGIA MARINA",
//            "AGIA MARINA - 123123/12m",
//            "2x BTR-80A PARKED ON ROAD", // description
//            "",
//            "ATTACK WEST TO EAST", // restrictions
//            "",
//            "",
//            "",
//            ""
//        ], //MSG TEXT
//        [], // MSG DATA
//        [
//             [
//                 "12:00",
//                 "System",
//                 "SENT"
//             ]
//         ] // REPLIES
//    ],
   [
       "NEW LZ", // TITLE
       "BLUESTONE 4-2", // SENDER
       "FALCON 2-3", // RECIPIENTS
       2, //MSG TYPE
       [
           "060 060",
           "0300 MSL",
           "LZ BRONZE",
           "APPROACH FROM THE SOUTH", // description
           "WATCH FOR THINGS AND STUFF",
           "", // restrictions
           "",
           "",
           "",
           ""
       ], //MSG TEXT
       [[0,0,0]], // MSG DATA
       [
            [
                "12:00",
                "BLUESTONE 4-2",
                "SENT"
            ]
        ] // REPLIES
   ]
   /*
    ,[
        "FIRE",
        "MAURICE MOSS", // determines who can see it, displayed for recipient
        "ALL", // determines who can see it, displayed for sender
        0, //MSG TYPE
        [
            "Dear Sir/Madam",
            "",
            "Fire!",
            "Fire!",
            "Help me!",
            "123 Cavendon Road.",
            "",
            "Looking forward to hearing from you.",
            "Yours truly,",
            "Maurice Moss."
        ], //MSG TEXT
        [], // MSG DATA
        "ACK", // REPLY
        "13:37" // REPLY TIME
    ]
    */
];
VTX_JVMF_SELECTED_IDX = 0;

ADDON = true;
