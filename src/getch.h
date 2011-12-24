#ifndef _H_GETCH_
#define _H_GETCH_

/*Como getch no es estandar debemos usar una version que se pueda compilar en
 * otros OSs. Si estamos compilando en windows usamos conio directamente, si no
 * usamos nuestra version de getch*/

#ifdef __linux__
/*Usamos nuestra version de getch*/

int getch();

#else

/*Podemos usar conio.h*/
#include <conio.h>

#endif

#endif
