// Source: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Author: Miao Zhang
// Date:   2021-04-23

/******************************************************
 * dp[i][j] = dp[i + 1][j - 1] if s[i] == s[j]
              min(dp[i][j - 1], dp[i + 1][j])+1 if s[i] != s[j]
******************************************************/
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 2; l <= n; l++) {
            for (int i = 0, j = l - 1; j < n; i++, j++) {
                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : min(dp[i][j - 1], dp[i + 1][j]) + 1;
            }
        }
        return dp[0][n - 1];
    }
};
