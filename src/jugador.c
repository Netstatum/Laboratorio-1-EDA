#include "jugador.h"
#include <malloc.h>

Jugador *siguiente_jugador(Jugador *actual)
{
	return actual->siguiente;
}


Jugador *agregar_jugador(Jugador *final, unsigned int monto_actual)
{
	Jugador *nuevo=NULL, *aux=NULL;

	if(final)
	{
		/*Ya tenemos una lista creada, debemos simplemente agregar un
		 * elemento al final de el dado como argumento y enlazarlo
		 * circularmente*/
		
		nuevo=malloc(sizeof(Jugador));
		if(!nuevo)
		{
			/*Fallamos al obtener memoria para Jugador*/
			return NULL;
		}else{
			aux=final->siguiente;
			final->siguiente=nuevo;

			nuevo->siguiente=aux;
			nuevo->monto_actual=monto_actual;
			return nuevo;
		}
	}else{
		/*No existe una lista anteriormente creada por lo que debemos
		 * crear una nueva*/

		nuevo=malloc(sizeof(Jugador));
		if(!nuevo)
		{
			return NULL;
		}else{
			/*Como es circular, enlazamos el primer elemento...al
			 * primer elemento*/
			nuevo->siguiente=nuevo;
			nuevo->monto_actual=monto_actual;
			return nuevo;
		}
	}
}

#ifdef DEBUG
int test_jugador()
{
	/*Vemos si podemos crear un jugador en una lista vacia*/
	Jugador *jugador=agregar_jugador(NULL, 2);

	if(!jugador)
	{
		return -1;
	}

	if(jugador->monto_actual!=2)
	{
		return -1;
	}

	/*Vemos si se agrega correctamente un nuevo jugador*/
	jugador=agregar_jugador(jugador, 3);

	if(!jugador)
	{
		return -1;
	}

	if(jugador->monto_actual!=3)
	{
		return -1;
	}
	
	/*Deberia ser el primer elemento*/
	jugador=siguiente_jugador(jugador);

	if(!jugador)
	{
		return -1;
	}

	if(jugador->monto_actual!=2)
	{
		return -1;
	}
	
	jugador=siguiente_jugador(jugador);
	/*Deberia ser el segundo elemento*/

	if(!jugador)
	{
		return -1;
	}

	if(jugador->monto_actual!=3)
	{
		return -1;
	}

	return 0; /*Todo salio bien :)*/
}
#endif
