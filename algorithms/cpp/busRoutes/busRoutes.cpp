// Source: https://leetcode.com/problems/bus-routes/
// Author: Miao Zhang
// Date:   2021-03-13

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        // bus stop: ith bus travel
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < routes.size(); i++) {
            for (const int u: routes[i]) {
                graph[u].push_back(i);
            }
        }
        // ith bus travel
        vector<int> visited(routes.size(), 0);
        queue<int> q;
        q.push(source);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            res++;
            while (size--) {
                int stop = q.front();
                q.pop();
                for (int travel: graph[stop]) {
                    if (visited[travel]) continue;
                    visited[travel] = 1;
                    for (int stop: routes[travel]) {
                        if (stop == target) return res;
                        q.push(stop);
                    }
                }
            }
        }
        return - 1;
    }
};
