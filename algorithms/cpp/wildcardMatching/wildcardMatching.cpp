// Source: https://leetcode.com/problems/wildcard-matching/
// Author: Miao Zhang
// Date:   2021-01-12

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        bool dp[m + 1][n + 1];
        int i, j;
        for (i = 0; i < m + 1; i++) {
            for (j = 0; j < n + 1; j++) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for (j = 1; j < n + 1; j++) {
            dp[0][j] = dp[0][j - 1] and (p[j - 1] == '*');
        }
        
        for (i = 1; i < m + 1; i++) {
            for (j = 1; j < n + 1; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
                }
                else if(s[i - 1] == p[j - 1] or p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
};
