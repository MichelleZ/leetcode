// Source: https://leetcode.com/problems/cut-off-trees-for-golf-event/
// Author: Miao Zhang
// Date:   2021-02-28

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();
        
        // {height, x, y}
        vector<tuple<int, int, int>> trees;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(forest[i][j], i, j);
                }
            }
        }
        sort(trees.begin(), trees.end());
        
        int sx = 0;
        int sy = 0;
        int total_steps = 0;
        for (int i = 0; i < trees.size(); i++) {
            int tx = get<1>(trees[i]);
            int ty = get<2>(trees[i]);
            int steps = bfs(forest, sx, sy, tx, ty);
            if (steps == INT_MAX) return -1;
            forest[tx][ty] = 1;
            total_steps += steps;
            sx = tx;
            sy = ty;
        }
        return total_steps;
    }
    
    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0},{-1, 0}};
        vector<vector<int>> visited(forest.size(), vector<int>(forest[0].size(), 0));
        
        queue<pair<int, int>> q;
        q.emplace(sx, sy);
        int steps = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int k = 0; k < n; k++) {
                auto node = q.front();
                q.pop();
                int cx = node.first;
                int cy = node.second;
                if (cx == tx && cy == ty) return steps;
                for (auto d: dirs) {
                    int x = cx + d[0];
                    int y = cy + d[1];
                    if (x < 0 || x >= forest.size() || y < 0 || y >= forest[0].size() || !forest[x][y] || visited[x][y]) continue;
                    visited[x][y] = 1;
                    q.emplace(x, y);
                }
            }
            steps++;
        }
        return INT_MAX;
    }
};
