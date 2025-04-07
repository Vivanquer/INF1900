#include "bouton.h"

Bouton::Bouton(){
    cli();
    EIMSK |= (1 << INT0);
    EICRA |= (1 << ISC01); 
    sei ();
}
void Bouton::useFallingEdge(){
    cli();  // Disable interrupts to configure
    EICRA &= ~(1 << ISC00); // Clear ISC00
    EICRA |= (1 << ISC01);  // Set ISC01 for falling edge
    sei();  // Enable interrupts after configuration
}
void Bouton::useAnyEdge(){
    cli();
    EICRA |= (1 << ISC00);   // Set ISC00 for any edge
    EICRA |= (1 << ISC01);
    sei();
}
void Bouton::useRisingEdge(){
    cli();  // Disable interrupts to configure
    EICRA |= (1 << ISC00);  // Set ISC00 for rising edge
    EICRA |= (1 << ISC01);  // Set ISC01 for rising edge
    sei();  // Enable interrupts after configuration
}
Bouton::~Bouton(){
    cli();  // Disable interrupts to configure
    EIMSK &= ~(1 << INT0);  // Disable external interrupt for INT0
    EICRA &= ~(1 << ISC00) & ~(1 << ISC01);  // Clear edge detection bits for INT0
    sei();  // Enable interrupts after configuration
}

