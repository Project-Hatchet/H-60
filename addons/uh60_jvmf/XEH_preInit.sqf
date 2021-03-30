#include "script_component.hpp"

ADDON = false;

#include "initSettings.sqf"
#include "XEH_PREP.hpp"

VTX_JVMF_MESSAGES = [
   [
       "WELCOME",
       "SYSTEM", // determines who can see it, displayed for recipient
       "ALL", // determines who can see it, displayed for sender
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
       [] // REPLIES
   ],
   [
       "TEST MESSAGE",
       "IMAGINARY JTAC", // determines who can see it, displayed for recipient
       "ALL", // determines who can see it, displayed for sender
       1, //MSG TYPE
       [
           "TYPE 2, USE ROCKETS",
           "500M NORTH OF AGIA MARINA",
           "AGIA MARINA - 123123/12m",
           "2x BTR-80A PARKED ON ROAD", // description
           "",
           "ATTACK WEST TO EAST", // restrictions
           "",
           "",
           "",
           ""
       ], //MSG TEXT
       [], // MSG DATA
       [] // REPLIES
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
