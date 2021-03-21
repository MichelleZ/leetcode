// Source: https://leetcode.com/problems/profitable-schemes/
// Author: Miao Zhang
// Date:   2021-03-21

/*******************************************************************************
 * dp[k][i][j]: profit i with j people, complete k crimes
 * dp[n][minProfit]
*******************************************************************************/
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int kMod = 1000000007;
        int K = group.size();
        vector<vector<vector<int>>> dp(K + 1, vector<vector<int>>(minProfit + 1, vector<int>(n + 1, 0)));
        dp[0][0][0] = 1;
        for (int k = 1; k <= K; k++) {
            int p = profit[k - 1];
            int g = group[k - 1];
            for (int i = 0; i <= minProfit; i++) {
                for (int j = 0; j <= n; j++) {
                    dp[k][i][j] = (dp[k - 1][i][j] + (j < g ? 0 : dp[k - 1][max(0, i - p)][j - g])) % kMod;
                }
            }
        }
        return accumulate(begin(dp[K][minProfit]), end(dp[K][minProfit]), 0LL) % kMod;
    }
};
