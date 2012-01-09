#include <stdio.h>

#include "modo_apoyo.h"
#include "display.h"
#include "menu.h"



void modo_apoyo()
{
	/*En esta funcion utilizamos fgets ya que es mas segura que otras
	 * funciones como scanf.
	 * fgets escribe la cantidad de caracteres que nosotros le digamos en un
	 * puntero y hace que termine en NULL (por eso pinta es pinta[2])*/
	CARTA cartas[5];
	char pinta[2], valor[3];
	unsigned int i; /*Usamos char ya que es lo mismo que un int pero de menor tamano*/


	limpiar();

	printf("\n\n\n");

	printf("Ingrese las cartas del flop:\n");

	for(i=0;i<3;)
	{
		printf("Carta %i: \n", i+1);

		printf("Pinta: ");
		fgets(pinta, 2, stdin);
		limpiar_buffer();

		printf("Valor: ");
		obtener(valor); /*Obtener valor se encarga de limpiar el buffer*/
		
		if(revisar_entrada(pinta[0], valor))
		{
			printf("Entrada no valida!\n");
			printf("Pinta debe ser: c => Corazones, p => Pica, d => Diamante o t => Trebol\n");
			printf("Valor debe ser: Numero entre 2 y el 9 o A, J, Q, o K\n");
		}else{
			convertir_a_carta(&(cartas[i]), pinta, valor);
			i++;
		}
	}

	for(i=0;i<3;i++)
	{
		printf("Pinta: %i Valor:%i\n", cartas[i]->pinta, cartas[i]->valor);
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
