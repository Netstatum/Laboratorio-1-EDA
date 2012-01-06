#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "log_factorial.h"
#include "funcion_probabilidades.h"
#include "carta.h"
#include "jugador.h"

double combinatoria(unsigned int a, unsigned int b){
	if (b==0 || a==b){
		return 1;
	}
	else{
		return log_factorial(a)-((log_factorial(b)+log_factorial(a-b)));
	}
}

/*Permite saber cuantas cartas de un tipo quedan*/

int busqueda_carta_sin_pinta(int numero,CARTA mazo[51]){
    int i, cantidad=0;
    for (i=0;i<52;i++){
        if (mazo[i].valor==numero && mazo[i].jugada==0){
        cantidad=cantidad+1;}
    }
    return cantidad;
}

/*Permite saber tamaño mazo*/

int tamano_mazo(CARTA mazo[51]){
    int i, tamano=0;
    for (i=0;i<52;i++){
        if (mazo[i].jugada==0){
        tamano=tamano+1;
        }
    }
    return tamano;
}

/*Funcion multihipergeometrica en su forma generalizada, falta especificar ahora para los casos particulares de las propias combinaciones de cartas*/
unsigned int multihipgeo(unsigned int a, unsigned int nita_a, unsigned int b, unsigned int nita_b, unsigned int t_mazo, unsigned int t_flop){
	return (combinatoria(a,nita_a)*combinatoria(b,nita_b)*combinatoria((t_mazo-(a+b)),(t_flop-(nita_a+nita_b)))/combinatoria(t_mazo,t_flop));
}

/*Ahora hay que ver que combiene hacer, como en un principio se tienen 2 cartas, hay que ver si estan son iguales, si son diferentes, si son
de la misma pinta, o si son consecutivas, esto sirve para el principio en que NO HAY CARTAS EN MESA TODAVIA*/

int comparador(CARTA carta[4],int turno){
    int indicador=0;

    if (turno==0){
        /*esto sirve para el principio en que NO HAY CARTAS EN MESA TODAVIA*/

    if (carta[0].valor==carta[1].valor){
        indicador=indicador+1;
    } /* 1 significa que se puede hacer un trio, una doble pareja , full o un poker*/
    if (carta[0].valor==(carta[0].valor+1)||carta[0].valor==(carta[0].valor-1)){
        indicador=2;/* 2 significa que se puede hacer una escala*/
    }
    if (indicador==1&&carta[0].pinta==carta[1].pinta){
        indicador=indicador+2; /* 3 significa que se puede hacer un trio,un full color, una doble pareja o un poker*/
    }
    if (indicador==2&&carta[0].pinta==carta[1].pinta){
        indicador=indicador+2; /* 4 significa que que se puede hacer una escala o una escala color*/
    }
    }
    if (turno==1){
         /*Significa que ademas de las 2 cartas de la mano hay 3 en mesa, y que el siguiente flop es de solo 1 carta*/

    }
    return indicador;
        /*Si al final el valor de indicador es igual a 0, significa que la prob de ocurrencia de las combinaciones
    será constante, yá explicare esto...*/
}
/*avanzando cualquier comentario es bienvenido xP*/

