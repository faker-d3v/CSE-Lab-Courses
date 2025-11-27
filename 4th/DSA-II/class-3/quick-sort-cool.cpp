#include "bits/stdc++.h"
using namespace std;

void printVector(vector<int> v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl; 
}

// returns the pivot index after sorting accordingly
int partition(vector<int> &array, int low, int high) {
    int pivot = array[high]; // last index as pivot
    int leftwall = low;

    for (int i = low; i < high; i ++) {
        if (array[i] < pivot) {
            swap(array[leftwall], array[i]);
            leftwall ++;
        }
    }

    swap(array[leftwall], array[high]);
    return leftwall;
}

void quicksort(vector<int> &array, int low, int high) {
    if (low < high) { 
        // basically quit if low == high during recursive calls
        int pivot_location = partition(array, low, high);
        quicksort(array, low, pivot_location-1);
        quicksort(array, pivot_location+1, high);
    }
}
    
int main() {
    //                  L                 P 
    vector<int> list = {8, 7, 6, 1, 0, 9, 2};
    quicksort(list, 0, list.size() - 1);
    printVector(list);
}

