#ifndef _H_MESA_
#define _H_MESA_

#include "carta.h"

/** Estructura tipo mesa de juego
    @var CARTA cartasJugadas[4]: son las 5 cartas que deben jugarse durante una partida
         int pozoApuestas: apuesta total realizada en cada instante
*/
struct mesa{
    CARTA cartasJugada[4];
    int pozoApuestas;
    int apuesta_maxima;
};
typedef struct mesa MESA;

/** Mesa de juego */
MESA mesaJuego;

/** Mazo de 52 cartas */
CARTA mazo[_cartas];

/** Funcion generadorDelMazo
    Genera un mazo de 52 cartas ordenados en orden: corazon, diamante, trebol y pica,
    del número 1 al 13 por pinta
*/
void generadorDelMazo();

/** Funcion mazoNuevo para "poner" todas las cartas de vuelta al mazo
    los valores de [jugada] de todas las cartas se hacen 0
*/
void mazoNuevo();

/** Función Flop, es la encargada de mostrar las primeras tres cartas en la segunda ronda de la partida
    Usa un valor aleatorio para acceder al mazo, esto provoca un efecto de revolver el mazo sin realmente
    hacerlo
*/
void flop();

/** Función turnORriver, es la encargada de mostrar las ultimas dos cartas en la tercera y cuarta ronda de la partida
    Usa un valor aleatorio para acceder al mazo, esto provoca un efecto de revolver el mazo sin realmente
    hacerlo
    @param int ronda: valor de la ronda en la que se encuentran, este valor debe ser:
                        3: para hacer el turn
                        4: para hacer el river
                      no debe ingresarse otro número
*/
void turnORriver(int ronda);

/** Funcion repartirCartas para darle 2 cartas a cada jugador de la partida
    @param Jugador *primero: puntero al primer jugador, a partir de este y hacia el segundo se iran
                             repartiendo las cartas hasta el ultimo jugador en partida
*/
void repartirCartas();

#endif
