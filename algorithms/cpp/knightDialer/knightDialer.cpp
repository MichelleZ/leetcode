// Source: https://leetcode.com/problems/knight-dialer/
// Author: Miao Zhang
// Date:   2021-03-26

class Solution {
public:
    int knightDialer(int n) {
        int kMod = 1e9 + 7;
        int dirs[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        vector<vector<int>> dp(4, vector<int>(3, 1));
        dp[3][0] = dp[3][2] = 0;
        for (int k = 1; k < n; k++) {
            vector<vector<int>> tmp(4, vector<int>(3));
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == 3 && j != 1) continue;
                    for (auto& d: dirs) {
                        int x = i + d[0];
                        int y = j + d[1];
                        if (x < 0 || x >= 4 || y < 0 || y >= 3) continue;
                        tmp[i][j] = (tmp[i][j] + dp[x][y]) % kMod;
                    }
                }
            }
            dp.swap(tmp);
        }
        int res = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                res = (res + dp[i][j]) % kMod;
            }
        }
        return res;
    }
};
