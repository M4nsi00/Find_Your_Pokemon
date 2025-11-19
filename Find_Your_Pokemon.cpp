#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "CargaDatos.h"
#include "Filtros.h"
#include "Ordenamiento.h"
#include "Historial.h"
#include "GestorDatos.h"

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
    historial.cargarHistorial("historial.dat");
    
    if (!historial.historialEmpty()) {
    pokedex = historial.ultimoCambio();
    std::cout << "Ultimo filtro restaurado.\n";
    mostrarPokemon(pokedex);
    }

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
        std::cout << "6. Agregar nuevo Pokemon a la base de datos\n";
        std::cout << "7. Elimiar TODO el historial de filtros\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        
        if (opcion >= 1 && opcion <= 4){
            if (opcion == 1 || opcion == 2) {
                int tipo; 
                std::cout << "Ingrese tipo (1-18): "; 
                std::cin >> tipo;
                pokedex = filtrarPorTipo(pokedex, tipo);
                if (opcion == 1){
                    mergeSort(pokedex, 0, pokedex.size() - 1, compararPorAtaqueAsc);
                }else{
                    mergeSort(pokedex, 0, pokedex.size() - 1, compararPorSpAtkAsc);
                }

                historial.reigstrarFiltro(pokedex);

            }
            else if (opcion == 3 || opcion == 4) {
                int gen; 
                std::cout << "Ingrese generacion (1-9): "; 
                std::cin >> gen;
                pokedex = filtrarPorGeneracion(pokedex, gen);
                
                if (opcion == 3){
                    mergeSort(pokedex, 0, pokedex.size() - 1, compararPorAtaqueAsc);
                }else{
                    mergeSort(pokedex, 0, pokedex.size() - 1, compararPorSpAtkAsc);
                }

                historial.reigstrarFiltro(pokedex);
        } 
             mostrarPokemon(pokedex);
    }else if (opcion == 5){
            if (!historial.deshacerUltimoCambio(pokedex))
                std::cout << "No hay filtros previos para deshacer.\n";
            else
                mostrarPokemon(pokedex);
        }
        else if(opcion == 6){
            agregarPokemonCSV("pokemon.csv");
            pokedex = cargarPokemon("pokemon.csv");
        }
        else if(opcion == 7){
            pokedex = cargarPokemon("pokemon.csv");
            historial.limpiarHistorial(pokedex);
            mostrarPokemon(pokedex);
        }
        
        cout << "Historial de estados guardados: " << historial.tamanio() << endl;

    
    }while (opcion != 0);

    historial.guardarHistorial("historial.dat");
    
    return 0;
}

