// Source: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
// Author: Miao Zhang
// Date:   2021-06-16

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + (nums1[__builtin_popcount(mask) - 1] ^ nums2[i]));
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
