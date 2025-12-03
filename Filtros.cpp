#include "Filtros.h"

std::vector<Pokemon> filtrarPorTipo(const std::vector<Pokemon>& lista, int tipo) {
    std::vector<Pokemon> resultado;
    for (const auto& p : lista) {
        if (p.tipo1_num == tipo || p.tipo2_num == tipo) {
            resultado.push_back(p);
        }
    }
    return resultado;
}

std::vector<Pokemon> filtrarPorGeneracion(const std::vector<Pokemon>& lista, int generacion) {
    std::vector<Pokemon> resultado;
    for (const auto& p : lista) {
        if (p.generacion == generacion) {
            resultado.push_back(p);
        }
    }
    return resultado;
}
