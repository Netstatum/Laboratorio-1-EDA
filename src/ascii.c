#include <stdio.h>
#include <malloc.h>
#include "ascii.h"

char *carta_a_ascii(CARTA carta, unsigned int linea)
{
	switch(carta.pinta)
	{
		case 3:
			/*Corazones*/
			if(carta.valor>0 && carta.valor<11)
			{
				/*le sumamos 48 para obtener el valor ascii del
				 * numero*/
				return corazones(linea, carta.valor+48);
			}else{
				/*No son numeros, son letras*/
				switch(carta.valor)
				{
					case 11:
						return corazones(linea, 'J');
					case 12:
						return corazones(linea, 'Q');
					case 13:
						return corazones(linea, 'K');
				}
			}
			break;
		case 4:
			/*diamante*/
			if(carta.valor>0 && carta.valor<11)
			{
				/*le sumamos 48 para obtener el valor ascii del
				 * numero*/
				return diamante(linea, carta.valor+48);
			}else{
				/*No son numeros, son letras*/
				switch(carta.valor)
				{
					case 11:
						return diamante(linea, 'J');
					case 12:
						return diamante(linea, 'Q');
					case 13:
						return diamante(linea, 'K');
				}
			}
			break;
		case 5:
			/*trebol*/
			if(carta.valor>0 && carta.valor<11)
			{
				/*le sumamos 48 para obtener el valor ascii del
				 * numero*/
				return trebol(linea, carta.valor+48);
			}else{
				/*No son numeros, son letras*/
				switch(carta.valor)
				{
					case 11:
						return trebol(linea, 'J');
					case 12:
						return trebol(linea, 'Q');
					case 13:
						return trebol(linea, 'K');
				}
			}
			break;
		case 6:
			/*pica*/
			if(carta.valor>0 && carta.valor<11)
			{
				/*le sumamos 48 para obtener el valor ascii del
				 * numero*/
				return pica(linea, carta.valor+48);
			}else{
				/*No son numeros, son letras*/
				switch(carta.valor)
				{
					case 11:
						return pica(linea, 'J');
					case 12:
						return pica(linea, 'Q');
					case 13:
						return pica(linea, 'K');
				}
			}
			break;

		default:
			return NULL;
			break;
	}
}


const char *mensaje_bienvenida()
{
return "        _..-''--'----_.                                        \n"
"      ,''.-''| .---/ _`-._                                     \n"
"    ,' \\ \\  ;| | ,/ / `-._`-.                                  \n"
"  ,' ,',\\ \\( | |// /,-._  / /                                  \n"
"  ;.`. `,\\ \\`| |/ / |   )/ /                                   \n"
" / /`_`.\\_\\ \\| /_.-.'-''/ /                                    \n"
"/ /_|_:.`. \\ |;'`..')  / /                                     \n"
"`-._`-._`.`.;`.\\  ,'  / /                                      \n"
"    `-._`.`/    ,'-._/ /                                       \n"
"      : `-/     \\`-.._/                                        \n"
"      |  :      ;._ (                                          \n"
"      :  |      \\  ` \\                                         \n"
"       \\         \\   |                                         \n"
"        :        :   ;                                         \n"
"        |           /                                          \n"
"        ;         ,'                                           \n"
"       /         /                                             \n"
"      /         /                                              \n"
"               /                                               \n"
"  _______  __          __            _______         __                 \n"
" |   _   ||  |_ .----.|__|.-----.   |   _   |.-----.|  |--..-----..----.\n"
" |   1___||   _||   _||  ||  _  |   |.  1   ||  _  ||    < |  -__||   _|\n"
" |____   ||____||__|  |__||   __|   |.  ____||_____||__|__||_____||__|  \n"
" |:  1   |                |__|      |:  |                               \n"
" |::.. . |                          |::.|                               \n"
" `-------'                          `---'                               \n";
}

