#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "jugador.h"
#include "mesa.h"

/*=========Esto es para calcular factorial=======*/
float log_factorial(int n)
{
	float factorial=0;
	int i;

	for(i=2;i<=n;i++)
	{
		factorial=factorial+log(i);
	}

	return factorial;
}

/*====================================================*/

/*Esto es para calcula combinatoria de la forma a sobre b */

double combinatoria(unsigned int a, unsigned int b){
	if (b==0 || a==b){
		return 1;
	}
	else{
		return log_factorial(a)-((log_factorial(b)+log_factorial(a-b)));
	}
}
/*==========================================*/

/*Permite saber cuantas cartas de un tipo quedan, por ejemplo cuantos cartas con el numero 4 quedan en el mazo (sin contar la pinta)*/

int busqueda_carta_sin_pinta(int numero,CARTA mazo[]){
    int i, cantidad=0;
    for (i=0;i<52;i++){ /*Para esto busco en el array del mazo, si el valor es igual al numero ingresado en la funcion y si ademas, la carta del mazo no ha sido jugada*/
        if (mazo[i].valor==numero && mazo[i].jugada==0){
        cantidad=cantidad+1;}
    }
    return cantidad; /*Retorno la cantidad de encuentros*/
}

/*======================================================================================================================0*/

/*Permite saber que cartas de cierta pinta quedan en el mazo*/

int busqueda_carta_con_pinta(char pinta,CARTA mazo[]){
    int i,color=0;
    for (i=0;i<52;i++){
        if (mazo[i].pinta==pinta && mazo[i].jugada==0){ /*Es lo mismo que con la funcion anterior, pero aqui no se toma en cuenta el valor de la carta sino que su pinta*/
            color=color+1;
        }
    }
    return color; /*Se retorna la cantidad de cartas con la misma pinta*/
}

/*======================================================================================================================*/


/*Esta funcion me permite saber si hay una carta en especifico en el mazo*/

int busqueda_carta_color_y_numero(int numero,char pinta,CARTA mazo[]){
    int i,carta_exacta=0;
    for (i=0;i<52;i++){
        if (mazo[i].pinta==pinta && mazo[i].jugada==0 && mazo[i].valor==numero){
            carta_exacta=carta_exacta+1;
            i=52;
        }
    }
    return carta_exacta;
}

/*======================================================================*/

/*Permite saber tamaño mazo*/

int tamano_mazo(CARTA mazo[]){
    int i, tamano=0;
    for (i=0;i<52;i++){ /*Para ello busco la cantidad de cartas que no han sido jugadas del mazo (las que tienen su indicador jugada=0*/
        if (mazo[i].jugada==0){
        tamano=tamano+1;
        }
    }
    return tamano;
}
/*Funcion multihipergeometrica en su forma generalizada*/
float multihipgeo(int a, int nita_a,int b,int nita_b,int t_mazo,int t_flop){
	return exp(combinatoria(a,nita_a)+combinatoria(b,nita_b)+combinatoria((t_mazo-(a+b)),(t_flop-(nita_a+nita_b)))-combinatoria(t_mazo,t_flop));
}

/*------------------------------------------------------------------------------------------

/*Funcion que muestra los datos en pantalla*/
void Imprimir_datos(float pos_doble,float pos_trio, float pos_doble_pareja, float pos_escala, float pos_color, float pos_full, float pos_poker, float pos_escala_color){
printf("Doble:%.10f", pos_doble);printf("%\n");
printf("Trio:%.10f", pos_trio);printf("%\n");
printf("Doble pareja:%.10f",pos_doble_pareja);printf("%\n");
printf("Escala:%.10f", pos_escala);printf("%\n");
printf("Color:%.10f",pos_color);printf("%\n");
printf("Full:%.10f",pos_full);printf("%\n");
printf("Poker:%.10f",pos_poker);printf("%\n");
printf("Escala Color:%.10f",pos_escala_color);printf("%\n");
}

/*Esta funcion me indica que tipo de cartas me quedaron en la mano cuando me las pasaron y en que turno voy asi se puede diferenciar el caso en que salen 3 cartas del mazo a la mesa
y el otro caso en que solo sale una carta del mazo a la mesa*/

int comparador(CARTA carta[],int turno){
    int indicador=0; /*Si el indicador queda como 0, significa que tienes una mala mano y estas en el turno 1*/

    if (turno==0){ /*Significa que saldran 3 cartas del mazo a la mesa!!!*/

    if (carta[0].valor==carta[1].valor){ /*Esto significa que las cartas que te han salido son iguales!! y estas en el turno 1*/
        indicador=indicador+1;
    }
    if (carta[0].valor==(carta[0].valor+1)||carta[0].valor==(carta[0].valor-1)){ /*Significa que tus cartas se diferencia en 1 unidad, o sea son consecutivas.... lo que significa que hay mas posibilidades de hacer una escala!!*/
        indicador=2;
    }
    if (indicador==1&&carta[0].pinta==carta[1].pinta){ /*Significa que tienes un par y ademas son de la misma pinta*/
        indicador=indicador+2;
    }
    if (indicador==2&&carta[0].pinta==carta[1].pinta){ /*Significa que tus cartas son consecutivas y de la misma pinta*/
        indicador=indicador+2;
    }
    }
        if (indicador==0&&(turno==1||turno==2)){ /*Lo mismo que el indicador 0, pero ahora está en el turno 1 o 2*/
            indicador=5;
        }
        else if (indicador==1&&(turno==1||turno==2)){/*Lo mismo que el indicador 1, pero ahora está en el turno 1 o 2*/
            indicador=6;
        }
        else if (indicador==2&&(turno==1||turno==2)){/*Lo mismo que el indicador 2, pero ahora está en el turno 1 o 2*/
            indicador=7;
        }
        else if (indicador==3&&(turno==1||turno==2)){/*Lo mismo que el indicador 3, pero ahora está en el turno 1 o 2*/
            indicador==8;
        }
        else if (indicador==4&&(turno==1||turno==2)){/*Lo mismo que el indicador 4, pero ahora está en el turno 1 o 2*/
            indicador==9;
        }

    return indicador; /*el indicador a final de cuentas, es el que me dice que tipo de mano tiene el jugador y en que turno va*/
}

