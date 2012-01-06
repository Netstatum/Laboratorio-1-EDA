#include <malloc.h>
#include "display.h"
#include "getch.h"
#include "modo_practica.h"
#include "jugador.h"
#include "mesa.h"
#include "carta.h"

int modo_practica(){
    limpiar();
    printf("%s",titulo());
    printf("\n\n\n");

    cantidad_jugadores();

    limpiar();
    printf("%s",titulo());
    printf("\n\n\n");

    info_de_juego();

    limpiar();
    printf("%s",titulo());
    printf("\n\n\n");

    comienzaMP();

    return 0;
}

void cantidad_jugadores(){
    int cJugadores;
    int mInicial;

    printf(" Cuantos jugadores participaran de este juego?\n");
    printf(" Considerese a usted dentro del numero\n\n");
    printf("\t Jugadores: "); scanf("%i",&cJugadores);

    printf("\n\n");

    printf(" Ingrese el dinero inicial que tendra cada uno de los participantes\n");
    printf(" Considerese el monto en terminos de millones\n\n");
    printf("\t Monto Inicial: "); scanf("%u",&mInicial);

    jugadoresMesa = crearJugadores(cJugadores,mInicial);
    set_principio(jugadoresMesa->siguiente);

    printf("\n\n Presione una tecla para continuar");

    getch();
}

void info_de_juego(){
    printf(" Este juego solo considera partidas de multiples jugadores mediante\n la misma pantalla, ");
    printf("es por ello que entre ustedes, jugadores, que\n deben ponerse deacuerdo en quien ");
    printf("ira primero y quien ira despues,\n para guiarse en los jugadores y no confudirse pueden ");
    printf("usar de guia\n el numero de ID del jugador que estan usando.");

    printf("\n\n");

    printf(" Que gane el mejor!!");

    printf("\n\n Presione una tecla para continuar");

    getch();
}

int comienzaMP(){
    int rondas;
    int opcion;
    Jugador *jugando;

    generadorDelMazo();

    repartirCartas(_principio);

    flop();
    turnORriver(3);
    turnORriver(4);

    jugando = _principio;

    printf("================================================================================\n");

    printf("Pozo Total de la Mesa: %d",mesaJuego.pozoApuestas);
    printf("\nPorcentaje del pozo que te corresponde: %d",calculoPP(jugando));


    printf("\nCartas en la Mesa: \n\n");


    display_principal(mesaJuego.cartasJugada,5,jugando->cartas);
    printf("\nDinero disponible: %d millones",jugando->dinero);
    printf("\nApuesta maxima realizada: %d",mesaJuego.apuesta_maxima);

    printf("\n\n================================================================================");

    printf("\nProbabilidades de juego:");

    printf("\n\n================================================================================");

    printf("\nQue desea hacer?\n\n");

    printf("[1]Igualar la apuesta maxima");
    printf("   [2]Aumentar la apuesta maxima");
    printf("   [3]All IN");
    printf("        [4]Check");
    printf("   [5]Retirarse");



    opcion=getch();

    return 0;
}

int calculoPP(Jugador *jugador){
    int porcentaje;

    if(jugador->dinero>0){
        porcentaje = 100;
    }

    return porcentaje;
}
