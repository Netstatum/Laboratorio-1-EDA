#ifndef _H_DISPLAY_
#define _H_DISPLAY_

/*Aqui se encuentras las funciones para mostrar informacion al usuario hacerca
 * del estado del juego*/

#include "carta.h"


/*Formatea y muestra las variables dadas segun lo especificado en el lab*/
/*TODO: Falta agregar las probabilidades*/
void display_principal(CARTA cartas_mesa[], CARTA cartas_jugador[]);

/*Limpia la pantalla eliminando los caracteres actuales*/
void limpiar();

#endif
