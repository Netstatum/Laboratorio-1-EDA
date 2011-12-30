#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

/** Constantes:
	    _cartas: cantidad de cartas del mazo
		_maxJugadores: cantidad maxima de jugadores
		_maxVueltas: cantidad maximas de vueltas al jugar
		_cartasMano: cantidad de cartas en la mano
*/
#define _cartas 52
#define _maxJugadores 4
#define _maxVueltas 4
#define _cartasMano 2

/** Estructura tipo carta del mazo
	@var int valor : el valor de la carta, esto ira de 1 a 13
	     char pinta: se le asignara el ascii asociado a la pinta
*/
struct carta{
	int valor;
	char pinta;
};
typedef struct carta CARTA;

/** Estructura tipo jugador
	@var Carta cartas[_cartasMano]: cantidad de cartas que tiene en la mano
	     int dinero: dinero total para apostar
		 int apuestaActual: cantidad de la ultima apuesta realizada
		 struct jugador * next: apunta al siguiente jugador
*/
typedef struct Jugador{

int monto_actual,id, apuesta_actual;  /*Asignar 0 a monto actual para su uso posterior en la funcion Apuesta*/
char jugando; /*Esto ve si pasó ('P') o apostó ('A')*/

CARTA cartas[1];

struct Jugador *siguiente;
} Jugador;

/*===========================Aqui empieza la funcion===========================*/

Jugador *Apuesta(Jugador *primero,int Apuesta_Max){
Jugador *auxiliar=primero;
int i;
 /*que sea solo para un jugador*/
    if(auxiliar->jugando=='P'){
        return auxiliar; /*Como pasó no se hace nada*/
    }
    if(auxiliar->jugando=='A'){
        if(auxiliar->apuesta_actual==Apuesta_Max){ /*aqui no tendria que pasar a siguiente, sino que se acaba, condicion de termino*/
            return auxiliar;
            }
    if(auxiliar->apuesta_actual<Apuesta_Max){
        int decision=0;
        while (decision!=1 || decision!=2 || decision!=3){
            printf("¿Quiere igualar (1) o Aumentar (2) o Pasar (3)?\n");scanf("%d",decision);
        }
        if (decision==3){
            auxiliar->jugando='P';
            return auxiliar;
            }
        if (decision==1){
            auxiliar->monto_actual=auxiliar->monto_actual-(Apuesta_Max-auxiliar->apuesta_actual);
            auxiliar->apuesta_actual=auxiliar->apuesta_actual+(Apuesta_Max-auxiliar->apuesta_actual);
            auxiliar->jugando='A';
            return auxiliar;
            }
        if (decision==2){
            int aumento_apuesta;
            printf("¿Cuanto quiere aumentar?\n");scanf("%d",aumento_apuesta); /*Notar que falta poner restriccion para que sea tipo numero*/
            auxiliar->monto_actual=auxiliar->monto_actual-aumento_apuesta;
            auxiliar->apuesta_actual=auxiliar->apuesta_actual+aumento_apuesta;
            Apuesta_Max=auxiliar->apuesta_actual; /*nito que la variable Apuesta_Max tambien cambie afuera de la funcion, y no solo dentro de ella, seria algo como retornar el jugador y ademas la apuesta_max*/
            return auxiliar;
            }
            }
    }
    if((auxiliar->jugando=!'A')&& (auxiliar->jugando=!'P')){
        if (Apuesta_Max==0){
        int decision=0;
        while (decision!=1){
            printf("¿Pasar (1) o Apostar (2)?\n");scanf("%d",decision);
        }
        if (decision==1){
        auxiliar->jugando='P';
        return auxiliar;
        }
        else{
        int costo;
        printf("¿Cuanto quiere Apostar?\n");scanf("%d",costo); /*Notar que aqui tambien falta restriccion para que sea tipo numero*/
        while (costo>auxiliar->monto_actual){
            printf("Disculpe, pero su apuesta supera su monto actual, por favor vuelva a ingresarla\n",costo);scanf("%d",costo);/*Aqui tambien falta poner restriccion para que sea tipo numero*/
        }
        auxiliar->monto_actual=auxiliar->monto_actual-costo;
        auxiliar->apuesta_actual=costo;
        auxiliar->apuesta_actual=Apuesta_Max;
        auxiliar->jugando='A';
        return auxiliar; /*nito que la variable Apuesta_Max tambien cambie afuera de la funcion, y no solo dentro de ella, seria algo como retornar el jugador y ademas la apuesta_max*/
        }
        }
        else{
            int decision=0;
            while (decision!=1 || decision!=2){
                printf("¿Quiere igualar (1) o Aumentar (2) o Pasar (3)?\n");scanf("%d",decision);
                }
            if (decision==3){
                auxiliar->jugando='P';
                return auxiliar;
        }
        if (decision==1){
            auxiliar->monto_actual=auxiliar->monto_actual-(Apuesta_Max-auxiliar->apuesta_actual);
            auxiliar->apuesta_actual=auxiliar->apuesta_actual+(Apuesta_Max-auxiliar->apuesta_actual);
            auxiliar->jugando='A';
            return auxiliar;
            }
        if (decision==2){
            int aumento_apuesta;
            printf("¿Cuanto quiere aumentar?\n");scanf("%d",aumento_apuesta); /*Notar que falta poner restriccion para que sea tipo numero*/
            auxiliar->monto_actual=auxiliar->monto_actual-aumento_apuesta;
            auxiliar->apuesta_actual=auxiliar->apuesta_actual+aumento_apuesta;
            Apuesta_Max=auxiliar->apuesta_actual;
            auxiliar->jugando='A';
            return auxiliar; /*nito que la variable Apuesta_Max tambien cambie afuera de la funcion, y no solo dentro de ella, seria algo como retornar el jugador y ademas la apuesta_max*/
            }
        }
        }
        }

int main(){
	printf ("Hola Mundo"); /*(para comprobar que compila no mas xd)*/
}
