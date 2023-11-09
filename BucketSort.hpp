#include <iostream>
#include <vector>
#include <algorithm>
#include "CountingSort.hpp"
using namespace std;
typedef unsigned long long ulonglong;
#define SIZE (ulonglong)10 // tamaño fijo de los arreglos: 100 millones

/*
void BucketSort(ulonglong A[], ulonglong u) { // u es el tamaño del universo
    // paso 1: calcular arreglo C de contadores
    int C[u] = {0};
    for(ulonglong i = 0; i < SIZE; i++) {
       C[A[i]]+=1;
    }
    // paso 2: convertir C en un arreglo de punteros
    // * recorrer C de izquierda a derecha calculando
    for(ulonglong j = 1; j < u; j++) {
        C[j] = C[j-1] + C[j];
    }
    // * C[j-1] contiene la posición donde deben empezar a escribirse las copias del valor j en A
    // paso 3: crear nuevo arreglo B[1,n] con valores de A ordenados
    ulonglong B[SIZE];
    // * se vuelve a recorrer A de izquierda a derecha
    // * se incrementa el puntero C[A[i]-1] para la siguiente ocurrencia del valor A[i]
    for(ulonglong i = 0; i < SIZE; i++) {
        B[C[A[i] - 1]] = A[i];
        C[A[i]-1]++;
    }
}
*/

// Implementación de bucket sort
void bucketSort(unsigned long long arr[], int n) {
    const int maximo = 1000000;  // Ajusta este valor según tus necesidades

    // Crear un vector de cubetas
    vector<vector<unsigned long long>> cubetas(maximo);

    // Distribuir los elementos en las cubetas
    for (int i = 0; i < n; i++) {
        int indiceCubeta = arr[i] / maximo;
        cubetas[indiceCubeta].push_back(arr[i]);
    }

    // Ordenar cada cubeta individualmente (puedes usar cualquier algoritmo de ordenamiento)
    for (int i = 0; i < maximo; i++) {
        sort(cubetas[i].begin(), cubetas[i].end());
    }

    // Recolectar los elementos de las cubetas de nuevo en el arreglo principal
    int indiceArr = 0;
    for (int i = 0; i < maximo; i++) {
        for (unsigned long long num : cubetas[i]) {
            arr[indiceArr++] = num;
        }
    }
}