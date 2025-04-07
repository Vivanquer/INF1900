#define F_CPU 8000000UL
#include<stdio.h>
#include <avr/io.h>
#include "moteur.h"

Moteur::Moteur() {
    DDRD |= (1 << DDD4) | (1 << DDD5) | (1 << DDD6) | (1 << DDD7);
    PORTD |= (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7);
    
    TCNT2 = 0;
    TCCR2A |= (1 << WGM21) | (1 << WGM20) | (1 << COM2A1) | (1 << COM2B1);
    TCCR2B |= (1 << CS22); 
    }

void Moteur::reculer(uint8_t top) {
    DDRD |= (1 << DDD4) | (1 << DDD5);
    PORTD |= (1 << PD4) | (1 << PD5);
    
    OCR2A = (uint8_t)((top * 255) / 100);
    OCR2B = (uint8_t)((top * 255) / 100);
}

void Moteur::avancer(uint8_t top) {
    DDRD |= (1 << DDD4) | (1 << DDD5);
    PORTD &= ~(1 << PD4);
    PORTD &= ~(1 << PD5);
    
    OCR2A = (uint8_t)((top * 255) / 100);
    OCR2B = (uint8_t)((top * 255) / 100);
}

void Moteur::arreter() {
    // DDRD &= ~(1 << DDD6);
    // DDRD &= ~(1 << DDD7);
    OCR2A = 0;
    OCR2B = 0;
}

void Moteur::tournerDroite(uint8_t top) {
    DDRD |= (1 << DDD4) | (1 << DDD5);
    PORTD &= ~(1 << PD4);
    PORTD &= ~(1 << PD5);
    
    OCR2A = 0;
    OCR2B = (uint8_t)((top * 255) / 100);
}

void Moteur::tournerGauche(uint8_t top) {
    DDRD |= (1 << DDD4) | (1 << DDD5);
    PORTD &= ~(1 << PD4);
    PORTD &= ~(1 << PD5);
    
    OCR2A = (uint8_t)((top * 255) / 100);
    OCR2B = 0;

}