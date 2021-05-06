// Source: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
// Author: Miao Zhang
// Date:   2021-05-06

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int kMod = 1e9 + 7;
        int n = hats.size();
        int maxhat = 0;
        for (int i = 0; i < n; i++) {
            for (int h: hats[i]) {
                maxhat = max(maxhat, h);
            }
        }
        vector<vector<int>> hat2People(maxhat + 1);
        for (int i = 0; i < n; i++) {
            for (int h: hats[i]) {
                hat2People[h].push_back(i);
            }
        }

        vector<vector<int>> dp(maxhat + 1, vector<int>(1 << n));
        dp[0][0] = 1;
        for (int i = 1; i < maxhat + 1; i++) {
            dp[i] = dp[i - 1];
            for (int mask = (1 << n) - 1; mask >= 0; mask--) {
                for (int p: hat2People[i]) {
                    if (mask & (1 << p)) continue;
                    dp[i][mask | (1 << p)] += dp[i - 1][mask];
                    dp[i][mask | (1 << p)] %= kMod;
                }
            }
        }
        return dp.back().back();
    }
};
