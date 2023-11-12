// C++ implementation QuickSort 
// using Lomuto's partition Scheme.
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <random>
#include <stack>


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
    ulonglong pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(ulonglong arr[], int low, int high) {
    #include <stack>
    std::stack<std::pair<int, int>> myStack;
    myStack.push(std::make_pair(low, high));


    while (!myStack.empty()) {
        low = myStack.top().first;
        high = myStack.top().second;
        myStack.pop();

        if (low < high) {
            int pi = partition(arr, low, high);

            if (pi - 1 > low) {
                myStack.push(std::make_pair(low, pi - 1));
            }
            if (pi + 1 < high) {
                myStack.push(std::make_pair(pi + 1, high));
            }
        }
    }
}
