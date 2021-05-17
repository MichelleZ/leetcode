// Source: https://leetcode.com/problems/stone-game-v/
// Author: Miao Zhang
// Date:   2021-05-16

/*************************************************************
 * dp(l, r) = max{
 * suml + dp(l, k) if suml < sumr
 * sumr + dp(k + 1, r) if sumr < suml
 * suml + max(dp(l, k), dp(k + 1, r))
 * } for k in range[l, r)
 * dp(0, n - 1)
*************************************************************/
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> sums(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + stoneValue[i];
        }
        vector<vector<int>> cache(n, vector<int>(n, -1));

        function<int(int, int)> dp = [&] (int l, int r) {
            if (l == r) return 0;
            int& res = cache[l][r];
            if (res != -1) return res;
            for (int k = l; k < r; k++) {
                // left: l, k; right: k + 1, r
                int suml = sums[k + 1] - sums[l];
                int sumr = sums[r + 1] - sums[k + 1];
                if (suml > sumr) {
                    res = max(res, sumr + dp(k + 1, r));
                } else if (suml < sumr) {
                    res = max(res, suml + dp(l, k));
                } else {
                    res = max(res, suml + max(dp(l, k), dp(k + 1, r)));
                }
            }
            return res;
        };
        return dp(0, n - 1);
    }
};
