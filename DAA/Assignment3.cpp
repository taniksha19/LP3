#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0)); //this line check

    for (int item = 1; item <= n; item++) {
        for (int weight = 1; weight <= capacity; weight++) {
            if (weights[item - 1] <= weight) {
                dp[item][weight] = max(dp[item - 1][weight - weights[item - 1]] + values[item - 1], dp[item - 1][weight]);// weight if current item included and if excluded
            } else {
                dp[item][weight] = dp[item - 1][weight];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    cout << "Press Ctrl+C to terminate..." << endl;

    while (true) {
        int n;
        cout << "Enter number of items: ";
        cin >> n;

        vector<int> values(n);
        cout << "Enter values of items: ";
        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }

        vector<int> weights(n);
        cout << "Enter weights of items: ";
        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }

        int capacity;
        cout << "Enter maximum weight: ";
        cin >> capacity;

        int maximum_value = knapsack(values, weights, capacity);
        cout << "The maximum value of items that can be carried: " << maximum_value << endl;
    }

    return 0;
}