#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ulonglong;
#define SIZE (ulonglong)10 // tamaño fijo de los arreglos: 100 millones

void CountingSort(ulonglong A[], ulonglong n, ulonglong u) {
    // counting array
    int C[u] = {0};
    // store count of ocurrences
    for(ulonglong i = 0; i < n; i++) {
        C[A[i]]++;
    }
    // rewrite A using C[j] copies of j
    for(ulonglong j = 0; j < u; j++) {
        
    }
}