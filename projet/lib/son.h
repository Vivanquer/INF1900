#ifndef SON_H
#define SON_H

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "minuteries.h"

class Son{
public:
    Son();
    void soundPWMLow();
    void soundPWMHigh();
    uint8_t chooseNoteFrequency(uint8_t operand);
    void playSound(uint8_t note, uint16_t time);
    // Fonction de délai personnalisé
    void myDelayMS(uint16_t operand);
private:
    Timer0 timer;
    const uint16_t PRESCALER = 256;
};

#endif