// Source: https://leetcode.com/problems/out-of-boundary-paths/
// Author: Miao Zhang
// Date:   2021-02-23

/*****************************************************
 * dp[n][i][j]: arrive [i, j] need n steps
 * dp[*][i][j]: if [i, j] is out of boundary, dp[*][i][j] = 1
 * dp[n][i][j] = dp[n - 1][i - 1][j]
 *             + dp[n - 1][i + 1][j]
 *             + dp[n - 1][i][j - 1]
 *             + dp[n - 1][i][j + 1]
*****************************************************/
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int kMod = 1000000007;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int s = 1; s <= N; s++) {
            vector<vector<int>> tmp(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (auto d: dirs) {
                        int x = i + d[0];
                        int y = j + d[1];
                        if (x < 0 || y < 0 || x >= m || y >= n) {
                            tmp[i][j] += 1;
                        } else {
                            tmp[i][j] = (tmp[i][j] + dp[x][y]) % kMod;
                        }
                    }
                }
            }
            dp.swap(tmp);
        }
        return dp[i][j];
    }
};
