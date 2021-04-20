// Source: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
// Author: Miao Zhang
// Date:   2021-04-20

/************************************************
 * dp[i][j]: the ith operation, postion is j
 * dp[i][j] = dp[i-1][j] + dp[i-1][j]+ dp[i-1][j+1]
 * dp[0][0] = 1
 * dp[steps][0]
************************************************/
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int kMod = 1e9 + 7;
        int n = min(steps + 1, arrLen);
        vector<vector<int>> dp(steps + 1, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = -1; k <= 1; k++) {
                    if (j - k >= 0 && j - k < n)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % kMod;
                }
            }
        }
        return dp[steps][0] % kMod;
    }
};
