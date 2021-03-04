// Source: https://leetcode.com/problems/count-different-palindromic-subsequences/
// Author: Miao Zhang
// Date:   2021-03-04

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int kMod = 1000000007;
        int n = S.length();
        vector<vector<long>> dp(n, vector<long>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i < n - len; i++) {
                int j = i + len;
                if (S[i] == S[j]) {
                    dp[i][j] = dp[i + 1][j - 1] * 2;
                    int l = i + 1;
                    int r = j - 1;
                    while (l <= r && S[l] != S[i]) l++;
                    while (l <= r && S[r] != S[i]) r--;
                    if (l > r) dp[i][j] += 2;
                    else if (l == r) dp[i][j] += 1;
                    else dp[i][j] -= dp[l + 1][r - 1];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }

                dp[i][j] = (dp[i][j] + kMod) % kMod;
            }
        }
        return (int)dp[0][n - 1];
    }
};
