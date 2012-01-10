#ifndef MODO_PRACTICA_H_INCLUDED
#define MODO_PRACTICA_H_INCLUDED

/** Librerias necesarias para el funcionamiento de modo_practica.c/h */
#include <stdio.h>
#include <malloc.h>
#include "getch.h"
#include "mesa.h"
#include "carta.h"
#include "jugador.h"
#include "display.h"
#include "apuesta.h"
#include "entrada.h"

/** Determina si la ronda finalizo */
int _finRonda;

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

/** Verifica si todos los jugadores han hecho check en la ronda */
int allCheckorAllAlIn(Jugador *jugador);

/** Permite a todos los jugadores que hicieron check volver a jugar la siguiente ronda*/
void allUnCheck();

/** Borra los jugadores con dinero 0 */
void chaoPerdedores();

/** Inicializa la mesa */
void inicializarMesaJuego();

/** Inicializa los jugadores */
void inicializarJugadores();

#endif // MODO_PRACTICA_H_INCLUDED
