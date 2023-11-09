#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ulonglong;
#define SIZE (ulonglong)10 // tamaño fijo de los arreglos: 100 millones

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