// Source: https://leetcode.com/problems/matrix-block-sum/
// Author: Miao Zhang
// Date:   2021-04-23

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        auto res = mat;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = max(0, i - k);
                int x2 = min(m - 1, i + k);
                int y1 = max(0, j - k);
                int y2 = min(n - 1, j + k);
                res[i][j] = dp[x2 + 1][y2 + 1] - dp[x2 + 1][y1] - dp[x1][y2 + 1] + dp[x1][y1];
            }
        }
        return res;
    }
};
