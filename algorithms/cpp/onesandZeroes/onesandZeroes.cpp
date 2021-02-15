// Source: https://leetcode.com/problems/ones-and-zeroes/
// Author: Miao Zhang
// Date:   2021-02-15

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str: strs) {
            int zeros = 0;
            int ones = 0;
            for (char c: str) {
                if (c == '0') zeros++;
                if (c == '1') ones++;
            }
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
