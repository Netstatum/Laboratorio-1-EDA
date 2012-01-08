#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "log_factorial.h"
#include "jugador.h"
#include "mesa.h"

double combinatoria(unsigned int a, unsigned int b){
	if (b==0 || a==b){
		return 1;
	}
	else{
		return log_factorial(a)-((log_factorial(b)+log_factorial(a-b)));
	}
}

/*Permite saber cuantas cartas de un tipo quedan*/

int busqueda_carta_sin_pinta(int numero,CARTA mazo[]){
    int i, cantidad=0;
    for (i=0;i<52;i++){
        if (mazo[i].valor==numero && mazo[i].jugada==0){
        cantidad=cantidad+1;}
    }
    return cantidad;
}

int busqueda_carta_con_pinta(char pinta,CARTA mazo[]){
    int i,color;
    for (i=0;i<52;i++){
        if (mazo[i].pinta==pinta && mazo[i].jugada==0){
            color=color+1;
        }
    }
    return color;
}

/*basicamente esta funcion me dice si hay determinada carta en el mazo*/

int busqueda_carta_color_y_numero(int numero,char pinta,CARTA mazo[]){
        int i,carta_exacta;
    for (i=0;i<52;i++){
        if (mazo[i].pinta==pinta && mazo[i].jugada==0 && mazo[i].valor==numero){
            carta_exacta=carta_exacta+1;
            i=52;
        }
    }
    return carta_exacta;
}

/*Permite saber tama�o mazo*/

int tamano_mazo(CARTA mazo[]){
    int i, tamano=0;
    for (i=0;i<52;i++){
        if (mazo[i].jugada==0){
        tamano=tamano+1;
        }
    }
    return tamano;
}



/*Funcion multihipergeometrica en su forma generalizada, falta especificar ahora para los casos particulares de las propias combinaciones de cartas*/
float multihipgeo(int a, int nita_a,int b,int nita_b,int t_mazo,int t_flop){
	return exp(combinatoria(a,nita_a)+combinatoria(b,nita_b)+combinatoria((t_mazo-(a+b)),(t_flop-(nita_a+nita_b)))-combinatoria(t_mazo,t_flop));
}

/*Ahora hay que ver que combiene hacer, como en un principio se tienen 2 cartas, hay que ver si estan son iguales, si son diferentes, si son
de la misma pinta, o si son consecutivas, esto sirve para el principio en que NO HAY CARTAS EN MESA TODAVIA*/

int comparador(CARTA carta[],MESA mesajuego[],int turno){
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
        indicador=indicador+2; /* significa que ademas de lo que se puede hacer en indicador 1, se puede hacer color*/
    }
    if (indicador==2&&carta[0].pinta==carta[1].pinta){
        indicador=indicador+2; /* significa que ademas de lo que se puede hacer en indicador 2, se puede hacer escala color color*/
    }
    }
    if (turno==1){ /*Significa que ademas de las 2 cartas de la mano hay 3 en mesa, y que el siguiente flop es de solo 1 carta*/

/*En general los siguientes indicadores me diran que cumple las mismas propiedades que los indicadores del 0 al 4, pero que
ahora estan en el turno 1, esto significa que al estar en el turno 1, el flop ser� solo de una carta algo que tomare en cuenta
en la funcion de prob, tambien tengo que tomar en cuenta las cartas que est�n en la mesa, que SOLO son 3 en este turno*/

        if (indicador==0)
        /*Este es el peor caso, ya que como no habia nada favorable al principio, entonces habr� que comparar todas
        las cartas entre la mano y la mesa, y lanzar un indicador xP*/
        {
            indicador=5;
        }
        else if (indicador==1){
            indicador=6;
        }
        else if (indicador==2){
            indicador=7;
        }
        else if (indicador==3){
            indicador==8;
        }
        else if (indicador==4){
            indicador==9;
        }

    }
    /*Aqui de nuevo cambian las reglas del juego, debido a que ahora las cartas de la mesa son 4*/

    else if (turno==2){

        /*Pendiente, primero termino el turno 1*/

    }
    return indicador;
        /*Si al final el valor de indicador es igual a 0, significa que la prob de ocurrencia de las combinaciones
    ser� constante, y� explicare esto...*/
}
/*avanzando cualquier comentario es bienvenido xP*/

