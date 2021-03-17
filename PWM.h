/******************************************************************************
* File Name: PWM.h
* Description: This file contains function Prototypes of PWM.c
* Tool-Chain: AVR GCC
*
* Modification History:
* Created by: Gokul K V1.0 13/March/2021
* Description: V1.0
*
******************************************************************************/
#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED
#include <stdint.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>
#include "GPIO.h"


void PWM_initialise(void);
void PWM_50(void);
void PWM_OFF(void);
#endif // PWM_H_INCLUDED
/******************************************************************************
* End of File
******************************************************************************/
