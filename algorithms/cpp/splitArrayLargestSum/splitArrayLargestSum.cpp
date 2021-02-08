// Source: https://leetcode.com/problems/split-array-largest-sum/
// Author: Miao Zhang
// Date:   2021-02-08

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        const int n = nums.size();
        vector<int> sums(n);
        sums[0] = nums[0];
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i - 1] + nums[i];
        }
        vector<vector<int>> dp(m + 1, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dp[1][i] = sums[i];
        }
        for (int i = 2; i <= m; i++) {
            for (int j = i - 1; j < n; j++) {
                for (int k = 0; k < j; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sums[j] - sums[k]));
                }
            }
        }
        return dp[m][n - 1];
    }
};
