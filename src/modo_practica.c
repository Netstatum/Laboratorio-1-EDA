#include "modo_practica.h"

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
    int rondas=1;
    int opcion,big,low;
    Jugador *jugando = _principio;

    /** Asignando las variables generales para el juego */
    generadorDelMazo();
    big = aBig(_principio->dinero);
    low = aLow(_principio->dinero);

    /** Mensaje de principio de juego */
    printf("%s",titulo());
    printf("\n\n\n");
    printf("\tEl juego comienza con el jugador ID: %i",jugando->id);
    printf("\n\tPresione una tecla para continuar");
    getch();

    /** Comienza el juego */
    while(jugando->siguiente!=jugando){
        /** Asignando las variables generales para la partida */
        repartirCartas(_principio);
        jugando = _principio;
        mesaJuego.pozoApuestas = 0;
        mesaJuego.apuesta_maxima = 0;

        /** Comienza la partida */
        while(rondas<=4){
            /** Comienza el turno */
            do{
                display_principal(jugando, mesaJuego.cartasJugada,rondas+1,jugando->cartas);

                printf("\nQue desea hacer?\n\n");

                if(rondas==1 && jugando == _principio){
                    printf("[1]Apostar el Low de: %i",low);

                        opcion=getch();

                        /** 49 es el ascii de la tecla 1 */
                        if(opcion==49){
                            apostando(jugando,_low);
                            jugando = siguiente_jugador(jugando);
                        }
                }else{
                    if(rondas==1 && jugando == _principio->siguiente){
                        printf("[1]Apostar el Big de: %i",big);

                        opcion=getch();

                        /** 49 es el ascii de la tecla 1 */
                        if(opcion==49){
                            apostando(jugando,_big);
                            jugando = siguiente_jugador(jugando);
                        }
                    }else{
                        printf("[1]Igualar la apuesta maxima");
                        printf("   [2]Aumentar la apuesta maxima");
                        printf("   [3]All IN");
                        printf("        [4]Check");
                        printf("   [5]Retirarse");

                        opcion=getch();

                        /** 49 es el ascii de la tecla 1 */
                        if(opcion==49){
							apostando(jugando,mesaJugando.apuesta_maxima);
						}
                            
                        /** 50 es el ascii de la tecla 2 */
                        if(opcion=50){}

                        /** 51 es el ascii de la tecla 3 */
                        if(opcion==51){}

                        /** 52 es el ascii de la tecla 4 */
                        if(opcion==52){}

                        /** 53 es el ascii de la tecla 5 */
                        if(opcion==53){}

                    }
                }

               // if(opcion>=49 && opcion<=53){
                    limpiar();

                    printf("%s",titulo());
                    printf("\n\n\n");

                    printf("\tEs el turno del jugador ID: %i",jugando->id);
                    printf("\n\tPresione una tecla para continuar");
                    getch();
                //}
            }while(jugando->apuesta_actual!=mesaJuego.apuesta_maxima);
            /** Acaba una ronda */

            //todos los jugadores con jugando->jugando = 1 deben ser seteados a 0
            //si los jugadores con jugando->jugando = 1 tienen jugando->dinero= 0 no se resetea su valor jugando a 0
            rondas++;

            if(rondas==2){
                limpiar();
                printf("\nApuesta pre-flop terminada, comienza el flop, presione una tecla para continuar");
                flop();
                getch();
            }

            if(rondas==3 || rondas==4){
                limpiar();
                if(rondas==3){
                    printf("\nComienza el Turn, presione una tecla para continuar");
                }else{
                    printf("\nComienza el River, presione una tecla para continuar");
                }

                turnORriver(rondas);
                getch();
            }

        }
        /** Acaba la partida */
        //todos los jugadores con dinero 0 se eliminan
    }
    /** Acaba el juego, hay un ganador */

    return 0;
}

int calculoPP(Jugador *jugador){
    int porcentaje;

    if(jugador->dinero>0){
        porcentaje = 100;
    }

    return porcentaje;
}
