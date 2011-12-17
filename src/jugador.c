#include "jugador.h"
#include <malloc.h>

Jugador *siguiente_jugador(Jugador *actual)
{
	return actual->siguiente;
}


Jugador *agregar_jugador(Jugador *final, unsigned int monto_actual)
{
	Jugador *nuevo=NULL, *aux=NULL;
	unsigned int *monto=NULL;

	if(final)
	{
		/*Ya tenemos una lista creada, debemos simplemente agregar un
		 * elemento al final de el dado como argumento y enlazarlo
		 * circularmente*/
		
		nuevo=malloc(sizeof(Jugador));
		monto=malloc(sizeof(unsigned int));

		if(!nuevo || !monto)
		{
			/*Fallamos al obtener memoria para Jugador*/
			return NULL;
		}else{
			aux=final->siguiente;
			final->siguiente=nuevo;

			nuevo->siguiente=aux;
			*monto=monto_actual;
			nuevo->monto_actual=monto;
			nuevo->id=final->id+1;
			return nuevo;
		}
	}else{
		/*No existe una lista anteriormente creada por lo que debemos
		 * crear una nueva*/

		nuevo=malloc(sizeof(Jugador));
		monto=malloc(sizeof(unsigned int));

		if(!nuevo || !monto)
		{
			return NULL;
		}else{
			/*Como es circular, enlazamos el primer elemento...al
			 * primer elemento*/
			nuevo->siguiente=nuevo;
			*monto=monto_actual;
			nuevo->monto_actual=monto;
			nuevo->id=1;
			return nuevo;
		}
	}
}

unsigned int monto_actual(Jugador *jugador)
{
	if(!jugador)
	{
		return 0;
	}else{
		if(!(jugador->monto_actual))
		{
			return 0;
		}else{
			return *(jugador->monto_actual);
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

	if(monto_actual(jugador)!=2)
	{
		return -1;
	}

	if(jugador->id!=1)
	{
		return -1;
	}

	/*Vemos si se agrega correctamente un nuevo jugador*/
	jugador=agregar_jugador(jugador, 3);

	if(!jugador)
	{
		return -1;
	}

	if(monto_actual(jugador)!=3)
	{
		return -1;
	}


	if(jugador->id!=2)
	{
		return -1;
	}
	
	/*Deberia ser el primer elemento*/
	jugador=siguiente_jugador(jugador);

	if(!jugador)
	{
		return -1;
	}


	if(jugador->id!=1)
	{
		return -1;
	}
	
	jugador=siguiente_jugador(jugador);
	/*Deberia ser el segundo elemento*/

	if(!jugador)
	{
		return -1;
	}

	if(jugador->id!=2)
	{
		return -1;
	}

	return 0; /*Todo salio bien :)*/
}
#endif
