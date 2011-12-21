cmake_minimum_required (VERSION 2.6)
project (strip_poker)



add_executable(strip_poker strip_poker.c)

add_library(jugador jugador.c)
add_library(mazo mazo.c)

add_definitions("-pipe -pedantic -ansi -Wall")

if(WIN32)
	#enlazamos con ncurses y cgywin en windows

else(WIN32)
	#enlazamos de forma normal en todo lo demas

endif(WIN32)


target_link_libraries(strip_poker jugador mazo)
