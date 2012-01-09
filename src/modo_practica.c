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
    int opcion,aumento;
    Jugador *jugando;

    /** Asignando las variables generales para el juego */
    generadorDelMazo();
	aLow(_principio->dinero);
    aBig(_principio->dinero);
	_finRonda=0;


    /** Mensaje de principio de juego */
    printf("%s",titulo());
    printf("\n\n\n");
    printf("\tEl juego comienza con el jugador ID: %i",_principio->id);
    printf("\n\tPresione una tecla para continuar");
    getch();

    /** Comienza el juego */
    do{
        /** Asignando las variables generales para la partida */
		inicializarJugadores();
        repartirCartas(_principio);
        inicializarMesaJuego();
		jugando = _principio;

        /** Comienza la partida */
        while(rondas<=4 && siguiente_jugador(jugando)!=jugando){
            /** Comienza el turno */
            do{
                display_principal(jugando, mesaJuego.cartasJugada,rondas+1,jugando->cartas);

                printf("\nQue desea hacer?%i\n\n",rondas);

				/** Apuesta el low si corresponde */
                if(rondas==1 && _aOB && jugando == _principio){
                    printf("[1]Apostar el Low de: %i",_low);

                        opcion=getch();

                        /** 49 es el ascii de la tecla 1 */
                        if(opcion==49){
                            apostando(jugando,_low);
                            jugando = siguiente_jugador(jugando);
                        }
                }else{
					/** Apuesta el big si corresponde */
                    if(rondas==1 && _aOB && jugando == _principio->siguiente){
                        printf("[1]Apostar el Big de: %i",_big);

                        opcion=getch();

                        /** 49 es el ascii de la tecla 1 */
                        if(opcion==49){
							_aOB = 0;
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
						/** Igualar la apuesta maxima
							Solo se realiza si la ultima apuesta hecha es diferente de la apuesta maxima
						*/
                        if(opcion==49){
							if(jugando->apuesta_actual!=mesaJuego.apuesta_maxima){
								apostando(jugando,mesaJuego.apuesta_maxima);
								jugando = siguiente_jugador(jugando);
							}else{
								limpiar();
								printf("%s",titulo());
								printf("\n\n\n");

								printf("Su apuesta ya es igual a la apuesta maxima");
								printf("\nPresiona una tecla para continuar");
								getch();

							}
						}

                        /** 50 es el ascii de la tecla 2 */
						/** Aumentar la apuesta maxima */
                        if(opcion==50){
							limpiar();
							printf("%s",titulo());
							printf("\n\n\n");

							printf("Para cancelar esta accion ingrese un monto de 0\n\n");
							printf("La apuesta maxima es de: %u",mesaJuego.apuesta_maxima);
							printf("\nIngrese en cuanto desea aumentarla: %u+",mesaJuego.apuesta_maxima);
							scanf("%u",&aumento);

							if(aumento!=0){
							    apostando(jugando,mesaJuego.apuesta_maxima+aumento);
                                jugando = siguiente_jugador(jugando);
							}
						}

                        /** 51 es el ascii de la tecla 3 */
						/** ALL IN */
                        if(opcion==51){
							jugando->jugando=2;
                            apostando(jugando,jugando->dinero);
							jugando = siguiente_jugador(jugando);
						}

                        /** 52 es el ascii de la tecla 4 */
						/** Check
							Solo puede hacerlo si su ultima apuesta es igual a la apuesta maxima
							Si el jugador haciendo check es el jugador _apostadorMaximo, se acaba la ronda
						*/
                        if(opcion==52){
                            if(mesaJuego.apuesta_maxima==jugando->apuesta_actual){
								if(jugando==_apostadorMaximo){
									_finRonda=1;
								}else{
									jugando = siguiente_jugador(jugando);
								}

								jugando->jugando = 1;

							}else{
								limpiar();
								printf("%s",titulo());
								printf("\n\n\n");

								printf("No puedes hacer Check en este momento");
								printf("\nPresione una tecla para continuar");
								getch();
							}
						}

                        /** 53 es el ascii de la tecla 5 */
						/** Retirarse */
                        if(opcion==53){
							jugando->jugando=3;
							jugando = siguiente_jugador(jugando);
						}

                    }
                }

				/** Si no se han retirado todos, ni es el fin de ronda ni todos han hecho Check */
				if(siguiente_jugador(jugando)!=jugando && !_finRonda && !allCheck(jugando)){
                    limpiar();
                    printf("%s",titulo());
                    printf("\n\n\n");

                    printf("\tEs el turno del jugador ID: %i",jugando->id);
                    printf("\n\tPresione una tecla para continuar");
                    getch();
				}
			/** Si no se han retirado todos, ni es el fin de ronda ni todos han hecho Check
				Se pasa al siguiente jugador
			*/
            }while(siguiente_jugador(jugando)!=jugando && !_finRonda && !allCheck(jugando));
            /** Acaba una ronda */

			/** Si no se han retirado todos */
            if(siguiente_jugador(jugando)!=jugando){
                rondas++; //avanza una ronda
				jugando = _principio; //la siguiente ronda parte con el _principio
				_finRonda=0; //ya no es fin de ronda
				_apostadorMaximo=NULL; //no hay apostadorMaximo actualmente
				allUnCheck(); //todos los jugadores que hicieron check pueden volver a jugar

				/** Reparte el flop */
                if(rondas==2){
                    limpiar();
                    printf("%s",titulo());
                    printf("\n\n\n");

                    printf("\nApuesta pre-flop terminada...\nComienza el flop, presione una tecla para continuar");
                    flop();
                    getch();
                }

				/** Reparte el turn o river */
                if(rondas==3 || rondas==4){
                    limpiar();
                    printf("%s",titulo());
                    printf("\n\n\n");

                    if(rondas==3){
                        printf("\nComienza el Turn, presione una tecla para continuar");
                    }else{
                        printf("\nComienza el River, presione una tecla para continuar");
                    }

                    turnORriver(rondas);
                    getch();
                }
            }

			/** Si no se han retirado todos
				Se avanza a la siguiente ronda
			*/

        }
        /** Acaba la partida */

		/** Si no se han retirado todos se debe verificar quien gana */
		if(siguiente_jugador(jugando)!=jugando){
			//Se verifica quien tiene el mejor juego
		}

        /** Todos los jugadores con jugador->dinero=0 se eliminan */
		chaoPerdedores();

		/** Si aun quedan jugadores contra los que luchar */
		if(jugando->siguiente!=jugando){
			_principio = _principio->siguiente; //El primer jugador sera el siguiente
			mazoNuevo(); //Se llena el mazo para repartir correctamente
		}

	/** Si aun quedan jugadores contra los que luchar
		se vuelve a jugar otra partida
	*/
    }while(jugando->siguiente!=jugando);
    /** Acaba el juego, hay un ganador */

	//felicitar al ganador y se acabo fin game over
	printf("gano el %u",_principio->id);
	getch();

    return 0;
}

