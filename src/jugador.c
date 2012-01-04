#include "jugador.h"
#include <malloc.h>
#include <stdio.h>

Jugador *siguiente_jugador(Jugador *actual)
{
	return actual->siguiente;
}


Jugador *agregar_jugador(Jugador *final, unsigned int dinero)
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
			nuevo->dinero=dinero;
			nuevo->id=final->id+1;
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
			nuevo->dinero=dinero;
			nuevo->id=1;
			return nuevo;
		}
	}
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

Jugador *crearJugadores(int cantidad){
    Jugador *lista = NULL;

    if(cantidad<=1)
        cantidad=2;

    while(cantidad>0){
        lista = agregar_jugador(lista,_dineroI);
        lista = lista->siguiente;
        cantidad--;
    }

    return lista;

}

void free_jugador(Jugador *nodo)
{
	/*No usamos la funcion jugador_final ya que podria estar siendo usada
	 * por el usuario de la lista*/
	Jugador *primero=nodo, *aux=NULL;

	do{
		aux=nodo;
		nodo=nodo->siguiente;
		free(aux);
	}while(nodo!=primero);
}

#ifdef DEBUG
#include <stdio.h>
int test_jugador()
{
	/*Vemos si podemos crear un jugador en una lista vacia*/
	Jugador *jugador=agregar_jugador(NULL, 2);

	if(!jugador)
	{
		printf("No se puede crear la nueva lista");
		return -1;
	}

	if(jugador->apuesta_actual!=2)
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

	if(jugador->apuesta_actual!=3)
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


	return 0; /*Todo salio bien :)*/
}
#endif
