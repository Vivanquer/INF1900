#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "capteur.h"
#include "moteur.h"
#include "led.h"

class Deplacement {
public:
    Deplacement();
    bool moteurOn = true;
    void suivreLigne();
    void ajusterCentre();
    void toggleMoteurOn();
    void tournerGauche(uint8_t vitesse);
    void tournerDroite(uint8_t vitesse);

private:
    const uint8_t VITESSE_CINQUANTE = 50;
    const uint8_t VITESSE_QUATHUIT = 80;
    const uint8_t DELAI_DIX = 10;
    Moteur moteur;
    Capteur capteur;
    LED led;
};

#endif