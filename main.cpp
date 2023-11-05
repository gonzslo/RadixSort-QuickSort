#include "Algorithms.hpp"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = { 5, 2, 4, 6, 1, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, size, 6);
    printArray(arr, size);
    return 0;

}