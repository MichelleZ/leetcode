// Source: https://leetcode.com/problems/coin-change-2/
// Author: Miao Zhang
// Date:   2021-02-19

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int c: coins) {
            for (int i = 1; i < amount + 1; i++) {
                if (c <= i) {
                    dp[i] += dp[i - c];
                }
            }
        }
        return dp[amount];
    }
};
