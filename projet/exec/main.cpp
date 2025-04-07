#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h> 
#include <avr/interrupt.h>
// #include "capteur.h"
// #include "led.h"
#include "deplacement.h"

// static Capteur capteur;
// static LED led;
// static Moteur moteur;
static Deplacement deplacement;

bool moving = true;

int main(){
    // while (moving)
    // {
    //     // moteur.avancer(50);
    //     // while(!capteur.estCentre()){
    //     //     led.lightGreen();
    //     //     moteur.arreter();
    //     //     _delay_ms(200);
    //     //     if(capteur.estDevieDroite()){
    //     //         moteur.tournerDroite(50);
    //     //         led.lightGreen();
                
    //     //     }
    //     //     else if(capteur.estDevieGauche()){
    //     //         moteur.tournerGauche(50);
    //     //     }
    //     //     _delay_ms(100);
    //     // }
    //     // led.lightOff();

    //     // Capteur capteur;
    //     // LED led;
    //     // if(capteur.estIntersectionDroite()){
    //     //     led.lightGreen();
    //     // }
    //     // else if(capteur.estIntersectionGauche()){
    //     //     led.lightRed();
    //     // }
    //     // else{
    //     //     led.lightOff();
    //     // }
    //     moving = deplacement.suivreLigne();
    // }
    deplacement.suivreLigne();
    deplacement.tournerDroite(50);
    deplacement.toggleMoteurOn();
    deplacement.suivreLigne();
    deplacement.tournerGauche(50);
    deplacement.toggleMoteurOn();
    deplacement.suivreLigne();
    deplacement.ajusterCentre();
    deplacement.tournerDroite(50);
    deplacement.toggleMoteurOn();
    deplacement.suivreLigne();
    deplacement.ajusterCentre();
    deplacement.tournerDroite(50);
}