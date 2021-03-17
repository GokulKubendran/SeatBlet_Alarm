/******************************************************************************
* File Name: Timer.C
* Description: This file contains API definitions for Timer functionality
* Tool-Chain: AVR GCC
* Modification History:
* Created by: GOKUL K V1.0 14/March/2021
* Description: V1.0
******************************************************************************/
/******************************************************************************

* Includes
******************************************************************************/
#include <stdint.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>
#include "PWM.h"
#include "Application.h"
#include "GPIO.h"
#include "Timer.h"
/******************************************************************************
*                      Global Macros
******************************************************************************/
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)
#define TOGGLE_BIT(PORT,BIT) PORT^= (1<<BIT)


void timerInit()
    {
    TCCR1A=0x00;
    TCCR1B|=(1<<CS10);          //presclaer
    TCCR1B|=(1<<CS12);          //prescaler
    TCNT1=0x48E4;               //timer start value
    TIMSK1 |=(1<<TOIE1);        //timer overflow interrrupt enable
    sei();
    }

 /******************************************************************************
* End of File
******************************************************************************/
