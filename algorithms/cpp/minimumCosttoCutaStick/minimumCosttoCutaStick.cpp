// Source: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
// Author: Miao Zhang
// Date:   2021-05-15

/******************************************************************
 * dp[i][j]: dp[i][k] + dp[k][j] + cut[j] - cut[i]
 * dp[0][n]
******************************************************************/
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts), end(cuts));
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = i + 1; j < m; j++) {
                dp[i][j] = ((i + 1) == j ? 0 : INT_MAX);
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return dp[0][m - 1];
    }
};
