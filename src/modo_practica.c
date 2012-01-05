#include <malloc.h>
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
    generadorDelMazo();

    repartirCartas(_principio);

    printf("%d,%c,%d,%c,%d,%c",
           _principio->cartas[0].valor,_principio->cartas[0].pinta,
           _principio->siguiente->cartas[0].valor,_principio->siguiente->cartas[0].pinta,
           _principio->siguiente->siguiente->cartas[0].valor,_principio->siguiente->siguiente->cartas[0].pinta);

    getch();

    return 0;
}
