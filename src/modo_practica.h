#ifndef MODO_PRACTICA_H_INCLUDED
#define MODO_PRACTICA_H_INCLUDED
#include "jugador.h"

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

/** Hacen el calculo de la apuesta maxima y minima obligatorias para los dos primeros jugadores
    en la primera ronda de cada partida, este valor es fijo para el resto del juego
 */
int aBig(int mInicial);
int aLow(int mInicial);

/** Analizara si la apuesta puede ser llevada acabo normalmente */
int apostandoBigOrLow(int apuesta, int dinero);

#endif // MODO_PRACTICA_H_INCLUDED
