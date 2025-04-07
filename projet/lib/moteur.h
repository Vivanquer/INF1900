/*************************************************************************************/
/*                                                                                   */
/* Auteurs:  Xing Wei, Alexandre Boutant, Elhadji-fallou-adama Gueye, Naoufel Brahmi */
/*                                                                                   */
/* Cette classe a pour but de générer un signal PWM qui servira a controler          */
/* la vitesse du moteur pour faire tourner les roues.                                */
/*                                                                                   */
/*************************************************************************************/
#ifndef MOTEUR_H
#define MOTEUR_H
#include <avr/io.h>

class Moteur {
public:
    Moteur();
    void avancer (uint8_t top);
    void reculer (uint8_t top);
    void arreter();
    void tournerGauche(uint8_t top);
    void tournerDroite(uint8_t top);
};

#endif