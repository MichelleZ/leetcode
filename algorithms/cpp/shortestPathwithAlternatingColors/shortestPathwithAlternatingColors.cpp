// Source: https://leetcode.com/problems/shortest-path-with-alternating-colors/
// Author: Miao Zhang
// Date:   2021-04-12

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<unordered_set<int>> edgesr(n);
        vector<unordered_set<int>> edgesb(n);
        for (const auto& e: red_edges) {
            edgesr[e[0]].insert(e[1]);
        }
        for (const auto& e: blue_edges) {
            edgesb[e[0]].insert(e[1]);
        }
        unordered_set<int> seenr;
        unordered_set<int> seenb;
        vector<int> res(n, -1);
        queue<pair<int, int>> q;
        q.push({0, 0}); // red
        q.push({0, 1}); // blue
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front().first;
                int isred = q.front().second;
                q.pop();
                res[node] = res[node] >= 0 ? min(res[node], steps): steps;
                auto& edges = isred ? edgesr : edgesb;
                auto& seen = isred ? seenr : seenb;
                for (int nxt: edges[node]) {
                    if (seen.count(nxt)) continue;
                    seen.insert(nxt);
                    q.push({nxt, 1 - isred});
                }
            }
            steps++;
        }
        return res;
    }
};
