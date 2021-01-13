// Source: https://leetcode.com/problems/minimum-path-sum/
// Author: Miao Zhang
// Date:   2021-01-13

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int tmp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    tmp = min(dp[i - 1][j], dp[i][j - 1]);
                } else if (i - 1 >= 0) {
                    tmp = dp[i - 1][j];
                } else if (j - 1 >= 0) {
                    tmp = dp[i][j - 1];
                } else {
                    tmp = 0;
                }
                dp[i][j] = grid[i][j] + tmp;
            }
        }
        return dp[m - 1][n - 1];
    }
};
