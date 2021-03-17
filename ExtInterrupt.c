/******************************************************************************
* File Name: ExtInterrupt.C
* Description: This file contains API definitions for External Interrupt functionality
* Tool-Chain: AVR GCC
* Modification History:
* Created by: GOKUL K V1.0 14/March/2021
* Description: V1.0
******************************************************************************/
/******************************************************************************

* Includes
******************************************************************************/
#include "ExtInterrupt.h"
/******************************************************************************
*                      Global Macros
******************************************************************************/
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)
#define TOGGLE_BIT(PORT,BIT) PORT^= (1<<BIT)


void extInterrupt(void){
    EIMSK|=(1<<INT1)|(1<<INT0);
    EICRA|=(1<<ISC00);
    EICRA&=~(1<<ISC01);
    EICRA|=(1<<ISC10);
    EICRA&=~(1<<ISC11);
    sei();                  // SREG|=(1<<7); macros to enable global INT sei(); cli();

}
