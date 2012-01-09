#ifndef _H_FUNCION_PROBABILIDADES_
#define _H_FUNCION_PROBABILIDADES_
#include "carta.h"
#include "mesa.h"
#include "log_factorial.h"

/*Devuelve la combinatoria con log. log(combinatoria). Para convertirla a
 * numeros normales utilizamos exp que se encuentra en math
 * Argumentos:
 * 	a: Es n
 * 	b: Es r*/
double combinatoria(int a,int b);

int busqueda_carta_sin_pinta(int numero,CARTA mazo[]);


int busqueda_carta_con_pinta(char pinta,CARTA mazo[]);


int busqueda_carta_color_y_numero(int numero,char pinta,CARTA mazo[]);


int tamano_mazo(CARTA mazo[]);



float multihipgeo(int a, int nita_a,int b,int nita_b,int t_mazo,int t_flop);

int comparador(CARTA carta[],int turno);


int prob(CARTA mazo[],CARTA mano[],MESA mesajuego,int indicador);


#endif

