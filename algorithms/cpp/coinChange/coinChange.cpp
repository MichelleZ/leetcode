// Source: https://leetcode.com/problems/coin-change/
// Author: Miao Zhang
// Date:   2021-02-02

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (auto coin: coins) {
                if (coin <= i) {
                    if (dp[i - coin] != INT_MAX) {
                        dp[i] = min(dp[i], dp[i - coin] + 1);
                    }
                }
            }
        }
        return dp[amount] <= amount ? dp[amount] : -1;
    }
};
