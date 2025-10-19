#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "CargaDatos.h"
#include "Filtros.h"
#include "Ordenamiento.h"
#include "Historial.h"

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
    Historial historial;
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
        std::cout << "5. Deshacer ultimo filtro\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        
        if (opcion >= 1 && opcion <= 4){
            if (opcion == 1 || opcion == 2) {
                int tipo; 
                std::cout << "Ingrese tipo (1-18): "; 
                std::cin >> tipo;
                historial.reigstrarFiltro(pokedex);

                pokedex = filtrarPorTipo(pokedex, tipo);

                if (opcion == 1){
                    mergeSort(pokedex, 0, pokedex.size() - 1, compararPorAtaqueAsc);
                }else{
                    mergeSort(pokedex, 0, pokedex.size() - 1, compararPorSpAtkAsc);
                }
            }
            else if (opcion == 3 || opcion == 4) {
                int gen; 
                std::cout << "Ingrese generacion (1-7): "; 
                std::cin >> gen;
                historial.reigstrarFiltro(pokedex);
                
                pokedex = filtrarPorGeneracion(pokedex, gen);

                if (opcion == 3){
                    mergeSort(pokedex, 0, pokedex.size() - 1, compararPorAtaqueAsc);
                }else{
                    mergeSort(pokedex, 0, pokedex.size() - 1, compararPorSpAtkAsc);
                }
        } 
             mostrarPokemon(pokedex);
    }else if (opcion == 5){
            if (!historial.deshacerUltimoCambio(pokedex))
                std::cout << "No hay filtros previos para deshacer.\n";
            else
                mostrarPokemon(pokedex);
        }
        
        cout << "Historial de estados guardados: " << historial.tamanio() << endl;

    } while (opcion != 0);

    return 0;
}

