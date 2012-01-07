#ifndef _H_FUNCION_PROBABILIDADES_
#define _H_FUNCION_PROBABILIDADES_
#include "carta.h"
#include "mesa.h"

/*Devuelve la combinatoria con log. log(combinatoria). Para convertirla a
 * numeros normales utilizamos exp que se encuentra en math
 * Argumentos:
 * 	a: Es n
 * 	b: Es r*/
double combinatoria(unsigned int a, unsigned int b);



int busqueda_carta_sin_pinta(int numero,CARTA mazo[]);


int busqueda_carta_con_pinta(char pinta,CARTA mazo[]);


int busqueda_carta_color_y_numero(int numero,char pinta,CARTA mazo[]);


int tamano_mazo(CARTA mazo[]);


unsigned int multihipgeo(unsigned int a, unsigned int nita_a, unsigned int b, unsigned int nita_b, unsigned int t_mazo, unsigned int t_flop);


int comparador(CARTA carta[],MESA mesajuego[],int turno);


int prob(CARTA mazo[],CARTA mano[],int indicador);


#endif

