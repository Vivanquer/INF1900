#include "deplacement.h"

Deplacement::Deplacement(){

}

void Deplacement::suivreLigne(){
    while(moteurOn){
        if(capteur.estCentre()){
            moteur.avancer(50);
        }
        else if(capteur.estDevieDroite()){
            led.lightGreen();
            moteur.tournerDroite(50);
        }
        else if(capteur.estDevieGauche()){
            led.lightRed();
            moteur.tournerGauche(50);
        }
        else{
            moteur.arreter();
            led.lightOff();
            _delay_ms(1000);
            // ajusterCentre();
            moteurOn = false;
        }
    }
    
}

void Deplacement::ajusterCentre(){
    moteur.avancer(50);
    _delay_ms(1000);
    moteur.arreter();
    _delay_ms(1000);
}

void Deplacement::toggleMoteurOn(){
    moteurOn = true;
};

void Deplacement::tournerGauche(uint8_t vitesse){
    moteur.tournerGauche(vitesse);
    _delay_ms(750);
    while(!capteur.estCentre()){
        moteur.tournerGauche(vitesse);
    }
    moteur.arreter();
}

void Deplacement::tournerDroite(uint8_t vitesse){
    moteur.tournerDroite(vitesse);
    _delay_ms(750);
    while(!capteur.estCentre()){
        moteur.tournerDroite(vitesse);
    }
    moteur.arreter();
}