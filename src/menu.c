#include "menu.h"
#include "getch.h"
#include "display.h"

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
        select[i] = 0;
    }

    /** Asigna el valor ascii y la posición inicial del señalador */
    select[starter] = _senalador;
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
    printf("\t\t\t\t%c MODO APOYO",select[0]);
    printf("\n\n\t\t\t\t%c MODO PRACTICA",select[1]);
    printf("\n\n\t\t\t\t%c CREDITOS",select[2]);
    printf("\n\n\t\t\t\t%c SALIR", select[3]);
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
"\t       _____ _        _         _____       _                     \n"
"\t      / ____| |      (_)       |  __ \\     | |                   \n"
"\t     | (___ | |_ _ __ _ _ __   | |__) |___ | | __ ___ _ __        \n"
"\t      \\__  \\| __| '__| | '_ \\  |  ___// _ \\| |/ // _ \\ '__|  \n"
"\t      ____) | |_| |  | | |_) | | |   | (_) |   <|  __/ |          \n"
"\t     |_____/ \\__|_|  |_| .__/  |_|    \\___/|_|\\_\\\\___|_|     \n"
"\t                       | |                                        \n"
"\t                       |_|                                        \n";
}


int menuInicio()
{
    opcion = getch();

    switch (opcion)
    {
        /** Caracter 72 = Flecha Arriba */
#ifdef _WIN32
        case 72:
#else
	case 65:
#endif
        {
            if(P!=0)
            {
                /** Mueve el Cursor a la opcion de arriba */
                select[P] = 0;
                P--;
                select[P] = _senalador;

                portada();

            }else{
                /** Si se esta en la Primera Opcion, al precionar Arriba el Cursor pasa a la última opcion*/
                select[P] = 0;
                P = _largoArray;
                select[P]= _senalador;

                /** Se vuelve a la Portada para mostrar la nueva pocicion del Cursor*/
                portada();
            }
            break;
        }

        /** Caracter 80 = Flecha Abajo */
#ifdef _WIN32
        case 80:
#else
	case 91:
#endif
        {
            if(P != _largoArray)
            {
                /** Mueve el Cursor a la opcion de abajo */
                select[P] = 0;
                P++;
                select[P] = _senalador;

                /** Se vuelve a la Portada para mostrar la nueva pocicion del Cursor */
                portada();
            }else{
                /** Si se esta en la Ultima Opcion, al precionar Abajo el Cursor pasa a la primera opcion */
                select[P] = 0;
                P = 0;
                select[P] = _senalador;

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
            break;
        }

        /** Modo Practica */
        case 1:
        {
            break;
        }

        /** Creditos */
        case 2:     //CREDITOS
        {
            limpiar();
            printf("\n\n\t\t\t\tCREDITOS\n");

            printf("\n\n\tCreado por:");
            printf("\n\t\tFelipe Garay");
            printf("\n\t\tEsteban Gaete Flores");
            printf("\n\t\tMarcial");
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
            break;
        }

        /** Salir */
        default:
        {
            return 0;
        }
    }
}
