#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "BucketSort.hpp"
using namespace std;
typedef unsigned long long ulonglong;
#define SIZE (ulonglong)10 // tamaño fijo de los arreglos: 100 millones

void RadixSort(ulonglong arr[], ulonglong u) {
    // realiza una serie de rondas de bucket sort sobre los datos
    // ordena progresivamente de los bits menos significativos a los más significativos
    
    // ordenamos de a k=ceil(log2(u)) bits
    int k = ceil(log2(u));

    for (int i = 0; i < k; i++) {
        // Ordena los elementos en función del i-ésimo bit menos significativo
        ulonglong mask = 1ULL << i;
        ulonglong bucket[2][SIZE]; // Usamos 2 buckets para alternar entre ellos
        
        for (int j = 0; j < SIZE; j++) {
            int bucketIndex = (arr[j] & mask) ? 1 : 0;
            bucket[bucketIndex][j] = arr[j];
        }
        
        // Aplica BucketSort en los dos buckets
        BucketSort(bucket[0], u);
        BucketSort(bucket[1], u);
        
        // Combina los elementos ordenados de los buckets
        int index = 0;
        for (int j = 0; j < SIZE; j++) {
            if (bucket[0][j] != 0) {
                arr[index] = bucket[0][j];
                index++;
            }
        }
        for (int j = 0; j < SIZE; j++) {
            if (bucket[1][j] != 0) {
                arr[index] = bucket[1][j];
                index++;
            }
        }
    }
}