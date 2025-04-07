#include "trajetAJ.h"

void trajetAJ::BC(char direction){
    switch(direction){
        case 'G':
            
            deplacement.suivreLigne();
        default:
        break;
    }
}