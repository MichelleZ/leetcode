// Source: https://leetcode.com/problems/stone-game-viii/
// Author: Miao Zhang
// Date:   2021-06-16

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sums;
        partial_sum(stones.begin(), stones.end(), back_inserter(sums));
        vector<int> dp(n);
        dp[n - 1] = sums[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            dp[i] = max(dp[i + 1], sums[i] - dp[i + 1]);
        }
        return dp[1];
    }
};
