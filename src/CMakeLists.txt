cmake_minimum_required (VERSION 2.6)
project (strip_poker)

set(DIR "${CMAKE_CURRENT_BINARY_DIR}/src/")


add_executable(strip_poker ${DIR}strip_poker.c)

add_library(jugador ${DIR}jugador.c)
add_library(mazo ${DIR}mazo.c)


target_link_libraries(strip_poker jugador)
