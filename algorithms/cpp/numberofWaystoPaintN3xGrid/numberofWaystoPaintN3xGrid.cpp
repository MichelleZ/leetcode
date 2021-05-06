// Source: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
// Author: Miao Zhang
// Date:   2021-05-05

/******************************************************
 * dp[i][0]: ABA; dp[i][1]: ABC
 * dp[i][0] = 3 * dp[i - 1][0] + 2 * dp[i - 1][1]
 * dp[i][1] = 2 * dp[i - 1][0] + 2 * dp[i - 1][1]
 * dp[1][0] = dp[1][1] = 6
******************************************************/
class Solution {
public:
    int numOfWays(int n) {
        int kMod = 1e9 + 7;
        vector<vector<long>> dp(n + 1, vector<long>(2));
        dp[1][0] = dp[1][1] = 6;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = (3 * dp[i - 1][0] + 2 * dp[i - 1][1]) % kMod;
            dp[i][1] = (2 * dp[i - 1][0] + 2 * dp[i - 1][1]) % kMod;
        }
        return (dp[n][0] + dp[n][1]) % kMod;
    }
};
