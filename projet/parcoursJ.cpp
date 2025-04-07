#include "parcoursJ.h"

ParcoursJ::ParcoursJ(){

};

void ParcoursJ::faireTrajetJ(){
    trajetKLM();
    trajetNOP();
};

void ParcoursJ::trajetKLM(){
    if(robot.capteur.objetEstDetecte()){
        deplacement.tournerDroite(60);
        deplacement.avancer(50);
        if(robot.capteur.estIntersectionGauche()){
            deplacement.arreter();
            deplacement.ajusterCentre();
            deplacement.tournerGauche(60);
            if(robot.capteur.objetEstDetecte()){
                position = 'M';
                deplacement.tournerGauche(60);
                deplacement.avancer(50);
                if(robot.capteur.estToutNoir()||robot.capteur.estIntersectionDroite()||robot.capteur.estIntersectionGauche()){
                    deplacement.arreter();
                    deplacement.ajusterCentre();
                    deplacement.avancer(50);
                    if(robot.capteur.estIntersectionDroite()){
                        deplacement.arreter();
                        deplacement.ajusterCentre();
                        deplacement.tournerDroite(60);
                        deplacement.avancer(50);
                        if(robot.capteur.estIntersectionDroite()){
                            deplacement.arreter();
                            deplacement.ajusterCentre();
                            deplacement.avancer(50);
                            if(robot.capteur.estIntersectionDroite()){
                                deplacement.arreter();
                                deplacement.ajusterCentre();
                            }
                        }
                    }
                }
            }
            else{
                position = 'K';
                deplacement.avancer(50);
                if(robot.capteur.estIntersectionGauche()){
                    deplacement.arreter();
                    deplacement.ajusterCentre();
                    deplacement.avancer(50);
                    if(robot.capteur.estIntersectionGauche()){
                        deplacement.arreter();
                        deplacement.ajusterCentre();
                    }
                }
            }
        }
    }
    else{
        deplacement.avancer(50);
        if(robot.capteur.estToutNoir()||robot.capteur.estIntersectionDroite()||robot.capteur.estIntersectionGauche()){
            deplacement.arreter();
            deplacement.ajusterCentre();
            deplacement.avancer(50);
            if(robot.capteur.estToutNoir()||robot.capteur.estIntersectionDroite()||robot.capteur.estIntersectionGauche()){
                deplacement.arreter();
                deplacement.ajusterCentre();
                position = 'L';
            }
        }
    }
}