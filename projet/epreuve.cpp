#include "epreuve.h"

void Epreuve::startEpreuve(char d1, char d2){
    deplacement.avancer(50);
    if(robot.capteur.estToutNoir()){
        deplacement.arreter();
        deplacement.ajusterCentre();
        start = 'J';
    }
    else if(robot.capteur.estToutBlanc()){
        deplacement.arreter();
        deplacement.ajusterCentre();
        start = 'A';
    }
    switchCaseStart(start, d1, d2);
}

void Epreuve::switchCaseStart(char start, char d1, char d2){
    switch (start){
        case 'A':
            pkA.faireTrajetA(d1,d2);
            adjustStart();
            pkJ.faireTrajetJ();
            break;
        case 'J':
            pkJ.faireTrajetJ();
            adjustStart();
            pkA.faireTrajetA(d1,d2);
            break;
        default:
            break;
    }
}

void Epreuve::adjustStart(){
    deplacement.avancer(50);
    if(robot.capteur.estToutBlanc()||robot.capteur.estToutNoir()){
        deplacement.arreter();
        deplacement.ajusterCentre();
    }
}