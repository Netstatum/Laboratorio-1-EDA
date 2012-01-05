#include <malloc.h>
#include "display.h"
#include "getch.h"
#include "modo_practica.h"
#include "jugador.h"

int modo_practica(){
    limpiar();
    printf("%s",titulo());
    printf("\n\n\n");

    cantidad_jugadores();

    limpiar();
    printf("%s",titulo());
    printf("\n\n\n");

    info_de_juego();

    return 0;
}

void cantidad_jugadores(){
    int cJugadores;
    int mInicial;

    printf("Cuantos jugadores participaran de este juego?\n");
    printf("Considerese a usted dentro del numero\n\n");
    printf("\tJugadores: "); scanf("%i",&cJugadores);

    printf("\n\n");

    printf("Ingrese el dinero inicial que tendra cada uno de los participantes\n");
    printf("Considerese el monto en terminos de millones\n\n");
    printf("\tMonto Inicial: "); scanf("%u",&mInicial);

    jugadoresMesa = crearJugadores(cJugadores,mInicial);
    set_principio(jugadoresMesa->siguiente);

    printf("\n\nPresione una tecla para continuar");

    getch();
}

void info_de_juego(){
    printf("Este juego solo considera partidas de multiples jugadores mediante la misma pantalla,\n");
    printf("es por ello que es entre ustedes, jugadores, que deben ponerse deacuerdo en quien\n");
    printf("ira primero y quien ira despues, para guiarse en los jugadores y no confudirse pueden\n");
    printf("usar de guia el numero de ID del jugador que estan usando.");

    printf("\n\n");

    printf("Que gane el mejor!!");

    printf("\n\nPresione una tecla para continuar");

    getch();

}
