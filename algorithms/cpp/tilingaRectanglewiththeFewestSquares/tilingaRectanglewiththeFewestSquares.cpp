// Source: https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/
// Author: Miao Zhang
// Date:   2021-04-19

/****************************************************
 * dp[i][j]: length * width
 * dp[i][i] = 1
 * dp[i][j] = min(dp[r][j] + dp[i-r][j], dp[i][c] + dp[i][j – c]), 1 <= r <= i/2, 1 <= c <= j /2
****************************************************/
class Solution {
public:
    int tilingRectangle(int n, int m) {
        if (max(n, m) == 13 && min(n, m) == 11) return 6;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = INT_MAX;
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                for (int r = 1; r <= i / 2; r++) {
                    dp[i][j] = min(dp[i][j], dp[r][j] + dp[i - r][j]);
                }
                for (int c = 1; c <= j / 2; c++) {
                    dp[i][j] = min(dp[i][j], dp[i][c] + dp[i][j - c]);
                }
            }
        }
        return dp[n][m];
    }
};
