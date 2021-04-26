// Source: https://leetcode.com/problems/maximum-students-taking-exam/
// Author: Miao Zhang
// Date:   2021-04-26

/*************************************************************
 * dp[i][s]: max of students after filling ith row
 * dp[i][s] = max{dp[i-1][t] + popcount(s)}
 * s & (s >> 1) check left and right
 * t & (s >> 1) check right top, s & (t >> 1) check left top
*************************************************************/
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        vector<int> s(m + 1);
        // seats valid state
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                s[i] |= (seats[i - 1][j] == '.') << j;
            }
        }

        vector<vector<int>> dp(m + 1, vector<int>(1<<n));
        for (int i = 1; i < m + 1; i++) {
            for (int l = s[i - 1]; ; l = (l - 1) & s[i - 1]) {
                for (int c = s[i]; ; c = (c - 1) & s[i]) {
                    if (!(c & (c >> 1)) && !(l & (c >> 1)) && !(c & (l >> 1))) {
                        dp[i][c] = max(dp[i][c], dp[i - 1][l] + __builtin_popcount(c));
                    }
                    if (c == 0) break;
                }
                if (l == 0) break;
            }
        }
        return *max_element(begin(dp[m]), end(dp[m]));
    }
};
