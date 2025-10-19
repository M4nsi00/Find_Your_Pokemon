#include "Historial.h"
#include <iostream>

void Historial::reigstrarFiltro(const std::vector<Pokemon>& lista){
    historial.push_back(lista);
}

bool Historial::deshacerUltimoCambio(std::vector<Pokemon>& lista){
    if(historial.empty()){
        cout << "No hay estados por deshacer\n";
        return false;
    } else {
        lista = historial.back();
        historial.pop_back();
        return true;
    }
}
