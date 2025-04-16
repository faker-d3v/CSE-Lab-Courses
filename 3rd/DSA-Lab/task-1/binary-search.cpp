#include "bits/stdc++.h"
using namespace std;

// C++ ceils when casting from float to int
bool binarySearch(int arr[], int low, int high, int x) {
  while (low <= high) {
    int mid = (low + high) / 2;

    if (x == arr[mid]) {
      return true; // or mid if you need index
    }

    if (x > arr[mid]) { // (take the right half)
      low = mid + 1;
    } else { // x is less than arr[mid] (take the left half)
      high = mid - 1;
    }
  }
  return false;
}

int main() {
  const int n = 10;
  int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int low = 0;
  int high = n - 1; // max index

  bool found = binarySearch(arr, low, high, 10);

  if (found) {
    cout << "Found" << endl;
    return 0;
  }

  cout << "Not Found" << endl;
}
