

/*Lee un maximo de caracteres del teclado y lo guarda en el puntero dado. Si hay
 * mas caracteres de los que se pueden leer estos son descartados
 * ARGUMENTOS:
 * 	cadena: Un array o puntero de tamano maximo+1 (debe haber espacio para
 * 	el NULL final) en donde se va a guardar la lectura del teclado
 * 	tamano: El tamano del array, vamos a leer (tamano-1) caracteres del
 * 	teclado*/
void leer_teclado(char *cadena, int tamano);

/*Verifica si la cadena (DEBE TERMINAR EN NULL) contiene solo numeros.
 * Se puede usar sscanf para convertir a int los numeros en la cadena una
 * vez que se haya comprobado que son numeros
 * ARGUMENTOS:
 * 	cadena: Un string a verificar que contenga solo numeros
 * 	tamano: El tamano del string a verificar
 * RETORNO: 1 si es un numero, 0 si no es un numero lo que contiene
 * */
int revisar_numero(char *cadena, int tamano);

/*Saca todos los caracteres que no han sido leidos del teclado del buffer*/
void limpiar_buffer();
