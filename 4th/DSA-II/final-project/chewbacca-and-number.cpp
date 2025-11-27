#include "bits/stdc++.h"
using namespace std;

// Adding 48 to any decimal gets you it's ascii value
char invert(char c) { return '9' - c + 48; }

int main() {
    string text;
    cin >> text;

    int count = 0;
    for (char i : text) {
        if (count == 0 && i == '9')
            continue; // we can't have first digit as 9-9=0

        cout << min(i, invert(i)); // keep the minimum
        count++;
    }

    cout << endl;
}
