// Source: https://leetcode.com/problems/flower-planting-with-no-adjacent/
// Author: Miao Zhang
// Date:   2021-04-06

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> res(n, 0);
        vector<vector<int>> g(n);
        for (const auto& p: paths) {
            g[p[0] - 1].push_back(p[1] - 1);
            g[p[1] - 1].push_back(p[0] - 1);
        }
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (const auto& j: g[i]) {
                mask |= (1 << res[j]);
            }
            for (int c = 1; c <= 4 && res[i] == 0; c++) {
                if (!(mask & (1 << c)))
                    res[i] = c;
            }
        }
        return res;
    }
};
