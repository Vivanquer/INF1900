#ifndef PARCOURSA_H
#define PARCOURSA_H
#include <avr/io.h>
#include <util/delay.h>
#include "deplacement.h"
#include "robot.h"

class Robot; 

class ParcoursA{
public:
    ParcoursA();
    void faireTrajetA(char d1, char d2);
    void trajetBC(char direction);
    void trajetCD(char direction);
    void trajetDE();
    void trajetEF();
    void trajetFG();
    void trajetGHI();
    void trajetIE();
    void trajetFJ();

private:
    Deplacement deplacement;
    Robot robot;
    char position;
};

#endif