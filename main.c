/******************************************************************************
* File Name: main.c
* Description:  This file contains Logic for the Given Problem
* Tool-Chain: AVR GCC
*
*  Modification History:
*  Created by:      GOKUL K   V1.0      14/March/2021
*  Description:     V1.0
******************************************************************************/


/******************************************************************************
*                      Includes
******************************************************************************/
#include <stdint.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>
#include "OperationDefine.h"
#include "Application.h"
#include "flags.h"

/******************************************************************************
*                      Global Macros
******************************************************************************/
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)
#define TOGGLE_BIT(PORT,BIT) PORT^= (1<<BIT)
/******************************************************************************
*                      Global variables
******************************************************************************/



/******************************************************************************
*                      Main function
******************************************************************************/
int main(void)
{
    //**************GPIO ***************//

    GPIO_Initialise();

    //**************PWM ***************//

    PWM_initialise();

    //**************External interrupts***************//

    extInterrupt();
//While Loop starts

    while(1)
        {
        switch(current_s)
        {
            case S0_Idle:                                //idle state
                {
                    if(state_flags.FLAG_ISR0 == 0)               //if the seat is  not occupied
                    {
                        if(state_flags.FLAG_ISR1 == 1)           //if the seatbelt is on
                            indiON();                         //make seat belt LED on
                        else
                            indiOFF();                        //make seatbelt LED off
                    }
                    else
                    current_s = S1_SeatOccupied;        //move to next state
                    break;
                }
            case S1_SeatOccupied:                         //seat occupied state
                {
                    if(state_flags.FLAG_ISR1==1)                      //if the seatbelt is on
                    current_s=S3_Seatbelt_ON;             // nothing to do : move to final state
                    else
                    {
                        indiOFF();                                 //make seat belt LED off
                        if(timer_check==0)
                        {
                            start_timer();                        //start timer for 15 seconds
                        }
                        if(state_flags.FLAG_ISR2==1)                   //timer overflow flag high
                        {
                            current_s=S2_PWM;                //move to Next state
                            state_flags.FLAG_ISR2=0;                     //clear the timer flag bit
                            timer_check=0;
                        }
                    }
                    break;
                }
            case S2_PWM:                                //buzzer state
                {
                    if(state_flags.FLAG_ISR0==0)                    //seat is not occupied
                    {
                        current_s=S0_Idle;               //move to idle state
                        Buzzer_OFF();                               //make buzzer off
                    }
                    else if(state_flags.FLAG_ISR1==1)                 //seat belt is on
                    {
                        current_s=S3_Seatbelt_ON;          //move to seat belt on state
                        Buzzer_OFF();                                 // make buzzer off
                    }
                    else
                    {
                        Buzzer_50();                                  //make buzzer on
                    }
                    break;
                }
            case S3_Seatbelt_ON:                          //seat belt on state
                if(state_flags.FLAG_ISR1==1)                //seat belt is in
                {
                    current_s=S0_Idle;           // move to idle state
                    indiON();               //make seatbelt LED on
                }
        }
    }

    return 0;
}




void start_timer()
{
    timerInit();           //call timer1 initialize
    timer_check=1;
}

void stopper()
{
    TCCR1B = 0X00;          //stop timer by making clock source zero
}
