// Source: https://leetcode.com/problems/is-graph-bipartite/
// Author: Miao Zhang
// Date:   2021-03-10

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n); // 0 uncoloured
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0 && !dfs(graph, colors, i, 1)) { // 1 red, -1 blue
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int cur, int color) {
        colors[cur] = color;
        for (int nxt: graph[cur]) {
            if (colors[nxt] == color) return false;
            if (colors[nxt] == 0 && !dfs(graph, colors, nxt, -color)) return false;
        }
        return true;
    }
};
