// Source: https://leetcode.com/problems/palindromic-substrings/
// Author: Miao Zhang
// Date:   2021-02-26

class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int l = 1; l < n + 1; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                if (l == 1 || (l == 2 && s[i] == s[j]) || (l >= 3 && s[i] == s[j] && dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
