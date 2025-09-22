#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>
#include "Pokemon.h"
#include <functional>

// MergeSort con comparador flexible
void mergeSort(std::vector<Pokemon>& arr, int left, int right, std::function<bool(const Pokemon&, const Pokemon&)> cmp);

// Comparadores
bool compararPorAtaqueAsc(const Pokemon& a, const Pokemon& b);
bool compararPorAtaqueDesc(const Pokemon& a, const Pokemon& b);
bool compararPorSpAtkAsc(const Pokemon& a, const Pokemon& b);
bool compararPorSpAtkDesc(const Pokemon& a, const Pokemon& b);

#endif
