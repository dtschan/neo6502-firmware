// ***************************************************************************************
// ***************************************************************************************
//
//      Name :      dispatch.c
//      Authors :   Paul Robson (paul@robsons.org.uk)
//      Date :      22nd November 2023
//      Reviewed :  No
//      Purpose :   Message dispatcher
//
// ***************************************************************************************
// ***************************************************************************************

#include "common.h"
#include "data/prompt.h"

#define DCOMMAND    (cBlock+0)
#define DFUNCTION   (cBlock+1)
#define DERROR      (cBlock+2)
#define DSTATUS     (cBlock+3)
#define DPARAMS     (cBlock+4)
#define DTOPSTACK   (cBlock+8)

// ***************************************************************************************
//
//							Handle commands sent by message
//
// ***************************************************************************************

void DSPHandler(uint8_t *cBlock,uint8_t *memory) {

       #include "data/dispatch_code.h"  

       *DCOMMAND = 0;															// Clear the message indicating completion.
}

// ***************************************************************************************
//
//     	  Polling code. Called at low repeat rate. About every 64k cycles is right.
//
// ***************************************************************************************

void DSPSync(void) {
    KBDSync();
}

// ***************************************************************************************
//
//     	  		Reset interfaces. Called at start, and also on command 0,0
//
// ***************************************************************************************

void DSPReset(void) {
    const char bootString[] = PROMPT;
    MEMInitialiseMemory();                                                      // Set up memory, load kernel ROM
    GFXSetMode(0);                                                              // Initialise graphics
    KBDInitialise();                                                            // Initialise keyboard
    KBDEvent(0,0xFF,0);                                                         // Reset the keyboard manager
    SNDInitialise();                                                            // Initialse sound
    const char *c = bootString;
    while (*c != '\0') CONWrite(*c++);	
}

// ***************************************************************************************
//
//      Date        Revision
//      ====        ========
//
// ***************************************************************************************