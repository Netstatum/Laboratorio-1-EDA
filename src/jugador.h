#ifndef _H_JUGADOR_
#define _H_JUGADOR_

#include "carta.h"

/*jugador.h
 * Para ejemplos de uso vease la funcion test_jugador
 *
 * Las siguientes funciones se encuentran en este archivo.
 *
 * siguiente_jugador: Devuelve el jugador al cual le corresponde el siguiente
 * turno.
 *
 * agregar_jugador: Agrega un nodo al final de final dejandola doblemente
 * enlazada (el ultimo elemento apunta al primer elemento)
 *
 * jugador_final: Indica si el jugador esta al final de la lista. Hay que usar
 * set_principio antes de usar.
 *
 * set_principio: Pone como principio el elemento actual de la lista
 */

/*Estructura que representa a un jugador
 * TODO: Agregar los atributos faltantes
 *
 * Las modificaciones efectuadas en esta estructura deben ser replicadas en las
 * siguientes funciones:
 * 	nueva_lista_jugador, agregar_jugador y test_jugador
 *
 * ATRUBUTOS:
 * 	id: es el identificador del jugador, un numero positivo mayor que 0.
 * 	(partimos del jugador 1). Se incrementa automaticamente al crear nuevos
 * 	nodos.
 *
 * 	jugando: 0 si no esta jugando en la ronda actual, 1 si esta jugando en
 * 	la ronda actual
 *
 * 	siguiente: puntero al siguiente elemento de la lista*/
typedef struct Jugador{

	unsigned int dinero, id, apuesta_actual,jugando;

	CARTA cartas[4];

	struct Jugador *siguiente;
} Jugador;

/** Lista circular de jugadores */
Jugador *jugadoresMesa;

/*Variables globales. No deberian ser usadas por funciones fuera de aqui*/

Jugador *_principio;

/*Devuelve el jugador al cual le corresponde el siguiente turno
 * ARGUMENTOS:
 * 	actual: Un puntero del jugador al cual le corresponde el turno de este
 * 	momento
 *
 * RETORNO: El jugador que le corresponde el siguiente turno*/
Jugador *siguiente_jugador(Jugador *actual);

/*Agrega un nodo al final de final dejandola doblemente enlazada (el ultimo
 * elemento apunta al primer elemento)
 * ARGUMENTOS:
 * 	final: es el ultimo jugador agregado a la lista. Si final es NULL
 * 	entonces se crea una nueva lista desde cero.
 * 	dinero: Es el dinero que posee el jugador
 *
 * RETORNO: El jugador que se agrega luego de usar la funcion. Devuelve NULL si
 * 	fallamos al obtener memoria para el nuevo nodo*/
Jugador *agregar_jugador(Jugador *final, unsigned int dinero);


/*Indica si estamos al final del recorrido de la lista. Para usarla hay llamar a
 * set_principio antes
 * ARGUMENTOS:
 * 	jugador: Un nodo de la lista a ser comprobado si es el final
 * RETORNO: 0 si no es el final, 1 si es el final. En caso de que jugador sea
 * NULL devuelve 1 para que no se formen bucles infinitos.
 * */
int jugador_final(Jugador *jugador);

/*Marca un punto arbitrario de la lista que va a ser usado como principio
 * ARGUMENTOS:
 * 	jugador: un nodo de la lista a usar como principio de esta*/
void set_principio(Jugador *jugador);



/*Borra el nodo dado de la lista. NO DEBERIA UTILIZASE EN LA LISTA GLOBAL DE
 * JUGADORES
 *
 * ARGUMENTOS:
 * 	nodo: borra el nodo de la lista */
void borrar_nodo(Jugador *nodo);


/*Borra el nodo en el cual se encuentra el id dado. No deberia utilizarse en la
 * lista global de jugadores
 * ARGUMENTOS:
 * 	id: el id del jugador a borrar
 * 	nodo: un nodo perteneciente a la lista
 * RETORNO: Devuelve 0 si se encontro el nodo, 1 si no se encontro*/
int borrar_jugador_id(Jugador *nodo, unsigned int id);

/** Función crearJugadores, crea una lista con tantos jugadores como se especifica con el monto dado
    @param int cantidad: cantidad de jugadores
                         si esta cantidad es 1 o menor se toma por defecto el valor de 2
                         si esta cantidad es 24 o mayor se toma por defecto el valor de 23
     @param double cantidad: monto total inicial
                         si esta cantidad es menor de 100 millones se toma por defecto el valor 100
                         si esta cantidad es mayor que 30000 millones se toma por defecto el valor 30000
*/
Jugador *crearJugadores(unsigned int cantidadJ, unsigned int cantidadM);


/*Libera la memoria utilizada por la lista jugador
 * ARGUMENTOS:
 * 	nodo: Un nodo que pertenezca a la lista jugador*/
void free_jugador(Jugador *nodo);

#ifdef DEBUG
/*Ejecuta algunas pruebas para ver que el codigo de jugador funciona. Solo esta
 * disponible si se especifica DEBUG
 * RETORNO: 0 Si todo salio bien*/
int test_jugador();
#endif
#endif
