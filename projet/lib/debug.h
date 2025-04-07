/************************************************************************************/
/*                                                                                  */
/* Auteurs: Xing Wei, Alexandre Boutant, Elhadji-fallou-adama Gueye, Naoufel Brahmi */
/*                                                                                  */           
/* Ce fichier définit une classe Debug qui gère l'affichage de messages de débogage */
/* via RS-232 (UART). Il permet d'envoyer des messages à un PC ou un autre          */
/* périphérique pour aider à analyser le fonctionnement du programme.               */
/*                                                                                  */
/************************************************************************************/

#ifndef DEBUG_H
#define DEBUG_H

#include "rs232.h"
#include <stdio.h>

#ifdef DEBUG
    #define DEBUG_PRINT(msg) Debug::print(msg)
    #define DEBUG_PRINT_VAR(label, var) Debug::printVar(label, var)
#else
    #define DEBUG_PRINT(msg) do {} while (0)
    #define DEBUG_PRINT_VAR(label, var) do {} while (0)
#endif

class Debug {
public:
    static void init();
    static void print(const char* msg);
    static void printVar(const char* label, int var);
};

#endif // DEBUG_H