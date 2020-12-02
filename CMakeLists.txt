cmake_minimum_required(VERSION 3.17)
project(HashExterior C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(HashExterior
        cliente.c
        cliente.h
        compartimento_hash.c
        compartimento_hash.h
        encadeamento_exterior.c
        encadeamento_exterior.h
        lista_clientes.c
        lista_clientes.h
        lista_compartimentos.c
        lista_compartimentos.h
        main.c)
