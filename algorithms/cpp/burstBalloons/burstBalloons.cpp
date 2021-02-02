// Source: https://leetcode.com/problems/burst-balloons/
// Author: Miao Zhang
// Date:   2021-02-01

/***********************************************************
 * c[i][j] = maxCoins(nums[i] - nums[j])
 * res = c[1][n]
 * c[i][j] = max(c[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + c[k+1][j])
***********************************************************/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // dp[i][j] = maxCoins(nums[i:j+1])
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int l = 1; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[1][n];
    }
};
