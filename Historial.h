#ifndef HISTORIAL_H
#define HISTORIAL_H

#include "Pokemon.h"
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Historial{
    private:
    std::vector<std::vector<Pokemon>> historial;
    stack <vector<Pokemon>> filtros;

    public:
    void reigstrarFiltro(const std::vector<Pokemon>& lista);
    bool deshacerUltimoCambio(std::vector<Pokemon>& lista);
    bool historialEmpty() const{
        return historial.empty();
    };
    int tamanio() const{
        return historial.size();
    }
};
#endif