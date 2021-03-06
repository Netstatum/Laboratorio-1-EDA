#include "display.h"

void display_principal(Jugador *jugando, CARTA cartas_mesa[], unsigned int cantidad_cartas_mesa, CARTA cartas_jugador[])
{
	char *cartas_mesa_graficas=NULL, *cartas_jugador_graficas=NULL;
	double pozoApuestas = mesaJuego.pozoApuestas;
	double apuestaMax = mesaJuego.apuesta_maxima;

    limpiar();
    printf("%s",titulo());
    printf("\n\n");
    printf("================================================================================\n");

    printf("Pozo Total de la Mesa: %g",pozoApuestas);

    printf("\nCartas en la Mesa: \n\n");

	if(cartas_mesa && (cantidad_cartas_mesa>=3 && cantidad_cartas_mesa<=5))
	{
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


	}else{
		/*dejamos la mesa sin cartas, pero nos saltamos el mismo espacio
		 * que ocuparian las cartas*/
		printf("\n\n\n\n\n\n");
	}

	printf("\n\n================================================================================\n\n");

	if(cartas_jugador)
	{
		cartas_jugador_graficas=cartas_2_graficas(cartas_jugador);
		printf("%s", cartas_jugador_graficas);
	}

	free(cartas_mesa_graficas);
	free(cartas_jugador_graficas);

	printf("\nDinero disponible: %g millones",jugando->dinero);
	printf("\nTu ultima apuesta realizada: %g",jugando->apuesta_actual);
    printf("\nApuesta maxima realizada: %g",apuestaMax);

    printf("\n\n================================================================================");

    printf("\nProbabilidades de juego:");

    prob(mazo,jugando->cartas,mesaJuego,comparador(jugando->cartas,cantidad_cartas_mesa-2));

    printf("\n\n================================================================================");
}

void display_modo_apoyo(CARTA cartas_mesa[], unsigned int cantidad_cartas_mesa, CARTA cartas_jugador[])
{
	char *cartas_mesa_graficas=NULL, *cartas_jugador_graficas=NULL;

	if(cartas_mesa && (cantidad_cartas_mesa>=3 && cantidad_cartas_mesa<=5))
	{
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


	}else{
		/*dejamos la mesa sin cartas, pero nos saltamos el mismo espacio
		 * que ocuparian las cartas*/
		printf("\n\n\n\n\n\n");
	}

	printf("\n\n================================================================================\n\n");

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
