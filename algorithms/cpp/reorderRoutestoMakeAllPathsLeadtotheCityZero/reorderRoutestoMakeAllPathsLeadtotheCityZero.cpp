// Source: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
// Author: Miao Zhang
// Date:   2021-05-09

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> g(n);
        for (const auto& c: connections) {
            g[c[0]].emplace_back(c[1], 1);
            g[c[1]].emplace_back(c[0], 0);
        }
        int res = 0;
        queue<int> q{{0}};
        vector<int> seen(n);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            seen[cur] = 1;
            for (auto& [nxt, cost]: g[cur]) {
                if (seen[nxt]) continue;
                res += cost;
                q.push(nxt);
            }
        }
        return res;
    }
};
