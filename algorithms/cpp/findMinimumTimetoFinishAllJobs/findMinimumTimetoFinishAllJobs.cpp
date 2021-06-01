// Source: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
// Author: Miao Zhang
// Date:   2021-06-01

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<vector<int>> dp(k + 1, vector<int>(1 << n, INT_MAX / 2));
        dp[0][0] = 0;
        vector<int> cost(1 << n);
        for (int s = 0; s < 1 << n; s++) {
            for (int i = 0; i < n; i++) {
                if (s >> i & 1) cost[s] += jobs[i];
            }
            dp[1][s] = cost[s];
        }
        for (int i = 2; i <= k; i++) {
            for (int s = 0; s < 1 << n; s++) {
                for (int subset = s; subset; subset = (subset - 1) & s) {
                    dp[i][s] = min(dp[i][s], max(dp[i - 1][subset], cost[subset ^ s]));
                }
            }
        }
        return dp[k][(1 << n) - 1];
    }
};
