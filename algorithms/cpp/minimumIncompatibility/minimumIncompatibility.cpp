// Source: https://leetcode.com/problems/minimum-incompatibility/
// Author: Miao Zhang
// Date:   2021-05-27

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n / k;
        vector<vector<int>> dp(1 << n, vector<int>(16, INT_MAX / 2));
        for (int i = 0; i < n; i++) dp[1 << i][i] = 0;
        for (int mask = 0; mask < 1 << n; mask++) {
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) continue;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue;
                    int t = mask | (1 << j);
                    if (__builtin_popcount(mask) % m == 0) {
                        dp[t][j] = min(dp[t][j], dp[mask][i]);
                    } else if (nums[j] > nums[i]) {
                        dp[t][j] = min(dp[t][j],
                                       dp[mask][i] + nums[j] - nums[i]);
                    }
                }
            }
        }
        int res = *min_element(begin(dp[(1 << n) - 1]), end(dp[(1 << n) - 1]));
        return res == INT_MAX / 2 ? -1 : res;
    }
};
