// Source: https://leetcode.com/problems/critical-connections-in-a-network/
// Author: Miao Zhang
// Date:   2021-04-16

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        vector<vector<int>> res;
        vector<int> low(n, -1);
        
        for (const auto& c: connections) {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        
        function<int(int, int, int)> tarjan = [&](int v, int par, int lvl) {
            low[v] = lvl + 1;
            for (auto& child: g[v]) {
                if (child == par)
                    continue;
                else if (low[child] == -1) {
                    low[v] = min(low[v], tarjan(child, v, lvl + 1));
                } else {
                    low[v] = min(low[v], low[child]);
                }
            }
            if (low[v] == lvl + 1 && v != 0) {
                res.push_back({v, par});
            }
            return low[v];
        };
    
        tarjan(0, -1, 0);
        return res;
    }
};
