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
    std::cout << "Ingrese ataque: "; std::cin >> nuevo.ataque;
    std::cout << "Ingrese nombre: "; std::cin >> nuevo.nombre;    
    std::cout << "Ingrese numero: "; std::cin >> nuevo.numero;
    std::cout << "Ingrese ataque especial: "; std::cin >> nuevo.spAtaque;
    std::cout << "Ingrese tipo1 (no numerico valor en ingles): "; std::cin >> nuevo.tipo1_str;
    std::cout << "Ingrese tipo2 (no numerico valor en ingles, si no tiene poner ,): "; std::cin >> nuevo.tipo2_str;
    std::cout << "Ingrese generacion (1-9): "; std::cin >> nuevo.generacion;
    std::cout << "Ingrese tipo1 (1-18): "; std::cin >> nuevo.tipo1_num;
    std::cout << "Ingrese tipo2 (0-18, 0 si no tiene): "; std::cin >> nuevo.tipo2_num;


    archivo << nuevo.ataque << ","
            << nuevo.nombre << ","
            << nuevo.numero << ","
            << nuevo.spAtaque << ","       
            << nuevo.tipo1_str << ","
            << nuevo.tipo2_str << ","
            << nuevo.generacion << ","
            << nuevo.tipo1_num << ","
            << nuevo.tipo2_num << "\n";

    archivo.close();
    std::cout << "Pokemon agregado correctamente al archivo.\n";
}
