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
struct jugador{
	CARTA cartas[_cartasMano];
	int dinero;
	int apuestaActual;
	struct jugador * next;
};
typedef struct jugador JUGADOR;

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

int main(){
	generadorDelMazo();

	return 0;
}
