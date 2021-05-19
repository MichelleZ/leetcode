// Source: https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/
// Author: Miao Zhang
// Date:   2021-05-19

/************************************************************
 * dp[i][s]: the first group: 0-i, second group: set,1 << (len(cost[0]))
 * dp[i][s | (1 << j)] = min(dp[i][s | (1 << j)],
 *                           dp[i][s] + cost[i][j],
 *                           dp[i - 1][s] + cost[i][j])
 * dp[0][0] = 0
 * dp[m][1 << n - 1]
************************************************************/
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m = cost.size();
        int n = cost[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int s = 0; s < 1 << n; s++) {
                    dp[i + 1][s | (1 << j)] = min({dp[i + 1][s | (1 << j)],
                                                  dp[i + 1][s] + cost[i][j],
                                                  dp[i][s] + cost[i][j]});
                }
            }
        }
        return dp[m].back();
    }
};
