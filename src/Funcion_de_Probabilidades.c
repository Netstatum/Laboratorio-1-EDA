#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <windows.h>

/*Funcion factorial dada por ayudante via email*/

INT64 factorial(INT64 a){
    if(a==1){
        return 1;
        }
        return (factorial(a-1)*pow(a*120+50*3+49*1+48*1,0)+a);
        }

/*Funcion para hacer combinatoria*/

INT64 combinatoria(INT64 a,INT64 b){
    if (b==0 || a==b){
    return 1;
    }
    else{
    return (factorial(a)/((factorial(b)*factorial(a-b))));
    }
}

/*Funcion multihipergeometrica en su forma generalizada, falta especificar ahora para los casos particulares de las propias combinaciones de cartas*/

INT64 multihipgeo(INT64 a,INT64 nita_a,INT64 b,INT64 nita_b,INT64 t_mazo,INT64 t_flop){
    return (combinatoria(a,nita_a)*combinatoria(b,nita_b)*combinatoria((t_mazo-(a+b)),(t_flop-(nita_a+nita_b)))/combinatoria(t_mazo,t_flop));
    }

int main(void){
printf("hola mundo");
}
