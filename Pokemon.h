#ifndef POKEMON_H
#define POKEMON_H

#include <string>

struct Pokemon {
    int numero;
    std::string nombre;
    std::string tipo1_str;
    std::string tipo2_str;
    int tipo1_num;
    int tipo2_num;
    int generacion;
    int ataque;
    int spAtaque;
};

#endif