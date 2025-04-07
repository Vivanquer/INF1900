#ifndef TRAJETAJ_H
#define TRAJETAJ_H
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "deplacement.h"

class trajetAJ {
public:
    trajetAJ();
    void BC(char direction);
    void CD(char direction);
    void EF();
    void FG();
    void GHI();
    void IE();
    void FJ();
private:
    Deplacement deplacement;
};


#endif