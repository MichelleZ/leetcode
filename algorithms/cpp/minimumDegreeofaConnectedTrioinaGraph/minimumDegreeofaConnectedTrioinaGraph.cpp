// Source: https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/
// Author: Miao Zhang
// Date:   2021-06-04

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<bitset<400>> g(n);
        for (auto& e: edges) {
            g[e[0] - 1].set(e[1] - 1);
            g[e[1] - 1].set(e[0] - 1);
        }
        size_t res = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (g[i][j]) {
                    for (int k = j + 1; k < n; k++) {
                        if (g[i][k] && g[j][k]) {
                            res = min(res, g[i].count() + g[j].count() + g[k].count() - 6);
                        }
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
