#include "ascii.h"
#include "carta.h"

int main()
{
	CARTA cartas[5];
	int i;

	for(i=0;i<5;i++)
	{
		cartas[i].pinta=3;
		cartas[i].valor=2;
	}

	cartas_5_graficas(cartas);
	
	return 0;
}
