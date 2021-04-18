// Source: https://leetcode.com/problems/dice-roll-simulation/
// Author: Miao Zhang
// Date:   2021-04-18

/**************************************************************
 * dp[i][j][k]: i: length, j: ends with j, k: consecutive times
 * dp[1][*][1] = 1
 * dp[i][j][1] = sum(dp[i - 1][p][*]) j != p
 * dp[i][j][k + 1] = dp[i - 1][j][k], k < rollMax[j]
 * sum(dp[n])
***************************************************************/
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int kMaxRolls = 15;
        int kMod = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1,
                                       vector<vector<int>>(6,
                                       vector<int>(kMaxRolls + 1)));
        for (int j = 0; j < 6; j++) {
            dp[1][j][1] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int p = 0; p < 6; p++) {
                    for (int k = 1; k <= rollMax[p]; k++) {
                        if (p != j) {
                            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][p][k]) % kMod;
                        } else if (k < rollMax[j]) {
                            dp[i][j][k + 1] = dp[i - 1][j][k];
                        }
                    }
                }
            }
        }

        int res = 0;
        for (int j = 0; j < 6; j++) {
            for (int k = 1; k <= rollMax[j]; k++) {
                res = (res + dp[n][j][k]) % kMod;
            }
        }
        return res;
    }
};
