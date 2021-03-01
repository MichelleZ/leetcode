// Source: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
// Author: Miao Zhang
// Date:   2021-02-28

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        int max_len = *max_element(dp.begin(), dp.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == max_len) res += cnt[i];
        }
        return res;
    }
};
