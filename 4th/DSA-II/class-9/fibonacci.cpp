#include <bits/stdc++.h>
using namespace std;

// Array to store computed Fibonacci values (memoization)
#define MAX_SIZE 500
long long fibMemo[MAX_SIZE];

// Simple recursive Fibonacci function (inefficient for large n)
int simpleFibo(int n) {
    if (n < 2)
        return n;
    return simpleFibo(n - 1) + simpleFibo(n - 2);
}

// Recursive Fibonacci with memoization (top-down dynamic programming)
long long fiboRec(int n) {
    // Base case: first two Fibonacci numbers
    if (n < 2) {
        fibMemo[n] = n;
        return fibMemo[n];
    }

    // If already computed, return stored value
    if (fibMemo[n] != -1)
        return fibMemo[n];

    // Compute recursively and store in memoization array
    fibMemo[n] = fiboRec(n - 1) + fiboRec(n - 2);
    return fibMemo[n];
}

int main() {
    int upto = 50; // Compute Fibonacci up to this index

    // Initialize memoization array with -1 (indicating not yet computed)
    for (int i = 0; i <= upto; i++)
        fibMemo[i] = -1;

    // Compute Fibonacci using recursive memoization
    fiboRec(upto);

    // Print all Fibonacci numbers from 0 to n
    for (int i = 0; i <= upto; i++) {
        cout << fibMemo[i] << " ";
    }
    cout << endl;

    // Optional: Print the nth Fibonacci number
    // cout << "Fibonacci of " << n << " is " << fibMemo[n] << endl;

    return 0;
}
