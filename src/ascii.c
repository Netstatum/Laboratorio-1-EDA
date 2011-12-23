#include <stdio.h>
#include "ascii.h"

const char **carta_a_ascii(CARTA carta)
{
	switch(carta.pinta)
	{
		case 3:
			/*Corazones*/
			switch(carta.valor)
			{
				case 2:
					return corazones_2();
					break;
				default:
					return NULL;
					break;
			}
			break;
		case 4:
			/*diamante*/
			break;
		case 5:
			/*trebol*/
			break;
		case 6:
			/*pica*/
			break;

		default:
			return NULL;
			break;
	}
}

const char **corazones_2()
{
	const char **cadena={
		{".------."},
		{"|2_  _ |"},
		{"|( \/ )|"},
		{"| \  / |"},
		{"|  \/ 2|"},
		{"`-----+'"}
	};

	return cadena;
}

char cartas_5_graficas(CARTA cartas[])
{
	char i, l;

	/*Una carta ocupa 48 caracteres . Son 5 cartas asi que es 48*5=240
	 * Ademas debemos poner 6 caracteres de espacio ademas del salto de
	 * linea entre cartas 6*5+240=270 y agregarle un caracter final NULL
	 * quedando como total 271*/

	char cadena[271]={NULL};

	/*Aqui vamos guardand cada linea para luego usarla asi:
	 * [numero de carta][linea][contenido_linea]*/
	char lineas[5][6][8]={NULL};



	for(i=0;i<5;i++)
	{
		for(l=0;l<6;l++)
		{
			sprintf(lineas[i][l], "%s", carta_a_ascii(cartas[i]));
			printf("%s\n", lineas[i][l]);
		}
	}

}
