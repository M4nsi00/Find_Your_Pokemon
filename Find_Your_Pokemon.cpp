#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "CargaDatos.h"
#include "Filtros.h"
#include "Ordenamiento.h"

void mostrarPokemon(const std::vector<Pokemon>& lista) {
    for (const auto& p : lista) {
        std::cout << p.numero << " - " << p.nombre
                  << " | Tipo1: " << p.tipo1
                  << " | Tipo2: " << p.tipo2
                  << " | Gen: " << p.generacion
                  << " | Atk: " << p.ataque
                  << " | SpAtk: " << p.spAtaque
                  << "\n";
    }
}

int main() {
    std::vector<Pokemon> pokedex = cargarPokemon("pokemon.csv");
    if (pokedex.empty()) {
        std::cerr << "No se cargaron datos.\n";
        return 1;
    }

    int opcion;
    do {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Filtrar por tipo y ordenar por ataque\n";
        std::cout << "2. Filtrar por tipo y ordenar por ataque especial\n";
        std::cout << "3. Filtrar por generacion y ordenar por ataque\n";
        std::cout << "4. Filtrar por generacion y ordenar por ataque especial\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        if (opcion == 1 || opcion == 2) {
            int tipo; 
            std::cout << "Ingrese tipo (1-18): "; 
            std::cin >> tipo;
            auto filtrados = filtrarPorTipo(pokedex, tipo);

            if (opcion == 1)
                mergeSort(filtrados, 0, filtrados.size() - 1, compararPorAtaqueAsc);
            else
                mergeSort(filtrados, 0, filtrados.size() - 1, compararPorSpAtkAsc);

            mostrarPokemon(filtrados);
        }
        else if (opcion == 3 || opcion == 4) {
            int gen; 
            std::cout << "Ingrese generacion (1-7): "; 
            std::cin >> gen;
            auto filtrados = filtrarPorGeneracion(pokedex, gen);

            if (opcion == 3)
                mergeSort(filtrados, 0, filtrados.size() - 1, compararPorAtaqueAsc);
            else
                mergeSort(filtrados, 0, filtrados.size() - 1, compararPorSpAtkAsc);

            mostrarPokemon(filtrados);
        }

    } while (opcion != 0);

    return 0;
}

