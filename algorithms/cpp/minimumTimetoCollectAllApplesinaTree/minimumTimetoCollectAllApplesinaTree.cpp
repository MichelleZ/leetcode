// Source: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
// Author: Miao Zhang
// Date:   2021-05-07

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> g(n);
        for (auto& edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<int> seen(n);
        function<int(int)> dfs = [&] (int cur) {
            seen[cur] = 1;
            int res = 0;
            for (int nxt: g[cur]) {
                if (seen[nxt]) continue;
                int cost = dfs(nxt);
                if (cost > 0 || hasApple[nxt])
                    res += 2 + cost;
            }
            return res;
        };
        return dfs(0);
    }
};
