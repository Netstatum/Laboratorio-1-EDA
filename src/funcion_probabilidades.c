#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "log_factorial.h"
#include "funcion_probabilidades.h"



double combinatoria(unsigned int a, unsigned int b){
	if (b==0 || a==b){
		return 1;
	}
	else{
		return log_factorial(a)-((log_factorial(b)+log_factorial(a-b)));
	}
}

/*Funcion multihipergeometrica en su forma generalizada, falta especificar ahora para los casos particulares de las propias combinaciones de cartas*/
unsigned int multihipgeo(unsigned int a, unsigned int nita_a, unsigned int b, unsigned int nita_b, unsigned int t_mazo, unsigned int t_flop){
	return exp(combinatoria(a,nita_a)+combinatoria(b,nita_b)+combinatoria((t_mazo-(a+b)),(t_flop-(nita_a+nita_b)))-combinatoria(t_mazo,t_flop));
}
