// Source: https://leetcode.com/problems/paint-house-iii/
// Author: Miao Zhang
// Date:   2021-05-09

/*********************************************************************
 * dp[k][i][c]: from 1 to i, k groups, last one is c
 * dp[k][i][c] = min(dp[k - (c != cj)][i - 1][cj]) + cost[i][c] if colors[i] == 0 else 0, j = i - 1
 * dp[0][0][*] = 0
 * dp[target][m][*]
 * ci = colors[i] dp[k][i][c != ci] = inf
*********************************************************************/
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int kInf = 1e9 + 7;
        int s = 1;
        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, kInf)));
        fill(begin(dp[0][0]), end(dp[0][0]), 0);
        for (int k = 1; k <= target; k++) {
            for (int i = k; i <= m; i++) {
                int hi = houses[i - 1];
                int hj = i >= 2 ? houses[i - 2] : 0;
                const auto& [si, ei] = hi ? tie(hi, hi) : tie(s, n);
                const auto& [sj, ej] = hj ? tie(hj, hj) : tie(s, n);
                for (int ci = si; ci <= ei; ci++) {
                    int v = ci == hi ? 0 : cost[i - 1][ci - 1];
                    for (int cj = sj; cj <= ej; cj++) {
                        dp[k][i][ci] = min(dp[k][i][ci], dp[k - (ci != cj)][i - 1][cj] + v);
                    }
                }
            }
        }
        int res = *min_element(begin(dp[target][m]), end(dp[target][m]));
        return res >= kInf ? -1 : res;
    }
};
