// Source: https://leetcode.com/problems/min-cost-climbing-stairs/
// Author: Miao Zhang
// Date:   2021-03-06

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};
