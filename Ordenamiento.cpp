#include "Ordenamiento.h"

void merge(std::vector<Pokemon>& arr, int left, int mid, int right,
           std::function<bool(const Pokemon&, const Pokemon&)> cmp) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Pokemon> L(n1);
    std::vector<Pokemon> R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (cmp(L[i], R[j])) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<Pokemon>& arr, int left, int right,
               std::function<bool(const Pokemon&, const Pokemon&)> cmp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, cmp);
        mergeSort(arr, mid + 1, right, cmp);
        merge(arr, left, mid, right, cmp);
    }
}

// Comparadores
bool compararPorAtaqueAsc(const Pokemon& a, const Pokemon& b) { return a.ataque < b.ataque; }
bool compararPorAtaqueDesc(const Pokemon& a, const Pokemon& b) { return a.ataque > b.ataque; }
bool compararPorSpAtkAsc(const Pokemon& a, const Pokemon& b) { return a.spAtaque < b.spAtaque; }
bool compararPorSpAtkDesc(const Pokemon& a, const Pokemon& b) { return a.spAtaque > b.spAtaque; }

