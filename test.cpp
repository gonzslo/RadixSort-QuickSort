#include <chrono>
#include <cmath>
#include <random>
#include "RadixSort.hpp"
#include "QuickSort.hpp"
#include <iostream>
#include <fstream>

#define SIZE (ulonglong) 1000000 // tamaño fijo de los arreglos: 100 millones

void print(ulonglong arr[], int n);
ulonglong power(ulonglong base, ulonglong exponent);
ulonglong u = power(2,64);

int main() {
    // crear arreglos de forma aleatoria con números en [1,u]
    // donde u pertenece a [2,2^2,2^3,...,2^64]
    for(int i=1; i<=64; i++) {
        //Crea un archivo por cada tamaño de universo
        ofstream archivo;
        archivo.open("universo"+to_string(i)+".txt");
        archivo << "Tiempo Radixsort,Tiempo Quicksort" << endl;


        // realizar al menos 100 repeticiones por cada tamaño de universo
        for(int j=0; j<2; j++) {
            //crea un arreglo tamaño SIZE 
            ulonglong *arr1 = new ulonglong[SIZE];
            ulonglong *arr2 = new ulonglong[SIZE];
            // crea un arreglo de tamaño SIZE con números aleatorios
            for(int k=0; k<SIZE; k++){
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<ulonglong> distr(0, power(2,i));
                
                ulonglong num = distr(gen);
                arr1[k] = num;
                arr2[k] = num;
            }
            cout << "arreglo "<< j <<" creado valores entre 0 y 2^" << i << endl;
            // imprimir arreglos desordenados
            //cout << "arreglo desordenado: " << endl;
            //print(arr1, SIZE);
            // medir tiempo de ejecución de cada algoritmo
            auto startRadix = std::chrono::high_resolution_clock::now();
            radixSort(arr1, SIZE, 4);
            auto endRadix = std::chrono::high_resolution_clock::now();

            auto startQuick = std::chrono::high_resolution_clock::now();
            quickSort(arr2, 0, SIZE);
            auto endQuick = std::chrono::high_resolution_clock::now();

            auto tiempofinalRadix = chrono::duration_cast<chrono::milliseconds>(endRadix - startRadix).count();
            auto tiempofinalQuick = chrono::duration_cast<chrono::milliseconds>(endQuick - startQuick).count();


            // // imprime arreglos ordenados
            // cout << "\narreglo ordenado con radix sort: " << endl;
            // print(arr1, SIZE);
            // cout << "\ntiempo radix sort: " << tiempofinalRadix << endl;

            // cout << "arreglo ordenado con quick sort: " << endl;
            // print(arr2,SIZE);
            // cout << "\ntiempo quick sort: " << tiempofinalQuick << "\n" << endl;
            

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