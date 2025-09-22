#ifndef FILTROS_H
#define FILTROS_H

#include <vector>
#include "Pokemon.h"

std::vector<Pokemon> filtrarPorTipo(const std::vector<Pokemon>& lista, int tipo);
std::vector<Pokemon> filtrarPorGeneracion(const std::vector<Pokemon>& lista, int generacion);

#endif
