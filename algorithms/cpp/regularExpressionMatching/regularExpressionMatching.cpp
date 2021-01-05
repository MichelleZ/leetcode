// Source: https://leetcode.com/problems/regular-expression-matching/
// Author: Miao Zhang
// Date:   2021-01-05

/*******************************
 *
 * Regular Expression Matching
 *
*******************************/


// Sequential processing
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        bool firstmatch = s.size() > 0 && (s[0] == p[0] || p[0] == '.');
        
        if (p.size() > 1 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (firstmatch && isMatch(s.substr(1), p));
        } else {
            return firstmatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

// dp
// dp[i][j] = dp[i -1][j -1] if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.')
// dp[i][j] = dp[i][j - 2] if p[j - 1] == '*' this situation represents the pattern repeates for 0 times
// dp[i][j] = dp[i - 1][j] if p[j - 1] == '*' && (s[i - 1] == p[j - 2] || p[j - 2] == '.') this situation represents the pattern repeates for at least 1 times
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for ( int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (j > 0 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};

