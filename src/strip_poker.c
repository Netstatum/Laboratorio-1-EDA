#include <stdio.h>
#include <malloc.h>
#include "menu.h"
#include "jugador.h"

int main()
{
    Jugador *jugadoresMesa;

    printf("%s",mensajeBienvenida());
    printf("\n\n\n\n\n\t\tANTES DE COMENZAR A JUGAR AGRANDE EL TAMA%cO DE LA CONSOLA",165);
    printf("\n\n\t\t\t\tAL MAXIMO POSIBLE\n");

    jugadoresMesa = crearJugadores(5);

    getch();


    //menuPrincipal(0);
}
