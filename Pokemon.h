#ifndef POKEMON_H
#define POKEMON_H

#include <string>

struct Pokemon {
    int numero;
    std::string nombre;
    int tipo1;
    int tipo2;
    int generacion;
    int ataque;
    int spAtaque;
};

#endif