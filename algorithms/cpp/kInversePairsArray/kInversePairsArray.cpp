// Source: https://leetcode.com/problems/k-inverse-pairs-array/
// Author: Miao Zhang
// Date:   2021-02-25

/***********************************************************
 * dp[i][k]: j reverse pair from 1 to i
 * dp[i][k] k = 5
 * xxxx5 dp[i-1][k]
 * xxx5x dp[i-1][k - 1]
 * xx5xx
 * x5xxx
 * 5xxxx dp[i - 1][k - 4] 4 = i - 1
 * dp[n][k] = dp[n-1][k] + dp[n-1][k-1]....+ dp[n-1][k-(n-1)]
 ************************************************************
 * dp[n][k+1] = dp[n-1][k+1] + dp[n-1][k]...+dp[n-1][k-n+2]
 * dp[n][k+1] = dp[n][k] + dp[n-1][k+1]-dp[n-1][k-n+1]
 * dp[n][k] = dp[n][k-1] + dp[n-1][k]-dp[n-1][k-n]
***********************************************************/
class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                for (int K = 0; K <= k; K++) {
                    if (K - j >= 0) {
                        dp[i][K] = (dp[i][K] + dp[i - 1][K - j]) % mod;
                    }
                }
            }
        }
        return dp[n][k];
    }
};

class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
                }
            }
        }
        return dp[n][k];
    }
};
