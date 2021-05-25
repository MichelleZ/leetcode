// Source: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Author: Miao Zhang
// Date:   2021-05-25

/**********************************************************
 * dp[i]
 * if s[i] == 'b': dp[i] = dp[i - 1]
 * else if s[i] == 'a':
 *   del s[i]: dp[i] = dp[i - 1] + 1
 *   keep    : dp[i] = del total b
**********************************************************/
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        int b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                dp[i + 1] = dp[i];
                b++;
            } else {
                dp[i + 1] = min(b, dp[i] + 1);
            }
        }
        return dp[n];
    }
};