int prob(CARTA mazo[],CARTA mano[],int indicador){

    /*DEBEN SER tipo float, ya que como guardan las probabilidades de cada caso, pues guardaran muchos decimales*/

    float pos_doble,pos_trio,pos_doble_pareja,pos_color,pos_full,pos_poker,pos_escala,pos_escala_color; /*estas variables indicaran las prob de exito de la ocurrencia de su nombre*/

    if (indicador==0){

        float probabilidad_acumulada;
        int i;
        for (i=0;i<2;i++){
            if (i==0){
                probabilidad_acumulada=probabilidad_acumulada+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),1,busqueda_carta_sin_pinta(mano[i+1].valor,mazo),0,tamano_mazo(mazo),3);
            }
            else if (i==1){
                probabilidad_acumulada=probabilidad_acumulada+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),1,busqueda_carta_sin_pinta(mazo[i-1].valor,mazo),0,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_sin_pinta(mano[i-1].valor,mazo),1,busqueda_carta_sin_pinta(mano[i].valor,mazo),1,tamano_mazo(mazo),3);
            }
        }
        pos_doble=probabilidad_acumulada;
        probabilidad_acumulada=0;

        for (i=0;i<2;i++){
            if (i==0){
                probabilidad_acumulada=probabilidad_acumulada+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),2,busqueda_carta_sin_pinta(mano[i+1].valor,mazo),0,tamano_mazo(mazo),3);
            }
            else if (i==1){
                probabilidad_acumulada=probabilidad_acumulada+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),2,busqueda_carta_sin_pinta(mazo[i-1].valor,mazo),0,tamano_mazo(mazo),3);
            }

        }
        pos_trio=probabilidad_acumulada;
        probabilidad_acumulada=0;
        pos_poker=probabilidad_acumulada; /*No tiene posibilidades de hacer poker el primer turno*/

        for (i=0;i<2;i++){
            if (i==0){

                if (mano[i].valor==11){
                }
        }

    /*Esta la hago al final .... esto significa que al jugador le salio una mano tan dispareja, que no tiene una probabilidad mayor
    para hacer cualquier combinacion, por esto nita que le salgan todas las cartas necesarias*/

    }

    if (indicador==1 || indicador==3){

        pos_doble=0;

        pos_trio=multihipgeo(busqueda_carta_sin_pinta(mano[0].valor,mazo),1, 0, 0, tamano_mazo(mazo), 3);
        if (mano[0].valor!=4){
        pos_doble_pareja=multihipgeo(busqueda_carta_sin_pinta(4,mazo),2,busqueda_carta_sin_pinta(mano[0].valor,mazo),0,tamano_mazo(mazo),3);
        }
        else if(mano[0].valor==4){
            pos_doble_pareja=multihipgeo(busqueda_carta_sin_pinta(5,mazo),2,busqueda_carta_sin_pinta(mano[0].valor,mazo),0,tamano_mazo(mazo),3);
        }
        if (mano[0].valor!=4){
            pos_full=multihipgeo(busqueda_carta_sin_pinta(mano[0].valor,mazo),1,busqueda_carta_sin_pinta(4,mazo),2,tamano_mazo(mazo),3);
        }
        else if(mano[0].valor==4){
            pos_full=multihipgeo((busqueda_carta_sin_pinta(mano[0].valor,mazo)),1,(busqueda_carta_sin_pinta(5,mazo)),2,tamano_mazo(mazo),3);
        }
        pos_poker=multihipgeo(busqueda_carta_sin_pinta(mano[0].valor,mazo),2,0,0,tamano_mazo(mazo),3);

        if (indicador==3){
            pos_color=multihipgeo(busqueda_carta_con_pinta(mano[0].pinta,mazo),2,0,0,tamano_mazo(mazo),3);
        }
        else if(indicador==2){
            float prob1,prob2;
            prob1=multihipgeo(busqueda_carta_con_pinta(mano[0].pinta,mazo),3,0,0,tamano_mazo(mazo),3);
            prob2=multihipgeo(busqueda_carta_con_pinta(mano[1].pinta,mazo),2,0,0,tamano_mazo(mazo),3);
            if (prob1>=prob2){
            pos_color=prob1;
            }
            else if(prob2>prob1){
            pos_color=prob2;
            }
        }
    }

    /*Falta ver la prob de que salga escalera, escalera color y escalera real.... aunque si se tienen 2 cartas iguales (lo indica el indicador)
    entonces... se nita que las 3 cartas del flop sean consecutivas xdd, por tanto para estos 3 casos seria la misma metodologia
    que se deberia usar como si fuera el indicador ==0 */


    if (indicador==2||indicador==4){

        /*Es necesario el siguiente proceso ya que para usar la formula de probabilidades, nito saber que cartas me deberian salir,
        por esto mismo, si tengo una carta 13, la sucesora de esta es 14, pero 14 no existe!, el sucesor de esta deberia ser 1, debido a esto
        los valores de las cartas se pasan a variables independientes y se hace la busqueda apoyandome en las variables sucesores y antecesores
        segun corresponda*/

        if (mano[0].valor>mano[1].valor){
            int sucesor1,sucesor2,antecesor1,antecesor2;
            if (mano[0].valor==13){
                sucesor1=1;
                sucesor2=sucesor1+1;
                }
            else if (mano[0].valor==12){
                sucesor1=mano[0].valor+1;
                sucesor2=1;
            }
            else if (mano[0].valor!=12&&mano[0].valor!=13){
                sucesor1=mano[0].valor+1;
                sucesor2=sucesor1+1;
            }
            if (mano[1].valor==1){
                antecesor1=13;
                antecesor2=antecesor1-1;
            }
            else if(mano[1].valor==2){
                antecesor1=mano[1].valor-1;
                antecesor2=13;
            }
            else if(mano[1].valor!=1&&mano[1].valor!=2){
                antecesor1=mano[1].valor-1;
                antecesor2=antecesor1-1;
            }
            pos_escala=multihipgeo((busqueda_carta_sin_pinta(sucesor1,mazo)),1,(busqueda_carta_sin_pinta(sucesor2,mazo)),1,tamano_mazo(mazo),3)+multihipgeo((busqueda_carta_sin_pinta(antecesor1,mazo)),1,(busqueda_carta_sin_pinta(antecesor2,mazo)),1,tamano_mazo(mazo),3)+multihipgeo((busqueda_carta_sin_pinta(antecesor1,mazo)),1,(busqueda_carta_sin_pinta(sucesor1,mazo)),1,tamano_mazo(mazo),3);
            }
            else if (mano[1].valor>mano[0].valor){
            int sucesor1,sucesor2,antecesor1,antecesor2;
            if (mano[1].valor==13){
                sucesor1=1;
                sucesor2=sucesor1+1;
                }
            else if (mano[1].valor==12){
                sucesor1=mano[1].valor+1;
                sucesor2=1;
            }
            else if (mano[1].valor!=12&&mano[1].valor!=13){
                sucesor1=mano[1].valor+1;
                sucesor2=sucesor1+1;
            }
            if (mano[0].valor==1){
                antecesor1=13;
                antecesor2=antecesor1-1;
            }
            else if(mano[0].valor==2){
                antecesor1=mano[0].valor-1;
                antecesor2=13;
            }
            else if(mano[0].valor!=1&&mano[0].valor!=2){
                antecesor1=mano[0].valor-1;
                antecesor2=antecesor1-1;
            }
            if (indicador==2){
            pos_escala=multihipgeo((busqueda_carta_sin_pinta(sucesor1,mazo)),1,(busqueda_carta_sin_pinta(sucesor2,mazo)),1,tamano_mazo(mazo),3)+multihipgeo((busqueda_carta_sin_pinta(antecesor1,mazo)),1,(busqueda_carta_sin_pinta(antecesor2,mazo)),1,tamano_mazo(mazo),3)+multihipgeo((busqueda_carta_sin_pinta(antecesor1,mazo)),1,(busqueda_carta_sin_pinta(sucesor1,mazo)),1,tamano_mazo(mazo),3);
            }
            else if(indicador==4){
            pos_escala_color=multihipgeo((busqueda_carta_color_y_numero(sucesor1,mano[0].pinta,mazo)),1,(busqueda_carta_color_y_numero(sucesor2,mano[0].pinta,mazo)),1,tamano_mazo(mazo),3)+multihipgeo((busqueda_carta_color_y_numero(antecesor1,mano[0].pinta,mazo)),1,(busqueda_carta_color_y_numero(antecesor2,mano[0].pinta,mazo)),1,tamano_mazo(mazo),3)+multihipgeo((busqueda_carta_color_y_numero(antecesor1,mano[0].pinta,mazo)),1,(busqueda_carta_color_y_numero(sucesor1,mano[0].pinta,mazo)),1,tamano_mazo(mazo),3);
            }
            }
    }
    if (indicador==5){

    /*Esto es lo mismo que el indicador 0 pero en el turno 1... por lo mismo lo dejo para el final*/

    }
}

/*ya est� hecha casi toda la parte de sacar la probabilidad del primer turno donde el flop es de 3 cartas,
ahora como solo es de una carta, creo que se usa la distribucion hipergeometrica no mas, no la multi, voy a tener que ver xP*/
}
