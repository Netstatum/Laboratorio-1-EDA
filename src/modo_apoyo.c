#include <stdio.h>
#include <string.h>

#include "modo_apoyo.h"
#include "display.h"
#include "menu.h"



void modo_apoyo()
{
	CARTA cartas[5];
	CARTA carta_aux;
	CARTA jugador[2];


	limpiar();

	printf("\n\n\n");

	printf("Ingrese las cartas del flop:\n");
	ingresar_cartas(cartas, 3);


	printf("\n");
	printf("Ingrese sus cartas:\n");
	ingresar_cartas(jugador, 2);

	display_modo_apoyo(cartas, 3, jugador);

	/*TODO: Probabilidades*/

	printf("\n");
	printf("Ingrese las cartas del turn:\n");
	ingresar_cartas(&carta_aux, 1);
	cartas[3]=carta_aux;

	display_modo_apoyo(cartas, 4, jugador);

	/*TODO: Probabilidades*/

	printf("\n");
	printf("Ingrese las cartas del river:\n");
	ingresar_cartas(&carta_aux, 1);
	cartas[4]=carta_aux;

	display_modo_apoyo(cartas, 5, jugador);

	/*TODO: Probabilidades*/
}

void ingresar_cartas(CARTA *cartas, int cantidad_preguntar)
{
	/*En esta funcion utilizamos fgets ya que es mas segura que otras
	 * funciones como scanf.
	 * fgets escribe la cantidad de caracteres que nosotros le digamos en un
	 * puntero y hace que termine en NULL (por eso pinta es pinta[2])*/
	unsigned int i; 
	char pinta[2], valor[3];
	
	for(i=0;i<cantidad_preguntar;)
	{
		
		memset(valor, '\0', sizeof(char)*3); /*para que los strings terminen en NULL*/
		printf("Carta %i: \n", i+1);

		printf("Pinta: ");
		fgets(pinta, 2, stdin);
		limpiar_buffer();

		printf("Valor: ");
		obtener(valor);
		
		if(revisar_entrada(pinta[0], valor))
		{
			printf("Entrada no valida!\n");
			printf("Pinta debe ser: c => Corazones, p => Pica, d => Diamante o t => Trebol\n");
			printf("Valor debe ser: Numero entre 2 y el 9 o A, J, Q, o K\n");
		}else{
			convertir_a_carta(&(cartas[i]), pinta, valor);
			i++;
		}
		printf("\n");
	}
}

int revisar_entrada(char pinta, char *valor)
{
	
	/*Vemos si la pinta es valida*/
	if(pinta!='c' && pinta!='d' && pinta!='t' && pinta!='p' && pinta!='C' && pinta!='D' && pinta!='T' && pinta!='P')
	{
		return 1;
	}
	
	if(!es_numero(valor))
	{
		if(valor[0]!='a' && valor[0]!='j' && valor[0]!='q' && valor[0]!='k' && valor[0]!='A' && valor[0]!='J' && valor[0]!='Q' && valor[0]!='K')
		{
			/*valor tambien puede tomar valores de letras*/
			return 1;
		}
	}



	return 0;

}

int es_numero(char *caracter)
{
	if(caracter[0]<'2' || caracter[0]>'9')
	{
		/*Podria ser el 10*/
		if(caracter[0]=='1' && caracter[1]=='0')
		{
			return 1;
		}
		return 0;
	}

	return 1;
}

void limpiar_buffer()
{
	while(getchar()!='\n');
}


void convertir_a_carta(CARTA *carta, char *pinta, char *valor)
{
	if(es_numero(valor))
	{
		printf("%s\n", valor);
		sscanf(valor, "%i", &(carta->valor));
	}else{
		/*Es una letra y debemos hacer la conversion nosotros*/
		switch(valor[0])
		{
			case 'A':
				carta->valor=1;
				break;
			case 'J':
				carta->valor=11;
				break;
			case 'Q':
				carta->valor=12;
				break;
			case 'K':
				carta->valor=13;
				break;
			case 'a':
				carta->valor=1;
				break;
			case 'j':
				carta->valor=11;
				break;
			case 'q':
				carta->valor=12;
				break;
			case 'k':
				carta->valor=13;
				break;
			default:
				break;
		}
	}

	switch(pinta[0])
	{
		case 'c':
			carta->pinta=3;
			break;
		case 'd':
			carta->pinta=4;
			break;
		case 't':
			carta->pinta=5;
			break;
		case 'p':
			carta->pinta=6;
			break;
		case 'C':
			carta->pinta=3;
			break;
		case 'D':
			carta->pinta=4;
			break;
		case 'T':
			carta->pinta=5;
			break;
		case 'P':
			carta->pinta=6;
			break;
		default:
			break;
	}
}

void obtener(char *cadena)
{
	char entrada;
	int i=0;
	while((entrada=getchar())!='\n')
	{
		if(i>=2)
		{
			limpiar_buffer();
			break;
		}
		cadena[i]=entrada;
		i++;
	}
}
