#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // input number of rows and columns

    vector<vector<int>> twodee(n, vector<int>(m));

    // Input elements
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> twodee[i][j];

    // Output the twodee
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << twodee[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
