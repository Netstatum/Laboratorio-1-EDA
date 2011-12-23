#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** Ascii usado para el se�alador del men� */
#define _senalador 36

/** Tama�o estandar del array, va de 0 a 3 */
#define _largoArray 3

/** Variables usadas para seleccionar las opciones en el menu de inicio */
int opcion;
int P;

/** Variable usada para mover el "cursor" de las opciones:
    Modo Apoyo, Modo Practica, Creditos y Salir
*/
char select[_largoArray+1];

/** Funci�n menuPrincipal, se preocupa de inicializar el array del se�alador
    y de mostrar la portada, solo es necesario usar una ves esta funcion al iniciar
    el uso de un menu con selector, una vez usado no es necesario usar las dem�s funciones
    ya que se realiza una reaccion en cadena.

    @param int starter: posici�n en la que comienza el cursor
    @return int: retorna un entero al main cuando finaliza el programa
 */
int menuPrincipal(int starter);

/** Funci�n iniciarSelect, inicializa el array en valores 0 y asigna el char
    dado por _senalador en la posicion [starter] dada.
    Es llamada de forma automatica por menuPrincipal, por lo que su uso directo no es
    necesario.

    @param int starter: posici�n en la que comienza el cursor
 */
void iniciarSelect(int starter);

/** Funci�n portada, limpia la pantalla y muestra el titulo junto con el menu inicial
    Es llamada inicialmente por menuPrincipal para iniciar el menu

    @return int: retorna un entero a menuPrincipal(quien lo retorna al main) cuando finaliza el programa
*/
int portada();

/** Funci�n banner, muestra el titulo y las opciones posibles para que el usuario elija */
void banner();

/** Funci�n titulo, consiste de un simple Pixelart del titulo
    @return char*: para ser usado dentro de un printf de la forma
                      printf("%s", titulo());
*/
const char *titulo();

/** Funci�n menuInicio, es el Algoritmo principal del Menu ya que es la encargada de "mover"
    el cursor por la pantalla usando el array para ello, tambien lleva cuenta de que posici�n esta
    siendo usada en ese momento para elegir correctamente la opcion cuando el usuario presione enter

    @return int: retorna un entero a portada (quien lo retorna a menuPrincipal(quien lo retorna al main))
                cuando finaliza el programa
*/
int menuInicio();

/** Funci�n opciones, dada la opcion elegida en el men� efectua la accion correspondiente

    @param int posicion: es la opcion seleccionada

    @return int: retorna un entero a menuInicio(quien lo retorna a portada (quien lo retorna a menuPrincipal
                 (quien lo retorna al main)) cuando finaliza el programa

 */
int opciones(int posicion);

/** Consiste de un simple Pixelart de presentaci�n
    @return char*: para ser usado dentro de un printf de la forma
                      printf("%s", titulo());
*/
const char *mensajeBienvenida();


#endif
