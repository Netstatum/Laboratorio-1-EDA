#ifndef _H_MODO_APOYO_
#define _H_MODO_APOYO_
#include "carta.h"


void modo_apoyo();

int revisar_entrada(char pinta, char *valor);

int es_numero(char *caracter);

void limpiar_buffer();

void convertir_a_carta(CARTA *carta, char *pinta, char *valor);
void obtener(char *cadena);
#endif
