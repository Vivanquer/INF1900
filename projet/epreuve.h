#ifndef EPREUVE_H
#define EPREUVE_H
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "deplacement.h"
#include "parcoursA.h"
#include "parcoursJ.h"


class Epreuve{
public:
    Epreuve();
    void startEpreuve(char d1, char d2);
    void switchCaseStart(char start, char d1, char d2);
    void adjustStart();
private:
    Robot robot;
    Deplacement deplacement;
    char start;
    ParcoursA pkA;
    ParcoursJ pkJ;
};

#endif