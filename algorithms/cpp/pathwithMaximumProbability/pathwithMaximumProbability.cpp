// Source: https://leetcode.com/problems/path-with-maximum-probability/
// Author: Miao Zhang
// Date:   2021-05-13

/***************************************************************
 * max(p1*p2*p3) = max(log(p1*p2*p3)) = max(log(p1)+log(p2)+log(p3))
 * = min(-(log(p1)+log(p2)+log(p3)))
***************************************************************/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            double w = -log(succProb[i]);
            g[edges[i][0]].emplace_back(edges[i][1], w);
            g[edges[i][1]].emplace_back(edges[i][0], w);
        }
        vector<double> dist(n, FLT_MAX);
        priority_queue<pair<double, int>> q;
        q.emplace(-0.0, start);
        vector<int> seen(n);
        while (!q.empty()) {
            double d = -q.top().first;
            int cur = q.top().second;
            q.pop();
            seen[cur] = 1;
            if (cur == end) return exp(-d);
            for (auto& [nxt, w]: g[cur]) {
                if (seen[nxt] || d + w > dist[nxt]) continue;
                q.emplace(-(dist[nxt] = d + w), nxt);
            }
        }
        return 0;
    }
};
