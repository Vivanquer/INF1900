#include "son.h"

Son::Son(){
    DDRA |= (1 << PA1) | (1 << PA0);
}

void Son::soundPWMLow() {
    PORTA &= ~(1 << PORTA0) & ~(1 << PORTA1);
}

void Son::soundPWMHigh() {
    soundPWMLow();
    PORTA |= (1 << PORTA1);
}

uint8_t Son::chooseNoteFrequency(uint8_t operand) {
    const uint8_t MIN_NOTE = 45;
    uint8_t index = operand - MIN_NOTE;
    double frequencyTable[40] = {110, 110, 116.54, 123.47, 130.81, 138.59, 146.83,
                                 155.56, 164.81, 174.61, 185, 196, 207.65, 220,
                                 233.08, 246.94, 261.63, 277.18, 293.66, 311.13,
                                 329.63, 349.23, 369.99, 392, 415.3, 440, 466.16,
                                 493.88, 523.25, 554.37, 587.33, 622.25, 659.26,
                                 698.46, 739.99, 783.99, 830.61, 880};
    
    return static_cast<uint8_t>((F_CPU / (2 * PRESCALER * frequencyTable[index])) - 1);
}

// Fonction de délai personnalisé
void Son::myDelayMS(uint16_t operand) {
    const int PERSONALIZED_DELAY = 25;
    while (operand--) {
        _delay_ms(PERSONALIZED_DELAY);
    }
}

void Son::playSound(uint8_t note, uint16_t time){
    timer.startTimer(chooseNoteFrequency(note));
    myDelayMS(time);
    timer.stopTimer();
}