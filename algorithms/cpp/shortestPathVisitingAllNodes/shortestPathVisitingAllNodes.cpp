// Source: https://leetcode.com/problems/shortest-path-visiting-all-nodes/
// Author: Miao Zhang
// Date:   2021-03-17

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int finalstate = (1 << n) - 1;
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(1 << n));
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});
        }
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto n = q.front();
                q.pop();
                int node = n.first;
                int state = n.second;
                if (state == finalstate) return step;
                if (visited[node][state]) continue;
                visited[node][state] = 1;
                for (int nxt: graph[node]) {
                    q.push({nxt, state | 1 << nxt});
                }
            }
            step++;
        }
        return -1;
    }
};
