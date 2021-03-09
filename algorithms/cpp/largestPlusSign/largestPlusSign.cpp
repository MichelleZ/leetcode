// Source: https://leetcode.com/problems/largest-plus-sign/
// Author: Miao Zhang
// Date:   2021-03-08

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int cnt = 0;
        int res = 0;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        unordered_set<int> s;
        for (auto mine: mines) s.insert(mine[0] * N + mine[1]);
        for (int i = 0; i < N; i++) {
            cnt = 0;
            for (int j = 0; j < N; j++) {
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = cnt;
            }
            cnt = 0;
            for (int j = N - 1; j >= 0; j--) {
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
            }
        }

        for (int j = 0; j < N; j++) {
            cnt = 0;
            for (int i = 0; i < N; i++) {
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
            }
            cnt = 0;
            for (int i = N - 1; i >= 0; i--) {
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
