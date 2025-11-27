#include <bits/stdc++.h>
using namespace std;

// DP table for storing lengths of LCS
int dp[100][100];

int main() {
    string str1, str2;
    int len1, len2;

    // Input two strings
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    len1 = str1.size();
    len2 = str2.size();

    // Initialize first row and first column of dp table to 0
    for (int i = 0; i <= len1; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= len2; i++)
        dp[i][0] = 0;

    // Build the dp table
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                // Characters match, increase length by 1 from diagonal
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // Characters do not match, take the maximum of left or top cell
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Print the DP table (optional, for understanding)
    cout << "\nDP Table:\n";
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // Length of Longest Common Subsequence
    cout << "\nLCS of \"" << str1 << "\" & \"" << str2 << "\" is "
         << dp[len1][len2] << endl;

    return 0;
}
