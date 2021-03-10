// Source: https://leetcode.com/problems/domino-and-tromino-tiling/
// Author: Miao Zhang
// Date:   2021-03-10

/**********************************************************************
 * dp[i][0]: i cols, all covered
 * dp[i][1]: i cols, but top row
 * dp[i][2]: i cols, but bottom row
 * dp[i][0] = dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]
 * dp[i][1] = dp[i - 2][0] + d[i - 1][2]
 * dp[i][2] = dp[i - 2][0] + dp[i - 1][1]
**********************************************************************/
class Solution {
public:
    int numTilings(int N) {
        int kMod = 1000000007;
        vector<vector<long>> dp(N + 1, vector<long>(3, 0));
        dp[0][0] = dp[1][0] = 1;
        for (int i = 2; i <= N; ++i) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]) % kMod;
            dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % kMod;
            dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % kMod;
        }
        return dp[N][0];
    }
};
