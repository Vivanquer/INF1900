#include "capteur.h"

Capteur::Capteur(){
    
    ADMUX  = ( 0 << REFS1 ) | ( 0 << REFS0 ) | ( 0 << ADLAR ) | ( 0 << MUX4 ) |
            ( 0 << MUX3 ) | ( 0 << MUX2 ) | ( 0 << MUX1) | ( 0 << MUX0 ) ;

   // ADC Status and Control Register A : 
   //  Active le convertisseur mais sans demarrer de conversion pour l'instant.
   //  Pas de declanchement automatique et aucune interruption suivant
   //  la fin d'une convertion. Division de l'horloge par 64 (il faudra
   //  donc 13 cycles du convertisseur * 64 pour terminer une conversion
   //  soit 832 cycles d'horloge soit 104 micro-secondes
    ADCSRA = ( 1 << ADEN ) | ( 0 << ADSC )  | ( 0 << ADATE ) | ( 0 << ADIF ) |
            ( 0 << ADIE ) | ( 1 << ADPS2 ) | ( 1 << ADPS1 ) | ( 0 << ADPS0 ) ;

    DDRA &= ~((1 << capteurD_) | (1 << capteurCentreD_) | (1 << capteurCentre_) | (1 << capteurCentreG_) | (1 << capteurG_)); // Set as input
    PORTA |= (1 << capteurD_) | (1 << capteurCentreD_) | (1 << capteurCentre_) | (1 << capteurCentreG_) | (1 << capteurG_);  // Enable pull-ups
}
// Initialization of ADC for dist measurement
// void Capteur::initADC() {
//     // Set the ADC reference to AVcc (5V) and select the sensor pin
//     ADMUX = (1 << REFS0) | (pinPoteau & 0x07);
//     // Enable the ADC and set prescaler to 64 for an 8 MHz clock
//     ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
// }

Capteur::~Capteur(){
    ADCSRA = 0 << ADEN ;
}

// Read ADC value from the specified pin
uint16_t Capteur::lectureADC(uint8_t pin) {
    uint16_t adcVal;

   // Garder les bits de ADMUX intacts, sauf les bit permettant 
   // la selection de l'entree
   ADMUX  &=  ~(( 1 << MUX4 ) | ( 1 << MUX3 ) | 
                ( 1 << MUX2 ) | ( 1 << MUX1)  | ( 1 << MUX0 ));

   // selectionner l'entree voulue
   ADMUX |= ((pin & 0x07) << MUX0) ;

   // demarrer la conversion
   ADCSRA |= ( 1 << ADSC );

   // Attendre la fin de la conversion soit 13 cycles du convertisseur.
   while( ! (ADCSRA & ( 1 << ADIF ) ) );

   // important: remettre le bit d'indication de fin de cycle a zero 
   // pour la prochaine conversion ce qui se fait en l'ajustant a un.
   ADCSRA |= (1 << ADIF);

   // Aller chercher le resultat sur 16 bits.
   adcVal =   ADCL ;
   adcVal +=  ADCH << 8;
   
   // resultat sur 16 bits
   return adcVal;
}

void Capteur::misAJourCapteur(){
    S1 = rubanLEDestAllume(capteurG_); 
    S2 = rubanLEDestAllume(capteurCentreG_);
    S3 = rubanLEDestAllume(capteurCentre_);
    S4 = rubanLEDestAllume(capteurCentreD_);
    S5 = rubanLEDestAllume(capteurD_);
}
// dist measurement functions
// uint16_t Capteur::distance() {
//     uint16_t adcValue = lectureADC(pinPoteau);
//     if (adcValue > 20) {
//         // Formula derived from the GP2Y0A21YK datasheet
//         return 4800 / (adcValue - 20);
//     }
//     return 0; // Indicates out of range
// }

bool Capteur::objetEstDetecte() {
    // uint16_t adc = lectureADC(pinPoteau);  // Read dist from the sensor
    uint16_t dist = lectureADC(pinPoteau);
    return (dist <= 300 && dist >= 120);
}

bool Capteur::objetEstA10cm() {
    uint16_t dist = lectureADC(pinPoteau);
    return (dist >= 400);
}

bool Capteur::rubanLEDestAllume(uint8_t pin) {
    return (PINA & (1 << pin));
}

bool Capteur::estCentre() {
    misAJourCapteur();  // Update sensor values before checking
    return rubanLEDestAllume(capteurCentre_) || 
          (rubanLEDestAllume(capteurCentre_) && rubanLEDestAllume(capteurCentreG_)) ||
          (rubanLEDestAllume(capteurCentre_) && rubanLEDestAllume(capteurCentreD_));
}

bool Capteur::estIntersectionGauche() {
    misAJourCapteur();
    if(S1 && S2 && S3){
        return true;
    }
    else{
        return false;
    }
}

bool Capteur::estIntersectionDroite() {
    misAJourCapteur();
    if(S3 && S4 && S5){
        return true;
    }
    else{ 
        return false;
    }
}

bool Capteur::estDevieDroite() {
    misAJourCapteur();
    if((S4 && S5)|| S5 || S4){
        return true;
    }
    else{
        return false;
    }
}

bool Capteur::estDevieGauche() {
    misAJourCapteur();
    if((S2 && S1) || S1 || S2){
        return true;
    }
    else{
        return false;
    }
}

bool Capteur::verifierUn(uint8_t capteur)
{
    switch(capteur)
    {
        case(capteurCentre_):
            return (rubanLEDestAllume(capteurCentre_));
            break;
        case(capteurCentreG_):
            return (rubanLEDestAllume(capteurCentreG_));
            break;
        case(capteurCentreD_):
            return (rubanLEDestAllume(capteurCentreD_));
            break;
        case(capteurG_):
            return (rubanLEDestAllume(capteurG_));
            break;
        case(capteurD_):
            return (rubanLEDestAllume(capteurD_));
            break;
        default:
            return false;
    }
}

bool Capteur::estToutBlanc() {
    misAJourCapteur();
    if (!S1 && !S2 && !S3 && !S4 && !S5){
        return true;
    }
    else{
        return false;
    }
}

bool Capteur::estToutNoir(){
    misAJourCapteur();
    if(S1 && S2 && S3 && S4 && S5){
        return true;
    }
    else{
        return false;
    }
}

bool Capteur::verifierAuMoinsUn()
{
    if (rubanLEDestAllume(capteurCentreG_) || rubanLEDestAllume(capteurCentre_) ||
        rubanLEDestAllume(capteurCentreD_) || rubanLEDestAllume(capteurG_) ||
        rubanLEDestAllume(capteurD_))
    {
        return true;
    }
    return false;
}
