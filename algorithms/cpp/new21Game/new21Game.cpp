// Source: https://leetcode.com/problems/new-21-game/
// Author: Miao Zhang
// Date:   2021-03-16

/***************************************************************
 * dp[x] = 1 K <= x <= min(N, K+W-1)
 *         0 x >= min(N, K+W-1)
 * dp[x] = (dp[x+1] + dp[x+2] ... + dp[x + W]) / W
 * dp[x] = dp[x+1] - (dp[x+W+1] -dp[x+1])/W, 0 <= x < K-1
 * dp[K-1] = (dp[K+1] ...+dp[K+W]) / W
 * dp[K-1] = min(N-K+1, W) / W
***************************************************************/
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1.0;
        vector<double> dp(K + W);
        for (int i = K; i <= N && i <= K + W - 1; i++) {
            dp[i] = 1.0;
        }
        dp[K - 1] = 1.0 * min(N - K + 1, W) / W;
        for (int i = K - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] - (dp[i + W + 1] - dp[i + 1]) / W;
        }
        return dp[0];
    }
};
