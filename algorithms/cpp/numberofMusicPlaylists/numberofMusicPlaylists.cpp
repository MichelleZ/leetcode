// Source: https://leetcode.com/problems/number-of-music-playlists/
// Author: Miao Zhang
// Date:   2021-03-24

/************************************************
 * dp[i][j]: i length with j different songs
 * dp[i][j] = dp[i - 1][j - 1] * (N - (j - 1))
 *          + dp[i - 1][j] * max(j - K, 0)
************************************************/
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        int kMod = 1e9 + 7;
        vector<vector<long>> dp(L + 1, vector<long>(N + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < L + 1; i++) {
            for (int j = 1; j <= min(i, N); j++) {
                dp[i][j] = (dp[i - 1][j - 1] * (N - (j - 1)) +
                            dp[i - 1][j] * max(j - K, 0)) % kMod;
            }
        }
        return dp[L][N] % kMod;
    }
};
