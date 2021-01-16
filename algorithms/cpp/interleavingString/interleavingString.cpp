// Source: https://leetcode.com/problems/interleaving-string/
// Author: Miao Zhang
// Date:   2021-01-16

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3) return false;
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        for (int i = 0; i < len1 + 1; i++) {
            for (int j = 0; j < len2 + 1; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                } else {
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) ||
                        (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
