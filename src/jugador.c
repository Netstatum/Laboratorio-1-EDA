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
			/*Los punteros no son NULL, podemos devolver el monto*/
			return *(jugador->monto_actual);
		}
	}
}

Jugador *nueva_lista_jugador(Jugador *nodo)
{
	/*FIXME: Quedo feo...pensar en otra forma de hacerlo*/

	Jugador *primera=nodo;
	Jugador *nueva=NULL;
	Jugador *nueva_primero=NULL; /*Primer elemento de la nueva lista*/

	nueva=malloc(sizeof(Jugador));

	nueva->id=nodo->id;
	nueva->monto_actual=nodo->monto_actual;

	nueva->siguiente=malloc(sizeof(Jugador));

	nueva_primero=nueva;

	nueva=nueva->siguiente;
	nodo=nodo->siguiente;

	do{
		/*Copiamos los elementos de nodo en la nueva lista*/
		nueva=malloc(sizeof(Jugador));

		nueva->id=nodo->id;
		nueva->monto_actual=nodo->monto_actual;

		nueva->siguiente=malloc(sizeof(Jugador));

		nueva=nueva->siguiente;
		nodo=nodo->siguiente;

	}while(nodo!=primera);

	nueva->siguiente=nueva_primero;

	return nodo; 
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
	
	/*Los punteros no son NULL, podemos modificar el monto*/
	*(jugador->monto_actual)=monto;
	return 0;
}

void set_principio(Jugador *jugador)
{
	_principio=jugador;
}

int jugador_final(Jugador *jugador)
{
	if(!jugador)
	{
		return 1;
	}

	if(jugador->siguiente==_principio)
	{
		return 1;
	}else{
		return 0;
	}
}

void borrar_nodo(Jugador *nodo)
{
	Jugador *anterior=nodo->siguiente;
	while(anterior->siguiente!=nodo)
	{
		anterior=anterior->siguiente;
	}

	anterior=nodo->siguiente;
	free(nodo);
}

int borrar_jugador_id(Jugador *nodo, unsigned int id)
{
	Jugador *primero=nodo;
	while(nodo->siguiente!=primero)
	{
		if(nodo->id==id)
		{
			borrar_nodo(nodo);
			return 0;
		}
		nodo=nodo->siguiente;
	}
	return 1;
}

#ifdef DEBUG
#include <stdio.h>
int test_jugador()
{
	/*Vemos si podemos crear un jugador en una lista vacia*/
	Jugador *jugador=agregar_jugador(NULL, 2);
	Jugador *nueva=NULL;

	if(!jugador)
	{
		printf("No se puede crear la nueva lista");
		return -1;
	}

	if(monto_actual(jugador)!=2)
	{
		printf("No se puede obtener el monto del jugador");
		return -1;
	}

	if(jugador->id!=1)
	{
		printf("El id del jugador 1 no se creo bien");
		return -1;
	}

	/*Vemos si se agrega correctamente un nuevo jugador*/
	jugador=agregar_jugador(jugador, 3);

	if(!jugador)
	{
		printf("No se pudo agregar un jugador");
		return -1;
	}

	if(monto_actual(jugador)!=3)
	{
		printf("No se agrego bien el monto del jugador");
		return -1;
	}


	if(jugador->id!=2)
	{
		printf("El id del jugador 2 no se creo bien");
		return -1;
	}
	
	/*Deberia ser el primer elemento*/
	jugador=siguiente_jugador(jugador);

	if(!jugador)
	{
		printf("No se pudo avanzar en la lista circular");
		return -1;
	}


	if(jugador->id!=1)
	{
		printf("Se avanzo mal en la lista");
		return -1;
	}
	
	jugador=siguiente_jugador(jugador);
	/*Deberia ser el segundo elemento*/

	if(!jugador)
	{
		printf("No se pudo avanzar al segundo elemento en la lista circular");
		return -1;
	}

	if(jugador->id!=2)
	{
		printf("No es el segundo elemento en la lista");
		return -1;
	}

	/*Creamos una nueva lista y vemos que tengamos las mismas cosas que la
	 * original*/

	nueva=nueva_lista_jugador(jugador);
	
	if(!nueva)
	{
		printf("No se pudo copiar la lista");
		return -1;
	}

	if(nueva->id!=2)
	{
		printf("No es el elemento 2 en el que nos encontramos");
		return -1;
	}

	if(nueva->siguiente->siguiente!=nueva)
	{
		printf("No funciona la lista circular");
		return -1;
	}

	
	nueva=siguiente_jugador(nueva);
	/*deberia ser el primer elemento*/


	if(!nueva)
	{
		printf("No nos pudimos mover en la nueva lista");
		return -1;
	}

	if(nueva->id!=1)
	{
		printf("Nos pudimos mover pero no es el primer elemento");
		return -1;
	}

	/*Si nos movemos deberia ser el segundo elemento*/
	nueva=siguiente_jugador(nueva);

	if(nueva->id!=2)
	{
		printf("No estamos en el segudo elemento en la nueva lista");
		return -1;
	}

	/*Si modificamos monto_actual deberiamos modificar el mismo en la lista
	 * global*/
	cambiar_monto(nueva, 100);


	if(monto_actual(jugador)!=100)
	{
		printf("No se cambio el monto actual en la lista vieja");
		return -1;
	}

	/*Borramos el nodo actual*/
	jugador=nueva->siguiente;
	borrar_nodo(nueva);

	/*Ahora jugador deberia apuntar a si mismo*/
	if(jugador==jugador->siguiente)
	{
		printf("No se pudo borrar el elemento correctamente");
		return -1;
	}

	return 0; /*Todo salio bien :)*/
}
#endif
