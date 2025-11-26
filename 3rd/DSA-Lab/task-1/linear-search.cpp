#include <bits/stdc++.h>
using namespace std;

int main() {
    const int n = 10;
    int arr[n] = {7, 2, 10, 1, 5, 9, 4, 6, 8, 3};
    int target = 9;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Found" << endl;
        return 0;
    }

    cout << "Not found :(" << endl;
}
