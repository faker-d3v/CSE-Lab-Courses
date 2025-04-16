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

  // selection sort
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }

      // swap anyway. If min_index == index the swap has virtually no effect
      swap(arr[minIndex], arr[i]);
    }
  }

  printArray(arr, n);
}

/* ###############
 * # Explanation #
 * ###############
 *
 * 1. Start with index = 0 and go up to len(array)-1
 * 2. Set min_index = index
 * 3. Target the index and search the whole array for a number less than that
 * 4. If found, update min_index
 *
 * */
