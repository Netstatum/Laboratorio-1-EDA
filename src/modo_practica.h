#ifndef MODO_PRACTICA_H_INCLUDED
#define MODO_PRACTICA_H_INCLUDED
#include "jugador.h"

/** Funci�n modo_practica, esta funci�n es la encargada de inicializar la partida
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

/** Hace el calculo de la proporci�n que le corresponde al jugador del poso total */
int calculoPP(Jugador *jugador);

#endif // MODO_PRACTICA_H_INCLUDED
