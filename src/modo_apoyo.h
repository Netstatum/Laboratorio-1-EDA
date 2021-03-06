#ifndef _H_MODO_APOYO_
#define _H_MODO_APOYO_
#include "carta.h"
#include "mesa.h"


/*Funcion que ejecuta el modo apoyo*/
void modo_apoyo();

/*Revisa que la pinta y el valor dados sean una carta valida
 * ARGUMENTOS:
 * 	pinta: un caracter representando a la
 * 	valor: un string de tamano 2 que puede contener un numero de 1 digito o
 * 	2 digitos
 * RETORNO: 0 si es valida la carta, 1 si no es valida la carta*/
int revisar_entrada(char pinta, char *valor);

/*Revisa si el string dado es un numero entre 2 y 10
 * ARGUMENTOS:
 * 	caracter: string de tamano 2, 
 * RETORNO: 1 si es numero valido, 0 si no es valido*/
int es_numero(char *caracter);


/*Convierte los strigs pinta y valor en una estructura carta
 * ARGUMENTOS:
 * 	carta: Un puntero a una variable carta en donde se van a guardar los
 * 	valores
 * 	pinta: string de tamano 1 que representa a la pinta (A, J, Q, K)
 * 	valor: string de tamano 2 de numero entre 2 a 10*/
void convertir_a_carta(CARTA *carta, char *pinta, char *valor);

/*Obtiene una cadena de tamano 1 o 2
 * ARGUMENTOS:
 * 	cadena: puntero en donde se va a guardar lo que leamos, debe ser de
 * 	tamano minimo 2*/
void obtener(char *cadena);

/*Pregunta al usuario por las cartas y las guarda en cartas
 * ARGUMENTOS:
 * 	cartas: puntero en donde guardar las cartas, debe ser de tamano
 * 	cantidad_preguntar
 * 	cantidad_preguntar: el numero de cartas a preguntar*/
void ingresar_cartas(CARTA *cartas, int cantidad_preguntar);


/*Marca la carta segun el tipo_jugada en el mazo
 * ARGUMENTOS:
 * 	carta: La carta a marcar en el mazo
 * 	tipo_jugada: 1 si es en la mesa, 2 si es en la mano*/
void marcar_mazo(CARTA *carta, int tipo_jugada);


/*Asigna las cartas (array de 5) en las cartas de la mesa (tambien array de 5)
 * ARGUMENTOS:
 * 	mesa: una estructura mesa que representa el estado actual de la mesa
 * 	cartas: las cartas a ser asignadas a la mesa*/
void asignar(MESA *mesa, CARTA *cartas);
#endif
