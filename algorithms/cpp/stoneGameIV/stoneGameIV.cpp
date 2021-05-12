// Source: https://leetcode.com/problems/stone-game-iv/
// Author: Miao Zhang
// Date:   2021-05-12

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k * k <= i; k++) {
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
