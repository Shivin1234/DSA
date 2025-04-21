#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // Base case: There's 1 way to make amount 0 (pick nothing)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Build the table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {  // start j from 0
                if (coins[i - 1] <= j) {
                    // Include current coin + exclude it
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                } else {
                    // Can't include it, so just exclude
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amount];
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int ways = sol.change(amount, coins);
    cout << "Number of combinations: " << ways << endl;  // Expected: 4
    return 0;
}
