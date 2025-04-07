#include "led.h"

LED::LED()
{
    DDRB = (1 << PORTB0) | (1 << PB1);
}
void LED::lightGreen()  
{
    PORTB&= ~(1 << PB1);
    PORTB|= (1 << PB0);
}

void LED::lightRed()      
{ 
    PORTB&=~ (1 << PB0);
    PORTB|= (1 << PB1);
}

void LED::lightOff()  
{
    PORTB&=~ (1 << PB0);
    PORTB&=~ (1 << PB1);
}

void LED::lightAmber()
{
    lightGreen();
    _delay_ms(AMBER_DELAY);
    lightRed();
    _delay_ms(AMBER_DELAY);
}

LED::~LED(){}
