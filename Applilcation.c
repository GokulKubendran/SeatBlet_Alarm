/******************************************************************************
* File Name: AppMode.c
* Description:  This file contains Logic for the Given Problem
* Tool-Chain: AVR GCC
*
*  Modification History:
*  Created by:      GOKUL K V1.0      23/Sept/2020
*  Description:     V1.0
******************************************************************************/

/******************************************************************************
*                      Includes
******************************************************************************/
#include "Application.h"

/******************************************************************************
*                      Global variables
******************************************************************************/
#define SET_BIT(PORT,BIT) PORT|= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&= ~(1<<BIT)
#define TOGGLE_BIT(PORT,BIT) PORT^= (1<<BIT)

/******************************************************************************
*                      Global variables
******************************************************************************/


void indiON()
{
    GPIOPinWrite(PD5,HIGH);
}

void indiOFF()
{
    GPIOPinWrite(PD5,LOW);
}




