#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "display.h"
#include "ascii.h"


void display_principal(CARTA cartas_mesa[], unsigned int cantidad_cartas_mesa, CARTA cartas_jugador[])
{
	char *cartas_mesa_graficas=NULL, *cartas_jugador_graficas=NULL;

	/*dependiendo de la cantidad de cartas que nos den es la funcion que
	 * llamamos*/
	switch(cantidad_cartas_mesa)
	{
		case 5:
			cartas_mesa_graficas=cartas_5_graficas(cartas_mesa);
			break;
		case 3:
			cartas_mesa_graficas=cartas_3_graficas(cartas_mesa);
			break;
		case 4:
			cartas_mesa_graficas=cartas_4_graficas(cartas_mesa);
			break;

		default:
			/*No hacemos nada*/
			break;
	}

	printf("%s", cartas_mesa_graficas);

	if(cartas_jugador)
	{
		cartas_jugador_graficas=cartas_2_graficas(cartas_jugador);
		printf("%s", cartas_jugador_graficas);
	}



	free(cartas_mesa_graficas);
	free(cartas_jugador_graficas);
}


void limpiar()
{
#ifdef __linux__
	system("clear");
#else
	system("cls");
#endif
}
