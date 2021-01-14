// Source: https://leetcode.com/problems/edit-distance/
// Author: Miao Zhang
// Date:   2021-01-13

/*****************************************************
 * dp[i][j] = dp[i-1][j-1] if word1[i] = word2[j]
 * dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])+1 if word1[i] != word2[j]
*****************************************************/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        int i, j;
        for (i = 0; i < n1 + 1; i++) {
            dp[i][0] = i;
        }
        for (j = 0; j < n2 + 1; j++) {
            dp[0][j] = j;
        }
        for (i = 1; i < n1 + 1; i++) {
            for (j = 1; j < n2 + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int tmp = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = min(tmp, dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};
