/** Constantes:
	    _cartas: cantidad de cartas del mazo
*/
#define _cartas 52

/** Estructura tipo carta del mazo
	@var int valor : el valor de la carta, esto ira de 1 a 13
	     char pinta: se le asignara el ascii asociado a la pinta
	     int jugada: sera un marcador para saber si la carta ha sido jugada en la mesa
                     o en la mano de algún jugador, para ello tendrá los siguientes valores:
                        0: no ha sido jugada
                        1: jugada en mesa
                        2: jugada en alguna mano
*/
struct carta{
	int valor;
	char pinta;
	int jugada;
};
typedef struct carta CARTA;
