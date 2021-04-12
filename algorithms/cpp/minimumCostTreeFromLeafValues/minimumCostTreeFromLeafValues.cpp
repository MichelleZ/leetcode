// Source: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Author: Miao Zhang
// Date:   2021-04-12

/*************************************************
 * dp[i][j] = min{dp[i][k] + dp[k + 1][j] + max(a[i~k]) * max(a[k + 1~j])}
*************************************************/
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> m(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            m[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                m[i][j] = max(m[i][j - 1], arr[j]);
            }
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + m[i][k] * m[k+1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
