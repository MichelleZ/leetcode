// Source: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
// Author: Miao Zhang
// Date:   2021-06-14

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        vector<int> degrees(n);
        for (auto& e: edges) {
            degrees[e[1]]++;
            g[e[0]].push_back(e[1]);
        }
        int found = 0;
        vector<array<int, 26>> f(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!degrees[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            found++;
            int u = q.front();
            q.pop();
            f[u][colors[u] - 'a']++;
            for (int v: g[u]) {
                degrees[v]--;
                for (int c = 0; c < 26; c++) {
                    f[v][c] = max(f[v][c], f[u][c]);
                }
                if (!degrees[v]) {
                    q.push(v);
                }
            }
        }
        if (found != n) return -1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, *max_element(f[i].begin(), f[i].end()));
        }
        return res;
    }
};
