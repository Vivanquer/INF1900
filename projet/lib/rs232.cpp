#include "rs232.h"

RS232::RS232(){
    UBRR0H = 0;
    UBRR0L = 0xCF;
    UCSR0B |= (1 << TXEN0) | (1 << RXEN0);
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
}

void RS232::transmissionUART ( uint8_t donnee ) {
    while ( !( UCSR0A & (1<<UDRE0)) );
    UDR0 = donnee;
}

uint8_t RS232::receptionUSART(void)
{
    while(!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

RS232::~RS232(){}