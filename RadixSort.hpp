#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef unsigned long long ulonglong;

// A utility function to get maximum
// value in arr[]
ulonglong getMax(ulonglong arr[], int n) {
	ulonglong mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}
// creo que no hay que usar esto porque el maximo será el tamaño de u en el ciclo correspondiente

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void countingSort(ulonglong arr[], int n, int exp) {
 
    // Output array
    ulonglong output[n];
    int i, count[10] = { 0 };
 
    // Store count of occurrences
    // in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i]
    // now contains actual position
    // of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[],
    // so that arr[] now contains sorted
    // numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


// Function to sort arr[] of
// size n using bucket sort
struct Bucket {
    std::vector<ulonglong> values;
};
void bucketSort(ulonglong arr[], int n) {
    if (n <= 0) {
        return;
    }

    // Encontrar el valor máximo y mínimo en el arreglo
    ulonglong max_val = arr[0];
    ulonglong min_val = arr[0];
    for (int i = 1; i < n; i++) {
        max_val = std::max(max_val, arr[i]);
        min_val = std::min(min_val, arr[i]);
    }

    // Crear los buckets (contenedores)
    int num_buckets = n;
    std::vector<std::vector<ulonglong>> buckets(num_buckets);

    // Colocar cada elemento en el bucket correspondiente
    for (int i = 0; i < n; i++) {
        int bucket_index = static_cast<int>((static_cast<double>(arr[i] - min_val) / (max_val - min_val) * (num_buckets - 1)));
        buckets[bucket_index].push_back(arr[i]);
    }

    // Ordenar cada bucket y combinar los resultados en el arreglo original
    for (int i = 0; i < num_buckets; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}
// The main function to that sorts arr[]
// of size n using Radix Sort
// Función para encontrar el dígito en la posición especificada
int getDigit(ulonglong num, int position) {
    for (int i = 0; i < position; i++) {
        num /= 10; // Suponiendo que trabajamos con números en base 10
    }
    return num % 10;
}

// Función para ordenar un arreglo de números utilizando Radix Sort
void radixSort(ulonglong arr[], int n, int numDigits) {
    int k = static_cast<int>(ceil(log2(n))); // Tamaño de los buckets

    for (int i = 0; i < numDigits; i++) {
        int numBuckets = 1 << k; // Usar 2^k buckets

        // Crear los buckets con un tamaño fijo k
        std::vector<std::vector<ulonglong>> buckets(numBuckets);

        // Distribuir elementos en los buckets
        for (int j = 0; j < n; j++) {
            int digit = getDigit(arr[j], i);
            int bucketIndex = digit * numBuckets / 10;
            buckets[bucketIndex].push_back(arr[j]);
        }

        // Recopilar los elementos de los buckets en el arreglo original
        int index = 0;
        for (int j = 0; j < numBuckets; j++) {
            for (ulonglong num : buckets[j]) {
                arr[index++] = num;
            }
        }
    }
}

