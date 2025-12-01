#include <iostream>
#include <fstream>
#include "Pokemon.h"

void agregarPokemonCSV(const std::string& rutaArchivo) {
    std::ofstream archivo(rutaArchivo, std::ios::app);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para agregar datos.\n";
        return;
    }

    Pokemon nuevo;
    std::cout << "Ingrese numero: "; std::cin >> nuevo.numero;
    std::cout << "Ingrese nombre: "; std::cin >> nuevo.nombre;
    std::cout << "Ingrese tipo1 (1-18): "; std::cin >> nuevo.tipo1;
    std::cout << "Ingrese tipo2 (0-18, 0 si no tiene): "; std::cin >> nuevo.tipo2;
    std::cout << "Ingrese generacion (1-9): "; std::cin >> nuevo.generacion;
    std::cout << "Ingrese ataque: "; std::cin >> nuevo.ataque;
    std::cout << "Ingrese ataque especial: "; std::cin >> nuevo.spAtaque;

    archivo << nuevo.numero << ","
            << nuevo.nombre << ","
            << nuevo.tipo1 << ","
            << nuevo.tipo2 << ","
            << nuevo.generacion << ","
            << nuevo.ataque << ","
            << nuevo.spAtaque << "\n";

    archivo.close();
    std::cout << "Pokemon agregado correctamente al archivo.\n";
}

