// Source: https://leetcode.com/problems/number-of-paths-with-max-score/
// Author: Miao Zhang
// Date:   2021-04-22

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int kMod = 1e9 + 7;
        int n = board.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> cnt(n, vector<int>(n));
        board[n - 1][n - 1] = board[0][0] = '0';
        cnt[n - 1][n -1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] != 'X') {
                    int m = 0;
                    if (i + 1 < n && j + 1 < n) {
                        m = dp[i + 1][j + 1];
                    }
                    if (i + 1 < n) {
                        m = max(m, dp[i + 1][j]);
                    }
                    if (j + 1 < n) {
                        m = max(m, dp[i][j + 1]);
                    }
                    dp[i][j] = m + board[i][j] - '0';
                    if (i + 1 < n && j + 1 < n && dp[i + 1][j + 1] == m) {
                        cnt[i][j] = (cnt[i][j] + cnt[i + 1][j + 1]) % kMod;
                    }
                    if (i + 1 < n && dp[i + 1][j] == m) {
                        cnt[i][j] = (cnt[i][j] + cnt[i + 1][j]) % kMod;
                    }
                    if (j + 1 < n && dp[i][j + 1] == m) {
                        cnt[i][j] = (cnt[i][j] + cnt[i][j + 1]) % kMod;
                    }
                }
            }
        }
        return {cnt[0][0] ? dp[0][0] : 0, cnt[0][0]};
    }
};
