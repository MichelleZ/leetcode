// Source: https://leetcode.com/problems/frog-position-after-t-seconds/
// Author: Miao Zhang
// Date:   2021-04-28

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        for (auto edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<int> seen(n + 1);
        queue<int> q{{1}};
        seen[1] = 1;
        vector<double> p(n + 1);
        p[1] = 1.0;
        while (t--) {
            int size = q.size();
            while (size--) {
                int cur = q.front();
                q.pop();
                int children = 0;
                for (int nxt: g[cur]) {
                    if (!seen[nxt]) children++;
                }
                for (int nxt: g[cur]) {
                    if (!seen[nxt]++) {
                        q.push(nxt);
                        p[nxt] = p[cur] / children;
                    }
                }
                if (children > 0) p[cur] = 0.0;
            }
        }
        return p[target];
    }
};
