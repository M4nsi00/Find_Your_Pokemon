#ifndef HISTORIAL_H
#define HISTORIAL_H

#include "Pokemon.h"
#include <stack>
#include <vector>
#include <fstream>
#include <limits>
#include <iostream>
using namespace std;

class Historial{
    private:
    stack <vector<Pokemon>> filtros;

    public:
    void reigstrarFiltro(const std::vector<Pokemon>& estado);
    bool deshacerUltimoCambio(std::vector<Pokemon>& estado);
    bool historialEmpty() const;
    std::vector<Pokemon> ultimoCambio() const;    
    int tamanio() const{
        return filtros.size();
    }

    //Guardar el historial de filtros en un archivo

    void guardarHistorial(const std::string& ruta);
    void cargarHistorial(const std::string& ruta);
    void limpiarHistorial(const std::vector<Pokemon>& estadoBase);
};
#endif