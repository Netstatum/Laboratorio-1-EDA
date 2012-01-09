#ifndef APUESTAS_H_INCLUDED
#define APUESTA_H_INCLUDED

#include "mesa.h"
#include "jugador.h"
#include "getch.h"

/** Apuestas obligatorias al comienzo de cada ronda
	Se aplican al primer y segundo jugandor correspondientemente
 */
double _low;
double _big;

/** Si se debe realizar la apuesta obligatoria o no */
int _aOB;

/** Función apuestaG
	Es la funcion general de apuestas, se asumen las siguientes cosas:
		Sup0) La cantidad ingresada es valida (es decir es un double)
		Sup1) La cantidad apostada es igual o mayor a la apuesta maxima (apuesta>=mesaJuego.apuesta_maxima)
		Sup2) El jugador tiene el dinero suficiente para apostar lo que indica (apuesta<=jugando->dinero)
 */
void apuestaG(Jugador *jugando, double apuesta);

/** Hacen el calculo de la apuesta maxima y minima obligatorias para los dos primeros jugadores
    en la primera ronda de cada partida, este valor es fijo para el resto del juego
	@param int mInicial: monto total inicial que tiene cada jugador al iniciar la partida
 */
void aLow(double mInicial);
void aBig(double mInicial);

/** Realizara las diferentes apuestas
	@param Jugador *jugando : jugador apostando
	       double apuesta: cantidad apostada

	Para realizar el low usar apostando(jugador,_low);
	Para realizar el big usar apostando(jugador,_big);
	Para igualar la apostando(jugador,mesaJuego.apuesta_maxima);
	Para aumentar la apostando(jugador,mesaJuego.puesta_maxima+aumento);;
	Para ir All In apostando(jugador,jugador->dinero);

	Si no tiene el dinero suficiente para realizar una de estas acciones, la apuesta realizada
	sera equivalente a apostando(jugador,jugador->dinero);
*/
void apostando(Jugador *jugando, double apuesta);

#endif
