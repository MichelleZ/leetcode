// Source: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
// Author: Miao Zhang
// Date:   2021-02-05

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        return solve(dp, 1, n);
    }
    
    int solve(vector<vector<int>> &dp, int l, int r) {
        if (l >= r) return 0;
        if (dp[l][r] != INT_MAX) return dp[l][r];
        for (int i = l; i <= r; i++) {
            dp[l][r] = min(dp[l][r], i + max(solve(dp, l, i - 1), solve(dp, i + 1, r)));
        }
        return dp[l][r];
    }
};
