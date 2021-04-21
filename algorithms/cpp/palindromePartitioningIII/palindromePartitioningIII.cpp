// Source: https://leetcode.com/problems/palindrome-partitioning-iii/
// Author: Miao Zhang
// Date:   2021-04-21

/*******************************************************
 * dp[i][k] 0-i divided k group
 * dp[i][k] = min(dp[j][k - 1] + cost(j + 1, i)) 0 <= j < i
 * dp[i][1] = cost(0, i)
 * dp[n - 1][k]
 * cost[i][j] = (s[i] != s[j]) + cost(i + 1, j - 1)
*******************************************************/
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.length();
        vector<vector<int>> cost(n, vector<int>(n));
        for (int l = 2; l <= n; l++) {
            for (int i = 0, j = l - 1; j < n; i++, j++) {
                cost[i][j] = (s[i] != s[j]) + cost[i + 1][j - 1];
            }
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX / 2));
        for (int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
            for (int m = 2; m <= k; m++) {
                for (int j = 0; j < i; j++) {
                    dp[i][m] = min(dp[i][m], dp[j][m - 1] + cost[j + 1][i]);
                }
            }
        }
        return dp[n - 1][k];
    }
};
