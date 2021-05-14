// Source: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
// Author: Miao Zhang
// Date:   2021-05-15

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> idx;
        idx[0] = -1;
        vector<int> dp(n + 1);
        int sums = 0;
        for (int i = 0; i < n; i++) {
            sums += nums[i];
            int t = sums - target;
            dp[i + 1] = dp[i];
            if (idx.count(t)) {
                dp[i + 1] = max(dp[i + 1], dp[idx[t] + 1] + 1);
            }
            idx[sums] = i;
        }
        return dp[n];
    }
};
