#include "Historial.h"
#include <iostream>

void Historial::reigstrarFiltro(const std::vector<Pokemon>& estado){
    filtros.push(estado);
}

bool Historial::deshacerUltimoCambio(std::vector<Pokemon>& estado){
    if(filtros.empty()){
        cout << "No hay estados por deshacer\n";
        return false;
    } else {
        estado = filtros.top();
        filtros.pop();
        return true;
    }
}

bool Historial::historialEmpty() const{
    return filtros.empty();
}

std::vector<Pokemon> Historial::ultimoCambio() const{
    if(filtros.empty()) return{}; 
    else{
        return filtros.top();
    }
}

void Historial::guardarHistorial(const std::string& ruta){
    std::ofstream out(ruta);
    if (!out.is_open()) {
        std::cerr << "No se pudo guardar historial.\n";
        return;
    }

    std::stack<std::vector<Pokemon>> temp = filtros;

    out << temp.size() << "\n";

    while (!temp.empty()) {
        auto estado = temp.top();
        temp.pop();

        out << estado.size() << "\n";
        for (const auto& p : estado) {
            out << p.numero << "," << p.nombre << "," << p.tipo1 << ","
                << p.tipo2 << "," << p.generacion << "," << p.ataque << ","
                << p.spAtaque << "\n";
        }
    }
}

void Historial::cargarHistorial(const std::string& ruta){
    std::ifstream in(ruta);
    if (!in.is_open()) return;

    int numEstados;
    in >> numEstados;

    if (!in || numEstados <= 0) return;
    in.ignore();

    std::vector<std::vector<Pokemon>> estados; 
    estados.reserve(numEstados);

    for (int i = 0; i < numEstados; ++i) {
        int tam;
        in >> tam;

        if (!in || tam <= 0) {
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        in.ignore();

        std::vector<Pokemon> estado;
        estado.reserve(tam);

        for (int j = 0; j < tam; ++j) {
            Pokemon p;
            char coma;

            in >> p.numero >> coma;
            std::getline(in, p.nombre, ',');
            in >> p.tipo1 >> coma >> p.tipo2 >> coma
               >> p.generacion >> coma >> p.ataque >> coma >> p.spAtaque;

            if (!in) break;

            in.ignore();
            estado.push_back(p);
        }

        if (!estado.empty())
            estados.push_back(estado);
    }

    for (int i = estados.size() - 1; i >= 0; --i) {
        filtros.push(estados[i]);
    }
}

void Historial::limpiarHistorial(const std::vector<Pokemon>& estadoBase) {
    while (!filtros.empty()) {
        filtros.pop();
    }
    filtros.push(estadoBase);
    std::cout << "Historial eliminado correctamente.\n";
}
