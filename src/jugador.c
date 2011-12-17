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

Jugador *nueva_lista_jugador(Jugador *nodo)
{
	/*FIXME: Quedo feo...pensar en otra forma de hacerlo*/

	Jugador *primera=nodo;
	Jugador *nueva=malloc(sizeof(Jugador));
	Jugador *nueva_primero=NULL; /*Primer elemento de la nueva lista*/

	if(!nueva)
	{
		/*fallamos al obtener memoria para nueva*/
		return NULL;
	}

	/*Hacemos el algoritmo una vez para saber cual es el primer elemento asi
	 * simplemente devolvemos nueva_primero*/
	nueva->monto_actual=nodo->monto_actual;
	nueva->id=nodo->id;
	
	nueva->siguiente=malloc(sizeof(Jugador));
	if(!(nueva->siguiente))
	{
		/*TODO: Liberar memoria*/
		return NULL;
	}
	nueva_primero=nueva;
	nueva=nueva->siguiente;
	nodo=nodo->siguiente;

	/*Ejecutamos el while hasta que demos una vuelta completa a la lista
	 * circular*/
	while(nodo!=primera)
	{
		nueva->monto_actual=nodo->monto_actual;
		nueva->id=nodo->id;
		
		nueva->siguiente=malloc(sizeof(Jugador));
		if(!(nueva->siguiente))
		{
			/*TODO: Liberar memoria*/
			return NULL;
		}
		nueva=nueva->siguiente;
		nodo=nodo->siguiente;
	}

	return nueva_primero; /*Devolvemos el primer elemento*/
}


int cambiar_monto(Jugador *jugador, unsigned int monto)
{
	if(!jugador)
	{
		return -1;
	}

	if(!(jugador->monto_actual))
	{
		return -1;
	}
	
	*(jugador->monto_actual)=monto;
	return 0;
}

void set_principio(Jugador *jugador)
{
	_principio=jugador;
}

int jugador_final(Jugador *jugador)
{
	if(jugador->siguiente==_principio)
	{
		return 1;
	}else{
		return 0;
	}
}

#ifdef DEBUG
int test_jugador()
{
	/*Vemos si podemos crear un jugador en una lista vacia*/
	Jugador *jugador=agregar_jugador(NULL, 2);
	Jugador *nueva=NULL;

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

	/*Creamos una nueva lista y vemos que tengamos las mismas cosas que la
	 * original*/

	nueva=nueva_lista_jugador(jugador);
	
	if(!nueva)
	{
		return -1;
	}

	if(nueva->id!=2)
	{
		return -1;
	}

	
	nueva=siguiente_jugador(nueva);
	/*deberia ser el primer elemento*/


	if(!nueva)
	{
		return -1;
	}

	if(nueva->id!=1)
	{
		return -1;
	}

	/*Si modificamos monto_actual deberiamos modificar el mismo en la lista
	 * global*/
	cambiar_monto(nueva, 100);

	/*pero avanzamos una pos. con nueva, asi que lo mismo con jugador*/
	jugador=siguiente_jugador(jugador);

	if(monto_actual(jugador)!=100)
	{
		return -1;
	}

	return 0; /*Todo salio bien :)*/
}
#endif
