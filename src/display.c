#include <stdio.h>
#include <malloc.h>
#include "display.h"
#include "ascii.h"


void display_principal(CARTA cartas_mesa[], CARTA cartas_jugador[])
{
	char *cartas_mesa_graficas=cartas_5_graficas(cartas_mesa);
	printf("%s", cartas_mesa_graficas);


	/*Actualemte este free da un error de doble free xD*/
	/*free(cartas_mesa_graficas);*/
}
