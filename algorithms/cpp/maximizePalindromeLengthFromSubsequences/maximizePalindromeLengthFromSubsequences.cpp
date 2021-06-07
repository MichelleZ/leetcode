// Source: https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
// Author: Miao Zhang
// Date:   2021-06-07

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        string s = word1 + word2;
        int n = l1 + l2;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                if (word1[i] == word2[j]) {
                    res = max(res, dp[i][l1 + j]);
                }
            }
        }
        return res;
    }
};
