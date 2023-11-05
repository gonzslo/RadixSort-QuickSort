#include <chrono>
#include <cmath>
#include <random>
#include "Algorithms.hpp"

#define SIZE 100000000 // tamaño fijo de los arreglos
typedef unsigned long long ulonglong;


int main() {
    // crear arreglos de forma aleatoria con números en [1,u]
    // u pertenece a [2,2^2,2^3,...,2^64]
    for(int i=1; i<=64; i++) {
        // realizar al menos 100 repeticiones por cada tamaño de universo
        for(int i=0; i<100; i++) {
            //crea un arreglo tamaño SIZE 
            ulonglong *arr = new ulonglong[SIZE];
            // crea un arreglo de tamaño SIZE con números aleatorios
            for(int i=0; i<SIZE; i++){
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<ulonglong> distr(0, pow(2,i));
                
                ulonglong num = distr(gen);
            }
            // medir tiempo de ejecución de cada algoritmo
            auto startRadix = std::chrono::high_resolution_clock::now();
            //hacer Radix
            auto endRadix = std::chrono::high_resolution_clock::now();

            auto startQuick = std::chrono::high_resolution_clock::now();
            //hacer Quick
            auto endQuick = std::chrono::high_resolution_clock::now();
            delete[] arr;
            
            auto tiempofinalRadix = chrono::duration_cast<chrono::milliseconds>(endRadix - startRadix).count();
            auto tiempofinalQuick = chrono::duration_cast<chrono::milliseconds>(endQuick - startQuick).count();
            // guardar resultados en un archivo de texto
        }
    }
    return 0;
}