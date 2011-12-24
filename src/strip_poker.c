#include <stdio.h>
#include "menu.h"

int main()
{
    printf("%s",mensajeBienvenida());
    printf("\n\n\n\n\n\t\tANTES DE COMENZAR A JUGAR AGRANDE EL TAMA%cO DE LA CONSOLA",165);
    printf("\n\n\t\t\t\tAL MAXIMO POSIBLE\n");

    getch();
    menuPrincipal(0);
}
