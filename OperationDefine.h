#ifndef OPERATIONDEFINE_H_INCLUDED
#define OPERATIONDEFINE_H_INCLUDED
#include <avr/io.h>
#include <avr/interrupt.h>
#include "GPIO.h"
#include "timer.h"

int timer_check = 0;

typedef struct
{
  volatile uint8_t FLAG_ISR0 : 1; // interrupt raised by SWITCH 1.
  volatile uint8_t FLAG_ISR1 : 1; // interrupt raised by Switch 2.
  volatile uint8_t FLAG_ISR2 : 1; // Interrupt raised by timer overflow.
}intflags;
intflags state_flags={0,0,0};


typedef enum
{
    S0_Idle,
    S1_SeatOccupied,
    S2_PWM,
    S3_Seatbelt_ON
}s;
s current_s= S0_Idle;


#endif // OPERATIONDEFINE_H_INCLUDED
