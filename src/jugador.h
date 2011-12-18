#ifndef _H_JUGADOR_
#define _H_JUGADOR_
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
 * monto_actual: Devuelve el monto actual de dinero que tiene el jugador
 *
 * nueva_lista_jugador: Devuelve una nueva lista semi-independiente de jugadores.
 * Debe usarse esta lista y no la global para cada ronda (Dado que en las rondas
 * debemos sacar a algunos jugadores)
 *
 * cambiar_monto: Cambia el monto_actual del jugador.
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
 * 	monto_actual: es la cantidad de dinero de que dispone el jugador.
 * 	Utilizamos un puntero para actualizar la lista total de jugadores cuando
 * 	se modifique el monto en la lista de la ronda. NO MODIFICAR A MANO!
 *
 * 	id: es el identificador del jugador, un numero positivo mayor que 0.
 * 	(partimos del jugador 1). Se incrementa automaticamente al crear nuevos
 * 	nodos.
 *
 * 	siguiente: puntero al siguiente elemento de la lista*/
typedef struct Jugador{
	
	unsigned int *monto_actual, id;
	struct Jugador *siguiente;
} Jugador;

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
 * 	monto_actual: Es el monto que posee el jugador
 *
 * RETORNO: El jugador que se agrega luego de usar la funcion. Devuelve NULL si
 * 	fallamos al obtener memoria para el nuevo nodo*/
Jugador *agregar_jugador(Jugador *final, unsigned int monto_actual);

/*Devuelve el monto actual de dinero que tiene el jugador
 * Debemos utilizar esta funcion ya que monto_actual en la estructura es un
 * puntero y asi simplificamos algo el codigo
 *
 * ARGUMENTOS:
 * 	jugador: el jugador del cual se quiere saber el monto de dinero
 *
 * RETORNO: El monto de dinero que posee. En caso de que el puntero al monto sea
 * NULL devolvemos 0 como valor de dinero, tambien si jugador es NULL (Que
 * devuelva 0 no quiere decir que el puntero sea NULL)*/
unsigned int monto_actual(Jugador *jugador);

/*Devuelve una nueva lista semi-independiente de jugadores. Lo unico que no es
 * independiente es el monto de dinero de cada jugador. Se debe crear una lista
 * de este tipo en cada ronda a partir de la lista general de jugadores.
 * ARGUMENTOS:
 * 	nodo: Uno de los nodos que pertenezca a la lista que queremos copiar
 *
 * RETORNO: Un nodo perteneciente a la nueva lista creada, devuelve NULL si algo
 * salio mal*/
Jugador *nueva_lista_jugador(Jugador *nodo);

/*Cambia el valor de monto en el jugador
 * ARGUMENTOS:
 * 	jugador: el jugador al cual se le va a cambiar el monto
 * 	monto: el nuevo monto_actual del jugador
 *
 * RETORNO: Devuelve -1 si algo fue mal, 0 si todo fue bien*/
int cambiar_monto(Jugador *jugador, unsigned int monto);


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



#ifdef DEBUG
/*Ejecuta algunas pruebas para ver que el codigo de jugador funciona. Solo esta
 * disponible si se especifica DEBUG
 * RETORNO: 0 Si todo salio bien*/
int test_jugador();
#endif
#endif
