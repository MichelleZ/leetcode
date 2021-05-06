// Source: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
// Author: Miao Zhang
// Date:   2021-05-06

/*********************************************************
 * dp[i][j][s] = dp[i - 1][j][s] * j
 *             + sum(dp[i - 1][x][s - 1]) 1 <= x < j
*********************************************************/
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int kMod = 1e9 + 7;
        if (k == 0) return 0;
        vector<vector<vector<long>>> dp(n + 1, vector<vector<long>>(m + 1, vector<long>(k + 1)));
        for (int j = 1; j < m + 1; j++) {
            dp[1][j][1] = 1;
        }
        for (int i = 2; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                for (int s = 1; s < min(k, i) + 1; s++) {
                    dp[i][j][s] = dp[i - 1][j][s] * j;
                    for (int j0 = 1; j0 < j; j0++) {
                        dp[i][j][s] += dp[i - 1][j0][s - 1];
                    }
                    dp[i][j][s] %= kMod;
                }
            }
        }
        long res = 0;
        for (int j = 1; j < m + 1; j++) {
            res += dp[n][j][k];
        }
        return res % kMod;
    }
};