/*Esta funcion me retorna las probabilidades de que me salga la carta que necesito en el flop, river o turno para hacer alguna combinacion*/

int prob(CARTA mazo[],CARTA mano[],MESA mesajuego,int indicador){


    float pos_doble=0,pos_trio=0,pos_doble_pareja=0,pos_color=0,pos_full=0,pos_poker=0,pos_escala=0,pos_escala_color=0; /*estas variables indicaran las prob de exito de la ocurrencia de su nombre*/

    if (indicador==0){
        int i;
        int sucesor1,sucesor2,sucesor3,antecesor1,antecesor2,antecesor3;

        for (i=0;i<2;i++){
            if (mano[i].valor==11){
                sucesor1=12,sucesor2=13,sucesor3=1;
                antecesor1=mano[i].valor-1,antecesor2=antecesor1-1,antecesor3=antecesor2-1;
                }
            else if (mano[i].valor==12){
                sucesor1=13,sucesor2=1,sucesor3=2;
                antecesor1=mano[i].valor-1,antecesor2=antecesor1-1,antecesor3=antecesor2-1;
                }
            else if (mano[i].valor==13){
                sucesor1=1,sucesor2=2,sucesor3=3;
                antecesor1=mano[i].valor-1,antecesor2=antecesor1-1,antecesor3=antecesor2-1;
                }
            else if (mano[i].valor==1){
                sucesor1=mano[i].valor+1,sucesor2=sucesor1+1,sucesor3=sucesor2+1;
                antecesor1=13,antecesor2=12,antecesor3=13;
                }
            else if (mano[i].valor==2){
                sucesor1=mano[i].valor+1,sucesor2=sucesor1+1,sucesor3=sucesor2+1;
                antecesor1=1,antecesor2=13,antecesor3=12;
                }
            else if (mano[i].valor==3){
                sucesor1=mano[i].valor+1,sucesor2=sucesor1+1,sucesor3=sucesor2+1;
                antecesor1=2,antecesor2=1,antecesor3=13;
                }
            else{
                sucesor1=mano[i].valor+1,sucesor2=sucesor1+1,sucesor3=sucesor2+1;
                antecesor1=mano[i].valor-1,antecesor2=antecesor1-1,antecesor3=antecesor2-1;
                }
            pos_escala=pos_escala+multihipgeo(busqueda_carta_sin_pinta(sucesor1,mazo),1,busqueda_carta_sin_pinta(sucesor2,mazo),1,tamano_mazo(mazo),3)*multihipgeo(busqueda_carta_sin_pinta(sucesor3,mazo),1,0,0,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_sin_pinta(antecesor1,mazo),1,busqueda_carta_sin_pinta(antecesor2,mazo),1,tamano_mazo(mazo),3)*multihipgeo(busqueda_carta_sin_pinta(antecesor3,mazo),1,0,0,tamano_mazo(mazo),3);
            pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(sucesor1,mano[i].pinta,mazo),1,busqueda_carta_color_y_numero(sucesor2,mano[i].pinta,mazo),1,tamano_mazo(mazo),3)*multihipgeo(busqueda_carta_color_y_numero(sucesor3,mano[i].pinta,mazo),1,0,0,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_color_y_numero(antecesor1,mano[i].pinta,mazo),1,busqueda_carta_color_y_numero(antecesor2,mano[i].pinta,mazo),1,tamano_mazo(mazo),3)*multihipgeo(busqueda_carta_color_y_numero(antecesor3,mano[i].pinta,mazo),1,0,0,tamano_mazo(mazo),3);
            if (mano[0].pinta!=mano[1].pinta){
                pos_color=pos_color+multihipgeo(busqueda_carta_con_pinta(mano[i].pinta,mazo),3,busqueda_carta_con_pinta(mano[i].pinta,mazo),0,tamano_mazo(mazo),3);
            }
            else{
            pos_color=multihipgeo(busqueda_carta_con_pinta(mano[i].pinta,mazo),2,busqueda_carta_con_pinta(mano[i].pinta,mazo),1,tamano_mazo(mazo),3);
            }
            if (busqueda_carta_sin_pinta(mano[i].valor,mazo)==3){
            pos_poker=pos_poker+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),2,busqueda_carta_sin_pinta(mano[i].valor,mazo),1,tamano_mazo(mazo),3);
            pos_doble_pareja=pos_poker;
            }
            else{
            pos_poker=0;
            pos_doble_pareja=pos_poker;
            }

            if (i==0){
                pos_doble=pos_doble+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),1,busqueda_carta_sin_pinta(mano[i+1].valor,mazo),0,tamano_mazo(mazo),3);
                pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),2,busqueda_carta_sin_pinta(mano[i+1].valor,mazo),0,tamano_mazo(mazo),3);
            }
            else if (i==1){
                pos_doble=pos_doble+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),1,busqueda_carta_sin_pinta(mazo[i-1].valor,mazo),0,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_sin_pinta(mano[i-1].valor,mazo),1,busqueda_carta_sin_pinta(mano[i].valor,mazo),1,tamano_mazo(mazo),3);
                pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),2,busqueda_carta_sin_pinta(mazo[i-1].valor,mazo),0,tamano_mazo(mazo),3);
            }
            /*la posibilidad de que haya full es nula, asi que no se modifica*/

        }
    }

    if (indicador==1 || indicador==3){
        int i,sucesor1,sucesor2,sucesor3,antecesor1,antecesor2,antecesor3;

        pos_doble=0; /*ya se tiene doble, por esto se dejó en 0*/

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

        for (i=0;i<2;i++){
            if (mano[i].valor==11){
                sucesor1=12,sucesor2=13,sucesor3=1;
                antecesor1=mano[i].valor-1,antecesor2=antecesor1-1,antecesor3=antecesor2-1;
                }
            else if (mano[i].valor==12){
                sucesor1=13,sucesor2=1,sucesor3=2;
                antecesor1=mano[i].valor-1,antecesor2=antecesor1-1,antecesor3=antecesor2-1;
                }
            else if (mano[i].valor==13){
                sucesor1=1,sucesor2=2,sucesor3=3;
                antecesor1=mano[i].valor-1,antecesor2=antecesor1-1,antecesor3=antecesor2-1;
                }
            else if (mano[i].valor==1){
                sucesor1=mano[i].valor+1,sucesor2=sucesor1+1,sucesor3=sucesor2+1;
                antecesor1=13,antecesor2=12,antecesor3=13;
                }
            else if (mano[i].valor==2){
                sucesor1=mano[i].valor+1,sucesor2=sucesor1+1,sucesor3=sucesor2+1;
                antecesor1=1,antecesor2=13,antecesor3=12;
                }
            else if (mano[i].valor==3){
                sucesor1=mano[i].valor+1,sucesor2=sucesor1+1,sucesor3=sucesor2+1;
                antecesor1=2,antecesor2=1,antecesor3=13;
                }
            else{
                sucesor1=mano[i].valor+1,sucesor2=sucesor1+1,sucesor3=sucesor2+1;
                antecesor1=mano[i].valor-1,antecesor2=antecesor1-1,antecesor3=antecesor2-1;
                }
            pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(sucesor1,mano[i].pinta,mazo),1,busqueda_carta_color_y_numero(sucesor2,mano[i].pinta,mazo),1,tamano_mazo(mazo),3)*multihipgeo(busqueda_carta_color_y_numero(sucesor3,mano[i].pinta,mazo),1,0,0,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_color_y_numero(antecesor1,mano[i].pinta,mazo),1,busqueda_carta_color_y_numero(antecesor2,mano[i].pinta,mazo),1,tamano_mazo(mazo),3)*multihipgeo(busqueda_carta_color_y_numero(antecesor3,mano[i].pinta,mazo),1,0,0,tamano_mazo(mazo),3);
            pos_escala=multihipgeo(busqueda_carta_sin_pinta(sucesor1,mazo),1,busqueda_carta_sin_pinta(sucesor2,mazo),1,tamano_mazo(mazo),3)*multihipgeo(busqueda_carta_sin_pinta(sucesor3,mazo),1,0,0,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_sin_pinta(antecesor1,mazo),1,busqueda_carta_sin_pinta(antecesor2,mazo),1,tamano_mazo(mazo),3)*multihipgeo(busqueda_carta_sin_pinta(antecesor3,mazo),1,0,0,tamano_mazo(mazo),3);
        }

        if (indicador==3){
            pos_color=multihipgeo(busqueda_carta_con_pinta(mano[0].pinta,mazo),2,0,0,tamano_mazo(mazo),3);
        }
        else if(indicador==1){
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

    /*Falta ver la escalera real....*/

    if (indicador==2||indicador==4){
        int i;

        /*Es necesario el siguiente proceso ya que para usar la formula de probabilidades, nito saber que cartas me deberian salir,
        por esto mismo, si tengo una carta 13, la sucesora de esta es 14, pero 14 no existe!, el sucesor de esta deberia ser 1, debido a esto
        los valores de las cartas se pasan a variables independientes y se hace la busqueda apoyandome en las variables sucesores y antecesores
        segun corresponda*/

        if (mano[0].valor>mano[1].valor){
            int sucesor1=0,sucesor2=0,antecesor1=0,antecesor2=0;
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
                antecesor2=mano[1].valor-2;
            }
            pos_escala=multihipgeo(busqueda_carta_sin_pinta(sucesor1,mazo),1,busqueda_carta_sin_pinta(sucesor2,mazo),1,tamano_mazo(mazo),3)+multihipgeo((busqueda_carta_sin_pinta(antecesor1,mazo)),1,busqueda_carta_sin_pinta(antecesor2,mazo),1,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_sin_pinta(antecesor1,mazo),1,busqueda_carta_sin_pinta(sucesor1,mazo),1,tamano_mazo(mazo),3);
            if(indicador==4){
                pos_escala_color=multihipgeo(busqueda_carta_color_y_numero(sucesor1,mano[0].pinta,mazo),1,busqueda_carta_color_y_numero(sucesor2,mano[0].pinta,mazo),1,tamano_mazo(mazo),3)+multihipgeo((busqueda_carta_color_y_numero(antecesor1,mano[0].pinta,mazo)),1,busqueda_carta_color_y_numero(antecesor2,mano[0].pinta,mazo),1,tamano_mazo(mazo),3)+multihipgeo((busqueda_carta_color_y_numero(antecesor1,mano[0].pinta,mazo)),1,(busqueda_carta_color_y_numero(sucesor1,mano[0].pinta,mazo)),1,tamano_mazo(mazo),3);
            }

            }
            else if (mano[1].valor>mano[0].valor){
            int sucesor1=0,sucesor2=0,antecesor1=0,antecesor2=0;
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
            pos_escala=multihipgeo(busqueda_carta_sin_pinta(sucesor1,mazo),1,busqueda_carta_sin_pinta(sucesor2,mazo),1,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_sin_pinta(antecesor1,mazo),1,busqueda_carta_sin_pinta(antecesor2,mazo),1,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_sin_pinta(antecesor1,mazo),1,busqueda_carta_sin_pinta(sucesor1,mazo),1,tamano_mazo(mazo),3);

            if(indicador==4){
            pos_escala_color=multihipgeo(busqueda_carta_color_y_numero(sucesor1,mano[0].pinta,mazo),1,busqueda_carta_color_y_numero(sucesor2,mano[0].pinta,mazo),1,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_color_y_numero(antecesor1,mano[0].pinta,mazo),1,busqueda_carta_color_y_numero(antecesor2,mano[0].pinta,mazo),1,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_color_y_numero(antecesor1,mano[0].pinta,mazo),1,busqueda_carta_color_y_numero(sucesor1,mano[0].pinta,mazo),1,tamano_mazo(mazo),3);
            }
            }

    for (i=0;i<2;i++){
    if (mano[0].pinta!=mano[1].pinta){
                pos_color=pos_color+multihipgeo(busqueda_carta_con_pinta(mano[i].pinta,mazo),3,busqueda_carta_con_pinta(mano[i].pinta,mazo),0,tamano_mazo(mazo),3);
            }
            else{
            pos_color=multihipgeo(busqueda_carta_con_pinta(mano[i].pinta,mazo),2,busqueda_carta_con_pinta(mano[i].pinta,mazo),1,tamano_mazo(mazo),3);
            }
            if (busqueda_carta_sin_pinta(mano[i].valor,mazo)==3){
            pos_poker=pos_poker+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),2,busqueda_carta_sin_pinta(mano[i].valor,mazo),1,tamano_mazo(mazo),3);
            pos_doble_pareja=pos_poker;
            }
            else{
            pos_poker=0;
            pos_doble_pareja=pos_poker;
            }

            if (i==0){
                pos_doble=pos_doble+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),1,busqueda_carta_sin_pinta(mano[i+1].valor,mazo),0,tamano_mazo(mazo),3);
                pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),2,busqueda_carta_sin_pinta(mano[i+1].valor,mazo),0,tamano_mazo(mazo),3);
            }
            else if (i==1){
                pos_doble=pos_doble+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),1,busqueda_carta_sin_pinta(mazo[i-1].valor,mazo),0,tamano_mazo(mazo),3)+multihipgeo(busqueda_carta_sin_pinta(mano[i-1].valor,mazo),1,busqueda_carta_sin_pinta(mano[i].valor,mazo),1,tamano_mazo(mazo),3);
                pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),2,busqueda_carta_sin_pinta(mazo[i-1].valor,mazo),0,tamano_mazo(mazo),3);
            }
    }
    }
    if (indicador==5){
        int i,j,guarda_par1=0,guarda_par2=0,guarda_par3=0,guarda_par4=0;
        for (i=0;i<2;i++){
            if (busqueda_carta_con_pinta(mano[i].pinta,mesajuego.cartasJugada)==2){ /*Esto implica que hay 2 cartas en mesa que tienen la misma pinta que una de las cartas de tu mano, como el indicador es el caso 5, tienes la peor mano, asi que tus cartas son de distinto color...*/
                pos_color=pos_color+multihipgeo(busqueda_carta_con_pinta(mano[i].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            int sucesor1=0,sucesor2=0,sucesor3=0,antecesor1=0,antecesor2=0,antecesor3=0;
            if (mano[i].valor==13){
                sucesor1=1;
                sucesor2=sucesor1+1;
                sucesor3=sucesor2+1;
                antecesor1=mano[i].valor-1;
                antecesor2=antecesor1-1;
                antecesor3=antecesor2-1;
                }
            else if (mano[i].valor==12){
                sucesor1=mano[i].valor+1;
                sucesor2=1;
                sucesor3=sucesor2+1;
                antecesor1=mano[i].valor-1;
                antecesor2=antecesor1-1;
                antecesor3=antecesor2-1;
            }
            else if (mano[i].valor==11){
                sucesor1=mano[i].valor+1;
                sucesor2=sucesor1+1;
                sucesor3=1;
                antecesor1=mano[i].valor-1;
                antecesor2=antecesor1-1;
                antecesor3=antecesor2-1;
            }
            else if (mano[i].valor==1){
                antecesor1=13;
                antecesor2=antecesor1-1;
                antecesor3=antecesor2-1;
                sucesor1=mano[i].valor+1;
                sucesor2=sucesor1+1;
                sucesor3=sucesor2+1;
            }
            else if(mano[i].valor==2){
                antecesor1=mano[i].valor-1;
                antecesor2=13;
                antecesor3=antecesor2-1;
                sucesor1=mano[i].valor+1;
                sucesor2=sucesor1+1;
                sucesor3=sucesor2+1;
            }
            else if(mano[i].valor==3){
                antecesor1=mano[i].valor-1;
                antecesor2=antecesor1-1;
                antecesor3=13;
                sucesor1=mano[i].valor+1;
                sucesor2=sucesor1+1;
                sucesor3=sucesor2+1;
            }
            if (busqueda_carta_sin_pinta(sucesor1,mesajuego.cartasJugada)==1&&busqueda_carta_sin_pinta(sucesor2,mesajuego.cartasJugada)==1){
                pos_escala=pos_escala+multihipgeo(busqueda_carta_sin_pinta(sucesor3,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if (busqueda_carta_color_y_numero(sucesor1,mano[i].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(sucesor2,mano[i].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(sucesor3,mano[i].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if (busqueda_carta_sin_pinta(sucesor1,mesajuego.cartasJugada)==1&&busqueda_carta_sin_pinta(antecesor1,mesajuego.cartasJugada)==1){
                pos_escala=pos_escala+multihipgeo(busqueda_carta_sin_pinta(sucesor2,mazo),1,0,0,tamano_mazo(mazo),1)+multihipgeo(busqueda_carta_sin_pinta(antecesor2,mazo),1,0,0,tamano_mazo(mazo),1);
                }
            if (busqueda_carta_color_y_numero(sucesor1,mano[i].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(antecesor1,mano[i].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(sucesor2,mano[i].pinta,mazo),1,0,0,tamano_mazo(mazo),1)+multihipgeo(busqueda_carta_color_y_numero(antecesor2,mano[i].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
                }
            if (busqueda_carta_sin_pinta(antecesor1,mesajuego.cartasJugada)==1&&busqueda_carta_sin_pinta(antecesor2,mesajuego.cartasJugada)==1){
                pos_escala=pos_escala+multihipgeo(busqueda_carta_sin_pinta(antecesor3,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if (busqueda_carta_color_y_numero(antecesor1,mano[i].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(antecesor2,mano[i].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(antecesor3,mano[i].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if (i==0){
                    pos_doble=multihipgeo(busqueda_carta_sin_pinta(mano[0].valor,mazo),1,0,0,tamano_mazo(mazo),1);

                }
                else if (i==1){
                    pos_doble=multihipgeo(busqueda_carta_sin_pinta(mano[1].valor,mazo),1,0,0,tamano_mazo(mazo),1);
                    pos_doble=pos_doble/2;
                    pos_escala=pos_escala/2;
                    pos_escala_color=pos_escala_color/2;
                    }


            if (busqueda_carta_sin_pinta(mano[i].valor,mesajuego.cartasJugada)==1) /*significa que tiene al menos una repeticion en la mesa*/ {
                if (guarda_par1==0){
                    guarda_par1=mano[i].valor;
                }
                else if (guarda_par1!=0&&guarda_par2==0){
                    guarda_par2=mano[i].valor;
                }
                if (busqueda_carta_sin_pinta(mano[i].valor,mesajuego.cartasJugada)==2){
                if (i==0){
                    pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mano[0].valor,mazo),1,busqueda_carta_sin_pinta(mano[1].valor,mazo),0,tamano_mazo(mazo),1);
            }
                if (i!=0){
                    pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mano[1].valor,mazo),1,busqueda_carta_sin_pinta(mano[0].valor,mazo),0,tamano_mazo(mazo),1);
                    pos_trio=pos_trio/2;
                }
                }
            }
            if (busqueda_carta_sin_pinta(mano[i].valor,mesajuego.cartasJugada)==2) /*Significa que hay un trio*/{
                pos_poker=pos_poker+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),1,0,0,tamano_mazo(mazo),1);
            }
        }
        for (j=0;j<5;j++){
            float pos_doble2=0;
            if (busqueda_carta_con_pinta(mesajuego.cartasJugada[j].pinta,mesajuego.cartasJugada)==3){
                pos_color=pos_color+multihipgeo(busqueda_carta_con_pinta(mesajuego.cartasJugada[j].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
                }

            pos_doble2=pos_doble2+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
            if (j==4){
                pos_doble2=pos_doble2/j;
                pos_doble=pos_doble+pos_doble2;
            }

        if (busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mesajuego.cartasJugada)==3){ /*Significa que hay un par entre las cartas de la mesa*/
            pos_poker=pos_poker+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
        }

        if (busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mesajuego.cartasJugada)==2){ /*Se pone 2 debido a que se comparará la carta consigo misma, asi que por lo menos encontrará una (ella misma...)*/
            pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
                if (guarda_par1==0){
                    guarda_par1=mesajuego.cartasJugada[j].valor;
                }
                else if (guarda_par1!=0&&guarda_par2==0){
                    guarda_par2=mesajuego.cartasJugada[j].valor;
                }
                else if (guarda_par2!=0&&guarda_par3==0){
                    guarda_par2=mesajuego.cartasJugada[j].valor;
                    }
                else if (guarda_par3!=0&&guarda_par4==0){
                    guarda_par2=mesajuego.cartasJugada[j].valor;
                }
        }
        }
        if (guarda_par1!=0){
            if (guarda_par1!=mesajuego.cartasJugada[j].valor){
                pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
            }

            if (guarda_par2!=0&&guarda_par1!=guarda_par2){
                pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par2,mazo),1,0,0,tamano_mazo(mazo),1);
        }
        }
        if (guarda_par3!=0){
            if (guarda_par3!=mesajuego.cartasJugada[j].valor){
                pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if(guarda_par1!=0&&guarda_par1!=guarda_par3){
                pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par3,mazo),1,0,0,tamano_mazo(mazo),1);
        }
        }
        if(guarda_par4!=0){
            if (guarda_par4!=mesajuego.cartasJugada[j].valor){
                pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
            }

        if(guarda_par1!=0&&guarda_par1!=guarda_par4){
            pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par4,mazo),1,0,0,tamano_mazo(mazo),1);
        }
        }
        if (guarda_par2!=0){
            if (guarda_par2!=mesajuego.cartasJugada[j].valor){
            pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if(guarda_par3!=0&&guarda_par2!=guarda_par3){
            pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par3,mazo),1,0,0,tamano_mazo(mazo),1);
        }
        }
        if (guarda_par2!=0&&guarda_par4!=0&&guarda_par2!=guarda_par4){
            pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par4,mazo),1,0,0,tamano_mazo(mazo),1);
        }
        if (guarda_par3!=0&&guarda_par4!=0&&guarda_par3!=guarda_par4){
            pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par3,mazo),1,0,0,tamano_mazo(mazo),1);
        }
    }


    if (indicador==6||indicador==8){ /*Corresponden a mano inicial par, de mismo color o no, con turno 1 o 2*/
        int guarda_par1=0,guarda_par2=0,guarda_par3=0,guarda_par4=0;
            if (busqueda_carta_con_pinta(mano[0].pinta,mesajuego.cartasJugada)==2){ /*Esto implica que hay 2 cartas en mesa que tienen la misma pinta que una de las cartas de tu mano, como el indicador es el caso 5, tienes la peor mano, asi que tus cartas son de distinto color...*/
                pos_color=pos_color+multihipgeo(busqueda_carta_con_pinta(mano[0].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
                pos_doble=1;/*Debido a que ya se tiene un par*/
            }
            int sucesor1=0,sucesor2=0,sucesor3=0,antecesor1=0,antecesor2=0,antecesor3=0;
            if (mano[0].valor==13){
                sucesor1=1;
                sucesor2=sucesor1+1;
                sucesor3=sucesor2+1;
                antecesor1=mano[0].valor-1;
                antecesor2=antecesor1-1;
                antecesor3=antecesor2-1;
                }
            else if (mano[0].valor==12){
                sucesor1=mano[0].valor+1;
                sucesor2=1;
                sucesor3=sucesor2+1;
                antecesor1=mano[0].valor-1;
                antecesor2=antecesor1-1;
                antecesor3=antecesor2-1;
            }
            else if (mano[0].valor==11){
                sucesor1=mano[0].valor+1;
                sucesor2=sucesor1+1;
                sucesor3=1;
                antecesor1=mano[0].valor-1;
                antecesor2=antecesor1-1;
                antecesor3=antecesor2-1;
            }
            else if (mano[0].valor==1){
                antecesor1=13;
                antecesor2=antecesor1-1;
                antecesor3=antecesor2-1;
                sucesor1=mano[0].valor+1;
                sucesor2=sucesor1+1;
                sucesor3=sucesor2+1;
            }
            else if(mano[0].valor==2){
                antecesor1=mano[0].valor-1;
                antecesor2=13;
                antecesor3=antecesor2-1;
                sucesor1=mano[0].valor+1;
                sucesor2=sucesor1+1;
                sucesor3=sucesor2+1;
            }
            else if(mano[0].valor==3){
                antecesor1=mano[0].valor-1;
                antecesor2=antecesor1-1;
                antecesor3=13;
                sucesor1=mano[0].valor+1;
                sucesor2=sucesor1+1;
                sucesor3=sucesor2+1;
            }
            if (busqueda_carta_sin_pinta(sucesor1,mesajuego.cartasJugada)==1&&busqueda_carta_sin_pinta(sucesor2,mesajuego.cartasJugada)==1){
                pos_escala=pos_escala+multihipgeo(busqueda_carta_sin_pinta(sucesor3,mazo),1,0,0,tamano_mazo(mazo),1);
            }

            if (busqueda_carta_sin_pinta(sucesor1,mesajuego.cartasJugada)==1&&busqueda_carta_sin_pinta(antecesor1,mesajuego.cartasJugada)==1){
                pos_escala=pos_escala+multihipgeo(busqueda_carta_sin_pinta(sucesor2,mazo),1,0,0,tamano_mazo(mazo),1)+multihipgeo(busqueda_carta_sin_pinta(antecesor2,mazo),1,0,0,tamano_mazo(mazo),1);
                }

            if (busqueda_carta_sin_pinta(antecesor1,mesajuego.cartasJugada)==1&&busqueda_carta_sin_pinta(antecesor2,mesajuego.cartasJugada)==1){
                pos_escala=pos_escala+multihipgeo(busqueda_carta_sin_pinta(antecesor3,mazo),1,0,0,tamano_mazo(mazo),1);
            }

            if (busqueda_carta_color_y_numero(sucesor1,mano[0].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(sucesor2,mano[0].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(sucesor3,mano[0].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if (busqueda_carta_color_y_numero(sucesor1,mano[0].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(antecesor1,mano[0].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(sucesor2,mano[0].pinta,mazo),1,0,0,tamano_mazo(mazo),1)+multihipgeo(busqueda_carta_color_y_numero(antecesor2,mano[0].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
                }
            if (busqueda_carta_color_y_numero(antecesor1,mano[0].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(antecesor2,mano[0].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(antecesor3,mano[0].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
            }

            pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mano[1].valor,mazo),1,busqueda_carta_sin_pinta(mano[0].valor,mazo),0,tamano_mazo(mazo),1);

            if (busqueda_carta_sin_pinta(mano[0].valor,mesajuego.cartasJugada)==1) /*Significa que hay un trio*/{
                pos_poker=pos_poker+multihipgeo(busqueda_carta_sin_pinta(mano[0].valor,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            int j;
        for (j=0;j<5;j++){
            float pos_doble2=0;
            if (busqueda_carta_con_pinta(mesajuego.cartasJugada[j].pinta,mesajuego.cartasJugada)==3){
                pos_color=pos_color+multihipgeo(busqueda_carta_con_pinta(mesajuego.cartasJugada[j].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
                }

            pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);

            pos_doble2=pos_doble2+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
            if (j==4){
                pos_doble2=pos_doble2/j;
                pos_doble=pos_doble+pos_doble2;
            }

        if (busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mesajuego.cartasJugada)==2){ /*Significa que hay un doble entre las cartas de la mesa*/
            pos_poker=pos_poker+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
        }

        if (busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mesajuego.cartasJugada)==2){ /*Se pone 2 debido a que se comparará la carta consigo misma, asi que por lo menos encontrará una (ella misma...)*/
            pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
    }
        }
    }
    /*--------------------------------------*/

    if (indicador==7||indicador==9){
        int i,j,guarda_par1=0,guarda_par2=0,guarda_par3=0,guarda_par4=0;
        int sucesor1=0,sucesor2=0,antecesor1=0,antecesor2=0;

        if (mano[0].valor>mano[1].valor){
            if (mano[0].valor==13){
                sucesor1=1;
                sucesor2=sucesor1+1;
                antecesor1=mano[1].valor-1;
                antecesor2=antecesor1-1;
                }
            else if (mano[0].valor==12){
                sucesor1=mano[0].valor+1;
                sucesor2=1;
                antecesor1=mano[1].valor-1;
                antecesor2=antecesor1-1;
            }

            else if (mano[1].valor==1){
                antecesor1=13;
                antecesor2=antecesor1-1;
                sucesor1=mano[0].valor+1;
                sucesor2=sucesor1+1;
            }
            else if(mano[1].valor==2){
                antecesor1=mano[1].valor-1;
                antecesor2=13;
                sucesor1=mano[0].valor+1;
                sucesor2=sucesor1+1;
            }
        }
        else if (mano[1].valor>mano[0].valor){
            if (mano[1].valor==13){
                sucesor1=1;
                sucesor2=sucesor1+1;
                antecesor1=mano[0].valor-1;
                antecesor2=antecesor1-1;
                }
            else if (mano[1].valor==12){
                sucesor1=mano[1].valor+1;
                sucesor2=1;
                antecesor1=mano[0].valor-1;
                antecesor2=antecesor1-1;
            }

            else if (mano[0].valor==1){
                antecesor1=13;
                antecesor2=antecesor1-1;
                sucesor1=mano[1].valor+1;
                sucesor2=sucesor1+1;
            }
            else if(mano[0].valor==2){
                antecesor1=mano[0].valor-1;
                antecesor2=13;
                sucesor1=mano[1].valor+1;
                sucesor2=sucesor1+1;
            }
        }
            if (busqueda_carta_sin_pinta(sucesor1,mesajuego.cartasJugada)==1&&busqueda_carta_sin_pinta(sucesor1,mesajuego.cartasJugada)==1){
                pos_escala=pos_escala+multihipgeo(busqueda_carta_sin_pinta(sucesor2,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if (busqueda_carta_color_y_numero(sucesor1,mano[0].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(sucesor1,mano[0].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(sucesor2,mano[0].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if (busqueda_carta_color_y_numero(sucesor1,mano[1].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(sucesor1,mano[1].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(sucesor2,mano[1].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if (busqueda_carta_sin_pinta(sucesor1,mesajuego.cartasJugada)==1&&busqueda_carta_sin_pinta(antecesor1,mesajuego.cartasJugada)==1){
                pos_escala=pos_escala+multihipgeo(busqueda_carta_sin_pinta(sucesor2,mazo),1,0,0,tamano_mazo(mazo),1)+multihipgeo(busqueda_carta_sin_pinta(antecesor2,mazo),1,0,0,tamano_mazo(mazo),1);
                }
            if (busqueda_carta_color_y_numero(sucesor1,mano[0].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(antecesor1,mano[0].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(sucesor2,mano[0].pinta,mazo),1,0,0,tamano_mazo(mazo),1)+multihipgeo(busqueda_carta_color_y_numero(antecesor2,mano[0].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
                }
            if (busqueda_carta_color_y_numero(sucesor1,mano[1].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(antecesor1,mano[1].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(sucesor2,mano[1].pinta,mazo),1,0,0,tamano_mazo(mazo),1)+multihipgeo(busqueda_carta_color_y_numero(antecesor2,mano[1].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
                }
            if (busqueda_carta_sin_pinta(antecesor1,mesajuego.cartasJugada)==1&&busqueda_carta_sin_pinta(antecesor1,mesajuego.cartasJugada)==1){
                pos_escala=pos_escala+multihipgeo(busqueda_carta_sin_pinta(antecesor2,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if (busqueda_carta_color_y_numero(antecesor1,mano[0].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(antecesor1,mano[0].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(antecesor2,mano[0].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if (busqueda_carta_color_y_numero(antecesor1,mano[1].pinta,mesajuego.cartasJugada)==1&&busqueda_carta_color_y_numero(antecesor1,mano[1].pinta,mesajuego.cartasJugada)==1){
                pos_escala_color=pos_escala_color+multihipgeo(busqueda_carta_color_y_numero(antecesor2,mano[1].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
            }

        for (i=0;i<2;i++){
            if (indicador==7){
            if (busqueda_carta_con_pinta(mano[i].pinta,mesajuego.cartasJugada)==2){
                pos_color=pos_color+multihipgeo(busqueda_carta_con_pinta(mano[i].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            }
            else if (indicador==9){
            if (busqueda_carta_con_pinta(mano[i].pinta,mesajuego.cartasJugada)==1){
                pos_color=pos_color+multihipgeo(busqueda_carta_con_pinta(mano[i].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
            }

            }

            if (i==0){
                    pos_doble=multihipgeo(busqueda_carta_sin_pinta(mano[0].valor,mazo),1,0,0,tamano_mazo(mazo),1);

                }
                else if (i==1){
                    pos_doble=multihipgeo(busqueda_carta_sin_pinta(mano[1].valor,mazo),1,0,0,tamano_mazo(mazo),1);
                }

            if (busqueda_carta_sin_pinta(mano[i].valor,mesajuego.cartasJugada)==1) /*significa que tiene al menos una repeticion en la mesa*/ {
                if (guarda_par1==0){
                    guarda_par1=mano[i].valor;
                }
                else if (guarda_par1!=0&&guarda_par2==0){
                    guarda_par2=mano[i].valor;
                }

            if (busqueda_carta_sin_pinta(mano[i].pinta,mesajuego.cartasJugada)==2){
                if (i==0){
                    pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mano[0].valor,mazo),1,busqueda_carta_sin_pinta(mano[1].valor,mazo),0,tamano_mazo(mazo),1);
            }
                if (i!=0){
                    pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mano[1].valor,mazo),1,busqueda_carta_sin_pinta(mano[0].valor,mazo),0,tamano_mazo(mazo),1);
                    pos_trio=pos_trio/2;
                }
                }

            }
            if (busqueda_carta_sin_pinta(mano[i].valor,mesajuego.cartasJugada)==2) /*Significa que hay un trio*/{
                pos_poker=pos_poker+multihipgeo(busqueda_carta_sin_pinta(mano[i].valor,mazo),1,0,0,tamano_mazo(mazo),1);
            }
        }
        for (j=0;j<5;j++){
            float pos_doble2=0;
            if (indicador==7){
            if (busqueda_carta_con_pinta(mesajuego.cartasJugada[j].pinta,mesajuego.cartasJugada)==3){
                pos_color=pos_color+multihipgeo(busqueda_carta_con_pinta(mesajuego.cartasJugada[j].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
                }
            }
            if (indicador==9){
            if (busqueda_carta_con_pinta(mesajuego.cartasJugada[j].pinta,mesajuego.cartasJugada)==2){
                pos_color=pos_color+multihipgeo(busqueda_carta_con_pinta(mesajuego.cartasJugada[j].pinta,mazo),1,0,0,tamano_mazo(mazo),1);
                }
            }

            pos_doble2=pos_doble2+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
            if (j==4){
                pos_doble2=pos_doble2/j;
                pos_doble=pos_doble+pos_doble2;
            }

        if (busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mesajuego.cartasJugada)==3){ /*Significa que hay un trio entre las cartas de la mesa*/
            pos_poker=pos_poker+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
        }

        if (busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mesajuego.cartasJugada)==2){ /*Se pone 2 debido a que se comparará la carta consigo misma, asi que por lo menos encontrará una (ella misma...)*/
            pos_trio=pos_trio+multihipgeo(busqueda_carta_sin_pinta(mesajuego.cartasJugada[j].valor,mazo),1,0,0,tamano_mazo(mazo),1);
                if (guarda_par1==0){
                    guarda_par1=mesajuego.cartasJugada[j].valor;
                }
                else if (guarda_par1!=0&&guarda_par2==0){
                    guarda_par2=mesajuego.cartasJugada[j].valor;
                }
                else if (guarda_par2!=0&&guarda_par3==0){
                    guarda_par2=mesajuego.cartasJugada[j].valor;
                    }
                else if (guarda_par3!=0&&guarda_par4==0){
                    guarda_par2=mesajuego.cartasJugada[j].valor;
                }
        }
        }
        if (guarda_par1!=0){
            if (guarda_par1!=5){
                pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(5,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            else{
                pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(4,mazo),1,0,0,tamano_mazo(mazo),1);
            }

            if (guarda_par2!=0&&guarda_par1!=guarda_par2){
                pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par2,mazo),1,0,0,tamano_mazo(mazo),1);
        }
        }
        if (guarda_par3!=0){
            if (guarda_par3!=5){
                pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(5,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            else{
                pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(4,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if(guarda_par1!=0&&guarda_par1!=guarda_par3){
                pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par3,mazo),1,0,0,tamano_mazo(mazo),1);
        }
        }
        if(guarda_par4!=0){
            if (guarda_par4!=5){
                pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(5,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            else{
                pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(4,mazo),1,0,0,tamano_mazo(mazo),1);
            }

        if(guarda_par1!=0&&guarda_par1!=guarda_par4){
            pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par4,mazo),1,0,0,tamano_mazo(mazo),1);
        }
        }
        if (guarda_par2!=0){
            if (guarda_par2!=5){
            pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(5,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            else{
            pos_doble_pareja=pos_doble_pareja+multihipgeo(busqueda_carta_sin_pinta(4,mazo),1,0,0,tamano_mazo(mazo),1);
            }
            if(guarda_par3!=0&&guarda_par2!=guarda_par3){
            pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par3,mazo),1,0,0,tamano_mazo(mazo),1);
        }
        }
        if (guarda_par2!=0&&guarda_par4!=0&&guarda_par2!=guarda_par4){
            pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par4,mazo),1,0,0,tamano_mazo(mazo),1);
        }
        if (guarda_par3!=0&&guarda_par4!=0&&guarda_par3!=guarda_par4){
            pos_full=pos_full+multihipgeo(busqueda_carta_sin_pinta(guarda_par3,mazo),1,0,0,tamano_mazo(mazo),1);
        }
    }
    pos_doble=pos_doble*100;
    pos_doble_pareja=pos_doble_pareja*100;
    pos_escala=pos_escala*100;
    pos_escala_color=pos_escala_color*100;
    pos_full=pos_full*100;
    pos_poker=pos_poker*100;
    pos_trio=pos_trio*100;
    Imprimir_datos(pos_doble,pos_trio,pos_doble_pareja,pos_escala,pos_color,pos_full,pos_poker,pos_escala_color);


}

/*------------------------------Modo de utilizacion de la funcion---------------------------------

->Las cabezeras de las funciones son asi<-

int comparador(CARTA carta[],int turno)

int prob(CARTA mazo[],CARTA mano[],MESA mesajuego,int indicador)

->Forma de utilizacion para que funcione<-

prob(mazo,mano,mesajuego,comparador(mano,numero_turno)) tendiendo en cuenta que el turno 1== flop de 3 cards, turno 2 o 3 flop de 1 card

Recordar que calcula la prob!, por tanto se debe multiplicar el valor resultante por 100 para que de porcentaje

falta la prob de la escala real<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-Falta porque este caso es extremadamente especifico y prefiero hacerlo al final*/

