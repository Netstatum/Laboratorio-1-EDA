#ifndef _H_CARTA_
#define _H_CARTA_
/** Constantes:
	    _cartas: cantidad de cartas del mazo
*/
#define _cartas 52

/** Estructura tipo carta del mazo
	@var int valor : el valor de la carta, esto ira de 1 a 13, del as al kaizer
	     char pinta: se le asignara el ascii asociado a la pinta
                        3: corazon
                        4: diamante
                        5: trebol
                        6: pica
	     int jugada: sera un marcador para saber si la carta ha sido jugada en la mesa
                     o en la mano de alg�n jugador, para ello tendr� los siguientes valores:
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
#endif
