#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    // Input number of different coin types
    int numCoins;
    cout << "Enter number of coins: ";
    cin >> numCoins;

    // Input values of each coin
    vector<int> coinValues(numCoins);
    cout << "Enter coin values: ";
    for (int i = 0; i < numCoins; i++)
        cin >> coinValues[i];

    // Input the target amount we want to make
    int targetAmount;
    cout << "Enter amount: ";
    cin >> targetAmount;

    // Define a large number as "infinity" for initialization

    // dp[i] = minimum number of coins needed to make amount i
    vector<int> dp(targetAmount + 1, INT_MAX);
    dp[0] = 0; // Base case: 0 coins are needed to make amount 0

    // Loop through each coin
    for (int i = 0; i < numCoins; i++) {
        // Update dp table for all amounts that can use this coin
        for (int amount = coinValues[i]; amount <= targetAmount; amount++) {
            dp[amount] = min(dp[amount], 1 + dp[amount - coinValues[i]]);
        }
    }

    // Check if the target amount is achievable
    if (dp[targetAmount] == INT_MAX)
        cout << "Not possible to make amount " << targetAmount << endl;
    else
        cout << "Minimum coins required = " << dp[targetAmount] << endl;

    return 0;
}
