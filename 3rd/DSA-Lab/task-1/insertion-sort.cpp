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

  // |          j           |
  // | 1 2 7 10 5 9 4 6 8 3 |

  // insertion sort
  for (int i = 1; i < n; i++) {
    int j = i;

    while (j > 0 && arr[j - 1] > arr[j]) {
      swap(arr[j - 1], arr[j]);
      j--;
    }
  }

  printArray(arr, n);
}

/* ###############
 * # Explanation #
 * ###############
 *
 * 1. Start off with index i=1 and increment till the last index
 * 2. Iterate back to zero for each value of i
 * 3. Sort the values as you iterate back
 * 4. Repeat 🔁
 *
 * */
