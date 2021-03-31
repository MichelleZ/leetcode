// Source: https://leetcode.com/problems/minimum-cost-to-merge-stones/
// Author: Miao Zhang
// Date:   2021-03-31

/************************************************
 * dp[i][j][k] = min{dp[i][m][1] + dp[m + 1][j][k - 1]}
 * dp[i][j][1] = dp[i][j][K] + sum(A[i]~A[j])
 * dp[0][n-1][1]
************************************************/
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1)) return -1;
        int kInf = 1e9;
        vector<int> sums(n + 1);
        for (int i = 0; i < stones.size(); i++) {
            sums[i + 1] = sums[i] + stones[i];
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K + 1, kInf)));
        for (int i = 0; i < n; i++) {
            dp[i][i][1] = 0;
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                for (int k = 2; k <= K; k++) {
                    for (int m = i; m < j; m += K - 1) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
                    }
                    dp[i][j][1] = dp[i][j][K] + sums[j + 1] - sums[i];
                }
            }
        }
        return dp[0][n - 1][1];
    }
};
