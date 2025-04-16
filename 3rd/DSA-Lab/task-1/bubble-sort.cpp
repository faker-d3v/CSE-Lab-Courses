#include "bits/stdc++.h"
using namespace std;

void printArray(int a[], int size) {
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void swap(int *a, int *b) {
  int *t = a;
  a = b;
  b = t;
}

int main() {
  const int n = 10;
  int arr[n] = {7, 2, 10, 1, 5, 9, 4, 6, 8, 3};

  // bubble sort
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (arr[j + 1] < arr[j]) {
        swap(arr[j + 1], arr[j]);
      }
    }
  }

  printArray(arr, n);
}

/* ###############
 * # Explanation #
 * ###############
 *
 * 1. Sort with the next value as you go
 * 2. Repeat this process len(array) - 1 times
 * 3. Dead simple :)
 *
 * */
