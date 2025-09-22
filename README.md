# Find_Your_Pokemon
Un programa que ayuda a clasificar de manera ascendente a los Pokémon basados en sus estadísticas de ataque o ataque especial, y buscando por tipo o generación específica. El programa utiliza una base de datos que contiene solo los Pokémon de primera a séptima generación. El resultado despliega los datos de la siguiente manera: Nombre Pokémon, Tipo 1, Tipo 2, Generación, Ataque y Ataque especial. También los tipos del pokemon están distribuidos en números que representan cada uno de los 18 tipos, distribuidos como muestra la siguiente tabla:
normal	1
fighting	2
flying	3
poison	4
ground	5
rock	6
bug	7
ghost	8
steel	9
fire	10
water	11
grass	12
electric	13
psychic	14
ice	15
dragon	16
dark	17
fairy	18
none 0
En el caso de none aplica cuando un Pokémon solo tiene un tipo en vez de dos.

## Algoritmo de ordenamiento implementado
Para la elaboración del programa se utilizó un algoritmo de tipo mergeSort que ordena los datos de ataque o ataque especial de forma ascendente, dependiendo del tipo de estadística que se desea acomodar. Se decidió implementar este algoritmo ya que tiene una complejidad de 0(n log n) que, aunque no es la más óptima, sigue siendo bastante buena. Por otro lado este algoritmo es bastante estable a diferencia de otros algoritmos que en el peor de los casos su complejidad llega a O(n^2). También el algoritmo se implementó con la posibilidad de modificar los comparadores al momento de decidir ordenar la Base de datos.

## Consideraciones
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

compilar con: "g++ .\Find_Your_Pokemon.cpp .\CargaDatos.cpp .\Filtros.cpp .\Ordenamiento.cpp .\Pokemon.h -o .\Find_Your_Pokemon.exe"

correr en linux: "/Find_Your_Pokemon.exe "

correr en windows: "Find_Your_Pokemon.exe "


