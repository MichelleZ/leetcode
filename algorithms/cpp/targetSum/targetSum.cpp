// Source: https://leetcode.com/problems/target-sum/
// Author: Miao Zhang
// Date:   2021-02-17

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum < std::abs(S)) return 0;
        int offset = sum;
        vector<int> dp(sum + offset + 1, 0);
        dp[offset] = 1;
        for (int n: nums) {
            vector<int> tmp(sum + offset + 1, 0);
            for (int i = n; i < sum + offset + 1 - n; i++) {
                if (dp[i]) {
                    tmp[i + n] += dp[i];
                    tmp[i - n] += dp[i];
                }
            }
            std::swap(dp, tmp);
        }
        return dp[S + offset];
    }
};
