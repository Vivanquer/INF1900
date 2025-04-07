/***************************************************************************************/
/*                                                                                     */
/* Auteurs:    Xing Wei, Alexandre Boutant, Elhadji-fallou-adama Gueye, Naoufel Brahmi */
/*                                                                                     */
/* Ce code est la définition de la classe Button et ses attributs. les methodes        */
/* de configuration du bouton pour les interuptions sont dans le fichier button.cpp    */
/*                                                                                     */
/***************************************************************************************/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

class Bouton {
public:
  Bouton(); 
  void useFallingEdge();
  void useAnyEdge();
  void useRisingEdge();
  ~Bouton();
};
