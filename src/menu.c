#include <stdio.h>
#include "menu.h"
#include "getch.h"
#include "display.h"
#include "modo_practica.h"

int menuPrincipal(int starter)
{
    /** Caracter 36($) usado como señalador de posición */
    iniciarSelect(starter);

    portada();
}


void iniciarSelect(int starter)
{
    int i;

    for(i=0;i<_largoArray;i++)
    {
        select_menu[i] = 0;
    }

    /** Asigna el valor ascii y la posición inicial del señalador */
    select_menu[starter] = _senalador;
    P = starter;
}

int portada()
{
    limpiar();

    banner();
    menuInicio();
}

void banner()
{
    printf("%s",titulo());

    printf("\n\n\n");

    /** En los siguientes Printf se dibuja el cursor de posicion */
    printf("\t\t\t\t%c MODO APOYO",select_menu[0]);
    printf("\n\n\t\t\t\t%c MODO PRACTICA",select_menu[1]);
    printf("\n\n\t\t\t\t%c CREDITOS",select_menu[2]);
    printf("\n\n\t\t\t\t%c SALIR", select_menu[3]);
}

const char *mensajeBienvenida()
{
    return ""
    "\t\t\t        _..-''--'----_.            \n"
    "\t\t\t      ,''.-''| .---/ _`-._         \n"
    "\t\t\t    ,' \\ \\  ;| | ,/ / `-._`-.    \n"
    "\t\t\t  ,' ,',\\ \\( | |// /,-._  / /    \n"
    "\t\t\t  ;.`. `,\\ \\`| |/ / |   )/ /     \n"
    "\t\t\t / /`_`.\\_\\ \\| /_.-.'-''/ /     \n"
    "\t\t\t/ /_|_:.`. \\ |;'`..')  / /        \n"
    "\t\t\t`-._`-._`.`.;`.\\  ,'  / /         \n"
    "\t\t\t    `-._`.`/    ,'-._/ /           \n"
    "\t\t\t      : `-/     \\`-.._/           \n"
    "\t\t\t      |  :      ;._ (              \n"
    "\t\t\t      :  |      \\  ` \\           \n"
    "\t\t\t       \\         \\   |           \n"
    "\t\t\t        :        :   ;             \n"
    "\t\t\t        |           /              \n"
    "\t\t\t        ;         ,'               \n"
    "\t\t\t       /         /                 \n"
    "\t\t\t      /         /                  \n"
    "\t\t\t               /                   \n"
    "     _______  __          __            _______         __                 \n"
    "    |   _   ||  |_ .----.|__|.-----.   |   _   |.-----.|  |--..-----..----.\n"
    "    |   1___||   _||   _||  ||  _  |   |.  1   ||  _  ||    < |  -__||   _|\n"
    "    |____   ||____||__|  |__||   __|   |.  ____||_____||__|__||_____||__|  \n"
    "    |:  1   |                |__|      |:  |                               \n"
    "    |::.. . |                          |::.|                               \n"
    "    `-------'                          `---'                               \n";
}

const char *titulo()
{
    return "\n"
"\t  _____  _ _        __   _    _       _     _   _                  \n"
"\t |  __ \\(_|_)      / _| | |  | |     | |   | | ( )                 \n"
"\t | |  | |_ _ _ __ | |_  | |__| | ___ | | __| | |/  ___ _ __ ___    \n"
"\t | |  | | | | '_ \\|  _| |  __  |/ _ \\| |/ _` |    / _ \\ '_ ` _ \\   \n"
"\t | |__| | | | | | | |   | |  | | (_) | | (_| |   |  __/ | | | | |  \n"
"\t |_____/|_|_|_| |_|_|   |_|  |_|\\___/|_|\\__,_|    \\___|_| |_| |_|  \n"
                                                                 ;
}


int menuInicio()
{
    opcion = getch();

    switch (opcion)
    {
        /** Caracter 72 = Flecha Arriba */
    #ifdef __linux__
        case 65:
    #else
        case 72:
    #endif
        {
            if(P!=0)
            {
                /** Mueve el Cursor a la opcion de arriba */
                select_menu[P] = 0;
                P--;
                select_menu[P] = _senalador;

                portada();

            }else{
                /** Si se esta en la Primera Opcion, al precionar Arriba el Cursor pasa a la última opcion*/
                select_menu[P] = 0;
                P = _largoArray;
                select_menu[P]= _senalador;

                /** Se vuelve a la Portada para mostrar la nueva pocicion del Cursor*/
                portada();
            }
            break;
        }

        /** Caracter 80 = Flecha Abajo */
    #ifdef __linux__
        case 91:
    #else
        case 80:
    #endif
        {
            if(P != _largoArray)
            {
                /** Mueve el Cursor a la opcion de abajo */
                select_menu[P] = 0;
                P++;
                select_menu[P] = _senalador;

                /** Se vuelve a la Portada para mostrar la nueva pocicion del Cursor */
                portada();
            }else{
                /** Si se esta en la Ultima Opcion, al precionar Abajo el Cursor pasa a la primera opcion */
                select_menu[P] = 0;
                P = 0;
                select_menu[P] = _senalador;

                /** Se vuelve a la Portada para mostrar la nueva pocicion del Cursor*/
                portada();
            }
            break;
        }

        /** Caracter 13 = Enter */
        case 13:
        {
            /** Se ejecuta la opción dada por la posición P */
            opciones(P);
            break;
        }

        default:
        {
            /** La Portada() se dibuja nuevamente cada vez que
            se preciona un boton diferente a los casos anteriores */
            portada();
        }
    }
}

int opciones(int posicion)
{
    /** Dada la pocición P en el menu */
    switch(posicion)
    {
        /** Modo Apoyo */
        case 0:
        {
			modo_apoyo();
            break;
        }

        /** Modo Practica */
        case 1:
        {
            modo_practica();
            break;
        }

        /** Creditos */
        case 2:     //CREDITOS
        {
            creditos();
            break;
        }

        /** Salir */
        default:
        {
            return 0;
        }
    }
}

void creditos(){
    limpiar();
    printf("\n\n\t\t\t\tCREDITOS\n");

    printf("\n\n\tCreado por:");
    printf("\n\t\tFelipe Garay");
    printf("\n\t\tEsteban Gaete Flores");
    printf("\n\t\tMarcial Hernandez");
    printf("\n\tEstudiantes de Ingenier%ca Civil en Informatic%c, USACH",161,160);

    printf("\n\n\tEl Juego a sido creado como objetivo de un Laboratorio del ramo:");
    printf("\n\n\t\tEstructura de Datos y Algoritmos",162);
    printf("\n\t\tLenguaje usado: C");

    printf("\n\n\tVersion del Juego: ---");
    printf("\n\tUltima Edicion: -------\n");

    printf("\n\n\t\t\t\tAGRADECIMIENTOS\n");

    printf("\n\n\tGracias a ...");

    getch();
    portada();
}
