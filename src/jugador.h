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
 */

/*Estructura que representa a un jugador
 * ATRUBUTOS:
 * 	monto_actual: es la cantidad de dinero de que dispone el jugador.
 * 	Utilizamos un puntero para actualizar la lista total de jugadores cuando
 * 	se modifique el monto en la lista de la ronda.
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


#ifdef DEBUG
/*Ejecuta algunas pruebas para ver que el codigo de jugador funciona. Solo esta
 * disponible si se especifica DEBUG
 * RETORNO: 0 Si todo salio bien*/
int test_jugador();
#endif
