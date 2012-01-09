#include "apuesta.h"
#include "display.h"

void apuestaG(Jugador *jugando, int apuesta){

	jugando->apuesta_actual += apuesta;
	jugando->dinero -= apuesta;

	if(jugando->apuesta_actual>mesaJuego.apuesta_maxima){
		mesaJuego.apuesta_maxima=jugando->apuesta_actual;
		set_apostoMas(jugando);
	}

	mesaJuego.pozoApuestas += apuesta;
}

void aLow(int mInicial){
	/** Sera el 5% del monto total inicial de cada jugador */
    _low = (mInicial*5)/100;
	_aOB = 1;
}

void aBig(int mInicial){
	/** Sera el 10% del monto total inicial de cada jugador */
    _big = (mInicial*10)/100;
	_aOB = 1;
}

void apostando(Jugador *jugando, int apuesta){
    if(jugando->dinero>=apuesta){
		apuestaG(jugando,apuesta);

		limpiar();
		printf("%s",titulo());
		printf("\n\n\n");

		printf("La apuesta ha sido realizada satisfactoriamente\n");
		printf("Presione una tecla para continuar");
		getch();

    }else{
		apuestaG(jugando,jugando->dinero);
		jugando->jugando=2;

        limpiar();
		printf("%s",titulo());
		printf("\n\n\n");

		printf("Ha apostado mas de lo que tiene, por lo que la apuesta se a limitado a apostar todo su dinero\n");
		printf("Presione una tecla para continuar");
		getch();
    }
}
