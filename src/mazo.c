#include <time.h>
#include <stdlib.h>
#include "carta.h"
#include "mesa.h"

void generadorDelMazo(){
	int contador = 0;
	int contadorValor = 0;
	int pinta = 3;

	while(contador<=51){

        /** Se asigna el valor de la carta de 1 a 13 */
		contadorValor++;
		mazo[contador].valor = contadorValor;
		if(contadorValor==13)
			contadorValor = 0;

        /** Se asgina la pinta corazon, diamante, trebol y pica, cambiando cada 13 cartas */
		mazo[contador].pinta = pinta;
		if((contador+1)%13==0)
			pinta++;

        /** Ningunca carta ha sido jugada */
        mazo[contador].jugada = 0;
		contador++;

	}
}

void mazoNuevo(){
    int contador = 0;

    /** Ningunca carta ha sido jugada */
	while(contador<=51){
	    mazo[contador].jugada=0;
	}
}

void flop(){
    int aletoriedad;
    int sacadas=0;

    srand(time(NULL));

    while(sacadas<3){
        aletoriedad = rand() % 52;

        /** Si la carta elegida no ha sido jugada aun:
            La carta es jugada en la mesa y se avanza a la siguiente carta,
            en caso contrario se vuelve a buscar otra carta aleatoria
        */
        if(mazo[aletoriedad].jugada == 0){

            mesaJuego.cartasJugada[sacadas] = mazo[aletoriedad];
            mazo[aletoriedad].jugada = 1;

            sacadas++;
        }
    }
}

void turnORriver(int ronda){
    int aletoriedad;
    int sacadas=0;

    srand(time(NULL));

    while(sacadas != 1){
        aletoriedad = rand() % 52;

        /** Si la carta elegida no ha sido jugada aun:
            La carta es jugada en la mesa y se avanza a la siguiente carta,
            en caso contrario se vuelve a buscar otra carta aleatoria
        */
        if(mazo[aletoriedad].jugada == 0){

            mesaJuego.cartasJugada[ronda+1] = mazo[aletoriedad];
            mazo[aletoriedad].jugada = 1;

            sacadas++;
        }
    }
}

void repartirCartas(Jugador *primero){
    int aletoriedad, contadorC=0;
    Jugador *aux = primero;

    srand(time(NULL));

    /** Se asignan las cartas al primero jugador */
    while(contadorC<2){

        /** Se asignan las cartas */
        aletoriedad = rand() % 52;
        if(mazo[aletoriedad].jugada == 0){
            aux->cartas[contadorC] = mazo[aletoriedad];
            mazo[aletoriedad].jugada = 2;
            contadorC++;
        }
    }
    contadorC=0;

    /** Se pasa al siguiente jugador */
    aux=aux->siguiente;

    /** Como es una lista circular al llegar al primero nuevamente debemos detenernos */
    while(aux!=primero){

        /** Se asignan las cartas */
        aletoriedad = rand() % 52;
        while(contadorC<2){
            if(mazo[aletoriedad].jugada == 0){
                aux->cartas[contadorC] = mazo[aletoriedad];
                mazo[aletoriedad].jugada = 2;
                contadorC++;
            }
        }

        aux=aux->siguiente;
    }

}
