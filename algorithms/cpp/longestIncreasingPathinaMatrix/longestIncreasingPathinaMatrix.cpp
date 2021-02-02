// Source: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Author: Miao Zhang
// Date:   2021-02-02

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int path = dfs(matrix, dp, i, j);
                res = max(res, path);
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> dp, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        dp[i][j] = 1;
        for (auto d: dirs) {
            int x = i + d.first;
            int y = j + d.second;
            if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] <= matrix[i][j]) continue;
            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, dp, x, y));
        }
        return dp[i][j];
    }
};