int calculoPP(Jugador *jugador){
    int porcentaje;

    if(jugador->dinero>=0){
        porcentaje = 100;
    }

    return porcentaje;
}

int allCheck(Jugador *jugador){
	Jugador *aux =jugador;

	do{
		if(aux->jugando>=1){
			aux=aux->siguiente;
		}else{
			return 0;
		}
	}while(aux!=jugador);

	return 1;
}

void allUnCheck(){
    Jugador *aux = _principio;

    do{
		if(aux->jugando<=2){
			aux->jugando=0;
		}

        aux=aux->siguiente;
    }while(aux!=_principio);

    _principio = aux;
}

void chaoPerdedores(){
	Jugador *aux = _principio;
	Jugador *aux2 = _principio->siguiente;

    do{
		if(aux->dinero==0){
			borrar_nodo(aux);
		}

        aux=aux2;
		aux2=aux2->siguiente;
    }while(aux!=_principio);

    _principio = aux;
}

void inicializarMesaJuego(){
	int contador=0;

	while(contador<5){
		mesaJuego.cartasJugada[contador].valor = 0;
		mesaJuego.cartasJugada[contador].pinta = 0;
		mesaJuego.cartasJugada[contador].jugada = 0;
		contador++;
	}

	mesaJuego.pozoApuestas = 0;
	mesaJuego.apuesta_maxima = 0;
}

void inicializarJugadores(){
	Jugador *aux = _principio;

    do{
		if(aux->dinero!=0){
			aux->apuesta_actual=0;
			aux->jugando = 0;
		}

		aux=aux->siguiente;
    }while(aux!=_principio);

    _principio = aux;
}
