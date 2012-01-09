#include <stdio.h>
#include <string.h>
#include "entrada.h"



int revisar_numero(char *cadena, int tamano)
{
	if(tamano<=0)
	{
		return 1;
	}else{
		/*Nos aprovechamos de la tabla ascii*/
		if((cadena[tamano-1]<'0' || cadena[tamano-1]>'9') && cadena[tamano-1]!='\0')
		{
			/*No contiene un numero*/
			return 0;
		}else{
			return 1*revisar_numero(cadena, tamano-1);
		}
	}
}


void leer_teclado(char *cadena, int tamano)
{
	char entrada;
	int i=0;
	memset(cadena, '\0', sizeof(char)*tamano);
	while((entrada=getchar())!='\n')
	{
		if(i>=(tamano-1))
		{
			limpiar_buffer();
			break;
		}
		cadena[i]=entrada;
		i++;
	}
}

void limpiar_buffer()
{
	while(getchar()!='\n');
}
