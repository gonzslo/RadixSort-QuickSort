#include <chrono>
#include <cmath>
#include <random>
#include "Algorithms.hpp"
#include "QuickSort.hpp"

#define SIZE (ulonglong)10 // tamaño fijo de los arreglos: 100 millones


int main() {
    // crear arreglos de forma aleatoria con números en [1,u]
    // donde u pertenece a [2,2^2,2^3,...,2^64]
    for(int i=1; i<=10; i++) {
        // realizar al menos 100 repeticiones por cada tamaño de universo
        for(int j=0; j<2; j++) {
            //crea un arreglo tamaño SIZE 
            ulonglong *arr1 = new ulonglong[SIZE];
            ulonglong *arr2 = new ulonglong[SIZE];
            // crea un arreglo de tamaño SIZE con números aleatorios
            for(int k=0; k<SIZE; k++){
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<ulonglong> distr(0, pow(2,i));
                
                ulonglong num = distr(gen);
                arr1[k] = num;
                arr2[k] = num;
            }
            // imprimir arreglos desordenados
            cout << "arreglo desordenado: " << endl;
            print(arr1, SIZE);
            // medir tiempo de ejecución de cada algoritmo
            auto startRadix = std::chrono::high_resolution_clock::now();
            radixsort(arr1, SIZE);
            auto endRadix = std::chrono::high_resolution_clock::now();

            auto startQuick = std::chrono::high_resolution_clock::now();
            quickSort(arr2, 0, SIZE-1);
            auto endQuick = std::chrono::high_resolution_clock::now();

            auto tiempofinalRadix = chrono::duration_cast<chrono::milliseconds>(endRadix - startRadix).count();
            auto tiempofinalQuick = chrono::duration_cast<chrono::milliseconds>(endQuick - startQuick).count();

            // imprime arreglos ordenados
            cout << "\narreglo ordenado con radix sort: " << endl;
            print(arr1, SIZE);
            cout << "\ntiempo radix sort: " << tiempofinalRadix << endl;

            cout << "\narreglo ordenado con quick sort: " << endl;
            print(arr2,SIZE);
            cout << "\ntiempo quick sort: " << tiempofinalQuick << endl;

            // eliminar arreglos
            delete[] arr1;
            delete[] arr2;
            
            // guardar resultados en un archivo de texto
        }
    }
    return 0;
}