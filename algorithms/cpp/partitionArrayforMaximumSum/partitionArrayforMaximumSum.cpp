// Source: https://leetcode.com/problems/partition-array-for-maximum-sum/
// Author: Miao Zhang
// Date:   2021-04-06

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int m = INT_MIN;
            for (int l = 1; l <= min(k, i); l++) {
                m = max(m, arr[i - l]);
                dp[i] = max(dp[i], dp[i - l] + m * l);
            }
        }
        return dp[n];
    }
};
