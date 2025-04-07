#ifndef CAPTEUR_H
#define CAPTEUR_H
#pragma once

#include <avr/io.h>
#include "can.h"

class Capteur{
public:
    Capteur(); //Constructeur Capteur   ** A AJOUTER POUR DETECTION POTEAU **
    bool rubanLEDestAllume(uint8_t pin); // Regarde si LED est allumer pour capteur Ruban
    void initADC();
    uint16_t lectureADC(uint8_t pin);
    void misAJourCapteur();
    uint16_t distance();
    bool objetEstDetecte();
    bool objetEstA10cm();
    bool estCentre(); // Regarde si au moins un des 3 LED au milieu est allumée
    bool estIntersectionDroite(); // Regarde si les 3 LED a droites sont allumées
    bool estIntersectionGauche(); // Regarde si les 3 LED a gauches sont allumées
    bool estDevieDroite(); // Regarde si les deux leds sur l'extrémité droite sont allumées
    bool estDevieGauche(); // Regarde si les deux leds sur l'extrémité gauche sont allumées
    bool estToutBlanc(); // Regarde si aucune LED est allumée
    bool estToutNoir(); // Regarde si toutes les LED sont allumées
    bool verifierUn(uint8_t capteur);
    bool verifierAuMoinsUn();

    

    ~Capteur();

    

private:
    // static const uint8_t S1_PIN = PA6;
    // static const uint8_t S2_PIN = PA5;
    // static const uint8_t S3_PIN = PA4;
    // static const uint8_t S4_PIN = PA3;
    // static const uint8_t S5_PIN = PA2;

    static const uint8_t capteurG_ = PA2;
    static const uint8_t capteurCentreG_ = PA3;
    static const uint8_t capteurCentre_ = PA4;
    static const uint8_t capteurCentreD_ = PA5;
    static const uint8_t capteurD_ = PA6;

    // ADC sensor for distance measurement
    uint8_t pinPoteau = 7; // ADC channel for the distance sensor

    // Line sensor states
    bool S1, S2, S3, S4, S5;



    


};

#endif
