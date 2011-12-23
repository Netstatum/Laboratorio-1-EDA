#ifndef _H_ascii_
#define _H_ascii_

/*Aqui se incluyen algunas funciones y ctes que devuelven ciertas imagenes en
 * ascii art que vamo sa usar*/


#include "carta.h"

/*Devuelve la linea indicada (entre 0 y 5) del string que representa la carta
 * ARGUMENTOS:
 * 	carta: carta a mostrar
 * 	linea: la linea que se quiere*/
char *carta_a_ascii(CARTA carta, unsigned int linea);

/*Las siguientes funciones devuelven la linea del string que representa a la
 * carta con el caracter dado en la parte del valor
 * ARGUEMNTOS:
 * 	linea: La linea que se quiere
 * 	caracter: el caracter a poner en la carta */
char *corazones(unsigned int linea, char caracter);
char *diamante(unsigned int linea, char caracter);
char *trebol(unsigned int linea, char caracter);
char *pica(unsigned int linea, char caracter);

/*Devuelve el mensaje de bienvenida del programa*/
const char *mensaje_bienvenida();

/*Devuelve un string que representa a las 2 cartas dadas como array
 * ARGUMENTOS:
 * 	cartas: array de cartas de tamano 2*/
char *cartas_2_graficas(CARTA cartas[]);

/*Devuelve un string que representa a las 5 cartas dadas como array
 * ARGUMENTOS:
 * 	cartas: array de cartas de tamano 5*/
char *cartas_5_graficas(CARTA cartas[]);

#endif
