/******************************************************************************
* File Name: PWM.C
* Description: This file contains API definitions for PWM functionality
* Tool-Chain: AVR GCC
* Modification History:
* Created by: GOKUL K V1.0 14/March/2021
* Description: V1.0
******************************************************************************/
/******************************************************************************

* Includes
******************************************************************************/
#include "PWM.h"
/******************************************************************************
*                      Global Macros
******************************************************************************/
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)
#define TOGGLE_BIT(PORT,BIT) PORT^= (1<<BIT)


void PWM_initialise()
{
    TCCR0A|=((1<<WGM01)|(1<<WGM00));            //setting timer mode to Fast PWM
    TCCR0A|=(1<<COM0A1);
    TCCR0A&=~(1<<COM0A0);
    TCNT0=0x00;                                 //timer start value
    TCCR0B |= ((1 << CS00) | (1 << CS02));      //prescaler value 1024
    TCCR0B &= ~(1 << CS01);

}
void Buzzer_50()
{
    OCR0A = 128;
}

void Buzzer_OFF()
{
    OCR0A = 0;
}

/******************************************************************************
* End of File
******************************************************************************/
