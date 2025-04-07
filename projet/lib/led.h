/************************************************************************************/
/*                                                                                  */
/* Auteurs: Xing Wei, Alexandre Boutant, Elhadji-fallou-adama Gueye, Naoufel Brahmi */
/*                                                                                  */
/* Ce code est la définition de la classe LED et ses attributs. les methodes        */
/* d'allumage de la LED et sa configuration sont dans le fichier light.cpp          */
/* Le constructeur prend en parametres le PORT de branchement le DDRC et les        */ 
/* pin de la LED sur la carte                                                       */
/*                                                                                  */
/************************************************************************************/

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>

class LED{
public:
    LED();

    void lightRed();
    void lightGreen();
    void lightOff();
    void lightAmber();
    ~LED();

private:
    static const uint8_t AMBER_DELAY = 2;
};
