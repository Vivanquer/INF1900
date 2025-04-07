#ifndef PARCOURSJ_H
#define PARCOURSJ_H
#include <avr/io.h>
#include <util/delay.h>
#include "deplacement.h"

class Deplacement;  
class Robot; 

class ParcoursJ{
public:
    ParcoursJ();
    void faireTrajetJ();
    void trajetKLM();
    void trajetNOP();
private:
    Deplacement deplacement;
    Robot robot;
    char position;
};

#endif