char *corazones(unsigned int linea, char caracter)
{
	/*Estamos practicamente obligados a usar punteros ya que las variables
	 * locales se eliminan al dejar de usar la funcion*/
	char *cadena=malloc(sizeof(char)*9);

	switch(linea)
	{
		case 0:
			sprintf(cadena, ".------.");
			break;
		case 1:
			sprintf(cadena, "|%c_  _ |", caracter);
			break;
		case 2:
			sprintf(cadena, "|( \\/ )|");
			break;
		case 3:
			sprintf(cadena, "| \\  / |");
			break;
		case 4:
			sprintf(cadena, "|  \\/ %c|", caracter);
			break;
		case 5:
			sprintf(cadena, "`-----+'");
			break;
	}

	return cadena;
}

  
char *diamante(unsigned int linea, char caracter)
{
	/*Estamos practicamente obligados a usar punteros ya que las variables
	 * locales se eliminan al dejar de usar la funcion*/
	char *cadena=malloc(sizeof(char)*9);

	switch(linea)
	{
		case 0:
			sprintf(cadena, ".------.");
			break;
		case 1:
			sprintf(cadena, "|%c /\\  |", caracter);
			break;
		case 2:
			sprintf(cadena, "| /  \\ |");
			break;
		case 3:
			sprintf(cadena, "| \\  / |");
			break;
		case 4:
			sprintf(cadena, "|  \\/ %c|", caracter);
			break;
		case 5:
			sprintf(cadena, "`-----+'");
			break;
	}

	return cadena;
}

char *trebol(unsigned int linea, char caracter)
{
	/*Estamos practicamente obligados a usar punteros ya que las variables
	 * locales se eliminan al dejar de usar la funcion*/
	char *cadena=malloc(sizeof(char)*9);

	switch(linea)
	{
		case 0:
			sprintf(cadena, ".------.");
			break;
		case 1:
			sprintf(cadena, "|%c _   |", caracter);
			break;
		case 2:
			sprintf(cadena, "| ( )  |");
			break;
		case 3:
			sprintf(cadena, "|(_x_) |");
			break;
		case 4:
			sprintf(cadena, "|  Y  %c|", caracter);
			break;
		case 5:
			sprintf(cadena, "`-----+'");
			break;
	}

	return cadena;

}




char *pica(unsigned int linea, char caracter)
{
	/*Estamos practicamente obligados a usar punteros ya que las variables
	 * locales se eliminan al dejar de usar la funcion*/
	char *cadena=malloc(sizeof(char)*9);

	switch(linea)
	{
		case 0:
			sprintf(cadena, ".------.");
			break;
		case 1:
			sprintf(cadena, "|%c .   |", caracter);
			break;
		case 2:
			sprintf(cadena, "| / \\  |");
			break;
		case 3:
			sprintf(cadena, "|(_,_) |");
			break;
		case 4:
			sprintf(cadena, "|  I  %c|", caracter);
			break;
		case 5:
			sprintf(cadena, "`-----+'");
			break;
	}

	return cadena;


}

char *cartas_5_graficas(CARTA cartas[])
{
	int l;
	char *cadena=malloc(sizeof(char)*450);

	/*5 cartas de 8 caracteres +4 espacios +1 salto de linea +NULL*/
	char lineas[6][5*8+6+17]={'\0'};
	char *carta1,*carta2,*carta3,*carta4,*carta5;
	
	for(l=0;l<6;l++)
	{
		carta1=carta_a_ascii(cartas[0], l);
		carta2=carta_a_ascii(cartas[1], l);
		carta3=carta_a_ascii(cartas[2], l);
		carta4=carta_a_ascii(cartas[3], l);
		carta5=carta_a_ascii(cartas[4], l);

		/*vamos guardando linea por linea para luego contatenarla*/
		/*debemos dejar un espacio al principio de 17 caracteres por (80-(5*8+6))/2*/
		sprintf(lineas[l], "                 %s %s %s %s %s\n", carta1,carta2,carta3,carta4,carta5);

		free(carta1);
		free(carta2);
		free(carta3);
		free(carta4);
		free(carta5);
	}

	/*concatenamos todo en un mismo string*/
	sprintf(cadena, "%s%s%s%s%s%s", lineas[0], lineas[1], lineas[2], lineas[3], lineas[4], lineas[5]);

	return cadena;
}

char *cartas_2_graficas(CARTA cartas[])
{
	int l;
	char *cadena=malloc(sizeof(char)*359);

	/*2 cartas de 8 caracteres +1 espacios +1 salto de linea +NULL*/
	char lineas[6][2*8+37]={'\0'};
	char *carta1,*carta2;
	
	for(l=0;l<6;l++)
	{
		carta1=carta_a_ascii(cartas[0], l);
		carta2=carta_a_ascii(cartas[1], l);

		/*vamos guardando linea por linea para luego contatenarla*/
		sprintf(lineas[l], "                                %s %s\n", carta1,carta2);

		free(carta1);
		free(carta2);
	}

	/*concatenamos todo en un mismo string*/
	sprintf(cadena, "%s%s%s%s%s%s", lineas[0], lineas[1], lineas[2], lineas[3], lineas[4], lineas[5]);

	return cadena;
}
