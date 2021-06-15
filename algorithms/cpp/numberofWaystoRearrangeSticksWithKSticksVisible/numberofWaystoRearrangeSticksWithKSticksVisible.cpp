// Source: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
// Author: Miao Zhang
// Date:   2021-06-15

/**************************************************************
 * dp(i, j) = dp(i - 1, j - 1) + (i - 1) * dp(i - 1, j)
 * dp(0, 0) = 1
 * dp(n, k)
**************************************************************/
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        int kMod = 1e9 + 7;
        vector<int> dp(k + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            vector<int> dp2(k + 1);
            for (int j = 1; j <= k; j++) {
                dp2[j] = (dp[j - 1] + (long long)dp[j] * (i - 1)) % kMod;
            }
            dp = std::move(dp2);
        }
        return dp[k];
    }
};
