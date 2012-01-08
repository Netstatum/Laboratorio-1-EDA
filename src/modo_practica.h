#ifndef MODO_PRACTICA_H_INCLUDED
#define MODO_PRACTICA_H_INCLUDED

/** Librerias necesarias para el funcionamiento de modo_practica.c/h */
#include <malloc.h>
#include "getch.h"
#include "mesa.h"
#include "carta.h"
#include "jugador.h"
#include "display.h"

/** Función modo_practica, esta función es la encargada de inicializar la partida
    para el modo practica y lanzar el juego
*/
int modo_practica();

/** Preguntara al usuario la cantidad de jugadores involucrados en la partida
    Y el monto inicial de cada uno de ellos
*/
void cantidad_jugadores();

/** Entra la informacion sobre algunos aspectos basicos para tener en cuenta al jugar
    entre varios jugadores
*/
void info_de_juego();

/** Da inicio al modo como tal */
int comienzaMP();

/** Hace el calculo de la proporción que le corresponde al jugador del poso total */
int calculoPP(Jugador *jugador);

#endif // MODO_PRACTICA_H_INCLUDED
