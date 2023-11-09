#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ulonglong;
#define SIZE (ulonglong)10 // tamaño fijo de los arreglos: 100 millones


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
void bucketSort(ulonglong arr[], int n) {

	// 1) Create n empty buckets
	vector<float> b[n];

	// 2) Put array elements
	// in different buckets
	for (int i = 0; i < n; i++) {
		// Index in bucket
		ulonglong bi = n * arr[i];
		b[bi].push_back(arr[i]);
	}

	// 3) Sort individual buckets
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	// 4) Concatenate all buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

// The main function to that sorts arr[]
// of size n using Radix Sort
void radixsort(ulonglong arr[], int n) {

	// Find the maximum number to
	// know number of digits
	ulonglong m = getMax(arr, n);

	// Do counting sort for every digit.
	// Note that instead of passing digit
	// number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countingSort(arr, n, exp);
}
// A utility function to print an array
void print(ulonglong arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
