#include <bits/stdc++.h>
using namespace std;

// Maximum possible items and weight (adjust if needed)
int dp[10][100];

// Structure to store an item's value and weight
struct Item {
    int value;
    int weight;
};

// Function to solve 0/1 Knapsack using Dynamic Programming
// w: maximum weight of the knapsack
// items: vector of items with value and weight
void zeroOneKnapsack(int maxWeight, vector<Item> &items) {
    int n = items.size();

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= maxWeight; w++) {
            if (items[i - 1].weight > w) {
                // Current item cannot be included, take previous value
                dp[i][w] = dp[i - 1][w];
            } else {
                // Take the maximum of including or excluding the current item
                dp[i][w] =
                    max(dp[i - 1][w], items[i - 1].value +
                                          dp[i - 1][w - items[i - 1].weight]);
            }
        }
    }

    // Optional: Print the DP table for understanding
    cout << "\nDP Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }
}

int main() {
    int maxWeight = 6;
    int numItems = 5;

    vector<Item> items(numItems);

    cout << "Enter " << numItems << " items (value weight):\n";
    for (int i = 0; i < numItems; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    zeroOneKnapsack(maxWeight, items);

    cout << "\nMaximum value in Knapsack is " << dp[numItems][maxWeight]
         << endl;

    return 0;
}

/*
Sample Input:
3 2
4 3
5 4
6 5
4 1

Expected Output:
Maximum value in Knapsack is 12
*/
