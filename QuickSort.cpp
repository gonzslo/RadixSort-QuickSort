#include <bits/stdc++.h>
#include <random>
using namespace std;
typedef unsigned long long ulonglong;

int partition(ulonglong arr[],int low,int high) {
    //choose the pivot
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, sizeof(arr)-1);
    int num = distr(gen);
    int pivot = arr[num];
    //Index of smaller element and Indicate
    //the right position of pivot found so far
    int i=(low-1);

    for(int j=low;j<=high;j++) {
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
void quickSort(ulonglong arr[],ulonglong low,ulonglong high) {
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
			
int main() {
    ulonglong arr[]={10,7,8,9,1,5};
    ulonglong n=sizeof(arr)/sizeof(arr[0]);
    // Function call
    quickSort(arr,0,n-1);
    //Print the sorted array
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
