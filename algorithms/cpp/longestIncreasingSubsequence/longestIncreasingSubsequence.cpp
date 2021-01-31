// Source: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: Miao Zhang
// Date:   2021-01-31

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
