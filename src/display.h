#ifndef _H_DISPLAY_
#define _H_DISPLAY_

/*Aqui se encuentras las funciones para mostrar informacion al usuario hacerca
 * del estado del juego*/

#include "carta.h"


/*Formatea y muestra las variables dadas segun lo especificado en el lab*/
/*TODO: Falta agregar las probabilidades
 * ARGUMENTOS:
 * 	cartas_mesa: Un array con 3, 4, o 5 cartas a mostrar en la mesa si es
 * 	NULL entonces se muestra una mesa sin cartas
 * 	cantidad_cartas_mesa: El numero de cartas que contiene cartas_mesa
 * 	cartas_jugador: Las cartas del jugador, si el jugador no tiene cartas
 * 	entonces es NULL*/
void display_principal(CARTA cartas_mesa[], unsigned int cantidad_cartas_mesa, CARTA cartas_jugador[]);

/*Limpia la pantalla eliminando los caracteres actuales*/
void limpiar();

#endif
