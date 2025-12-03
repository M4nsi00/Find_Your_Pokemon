#include "CargaDatos.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<Pokemon> cargarPokemon(const std::string& nombreArchivo) {
    std::vector<Pokemon> lista;
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo\n";
        return lista;
    }

    // Saltar encabezado
    std::getline(archivo, linea);

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string dato;
        std::vector<std::string> columnas;

        while (std::getline(ss, dato, ',')) {
            columnas.push_back(dato);
        }

        if (columnas.size() < 9) continue;

        Pokemon p;
        p.numero = std::stoi(columnas[2]);
        p.nombre = columnas[1];
        p.tipo1_num = std::stoi(columnas[7]);   // type1_num
        p.tipo2_num = std::stoi(columnas[8]);   // type2_num
        p.generacion = std::stoi(columnas[6]);
        p.ataque = std::stoi(columnas[0]);
        p.spAtaque = std::stoi(columnas[3]);

        lista.push_back(p);
    }

    return lista;
}
