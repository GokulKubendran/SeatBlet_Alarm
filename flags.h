#ifndef FLAGS_H_INCLUDED
#define FLAGS_H_INCLUDED
ISR(INT0_vect)
{
     state_flags.FLAG_ISR0 = state_flags.FLAG_ISR0^1;
}

ISR(INT1_vect)
{
    state_flags.FLAG_ISR1 = state_flags.FLAG_ISR1^1;
}

ISR(TIMER1_OVF_vect)
{
    static uint16_t counter;
    counter++;
    if(counter >= 3)
    {
        state_flags.FLAG_ISR2 = 1;
        counter=0;
        stopper();
    }
    else{
        state_flags.FLAG_ISR2 = 0;
    }
}


#endif // FLAGS_H_INCLUDED
