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

ulonglong partition(ulonglong arr[],int low,int high) {
    //choose the pivot
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ulonglong> distr(0, SIZE-1);
    ulonglong num = distr(gen);
    ulonglong pivot = arr[num];
    //Index of smaller element and Indicate
    //the right position of pivot found so far
    ulonglong i=(low-1);

    for(ulonglong j=low;j<=high;j++) {
        //If current element is smaller than the pivot
        if(arr[j]<pivot) {
            //Increment index of smaller element
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

// The Quicksort function Implement
void quickSort(ulonglong arr[],int low,int high) {
    // when low is less than high
    if(low<high) {
        // pi is the partition return index of pivot
        ulonglong pi=partition(arr,low,high);
        
        //Recursion Call
        //smaller element than pivot goes left and
        //higher element goes right
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}