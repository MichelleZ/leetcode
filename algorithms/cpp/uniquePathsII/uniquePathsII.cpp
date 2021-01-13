// Source: https://leetcode.com/problems/unique-paths-ii/
// Author: Miao Zhang
// Date:   2021-01-13

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (obstacleGrid[0][0] == 0) {
            dp[0][0] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0 && obstacleGrid[i - 1][j] == 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
