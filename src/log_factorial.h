#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*Esta funcion devuelve el logaritmo del factorial calculado. Lo podemos usar
 * para calcular logaritmos grandes sin miedo al overflow tansformando con exp
 * de logaritmo a factorial normal LUEGO DE REALIZAR LOS CALCULOS con los
 * logaritmos.
 * Al usar log. las divisiones se transforman en restas y las multiplicaciones
 * en sumas asi:
 * n!/m! => exp(log_factorial(n)-log_factorial(m))
 *
 * La funcion exp se puede encontrar en math.h
 *
 * FUNCIONES:
 * log_factorial: Devuelve ln(n!). Luego de realizar los */


/*Devuelve log(n!)
 * ARGUMENTOS:
 * 	n: El factorial que queremos encontrar*/
float log_factorial(int n);
