/******************************************************************************
* File Name: GPIO.h
* Description: This file contains function Prototypes of GPIO.c
* Tool-Chain: AVR GCC
*
* Modification History:
* Created by: GOKUL K V1.0 13/03/2021
* Description: V1.0
******************************************************************************/
#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED
/******************************************************************************
*                      Includes
******************************************************************************/

#include<stdlib.h>
#include<stdint.h>
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

/******************************************************************************
*                      Global Macros
******************************************************************************/
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)
#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0
#define F_CPU (16000000UL)



/******************************************************************************
* Public function prototypes
******************************************************************************/

void GPIOConfig(uint8_t pin,uint8_t mode);
void GPIOPinWrite(uint8_t pin,uint8_t state);
int GPIOPinRead(uint8_t pin);
void GPIO_Initialise(void);
/******************************************************************************
* End of File
******************************************************************************/

#endif // GPIO_H_INCLUDED
