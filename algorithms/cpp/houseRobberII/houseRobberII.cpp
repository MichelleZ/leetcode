// Source: https://leetcode.com/problems/house-robber-ii/
// Author: Miao Zhang
// Date:   2021-01-26

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(robTotal(nums, 0, n - 2), robTotal(nums, 1, n - 1));
    }
    
    int robTotal(vector<int>& nums, int i, int j) {
        if (i + 1 >= j) return max(nums[i], nums[j]);
        vector<int> dp(j - i + 1, 0);
        dp[0] = nums[i];
        dp[1] = max(nums[i], nums[i + 1]);
        for (int k = i + 2; k <= j; k++) {
            dp[k - i] = max(dp[k - 1 - i], dp[k - 2 - i] + nums[k]);
        }
        return dp[j - i];
    }
};