int prob(CARTA mazo[51],CARTA mano[4],int indicador){
    int pos_trio,pos_doble_pareja,pos_full,pos_poker,pos_escala; /*estas variables indicaran las prob de exito de la ocurrencia de su nombre*/
    if (indicador==1){
        pos_trio=multihipgeo(busqueda_carta_sin_pinta(mano[0].valor,mazo[51]),1, 0, 0, tamano_mazo(mazo[51]), 3);
        if (mano[0].valor!=4){
        pos_doble_pareja=multihipgeo(busqueda_carta_sin_pinta(4,mazo[51]),2,0,0,tamano_mazo(mazo[51]),3);
        }
        else{
            pos_doble_pareja=multihipgeo(busqueda_carta_sin_pinta(5,mazo[51]),2,0,0,tamano_mazo(mazo[51]),3);
        }
        if (mano[0].valor!=4){
            pos_full=multihipgeo(busqueda_carta_sin_pinta(4,mazo[51]),3,mano[0].valor,0,tamano_mazo(mazo[51]),3);
        }
        else{
            pos_full=multihipgeo(busqueda_carta_sin_pinta(5,mazo[51]),3,mano[0].valor,0,tamano_mazo(mazo[51]),3);
        }
        pos_poker=multihipgeo(busqueda_carta_sin_pinta(mano[0],mazo[51]),2,0,0,tamano_mazo(mazo[51]),3);
    }
    if (indicador==2){

        /*Es necesario el siguiente proceso ya que para usar la formula de probabilidades, nito saber que cartas me deberian salir,
        por esto mismo, si tengo una carta 13, la sucesora de esta es 14, pero 14 no existe!, el sucesor de esta deberia ser 1, debido a esto
        los valores de las cartas se pasan a variables independientes y se hace la busqueda apoyandome en las variables sucesores y antecesores
        segun corresponda*/

        if (carta[0].valor>carta[1].valor){
            int carta1,carta2,sucesor1,sucesor2,antecesor1,antecesor2;
            if (carta[0].valor==13){
                sucesor1=1;
                sucesor2=sucesor1+1;
                }
            else if (carta[0].valor==12){
                sucesor1=carta[0].valor+1;
                sucesor2=1;
            }
            else if (carta[0].valor!=12&&carta[0].valor!=13){
                sucesor1=carta[0].valor+1;
                sucesor2=sucesor1+1;
            }
            if (carta[1].valor==1){
                antecesor1=13;
                antecesor2=antecesor1-1;
            }
            else if(carta[1].valor==2){
                antecesor1=carta[1].valor-1;
                antecesor2=13;
            }
            else if(carta[1].valor!=1&&carta[1].valor!=2){
                antecesor1=carta[1].valor-1;
                antecesor2=antecesor1-1;
            }
            pos_escala=multihipgeo(busqueda_carta_sin_pinta(sucesor1,mazo[51]),1,(busqueda_carta_sin_pinta(sucesor2,mazo[51]),1,tamano_mazo(mazo[51]),3)+multihipgeo(busqueda_carta_sin_pinta(antecesor1,mazo[51]),1,(busqueda_carta_sin_pinta(antecesor2,mazo[51]),1,tamano_mazo(mazo[51]),3))+multihipgeo(busqueda_carta_sin_pinta(antecesor1,mazo[51]),1,(busqueda_carta_sin_pinta(sucesor1,mazo[51]),1,tamano_mazo(mazo[51]),3));
            }
            else if (carta[1].valor>carta[0].valor){
            int sucesor1,sucesor2,antecesor1,antecesor2;
            if (carta[1].valor==13){
                sucesor1=1;
                sucesor2=sucesor1+1;
                }
            else if (carta[1].valor==12){
                sucesor1=carta[1].valor+1;
                sucesor2=1;
            }
            else if (carta[1].valor!=12&&carta[1].valor!=13){
                sucesor1=carta[1].valor+1;
                sucesor2=sucesor1+1;
            }
            if (carta[0].valor==1){
                antecesor1=13;
                antecesor2=antecesor1-1;
            }
            else if(carta[0].valor==2){
                antecesor1=carta[0].valor-1;
                antecesor2=13;
            }
            else if(carta[0].valor!=1&&carta[0].valor!=2){
                antecesor1=carta[0].valor-1;
                antecesor2=antecesor1-1;
            }
            pos_escala=multihipgeo(busqueda_carta_sin_pinta(sucesor1,mazo[51]),1,(busqueda_carta_sin_pinta(sucesor2,mazo[51]),1,tamano_mazo(mazo[51]),3)+multihipgeo(busqueda_carta_sin_pinta(antecesor1,mazo[51]),1,(busqueda_carta_sin_pinta(antecesor2,mazo[51]),1,tamano_mazo(mazo[51]),3))+multihipgeo(busqueda_carta_sin_pinta(antecesor1,mazo[51]),1,(busqueda_carta_sin_pinta(sucesor1,mazo[51]),1,tamano_mazo(mazo[51]),3));
            }
    }
    if (indicador==3){ /*trabajando todavia en esto xP*/

    }

}
