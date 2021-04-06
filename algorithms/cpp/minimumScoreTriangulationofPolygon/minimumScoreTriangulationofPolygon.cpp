// Source: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
// Author: Miao Zhang
// Date:   2021-04-06

/****************************************************************
 * dp[i][j] = 0 if 0 <= j - i <= 1
 * dp[i][j] = min(dp[i][k] + dp[k][j] + A[i]*A[k]*A[j]) i < k < j
 * dp[0][n - 1]
****************************************************************/
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 3; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k <= j - 1; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i]* values[k] * values[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
