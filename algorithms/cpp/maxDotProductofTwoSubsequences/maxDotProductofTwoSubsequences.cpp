// Source: https://leetcode.com/problems/max-dot-product-of-two-subsequences/
// Author: Miao Zhang
// Date:   2021-05-08

/****************************************************************
 * dp[i][j]: 0--i, 0--j
 * dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], max(0, dp[i - 1][j - 1]) + nums1[i] * nums2[j])
****************************************************************/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2));
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                dp[i][j] = nums1[i] * nums2[j];
                if (i > 0 && j > 0) dp[i][j] += max(0, dp[i - 1][j - 1]);
                if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp.back().back();
    }
};
