// Source: https://leetcode.com/problems/count-sorted-vowel-strings/
// Author: Miao Zhang
// Date:   2021-05-25

/***********************************************************
 * dp[i][j]: length i, ends with j
 * dp[i][j] = sum(dp[i - 1][k]) 0 <= k <= j
***********************************************************/
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(5, 1));
        for (int i = 2; i <= n; i++) {
            int tmp = 0;
            for (int j = 0; j < 5; j++) {
                tmp += dp[i - 1][j];
                dp[i][j] = tmp;
            }
        }
        return accumulate(begin(dp[n]), end(dp[n]), 0);
    }
};
