// C++ implementation QuickSort 
// using Lomuto's partition Scheme.
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <random>


using namespace std;
typedef unsigned long long ulonglong;

// This function takes last element
// as pivot, places
// the pivot element at its correct
// position in sorted array, and 
// places all smaller (smaller than pivot)
// to left of pivot and all greater 
// elements to right of pivot
ulonglong partition(ulonglong arr[], int low, int high) {
	// pivot
	ulonglong pivot = arr[high]; 

	// Index of smaller element
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) 
	{
		// If current element is smaller
		// than or equal to pivot
		if (arr[j] <= pivot) {

			// increment index of 
			// smaller element
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
ulonglong partition_r(ulonglong arr[], int low, int high) {
	// Generate a random number in between
	// low .. high
	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ulonglong> distr(low, high);
	ulonglong random = distr(gen);

	// Swap A[random] with A[high]
	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}

/* The main function that implements
QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(ulonglong arr[], int low, int high) {
	if (low < high) {

		/* pi is partitioning index,
		arr[p] is now
		at right place */
		int pi = partition_r(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

