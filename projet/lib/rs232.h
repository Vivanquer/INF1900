/************************************************************************************/
/*                                                                                  */
/* Auteurs: Xing Wei, Alexandre Boutant, Elhadji-fallou-adama Gueye, Naoufel Brahmi */
/*                                                                                  */                                                             
/* Ce fichier est destiné à gérer la communication série via le protocole RS-232    */
/* sur un microcontrôleur Atmel AVR. Il définit la classe RS232, qui permet         */
/* l’envoi et la réception de données par UART (Universal Asynchronous              */   
/* Receiver-Transmitter).                                                           */
/*                                                                                  */
/************************************************************************************/

#ifndef RS232_H
#define RS232_H

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <util/twi.h>
#include <string.h>
#include "memoire_24.h"

class RS232 {
public:
    RS232(); 
    void transmissionUART( uint8_t donnee );
    uint8_t receptionUSART(void);
    ~RS232();
};

#endif // RS232_H


