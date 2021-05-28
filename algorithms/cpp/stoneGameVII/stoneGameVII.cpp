// Source: https://leetcode.com/problems/stone-game-vii/
// Author: Miao Zhang
// Date:   2021-05-28

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> cache(n, vector<int>(n, INT_MAX));
        function<int(int, int, int)> dp = [&] (int l, int r, int s) {
            if (l >= r) return 0;
            if (cache[l][r] == INT_MAX) {
                cache[l][r] = max(s - stones[r] - dp(l, r - 1, s - stones[r]),
                                 s - stones[l] - dp(l + 1, r, s - stones[l]));
            }
            return cache[l][r];
        };
        return dp(0, n - 1, accumulate(begin(stones), end(stones), 0));
    }
};
