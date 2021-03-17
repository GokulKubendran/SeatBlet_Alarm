/******************************************************************************
* File Name: Application.h
* Description: This file contains function Prototypes of Application.c
* Tool-Chain: AVR GCC
*
* Modification History:
* Created by: Gokul K V1.0 13/March/2021
* Description: V1.0
*
******************************************************************************/
#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include<stdint.h>
#include<string.h>
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include "PWM.h"
#include "GPIO.h"
#include "Timer.h"


/******************************************************************************
* Public function prototypes
******************************************************************************/


void ledON();
void ledOFF();

#endif // APPLICATION_H_INCLUDED
/******************************************************************************
* End of File
******************************************************************************/
