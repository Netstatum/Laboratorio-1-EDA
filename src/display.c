#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "display.h"
#include "ascii.h"


void display_principal(CARTA cartas_mesa[], CARTA cartas_jugador[])
{
	char *cartas_mesa_graficas=cartas_5_graficas(cartas_mesa);
	char *cartas_jugador_graficas=cartas_2_graficas(cartas_jugador);
	printf("%s", cartas_mesa_graficas);

	printf("%s", cartas_jugador_graficas);



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
