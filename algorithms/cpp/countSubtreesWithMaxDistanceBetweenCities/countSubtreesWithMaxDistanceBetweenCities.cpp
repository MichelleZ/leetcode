// Source: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/
// Author: Miao Zhang
// Date:   2021-05-21

/**********************************************************************
 * d: diameter of the tree, k: from root to farthest leaf node
 * dp[i][k][d]: root is i
 * dp[i][0][0] = 1
 * dp[u][k][d] = sum(dp[u][k1][d1] * dp[v][k2][d2])
 *               k = max(k1, k2 + 1), d = max(d1, d2, d1 + d2 + 1)
**********************************************************************/
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e: edges) {
            g[e[0] - 1].push_back(e[1] - 1);
            g[e[1] - 1].push_back(e[0] - 1);
        }
        vector<vector<vector<int>>> dp(n);
        vector<int> sizes(n);
        function<void(int, int)> dfs = [&] (int u, int p) {
            if (dp[u].size()) return;
            sizes[u] = 1;
            dp[u] = vector<vector<int>>(n, vector<int>(n));
            dp[u][0][0] = 1;
            for (int v: g[u]) {
                if (v == p) continue;
                dfs(v, u);
                vector<vector<int>> tmp(dp[u]);
                for(int d1 = 0; d1 < sizes[u]; d1++) {
                    for (int k1 = 0; k1 <= d1; k1++) {
                        if (!dp[u][k1][d1]) continue;
                        for (int d2 = 0; d2 < sizes[v]; d2++) {
                            for (int k2 = 0; k2 <= d2; k2++) {
                                int d = max({d1, d2, k1 + k2 + 1});
                                int k = max(k1, k2 + 1);
                                tmp[k][d] += dp[u][k1][d1] * dp[v][k2][d2];
                            }
                        }
                    }
                }
                swap(tmp, dp[u]);
                sizes[u] += sizes[v];
            }
        };
        vector<int> res(n - 1);
        dfs(0, -1);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                for (int d = 1; d < n; d++) {
                    res[d - 1] += dp[i][k][d];
                }
            }
        }
        return res;
    }
};
