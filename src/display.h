#ifndef _H_DISPLAY_
#define _H_DISPLAY_

/** Para las funciones de C usadas en este archivo */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*Aqui se encuentras las funciones para mostrar informacion al usuario hacerca
 * del estado del juego*/

#include "carta.h"
#include "mesa.h"
#include "jugador.h"

/** Aqui se encuentran las funciones para acceder a ciertos datos como el titulo o calculos
    particulares
 */
#include "ascii.h"
#include "menu.h"
#include "modo_practica.h"

/*Formatea y muestra las variables dadas segun lo especificado en el lab*/
/*TODO: Falta agregar las probabilidades
 * ARGUMENTOS:
 * 	cartas_mesa: Un array con 3, 4, o 5 cartas a mostrar en la mesa si es
 * 	NULL entonces se muestra una mesa sin cartas
 *
 * 	cantidad_cartas_mesa: El numero de cartas que contiene cartas_mesa. Si
 * 	la cantidad de cartas es menor que 3 o mayor que 5 no muestra nada en la
 * 	mesa
 *
 * 	cartas_jugador: Las cartas del jugador, si el jugador no tiene cartas
 * 	entonces es NULL*/
void display_principal(Jugador *jugando, CARTA cartas_mesa[], unsigned int cantidad_cartas_mesa, CARTA cartas_jugador[]);

/*Muestra solamente las cartas en la pantalla
 * ARGUMENTOS:
 * 	NULL entonces se muestra una mesa sin cartas
 *
 * 	cantidad_cartas_mesa: El numero de cartas que contiene cartas_mesa. Si
 * 	la cantidad de cartas es menor que 3 o mayor que 5 no muestra nada en la
 * 	mesa
 *
 * 	cartas_jugador: Las cartas del jugador, si el jugador no tiene cartas
 * 	entonces es NULL*/
void display_modo_apoyo(CARTA cartas_mesa[], unsigned int cantidad_cartas_mesa, CARTA cartas_jugador[]);

/*Limpia la pantalla eliminando los caracteres actuales*/
void limpiar();

#endif
