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
char jugando;

CARTA cartas[1];

struct Jugador *siguiente;
} Jugador;

/** Mazo de 52 cartas */
CARTA mazo[_cartas];

void generadorDelMazo(){
	int contador = 0;
	int contadorValor = 0;
	int pinta = 3;

	while(contador<=51){

		contadorValor++;
		mazo[contador].valor = contadorValor;

		if(contadorValor==13)
			contadorValor = 0;

		mazo[contador].pinta = pinta;

		if((contador+1)%13==0)
			pinta++;

		printf("%d%c ",mazo[contador].valor,mazo[contador].pinta);
		contador++;

	}

	getch();
}

int Largo(Jugador *primero){
Jugador *auxiliar;
int i=0;
if(primero!=NULL){
auxiliar=primero;
i++;
auxiliar=auxiliar->siguiente;
while(auxiliar!=primero){
i++;
auxiliar=auxiliar->siguiente;}
}
}

/*La funcion sirve para dar la vuelta solo una vez, ademas falta retornar que se pondria esa linea de codigo en donde dejare marcado*/

Jugador *Apuesta(Jugador *primero){
Jugador *auxiliar=primero;
int i,Apuesta_Max;
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
            Apuesta_Max=auxiliar->apuesta_actual;
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
        }
        }
        else{
            int decision=0;
            while (decision!=1 || decision!=2){
                printf("¿Quiere igualar (1) o Aumentar (2) o Pasar (3)?\n%d",decision);
                }
            if (decision==3){
                auxiliar->jugando='P';
        }
        if (decision==1){
            auxiliar->monto_actual=auxiliar->monto_actual-(Apuesta_Max-auxiliar->apuesta_actual);
            auxiliar->apuesta_actual=auxiliar->apuesta_actual+(Apuesta_Max-auxiliar->apuesta_actual);
            auxiliar->jugando='A';
            }
        if (decision==2){
            int aumento_apuesta;
            printf("¿Cuanto quiere aumentar?\n%d",aumento_apuesta); /*Notar que falta poner restriccion para que sea tipo numero*/
            auxiliar->monto_actual=auxiliar->monto_actual-aumento_apuesta;
            auxiliar->apuesta_actual=auxiliar->apuesta_actual+aumento_apuesta;
            Apuesta_Max=auxiliar->apuesta_actual;
            auxiliar->jugando='A';
            }
        }



           }
           }

int main(){
	generadorDelMazo();

	return 0;
}
