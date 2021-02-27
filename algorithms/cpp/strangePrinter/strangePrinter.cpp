// Source: https://leetcode.com/problems/strange-printer/
// Author: Miao Zhang
// Date:   2021-02-27

/********************************************************
 * dp[i][j] = dp[i][j - 1] + 1
 * dp[i][j] = min(dp[i][j], dp[i][k], dp[k + 1][j - 1])
 * i <= k < j s[k] == s[j]
********************************************************/
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return print(s, 0, n - 1, dp);
    }

    int print(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] > 0) return dp[i][j];
        int res = print(s, i, j - 1, dp) + 1;
        for (int k = i; k < j; k++) {
            if (s[k] == s[j]) {
                res = min(res, print(s, i, k, dp) + print(s, k + 1, j - 1, dp));
            }
        }
        return dp[i][j] = res;
    }
};
