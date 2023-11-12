#include <chrono>
#include <cmath>
#include <random>
#include "RadixSort.hpp"
#include "QuickSort.hpp"
#include <iostream>
#include <fstream>

#define SIZE (ulonglong) 10 // tamaño fijo de los arreglos: 100 millones

void print(ulonglong arr[], int n);
ulonglong power(ulonglong base, ulonglong exponent);
ulonglong u = power(2,64);

int main() {
    // crear arreglos de forma aleatoria con números en [1,u]
    // donde u pertenece a [2,2^2,2^3,...,2^64]
    for(int i=1; i<=10; i++) {
        //Crea un archivo por cada tamaño de universo
        ofstream archivo;
        archivo.open("universo"+to_string(i)+".txt");
        archivo << "Tiempo Radixsort,Tiempo Quicksort" << endl;
        int k=1;
        if (i >= 4 && i <= 6) k=2;
        if (i >= 7 && i <= 9) k=3;
        if (i >= 10 && i <= 13) k=4;
        if (i >= 14 && i <= 16) k=5;
        if (i >= 17 && i <= 19) k=6;
        if (i >= 20 && i <= 23) k=7;
        if (i >= 24 && i <= 26) k=8;
        if (i >= 27 && i <= 29) k=9;
        if (i >= 30 && i <= 33) k=10;
        if (i >= 34 && i <= 36) k=11;
        if (i >= 37 && i <= 39) k=12;
        if (i >= 40 && i <= 43) k=13;
        if (i >= 44 && i <= 46) k=14;
        if (i >= 47 && i <= 49) k=15;
        if (i >= 50 && i <= 53) k=16;
        if (i >= 54 && i <= 56) k=17;
        if (i >= 57 && i <= 59) k=18;
        if (i >= 60 && i <= 63) k=19;
        if (i >= 64) k=20;
        // realizar al menos 100 repeticiones por cada tamaño de universo
        for(int j=0; j<1; j++) {
            //crea un arreglo tamaño SIZE 
            ulonglong *arr1 = new ulonglong[SIZE];
            ulonglong *arr2 = new ulonglong[SIZE];
            // crea un arreglo de tamaño SIZE con números aleatorios
            for(int l=0; l<SIZE; l++){
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<ulonglong> distr(0, pow(2,i));
                
                ulonglong num = distr(gen);
                arr1[l] = num;
                arr2[l] = num;
            }
            // imprimir arreglos desordenados
            //cout << "arreglo desordenado: " << endl;
            //print(arr1, SIZE);
            // medir tiempo de ejecución de cada algoritmo
            auto startRadix = std::chrono::high_resolution_clock::now();
            radixSort(arr1, SIZE, k);
            auto endRadix = std::chrono::high_resolution_clock::now();

            auto startQuick = std::chrono::high_resolution_clock::now();
            quickSort(arr2, 0, SIZE);
            auto endQuick = std::chrono::high_resolution_clock::now();

            auto tiempofinalRadix = chrono::duration_cast<chrono::nanoseconds>(endRadix - startRadix).count();
            auto tiempofinalQuick = chrono::duration_cast<chrono::nanoseconds>(endQuick - startQuick).count();


            // imprime arreglos ordenados
            cout << "\narreglo ordenado con radix sort: " << endl;
            print(arr1, SIZE);
            cout << "\ntiempo radix sort: " << tiempofinalRadix << endl;

            cout << "arreglo ordenado con quick sort: " << endl;
            print(arr2,SIZE);
            cout << "\ntiempo quick sort: " << tiempofinalQuick << "\n" << endl;
            

            // eliminar arreglos
            delete[] arr1;
            delete[] arr2;

            // guardar resultados en un archivo de texto
            archivo << tiempofinalRadix << "," << tiempofinalQuick << endl;

        }
        archivo.close();
    }
    return 0;
}

void print(ulonglong arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

ulonglong power(ulonglong base, ulonglong exponent) {
    ulonglong resultado = 1;
    for (ulonglong i = 0; i < exponent; i++) {
        resultado *= base;
    }
    return resultado;
}