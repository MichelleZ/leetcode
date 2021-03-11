// Source: https://leetcode.com/problems/champagne-tower/
// Author: Miao Zhang
// Date:   2021-03-11

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int n = 100;
        vector<vector<double>> dp(n, vector<double>(n));
        dp[0][0] = poured;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] > 1) {
                    dp[i + 1][j] += (dp[i][j] - 1) / 2.0;
                    dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0;
                    dp[i][j] = 1.0;
                }
            }
        }
        return std::min(1.0, dp[query_row][query_glass]);
    }
};


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int n = 100;
        vector<double> dp(n);
        dp[0] = poured;
        for (int i = 0; i < query_row; i++) {
            vector<double> tmp(n);
            for (int j = 0; j <= i; j++) {
                if (dp[j] > 1) {
                    tmp[j] += (dp[j] - 1) / 2.0;
                    tmp[j + 1] += (dp[j] - 1) / 2.0;
                }
            }
            dp.swap(tmp);
        }
        return std::min(1.0, dp[query_glass]);
    }
};
