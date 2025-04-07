#include "parcoursA.h"
#include "deplacement.h"

ParcoursA::ParcoursA(){

};

void ParcoursA::faireTrajetA(char direction1, char direction2){

    trajetBC(direction1);
    trajetCD(direction2);
    trajetDE();
    trajetEF();
    trajetFG();
    trajetGHI();
    trajetIE();
    trajetEF();
    trajetFJ();

};

void ParcoursA::trajetBC(char direction){

    switch (direction){
        case 'G':
            deplacement.tournerGauche(80);
            _delay_ms(100);
            deplacement.avancer(50);
            break;
        case 'D':
            deplacement.tournerDroite(80);
            _delay_ms(100);
            deplacement.avancer(50);
            break;
        default:
            break;
    }

    if (robot.capteur.estToutBlanc()){
        deplacement.arreter();
        _delay_ms(100);
    }
    
    position = 'C';

};

void ParcoursA::trajetCD(char direction){

    switch (direction){
        case 'G':
            deplacement.tournerGauche(80);
            _delay_ms(100);
            deplacement.avancer(50);
            if(robot.capteur.estIntersectionDroite()){
                deplacement.arreter();
            }
            _delay_ms(100);
            deplacement.tournerDroite(80);
            _delay_ms(100);
            break;
        case 'D':
            deplacement.tournerDroite(80);
            _delay_ms(100);
            deplacement.avancer(50);
            if(robot.capteur.estIntersectionGauche()){
                deplacement.arreter();
            }
            _delay_ms(100);
            deplacement.tournerGauche(80);
            _delay_ms(100);
            break;
        default:
            break;
    }

    deplacement.avancer(50);

    if(robot.capteur.estIntersectionDroite()){
        deplacement.arreter();
        _delay_ms(100);
        deplacement.ajusterCentre();
    }

    deplacement.tournerDroite(80);
    _delay_ms(100);

    position = 'D';

};

void ParcoursA::trajetDE(){
    
    deplacement.avancer(50);

    if(robot.capteur.estIntersectionDroite()){
        deplacement.arreter();
        _delay_ms(100);
        deplacement.ajusterCentre();
    }

    position = 'E';

};

void ParcoursA::trajetEF(){

    deplacement.avancer(50);

    if(robot.capteur.estIntersectionDroite()){
        deplacement.arreter();
        _delay_ms(100);
        deplacement.ajusterCentre();
    }

    position = 'F';
};

void ParcoursA::trajetFG(){

    deplacement.tournerDroite(80);
    _delay_ms(100);
    deplacement.avancer(50);
    
    if(robot.capteur.estIntersectionDroite()){
        deplacement.arreter();
        _delay_ms(100);
        deplacement.ajusterCentre();
    }

    position = 'G';
}

void ParcoursA::trajetGHI(){

    deplacement.tournerDroite(40);
    _delay_ms(250);

    // TODO
    // ALLUMAGE DE LED A AJOUTER

    if(robot.capteur.objetEstDetecte()){

        deplacement.tournerDroite(70);
        _delay_ms(100);
        deplacement.avancer(50);

        if(robot.capteur.estIntersectionDroite()){
            deplacement.arreter();
            _delay_ms(100);
            deplacement.ajusterCentre();
        }

        deplacement.tournerDroite(70);

        position = 'I';

    }

    else{
        deplacement.avancer(50);

        if(robot.capteur.estIntersectionDroite() || robot.capteur.estToutNoir()){
            deplacement.arreter();
        }

        _delay_ms(200);

        position = 'H';

        deplacement.tournerDroite(60);
        _delay_ms(100);
        deplacement.avancer(50);
        if(robot.capteur.estIntersectionDroite()){
            deplacement.arreter();
            _delay_ms(100);
            deplacement.ajusterCentre();
        }

        position = 'I';
    }
}

void ParcoursA::trajetIE(){

    deplacement.avancer(50);

    if(robot.capteur.estIntersectionDroite()||robot.capteur.estIntersectionGauche()||robot.capteur.estToutNoir()){
        deplacement.arreter();
        _delay_ms(100);
        deplacement.ajusterCentre();
        deplacement.tournerDroite(70);

        position = 'E';
    }

}

void ParcoursA::trajetFJ(){

    deplacement.avancer(50);
    
    if(robot.capteur.estIntersectionDroite()){
        deplacement.arreter();
        _delay_ms(100);
        deplacement.ajusterCentre();
    }
    
    deplacement.tournerDroite(70);

    position = 'J';
}